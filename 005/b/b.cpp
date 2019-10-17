#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))

int main()
{
    int N;
    cin >> N;
    int ans = 100;
    repeat(i,N){
        int T;
        cin >> T;
        ans = min(ans, T);
    }
    cout << ans << endl;
}
