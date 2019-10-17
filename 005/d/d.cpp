#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))
#define foreach(i, k, n) for (int i = (k); (i) < (n); ++(i))

int main()
{
    int N;
    cin >> N;
    int D[N][N];
    repeat(i, N) repeat(j, N) cin >> D[i][j];
    int Q;
    cin >> Q;
    int P[Q];
    repeat(i, Q) cin >> P[i];

    // 1. 右下(or左上左下とかでも可) までの長方形全通りに対してそれぞれ美味しさの合計を出すO(N ^ 2)
    // 左上(0,0)右下(i,j)として考える
    int len = N + 1; // 長方形同士の減算をする際に内側に面積0の長方形を考えたほうが計算しやすいので1つ大きめに取る
    int deliSumArray[len][len];
    repeat(i, len) repeat(j, len) deliSumArray[i][j] = 0; // 0初期化
    foreach(i, 1, len) {
        int row = 0; // 行内の増分値
        foreach(j, 1, len) {
            row += D[i-1][j-1]; // Dは0~Nのindexで考える
            // 一区画手前の長方形の美味しさの合計 + 行内での増分値 = 左上基点の長方形の美味しさの合計
            deliSumArray[i][j] = deliSumArray[i - 1][j] + row;
        }
    }
    // repeat(i, len) {
    //     repeat(j, len) cout << std::setw(2) << deliSumArray[i][j] << " ";
    //     cout << endl;
    // }

    // 2. 全長方形に対してそれぞれ美味しさの合計を出すO(N ^ 4)
    // 同じ面積で合計が小さい方をとり得るケースはないため、W*H（焼けるたこ焼きの個数）に対応するmaxを記憶すればよい
    int deliSumAllArray[N * N];
    repeat(i, N * N) {deliSumAllArray[i] = 0;} // 0初期化
    repeat(w, len)
    repeat(h, len)
    repeat(x, len - w)
    repeat(y, len - h)
    {
        // (x, y, w, h)の長方形の美味しさの合計を求める
        int area = deliSumArray[x + w][y + h]   // (0,0)から(x+w,y+h)までの長方形に、
                    - deliSumArray[x + w][y]    // (0,0)から(x+w,y)までの長方形と、
                    - deliSumArray[x][y + h]    // (0,0)から(x,y+h)までの長方形を引いて、
                    + deliSumArray[x][y];       // (0,0)から(x,y)までの長方形を足す（重なり部分）
        deliSumAllArray[w * h] = max(deliSumAllArray[w * h], area); // maxを取る
    }
    // repeat(i, N * N) cout << deliSumAllArray[i] << ", ";
    // cout << endl;

    // 3. 全たこ焼き個数に対して最大値を求めるO(N ^ 2)
    // 少ない個数で美味しさの合計が大きいケースを考慮するため、一つ前の合計値とmaxを取って更新する
    foreach(i, 1, N*N) {
        deliSumAllArray[i] = max(deliSumAllArray[i], deliSumAllArray[i - 1]);
    }
    // repeat(i, N * N) cout << deliSumAllArray[i] << ", ";
    // cout << endl;

    // 焼けるたこ焼きの個数に対応する美味しさの合計を取る
    repeat(i, Q) cout << deliSumAllArray[P[i]] << endl;
}

/*
全くわからなかったので解説を見た

全てのパターンの長方形の面積は右下までの面積の長方形の面積の和差で表せる
なので、
1. 右下(or左上左下とかでも可)までの長方形全通りに対してそれぞれ美味しさの合計を出すO(N^2)
2. 全長方形に対してそれぞれ美味しさの合計を出すO(N^4)
3. 全たこ焼き個数に対して最大値を求めるO(N^2)
で、店員が出せる最大値が分かる

参考: http://competitive-kivantium.hateblo.jp/entry/2016/12/14/144030
*/