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

//movInfo_t movInfos[10];

void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{
	movInfo_t* mvPtr;							 		//movInfo의 각 구성요소에 접근하는 포인터 mvPtr를 만듦  
	
	mvPtr = (movInfo_t*) malloc( sizeof (movInfo_t) );	//동적할당? 
	
	if(mvPtr == NULL){
		printf("[error] mvPtr is NULL.\n");				//mvPtr 가 NULL 이면 에러라고 알려줌  
	}
	
	//allocate memory and set the member variables
	//	<<movInfo 의 각 구성요소에 값 할당하는 코드>> 

	strcpy(mvPtr->name, name);			//movInfo 의 name에 main 함수에서 받아온 name을 할당함 
	strcpy(mvPtr->madeIn, country);		//movInfo 의 madeIn에 main 함수에서 받아온 country를 할당함 
	mvPtr->runTime = runTime;			//movInfo 의 runTime에 main 함수에서 받아온 runTime을 할당함 
	mvPtr->score = score;				//movInfo 의 score에 main 함수에서 받아온 score을 할당함 
	
	return (void*)mvPtr;				//mvPtr 를 반환함 
}

void mv_print(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;	
			//main 함수에서 받아온 obj 포인터를 movInfo_t 형식으로 지정하여 mvPtr 포인터가 이를 가리키게 함  
	
	if (mvPtr == NULL)					//mvPtr 이 NULL 이면 에러를 출력  
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);	
										// 포인터를 이용해 movInfo의 name과 madeIn 출력 
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
										// 포인터를 이용해 movInfo의 runTime과 score 출력 
	
	return;
}


//return the score value from the input instance of movInfo_t structure
float mv_getScore(void* obj)
{
	return( ((movInfo_t*)obj) -> score );	
					//main 함수에서 받은 포인터를 movInfo_t 형식으로 받고, 구조체 movInfo 의 score 를 반환  
}

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)
{
	return( ((movInfo_t*)obj) -> runTime );
					//main 함수에서 받은 포인터를 movInfo_t 형식으로 받고, 구조체 movInfo 의 runTime 반환
}

//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)
{

}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)
{
	return( ((movInfo_t*)obj) -> madeIn );
					//main 함수에서 받은 포인터를 movInfo_t 형식으로 받고, 구조체 movInfo 의 madeIn 반환
}


