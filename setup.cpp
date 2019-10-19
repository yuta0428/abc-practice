#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; // コンテスト番号 001
    cin >> n;

    string dir_abcd = n < 126 ? "abcd" : "abcd";
    for (int i = 0; i < dir_abcd.length(); i++)
    {
        const char dir = dir_abcd[i];
        ostringstream ss;

        // make directories
        ss << "./";
        ss << std::setw(3) << std::setfill('0') << n << "/";
        ss << dir;
        string cmd1 = "mkdir -p " + ss.str();
        cout << cmd1 << endl;
        system(cmd1.c_str());

        // copy template.cpp
        string file_path = ss.str() + "/" + dir + ".cpp";
        string cmd2 = "cp -n ./template/template.cpp " + file_path;
        cout << cmd2 << endl;
        system(cmd2.c_str());

        // execute oj d
        char atcoder_url[256];
        if (n < 20)
            sprintf(atcoder_url, "https://atcoder.jp/contests/abc%03d/tasks/abc%03d_%d", n, n, i+1);
        else
            sprintf(atcoder_url, "https://atcoder.jp/contests/abc%03d/tasks/abc%03d_%c", n, n, dir);
        string test_path = ss.str() + "/test";
        string cmd3 = "oj d -d " + test_path + " " + atcoder_url;
        cout << cmd3 << endl;
        system(cmd3.c_str());
    }
}
