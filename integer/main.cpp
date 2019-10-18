#include "integer.hpp"

int main()
{
    string a, b;
    cin >> a >> b;

    cout << a << " + " << b << " = " << add(a, b) << endl;
    cout << a << " - " << b << " = " << ayir(a, b) << endl;

    return 0;
}