#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    vector<int> p[N];
    for (int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        p[x-1].push_back(y);
        p[y-1].push_back(x);
    }
    for (int i = 0; i < N; i++) {
        p[i].push_back(i + 1);
        sort(p[i].begin(), p[i].end());
    }

    int lenmax = 0;
    for (int i = 0; i < N; i++)
    {
        set<int> src(p[i].begin(), p[i].end());
        for (int j = i + 1; j < N; j++) {
            set<int> tar(p[j].begin(), p[j].end());
            vector<int> v;
            set_intersection(p[i].begin(), p[i].end(), p[j].begin(), p[j].end(),back_inserter(v));
            int s = v.size();
            lenmax = max(lenmax, s);
        }
    }
    if (lenmax == 0) lenmax = 1;
    cout << lenmax << endl;
}


/*
直和積とかリストの長さとかでやったがだめだった
*/
