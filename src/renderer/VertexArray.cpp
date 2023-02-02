//
// Created by Anze Wang on 2/1/23.
//

#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Renderer.h"

VertexArray::VertexArray() {
    GL_CALL(glGenVertexArrays(1, &mRendererID));
    GL_CALL(glBindVertexArray(mRendererID));
}

VertexArray::~VertexArray() {
    GL_CALL(glDeleteVertexArrays(1, &mRendererID));
}
void VertexArray::AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout) {
    Bind();
    vb.Bind();
    const auto& elements = layout.getElements();
    unsigned int offset = 0;
    for (int i = 0; i < elements.size(); i++) {
        const auto& element = elements[i];
        GL_CALL(glEnableVertexAttribArray(i));
        GL_CALL(glVertexAttribPointer(i, element.count, GL_FLOAT, element.normalized, layout.GetStride(), (void*)(uintptr_t)offset));
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}

void VertexArray::Bind() {
    GL_CALL(glBindVertexArray(mRendererID));
}

void VertexArray::UnBind() {
    GL_CALL(glBindVertexArray(0));
}