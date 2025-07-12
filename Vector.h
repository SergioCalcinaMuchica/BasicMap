#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Vector{
    private:
        T* data;
        int index;
        int capacity;
    public:
        Vector(int);
        ~Vector();
        void pushback(T);
        void remove(int);
        bool search(T);
        void print();
        int size();
        T& operator[](int);
};