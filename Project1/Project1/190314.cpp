#include "dictionary.h"
	
int size() {	//배열의 크기, 단어의 개수 출력
	return sizeof(list);
}



void read() {	//사전 배열에 저장
	int i = 0;	//dict 배열
	int j = 0;	//글자수
	char fileName[LENGTH];

	scanf("%s", fileName);
	
	FILE *in_fp = fopen(fileName, "r");


	while (fscanf(in_fp, "%s", dict)!=EOF) 
	{
		if (i == 0||dict[i] == '\\'&&dict[i + 1] == '\\'){
			j=0;
			i++; i++;
			while (dict[i] != '(')	//단어
			{
				list[num].word[j] = dict[i];
				i++; j++;
			}
		}
		else if (dict[i] == '(') {	//품사
			j = 0;
			i++;
			while (dict[i] != ')') {
				list[num].speech[j] = dict[i];
				j++; i++;
			}
		}
		else if (dict[i] == ')'){	//뜻
			j = 0;
			i++;
			while (dict[i] != '\\') {
				list[num].mean[j] = dict[i];
				j++; i++;
			}
		}
		num++;
	}
	fclose(in_fp);
}

void print_found(int index) {

	printf("%s %s %s", &list[index].word, &list[index].speech, &list[index].mean);

}

void print_notfound(int index) {
	printf("not found\n");
	if (index + 1 != 0) {
		printf("%s %s\n", &list[index].word, &list[index].speech);
	}
	printf("- - -\n");
	printf("%s %s", &list[index + 1].word, &list[index + 1].speech);
}

int binarySearch(struct voca data[], char target[], int begin, int end) {	//검색

	int middle = (begin + end) / 2;

	if (begin > end) {	//끝
		return middle-1;
	}

	else {
		if (strcmp(data[middle].word, target) == 0)		//찾음
		{
			return middle;
			print_found(middle);
		}
		else if (strcmp(data[middle].word,target)>0)
			return binarySearch(data, target, begin, middle - 1);
		else return binarySearch(data, target, middle + 1, end);
	}
}


void find() {

	int item = 0;
	int found[LENGTH]={0};
	int a = 0;
	int length = size(); 

	char buf[LENGTH];
	scanf("%s", buf);

	while (found[item] > length) {
		found[item++] = binarySearch(list, buf, found[item], length);

	}

	if (item > 0) {
		printf("found %d items", &item);
		while (a<item)
			print_found(found[a]);
	}
	else print_notfound(found[item]);

}



	int main(void) {

		char command[LENGTH];

		while (1) {
			printf("$ ");
			scanf("%s", command);

			if (strcmp(command, "read") == 0)
			{
				read();
			}
			else if (strcmp(command, "size") == 0)
			{
				int i = size();
				printf("%d\n",&i);
			}
			else if (strcmp(command, "find")==0)
			{
				find();
			}
			else if (strcmp(command, "exit")==0)
				break;

		}
	}
