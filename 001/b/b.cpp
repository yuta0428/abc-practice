#include <bits/stdc++.h>
using namespace std;

int main() {
  int m;
  scanf("%d", &m);
  if (m < 100) {
    printf("00\n");
  } else if (m <= 5000) {
    printf("%02d\n", m / 100);
  } else if (m <= 30000) {
    printf("%d\n", m / 1000 + 50);
  } else if (m <= 70000) {
    printf("%d\n", (m / 1000 - 30) / 5 + 80);
  } else {
    printf("89\n");
  }
}

/*
計算結果だけ変数に詰めて、最後に
printf("%02d",o);とやるほうが賢かったかも
*/
