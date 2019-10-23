#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))
#define foreach(i, k, n) for (int i = (k); (i) < (n); ++(i))
#define check(x) cout << #x "=" << x << endl;
#define checkpair(x, y) cout << #x "=" << x << ", " #y "=" << y << endl;

const int INF = 1001001001;

int main()
{
    int N;
    cin >> N;
    string ans = "NO";
    if (N % 3 == 0) ans = "YES";

    for (char s : to_string(N)){
        if (s == '3') {
            ans = "YES";
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
