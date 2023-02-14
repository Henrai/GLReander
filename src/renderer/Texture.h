//
// Created by Anze Wang on 2/13/23.
//

#ifndef OGLRENDER_TEXTURE_H
#define OGLRENDER_TEXTURE_H

#include <string>
#include <glad/glad.h>

class Texture {
private:
    unsigned int mRenderID;
    std::string mFilePath;
    unsigned char* mLocalBuffer;
    int mWidth, mHeight, mBPP;
public:
    Texture(const std::string& path, unsigned int format = GL_RGB);
    ~Texture();


    void Bind(unsigned int slot = 0);
    void UnBind();

    int GetWidth() {return mWidth;}
    int GetHeight() {return mHeight;}
};


#endif //OGLRENDER_TEXTURE_H
