//
// Created by Anze Wang on 1/31/23.
//

#ifndef OGLRENDER_RENDERER_H
#define OGLRENDER_RENDERER_H

#define ASSERT(x) if(!(x)){__builtin_trap();}
#define GL_CALL(x)  GLClearError(); \
                x;            \
                ASSERT(GLLogCall(#x, __FILE__, __LINE__))


class VertexArray;
class IndexBuffer;
class Shader;

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);


class Renderer {
public:
    void draw(const VertexArray& vb, const IndexBuffer& ib, const Shader& shader) const;

};
#endif //OGLRENDER_RENDERER_H
