#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))
#define foreach(i, k, n) for (int i = (k); (i) < (n); ++(i))
#define check(x) cout << #x "=" << x << endl;
#define checkpair(x, y) cout << #x "=" << x << ", " #y "=" << y << endl;

const int INF = 1001001001;

int main()
{
    int n;
    cin >> n;
    bool ok = false;
    foreach(i, 1, 10)
    foreach(j, 1, 10){
        if (n == i*j){
            ok = true;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
