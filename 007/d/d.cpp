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
    int A, B;
    cin >> A >> B;
    int ans = 0;
    std::regex re("^4|^9");
    std::smatch m;
    foreach(i,A, B){
        string s = to_string(i);
        if (regex_search(s, m, re)) {
            cout << s << ", ";
            ans++;
        }
    }
    cout << endl;
    cout << ans << endl;
    return 0;
}

/*
一桁目が4or9なのは2*(B/10...四捨五入)個
40,90,340,390など40,90連番台は2*(B/10...四捨五入)個
法則性がありそうだけどムズい、、
*/
