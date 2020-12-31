//
// Created by Dima on 27.12.2020.
//

#ifndef LABAALL_IDICTIONARYHASH_H
#define LABAALL_IDICTIONARYHASH_H
#include "IDictionary.h"
#include "DynamicArray.h"
#include "Sequence.h"
#include "LinkedListSequence.h"

template <class TKey, class TElem>
class IDictionaryHash: public IDictionary<TKey, TElem> {
private:
    int n, p, q;
    DynamicArray<Sequence<pair<TKey, TElem> >*> *data;
    function<int(TKey, int)> GetHashCode;
public:
    IDictionaryHash(function<int(TKey, int)> func, int compress, int multiplicity)
    {
        n = 0;
        p = compress;
        q = multiplicity;
        GetHashCode = func;
        data = new DynamicArray<Sequence<pair<TKey, TElem> >* >(10, nullptr);
    }

    IDictionaryHash(function<int(TKey, int)> func)
    {
        n = 0;
        p = 4;
        q = 2;
        GetHashCode = func;
        data = new DynamicArray<Sequence<pair<TKey, TElem> >* >(10, nullptr);
    }

    int Size() override
    {
        return n;
    }

    TElem Get(TKey key) override
    {
        int index = GetHashCode(key, data->GetSize());
        if(data->Get(index)!=nullptr)
            for(int i=0;i<data->Get(index)->GetSize();++i)
            {
                if(data->Get(index)->Get(i).first == key)
                    return data->Get(index)->Get(i).second;
            }
        throw logic_error("IndexOutOfRange");
    }

    bool ContainsKey(TKey key) override
    {
        int index = GetHashCode(key, data->GetSize());
        if(data->Get(index)!=nullptr)
            for(int i=0;i<data->Get(index)->GetSize();++i)
            {
                if(data->Get(index)->Get(i).first == key)
                    return true;
            }
        return false;
    }

    void Add(TKey key, TElem elem) override
    {
        if(!ContainsKey(key)) {
            int index = GetHashCode(key, data->GetSize());
            if (data->Get(index) == nullptr)
                data->Set(new LinkedListSequence<pair<TKey, TElem> >(), index);
            data->Get(index)->Prepend({key, elem});
            n++;
            if(n >= data->GetSize())
            {
                DynamicArray<Sequence<pair<TKey, TElem> >*> *new_data = new DynamicArray<Sequence<pair<TKey, TElem> >*>(data->GetSize()*q, nullptr);
                auto old_data = data;
                data = new_data;
                for(int i=0; i < old_data->GetSize(); ++i)
                {
                    if(old_data->Get(i) != nullptr)
                        for(int j=0; j < old_data->Get(i)->GetSize(); ++j)
                            Add(old_data->Get(i)->Get(j).first, old_data->Get(i)->Get(j).second);
                }
            }
        }
        else
            throw logic_error("ThisKeyEmployed");
    }

    void Erase(TKey key) override
    {
        int index = GetHashCode(key, data->GetSize());
        bool f = true;
        if(data->Get(index) != nullptr)
            for(int i=0;i<data->Get(index)->GetSize();++i)
            {
                if(data->Get(index)->Get(i).first == key)
                {
                    data->Get(index)->Erase(i);
                    f = false;
                    n--;
                    if (n <= data->GetSize() / p && data->GetSize()>10) {
                        DynamicArray<Sequence<pair<TKey, TElem> > *> *new_data = new DynamicArray<Sequence<pair<TKey, TElem> > *>(
                                data->GetSize() / q, nullptr);
                        auto old_data = data;
                        data = new_data;
                        for (int j = 0; j < old_data->GetSize(); ++j) {
                            if (old_data->Get(j) != nullptr)
                                for (int k = 0; k < old_data->Get(j)->GetSize(); ++k)
                                    Add(old_data->Get(j)->Get(k).first, old_data->Get(j)->Get(k).second);
                        }
                    }
                    break;
                }
            }
        if(f)
            throw logic_error("KeyNotFound");
    }
};


#endif //LABAALL_IDICTIONARYHASH_H
