#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, bmaxim, bminim, bb, s = 0, p = 1, posmaxim, posminim;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        cin >> bb;
        a.push_back(bb);
    }
    bmaxim = a[0];
    posmaxim = 0;
    bminim = a[0];
    posminim = 0;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] > 0)
            s += a[i];
    for (int i = 1; i < a.size(); ++i) {
        if (bmaxim < a[i]) {
            bmaxim = a[i];
            posmaxim = i;
        }
        if (bminim > a[i]) {
            bminim = a[i];
            posminim = i;
        }
    }

    cout << s << " ";
    if (posminim > posmaxim)
        for (int i = posmaxim + 1; i < posminim; ++i)
            p *= a[i];
    if (posminim < posmaxim)
        for (int i = posminim + 1; i < posmaxim; ++i)
            p *= a[i];
    cout << p;
    return 0;
}