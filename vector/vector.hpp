#ifndef GEN_H
#define GEN_H
#pragma once
#include <iostream>
using namespace std;

template<typename T> class vect {
    private:
        int size;
        T* data;
    public:
        vect();
        vect(vect<T> &b);
        ~vect();
        int getsize();
        T& operator[](int index);
        void push_back(T val);
        T pop_back();
        void insert(int index, T val);
        void remove(int index);
        void print();
};

template <typename T>
int vect<T>::getsize() {
    return this->size;
}

template <typename T>
T& vect<T>::operator[](int index) {
    return data[index];
}

template <typename T>
vect<T>::vect() {
    size=0;
    data = new T[size];
}

template <typename T>
vect<T>::vect(vect<T> &b) {
    size = b.getsize();
    data = new T[size];

    for (int i=0; i<size; i++) {
        data[i] = b.data[i];
    }
}

template <typename T>
vect<T>::~vect(){
    delete[] data; 
}

template <typename T>
void vect<T>::push_back(T val) {
    T* tmp = new T[size + 1];
    for (int i=0; i<size; i++) {
        tmp[i] = data[i];
    }
    tmp[size] = val;
    size++;
    delete[] data;
    data = tmp;
}

template <typename T>
T vect<T>::pop_back() {
    T* tmp= new T[size -1];
    for (int i=0; i<size-1; i++) {
        tmp[i] = data[i];
    }
    T pop_obj = data[size-1];
    delete[] data;
    data = tmp;
    size--;
    return pop_obj;
}

template <typename T>
void vect<T>::insert(int index, T val) {
    T* tmp = new T[size +1];
    for (int i =0;i<size+1; i++){
        if (i < index)
            tmp[i] = data[i];
        else if (i == index)
            tmp[index] = val;
        else 
            tmp[i] = data[i-1];
    }
    delete[] data;
    data = tmp;
    size++;
}

template <typename T>
void vect<T>::remove(int index) {
    T* tmp = new T[size -1];
    for (int i=0;i<size;i++) {
        if (i<index)
            tmp[i]=data[i];
        else if (i>index)
            tmp[i-1]= data[i];
    }
    delete[] data;
    data=tmp;
    size--;
}


template <typename T>
void vect<T>::print() {
    for (int i=0; i<size; i++) {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

#endif
