//
// Created by Dima on 08.11.2020.
//

#ifndef DATASTRUCTURE_SORTER_H
#define DATASTRUCTURE_SORTER_H

#include "Sequence.h"

template<class T>
class Sorter
{
public:
    virtual void Sort(Sequence<T> *a) = 0;
};

#endif //DATASTRUCTURE_SORTER_H
