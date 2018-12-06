/*
 ============================================================================
 Name        : 100_chicken.c
 Author      : wovert
 Version     : 1.0.0
 Copyright   : copyright@wovert.com
 Description : 百钱百鸡问题
 ============================================================================
 */

#include <stdio.h>

void algrithm1() {
	// 这个是最笨的方法，根据cock、hen、chick可能的组合全部遍历，看哪些符合方程条件，运算步骤上万步。

	int cock, hen, chick, count;						// 定义变量公鸡，母鸡，小鸡
	for(cock=0; cock<=20; cock++) { // 公鸡可能的数量遍历 
		for(hen=0; hen<34; hen++) {		// 母鸡可能的数量遍历 
			for(chick=0; chick<100; chick=chick+3) { // 小鸡可能的数量遍历 
				if((cock+hen+chick==100) && (cock*5+hen*3+chick/3==100)) { // 符合题2要求后输出 
					printf("cock=%2d, hen=%2d, chick=%2d\n", cock, hen, chick);
				}
			}
		}
	}
	printf("algrithm1 loop %d\n\n", count); 
}

void algrithm2() {

	// 算法二:我们可以通过Y=100-X-Y这条已知条件，减去一个循环，使算法复杂法降为N的平方，运算步骤减至几百步。
	int cock,hen,chick,count=0; //定义变量公鸡，母鸡，小鸡
	for(cock=0;cock<=20;cock++) {//公鸡可能的数量遍历 
		for(chick=0;chick<=100-cock;chick=chick+3) //小鸡数是3的倍数且不可能大于100-公鸡数 
		{
			hen=100-cock-chick;//母鸡数是100-公鸡-小鸡数 
			count++;
			if(cock*5+hen*3+chick/3==100) { //符合题2要求后输出 
				printf("cock=%2d, hen=%2d, chicken=%2d\n", cock, hen, chick);
			}
		}	
	}
	printf("algrithm2 loop %d\n\n", count); 	
}

void algrithm3() {
	// 设法一个循环解决问题，通过5cock+3hen+chick/3=100得出15cock+9hen+chick=300,再因chick=100-cock-hen,得出15cock+9hen+(100-cock-hen)=300,进而得出14cock+8hen=200再得出7cock+4hen=100(x和y都是整数）。通过先用数学方法的简化，运算步骤减至几十步。

	int cock,hen,chick;//定义变量公鸡，母鸡，小鸡
	int count = 0;
	for(cock=0;cock<15;cock++) { //根据7cock+4hen=100,得出cock小于15 
		count++;
		if((100-cock*7)%4==0) { //此条表示7cock+4hen成立且cock和hen都是整数，符合条件
			hen=(100-cock*7)/4;
			chick=100-cock-hen;
			printf("cock=%2d, hen=%2d, chicken=%2d\n", cock, hen, chick);
		}
	}
	printf("algrithm3 loop %d\n\n", count); 	
}

int main(void) {
	
	// cock + hen + chick = 100
	// 5*cock + 3*hen + chick/3 = 100

	algrithm1();

	algrithm2();

	algrithm3();


	return 0;
}

