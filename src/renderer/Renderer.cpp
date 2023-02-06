//
// Created by Anze Wang on 1/31/23.
//

#include "Renderer.h"

#include <iostream>
#include "glad/glad.h"

#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"

void GLClearError() {
    while(glGetError() != GL_NO_ERROR);
}
bool GLLogCall(const char* function, const char* file, int line) {
    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] (" << error << "): " << function <<
            " " << file << " " << line << std::endl;
        return false;
    }
    return true;
}

void Renderer::draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const {
    shader.Bind();
    va.Bind();
    ib.Bind();

    GL_CALL(glDrawElements(GL_TRIANGLES, ib.GetSize(), GL_UNSIGNED_INT, nullptr));
}