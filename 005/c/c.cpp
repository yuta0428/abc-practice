#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))

int main()
{
    int T, N;
    cin >> T >> N;
    int A[N];
    repeat(i, N) cin >> A[i];
    int M;
    cin >> M;
    int B[M];
    repeat(i, M) cin >> B[i];
    int b_i = 0;
    repeat(i,N){
        int a = A[i];
        int b = B[b_i];
        if (a > b) break; // 客を待たすのでno
        if (N-i < M-b_i) break; // 客を捌ききれないのでno
        if (abs(a-b) <= T) b_i++; // すぐに売れる
        if (b_i == M) break; // 全部捌いたら終わり
    }
    if (b_i == M) cout << "yes" << endl;
    else cout << "no" << endl;
}

/*
なぜかWA。。。
M人に対してたこ焼きが売れるかどうかループを回して判定を行うらしい
N個のたこ焼きに対してループを回し売られてない中でT秒以内のものを最も古いものを売る
なければno, 全て売れればyes

→どうやら配列長を不定数で宣言していたのがいけなかったよう。宣言方法を変えたらACになった
*/