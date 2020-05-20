#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
        int len, pos;
        unit<T> *data, *start, *finish;
    public:
        LinkedList();
        LinkedList(T *items, int l);
        LinkedList(LinkedList<T> &listconst);
        T GetFirst();
        T GetLast();
        T Get(int index);
        LinkedList<T>* GetSubList(int startindex, int endindex);
        int GetSize();
        void Append(T item);
        void Prepend(T item);
        void InsertAt(T item, int index);
        LinkedList<T>* Concat(LinkedList<T> *list);
        void Erase(int index);
        void Set(T item, int index);
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
LinkedList<T>::LinkedList(T *items, int l)
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
        for(int i=1;i<l;++i)
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
        for(int i=1;i<listconst.len;++i)
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
        cout<<"IndexOutOfRange3"<<endl;
        return 0;
    }
    return start->val;
}

template <class T>
T LinkedList<T>::GetLast()
{
    if(len == 0)
    {
        cout<<"IndexOutOfRange4"<<endl;
        return 0;
    }
    return finish->val;
}

template <class T>
T LinkedList<T>::Get(int index)
{
    if(index<0 || index>=len)
    {
        cout<<"IndexOutOfRange5"<<endl;
        return 0;
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
LinkedList<T>* LinkedList<T>::GetSubList(int startindex, int endindex)
{
    if(startindex>endindex || startindex<0 || endindex>=len)
    {
        cout<<"IndexOutOfRange6"<<endl;
        return this;
    }
    LinkedList<T> *res = new LinkedList<T>();
    for(int i=startindex;i<=endindex;++i)
    {
        res->Prepend(this->Get(i));
    }
    return res;
}

template <class T>
int LinkedList<T>::GetSize()
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
void LinkedList<T>::InsertAt(T item, int index)
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
            cout<<"IndexOutOfRange7"<<endl;
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
void LinkedList<T>::Erase(int index)
{
    if(index<0||index>=len)
    {
        cout<<"IndexOutOfRange8\n";
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
void LinkedList<T>::Set(T item, int index)
{
    if(index<0 || index>=len)
    {
        cout<<"IndexOutOfRange9"<<endl;
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
        delete(j);
    }
}

#endif // LINKEDLIST_H
