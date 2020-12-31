//
// Created by Dima on 28.12.2020.
//

#ifndef LABAALL_CACHEQUEUE_H
#define LABAALL_CACHEQUEUE_H
#include "LinkedList.h"

template <class T>
class CacheQueue {
private:
    LinkedList<T> *data;
public:
    CacheQueue()
    {
        data = new LinkedList<T>();
    }
    void GoToEnd(unit<T> *el)
    {
        data->Erase(el);
        data->Prepend(el);
    }
    unit<T>* GetLastUnit()
    {
        return data->GetLastUnit();
    }
    T GetFirst()
    {
        data->GetFirst();
    }
    void Pop()
    {
        if(data->GetSize() != 0)
            data->Erase(1-1);
    }
    void Push(T key)
    {
        data->Prepend(key);
    }

    int GetSize()
    {
        return data->GetSize();
    }

};


#endif //LABAALL_CACHEQUEUE_H
