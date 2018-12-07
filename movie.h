//<영화 정보 만드는 함수>
void* mv_genMvInfo(char* name, float score, int runTime, char* country); //영화 정보를 만드는 함수

//<영화 정보 출력 함수>
void mv_print(void* obj); //영화의 정보를 출력하는 함수

//<사용자의 선택과 비교하기 위해 쓰이는 함수> 
float mv_getScore(void* obj); //영화의 score를 반환하는 함수
int mv_getRunTime(void* obj); //영화의 run time 을 반환하는 함수
//char* mv_getName(void* obj);
char* mv_getCountry(void* obj); //화의 제작 국가를 반환하는 함수
