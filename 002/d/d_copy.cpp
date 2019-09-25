#include <bits/stdc++.h>
using namespace std;

/*
最大でも2^12で2048通りなので全パターンに対して派閥に作ることができるかを調べる
やり方はbitを使うか、再帰関数を使うか
適当な貪欲法だと漏れがでるので確実にな答えを返すのでやりましょう

参考）https://atcoder.jp/contests/abc002/submissions/1481738
 */

int main() {
    int N, M;
    cin >> N >> M;
    bool con[N][N]; // どの組合せが存在するか
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        con[x - 1][y - 1] = true;
        con[y - 1][x - 1] = true; // 逆組み合わせもやっておく
    }

    int ans = 0;
    // 全議員数分の組み合わせパターンを調べる。大きい組み合わせパターンから調べる。2^12=2048から
    for (int i = 1<<N; i >=0; i--) {
        // 組み合わせパターンはbitを使用
        int len = bitset<32>(i).count();  // 1になっているビットの数=派閥の人数
        if (len <= ans) continue; // すでに答えより小さければ無視

        // この派閥を作ることができるか
        bool is_create = false;
        for (int j=0;j<N;j++) {
            for (int k=0;k<N;k++) {
                if (con[j][k] == true){ // この派閥は
                    is_create = true;
                }
            }
        }
        if (is_create) ans = len; // 作れるので更新！
    }
}
