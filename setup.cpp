#include <bits/stdc++.h>
using namespace std;

int main()
{
    char cmd[1024];
    int n; // コンテスト番号 001
    scanf("%d", &n);
    char dir[32];
    sprintf(dir, "./%03d", n);

    sprintf(cmd, "test -d %s\n", dir);
    int status = system(cmd);
    if (status!=0){
        // create
        sprintf(cmd, "cp -r ./template %s\n", dir);
        printf(cmd);
        system(cmd);
    }

    // DL test
    char c[4] = {'a','b','c','d'};
    for (int i=0; i<4; i++){
        sprintf(cmd, "oj d -d %s/%c/test https://atcoder.jp/contests/abc%03d/tasks/abc%03d_%d\n",dir,c[i],n,n,i+1);
        printf(cmd);

        system(cmd);
    }
}
