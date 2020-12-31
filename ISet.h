//
// Created by Dima on 26.12.2020.
//

#ifndef LABAALL_ISET_H
#define LABAALL_ISET_H


template <class T>
class ISet {
public:
    virtual void Add(T el) = 0;
    virtual T GetKth(int index) = 0;
    virtual bool Empty() = 0;
    virtual int Size() = 0;
    virtual bool Find(T el) = 0;
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual void Erase(T el) = 0;
    virtual void EraseKth(int index) = 0;
    virtual void Union(ISet<T> *set) = 0;
    virtual int IndexOfElem(T el) = 0;
};


#endif //LABAALL_ISET_H
