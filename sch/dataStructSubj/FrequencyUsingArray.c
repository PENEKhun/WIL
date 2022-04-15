/*

순천향대학교 정보보호학과
20194581 문성훈
penekhun@gmail.com

함수의 모듈화와 포인터를 공부하고 이해한
예제를 보여드리기 위해 작성된 코드입니다

*/

#include <stdio.h>
#define HOW_MANY_INPUT 20 //숫자 몇개 받을지에 대한 명시
#define MAX_NUMBER_VALUE 9 //입력 받을 숫자의 최대치를 명시

void println();
int *getArrayReference(int *array, int idx);
void incArrayValue(int *array, int idx);
int compareArrayValue(int *array, int a, int b);

int main(void)
{
   int real_frequency[HOW_MANY_INPUT+1] = {0}; //입력받은 숫자의 빈도수를 저장할 배열
   int *frequency = &real_frequency; //진짜 빈도수 변수를 가르켜줌


   int inputNum = 0; //입력받는 정수들
   int maxInputArr = 0; //빈도수가 많은 숫자를 담아둘 변수
   int i=0, n=1;

   while (n != HOW_MANY_INPUT + 1){
      printf("%d번째 정수 : ", n);
      scanf("%d", &inputNum);
      if (inputNum < 1 || inputNum > MAX_NUMBER_VALUE)
        printf("입력 오류 : 1이상 %d이하의 정수만 입력하시오\n", MAX_NUMBER_VALUE);
      else {
         incArrayValue(frequency, inputNum); //입력받은 숫자의 빈도수를 1만큼 올림
         n++;
      }
   }

   for (i = 1;i < HOW_MANY_INPUT;i++)
   {
         maxInputArr = compareArrayValue(frequency, maxInputArr, i);
   }
   
  println();
  printf("제일 많이 입력된 정수는 %d 이고", maxInputArr);
  println();
  printf("빈도수는 %d번입니다.", getArrayReference(frequency, maxInputArr));
  println();

   return 0;
}

int *getArrayReference(int* array, int idx){
    //배열의 idx값을 리턴해주는 함수
    return *(array + idx);
}

void println(){
    //개행을 프린트하는 프로시저
    printf("\n");
}

void incArrayValue(int *array, int idx){
    //배열의 idx값을 inc해주는 프로시저
    *(array + idx) += 1;
}


int compareArrayValue(int *array, int a, int b){
    //배열의 value를 compare하고, 큰 value의 idx 리턴해줌
    return
        (getArrayReference(array, a) < getArrayReference(array, b)) ? b : a;
}