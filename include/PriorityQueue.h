#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

template <class T, class P>
struct node
{
    T value;
    P priority;
};

template <class T, class P>
class PriorityQueue
{
    private:
        Sequence<node<T, P> > *data;
    public:
        PriorityQueue()
};

#endif // PRIORITYQUEUE_H_INCLUDED
