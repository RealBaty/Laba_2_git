//
// Created by Dima on 27.12.2020.
//

#ifndef LABAALL_ISORTEDSEQUENCE_H
#define LABAALL_ISORTEDSEQUENCE_H
#include <iostream>

template <class T>
class ISortedSequence {
public:
    virtual void Add(T el) = 0;
    virtual T GetKth(int index) = 0;
    virtual bool Empty() = 0;
    virtual int Size() = 0;
    virtual bool Find(T el) = 0;
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual void Erase(T el) = 0;
    virtual void EraseAll(T el) = 0;
    virtual void EraseKth(int index) = 0;
    virtual void EraseKth(int index1, int index2) = 0;
    virtual int IndexOfElem(T el) = 0;
    virtual ISortedSequence<T>* Cut(int index1, int index2) = 0;
};


#endif //LABAALL_ISORTEDSEQUENCE_H
