//
// Created by Dima on 08.11.2020.
//

#ifndef DATASTRUCTURE_SEQUENCE_H
#define DATASTRUCTURE_SEQUENCE_H


#include<functional>


template <class T>
class Sequence
{
public:
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(long long index) = 0;
    virtual Sequence<T>* GetSubSequence(long long leftindex, long long rightindex) = 0;
    virtual long long GetSize() = 0;
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item, long long index) = 0;
    virtual void Set(T item, long long index) = 0;
    virtual void Erase(long long index) = 0;
    virtual void Concat(Sequence<T> *list) = 0;
    virtual void EraseAllOf(std::function<bool(T)> f) = 0;

};

#endif //DATASTRUCTURE_SEQUENCE_H
