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