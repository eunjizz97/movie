#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp = NULL; 		//영화 데이터를 읽어오기 위한 파일 포인터 
	char name[200];			//영화 제목 변수 
	char country[10]; 		//영화 제작국가 변수 
	int runTime; 			//영화 런타임 변수 
	float score; 			//영화 평점 변수 
	
	char inputCountry[10];	//사용자가 검색하려는 제작국가 
	int inputRunTime;		//사용자가 검색하려는 최저 런타임 
	float inputScore;		//사용자가 검색하려는 최저 평점  
	
	int cnt = 0;			//검색한 결과에 해당하는 영화가 몇 개 인지를 세는 변수  
	
	int exit_flag = 0; 		//while문을 계속 반복시키기 위한 변수, 반복 멈출 때 1로 바뀜 
	int option; 			//사용자가 메뉴에서 선택하는 숫자 
	void *list, *mvInfo; 	//linked list 의 맨처음 node 를 가리키는 포인터, node 내부를 가리키는 포인터 
	void *ndPtr;			//linked list의 각 node를 가리키는 포인터 
	
	
	
	//<파일 읽어오면서 linked list 만들기> 
	fp = fopen("movie.dat", "r");									//movie.dat 파일을 읽기모드로 연다. 
	

	if(fp == NULL){													//fp가 아무것도 가리키지 않으면 
		printf("[error] Failed to find a file (movie.dat)\n");		//error를 출력한다. 
	} 
	
	list = list_genList();											//linked list 첫부분을 만든다. 
	
	
	while ((fgetc(fp)) != EOF)										//파일이 끝날 때까지 반복 
	{	
		
		fscanf(fp, "%s %s %d %f", name, country, &runTime, &score);				//파일에서 영화정보를 가져온다 . 
		
		mvInfo = mv_genMvInfo(name, score, runTime, country);					//영화 정보들을 만들고 포인터로 그 정보를 가리킨다.  

		
		list_addTail(mvInfo, list);												//list 의 끝에 node를 생성한다. 
		
	}


	fclose(fp);																	//파일을 닫아준다. 
	
	
	//<프로그램 시작> 
	
	printf("Reading the data files...\n");										
	printf("Read done! %d items are read\n\n\n", list_len(list));				//총 몇개의 영화 데이터가 있는지 출력, list_len 함수를 이용하여  
	
	 
	while(exit_flag == 0) 														//exit_flag 가 0이면 반복 
	{
		//Menu 를 출력 
		printf("----------------------- Menu -----------------------\n");
		printf("1. print all the movies\n");
		printf("2. search for specific country movies\n");
		printf("3. search for specific runtime movies\n");
		printf("4. search for specific score movies\n");
		printf("5. exit\n");
		printf("----------------------------------------------------\n\n");
		
		//사용자에게 option을 입력 받는다. 
		printf("\t- select an option : ");
		scanf("%d", &option);
		
		//option에 따라 프로그램을 실행한다. 
		switch(option)
		{
			case 1: //print all the movies
				printf("printing all the movies in the list.....\n\n\n");		
				printf("------------------------ list ----------------------\n");
				
				ndPtr = list;													//ndPtr을 linked list 의 맨처음을 가리키게 한다. 
				while ( list_isEndNode(ndPtr)==0 )								//ndPtr이 가리키는 node가 마지막 node가 아니면 반복한다. 
				{
					ndPtr = list_getNextNd(ndPtr);								//ndPtr이 다음 node를 가리킴  
	
					mvInfo = list_getNdObj(ndPtr);								//mvInfo 가 node의 object 를 가리킴 
					
					mv_print(mvInfo);											//mvInfo가 가리키는 것을 함수를 통해 출력함 (node의 object들) 
					printf("----------------------------------------------------\n");
					 
				}
				printf("\n\t- totally %d movies are listed!\n\n\n", list_len(list) );
																				//총 몇개인지 list_len 함수를 통해 출력
				break;
				
			case 2: //print movies of specific country
				
				cnt = 0;														//카운트 0으로 초기화 
				
				printf("\t- select a country : ");
				scanf("%s", inputCountry);										//사용자에게 검색할 국가를 입력받음  
				printf("------------------------ list ----------------------\n");
				
				ndPtr = list;													//ndPtr을 linked list의 맨처음을 가리키게 한다. 
					while (list_isEndNode(ndPtr)==0)							//ndPtr이 가리키는 것이 마지막 node가 아니면 반복  
				{
					ndPtr = list_getNextNd(ndPtr);								//ndPtr이 다음 node를 가리키게 함  
					
					mvInfo = list_getNdObj(ndPtr);								//mvInfo 가 node의 object 를 가리킴 
					
					
					if(strncmp(inputCountry, mv_getCountry(mvInfo), strlen(inputCountry)) == 0)	//제작 국가의 문자열을 비교하여 같으면, 
					{
						mv_print(mvInfo);														//그 node의 object들을 출력  
						printf("----------------------------------------------------\n");
						cnt++;																	//총 몇개의 영화가 일치하는지를 위해 하나씩 더함  
					}
				}
				printf("\n\t - totally %d movies are listed!\n\n\n", cnt);						//총 cnt 개의 영화랑 일치함을 출력  
				
				break;
				
			case 3: //search for specific runtime movies
				
				cnt = 0;														//cnt 0으로 초기화 
				 
				printf("\t- lowest runtime : ");
				scanf("%d", &inputRunTime);										//사용자가 최소 런타임 입력  
				printf("------------------------ list ----------------------\n");
				
				ndPtr = list;													//ndPtr이 head node를 가리키게 함
				 
					while (list_isEndNode(ndPtr)==0)							//ndPtr이 마지막 node가 아니면 반복  
				{
					ndPtr = list_getNextNd(ndPtr);								//ndPtr이 다음 node를 가리키게 함  
				
					mvInfo = list_getNdObj(ndPtr);								//mvInfo가 node의 object를 가리키게 함  
					
					
					if(inputRunTime <= mv_getRunTime(mvInfo))					//사용자가 입력한 최소 런타임보다 node의 런타임이 작거나 같으면, 
					{
						mv_print(mvInfo);										//그 node의 object를 출력한다. 
						printf("----------------------------------------------------\n");
						cnt++;													//cnt를 하나 증가시킨다. 
					}
				}
				printf("\n\t - totally %d movies are listed!\n\n\n", cnt);		//총 cnt 개의 영화가 일치함을 출력  
				
				break;
				
			case 4: //search for specific score movies
				
				cnt = 0;														//cnt 0으로 초기화
				 
				printf("\t- lowest score : ");
				scanf("%f", &inputScore);										//사용자가 최소 score 입력  
				printf("------------------------ list ----------------------\n");
				
				ndPtr = list;													//ndPtr이 head node 가리킴
				 
					while (list_isEndNode(ndPtr)==0)							//ndPtr이 가리키는 node가 끝이 아니면 반복  
				{
					ndPtr = list_getNextNd(ndPtr);								//ndPtr은 다음 node를 가리킴  
					
					mvInfo = list_getNdObj(ndPtr);								//mvInfo는 node의 object를 가리킴  
					
					
					if(inputScore <= mv_getScore(mvInfo))						//사용자가 입력한 score보다 크거나 같은 score이면, 
					{
						mv_print(mvInfo);										//그 영화의 정보를 출력함  
						printf("----------------------------------------------------\n");
						cnt++;													//cnt 를 하나 증가 시킴 
					}
				}
				printf("\t - totally %d movies are listed!\n\n\n", cnt);		//총 cnt개의 영화가 일치함  
				
				break; 
				
			case 5: //exit
			
				printf("Bye!\n\n");												//bye 출력 
				exit_flag = 1;													//exit_flag = 1 이 되어 while문 반복 중지  
				break;
				
			default: //사용자가 선택한 option 이 1~5 범위 밖일 때 
				
				printf("wrong command! input again\n");		// 다시 입력하라고 출력 
				break;
		}
	}

	return 0;
}
