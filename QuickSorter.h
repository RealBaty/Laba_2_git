//
// Created by Dima on 08.11.2020.
//

#ifndef DATASTRUCTURE_QUICKSORTER_H
#define DATASTRUCTURE_QUICKSORTER_H
#include "Sorter.h"

template<class T>
class QuickSorter: public Sorter<T>
{
public:
    void Sort(Sequence<T> *a) override;
private:
    int FastSort(long long l, long long r, Sequence<T> *a)
    {
        if(l>=r)
            return 0;
        long long t = (rand()%(r-l+1)) + l;
        T ti = a->Get(t);
        long long i=l, j=r;
        do
        {
            while(a->Get(i)<ti)
                i++;
            while(a->Get(j)>ti)
                j--;
            if(i<=j)
            {
                T x = a->Get(i);
                a->Set(a->Get(j), i); //i j
                a->Set(x, j);
                i++;
                j--;
            }
        }while(i<=j);
        FastSort(l, j, a);
        FastSort(i, r, a);
        return 0;

    }
};

template <class T>
void QuickSorter<T>::Sort(Sequence<T> *a)
{
    this->FastSort(0, a->GetSize()-1, a);
}


#endif //DATASTRUCTURE_QUICKSORTER_H
