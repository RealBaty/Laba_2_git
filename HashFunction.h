//
// Created by Dima on 28.12.2020.
//

#ifndef LABAALL_HASHFUNCTION_H
#define LABAALL_HASHFUNCTION_H
#include <iostream>

int GetHashInt(int el, int lim)
{
    int res = 0;
    for(int i=1;el>0; i=(i*27)%lim, el=el/10)
        res=(res+((el%10)*i)%lim)%lim;
    return res;
}

int GetHashString(string el, int lim)
{
    int res = 0;
    for(int i=0, j=1; i<el.size(); i++, j=(j*27)%lim)
    {
        res=(res+((el[i])*j)%lim)%lim;
    }
    return res;
}

int GetHashPairInt(pair<int, int> el, int lim)
{
    int res = 0;
    for(int i=1;el.first>0; i=(i*27)%lim, el.first=el.first/10)
        res=(res+((el.first%10)*i)%lim)%lim;
    for(int i=27;el.second>0; i=(i*27)%lim, el.second=el.second/10)
        res=(res+((el.second%10)*i)%lim)%lim;
    return res;
}

#endif //LABAALL_HASHFUNCTION_H
