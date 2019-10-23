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
    int a[3] = {0, 0, 1};
    for (int i = 4; i <= n; i++){
        int an = a[2] + a[1] + a[0];
        a[0] = a[1] % 10007;
        a[1] = a[2] % 10007;
        a[2] = an % 10007;
    }
    cout << (n <= 3 ? a[n-1] : a[2]) << endl;
    return 0;
}
