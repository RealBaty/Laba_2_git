//
// Created by Dima on 08.11.2020.
//

#ifndef DATASTRUCTURE_CARTESIANTREE_H
#define DATASTRUCTURE_CARTESIANTREE_H

#include "Cartesian.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include <iostream>

using namespace std;

template <class T>
class CartesianTree
{
private:
    Cartesian<T> *data;

    CartesianFunction<T> *Func;

    CartesianTree(Cartesian<T> *elem)
    {
        data = elem;
        Func = new CartesianFunction<T>();
    }

    CartesianTree(Cartesian<T> *elem, function<bool(T&, T&)> cmp)
    {
        data = elem;
        Func = new CartesianFunction<T>(cmp);
    }

public:
    CartesianTree()
    {
        data = nullptr;
        Func = new CartesianFunction<T>();
    }

    CartesianTree(function<bool(T&, T&)> cmp)
    {
        data = nullptr;
        Func = new CartesianFunction<T>(cmp);
    }

    bool Find(T key)
    {
        return Func->Exists(data, key);
    }

    int IndexOfElem(T key)
    {
        return Func->IndexOfElem(data, key);
    }

    T GetKth(int index)
    {
        return Func->Kth(data, index);
    }

    Cartesian<T>* GetKthNode(int index)
    {
        return Func->KthNode(data, index);
    }

    Sequence<T>* GetList(string s)
    {
        Sequence<T> *res = new LinkedListSequence<T>();
        Func->GetSequence(data, res, s);
        return res;
    }

    int Size()
    {
        return Func->GetSize(data);
    }

    void Insert(T key)
    {
        Cartesian<T> *elem = new Cartesian<T>(key);
        auto root = Func->LeftSplit(data, key);
        root.first = Func->Merge(root.first, elem);
        data = Func->Merge(root.first, root.second);
    }

    void Insert(T key, int prior)
    {
        Cartesian<T> *elem = new Cartesian<T>(key, prior);
        auto root = Func->LeftSplit(data, key);
        root.first = Func->Merge(root.first, elem);
        data = Func->Merge(root.first, root.second);
    }

    void InsertKth(T key, int index)
    {
        Cartesian<T> *elem = new Cartesian<T>(key);
        auto root = Func->SplitKth(data, index);
        root.first = Func->Merge(root.first, elem);
        data = Func->Merge(root.first, root.second);
    }

    void InsertKth(CartesianTree<T> *key, int index)
    {
        Cartesian<T> *elem = key->data;
        auto root = Func->SplitKth(data, index);
        root.first = Func->Merge(root.first, elem);
        data = Func->Merge(root.first, root.second);
        key->data = data;
    }

    void PushBack(T key)
    {
        this->Insert(key, this->Size());
    }

    void PushFront(T key)
    {
        this->Insert(key, 0);
    }

    void EraseAll(T key)
    {
        auto root1 = Func->LeftSplit(data, key);
        auto root2 = Func->RightSplit(root1.first, key);
        delete root2.second;
        data = Func->Merge(root2.first, root1.second);
    }

    void EraseKth(int index)
    {
        auto root1 = Func->SplitKth(data, index + 1);
        auto root2 = Func->SplitKth(root1.first, index);
        delete root2.second;
        data = Func->Merge(root2.first, root1.second);
    }

    void EraseKth(int index1, int index2)
    {
        auto root1 = Func->SplitKth(data, index2 + 1);
        auto root2 = Func->SplitKth(root1.first, index1);
        delete root2.second;
        data = Func->Merge(root2.first, root1.second);
    }

    CartesianTree<T>* Cut(int index1, int index2)
    {
        auto root1 = Func->SplitKth(data, index2 + 1);
        auto root2 = Func->SplitKth(root1.first, index1);
        CartesianTree<T> *res = new CartesianTree(root2.second, Func->GetCmp());
        data = Func->Merge(root2.first, root1.second);
        return res;
    }

    int Height()
    {
        return Func->Depth(data);
    }

    void StitchTree(string s)
    {
        Cartesian<T> *root1;
        //cout<<"root1"<<endl;
        root1 = nullptr;
        //cout<<"openstith"<<endl;
        Func->Stitch(&root1, data, s);
    }

    ~CartesianTree()
    {
        delete data;
        delete Func;
    }
};

#endif //DATASTRUCTURE_CARTESIANTREE_H
