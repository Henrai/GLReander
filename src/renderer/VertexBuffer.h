//
// Created by Anze Wang on 1/31/23.
//

#ifndef OGLRENDER_VERTEXBUFFER_H
#define OGLRENDER_VERTEXBUFFER_H


class VertexBuffer {
private:
    unsigned  int mRenderedID;
public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void Bind() const;
    void UnBind() const;
};


#endif //OGLRENDER_VERTEXBUFFER_H
