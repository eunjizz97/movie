#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

typedef struct movInfo{	//name, score, runTime, madeIn 의 정보를 가지는 구조체 'movInfo' 를 만듦 
	char name[200];		//영화의 이름 
	float score;		//영화의 평점 
	int runTime;		//영화의 런타임 
	char madeIn[10];	//영화의 제작국가 
} movInfo_t;			//구조체 'movInfo' 를 'movInfo_t' 를 통해 정의함 


void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{
	movInfo_t* mvPtr;
	int i;
//	mvPtr = movInfo;			//mvPtr 는 movInfo 구조체를 가리킴 
	
	//allocate memory and set the member variables
	for(i=0;i<200;i++){
	(mvPtr->name[i]) = name[i];		//movInfo 의 name에 main 함수에서 받아온 name을 할당함 
	}
	for(i=0;i<10;i++){
	(mvPtr->madeIn[i]) = country[i];	//movInfo 의 madeIn에 main 함수에서 받아온 country를 할당함 
	}
	(mvPtr->runTime) = runTime;	//movInfo 의 runTime에 main 함수에서 받아온 runTime을 할당함 
	(mvPtr->score) = score;		//movInfo 의 score에 main 함수에서 받아온 score을 할당함 
	
	return (void*)mvPtr;		//mvPtr 를 반환함 
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


