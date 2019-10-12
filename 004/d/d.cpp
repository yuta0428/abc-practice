#include <bits/stdc++.h>
using namespace std;
#define sum(n) (n+1)*n/2.0f
int main()
{
    int R,G,B;
    cin >> R>>G>>B;
    int s = 0;
    if (G < 200){
        int s = 0;
        for (int A : {R, G, B})
        {
            int r = A / 2;     // 右に移動する個数
            int l = A - r - 1; // 左に移動する個数（箱に残す分除く）
            s += sum(r) + sum(l);
        }
    }
    else{
        // 左右の個数を見て均等に動かしたほうがトータルで動かす量が少ない
        // int total = (R + G + B) / 2 - 99;
        // int rover = R < total ? 0 : R - total;
        // int lover = B < total ? 0 : B - total;

        // s += R < total ? sum(R - 1) : sum(total - 1) + sum(rover);
        // s += B < total ? sum(B - 1) : sum(total - 1) + sum(lover);

        // assert(rover >= 0);
        // assert(lover >= 0);
        // s += sum(99 - rover);
        // s += sum(99 - lover);
        // int r = R - rover;
        // int l = B - lover;
        // int nokori = G - (99 - rover) - (99 - lover) - 1;
        // for (int i = 0; i < nokori;i++){
        //     // cout << r << ", " << l << endl;

        //     // 少ない方を移動させる
        //     if (r < l)
        //     {
        //         s += r;
        //         r++;
        //     }
        //     else
        //     {
        //         s += l;
        //         l++;
        //     }
        //     // cout << s << endl;
        // }
    }
    cout << s << endl;
}

/*
G > 200のケースの解き方がわからず死亡
均等に移動させるのかと思ったが、均等にした上でR,B動かした時点で正解ケースより多くなっていて謎
*/