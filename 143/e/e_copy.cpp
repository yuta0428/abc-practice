#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))

const int INF = 1001001001;

int main()
{
    int N, M, L;
    cin >> N >> M >> L;

    // 全点間最短路を求めるための2次元配列を定義
    // 各町を頂点、各道を辺、各辺の距離は道の距離
    vector<vector<int>> dist(N, vector<int>(N, INF)); // a,b間の辺が存在しないときはINF扱い(INT_MAXだと値がオーバーフローする可能性があった)
    repeat(i, N) dist[i][i] = 0; // a=bのときは0
    repeat(i, M){
        int a, b, c;
        cin >> a >> b >> c;
        a--; // 1から始まるので0にしとく
        b--;
        dist[a][b] = dist[b][a] = c; // a,b間のコストを入れる（a,bのペアが重複する場合はminを取る必要がある）
    }

    // ワーシャルフロイドで全点間最短路を求める=各町間の最短距離
    repeat(k, N) repeat(i, N) repeat(j, N) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    // グラフその2を作る
    // 各町を頂点、最短距離がL以下である町の組の間に距離1の辺を張る
    vector<vector<int>> dist2(N, vector<int>(N, INF));
    repeat(i, N) repeat(j, N){
        if (dist[i][j] <= L) dist2[i][j] = 1;
    }
    // ワーシャルフロイドをグラフ2に対してもやる
    // = 各町間を移動する際に必要な燃料補給回数の最小値が求められる
    repeat(k, N) repeat(i, N) repeat(j, N) {
        dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);
    }

    int Q;
    cin >> Q;
    repeat(i, Q){
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        int ans = dist2[s][t] - 1; // 最初は燃料MAXなので1回分の補給は無視する
        if (dist2[s][t] == INF) ans = -1; // 道がない経路は-1
        cout << ans << endl;
    }
}

/*
解説: https://youtu.be/3U_N7zelnMM?t=3990

１回の補給でどこまで行けるのか
・最初に１回補給すると考えて、、１回の補給で辿れる頂点を結ぶ辺の数が補給数になるようなグラフを考える
・aからbまでの距離をdist[a][b]とすると、辺が晴れる条件はdist[a][b] <= L
・全頂点間の距離が分かってればグラフが作れる
それを求めるアルゴリズム=ワーシャルフロイド

初期化として
    dist[a][b] = if 辺がある->長さ
                elseif ない->INF
                elseif a==0->0
全点間最短路を求める
    for k=1..N
    for i=1..N
    for j=1..N
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])
=> i→jの経路よりi→k→jの経路のほうが短かったらそっちに更新するという式
ワーシャルフロイドの注意点としては、経由点のkを一番外に持ってくることらしい
kを見てるとき、k-1以下のみからなる最短路が全部正しく求まってるから
*/