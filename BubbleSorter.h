//
// Created by Dima on 08.11.2020.
//

#ifndef DATASTRUCTURE_BUBBLESORTER_H
#define DATASTRUCTURE_BUBBLESORTER_H

#include "Sorter.h"

template<class T>
class BubbleSorter: public Sorter<T>
{
public:
    void Sort(Sequence<T> *a) override;
};

template <class T>
void BubbleSorter<T>::Sort(Sequence<T> *a)
{
    for(long long i=0;i<a->GetSize();++i)
    {
        bool f=false;
        for(long long j=1;j<a->GetSize();++j)
        {
            if(a->Get(j)<a->Get(j-1))
            {
                T c=a->Get(j);
                a->Set(a->Get(j-1), j);
                a->Set(c, j-1);
                f=true;
            }
        }
        if(!f)
            break;
    }
}

#endif //DATASTRUCTURE_BUBBLESORTER_H
