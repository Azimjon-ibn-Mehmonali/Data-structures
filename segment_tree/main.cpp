#include "segmentTree.hpp"

int main(int argc, const char** argv)
{
    int n;
    scanf("%d", &n);

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    segmentTree st(a);

    int m;
    scanf("%d", &m);

    int x, y;
    char c;
    while (m--){
        cin >> c >> x >> y;

        if (c == 'u')
            st.update(x - 1, y);
        else
            printf("%lld ", st.rsq(x - 1, y - 1));
    }

    return 0;
}