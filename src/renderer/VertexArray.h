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
    unsigned int mCnt;
public:
    VertexArray();
    ~VertexArray();

    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void setVertexCount(unsigned int cnt) {mCnt = cnt;}
    unsigned int getVertexCount() {return mCnt;}

    void Bind() const;
    void UnBind() const;

};


#endif //OGLRENDER_VERTEXARRAY_H
