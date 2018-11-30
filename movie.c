#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

typedef struct movInfo{	//name, score, runTime, madeIn �� ������ ������ ����ü 'movInfo' �� ���� 
	char name[200];		//��ȭ�� �̸� 
	float score;		//��ȭ�� ���� 
	int runTime;		//��ȭ�� ��Ÿ�� 
	char madeIn[10];	//��ȭ�� ���۱��� 
} movInfo_t;			//����ü 'movInfo' �� 'movInfo_t' �� ���� ������ 

//movInfo_t movInfos[10];

void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{
	movInfo_t* mvPtr;
	
	mvPtr = (movInfo_t*) malloc( sizeof (movInfo_t) );
	
	if(mvPtr == NULL){
		printf("[error]\n");
	}
	
	//allocate memory and set the member variables

	strcpy(mvPtr->name, name);		//movInfo �� name�� main �Լ����� �޾ƿ� name�� �Ҵ��� 
	strcpy(mvPtr->madeIn, country);	//movInfo �� madeIn�� main �Լ����� �޾ƿ� country�� �Ҵ��� 
	mvPtr->runTime = runTime;	//movInfo �� runTime�� main �Լ����� �޾ƿ� runTime�� �Ҵ��� 
	mvPtr->score = score;		//movInfo �� score�� main �Լ����� �޾ƿ� score�� �Ҵ��� 
	
	return (void*)mvPtr;		//mvPtr �� ��ȯ�� 
}

void mv_print(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	
	return;
}


//return the score value from the input instance of movInfo_t structure
float mv_getScore(void* obj)
{
	
}

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)
{
	
}

//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)
{
	
}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)
{
	
}


