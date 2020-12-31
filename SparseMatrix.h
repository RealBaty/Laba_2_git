//
// Created by Dima on 28.12.2020.
//

#ifndef LABAALL_SPARSEMATRIX_H
#define LABAALL_SPARSEMATRIX_H
#include <iostream>
#include "IDictionaryTree.h"

template <class T>
class SparseMatrix {
private:
    IDictionary<pair<int, int>, T> *data;
public:
    SparseMatrix()
    {
        data = new IDictionaryTree<pair<int, int>, T>();
    }

    int Size()
    {
        return data->Size();
    }
    void Set(int x, int y, T el)
    {
        if(data->ContainsKey({x, y}))
            data->Erase({x, y});
        data->Add({x, y}, el);
    }
    T Get(int x, int y)
    {
        return data->Get({x, y});
    }
    void Delete(int x, int y)
    {
        if(data->ContainsKey({x, y}))
            data->Erase({x, y});
    }
    bool IsNull(int x, int y)
    {
        return !data->ContainsKey({x, y});
    }

};


#endif //LABAALL_SPARSEMATRIX_H
