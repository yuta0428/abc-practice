#include <bits/stdc++.h>
using namespace std;
/*
いもす法版
色々やり方あるが一番シンプルな
0000 => 0
0005 => 1
0010 => 2
...
1310 => 262
...
2400 => 480
という時刻そのものをindexをとして扱うやり方でやる。
ex) 0003-0016 -> 0000-0020と考えられるため => 0, 4

注意点は
0055 => 11, 0100 => 20
0155 => 31, 0200 => 40
0355 => 51, 0200 => 60
のようにxx60~xx99までは時刻として扱わないindexになる。塗りつぶしされるかもだが出力時に無視してあげる

参考) https://atcoder.jp/contests/abc001/submissions/1398887
*/

int main()
{
    int len = 2400/5+1;
    int t[len] = {};
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int a,b;
        scanf("%d-%d", &a, &b);
        int ia = a/5;
        int ib = b/5 + (b%5!=0); // 切り上げ処理
        t[ia]++;
        t[ib]--;
    }

    // シミュレート
    for (int i = 0; i < len; i++) {
        if (0 < i) t[i] += t[i - 1];
    }

    bool c = false;
    for (int i = 0; i < len; i++) {
        if (i%20>=12)continue;

        if (t[i] > 0) {
            if (!c){
                printf("%04d",i*5);
                c = true;
            }
        }
        else {
            if (c){
                printf("-%04d\n",i*5);
                c = false;
            }
        }
    }
}

