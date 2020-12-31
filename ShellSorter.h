//
// Created by Dima on 08.11.2020.
//

#ifndef DATASTRUCTURE_SHELLSORTER_H
#define DATASTRUCTURE_SHELLSORTER_H
#include "Sorter.h"

template <class T>
class ShellSorter: public Sorter<T>
{
public:
    void Sort(Sequence<T> *a) override;
private:
    bool Check(long long x)
    {
        while(x%2==0)
            x/=2;
        while(x%3==0)
            x/=3;
        if(x==1)
            return true;
        return false;
    }

};

template <class T>
void ShellSorter<T>::Sort(Sequence<T> *a)
{
    long long inc, i, j;
    for(inc = a->GetSize()/2; inc>0; --inc)
    {
        if(Check(inc))
        {
            for (i = inc; i < a->GetSize(); i++)
            {
                T temp = a->Get(i);
                for (j = i-inc; (j >= 0) && (a->Get(j) > temp); j -= inc)
                    a->Set(a->Get(j), j+inc);
                a->Set(temp, j+inc);
            }
        }
    }
}


#endif //DATASTRUCTURE_SHELLSORTER_H
