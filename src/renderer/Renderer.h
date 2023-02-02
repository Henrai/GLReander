//
// Created by Anze Wang on 1/31/23.
//

#ifndef OGLRENDER_RENDERER_H
#define OGLRENDER_RENDERER_H

#define ASSERT(x) if(!(x)){__builtin_trap();}
#define GL_CALL(x)  GLClearError(); \
                x;            \
                ASSERT(GLLogCall(#x, __FILE__, __LINE__))


//\\GLCall(x) GLClearError();
//    x;
//    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

#endif //OGLRENDER_RENDERER_H
