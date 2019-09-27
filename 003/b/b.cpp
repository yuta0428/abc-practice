#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S, T;
    cin >> S;
    cin >> T;
    const string atcoder = "atcoder";
    bool is_same = true;
    for (int i = 0; i < S.size(); i++) {
        char s = S[i];
        char t = T[i];
        if (s == t) continue;
        if (s == '@' && atcoder.find(t) != std::string::npos) continue;
        if (t == '@' && atcoder.find(s) != std::string::npos) continue;
        is_same = false;
        break;
    }
    if (is_same) cout << "You can win" << endl;
    else cout << "You will lose" << endl;
}
