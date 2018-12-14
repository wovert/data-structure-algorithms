#include <stdio.h>
#include <math.h>



int main() {

  float solution(float a, float b, float c, float d); // 牛顿迭代法求方程根

  float a, b, c, d, x;    // a,b,c,d 代表所求方程的系数，x 用来记录求得的方程根
  printf("Please input fangcheng xishu:");
  scanf("%f %f %f %f, &a, &b, &c, &d");
  x = solution(a, b, c ,d);
  printf("所求方程的根为 x=%f", x);

  return 0;
}

float solution(float a, float b, float c, float d) {
  // 用来描述方程的值，fd 用来描述方程求导之后的值
  float x0, x=1.5, f, fd, h;

  do {
    x0 = x; // 用所求的X的值代替 x0 原来的值
    f = a * x0 * x0 * x0 + b * x0 * x0 + c * x0 + d;
    fd = 3 * a * x0 * x0 + 2 * b * x0 + c;
    h = f/fd;
    x = x0-h;  // 求得更接近方程根的x 的值
  } while(fabs(x-x0) >= 1e-5);

  return x;
}