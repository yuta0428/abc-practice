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
    int c[N];
    repeat(i, N) cin >> c[i];
    int cnt = 0;
    int ci = 0;
    repeat(i,N){
        int cc = c[ci];
        if (i + 1 >= cc) {
            ci++;
            continue;
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}

/*
雑にやってみたが当然だめだった
*/