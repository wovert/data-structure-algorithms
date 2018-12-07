#include <stdio.h>

void algrithm1() {
  int a,b,c,i=0; // a,b,c分别用来记录三个人所选新书编号，i用来控制有效节约次数

  int count = 0; // 循环次数
  printf("A,B,C 三人所选书号分别为：\n");

  for(a=1; a<=5; a++) { // 控制A借阅图书编号
    for(b=1; b<=5; b++) { // 控制B借阅图书编号
      for(c=1; c<=5; c++) { // 控制C借阅图书编号
        count++;
        if(a!=b && a!=c && b!=c) { // 控制有效借阅组合
          printf("A:%2d, B:%2d, C:%2d\n", a, b, c);
          i++;
          if(i%4 == 0) printf("\n");
          printf("Total: %d\n", i); // 有效借阅总数
        }
      }
    }
  }
  printf("Loop Total: %d\n", count); // 有效借阅总数
}

void algrithm2() {
  int a,b,c,i=0; // a,b,c分别用来记录三个人所选新书编号，i用来控制有效节约次数

  int count = 0; // 循环次数
  printf("A,B,C 三人所选书号分别为：\n");

  for(a=1; a<=5; a++) { // 控制A借阅图书编号
    for(b=1; b<=5; b++) { // 控制B借阅图书编号
      if(a==b) continue;
      for(c=1; c<=5; c++) { // 控制C借阅图书编号
        count++;
        if( a==c || b==c) continue;
        
        // 控制有效借阅组合
        printf("A:%2d, B:%2d, C:%2d\n", a, b, c);
        i++;
        if(i%4 == 0) printf("\n");
        printf("Total: %d\n", i); // 有效借阅总数
        
      }
    }
  }
  printf("Loop Total: %d\n", count); // 有效借阅总数
}

int main() {
  algrithm1();
  algrithm2();

  return 0;
}