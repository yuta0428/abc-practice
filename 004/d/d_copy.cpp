#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;

int main()
{
    /*
    解法1: 広げ方の全探索
    ・一番左の箱を決めれば最終状態（移動数）は確定する
    ・青赤の移動量は等差数列の和なのでO(1)
    ・参考: https://atcoder.jp/contests/abc004/submissions/5440237
    */
    int R, G, B;
    cin >> R >> G >> B;

    int ans = INF;

    // 範囲-1000~1000まではおそらく適当。このケース全探索すればいいよね。
    // 緑を置く箱の最左端の位置が分かれば自ずと赤の最左端、青の最左端及び移動量も分かるよね
    for (int lG = -1000; lG <= 1000; ++lG)
    {
        // 赤の最左端の位置（左に行くほど順番が小さくなるのでminを取る）
        // min(赤を基点から均等に振り分ける場合の最左端, 緑の分左に寄せた場合の最左端）
        int lR = min(-100 - R / 2, lG - R);
        // 青の最左端の位置（右に行くほど順番が大きくなるのでmaxを取る）
        // max(青を基点から均等に振り分ける場合の最左端, 緑の分右に寄せた場合の最左端）
        int lB = max(100 - B / 2, lG + G);

        int s = 0;
        for (int i = lR; i < lR + R; ++i) // 赤の移動量（等差数列の和）lR=-100のとき0
            s += abs(-100 - i);
        for (int i = lG; i < lG + G; ++i) // 緑の移動量（等差数列の和）lG=0のとき0
            s += abs(0 - i);
        for (int i = lB; i < lB + B; ++i) // 青の移動量（等差数列の和）lB=100のとき0
            s += abs(100 - i);
        ans = min(ans, s);
    }

    cout << ans << endl;

    return 0;
}

/*
解説: https://www.slideshare.net/chokudai/abc004
動的計画法、メモ化で高速化してやってくらしい。よくわからなかった。

反省
・箱内の全てのマーブルをずらす場合、移動量が1の場合とかなくなるので単純な和の公式に当てはめられなかった
// #define sum(n) (n + 1) * n / 2
使うべきは初項を指定できる等差数列の和の公式だった
#define sum2(a,n,d) ((2*a + (n - 1)*d) * n / 2)
ただ、移動量は絶対値で取るため純粋な等差数列の和の公式に当てはめるには、順番が負と正での分岐が必要
オーダー的に約2000*300=60000なのでもう少し高速化できそうではあるがめんどい
*/