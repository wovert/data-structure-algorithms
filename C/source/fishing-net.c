#include <stdio.h>

// 定义日期结构体
typedef struct date {
  int year;
  int month;
  int day;
} DATE;

int countDay(DATE); // 函数声明
int runYear(int);   // 函数声明

int main() {
  DATE today;     // 指定日期
  int totalDay;   // 指定日期距离 1990-1-1 的天数
  int result;     // totalDay 对取余的结果
  printf("Please input Year Month Day example: 1990 1 31\n");
  scanf("%d%d%d", &today.year, &today.month, &today.day);

  totalDay = countDay(today); // 求出指定日期距离1990-1-1 的天数

  printf("Remain days: %d\n", totalDay);

  result = totalDay%5;        // 天数%5， 判断输出打鱼还是晒网
  if (result > 0 && result < 4) {
    printf("Today fishing\n");
  } else {
    printf("Shine net\n");
  }
  return 0;
}

/**
 * s判断是否为闰年，是返回1，否则返回0
 */
int runYear(int year) {
  if (((year%4 == 0) && (year%100 !=0)) || (year%400 == 0)) {
    return 1;
  } else {
    return 0;
  }
}

int countDay(DATE currentDay) {
  int perMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; // 每月天数数组
  int totalDay = 0, year, i;

  // 求出指定日期之前的每一年的天数累加和
  for(year=1990; year<currentDay.year; year++) {
    if(runYear(year)) {   // 判断是否为闰年
      totalDay = totalDay + 366;
    } else {
      totalDay = totalDay + 365;
    }
  }

  printf("Total days: %d\n", totalDay);

  if(runYear(currentDay.year)) {  // 如果为闰年，则二月份为 29 天
    perMonth[2] += 1;
  }

  // 将本年内的天数累加到 totalDay 中
  for(i=0; i<currentDay.month; i++) {
    totalDay += perMonth[i];
  }

  totalDay += currentDay.day; // j将笨鱼的天数累加到 totalDay 中

  return totalDay;
}