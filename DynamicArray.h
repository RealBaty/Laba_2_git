//
// Created by Dima on 08.11.2020.
//

#ifndef DATASTRUCTURE_DYNAMICARRAY_H
#define DATASTRUCTURE_DYNAMICARRAY_H


#include <iostream>

using namespace std;

template <class T>
class DynamicArray
{
private:
    T *data;
    long long len;
public:
    DynamicArray();
    DynamicArray(T *items, long long l);
    DynamicArray(long long l);
    DynamicArray(long long l, T item);
    DynamicArray(DynamicArray<T> *DynamicArrayConst);
    T Get(long long index);
    long long GetSize();
    void Set(T item, long long index);
    void Resize(long long newsize);
    ~DynamicArray();

};

template <class T>
DynamicArray<T>::DynamicArray()
{
    len = 0;
    data = nullptr;
}

template <class T>
DynamicArray<T>::DynamicArray(T *items, long long l)
{
    len = l;
    if(l!=0)
        data = new T[l];
    else
        data = nullptr;
    for(long long i=0;i<l;++i)
    {
        this->Set(items[i], i);
    }
}

template <class T>
DynamicArray<T>::DynamicArray(long long l, T item)
{
    len = l;
    if(l!=0)
        data = new T[l];
    else
        data = nullptr;
    for(long long i=0;i<l;++i)
    {
        this->Set(item, i);
    }
}

template <class T>
DynamicArray<T>::DynamicArray(long long l)
{
    len = l;
    if(l!=0)
        data = new T[l];
    else
        data = nullptr;
}

template <class T>
DynamicArray<T>::DynamicArray(DynamicArray<T> *DynamicArrayConst)
{
    len = DynamicArrayConst->len;
    if(DynamicArrayConst->len!=0)
        data = new T[len];
    else
        data = nullptr;
    for(long long i=0;i<len;++i)
    {
        this->Set(DynamicArrayConst->Get(i), i);
    }
}

template <class T>
T DynamicArray<T>::Get(long long index)
{
    if(index<0 || index>=len)
    {
        cout<<"IndexOutOfRange1\n";
    }
    else
        return data[index];
}

template <class T>
long long DynamicArray<T>::GetSize()
{
    return len;
}

template <class T>
void DynamicArray<T>::Set(T item, long long index)
{
    if(index<0 || index>=len)
    {
        cout<<"IndexOutOfRange2\n";
    }
    else
    {
        this->data[index] = item;
    }
}

template <class T>
void DynamicArray<T>::Resize(long long newsize)
{
    if(newsize!=len)
    {
        T *newdata;
        if(newsize!=0)
            newdata = new T[newsize];
        else
            newdata = nullptr;
        for(long long i=0;i<newsize && i<len;++i)
            newdata[i] = this->Get(i);
        len = newsize;
        delete(data);
        data = newdata;
    }
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
    delete data;
}



#endif //DATASTRUCTURE_DYNAMICARRAY_H
