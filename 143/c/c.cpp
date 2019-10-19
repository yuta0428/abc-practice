#include <bits/stdc++.h>
using namespace std;

#define repeat(i, n) for (int i = 0; (i) < (n); ++(i))

int main()
{
    int N;
    cin >> N;
    char s = '0';
    int ans = 0;
    repeat(i, N) {
        char ss;
        cin >> ss;
        if (s != ss) {
            s = ss;
            ans++;
        }
    }
    cout << ans << endl;
}
