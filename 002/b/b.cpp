#include <bits/stdc++.h>
using namespace std;

int main()
{
    string W;
    cin >> W;
    for (int i = 0; i < W.size(); i++){
        switch (W[i])
        {
            case 'a':
            case 'i':
            case 'u':
            case 'e':
            case 'o':
                break;
            default:
                cout << W[i];
                break;
        }
    }
    cout<<endl;
}

/*
char型だと挙動がおかしかった
おそらく採点側とコード書く側の環境の違いぽい
*/
