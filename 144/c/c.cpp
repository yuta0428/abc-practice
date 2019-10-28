#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))
#define foreach(i, k, n) for (int i = (k); (i) < (n); ++(i))
#define check(x) cout << #x "=" << x << endl;
#define checkpair(x, y) cout << #x "=" << x << ", " #y "=" << y << endl;

#define lli long long int
const lli INF = 1001001001001;

int main()
{
    lli n;
    cin >> n;
    lli a = 1L;
    lli b = n;
    lli lasta = a;
    lli lastb = b;
    while (a < b) {
        if (a * b == n) {
            lasta = a;
            lastb = b;
        }
        a++;
        b = n / a;
    }

    lli ans = lasta - 1 + lastb - 1;
    cout << ans << endl;
    return 0;
}

/*
最初素因数分解で約数出してやってみたが大きい数のときTLE
次に九九で縮小して考えられると思って何の段に属するかチェック
ただこれ結局19の段とか考えられないし、5,2*5みたいなパターンに対応できなくて詰み

1の段から順に1*n, 2*n/2, 3*n/3,...を考えて行く方式にした
何故かsample1でWA。他の一部でもWAになる。

解説見た感じ、a<=sqrt(N)の範囲で全探索すればよいとのこと
*/