#include <bits/stdc++.h>
#include "pqueue.cpp"

using namespace std;

int main()
{
    pqueue<int> pqi;
    
    int t;

    cout << "Tartibsiz massiv:\n";
    for (int i = 1; i <= 10; i++)
    {
        t = random() % 20;
        cout << t << " ";
        pqi.push(t);
    }

    //pqi.remove(13);
    cout << "\nMinimum PQ:\n";
    while (!pqi.empty()){
        cout << pqi.pop() << " ";
    }

    return 0;
}