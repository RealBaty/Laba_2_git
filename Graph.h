//
// Created by Dima on 28.12.2020.
//

#ifndef LABAALL_GRAPH_H
#define LABAALL_GRAPH_H

template <class T>
class Graph{
public:
    virtual bool IsEdge(int x, int y) = 0;
    virtual void SaveEdge(int x, int y, T el) = 0;
    virtual void DeleteEdge(int x, int y) = 0;
    virtual T GetEdge(int x, int y) = 0;
    virtual int Size() = 0;
};


#endif //LABAALL_GRAPH_H
