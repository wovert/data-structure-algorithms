#include <stdio.h>

int main() {
  int i, j, k, temp; // i:前两位车牌数字，j:后两位车牌数字，k: 车牌号

  for(i=0; i<=9; i++) {
    for(j=0; j<=9; j++) { // 穷举前两位和后两位
      if (i != j) {
        
        // 组成4位车牌号 k
        k = 1000*i + 100*i + 10*j + j;
        
        // 判断 k 是否某个数的平方，若是则输出 k
        for(temp=31; temp<=99; temp++) {
          if ((temp * temp) == k) {
            printf("Car Number is %d. number is %d\n", k, temp);
          }
        }
      }
    }
  }
}