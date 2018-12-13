#include <stdio.h>

int main () {
  long fib1=1, fib2=1, fib;
  int i;
  printf("%12ld%12ld", fib1, fib2); // 输出每一个月和第二个月的兔子数
  for (i=3; i<=30; i++) {
    fib = fib1 + fib2;    // 迭代求出当前月份的兔子数
    printf("%12d", fib);  // 输出当前月份兔子数
    if (i%4 == 0) {
      printf("\n");        // 每行输出 4个
    }
    fib2 = fib1;          // 为下一次迭代作准备，求出新的 fib2
    fib1 = fib;           // 求出新的 fib1
  }
}