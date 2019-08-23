#include <bits/stdc++.h>

using namespace std;

template <class T>
class pqueue {
    private:
        vector<T> navbat;

        int left(int);
        int right(int);
        int parent(int);
        int search(T);

        void bubleup(int);
        void bubledown(int);
        void swap(int, int);
        void removein(int);
    
    public:
        void push(T);
        T top();
        T pop();
        bool remove(T);
        int size();
        bool empty();
        void vizual();
        
};

template<class T>
int pqueue<T>::left(int node) { return (node << 1) + 1 ; }

template<class T>
int pqueue<T>::right(int node) { return (node << 1) + 2; }

template<class T>
int pqueue<T>::parent(int node) { return (node - 1) >> 1; }

template<class T>
int pqueue<T>::size() { return navbat.size(); }

template<class T>
bool pqueue<T>::empty() { return navbat.empty(); }

template<class T>
void pqueue<T>::push(T node)
{
    navbat.push_back(node);

    if (navbat.size() == 1)
        return;
    
    bubleup(navbat.size() - 1);
}

template<class T>
void pqueue<T>::swap(int a, int b)
{
    T temp = navbat[a];
    navbat[a] = navbat[b];
    navbat[b] = temp;
}

template<class T>
void pqueue<T>::bubleup(int index)
{
    int par = parent(index);

    if (navbat[index] < navbat[par])
    {
        swap(index, par);
        bubleup(par);
    }
}

template<class T>
void pqueue<T>::bubledown(int index)
{
    int maxindex = navbat.size() - 1;
    int l = left(index), r = right(index);
    int minchild = -1;

    if (l <= maxindex && r <= maxindex)
        minchild = (navbat[l] < navbat[r]) ? l : r;
    else if (r <= maxindex)
        minchild = (navbat[r] < navbat[index]) ? r : -1;
    else if (l <= maxindex)
        minchild = (navbat[l] < navbat[index]) ? l : -1;
    
    if (minchild == -1)
        return;

    if (navbat[minchild] < navbat[index])
    {
        swap(index, minchild);
        bubledown(minchild);
    }
}

template<class T>
T pqueue<T>::top()
{
    if (navbat.empty())
        throw runtime_error("pqueue is empty!");
    else
        return navbat[0];
}

template<class T>
int pqueue<T>::search(T node)
{
    int size = navbat.size();

    for (int i = 0; i < size; i++)
        if (navbat[i] == node)
            return i;

    return -1;
}

template<class T>
bool pqueue<T>::remove(T node)
{
    int place = search(node);

    if (place == -1)
        return false;
    
    removein(place);
    
    return true;
}

template<class T>
void pqueue<T>::removein(int place)
{
    swap(place, navbat.size() - 1);
    navbat.pop_back();
    
    if (navbat[parent(place)] >= navbat[place])
        bubleup(place);
    else
        bubledown(place);
}

template<class T>
T pqueue<T>::pop()
{
    if (navbat.empty())
        throw runtime_error("pqueue is empty!");
  
    T temp = navbat[0];
    removein(0);

    return temp;    
}
