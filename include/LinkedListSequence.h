#ifndef LINKEDLISTSEQUENCE_H_INCLUDED
#define LINKEDLISTSEQUENCE_H_INCLUDED
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
        LinkedListSequence(T* items, int l);
        LinkedListSequence(Sequence<T> *list);
        T GetFirst() override;
        T GetLast() override;
        T Get(int index) override;
        Sequence<T>* GetSubSequence(int leftindex, int rightindex) override;
        int GetSize() override;
        void Append(T item) override;
        void Prepend(T item) override;
        void InsertAt(T item, int index) override;
        void Set(T item, int index) override;
        void Erase(int index) override;
        void Concat(Sequence<T> *list) override;
        ~LinkedListSequence();
};

template <class T>
LinkedListSequence<T>::LinkedListSequence()
{
    data = new LinkedList<T>();
}

template <class T>
LinkedListSequence<T>::LinkedListSequence(T* items, int l)
{
    data = new LinkedList<T>(items, l);
}

template <class T>
LinkedListSequence<T>::LinkedListSequence(Sequence<T> *list)
{
    data = new LinkedList<T>();
    for(int i=0;i<list->GetSize();++i)
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
T LinkedListSequence<T>::Get(int index)
{
    return data->Get(index);
}

template <class T>
Sequence<T>* LinkedListSequence<T>::GetSubSequence(int leftindex, int rightindex)
{
    if(leftindex<0 || leftindex>=data->GetSize() || rightindex<0 || rightindex>=data->GetSize())
    {
        cout<<"Indexoutofren\n";
        return 0;
    }
    else
    {
        Sequence<T> *res = new LinkedListSequence<T>();
        for(int i=leftindex;i<=rightindex;++i)
        {
            res->Prepend(data->Get(i));
        }
        return res;
    }
}

template <class T>
int LinkedListSequence<T>::GetSize()
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
void LinkedListSequence<T>::InsertAt(T item, int index)
{
    data->InsertAt(item, index);
}

template <class T>
void LinkedListSequence<T>::Set(T item, int index)
{
    data->Set(item, index);
}

template <class T>
void LinkedListSequence<T>::Erase(int index)
{
    data->Erase(index);
}

template <class T>
void LinkedListSequence<T>::Concat(Sequence<T> *list)
{
    for(int i=0;i<list->GetSize();++i)
    {
        data->Prepend(list->Get(i));
    }
}

template <class T>
LinkedListSequence<T>::~LinkedListSequence()
{
    delete(data);
}

#endif // LINKEDLISTSEQUENCE_H_INCLUDED
