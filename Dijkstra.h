//
// Created by Dima on 28.12.2020.
//

#ifndef LABAALL_DIJKSTRA_H
#define LABAALL_DIJKSTRA_H
#include "ArraySequence.h"
#include "Graph.h"
#include "UndirectedGraph.h"
#include "DirectedGraph.h"
#include <iostream>
#include "ISortedSequenceTree.h"

template <class T>
Sequence<pair<bool, T> >* Dijkstra(Graph<T> *g, int s, T start)
{
    Sequence<pair<bool, T> > *dist = new ArraySequence<pair<bool, T> >(g->Size());
    for(int i=0;i<dist->GetSize();++i)
    {
        dist->Set({true, start}, i);
    }
    dist->Set({false, start}, s);
    ISortedSequence<pair<pair<bool, T>, int> > *q = new ISortedSequenceTree<pair<pair<bool, T>, int> >();
    q->Add({dist->Get(s), s});
    while (q->Size() != 0)
    {
        int v = q->GetFirst().second;
        q->EraseAll(q->GetFirst());
        for(int to=0;to<g->Size();++to)
        {
            if(g->IsEdge(v, to))
            {
                T len = g->GetEdge(v, to);
                if(make_pair(false, dist->Get(v).second + len) < dist->Get(to))
                {
                    q->Erase({dist->Get(to), to});
                    dist->Set({false, dist->Get(v).second + len}, to);
                    q->Add({dist->Get(to), to});
                }
            }
        }
    }
    return dist;
}


#endif //LABAALL_DIJKSTRA_H
