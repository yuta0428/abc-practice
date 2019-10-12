#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c[4][4];
    for (int i = 0; i < 4;i++){
        for (int j = 0; j < 4;j++){
            cin >> c[i][j];
        }
    }
    for (int i = 3; i >= 0;i--){
        cout << c[i][3] << " " << c[i][2] << " " << c[i][1] << " " << c[i][0] << endl;
    }
}
