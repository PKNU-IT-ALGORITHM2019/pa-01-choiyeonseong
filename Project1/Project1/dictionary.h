#pragma once
#pragma warning (disable:4996)
#include<stdio.h>
#include<string.h>
#define NUM_VOCA 200000
#define LENGTH 1000

//함수선언
int size();
void print_found(int index);
void print_notfound(int index);
void read();
int binarySearch(struct voca data[], char target[], int begin, int end);
void find();



struct voca {					//구조체로 묶기
	char word[LENGTH];
	char speech[LENGTH];
	char mean[LENGTH];
};

struct voca list[NUM_VOCA];	//구조체 선언
int num = 0;					//단어의 수
char dict[NUM_VOCA];			//읽어들일 배열

