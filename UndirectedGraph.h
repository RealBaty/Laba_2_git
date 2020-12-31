//
// Created by Dima on 28.12.2020.
//

#ifndef LABAALL_UNDIRECTEDGRAPH_H
#define LABAALL_UNDIRECTEDGRAPH_H
#include "iostream"
#include "SparseMatrix.h"
#include "Graph.h"

template <class T>
class UndirectedGraph: public Graph<T> {
private:
    SparseMatrix<T> *data;
    int n;
public:
    UndirectedGraph(int size)
    {
        data = new SparseMatrix<T>();
        n = size;
    }
    int Size() override
    {
        return n;
    }
    bool IsEdge(int x, int y) override
    {
        if(x<0 || x>=n || y<0 || y>=n)
            throw logic_error("OutOfRange");
        return !data->IsNull(x, y);
    }
    void SaveEdge(int x, int y, T el) override
    {
        if(x<0 || x>=n || y<0 || y>=n)
            throw logic_error("OutOfRange");
        data->Set(x, y, el);
        data->Set(y, x, el);
    }
    void DeleteEdge(int x, int y) override
    {
        if(x<0 || x>=n || y<0 || y>=n)
            throw logic_error("OutOfRange");
        data->Delete(x, y);
        data->Delete(y, x);
    }
    T GetEdge(int x, int y) override
    {
        if(x<0 || x>=n || y<0 || y>=n || data->IsNull(x, y))
            throw logic_error("NotFound");
        return data->Get(x, y);
    }
};


#endif //LABAALL_UNDIRECTEDGRAPH_H
