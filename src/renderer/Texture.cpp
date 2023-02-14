//
// Created by Anze Wang on 2/13/23.
//

#include "Texture.h"
#include "Renderer.h"
#include "../stb_image/stb_image.h"
#include <glad/glad.h>

Texture::Texture(const std::string &path, unsigned int format) {
    stbi_set_flip_vertically_on_load(1);
    mLocalBuffer = stbi_load(path.c_str(), &mWidth, &mHeight, &mBPP, 0 /* rgba */);
    assert(mLocalBuffer != nullptr);
    GL_CALL(glGenTextures(1, &mRenderID));
    GL_CALL(glBindTexture(GL_TEXTURE_2D, mRenderID));


    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

    GL_CALL(glTexImage2D(GL_TEXTURE_2D, 0, format, mWidth, mHeight, 0, format, GL_UNSIGNED_BYTE, mLocalBuffer));
    GL_CALL(glBindTexture(GL_TEXTURE_2D, 0));

    if(mLocalBuffer)
        stbi_image_free(mLocalBuffer);
}

Texture::~Texture() {
    GL_CALL(glDeleteTextures(1, &mRenderID));
}

void Texture::Bind(unsigned int slot) {
    GL_CALL(glActiveTexture(GL_TEXTURE0 + slot));
    GL_CALL(glBindTexture(GL_TEXTURE_2D, mRenderID));
}

void Texture::UnBind() {
    GL_CALL(glBindTexture(GL_TEXTURE_2D, 0));
}