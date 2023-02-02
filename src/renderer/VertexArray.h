//
// Created by Anze Wang on 2/1/23.
//

#ifndef OGLRENDER_VERTEXARRAY_H
#define OGLRENDER_VERTEXARRAY_H

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
class VertexArray {
private:
    unsigned  int mRendererID;
public:
    VertexArray();
    ~VertexArray();

    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

    void Bind();
    void UnBind();

};


#endif //OGLRENDER_VERTEXARRAY_H
