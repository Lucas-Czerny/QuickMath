#pragma once

#define ASSERT(x, message) \
	if (!(x)) __debugbreak();

namespace qmath
{
    struct iterator
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = float;
        using pointer = float*;
        using reference = float&;

    private:
        pointer m_Pointer;

    public:
        iterator(pointer ptr) : m_Pointer(ptr) {}

        reference operator*() const { return *m_Pointer; }
        pointer operator->() { return m_Pointer; }

        iterator& operator++() { m_Pointer++; return *this; }

        iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }

        friend bool operator== (const iterator& a, const iterator& b) { return a.m_Pointer == b.m_Pointer; };
        friend bool operator!= (const iterator& a, const iterator& b) { return a.m_Pointer != b.m_Pointer; };
    };
}