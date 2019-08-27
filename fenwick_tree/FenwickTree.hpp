#include <bits/stdc++.h>
using namespace std;

#define LSB(s) ((s) & (-s))

class FenwickTree {
    private:
        vector<int> ft;
    
    public:
        FenwickTree(vector<long long> a)
        {
            ft.push_back(0);
            ft.insert(ft.end(), a.begin(), a.end());
            for (int i = 1; i <= a.size(); i++)
            {
                int j = i + LSB(i);
                if (j <= a.size())
                    ft[j] += ft[i];
            }
        }
        long long rsq(int i)
        {
            long long sum = 0;
            while (i > 0)
                sum += ft[i], i -= LSB(i);
            
            return sum;
        }
        
        long long rsq(int i, int j)
        {
            return rsq(j) - rsq(i - 1);
        }

        void add(int i, int v)
        {
            while (i < ft.size()) {
                ft[i] += v;
                i += LSB(i);
            }
        }

        long long at(int i)
        {
            return rsq(i, i);
        }

        void update(int i, int v)
        {
            long long dif = v - at(i);
            add(i, dif);
        }
};