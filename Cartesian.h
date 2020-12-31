//
// Created by Dima on 08.11.2020.
//

#ifndef DATASTRUCTURE_CARTESIAN_H
#define DATASTRUCTURE_CARTESIAN_H


#include <iostream>
#include <functional>
#include <ctime>
#include "ArraySequence.h"
#include "LinkedListSequence.h"

using namespace std;

template <class T>
class Cartesian
{
private:
    T x;
    int y, size;
    Cartesian *left, *right, *next;
public:
    Cartesian(T a, int p)
    {
        x = a;
        y = p;
        size = 1;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }


    Cartesian(T a)
    {
        x = a;
        y = (rand() << 15) + rand();
        size = 1;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }

    Cartesian()
    {
        y = (rand() << 15) + rand();
        size = 1;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }

    ~Cartesian()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }

    template<class P> friend class CartesianFunction;
};

template <class T>
class CartesianFunction {
    private:
        function<bool(T&,T&)> Func;
    public:
        function<bool(T&,T&)> GetCmp()
        {
            return Func;
        }
        CartesianFunction(function<bool(T&,T&)> Cmp)   //< > =
        {
            Func = Cmp;
        }

        CartesianFunction()   //< > =
        {
            Func = [](T &a,T &b){return a<b;};
        }

        bool Less(T &a, T &b)
        {
            return Func(a, b);
        }

        bool More(T &a, T &b)
        {
            return Func(b, a);
        }

        bool Equal(T &a, T &b)
        {
            return (!Func(a, b)) && (!Func(b, a));
        }

        int Depth(Cartesian<T> *root) {
            if (!root)
                return 0;
            return max(this->Depth(root->left), this->Depth(root->right)) + 1;
        }

        int GetSize(Cartesian<T> *root) {
            if (root == nullptr)
                return 0;
            return root->size;
        }

        void Update(Cartesian<T> *root) {
            if (!root)
                return;
            root->size = 1 + this->GetSize(root->left) + this->GetSize(root->right);
        }

        bool Exists(Cartesian<T> *root, T key) {
            if (root == nullptr)
                return false;
            if (Equal(key, root->x))
                return true;
            if (More(key, root->x))
                return Exists(root->right, key);
            return Exists(root->left, key);
        }

        T &Kth(Cartesian<T> *root, int index) {
            if (!root) {
                cout << "indexoutofreng" << endl;
            } else {
                if (index == GetSize(root->left))
                    return root->x;
                if (index < GetSize(root->left))
                    return Kth(root->left, index);
                return Kth(root->right, index - GetSize(root->left) - 1);
            }
        }

        Cartesian<T> *KthNode(Cartesian<T> *root, int index) {
            if (!root) {
                cout << "indexoutofreng" << endl;
            } else {
                if (index == GetSize(root->left))
                    return root;
                if (index < GetSize(root->left))
                    return KthNode(root->left, index);
                return KthNode(root->right, index - GetSize(root->left) - 1);
            }
        }

        int IndexOfElem(Cartesian<T> *root, T key) {
            if (!root) {
                return -1;
            } else {
                if (Equal(key, root->x))
                    return GetSize(root->left);
                if (Less(key, root->x))
                    return IndexOfElem(root->left, key);
                return IndexOfElem(root->right, key) + 1 + GetSize(root->left);
            }
        }

        pair<Cartesian<T> *, Cartesian<T> *> SplitKth(Cartesian<T> *root, int k) {
            if (root == nullptr)
                return {nullptr, nullptr};
            if (k <= GetSize(root->left)) {
                auto res = SplitKth(root->left, k);
                root->left = res.second;
                Update(root);
                return {res.first, root};
            } else {
                auto res = SplitKth(root->right, k - 1 - GetSize(root->left));
                root->right = res.first;
                Update(root);
                return {root, res.second};
            }
        }

        pair<Cartesian<T> *, Cartesian<T> *> LeftSplit(Cartesian<T> *root, T val) {
            if (root == nullptr)
                return {nullptr, nullptr};
            if (Less(root->x, val) || Equal(root->x, val)) {
                auto res = LeftSplit(root->right, val);
                root->right = res.first;
                Update(root);
                return {root, res.second};
            } else {
                auto res = LeftSplit(root->left, val);
                root->left = res.second;
                Update(root);
                return {res.first, root};
            }
        }

        pair<Cartesian<T> *, Cartesian<T> *> RightSplit(Cartesian<T> *root, T val) {
            if (root == nullptr)
                return {nullptr, nullptr};
            if (Less(root->x, val)) {
                auto res = RightSplit(root->right, val);
                root->right = res.first;
                Update(root);
                return {root, res.second};
            } else {
                auto res = RightSplit(root->left, val);
                root->left = res.second;
                Update(root);
                return {res.first, root};
            }
        }

        Cartesian<T> *Merge(Cartesian<T> *root1, Cartesian<T> *root2) {
            if (root1 == nullptr)
                return root2;
            if (root2 == nullptr)
                return root1;
            if (root1->y <= root2->y) {
                root1->right = Merge(root1->right, root2);
                Update(root1);
                return root1;
            } else {
                root2->left = Merge(root1, root2->left);
                Update(root2);
                return root2;
            }
        }

        void Stitch(Cartesian<T> **elem, Cartesian<T> *root, string s) {
            if (!root) {
                return;
            }
            for (int i = 0; i < 3; ++i) {
                if (s[i] == 'K') {
                    if (*elem)
                        (*elem)->next = root;
                    (*elem) = root;
                }
                if (s[i] == 'L') {
                    Stitch(elem, root->left, s);
                }
                if (s[i] == 'P') {
                    Stitch(elem, root->right, s);
                }
            }
        }

        void GetSequence(Cartesian<T> *root, Sequence<T> *res, string s) {
            if (!root) {
                return;
            }
            for (int i = 0; i < 3; ++i) {
                if (s[i] == 'K') {
                    res->Prepend(root->x);
                }
                if (s[i] == 'L') {
                    GetSequence(root->left, res, s);
                }
                if (s[i] == 'P') {
                    GetSequence(root->right, res, s);
                }
            }
        }
};


#endif //DATASTRUCTURE_CARTESIAN_H
