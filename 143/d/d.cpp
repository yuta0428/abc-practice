#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))
#define foreach(i, k, n) for (int i = (k); (i) < (n); ++(i))

int main()
{
    int N;
    cin >> N;
    int L[N];
    repeat(i, N) cin >> L[i];
    sort(L, L+N);
    int ans = 0;
    int a, b, c;
    foreach (i, 0, N)
    foreach (j, i+1, N)
    foreach (k, j+1, N)
    {
        int a = L[i];
        int b = L[j];
        int c = L[k];
        bool ok = a < b + c && b < c + a && c < a + b;
        if (!ok) break;
        ans++;
    }
    cout << ans << endl;
}
