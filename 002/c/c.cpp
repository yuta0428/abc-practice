#include <bits/stdc++.h>
using namespace std;

int main()
{
    int xa,ya,xb,yb,xc,yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    float r = abs((xb - xa) * (yc - ya) - (yb - ya) * (xc - xa)) / 2.0f;
    printf("%.1f\n", r);
}

/*
float出力はprintfでやらないと桁がうまく表示されないよう
*/
