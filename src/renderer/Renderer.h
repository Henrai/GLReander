//
// Created by Anze Wang on 1/31/23.
//

#ifndef OGLRENDER_RENDERER_H
#define OGLRENDER_RENDERER_H

#define ASSERT(x) if(!(x)){__builtin_trap();}
#define GL_CALL(x)  GLClearError(); \
                x;            \
                ASSERT(GLLogCall(#x, __FILE__, __LINE__))

#include <memory>
#include <vector>
#include <glad/glad.h>

class VertexArray;
class VertexBuffer;
class IndexBuffer;
class Shader;
class Texture;
void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);


class Renderer {
private:
    std::unique_ptr<Shader> mShader;
    std::unique_ptr<VertexBuffer> mVertexBuffer;
    std::unique_ptr<VertexArray> mVertexArray;
    std::unique_ptr<IndexBuffer> mIndexBuffer;
    std::vector<std::unique_ptr<Texture>> mTextures;

public:
    void initShader(const std::string& path);
    void appendTexture(const std::string& path, const std::string& name , unsigned int format = GL_RGB);
    void initVertexData(float *vertices, unsigned int vlen, unsigned int* indices, unsigned int ilen, const std::vector<int>& layout);
    void initVertexData(float *vertices, unsigned int vlen, const std::vector<int>& layout);
    void draw() const;
    void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
    void setUniform1i(const std::string& name, int v);
    void setUniform1f(const std::string& name, float v);

    void unBind();
};
#endif //OGLRENDER_RENDERER_H
