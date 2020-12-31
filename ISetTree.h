//
// Created by Dima on 27.12.2020.
//

#ifndef LABAALL_ISETTREE_H
#define LABAALL_ISETTREE_H
#include "ISet.h"
#include "CartesianTree.h"

template <class T>
class ISetTree: public ISet<T>{
private:
    CartesianTree<T> *data;
public:
    ISetTree()
    {
        data = new CartesianTree<T>();
    }
    ISetTree(function<bool(T&, T&)> cmp)
    {
        data = new CartesianTree<T>(cmp);
    }
    void Add(T el) override
    {
        if(!Find(el))
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
        data->EraseAll(el);
    }
    void EraseKth(int index) override
    {
        data->EraseKth(index);
    }
    void Union(ISet<T> *set) override
    {
        for(int i=0; i<set->Size(); ++i)
        {
            Add(set->GetKth(i));
        }
    }
    int IndexOfElem(T el) override
    {
        return IndexOfElem(el);
    }

    ~ISetTree()
    {
        delete data;
    }
};


#endif //LABAALL_ISETTREE_H
