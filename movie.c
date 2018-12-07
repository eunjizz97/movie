#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

typedef struct movInfo{	//name, score, runTime, madeIn �� ������ ������ ����ü 'movInfo' �� ���� 
	char name[200];		//��ȭ�� �̸� 
	float score;		//��ȭ�� ���� 
	int runTime;		//��ȭ�� ��Ÿ�� 
	char madeIn[10];	//��ȭ�� ���۱��� 
} movInfo_t;			//'����ü movInfo' �� 'movInfo_t' �� ���� ������ 



//<��ȭ ������ ����� �Լ�> 
void* mv_genMvInfo(char* name, float score, int runTime, char* country)		//main �Լ����� ���� name, score, runTime, country �� �޾ƿ�  
{
	movInfo_t* mvPtr;							 							//movInfo�� �� ������ҿ� �����ϴ� ������ mvPtr�� ����  
	
	mvPtr = (movInfo_t*) malloc( sizeof (movInfo_t) );						//�����Ҵ��� ���� 
	
	if(mvPtr == NULL){
		printf("[error] mvPtr is NULL.\n");									//mvPtr �� NULL �̸� ������� �˷���  
	}
	
	
	//movInfo �� �� ������ҿ� �� �Ҵ��ϴ� �ڵ�

	strcpy(mvPtr->name, name);			//movInfo �� name�� main �Լ����� �޾ƿ� name�� �Ҵ��� 
	strcpy(mvPtr->madeIn, country);		//movInfo �� madeIn�� main �Լ����� �޾ƿ� country�� �Ҵ��� 
	mvPtr->runTime = runTime;			//movInfo �� runTime�� main �Լ����� �޾ƿ� runTime�� �Ҵ��� 
	mvPtr->score = score;				//movInfo �� score�� main �Լ����� �޾ƿ� score�� �Ҵ��� 
	
	return (void*)mvPtr;				//mvPtr �� ��ȯ�� 
}

//<��ȭ�� ������ ����ϴ� �Լ�> 
void mv_print(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;		//main �Լ����� �޾ƿ� obj �����͸� movInfo_t �������� �����Ͽ� mvPtr �����Ͱ� �̸� ����Ű�� ��
		  
	
	if (mvPtr == NULL)															//mvPtr �� NULL �̸� ������ ���  
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);						// �����͸� �̿��� movInfo�� name�� madeIn ���
								 
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);	// �����͸� �̿��� movInfo�� runTime�� score ��� 
								
	
	return;
}


//<��ȭ�� score�� ��ȯ�ϴ� �Լ� >
float mv_getScore(void* obj)
{
	return( ((movInfo_t*)obj) -> score );	
	//main �Լ����� ���� �����͸� movInfo_t �������� �ް�, ����ü movInfo �� score �� ��ȯ  
}

//<��ȭ�� run time �� ��ȯ�ϴ� �Լ� >
int mv_getRunTime(void* obj)
{
	return( ((movInfo_t*)obj) -> runTime );
	//main �Լ����� ���� �����͸� movInfo_t �������� �ް�, ����ü movInfo �� runTime ��ȯ
}

/* �ʿ� ����  
char* mv_getName(void* obj)
{

}
*/

//<��ȭ�� ���� ������ ��ȯ�ϴ� �Լ� >
char* mv_getCountry(void* obj)
{
	return( ((movInfo_t*)obj) -> madeIn );
	//main �Լ����� ���� �����͸� movInfo_t �������� �ް�, ����ü movInfo �� madeIn ��ȯ
}


