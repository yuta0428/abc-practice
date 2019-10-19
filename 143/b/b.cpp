#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))

int main()
{
    int N;
    cin >> N;
    int d[N];
    repeat(i, N) cin >> d[i];
    int ans = 0;
    repeat(i, N) for (int j = i + 1; j < N; j++){
        ans += d[i] * d[j];
    }
    cout << ans << endl;
}
