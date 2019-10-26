#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))
#define foreach(i, k, n) for (int i = (k); (i) < (n); ++(i))
#define check(x) cout << #x "=" << x << endl;
#define checkpair(x, y) cout << #x "=" << x << ", " #y "=" << y << endl;
#define puts3(x, y, z) \
    cout << #x "=" << x << ", " #y "=" << y << ", " #z "=" << z << endl;
const int INF = 1001001001;

int main()
{
    int N, M;
    cin >> N >> M;
    int a, b, c;
    bool ok = false;
    a = b = 0;
    c = M / 4;
    int n = N - (a + b + c);  //不足人数
    int m = M - (a * 2 + b * 3 + c * 4);//不足足の数
    int max = min(c, n);
    for(int i=0;i<=max;i++){
        int nn = n + i;
        int mm = m + i * 4;
        for (int x = 0; x <= nn;x++) {
            int k = 2 * (nn - x) + 3 * (x);
            if (k==mm) {
                a += (nn - x);
                b += x;
                c -= i;
                ok = true;
                break;
            }else if(k>mm){
                break;
            }
        }
        if (ok) break;
    }

    if (ok) cout << a << " " << b << " " << c << endl;
    else cout << "-1 -1 -1" << endl;
    return 0;
}

/*
赤ちゃん、老人、大人それぞれ0人のケースもあり得ることに気づくまでに時間かかった


解説
https://atcoder.jp/contests/abc006/submissions/7981739
a={0,N},
b={0,1},
c=N-(a+b)
としてそれぞれ探索していけばよい
bを0,1しか考えなくてよいのは、老人が2人のとき足の数は6本。これは赤ちゃん1人と大人1人でも表せるため。
*/