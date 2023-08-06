#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char letter[10][5]={{}, {}, {"abc"}, {"def"}, {"ghi"}, {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};
char** re;
char* dist;
int index = 0;
void rsum(int size, char* tempstr){
	int i, j;
	
	if(dist[size] == '\0'){
		re[index] = (char*)malloc(sizeof(char)*3);
		strcpy(re[index], tempstr);
		index++;
	}
	else{
		for(i=0; i<strlen(letter[dist[size]-'0']); i++){
			tempstr[size] = letter[dist[size]-'0'][i];
			rsum(size+1, tempstr);
		}	
	}

} 
char ** letterCombinations(char * digits, int* returnSize){
	dist = digits;

	if(strlen(digits)!= 0){
		*returnSize = 1;
		int i,j;
		for(i=0; i<strlen(digits); i++){
			*returnSize = *returnSize * strlen(letter[digits[i]-'0']);
		}
	}
	else{
		*returnSize = 0;
	}
	
	re = (char**)malloc(sizeof(char*)*(*returnSize));
	char tempstr[5] = {0};
	if(*returnSize > 0){
		rsum(0 ,tempstr);
	}
	
	return re;

}
int main(void){
	char* s;
	char temp[80] = "";
	printf("請輸入一組數字 : ");
	scanf("%s",temp);
	s = temp;	
	int i,j;
	int returnSize;
	
	char** answer =  letterCombinations(s,&returnSize);
	for(i=0; i<returnSize; i++){
		printf("%s  ",answer[i]);	
	}
	
	free(re);
	
}

