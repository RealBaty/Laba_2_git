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
        DynamicArray();
        DynamicArray(T *items, int l);
        DynamicArray(int l);
        DynamicArray(DynamicArray<T> &DynamicArrayConst);
        T Get(int index);
        int GetSize();
        void Set(T item, int index);
        void Resize(int newsize);
        ~DynamicArray();

};

template <class T>
DynamicArray<T>::DynamicArray()
{
    len = 0;
    data = nullptr;
}

template <class T>
DynamicArray<T>::DynamicArray(T *items, int l)
{
    len = l;
    if(l!=0)
        data = new T[l];
    else
        data = nullptr;
    for(int i=0;i<l;++i)
    {
        this->Set(i, items[i]);
    }
}

template <class T>
DynamicArray<T>::DynamicArray(int l)
{
    len = l;
    if(l!=0)
        data = new T[l];
    else
        data = nullptr;
}

template <class T>
DynamicArray<T>::DynamicArray(DynamicArray<T> &DynamicArrayConst)
{
    len = DynamicArrayConst->len;
    if(DynamicArrayConst->len!=0)
        data = new T[len];
    else
        data = nullptr;
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
        cout<<"IndexOutOfRange1\n";
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
void DynamicArray<T>::Set(T item, int index)
{
    if(index<0 || index>=len)
    {
        cout<<"IndexOutOfRange2\n";
    }
    else
    {
        cout<<index<<" "<<this->GetSize()<<endl;
        cout<<"0000000000000000000000000000"<<endl;
        this->data[index] = item;
        cout<<"0000000000000000000000000000"<<endl;
    }
}

template <class T>
void DynamicArray<T>::Resize(int newsize)
{
    if(newsize!=len)
    {
        if(newsize!=0)
            T *newdata = new T[newsize];
        else
            T *newdata = nullptr;
        for(int i=0;i<newsize && i<len;++i)
            newdata[i] = this->Get(i);
        len = newsize;
        delete(data);
        data = newdata;
    }
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
    delete(data);
}

#endif // DYNAMICARRAY_H_INCLUDED
