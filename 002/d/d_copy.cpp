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
    // int N, M;
    // cin >> N >> M;
    // bool con[N][N]; // 人間関係を隣接行列で表現
    // for (int i = 0; i < M; i++) {
    //     int x, y;
    //     cin >> x >> y;
    //     con[x - 1][y - 1] = true;
    //     con[y - 1][x - 1] = true; // 逆組み合わせもやっておく
    // }

    // int ans = 0;
    // // 全通りの派閥の組み合わせをビット全探索で調べる
    // for (int i = 1<<N; i >=0; i--) {
    //     bitset<32> groups(i);     // 派閥
    //     int len = groups.count(); // 1になっているビットの数=派閥の人数
    //     if (len <= ans) continue; // すでに答えより小さければ無視
        
    // }

    // // 全議員数分の組み合わせパターンを調べる。大きい組み合わせパターンから調べる。2^12=2048から
    // for (int i = 1<<N; i >=0; i--) {
    //     // 組み合わせパターンはbitを使用
    //     int len = bitset<32>(i).count();  // 1になっているビットの数=派閥の人数
    //     if (len <= ans) continue; // すでに答えより小さければ無視

    //     // この派閥を作ることができるか
    //     bool is_create = false;
    //     for (int j=0;j<N;j++) {
    //         for (int k=0;k<N;k++) {
    //             if (con[j][k] == true){ // この派閥は
    //                 is_create = true;
    //             }
    //         }
    //     }
    //     if (is_create) ans = len; // 作れるので更新！
    // }

    // for (int i=0; i<12; i++){
    //     for (int j=i; j<12; j++){
    //         cout << "(" << i << "," << j << ")" << endl;
    //     }
    // }
}
