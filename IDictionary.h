//
// Created by Dima on 27.12.2020.
//

#ifndef LABAALL_IDICTIONARY_H
#define LABAALL_IDICTIONARY_H

template <class TKey, class TElem>
class IDictionary {
public:
    virtual int Size() = 0;
    virtual TElem Get(TKey key) = 0;
    virtual bool ContainsKey(TKey key) = 0;
    virtual void Add(TKey key, TElem elem) = 0;
    virtual void Erase(TKey key) = 0;
};


#endif //LABAALL_IDICTIONARY_H
