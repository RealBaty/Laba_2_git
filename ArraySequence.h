//
// Created by Dima on 08.11.2020.
//

#ifndef DATASTRUCTURE_ARRAYSEQUENCE_H
#define DATASTRUCTURE_ARRAYSEQUENCE_H


#include <iostream>
#include "Sequence.h"
#include "DynamicArray.h"


template<class T>
class ArraySequence: public Sequence<T>
{
private:
    DynamicArray<T> *data;
    long long left, right;
public:
    ArraySequence();
    ArraySequence(long long n);
    ArraySequence(T* items, long long l);
    ArraySequence(Sequence<T> *list);
    T GetFirst() override;
    T GetLast() override;
    T Get(long long index) override;
    Sequence<T>* GetSubSequence(long long leftindex, long long rightindex) override;
    long long GetSize() override;
    void Append(T item) override;
    void Prepend(T item) override;
    void InsertAt(T item, long long index) override;
    void Set(T item, long long index) override;
    void Erase(long long index) override;
    void Concat(Sequence<T> *list) override;
    void EraseAllOf(function<bool(T)> f) override;
    ~ArraySequence();
};

template <class T>
ArraySequence<T>::ArraySequence()
{
    data = new DynamicArray<T>();
    left = 0;
    right = -1;
}

template <class T>
ArraySequence<T>::ArraySequence(long long l)
{
    data = new DynamicArray<T>(l);
    left = 0;
    right = l-1;
}

template <class T>
ArraySequence<T>::ArraySequence(T* items, long long l)
{
    data = new DynamicArray<T>(l*3);
    for(long long i=l;i<2*l;++i)
    {
        data->Set(items[i-l], i);
    }
    left = l;
    right = 2*l-1;
}

template <class T>
ArraySequence<T>::ArraySequence(Sequence<T> *list)
{
    data = new DynamicArray<T>(list->GetSize());
    for(long long i=0;i<list->GetSize();++i)
    {
        data->Set(list->Get(i), i);
    }
    left = 0;
    right = list->GetSize()-1;
}

template <class T>
T ArraySequence<T>::GetFirst()
{
    if(this->GetSize() == 0)
    {
        cout<<"Indexoutofreng\n";
    }
    else
        return data->Get(left);
}

template <class T>
T ArraySequence<T>::GetLast()
{
    if(this->GetSize() == 0)
    {
        cout<<"Indexoutofreng\n";
    }
    else
        return data->Get(right);
}

template <class T>
T ArraySequence<T>::Get(long long index)
{
    if(index<0||index>=this->GetSize())
    {
        cout<<index<<" Indexoutofreng\n";
    }
    else
        return data->Get(index+left);
}

template <class T>
Sequence<T>* ArraySequence<T>::GetSubSequence(long long leftindex, long long rightindex)
{
    if(leftindex<0 || leftindex>=this->GetSize() || rightindex<0 || rightindex>=this->GetSize())
    {
        cout<<"Indexoutofren\n";
        return 0;
    }
    else
    {
        if(leftindex>rightindex)
        {
            Sequence<T> *res = new ArraySequence<T>();
            return res;
        }
        T *res1 = new T[rightindex-leftindex+1];
        for(long long i=leftindex;i<=rightindex;++i)
        {
            res1[i-leftindex] = this->Get(i);
        }
        Sequence<T> *res = new ArraySequence<T>(res1, rightindex-leftindex+1);
        return res;
    }
}

template <class T>
long long ArraySequence<T>::GetSize()
{
    return right-left+1;
}

template <class T>
void ArraySequence<T>::Append(T item)
{
    if(left>0)
    {
        left--;
        this->data->Set(item, left);
    }
    else
    {
        DynamicArray<T> *newdata = new DynamicArray<T>((this->GetSize()+1)*3);
        long long left1=this->GetSize()+1;
        long long right1=(this->GetSize()+1)*2-1;
        newdata->Set(item, left1);
        for(long long i=left1+1;i<=right1;++i)
        {
            newdata->Set(this->Get(i-left1-1), i);
        }
        delete(data);
        data = newdata;
        left = left1;
        right = right1;
    }
}

template <class T>
void ArraySequence<T>::Prepend(T item)
{
    if(right<data->GetSize()-1)
    {
        data->Set(item, right+1);
        right++;
    }
    else
    {
        DynamicArray<T> *newdata = new DynamicArray<T>((this->GetSize()+1)*3);
        long long left1=this->GetSize()+1;
        long long right1=(this->GetSize()+1)*2-1;
        newdata->Set(item, right1);
        for(long long i=left1;i<right1;++i)
        {
            newdata->Set(this->Get(i-left1), i);
        }
        delete(data);
        data = newdata;
        left = left1;
        right = right1;
    }
}

template <class T>
void ArraySequence<T>::InsertAt(T item, long long index)
{
    if(index<0||index>this->GetSize())
    {
        cout<<"Indexoutofreng\n";
    }
    else if(index == 0)
    {
        this->Append(item);
    }
    else if(index == this->GetSize())
    {
        this->Prepend(item);
    }
    else
    {

        DynamicArray<T> *newdata = new DynamicArray<T>((this->GetSize()+1)*3);
        long long left1=this->GetSize()+1;
        long long right1=(this->GetSize()+1)*2-1;
        for(long long i=left1;i<left1+index;++i)
        {
            newdata->Set(this->Get(i-left1), i);
        }
        newdata->Set(item, left1+index);
        for(long long i=left1+index+1;i<=right1;++i)
        {
            newdata->Set(this->Get(i-left1-1), i);
        }
        delete(data);
        data = newdata;
        left = left1;
        right = right1;
    }
}

template <class T>
void ArraySequence<T>::Set(T item, long long index)
{
    if(index<0||index>=this->GetSize())
    {
        cout<<"Indexoutofreng\n"<<index<<endl;
    }
    else
        data->Set(item, index+left);
}

template <class T>
void ArraySequence<T>::Erase(long long index)
{
    if(index<0||index>=this->GetSize())
    {
        cout<<"Indexoutofreng\n";
    }
    else if(index == 0)
    {
        left++;
    }
    else if(index == this->GetSize()-1)
    {
        right--;
    }
    else
    {
        for(long long i=index;i<this->GetSize()-1;++i)
        {
            data->Set(data->Get(i+left+1),i+left);
        }
        right--;
    }
}

template <class T>
void ArraySequence<T>::Concat(Sequence<T> *list)
{
    DynamicArray<T> *newdata = new DynamicArray<T>((this->GetSize()+list->GetSize())*3);
    long long left1=this->GetSize()+list->GetSize();
    long long right1=(this->GetSize()+list->GetSize())*2-1;
    for(long long i=0;i<this->GetSize();++i)
    {
        newdata->Set(this->Get(i),i+left1);
    }
    for(long long i=this->GetSize();i<this->GetSize()+list->GetSize();++i)
    {
        newdata->Set(list->Get(i-this->GetSize()),i+left1);
    }
    delete(data);
    left=left1;
    right=right1;
    data=newdata;
}

template<class T>
void ArraySequence<T>::EraseAllOf(function<bool(T)> f)
{
    long long t=0;
    for(long long i=0;i<this->GetSize();++i)
    {
        if(!f(this->Get(i)))
        {
            this->Set(this->Get(i), t);
            t++;
        }
    }
    right = t-1+left;
}

template <class T>
ArraySequence<T>::~ArraySequence()
{
    delete(data);
}


#endif //DATASTRUCTURE_ARRAYSEQUENCE_H
