#include <iostream>
#include <vector>
#include <ctime>
#include "LinkedList.h"
#include "DynamicArray.h"
#include "LinkedListSequence.h"
#include "Sequence.h"
#include "ArraySequence.h"
#include "PriorityQueue.h"
#include "Cartesian.h"
#include "CartesianTree.h"
#include "CartesianSequence.h"
#include "BubbleSorter.h"
#include "QuickSorter.h"
#include "TreeSorter.h"
#include "ShellSorter.h"
#include "ISortedSequenceTree.h"
#include "ISortedSequence.h"
#include "ISetTree.h"
#include "ISet.h"
#include "IDictionaryHash.h"
#include "IDictionaryTree.h"
#include "Cache.h"
#include "Graph.h"
#include "UndirectedGraph.h"
#include "DirectedGraph.h"
#include "Dijkstra.h"

using namespace std;

void CacheTest()
{
    int n=0, m=0, len=0, c_len=0;
    ISet<string> *set = new ISetTree<string>();
    cout<<"Enter the number of elements in the set"<<endl;
    cin>>n;
    bool f;
    cout<<"Do you want to fill out the set yourself? (1/0)"<<endl;
    cin>>f;
    bool f3;
    if(!f)
    {
        cout<<"What is the length of the string you want to use?"<<endl;
        cin>>len;
    }
    else
        cout<<"Enter the elements of the set"<<endl;
    for(int i=0;i<n;++i)
    {
        string s;
        if(f)
        {
            cin>>s;
        }
        else
        {
            s.reserve(len);
            for(int j=0;j<len;j++)
            {
                s.push_back(rand()%250);
            }
        }
        set->Add(s);
    }
    cout<<"Want to see the input set? (1/0)"<<endl;
    cin>>f3;
    if(f3)
    {
        for(int i=0;i<set->Size();++i)
        {
            cout<<i<<": "<<set->GetKth(i)<<endl;
            cout<<"---------------------------------------------------------------"<<endl;
        }
    }
    cout<<"Enter the cache size"<<endl;
    cin>>c_len;
    cout<<"How many requests do you want to make?"<<endl;
    cin>>m;
    cout<<"Do you want to make requests yourself? (1/0)"<<endl;
    bool f2;
    cin>>f2;
    Cache<string> *data = new Cache<string>(set, c_len);
    if(f2)
        cout<<"Enter a query for an item by index. A set stores a single instance of an element. Items are stored in alphabetical order."<<endl;
    clock_t start, stop;
    start = clock();
    for(int i=0;i<m;++i)
    {
        int index=0;
        if(f2)
        {
            cin>>index;
            cout<<data->Get(index)<<endl;
        }
        else
        {
            index = ((rand() << 15) + rand())%(set->Size());
            data->Get(index);
        }
    }
    stop = clock();
    cout<<endl<<"time: "<<(double)(stop - start) / CLOCKS_PER_SEC<<endl;
}

void DijkstraTest()
{
    int n=0,m=0, start=0, num = 0;
    Graph<int> *graph;
    cout<<"Enter the number of nodes in the graph"<<endl;
    cin>>n;
    bool f;
    cout<<"Do you want to use a directed or undirected graph? (1/0)"<<endl;
    cin>>f;
    if(f)
        graph = new DirectedGraph<int>(n);
    else
        graph = new UndirectedGraph<int>(n);
    cout<<"Enter the number of edges of the graph"<<endl;
    cin>>m;
    cout<<"Enter the edges of the graph in the format (StartNode, FinishNode, Size) without multiple edges"<<endl;
    for(int i=0;i<m;++i)
    {
        int x, y, w;
        cin>>x>>y>>w;
        graph->SaveEdge(x, y, w);
    }
    cout<<"Enter the start node"<<endl;
    cin>>start;
    auto res = Dijkstra(graph, start, 0);
    cout<<"Enter the number of nodes you want to know the distance to"<<endl;
    cin>>num;
    cout<<"Enter the nodes you want to find out the path to"<<endl;
    for(int i=0;i<num;++i)
    {
        int f_node=0;
        cin>>f_node;
        if(res->Get(f_node).first)
            cout<<"Path not found"<<endl;
        else
            cout<<res->Get(f_node).second<<endl;
    }
}

void SorterTest()
{
    long long n=0;
    cout<<"Enter the number of items in the sequence"<<endl;
    cin>>n;
    bool f;
    cout<<"Do you want to fill out the sequence yourself? (1/0)"<<endl;
    cin>>f;
    bool f3;
    if(!f)
    {
        cout<<"Want to see the input sequence? (1/0)"<<endl;
        cin>>f3;
    }
    cout<<"Use a list or array? (1/0)"<<endl;
    bool f1;
    cin>>f1;
    bool f2;
    cout<<"Show the result? (1/0)"<<endl;
    cin>>f2;
    string sor;
    cout<<"What sort do you want to use? (bubble/quick/shell/tree)"<<endl;
    cin>>sor;
    clock_t start, stop;
    Sequence<int> *a;
    if(f1)
        a = new LinkedListSequence<int>();
    else
        a = new ArraySequence<int>();
    int t;
    for(int i=0;i<n;++i)
    {
        if(f)
            cin>>t;
        else {
            t = rand();
            if (f3)
                cout << t << " ";
        }
        a->Prepend(t);
    }
    if(f3)
        cout<<endl<<"------------------------------------------------------------------------------------"<<endl;
    Sorter<int> *sorting;
    if(sor == "bubble")
        sorting = new BubbleSorter<int>();
    else if(sor == "quick")
        sorting = new QuickSorter<int>();
    else if(sor == "shell")
        sorting = new ShellSorter<int>();
    else if(sor == "tree")
        sorting = new TreeSorter<int>();
    else
        sorting = new BubbleSorter<int>();
    start = clock();
    sorting->Sort(a);
    stop = clock();
    if(f2)
        for(int i=0;i<n;++i)
        {
            cout<<a->Get(i)<<" ";
        }
    cout<<endl<<"time: "<<(double)(stop - start) / CLOCKS_PER_SEC<<endl;
}


int main()
{
    CacheTest();
    //DijkstraTest();
    return 0;
}

