#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))
#define foreach(i, k, n) for (int i = (k); (i) < (n); ++(i))
#define check(x) cout << #x "=" << x << endl;
#define checkpair(x, y) cout << #x "=" << x << ", " #y "=" << y << endl;

const int INF = 1001001001;
#define lli long long int

int main()
{
    int R, C, sy, sx, gy, gx;
    cin >> R >> C;
    cin >> sy >> sx;
    cin >> gy >> gx;
    char c[R][C];
    int b[R][C];
    repeat(i, R) repeat(j, C) {
        cin >> c[i][j];
        b[i][j] = c[i][j] == '.' ? -1 : INF;
    }
    queue<tuple<int, int>> q;
    q.push(make_tuple(sy-1, sx-1));
    int ans = 0;
    int v[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
        ans++;
        queue<tuple<int, int>> tmpq = q;
        while (!q.empty()) q.pop();
        while (!tmpq.empty()) {
            auto t = tmpq.front();
            tmpq.pop();
            int x, y;
            tie(y, x) = t;
            repeat(i, 4)
            {
                int vy = y + v[i][0];
                int vx = x + v[i][1];
                if (b[vy][vx] != -1) continue;
                b[vy][vx] = ans;
                q.push(make_tuple(vy, vx));
            }
        }
    }
    cout << b[gy - 1][gx - 1] << endl;
    return 0;
}
