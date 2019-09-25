#include <bits/stdc++.h>
using namespace std;

int main()
{
    int deg, dis, W;
    string dir;
    scanf("%d %d", &deg, &dis);
    if (deg <= 112) dir = "N";
    else if (deg <= 337) dir = "NNE";
    else if (deg <= 562) dir = "NE";
    else if (deg <= 787) dir = "ENE";
    else if (deg <= 1012) dir = "E";
    else if (deg <= 1237) dir = "ESE";
    else if (deg <= 1462) dir = "SE";
    else if (deg <= 1687) dir = "SSE";
    else if (deg <= 1912) dir = "S";
    else if (deg <= 2137) dir = "SSW";
    else if (deg <= 2362) dir = "SW";
    else if (deg <= 2587) dir = "WSW";
    else if (deg <= 2812) dir = "W";
    else if (deg <= 3037) dir = "WNW";
    else if (deg <= 3262) dir = "NW";
    else if (deg <= 3487) dir = "NNW";
    else dir = "N";

    int d = (int)(dis / 60.0f * 10 + 0.5f);
    if (d <= 2) W = 0;
    else if(d <= 15) W = 1;
    else if (d <= 33) W = 2;
    else if (d <= 54) W = 3;
    else if (d <= 79) W = 4;
    else if (d <= 107) W = 5;
    else if (d <= 138) W = 6;
    else if (d <= 171) W = 7;
    else if (d <= 207) W = 8;
    else if (d <= 244) W = 9;
    else if (d <= 284) W = 10;
    else if (d <= 326) W = 11;
    else W = 12;

    if (W == 0) dir = "C";
    printf("%s %d\n", dir.c_str(), W);
}


/*
方角、角度を配列にしてfor文でやってるのもあった
あと大体floatで受け付けてちゃんと計算させてた
*/
