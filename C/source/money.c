#include <stdio.h>

int main() {
  int i;
  double money = 0.0;
  for(i=0; i<5; i++) {
    money = (money+1000.0)/(1+0.0063*12);
  }
  printf("Save money is:%0.2f\n", money);
  return 0;
}