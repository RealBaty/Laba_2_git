//
// Created by Dima on 08.11.2020.
//

#ifndef DATASTRUCTURE_TREESORTER_H
#define DATASTRUCTURE_TREESORTER_H
#include "Sorter.h"
#include "CartesianTree.h"

template <class T>
class TreeSorter: public Sorter<T>
{
public:
    void Sort(Sequence<T> *a) override;
};

template <class T>
void TreeSorter<T>::Sort(Sequence<T> *a)
{
    CartesianTree<T> *tree = new CartesianTree<T>();
    while(a->GetSize()>0)
    {
        tree->Insert(a->GetFirst());
        a->Erase(0);
    }
    for(int i=0;i< tree->Size(); ++i)
    {
        a->Prepend(tree->GetKth(i));
    }
    delete tree;
}



#endif //DATASTRUCTURE_TREESORTER_H
