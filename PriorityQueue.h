//
// Created by Dima on 08.11.2020.
//

#ifndef DATASTRUCTURE_PRIORITYQUEUE_H
#define DATASTRUCTURE_PRIORITYQUEUE_H


#include "LinkedListSequence.h"
#include "Sequence.h"
#include "ArraySequence.h"

template <class P, class T>
struct node
{
    T value;
    P priority;
};

template <class P, class T>
class PriorityQueue
{
private:
    Sequence<node<P, T> > *data;
    bool type;
public:
    PriorityQueue(bool f)
    {
        if(!f)
        {
            type = false;
            data = new LinkedListSequence<node<P, T> >();
        }
        else
        {
            type = true;
            data = new ArraySequence<node<P, T> >();
        }
    }

    PriorityQueue(PriorityQueue<P, T> *constqueue)
    {
        if(constqueue->type == true)
        {
            type = true;
            data = new ArraySequence<node<P, T> >(constqueue->data);
        }
        else
        {
            type = false;
            data = new LinkedListSequence<node<P, T> >(constqueue->data);
        }
    }

    PriorityQueue(PriorityQueue<P, T> *constqueue, bool f)
    {
        if(f == true)
        {
            type = true;
            data = new ArraySequence<node<P, T> >(constqueue->data);
        }
        else
        {
            type = false;
            data = new LinkedListSequence<node<P, T> >(constqueue->data);
        }
    }

    void Push(P prior, T elem)
    {
        node<P, T> item;
        item.priority = prior;
        item.value = elem;
        int index = 0;
        for(index = 0;index<data->GetSize();++index)
        {
            if(data->Get(index).priority > prior)
                break;
        }
        data->InsertAt(item, index);
    }

    bool Empty()
    {
        if(data->GetSize() == 0)
            return true;
        return false;
    }

    T Top()
    {
        if(this->Empty())
        {
            cout<<"IndexOutOfReng"<<endl;
        }
        return data->Get(0).value;
    }

    P TopPrior()
    {
        if(this->Empty())
        {
            cout<<"IndexOutOfReng"<<endl;
        }
        return data->Get(0).priority;
    }

    bool Pop()
    {
        if(this->Empty())
        {
            return false;
        }
        else
        {
            data->Erase(0);
            return true;
        }
    }

    int GetSize()
    {
        return data->GetSize();
    }

};


#endif //DATASTRUCTURE_PRIORITYQUEUE_H
