//
// Created by Dima on 28.12.2020.
//

#ifndef LABAALL_CACHE_H
#define LABAALL_CACHE_H
#include "ISetTree.h"
#include "IDictionaryHash.h"
#include "CacheQueue.h"
#include "HashFunction.h"


template <class T>
class Cache {
private:
    ISet<T> *data;
    IDictionary<int, pair<T, unit<int>* > > *cache;
    CacheQueue<int> *del_queue;
    int limit;
public:

    Cache(ISet<T> *set, int cache_max)
    {
        data = set;
        limit = cache_max;
        cache = new IDictionaryHash<int, pair<T, unit<int>* > >(GetHashInt);
        del_queue = new CacheQueue<int>();
    }

    int GetLimit()
    {
        return limit;
    }

    void SaveLimit(int x)
    {
        if(x>0) {
            limit = x;
            while (del_queue->GetSize() > limit)
            {
                cache->Erase(del_queue->GetFirst());
                del_queue->Pop();
            }
        }
        else
            throw logic_error("Can not save this limit");
    }

    T Get(int key)
    {
        if(cache->ContainsKey(key))
        {
            del_queue->GoToEnd(cache->Get(key).second);
            return cache->Get(key).first;
        }
        if(data->Size()>key && key>=0)
        {
            del_queue->Push(key);
            while (del_queue->GetSize() > limit)
            {
                cache->Erase(del_queue->GetFirst());
                del_queue->Pop();
            }
            cache->Add(key, {data->GetKth(key), del_queue->GetLastUnit()});
            return cache->Get(key).first;
        }
        throw logic_error("KeyNotFound");
    }
};


#endif //LABAALL_CACHE_H
