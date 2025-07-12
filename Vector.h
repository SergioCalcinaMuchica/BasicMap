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
        Vector(int tam=10);
        ~Vector();
        void pushback(T);
        void remove(int);
        bool search(T);
        void print();
        int size();
        T& operator[](int);
};

template <typename T>
Vector<T>::Vector(int tam){
    capacity=tam;
    index=0;
    data = new T[tam];
}

template <typename T>
Vector<T>::~Vector(){
    delete[] data;
}

template <typename T>
void Vector<T>::pushback(T dato){
    if(index==capacity){
        capacity = capacity * 2;
        T* temporal = new T[capacity];
        for(int i=0;i<index;i++){
            temporal[i]=data[i];
        }
        delete[]data;
        data=temporal;
    }
    data[index]=dato;
    index++;
}

template <typename T>
void Vector<T>::remove(int indice){
    if (indice < 0 || indice >= index) return;

    data[indice] = T();
    for(int i=indice;i<index-1;i++){
        data[i] = data[i+1];
    }
    index--;
    if(index > 0 && index == capacity/4){
        capacity = capacity/2;
        T* temporal = new T[capacity];
        for(int i=0;i<index;i++){
            temporal[i]=data[i];
        }
        delete[] data;
        data=temporal;
    }
}

template <typename T>
bool Vector<T>::search(T val){
    for(int i=0;i<index;i++){
        if(data[i]==val){
            return true;
        }
    }
    return false;
}

template <typename T>
void Vector<T>::print(){
    for(int i=0;i<index;i++){
        cout<<data[i]<<"-";
    }
    cout<<endl;
}

template <typename T>
int Vector<T>::size(){
    return index;
}

template <typename T>
T& Vector<T>::operator[](int indice){
    if(indice < 0 || indice >= index){
        throw out_of_range("Index out of range");
    }
    return data[indice];
}