#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))

int main()
{
    int N, M, L;
    cin >> N >> M >> L;

    int rl = N + 1;
    int root[rl][rl];
    repeat(i, rl) repeat(j, rl) root[i][j] = 0;
    repeat(i, M){
        int a, b, c;
        cin >> a >> b >> c;
        root[a][b] = c; // 街の移動に必要な燃料
        root[b][a] = c; // 街の移動に必要な燃料
    }
    int memo[rl][rl];
    repeat(i, rl) repeat(j, rl) memo[i][j] = INT_MAX;
    int Q;
    cin >> Q;
    repeat(i, Q){
        int s, t;
        cin >> s >> t;
        if (s > t) {
            int tmp = t;
            t = s;
            s = tmp;
        }
        if (memo[s][t] != INT_MAX || memo[t][s] != INT_MAX) {
            cout << memo[s][t] << endl;
            continue;
        }
        int ans = INT_MAX;
        // ルートの組み合わせを全探索
        int start = (1 << t) | (1 << s);
        int end = (1 << t + 1) - 1 ^ (1 << s) - 1;
        for (int b = end; b >= start; b -= 1<<s+1)
        {
            // それぞれの経由ルートでの燃料補給回数を調べる
            bool move = true;
            int cnt = 0;
            int prev = s;
            int LL = L;
            for (int j = s + 1; j <= t; j++)
            {
                if (!(b & 1<<j)) continue;
                int ll = root[prev][j]; //移動に必要な燃料
                prev = j;
                if (ll == 0){
                    // 道がなかった
                    move = false;
                    break;
                }

                if (LL >= ll){
                    // 燃料足りる=移動できる
                    LL -= ll;
                }
                else if (j == s+1) {
                    // 1回目で燃料が足りないのは移動できない扱い
                    move = false;
                    break;
                }
                else {
                    // 燃料が足りなければ前の街で補給した扱いにする
                    LL = L;
                    LL -= ll;
                    cnt++;
                }
            }
            // 最小補給回数を調べる
            if (move) ans = min(ans, cnt);
            if (ans == 0) break;
        }
        cout << (ans != INT_MAX ? ans : -1) << endl;
        memo[s][t] = memo[t][s] = ans;
    }
}

/*
TLEになる・・
ルート全探索がダメそう
メモ化したがそれでも遅い
*/