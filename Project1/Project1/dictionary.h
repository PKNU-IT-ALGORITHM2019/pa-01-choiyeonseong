#pragma once
#pragma warning (disable:4996)
#include<stdio.h>
#include<string.h>
#define NUM_VOCA 200000
#define LENGTH 1000

//�Լ�����
int size();
void print_found(int index);
void print_notfound(int index);
void read();
int binarySearch(struct voca data[], char target[], int begin, int end);
void find();



struct voca {					//����ü�� ����
	char word[LENGTH];
	char speech[LENGTH];
	char mean[LENGTH];
};

struct voca list[NUM_VOCA];	//����ü ����
int num = 0;					//�ܾ��� ��
char dict[NUM_VOCA];			//�о���� �迭

