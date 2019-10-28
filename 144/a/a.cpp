#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))
#define foreach(i, k, n) for (int i = (k); (i) < (n); ++(i))
#define check(x) cout << #x "=" << x << endl;
#define checkpair(x, y) cout << #x "=" << x << ", " #y "=" << y << endl;

const int INF = 1001001001;

int main()
{
    int a,b;
    cin >> a >> b;
    cout << (a < 10 && b < 10 ? a * b : -1) << endl;
    return 0;
}
