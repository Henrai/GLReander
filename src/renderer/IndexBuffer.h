//
// Created by Anze Wang on 1/31/23.
//

#ifndef OGLRENDER_INDEXBUFFER_H
#define OGLRENDER_INDEXBUFFER_H


class IndexBuffer {
private:
    unsigned int mRendererID;
    unsigned int mCount;
public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void  Bind() const;
    void UnBind() const;

    inline unsigned int GetSize() const { return mCount; }
};


#endif //OGLRENDER_INDEXBUFFER_H
