//#include "LinkedList.h"
/*
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
        cout<<"IndexOutOfRange"<<endl;
        return 0;
    }
    return start->val;
}

template <class T>
T LinkedList<T>::GetLast()
{
    if(len == 0)
    {
        cout<<"IndexOutOfRange"<<endl;
        return 0;
    }
    return finish->val;
}

template <class T>
T LinkedList<T>::Get(int index)
{
    if(index<0 || index>=len)
    {
        cout<<"IndexOutOfRange"<<endl;
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
        cout<<"IndexOutOfRange"<<endl;
        return 0;
    }
    LinkedList<T> *res = new LinkedList<T>();
    for(int i=startindex;i<=endindex;++i)
    {
        res.Prepend(this->Get(i));
    }
    return res;
}

template <class T>
int LinkedList<T>::GetLength()
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
    if(index<0 || index>len)
    {
        cout<<"IndexOutOfRange"<<endl;
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
    len++;
    if(data == nullptr || this->len == 0)
    {
        this->Prepend(item);
    }
    else if(pos == 0)
    {
        this->Append(item);
    }
    else
    {
        unit<T> *el = new unit<T>;
        el->val = item;
        el->left = data->left;
        data->left->right = el;
        el->right = data;
        data->left = el;
    }
}

template <class T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T> *list)
{
    LinkedList<T> *res = new LinkedList<T>();
    for(int i=0;i<len;++i)
        res.Prepend(this->Get(i));
    for(int i=0;i<list->len;++i)
        res.Prepend(list->Get(i));
}


template <class T>
LinkedList<T>::~LinkedList()
{
    //dtor
}

*/
