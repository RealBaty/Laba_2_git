//
// Created by Dima on 08.11.2020.
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H


#include <iostream>

using namespace std;

template <class T>
struct unit
{
    T val;
    unit *left;
    unit *right;
};

template <class T>
class LinkedList
{
private:
    long long len, pos;
    unit<T> *data, *start, *finish;
public:
    LinkedList();
    LinkedList(T *items, long long l);
    LinkedList(LinkedList<T> &listconst);
    T GetFirst();
    T GetLast();
    T Get(long long index);
    unit<T>* GetFirstUnit();
    unit<T>* GetLastUnit();
    LinkedList<T>* GetSubList(long long startindex, long long endindex);
    long long GetSize();
    void Append(T item);
    void Prepend(T item);
    void Prepend(unit<T> *el);
    void InsertAt(T item, long long index);
    LinkedList<T>* Concat(LinkedList<T> *list);
    void Erase(long long index);
    void Erase(unit<T> *el);
    void Set(T item, long long index);
    ~LinkedList();

};

template <class T>
LinkedList<T>::LinkedList()
{
    data = nullptr;
    start = nullptr;
    finish = nullptr;
    len = 0;
    pos = 0;
}

template <class T>
LinkedList<T>::LinkedList(T *items, long long l)
{
    if(l==0)
    {
        data = nullptr;
        start = nullptr;
        finish = nullptr;
        len = 0;
        pos = 0;
    }
    else
    {
        len=l;
        start = new unit<T>;
        pos=0;
        data = start;
        finish = start;
        start->left = nullptr;
        start->right = nullptr;
        start->val = items[0];
        for(long long i=1;i<l;++i)
        {
            unit<T> *t = new unit<T>;
            finish->right = t;
            t->left = finish;
            t->right = nullptr;
            t->val = items[i];
            finish = t;
        }
    }
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T> &listconst)
{
    if(listconst.len==0)
    {
        data = nullptr;
        start = nullptr;
        finish = nullptr;
        len = 0;
        pos = 0;
    }
    else
    {
        len=listconst.len;
        start = new unit<T>;
        pos=0;
        data = start;
        finish = start;
        start->left = nullptr;
        start->right = nullptr;
        start->val = listconst.Get(0);
        for(long long i=1;i<listconst.len;++i)
        {
            unit<T> *t = new unit<T>;
            finish->right = t;
            t->left = finish;
            t->right = nullptr;
            t->val = listconst.Get(i);
            finish = t;
        }
    }
}

template <class T>
T LinkedList<T>::GetFirst()
{
    if(len == 0)
    {
        throw logic_error("IndexOutOfRange");
    }
    else
        return start->val;
}

template <class T>
T LinkedList<T>::GetLast()
{
    if(len == 0)
    {
        throw logic_error("IndexOutOfRange");
    }
    else
        return finish->val;
}

template<class T>
unit<T>* LinkedList<T>::GetFirstUnit() {
    return start;
}

template<class T>
unit<T>* LinkedList<T>::GetLastUnit() {
    return finish;
}

template<class T>
void LinkedList<T>::Erase(unit<T> *el) {
    len--;
    if(el->left == nullptr)
        start = el->right;
    if(el->right == nullptr)
        finish = el->left;
    if(el->left!= nullptr)
        el->left->right = el->right;
    if(el->right != nullptr)
        el->right->left = el->left;
}

template <class T>
T LinkedList<T>::Get(long long index)
{
    if(index<0 || index>=len)
    {
        throw logic_error("IndexOutOfRange");
    }
    if(index == 0)
    {
        data = start;
        pos = 0;
    }
    if(index == len-1) {
        data = finish;
        pos = len - 1;
    }
    if(index < pos)
    {
        for(;pos!=index;--pos)
        {
            data=data->left;
        }
    }
    if(index > pos)
    {
        for(;pos!=index;++pos)
        {
            data=data->right;
        }
    }
    return data->val;
}

template <class T>
LinkedList<T>* LinkedList<T>::GetSubList(long long startindex, long long endindex)
{
    if(startindex>endindex || startindex<0 || endindex>=len)
    {
        throw logic_error("IndexOutOfRange");
    }
    LinkedList<T> *res = new LinkedList<T>();
    for(long long i=startindex;i<=endindex;++i)
    {
        res->Prepend(this->Get(i));
    }
    return res;
}

template <class T>
long long LinkedList<T>::GetSize()
{
    return len;
}

template <class T>
void LinkedList<T>::Append(T item)
{
    len++;
    unit<T> *el = new unit<T>;
    el->val = item;
    el->left = nullptr;
    el->right = start;
    if(start!=nullptr)
        start->left = el;
    start = el;
    if(finish == nullptr)
        finish = el;
    pos = 0;
    data = start;
}

template <class T>
void LinkedList<T>::Prepend(T item)
{
    len++;
    unit<T> *el = new unit<T>;
    el->val = item;
    el->left = finish;
    el->right = nullptr;
    if(finish != nullptr)
        finish->right = el;
    finish = el;
    if(start == nullptr)
        start = el;
    pos = len-1;
    data = finish;
}

template <class T>
void LinkedList<T>::Prepend(unit<T> *el)
{
    len++;
    el->left = finish;
    el->right = nullptr;
    if(finish != nullptr)
        finish->right = el;
    finish = el;
    if(start == nullptr)
        start = el;
    pos = len-1;
    data = finish;
}

template <class T>
void LinkedList<T>::InsertAt(T item, long long index)
{
    if(index == len)
    {
        this->Prepend(item);
    }
    else if(index == 0)
    {
        this->Append(item);
    }
    else
    {
        if(index<0 || index>len)
        {
            throw logic_error("IndexOutOfRange");
        }
        else
        {
            len++;
            if(index < pos)
            {
                for(;pos!=index;--pos)
                {
                    data=data->left;
                }
            }
            if(index > pos)
            {
                for(;pos!=index;++pos)
                {
                    data=data->right;
                }
            }
            unit<T> *el = new unit<T>;
            el->val = item;
            el->left = data->left;
            data->left->right = el;
            el->right = data;
            data->left = el;
            data = el;
        }
    }
}

template <class T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T> *list)
{
    if(len == 0)
    {
        len = list->len;
        data = list->data;
        start = list->start;
        finish = list->finish;
        pos = list->pos;
    }
    else
    {
        len+=list->len;
        finish->right = list->start;
        if(list->start!=nullptr)
        {
            list->start->left = finish;
            finish = list -> finish;
        }
        list->len = len;
        list->data = data;
        list->start = start;
        list->finish = finish;
        list->pos = pos;
    }
}

template <class T>
void LinkedList<T>::Erase(long long index)
{
    if(index<0||index>=len)
    {
        throw logic_error("IndexOutOfRange");
    }
    else if(index == 0 && index == len-1)
    {
        delete(start);
        start = nullptr;
        finish = nullptr;
        data = nullptr;
        pos = 0;
        len = 0;
    }
    else if(index == 0)
    {
        start = start->right;
        delete(start->left);
        start->left = nullptr;
        len--;
        data = start;
        pos = 0;
    }
    else if(index == len-1)
    {
        finish = finish->left;
        delete(finish->right);
        finish->right = nullptr;
        len--;
        data = finish;
        pos = len-1;
    }
    else
    {
        if(index < pos)
        {
            for(;pos!=index;--pos)
            {
                data=data->left;
            }
        }
        if(index > pos)
        {
            for(;pos!=index;++pos)
            {
                data=data->right;
            }
        }
        data->right->left = data->left;
        data->left->right = data->right;
        unit<T> *vr = data;
        data = data->right;
        len--;
        delete(vr);
    }
}

template <class T>
void LinkedList<T>::Set(T item, long long index)
{
    if(index<0 || index>=len)
    {
        throw logic_error("IndexOutOfRange");
    }
    else
    {
        if(index < pos)
        {
            for(;pos!=index;--pos)
            {
                data=data->left;
            }
        }
        if(index > pos)
        {
            for(;pos!=index;++pos)
            {
                data=data->right;
            }
        }
        data->val = item;
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    for(unit<T> *i = start;i!=nullptr;)
    {
        unit<T> *j = i;
        i = i->right;
        delete j;
    }
}


#endif //DATASTRUCTURE_LINKEDLIST_H
