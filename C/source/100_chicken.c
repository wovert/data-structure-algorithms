/*
 ============================================================================
 Name        : 100_chicken.c
 Author      : wovert
 Version     : 1.0.0
 Copyright   : copyright@wovert.com
 Description : ��Ǯ�ټ�����
 ============================================================================
 */

#include <stdio.h>

void algrithm1() {
	// �������ķ���������cock��hen��chick���ܵ����ȫ������������Щ���Ϸ������������㲽�����򲽡�

	int cock, hen, chick, count;						// �������������ĸ����С��
	for(cock=0; cock<=20; cock++) { // �������ܵ��������� 
		for(hen=0; hen<34; hen++) {		// ĸ�����ܵ��������� 
			for(chick=0; chick<100; chick=chick+3) { // С�����ܵ��������� 
				if((cock+hen+chick==100) && (cock*5+hen*3+chick/3==100)) { // ������2Ҫ������ 
					printf("cock=%2d, hen=%2d, chick=%2d\n", cock, hen, chick);
				}
			}
		}
	}
	printf("algrithm1 loop %d\n\n", count); 
}

void algrithm2() {

	// �㷨��:���ǿ���ͨ��Y=100-X-Y������֪��������ȥһ��ѭ����ʹ�㷨���ӷ���ΪN��ƽ�������㲽��������ٲ���
	int cock,hen,chick,count=0; //�������������ĸ����С��
	for(cock=0;cock<=20;cock++) {//�������ܵ��������� 
		for(chick=0;chick<=100-cock;chick=chick+3) //С������3�ı����Ҳ����ܴ���100-������ 
		{
			hen=100-cock-chick;//ĸ������100-����-С���� 
			count++;
			if(cock*5+hen*3+chick/3==100) { //������2Ҫ������ 
				printf("cock=%2d, hen=%2d, chicken=%2d\n", cock, hen, chick);
			}
		}	
	}
	printf("algrithm2 loop %d\n\n", count); 	
}

void algrithm3() {
	// �跨һ��ѭ��������⣬ͨ��5cock+3hen+chick/3=100�ó�15cock+9hen+chick=300,����chick=100-cock-hen,�ó�15cock+9hen+(100-cock-hen)=300,�����ó�14cock+8hen=200�ٵó�7cock+4hen=100(x��y������������ͨ��������ѧ�����ļ򻯣����㲽�������ʮ����

	int cock,hen,chick;//�������������ĸ����С��
	int count = 0;
	for(cock=0;cock<15;cock++) { //����7cock+4hen=100,�ó�cockС��15 
		count++;
		if((100-cock*7)%4==0) { //������ʾ7cock+4hen������cock��hen������������������
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

