#include <bits/stdc++.h>
using namespace std;

#define htor(s) ((s) - 48)
#define rtoh(s) ((s) + 48)

string add(string, string);
string ayir(string, string);
void noltozala(string &);

void noltozala(string & s)
{
    int ns = 0;
    while (s[ns] == '0')
        ns++;
    s.erase(0, ns);
}

string add(string a, string b)
{
    if (a.size() < b.size())
        return add(b, a);
    
    a = "0" + a;

    int i, j;
    i = a.size() - 1;
    j = b.size() - 1;
    
    for (; j >= 0; i--, j--)
    {
        a[i] += htor(b[j]);
    }

    i = a.size() - 1;

    for (; i > 0; i--)
    {
        if (htor(a[i]) > 9)
        {
            a[i] -= 10;
            a[i - 1]++;
        }
    }
    noltozala(a);

    return a;
}

string ayir(string a, string b)
{
    int i, j;
    i = a.size() - 1;
    j = b.size() - 1;

    for (;j >= 0; i--, j--)
        a[i] -= htor(b[j]);
    
    i = a.size() - 1;

    for (; i > 0; i--)
    {
        if (htor(a[i]) < 0)
        {
            a[i] += 10;
            a[i - 1]--;
        }
    }
    noltozala(a);

    return a;
}