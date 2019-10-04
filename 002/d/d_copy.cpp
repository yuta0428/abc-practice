#include <bits/stdc++.h>
using namespace std;

/*
派閥のパターンは最大でも2^12で2048通りなので全通りに対して派閥に作ることができるかを調べる
やり方はbitを使うか、再帰関数を使うか
適当な貪欲法だと漏れがでるので確実にな答えを返すのでやりましょう
参考）https://atcoder.jp/contests/abc002/submissions/1481738

・全通りの派閥の組み合わせを調べる方法 => ビット全探索
・派閥内の全員が知り合い同士を調べる方法 => 完全グラフかを調べる

ビット全探索 https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361#bit-全探索
    for (int bit = 0; bit < (1<<n); ++bit){}
    (0), (1), (0 1), (2), (0 2), ..., (0 1 .. n-1)
    各数字に対してどの桁が1になっているかを列挙することで調べることが出来る

完全グラフかを調べる
    隣接行列で頂点と辺のつながりを表現することできる https://mathtrain.jp/graphmatrix
    頂点(A,B)が辺を持つか A行B列が1なら持つ、0なら持たない
 */

int main() {
    int N, M;
    cin >> N >> M;
    bool con[N][N]; // 人間関係を隣接行列で表現+
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        con[x - 1][y - 1] = true;
        con[y - 1][x - 1] = true; // 逆組み合わせもやっておく
    }

    int ans = 0;
    // 全通りの派閥の組み合わせをビット全探索で調べる
    for (int i = 1; i <= (1<<N); i++) {
        bitset<16> groups(i);     // 派閥
        int len = groups.count(); // 1になっているビットの数=派閥の人数

        bool ok = true;
        // 2人組の全パターンを挙げて派閥内の人同士が互いに知り合いか=完全グラフが成り立つかを確認する
        for(int j=0; j<N; j++){
            for (int k=0; k=j; k++){
                if (groups.test(j) && groups.test(k) // j,kさんは派閥に属しているか
                && !con[j][k]) // j,kさんは知り合い同士でないか
                {
                    ok = false; // 派閥内の人同士が互いに知り合いでないといけないためどの組かでも知り合いじゃない組がいたら無効
                }
            }
        }
        if(ok)ans=len;
    }
}
