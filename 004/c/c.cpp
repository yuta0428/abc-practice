#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[6] = {1, 2, 3, 4, 5, 6};
    int N;
    cin >>N;
    N %= 30;
    for (int i = 0; i < N; i++)
    {
        int i1 = i % 5 + 1;
        int i2 = i % 5 + 2;
        swap(a[i1-1], a[i2-1]);
    }
    for (int aa : a) cout << aa;
    cout << endl;
}

/*
出力して結果見た感じ30回周期で元に戻るので30で割った余りの回数行うだけで良い
*/