//<��ȭ ���� ����� �Լ�>
void* mv_genMvInfo(char* name, float score, int runTime, char* country); //��ȭ ������ ����� �Լ�

//<��ȭ ���� ��� �Լ�>
void mv_print(void* obj); //��ȭ�� ������ ����ϴ� �Լ�

//<������� ���ð� ���ϱ� ���� ���̴� �Լ�> 
float mv_getScore(void* obj); //��ȭ�� score�� ��ȯ�ϴ� �Լ�
int mv_getRunTime(void* obj); //��ȭ�� run time �� ��ȯ�ϴ� �Լ�
//char* mv_getName(void* obj);
char* mv_getCountry(void* obj); //ȭ�� ���� ������ ��ȯ�ϴ� �Լ�
