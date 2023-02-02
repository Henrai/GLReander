//
// Created by Anze Wang on 1/31/23.
//

#include "VertexBuffer.h"
#include "Renderer.h"

#include "glad/glad.h"

VertexBuffer::VertexBuffer(const void *data, unsigned int size) {
    GL_CALL(glGenBuffers(1, &mRenderedID));
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER,mRenderedID));
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer() {
    GL_CALL(glDeleteBuffers(1, &mRenderedID));
}

void VertexBuffer::Bind() const {
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, mRenderedID));
}

void VertexBuffer::UnBind() const {
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

