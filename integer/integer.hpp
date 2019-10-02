#include <bits/stdc++.h>
using namespace std;

#define htor(s) ((s) - 48)
#define rtoh(s) ((s) + 48)

void toldir(string &s, int n)
{
    while (s.size() < n)
        s = "0" + s;
}

string add(string a, string b)
{
    int ml = max(a.size(), b.size());

    toldir(a, ml);
    toldir(b, ml);

    string c(ml, '0');
    
    int yodda = 0, ry;
    for (int i = ml - 1; i >= 0; i--)
    {
        ry = htor(a[i]) + htor(b[i]) + yodda;
        c[i] = rtoh(ry % 10);
        yodda = ry / 10;
    }
    
    if (yodda)
        c = "0" + c;
        c[0] = rtoh(yodda);

    return c;
}