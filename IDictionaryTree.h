//
// Created by Dima on 27.12.2020.
//

#ifndef LABAALL_IDICTIONARYTREE_H
#define LABAALL_IDICTIONARYTREE_H
#include "CartesianTree.h"
#include "IDictionary.h"


template <class TKey, class TElem>
class IDictionaryTree: public IDictionary<TKey, TElem> {
private:
    CartesianTree<pair<TKey, TElem> > *data;
public:
    IDictionaryTree()
    {
        data = new CartesianTree<pair<TKey, TElem> >([](pair<TKey, TElem> &a, pair<TKey, TElem> &b){return a.first<b.first;});
    }
    IDictionaryTree(function<bool(TKey&, TKey&)> cmp)
    {
        data = new CartesianTree<pair<TKey, TElem> >([cmp](pair<TKey, TElem> &a, pair<TKey, TElem> &b){return cmp(a.first, b.first);});
    }
    int Size() override
    {
        data->Size();
    }
    TElem Get(TKey key) override
    {
        pair<TKey, TElem> a;
        a.first = key;
        return data->GetKth(data->IndexOfElem(a)).second;
    }
    bool ContainsKey(TKey key) override
    {
        pair<TKey, TElem> a;
        a.first = key;
        return data->Find(a);
    }
    void Add(TKey key, TElem elem) override
    {
        pair<TKey, TElem> a;
        a = {key, elem};
        if(!data->Find(a))
            data->Insert(a);
    }
    void Erase(TKey key) override
    {
        pair<TKey, TElem> a;
        a.first = key;
        data->EraseAll(a);
    }
};


#endif //LABAALL_IDICTIONARYTREE_H
