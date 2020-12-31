cmake_minimum_required(VERSION 3.17)
project(LabaAll)

set(CMAKE_CXX_STANDARD 20)

add_executable(LabaAll main.cpp ISet.h ISetTree.h ISortedSequence.h ISortedSequenceTree.h IDictionary.h IDictionaryTree.h IDictionaryHash.h CacheQueue.h Cache.h HashFunction.h SparseArray.h SparseMatrix.h DirectedGraph.h Graph.h UndirectedGraph.h Dijkstra.h)