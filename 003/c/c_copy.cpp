#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,K;
    cin >> N >> K;
    vector<int> R(N);
    for (int i = 0; i < N; i++) cin >> R[i];
    std::sort(R.begin(), R.end());

    double C = 0;
    for (int i = N-K; i < N; i++){
        C = (C + R[i]) / 2.0f;
    }
    printf("%lf\n", C);
}
/*
1 <= N <= 100なので最大100!通りで到底全パターン調べられないよ
→ 組み合わせが膨大なときは、計算をうまくまとめるか、規則性を見つけよう
→今回は規則性を見つける

単純に考えて大きいレートの動画をK個見るのが期待値が最も高い
なのでK個の動画の中でレートの低いものから見れば最大値を出せるよね
*/
