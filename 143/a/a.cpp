#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))

int main()
{
    int A,B;
    cin >> A >> B;
    cout << max(A-B*2, 0) << endl;
}
