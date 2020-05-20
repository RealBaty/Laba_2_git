#ifndef ARRAYSEQUENCE_H_INCLUDED
#define ARRAYSEQUENCE_H_INCLUDED
#include <iostream>
#include "Sequence.h"
#include "DynamicArray.h"

using namespace std;

template<class T>
class ArraySequence: public Sequence<T>
{
    private:
        DynamicArray<T> *data;
        int left, right;
    public:
        ArraySequence();
        ArraySequence(T* items, int l);
        ArraySequence(Sequence<T> *list);
        T GetFirst() override;
        T GetLast() override;
        T Get(int index) override;
        Sequence<T>* GetSubSequence(int leftindex, int rightindex) override;
        int GetSize() override;
        void Append(T item) override;
        void Prepend(T item) override;
        void InsertAt(T item, int index) override;
        void Set(T item, int index) override;
        void Erase(int index) override;
        void Concat(Sequence<T> *list) override;
        ~ArraySequence();
};

template <class T>
ArraySequence<T>::ArraySequence()
{
    data = new DynamicArray<T>(0);
    left = 0;
    right = -1;
}

template <class T>
ArraySequence<T>::ArraySequence(T* items, int l)
{
    data = new DynamicArray<T>(l*3);
    for(int i=l;i<2*l;++i)
    {
        data->Set(i, items[i-l]);
    }
    left = l;
    right = 2*l-1;
}

template <class T>
ArraySequence<T>::ArraySequence(Sequence<T> *list)
{
    data = new DynamicArray<T>(list->GetSize());
    for(int i=0;i<list->GetSize();++i)
    {
        data->Set(i, list->Get(i));
    }
    left = 0;
    right = list->GetSize()-1;
}

template <class T>
T ArraySequence<T>::GetFirst()
{
    if(this->GetSize() == 0)
    {
        cout<<"Indexoutofreng\n";
        return 0;
    }
    return data->Get(left);
}

template <class T>
T ArraySequence<T>::GetLast()
{
    if(this->GetSize() == 0)
    {
        cout<<"Indexoutofreng\n";
        return 0;
    }
    return data->Get(right);
}

template <class T>
T ArraySequence<T>::Get(int index)
{
    if(index<0||index>=this->GetSize())
    {
        cout<<"Indexoutofreng\n";
        return 0;
    }
    return data->Get(index+left);
}

template <class T>
Sequence<T>* ArraySequence<T>::GetSubSequence(int leftindex, int rightindex)
{
    if(leftindex<0 || leftindex>=this->GetSize() || rightindex<0 || rightindex>=this->GetSize())
    {
        cout<<"Indexoutofren\n";
        return 0;
    }
    else
    {
        if(leftindex>rightindex)
        {
            Sequence<T> *res = new ArraySequence<T>();
            return res;
        }
        T *res1 = new T[rightindex-leftindex+1];
        for(int i=leftindex;i<=rightindex;++i)
        {
            res1[i-leftindex] = this->Get(i);
        }
        Sequence<T> *res = new ArraySequence<T>(res1, rightindex-leftindex+1);
        return res;
    }
}

template <class T>
int ArraySequence<T>::GetSize()
{
    return right-left+1;
}

template <class T>
void ArraySequence<T>::Append(T item)
{
    cout<<"==============================================="<<endl;
    cout<<left<<" "<<right<<endl;
    for(int i=0;i<data->GetSize();++i)
        cout<<data->Get(i)<<" ";
    cout<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    if(left>0)
    {
        left--;
        cout<<"{"<<item<<" "<<left<<"}"<<endl;
        this->data->Set(item, left);
    }
    else
    {
        DynamicArray<T> *newdata = new DynamicArray<T>((this->GetSize()+1)*3);
        int left1=this->GetSize()+1;
        int right1=(this->GetSize()+1)*2-1;
        newdata->Set(item, left1);
        for(int i=left1+1;i<=right1;++i)
        {
            newdata->Set(this->Get(i-left1-1), i);
        }
        delete(data);
        data = newdata;
        left = left1;
        right = right1;
    }
    cout<<"==============================================="<<endl;
    cout<<left<<" "<<right<<endl;
    for(int i=0;i<data->GetSize();++i)
        cout<<data->Get(i)<<" ";
    cout<<endl;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}

template <class T>
void ArraySequence<T>::Prepend(T item)
{
    if(right<data->GetSize()-1)
    {
        data->Set(item, right+1);
        right++;
    }
    else
    {
        DynamicArray<T> *newdata = new DynamicArray<T>((this->GetSize()+1)*3);
        int left1=this->GetSize()+1;
        int right1=(this->GetSize()+1)*2-1;
        newdata->Set(item, right1);
        for(int i=left1;i<right1;++i)
        {
            newdata->Set(this->Get(i-left1), i);
        }
        delete(data);
        data = newdata;
        left = left1;
        right = right1;
    }
}

template <class T>
void ArraySequence<T>::InsertAt(T item, int index)
{
    if(index<0||index>this->GetSize())
    {
        cout<<"Indexoutofreng\n";
    }
    else if(index == 0)
    {
        this->Append(item);
    }
    else if(index == this->GetSize())
    {
        this->Prepend(item);
    }
    else
    {

        DynamicArray<T> *newdata = new DynamicArray<T>((this->GetSize()+1)*3);
        int left1=this->GetSize()+1;
        int right1=(this->GetSize()+1)*2-1;
        for(int i=left1;i<left1+index;++i)
        {
            newdata->Set(this->Get(i-left1), i);
        }
        newdata->Set(item, left1+index);
        for(int i=left1+index+1;i<=right1;++i)
        {
            newdata->Set(this->Get(i-left1-1), i);
        }
        delete(data);
        data = newdata;
        left = left1;
        right = right1;
    }
}

template <class T>
void ArraySequence<T>::Set(T item, int index)
{
    if(index<0||index>=this->GetSize())
    {
        cout<<"Indexoutofreng\n";
    }
    else
        data->Set(item, index+left);
}

template <class T>
void ArraySequence<T>::Erase(int index)
{
    if(index<0||index>=this->GetSize())
    {
        cout<<"Indexoutofreng\n";
    }
    else if(index == 0)
    {
        left++;
    }
    else if(index == this->GetSize()-1)
    {
        right--;
    }
    else
    {
        for(int i=index;i<this->GetSize()-1;++i)
        {
            data->Set(data->Get(i+left+1),i+left);
        }
        right--;
    }
}

template <class T>
void ArraySequence<T>::Concat(Sequence<T> *list)
{
    DynamicArray<T> *newdata = new DynamicArray<T>((this->GetSize()+list->GetSize())*3);
    int left1=this->GetSize()+list->GetSize();
    int right1=(this->GetSize()+list->GetSize())*2-1;
    for(int i=0;i<this->GetSize();++i)
    {
        newdata->Set(this->Get(i),i+left1);
    }
    for(int i=this->GetSize();i<this->GetSize()+list->GetSize();++i)
    {
        newdata->Set(list->Get(i-this->GetSize()),i+left1);
    }
    delete(data);
    left=left1;
    right=right1;
    data=newdata;
}

template <class T>
ArraySequence<T>::~ArraySequence()
{
    delete(data);
}


#endif // ARRAYSEQUENCE_H_INCLUDED
