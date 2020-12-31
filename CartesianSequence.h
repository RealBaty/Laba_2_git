//
// Created by Dima on 08.11.2020.
//

#ifndef DATASTRUCTURE_CARTESIANSEQUENCE_H
#define DATASTRUCTURE_CARTESIANSEQUENCE_H


#include "Cartesian.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include <iostream>

using namespace std;

template <class T>
class CartesianSequence
{
private:
    CartesianTree<T> *data;
public:
    CartesianSequence()
    {
        data = new CartesianTree<T>();
    }

    CartesianSequence(function<bool(T&, T&)> cmp)
    {
        data = new CartesianTree<T>(cmp);
    }

    T GetKth(int index)
    {
        return data->GetKth(index);
    }

    int Size()
    {
        return data->Size();
    }

    void InsertKth(T key, int index)
    {
        data->InsertKth(key, index);
    }

    void InsertKth(CartesianSequence<T> *key, int index)
    {
        data->InsertKth(key, index);
    }

    void EraseKth(int index)
    {
        data->EraseKth(index);
    }

    void EraseKth(int index1, int index2)
    {
        data->EraseKth(index1, index2);
    }

    void PushBack(T key)
    {
        data->PushBack(key);
    }

    void PushFront(T key)
    {
        data->PushFront(key);
    }

    int Height()
    {
        return data->Height();
    }

    Sequence<T>* GetList(string s)
    {
        return data->GetList(s);
    }

    ~CartesianSequence()
    {
        delete data;
    }
};


#endif //DATASTRUCTURE_CARTESIANSEQUENCE_H
