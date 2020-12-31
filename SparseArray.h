//
// Created by Dima on 28.12.2020.
//

#ifndef LABAALL_SPARSEARRAY_H
#define LABAALL_SPARSEARRAY_H
#include <iostream>
#include "IDictionaryTree.h"

template <class T>
class SparseArray {
private:
    IDictionary<int, T> *data;
public:
    SparseArray()
    {
        data = new IDictionaryTree<int, T>();
    }

    int Size()
    {
        return data->Size();
    }

    void Set(int x, T el)
    {
        if(data->ContainsKey(x))
            data->Erase(x);
        data->Add(x, el);
    }
    T Get(int x)
    {
        return data->Get(x);
    }
    void Delete(int x)
    {
        if(data->ContainsKey(x))
            data->Erase(x);
    }
    bool IsNull(int x)
    {
        return !data->ContainsKey(x);
    }

};


#endif //LABAALL_SPARSEARRAY_H
