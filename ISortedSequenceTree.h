//
// Created by Dima on 27.12.2020.
//

#ifndef LABAALL_ISORTEDSEQUENCETREE_H
#define LABAALL_ISORTEDSEQUENCETREE_H
#include "ISortedSequence.h"
#include "CartesianTree.h"

template<class T>
class ISortedSequenceTree : public ISortedSequence<T>{
private:
    CartesianTree<T> *data;

    ISortedSequenceTree(CartesianTree<T> *el)
    {
        data = el;
    }

public:
    ISortedSequenceTree()
    {
        data = new CartesianTree<T>();
    }

    ISortedSequenceTree(function<bool(T&, T&)> cmp)
    {
        data = new CartesianTree<T>(cmp);
    }

    void Add(T el) override
    {
        data->Insert(el);
    }

    T GetKth(int index) override
    {
        return data->GetKth(index);
    }

    bool Empty() override
    {
        return (data->Size() == 0);
    }

    int Size() override
    {
        return data->Size();
    }

    bool Find(T el) override
    {
        data->Find(el);
    }

    T GetFirst() override
    {
        return data->GetKth(0);
    }

    T GetLast() override
    {
        return data->GetKth(data->Size()-1);
    }

    void Erase(T el) override
    {
        data->EraseKth(data->IndexOfElem(el));
    }

    void EraseAll(T el) override
    {
        data->EraseAll(el);
    }

    void EraseKth(int index) override
    {
        data->EraseKth(index);
    }

    void EraseKth(int index1, int index2) override
    {
        data->EraseKth(index1, index2);
    }

    int IndexOfElem(T el) override
    {
        return data->IndexOfElem(el);
    }

    ISortedSequence<T>* Cut(int index1, int index2) override
    {
        CartesianTree<T> *el = data->Cut(index1, index2);
        ISortedSequenceTree<T> *res = new ISortedSequenceTree<T>(el);
        return res;
    }

    ~ISortedSequenceTree()
    {
        delete data;
    }
};


#endif //LABAALL_ISORTEDSEQUENCETREE_H
