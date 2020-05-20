#ifndef SEQUENCE_H_INCLUDED
#define SEQUENCE_H_INCLUDED

template <class T>
class Sequence
{
    public:
        virtual T GetFirst() = 0;
        virtual T GetLast() = 0;
        virtual T Get(int index) = 0;
        virtual Sequence<T>* GetSubSequence(int leftindex, int rightindex) = 0;
        virtual int GetSize() = 0;
        virtual void Append(T item) = 0;
        virtual void Prepend(T item) = 0;
        virtual void InsertAt(T item, int index) = 0;
        virtual void Set(T item, int index) = 0;
        virtual void Erase(int index) = 0;
        virtual void Concat(Sequence<T> *list) = 0;

};

#endif // SEQUENCE_H_INCLUDED
