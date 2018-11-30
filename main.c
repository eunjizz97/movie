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
	
	char inputContry[10];	//사용자가 검색하려는 제작국가 
	int inputRunTime;		//사용자가 검색하려는 최저 런타임 
	float inputScore;		//사용자가 검색하려는 최저 평점  
	
	int cnt = 0;				//검색한 결과에 해당하는 영화가 몇 개 인지를 세는 변수  
	
	int exit_flag = 0; 		//flag variable for while loop
	int option; 			//사용자가 메뉴에서 선택하는 숫자 
	void *list, *mvInfo; 	//pointers for linked list and a specific structure instance for a movie data
	void *ndPtr;			//void pointer for linked list node
	
	
	//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	fp = fopen("movie.dat", "r");	//파일을 읽기모드로 연다. 
	
	if(fp == NULL){
		printf("[error] Failed to find a file (movie.dat)\n")
	} 
	
	//1.2 list generation (use function list_genList() )
	list = list_genList();							//영화 리스트를 만든다. 
	
	//1.3 read each movie data from the file and add it to the linked list
	while ((fgetc(fp)) != EOF /* read name, country, runtime and score*/ )		//파일이 끝날 때까지 반복 
	{	
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
		fscanf(fp, "%s %s %d %f", name, country, &runTime, &score);				//파일에서 영화정보를 입력받는다  
		
		mvInfo = mv_genMvInfo(name, score, runTime, country);							//영화 정보들을 만든다 
//		printf("%s %s %d %f\n", name, country, runTime, score); // ***시험용 
//		mv_print(mvInfo);
		
		list_addTail(mvInfo, list);			//*******list 의 끝에 node를 추가한다. 
		
	}

	//1.4 FILE close
	fclose(fp);				//파일을 닫아준다. 
	
	
	//2. program start
	while(exit_flag == 0) 
	{
		//2.1 print menu message and get input option
		printf("------------------------- Menu -------------------------\n");
		printf("1. print all the movies\n");
		printf("2. search for specific country movies\n");
		printf("3. search for specific runtime movies\n");
		printf("4. search for specific score movies\n");
		printf("5. exit\n");
		printf("--------------------------------------------------------\n\n");
		
		printf("-- select an option : ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1: //print all the movies
				printf("printing all the movies in the list.....\n\n\n");
				
				ndPtr = list;
				while (list_isEndNode(ndPtr)==0 /* repeat until the ndPtr points to the end node */)
//				for(i=0;i<10;i++)
				{
					//2.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = list_getNextNd(ndPtr);
					//get object of ndPtr to mvInfo void pointer
					mvInfo = list_getNdObj(ndPtr);
					//print the contents of the mvInfo
					mv_print(mvInfo);
					printf("----------------------------------------------------\n");
					 
				}
				printf("\t- totally %d movies are listed!\n\n", list_len(list) );
																//총 몇개인지 list_len 함수를 통해 출력
				break;
				
			case 2: //print movies of specific country
				//2.3.1 get country name to search for
				cnt = 0;	//카운트 0으로 초기화 
				printf("select a country : ");
				scanf("%s", inputCountry);
				
				ndPtr = list;
					while (list_isEndNode(ndPtr)==0 /* repeat until the ndPtr points to the end node */)
				{
					//2.3.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = list_getNextNd(ndPtr);
					//get object of ndPtr to mvInfo void pointer
					mvInfo = list_getNdObj(ndPtr);
					//if the input country matches to the country of the movie,
					if(inputCountry == mv_getCountry(mvInfo))
					{
					//then print the contents of the mvInfo
						mv_print(mvInfo);
						printf("----------------------------------------------------\n");
						cnt++;
					}
				}
				printf("\t - totally %d movies are listed!\n\n", cnt);
				
				break;
				
			case 3:
				//2.4.1 get minimal runtime value to search for
				cnt = 0;	//cnt 0으로 초기화  
				printf("lowest runtime : ");
				scanf("%d", inputRunTime);
				
				ndPtr = list;
					while (list_isEndNode(ndPtr)==0 /* repeat until the ndPtr points to the end node */)
				{
					//2.4.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = list_getNextNd(ndPtr);
					//get object of ndPtr to mvInfo void pointer
					mvInfo = list_getNdObj(ndPtr);
					//if the input runtime is lower than the runtime of the movie,
					if(inputRunTime <= mv_getRunTime(mvInfo))
					{
					//then print the contents of the mvInfo
						mv_print(mvInfo);
						printf("----------------------------------------------------\n");
						cnt++;
					}
				}
				printf("\t - totally %d movies are listed!\n\n", cnt);
				
				break;
				
			case 4:
				//2.5.1 get minimal score value to search for
				printf("lowest score : ");
				scanf("%f", inputScore);
				cnt = 0;
				
				ndPtr = list;
					while (list_isEndNode(ndPtr)==0 /* repeat until the ndPtr points to the end node */)
				{
					//2.5.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = list_getNextNd(ndPtr);
					//get object of ndPtr to mvInfo void pointer
					mvInfo = list_getNdObj(ndPtr);
					//if the input score is lower than the score of the movie,
					if(inputScore <= mv_getScore(mvInfo))
					{
					//then print the contents of the mvInfo
						mv_print(mvInfo);
						printf("----------------------------------------------------\n");
						cnt++;
					}
				}
				printf("\t - totally %d movies are listed!\n\n", cnt);
				
				break; 
				
			case 5:
				printf("Bye!\n\n");
				exit_flag = 1;
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
	}

	return 0;
}
