//
// Created by Anze Wang on 2/1/23.
//

#ifndef OGLRENDER_VERTEXBUFFERLAYOUT_H
#define OGLRENDER_VERTEXBUFFERLAYOUT_H

#include <vector>
#include <glad/glad.h>
#include "Renderer.h"
struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int GetSizeOfType(unsigned int type) {
        switch (type) {
            case GL_FLOAT:
            case GL_UNSIGNED_INT:
                return 4;
            case GL_UNSIGNED_BYTE:
                return 1;
        }
        return 0;
    }
};

template <class... T>
constexpr bool always_false = false;

class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> mElements;
    unsigned int mStride = 0;
public:
    VertexBufferLayout(){}

    template<class T>
    void Push(unsigned int count) {
        static_assert(always_false<T>, "not support type");
    }

    template<>
    void Push<float>(unsigned int count) {
        mElements.push_back({GL_FLOAT, count, GL_FALSE});
        mStride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
    }

    template<>
    void Push<unsigned int>(unsigned int count) {
        mElements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
        mStride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
    }

    template<>
    void Push<unsigned char>(unsigned int count) {
        mElements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
        mStride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
    }

    inline unsigned int GetStride() const {
        return mStride;
    }

    inline std::vector<VertexBufferElement> getElements() const {
        return mElements;
    }

};


#endif //OGLRENDER_VERTEXBUFFERLAYOUT_H
