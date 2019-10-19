#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))
#define foreach(i, k, n) for (int i = (k); (i) < (n); ++(i))
#define check(x) cout << #x "=" << x << endl;
#define checkpair(x, y) cout << #x "=" << x << ", " #y "=" << y << endl;

vector<int> roots[301];

void next_root(int now, int end, int mark, vector<int>& root)
{
    mark |= 1 << now;
    // checkpair(now, end);
    // cout << (bitset<8>)mark << endl;
    if (now == end) {
        cout << "ok" << endl;
    }
    repeat(i, root.size())
    {
        int r = root[i];
        if (mark & 1<<r) continue; // 既に通った
        // 次のルート探索
        next_root(r, end, mark, roots[r]);
    }
}

int main()
{
    int N, M, L;
    cin >> N >> M >> L;

    int rl = 301;
    int fuel[rl][rl];
    repeat(i, rl) repeat(j, rl) fuel[i][j] = 0;
    repeat(i, M){
        int a, b, c;
        cin >> a >> b >> c;
        fuel[a][b] = c; // 街の移動に必要な燃料
        fuel[b][a] = c; // 街の移動に必要な燃料
        roots[a].push_back(b);
    }
    int memo[rl][rl];
    repeat(i, rl) repeat(j, rl) memo[i][j] = INT_MAX;
    int Q;
    cin >> Q;
    repeat(i, Q){
        int s, t;
        cin >> s >> t;
        // if (s > t) {
        //     int tmp = t;
        //     t = s;
        //     s = tmp;
        // }
        next_root(s, t, 0, roots[s]);
    }
}

/*
再帰でやってみる
複数パターンがありえるのどう表現すればいいか不明
*/