#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp = NULL; 		//��ȭ �����͸� �о���� ���� ���� ������ 
	char name[200];			//��ȭ ���� ���� 
	char country[10]; 		//��ȭ ���۱��� ���� 
	int runTime; 			//��ȭ ��Ÿ�� ���� 
	float score; 			//��ȭ ���� ���� 
	
	char inputCountry[10];	//����ڰ� �˻��Ϸ��� ���۱��� 
	int inputRunTime;		//����ڰ� �˻��Ϸ��� ���� ��Ÿ�� 
	float inputScore;		//����ڰ� �˻��Ϸ��� ���� ����  
	
	int cnt = 0;			//�˻��� ����� �ش��ϴ� ��ȭ�� �� �� ������ ���� ����  
	
	int exit_flag = 0; 		//while���� ��� �ݺ���Ű�� ���� ����, �ݺ� ���� �� 1�� �ٲ� 
	int option; 			//����ڰ� �޴����� �����ϴ� ���� 
	void *list, *mvInfo; 	//linked list �� ��ó�� node �� ����Ű�� ������, node ���θ� ����Ű�� ������ 
	void *ndPtr;			//linked list�� �� node�� ����Ű�� ������ 
	
	
	
	//<���� �о���鼭 linked list �����> 
	fp = fopen("movie.dat", "r");									//movie.dat ������ �б���� ����. 
	

	if(fp == NULL){													//fp�� �ƹ��͵� ����Ű�� ������ 
		printf("[error] Failed to find a file (movie.dat)\n");		//error�� ����Ѵ�. 
	} 
	
	list = list_genList();											//linked list ù�κ��� �����. 
	
	
	while ((fgetc(fp)) != EOF)										//������ ���� ������ �ݺ� 
	{	
		
		fscanf(fp, "%s %s %d %f", name, country, &runTime, &score);				//���Ͽ��� ��ȭ������ �����´� . 
		
		mvInfo = mv_genMvInfo(name, score, runTime, country);					//��ȭ �������� ����� �����ͷ� �� ������ ����Ų��.  

		
		list_addTail(mvInfo, list);												//list �� ���� node�� �����Ѵ�. 
		
	}


	fclose(fp);																	//������ �ݾ��ش�. 
	
	
	//<���α׷� ����> 
	
	printf("Reading the data files...\n");										
	printf("Read done! %d items are read\n\n\n", list_len(list));				//�� ��� ��ȭ �����Ͱ� �ִ��� ���, list_len �Լ��� �̿��Ͽ�  
	
	 
	while(exit_flag == 0) 														//exit_flag �� 0�̸� �ݺ� 
	{
		//Menu �� ��� 
		printf("----------------------- Menu -----------------------\n");
		printf("1. print all the movies\n");
		printf("2. search for specific country movies\n");
		printf("3. search for specific runtime movies\n");
		printf("4. search for specific score movies\n");
		printf("5. exit\n");
		printf("----------------------------------------------------\n\n");
		
		//����ڿ��� option�� �Է� �޴´�. 
		printf("\t- select an option : ");
		scanf("%d", &option);
		
		//option�� ���� ���α׷��� �����Ѵ�. 
		switch(option)
		{
			case 1: //print all the movies
				printf("printing all the movies in the list.....\n\n\n");		
				printf("------------------------ list ----------------------\n");
				
				ndPtr = list;													//ndPtr�� linked list �� ��ó���� ����Ű�� �Ѵ�. 
				while ( list_isEndNode(ndPtr)==0 )								//ndPtr�� ����Ű�� node�� ������ node�� �ƴϸ� �ݺ��Ѵ�. 
				{
					ndPtr = list_getNextNd(ndPtr);								//ndPtr�� ���� node�� ����Ŵ  
	
					mvInfo = list_getNdObj(ndPtr);								//mvInfo �� node�� object �� ����Ŵ 
					
					mv_print(mvInfo);											//mvInfo�� ����Ű�� ���� �Լ��� ���� ����� (node�� object��) 
					printf("----------------------------------------------------\n");
					 
				}
				printf("\n\t- totally %d movies are listed!\n\n\n", list_len(list) );
																				//�� ����� list_len �Լ��� ���� ���
				break;
				
			case 2: //print movies of specific country
				
				cnt = 0;														//ī��Ʈ 0���� �ʱ�ȭ 
				
				printf("\t- select a country : ");
				scanf("%s", inputCountry);										//����ڿ��� �˻��� ������ �Է¹���  
				printf("------------------------ list ----------------------\n");
				
				ndPtr = list;													//ndPtr�� linked list�� ��ó���� ����Ű�� �Ѵ�. 
					while (list_isEndNode(ndPtr)==0)							//ndPtr�� ����Ű�� ���� ������ node�� �ƴϸ� �ݺ�  
				{
					ndPtr = list_getNextNd(ndPtr);								//ndPtr�� ���� node�� ����Ű�� ��  
					
					mvInfo = list_getNdObj(ndPtr);								//mvInfo �� node�� object �� ����Ŵ 
					
					
					if(strncmp(inputCountry, mv_getCountry(mvInfo), strlen(inputCountry)) == 0)	//���� ������ ���ڿ��� ���Ͽ� ������, 
					{
						mv_print(mvInfo);														//�� node�� object���� ���  
						printf("----------------------------------------------------\n");
						cnt++;																	//�� ��� ��ȭ�� ��ġ�ϴ����� ���� �ϳ��� ����  
					}
				}
				printf("\n\t - totally %d movies are listed!\n\n\n", cnt);						//�� cnt ���� ��ȭ�� ��ġ���� ���  
				
				break;
				
			case 3: //search for specific runtime movies
				
				cnt = 0;														//cnt 0���� �ʱ�ȭ 
				 
				printf("\t- lowest runtime : ");
				scanf("%d", &inputRunTime);										//����ڰ� �ּ� ��Ÿ�� �Է�  
				printf("------------------------ list ----------------------\n");
				
				ndPtr = list;													//ndPtr�� head node�� ����Ű�� ��
				 
					while (list_isEndNode(ndPtr)==0)							//ndPtr�� ������ node�� �ƴϸ� �ݺ�  
				{
					ndPtr = list_getNextNd(ndPtr);								//ndPtr�� ���� node�� ����Ű�� ��  
				
					mvInfo = list_getNdObj(ndPtr);								//mvInfo�� node�� object�� ����Ű�� ��  
					
					
					if(inputRunTime <= mv_getRunTime(mvInfo))					//����ڰ� �Է��� �ּ� ��Ÿ�Ӻ��� node�� ��Ÿ���� �۰ų� ������, 
					{
						mv_print(mvInfo);										//�� node�� object�� ����Ѵ�. 
						printf("----------------------------------------------------\n");
						cnt++;													//cnt�� �ϳ� ������Ų��. 
					}
				}
				printf("\n\t - totally %d movies are listed!\n\n\n", cnt);		//�� cnt ���� ��ȭ�� ��ġ���� ���  
				
				break;
				
			case 4: //search for specific score movies
				
				cnt = 0;														//cnt 0���� �ʱ�ȭ
				 
				printf("\t- lowest score : ");
				scanf("%f", &inputScore);										//����ڰ� �ּ� score �Է�  
				printf("------------------------ list ----------------------\n");
				
				ndPtr = list;													//ndPtr�� head node ����Ŵ
				 
					while (list_isEndNode(ndPtr)==0)							//ndPtr�� ����Ű�� node�� ���� �ƴϸ� �ݺ�  
				{
					ndPtr = list_getNextNd(ndPtr);								//ndPtr�� ���� node�� ����Ŵ  
					
					mvInfo = list_getNdObj(ndPtr);								//mvInfo�� node�� object�� ����Ŵ  
					
					
					if(inputScore <= mv_getScore(mvInfo))						//����ڰ� �Է��� score���� ũ�ų� ���� score�̸�, 
					{
						mv_print(mvInfo);										//�� ��ȭ�� ������ �����  
						printf("----------------------------------------------------\n");
						cnt++;													//cnt �� �ϳ� ���� ��Ŵ 
					}
				}
				printf("\t - totally %d movies are listed!\n\n\n", cnt);		//�� cnt���� ��ȭ�� ��ġ��  
				
				break; 
				
			case 5: //exit
			
				printf("Bye!\n\n");												//bye ��� 
				exit_flag = 1;													//exit_flag = 1 �� �Ǿ� while�� �ݺ� ����  
				break;
				
			default: //����ڰ� ������ option �� 1~5 ���� ���� �� 
				
				printf("wrong command! input again\n");		// �ٽ� �Է��϶�� ��� 
				break;
		}
	}

	return 0;
}
