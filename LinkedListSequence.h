//
// Created by Dima on 08.11.2020.
//

#ifndef DATASTRUCTURE_LINKEDLISTSEQUENCE_H
#define DATASTRUCTURE_LINKEDLISTSEQUENCE_H

#include <iostream>
#include "Sequence.h"
#include "LinkedList.h"

using namespace std;

template<class T>
class LinkedListSequence: public Sequence<T>
{
private:
    LinkedList<T> *data;
public:
    LinkedListSequence();
    LinkedListSequence(T* items, long long l);
    LinkedListSequence(Sequence<T> *list);
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
    ~LinkedListSequence();
};

template <class T>
LinkedListSequence<T>::LinkedListSequence()
{
    data = new LinkedList<T>();
}

template <class T>
LinkedListSequence<T>::LinkedListSequence(T* items, long long l)
{
    data = new LinkedList<T>(items, l);
}

template <class T>
LinkedListSequence<T>::LinkedListSequence(Sequence<T> *list)
{
    data = new LinkedList<T>();
    for(long long i=0;i<list->GetSize();++i)
    {
        data->Prepend(list->Get(i));
    }
}

template <class T>
T LinkedListSequence<T>::GetFirst()
{
    return data->GetFirst();
}

template <class T>
T LinkedListSequence<T>::GetLast()
{
    return data->GetLast();
}

template <class T>
T LinkedListSequence<T>::Get(long long index)
{
    return data->Get(index);
}

template <class T>
Sequence<T>* LinkedListSequence<T>::GetSubSequence(long long leftindex, long long rightindex)
{
    if(leftindex<0 || leftindex>=data->GetSize() || rightindex<0 || rightindex>=data->GetSize())
    {
        cout<<"Indexoutofren\n";
        return 0;
    }
    else
    {
        Sequence<T> *res = new LinkedListSequence<T>();
        for(long long i=leftindex;i<=rightindex;++i)
        {
            res->Prepend(data->Get(i));
        }
        return res;
    }
}

template <class T>
long long LinkedListSequence<T>::GetSize()
{
    return data->GetSize();
}

template <class T>
void LinkedListSequence<T>::Append(T item)
{
    data->Append(item);
}

template <class T>
void LinkedListSequence<T>::Prepend(T item)
{
    data->Prepend(item);
}

template <class T>
void LinkedListSequence<T>::InsertAt(T item, long long index)
{
    data->InsertAt(item, index);
}

template <class T>
void LinkedListSequence<T>::Set(T item, long long index)
{
    data->Set(item, index);
}

template <class T>
void LinkedListSequence<T>::Erase(long long index)
{
    data->Erase(index);
}

template <class T>
void LinkedListSequence<T>::Concat(Sequence<T> *list)
{
    for(long long i=0;i<list->GetSize();++i)
    {
        data->Prepend(list->Get(i));
    }
}

template <class T>
LinkedListSequence<T>::~LinkedListSequence()
{
    delete(data);
}

template <class T>
void LinkedListSequence<T>::EraseAllOf(function<bool(T)> f)
{
    for(long long i=this->GetSize()-1;i>=0;--i)
    {
        if(f(this->Get(i)))
            this->Erase(i);
    }
}


#endif //DATASTRUCTURE_LINKEDLISTSEQUENCE_H
