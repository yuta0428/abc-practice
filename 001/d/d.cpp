#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    pair<int, int> SE[N];
    for (int i = 0; i < N; i++) {
        scanf("%d-%d", &SE[i].first, &SE[i].second);
    }

    for(auto& p : SE){
        p.first = p.first % 10 < 5 ? floor(p.first / 10.f) * 10 : floor(p.first / 10.f) * 10 + 5;
        int s = p.second % 10;
        p.second = 0 < s && s <= 5 ? ceil(p.second / 10.f) * 10 - 5 : ceil(p.second / 10.f) * 10;
        if (p.second%100 == 60) p.second += 40;
    }

    sort(SE, SE+N);

    int a,b;
    tie(a, b) = SE[0];
    for (auto& p : SE) {
        if (b >= p.first) {
            b = max(p.second, b);
            continue;
        }else{
            printf("%04d-%04d\n", a, b);
            tie(a, b) = p;
        }
    }
    printf("%04d-%04d\n", a, b);
}

/*
時間軸を配列として考えて、該当する時間帯を塗りつぶし雨の時間帯を割り出す

最速はいもす法を使って解かれてるのがほとんど
startを+1, end+1を-1にして1以上の箇所をみるやりかた
*/
