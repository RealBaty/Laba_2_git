#include <iostream>
#include <vector>
#include "LinkedList.h"
#include "DynamicArray.h"
#include "LinkedListSequence.h"
#include "Sequence.h"
#include "ArraySequence.h"


using namespace std;

int main()
{
    /*Sequence<int> *a = new LinkedListSequence<int>();
    a->Append(1);
    a->Prepend(2);
    a->Prepend(3);
    a->Append(4);
    a->InsertAt(5,1);
    for(int i=0;i<a->GetSize();++i)
        cout<<a->Get(i)<<" ";
    cout<<endl;
    a->Erase(2);
    for(int i=0;i<a->GetSize();++i)
        cout<<a->Get(i)<<" ";
    cout<<endl;
    a->Erase(3);
    for(int i=0;i<a->GetSize();++i)
        cout<<a->Get(i)<<" ";
    cout<<endl;
    a->Erase(0);
    for(int i=0;i<a->GetSize();++i)
        cout<<a->Get(i)<<" ";
    cout<<endl;
    int c[3] = {7,8,9};
    Sequence<int> *d = new LinkedListSequence<int>();
    d = a->GetSubSequence(0,1);
    for(int i=0;i<d->GetSize();++i)
        cout<<d->Get(i)<<" ";
    cout<<endl;
    a->Concat(d);
    for(int i=0;i<d->GetSize();++i)
        cout<<d->Get(i)<<" ";
    cout<<endl;*/
    Sequence<int> *arr = new ArraySequence<int>();
    cout<<"11111111111111111111111111111111111111111111111111111111111111"<<endl;
    arr->Append(1);
    cout<<"11111111111111111111111111111111111111111111111111111111111111"<<endl;
    cout<<"222222222222222222222222222222222222222222222222222222222222222222"<<endl;
    arr->Append(2);
    cout<<"2222222222222222222222222222222222222222222222222222222222222222"<<endl;
    cout<<"33333333333333333333333333333333333333333333333333333333333333333333"<<endl;
    arr->Append(3);
    cout<<"13333333333333333333333333333333333333333333333333333333333333333333333333333"<<endl;
    cout<<"4444444444444444444444444444444444444444444444444444444444444444444444444444444"<<endl;
    arr->Append(4);
    cout<<"144444444444444444444444444444444444444444444444444444444444444444444444444444444"<<endl;
    for(int i=0;i<arr->GetSize();++i)
        cout<<arr->Get(i)<<" ";
    cout<<endl;
    return 0;
}
