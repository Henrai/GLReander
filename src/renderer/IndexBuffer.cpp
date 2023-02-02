//
// Created by Anze Wang on 1/31/23.
//

#include "IndexBuffer.h"


#include "glad/glad.h"
#include "Renderer.h"

IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count) : mCount(count) {
    ASSERT(sizeof (unsigned int) == sizeof(GLint));

    GL_CALL(glGenBuffers(1, &mRendererID));
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID));
    GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW))
}

IndexBuffer::~IndexBuffer() {
    GL_CALL(glDeleteBuffers(1, &mRendererID));
}

void IndexBuffer::Bind() const {
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, mRendererID));
}

void IndexBuffer::UnBind() const {
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}