#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; // コンテスト番号 001
    cin >> n;

    char dir_abcd[4] = { 'a', 'b', 'c', 'd' };
    for (int i = 0; i < 4; i++)
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
        string cmd2 = "cp ./template/template.cpp " + file_path;
        cout << cmd2 << endl;
        system(cmd2.c_str());

        // execute oj d
        char atcoder_url[256];
        sprintf(atcoder_url, "https://atcoder.jp/contests/abc%03d/tasks/abc%03d_%d", n, n, i+1);
        string test_name = ss.str() + "/test";
        string cmd3 = "oj d -d " + test_name + " " + atcoder_url;
        cout << cmd3 << endl;
        system(cmd3.c_str());
    }
}
