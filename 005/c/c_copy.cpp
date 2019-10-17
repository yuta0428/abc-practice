#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))

int main()
{
    int T,N;
    cin >> T >> N;
    int A[N];
    repeat(i, N) cin >> A[i];
    int M;
    cin >> M;
    int B[M];
    repeat(i, M) cin >> B[i];
    bool ok = true;
    int a_i = 0;
    // 客にそれぞれに売れるたこ焼きがあるか調べる
    repeat(i,M){
        // 客の来店時間とたこ焼きのできる時間の差分がT秒以内のものを探す
        while (a_i < N && B[i] - A[a_i] > T) {
            a_i++;
        }
        // 最後のたこ焼きまで探索しきった（=客を捌ききれなかった）
        if (a_i == N) {
            ok = false;
            break;
        }
        // 客の来店時間の方が小さい（=客を待たせた）
        if (B[i] < A[a_i]) {
            ok = false;
            break;
        }
        // 売れる
        a_i++;
    }
    if (ok) cout << "yes" << endl;
    else cout << "no" << endl;
}

/*
参考: https://atcoder.jp/contests/abc005/submissions/7914800
*/