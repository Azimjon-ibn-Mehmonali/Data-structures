/*
    Sum Segment Treening implementatsiyasi.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

class segmentTree
{
private:
    vl st, a;
    int n;

    int left(int p) { return (p << 1) + 1; }
    int right(int p) { return (p << 1) + 2; }

    void build(int p, int l, int r)
    {
        if (l == r)
            st[p] = a[l];
        else
        {
            build(left(p), l, (l + r) / 2);
            build(right(p), (l + r) / 2 + 1, r);
            st[p] = st[left(p)] + st[right(p)];
        }
    }

    ll rsq(int p, int l, int r, int i, int j)
    {
        if (i <= l && r <= j)
            return st[p];
        
        if (r < i || j < l)
            return 0;
        
        return rsq(left(p), l, (l + r) / 2, i, j) +
                rsq(right(p), (l + r) / 2 + 1, r, i, j);

    }

    void update(int p, int l, int r, int i, ll osh)
    {
        if (i < l || r < i)
            return;
        
        st[p] += osh;
        if (r != l)
        {
            update(left(p), l, (l + r) / 2, i, osh);
            update(right(p), (l + r) / 2 + 1, r, i, osh);
        }
    }

public:
    segmentTree(vl _a)
    {
        a = _a;
        n = a.size();
        st.assign(4 * n, 0);
        build(0, 0, n - 1);
    }
    ll rsq(int i, int j) { return rsq(0, 0, n - 1, i, j); }
    void update(int i, ll yangi)
    {
        update(0, 0, n - 1, i, yangi - a[i]);
        a[i] = yangi;
    }
};