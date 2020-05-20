#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED

#include <iostream>

using namespace std;

template <class T>
class DynamicArray
{
    private:
        T *data;
        int len;
    public:
        DynamicArray(T *items, int l);
        DynamicArray(int l);
        DynamicArray(DynamicArray<T> &DynamicArrayConst);
        T Get(int index);
        int GetSize();
        void Set(int index, T value);
        void Resize(int newsize);
};

template <class T>
DynamicArray<T>::DynamicArray(T *items, int l)
{
    len = l;
    data = new T[l];
    for(int i=0;i<l;++i)
    {
        this->Set(i, items[i]);
    }
}

template <class T>
DynamicArray<T>::DynamicArray(int l)
{
    len = l;
    data = new T[l];
}

template <class T>
DynamicArray<T>::DynamicArray(DynamicArray<T> &DynamicArrayConst)
{
    len = DynamicArrayConst->len;
    data = new T[len];
    for(int i=0;i<len;++i)
    {
        this->Set(i, DynamicArrayConst->Get(i));
    }
}

template <class T>
T DynamicArray<T>::Get(int index)
{
    if(index<0 || index>=len)
    {
        cout<<"IndexOutOfRange\n";
        return 0;
    }
    return data[index];
}

template <class T>
int DynamicArray<T>::GetSize()
{
    return len;
}

template <class T>
void DynamicArray<T>::Set(int index, T value)
{
    if(index<0 || index>=len)
    {
        cout<<"IndexOutOfRange\n";
    }
    else
    {
        data[index]=value;
    }
}

template <class T>
void DynamicArray<T>::Resize(int newsize)
{
    if(newsize!=len)
    {
        T *newdata = new T[newsize];
        for(int i=0;i<newsize && i<len;++i)
            newdata[i] = this->Get(i);
        len = newsize;
        delete(data);
        data = newdata;
    }
}

#endif // DYNAMICARRAY_H_INCLUDED
