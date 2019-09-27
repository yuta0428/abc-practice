#include <bits/stdc++.h>
using namespace std;

// https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361#next_combination
/* next combination */
int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

int main()
{
    int N,K;
    cin >> N >> K;
    int R[N];
    for (int i = 0; i < N; i++) cin >> R[i];

    double ans = 0;
    // nPkの順列問題（N個からK個取り出して並べる）nCkに対して、それぞれkPkすることでnPkが求まる
    int bit = (1 << K) - 1;  // bit = {0, 1, 2 ,..., K}
    for (; bit < (1 << N); bit = next_combination(bit)) { // nCk
        vector<int> v;
        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) v.push_back(i);
        }
        do {
            double C = 0;
            for (int i : v) C = (C + R[i]) / 2.0f;
            ans = max(ans, C);
        } while (std::next_permutation(v.begin(), v.end()));  // kPk
    }
    printf("%lf\n", ans);
}

/*
これだとTLE (Time Limit Exceeded)、一部RE (Runtime Error)だった
改善が必要
*/
