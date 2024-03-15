// Enter your student ID and Fullname
//22300745 차상은
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct st_class{
	int code;		// class code
	char name[30]; 	// class name
	int unit;		// credites    
	int grading;	// grading (1:A+~F, 2:P/F)
};

char kname[2][10] = {"A+~F", "P/F"}; // String for grading

// Functions provided
int loadData(struct st_class* c[]); // Load all class list from data file.
void printAllClasses(struct st_class* c[], int csize); // Print all class list
void saveAllClasses(struct st_class* c[], int csize); // Save all class list

// Functions for modifying
int addNewClass(struct st_class* c[], int csize); // Add a class into the list
void editClass(struct st_class* c[], int csize); // Modify a class in the list
void findClasses(char* name, struct st_class* c[], int csize); // Search a class by name from the list

// Functions for making
int applyMyClasses(int my[], int msize, struct st_class* c[], int csize); // Apply a class
void printMyClasses(int my[], int msize, struct st_class* c[], int csize); // Print my classes
void saveMyClass(int my[], int msize, struct st_class* c[], int csize); // Save my classes



int main(void) {
	int no;	// menu number 
	struct st_class* classes[50]; // Class list (max. 50 classes)

	int myclass[10]; // My classes (max. 10 classes of code)
	int mycount = 0; // Amount of my classes

	srand(time(0));
	int count = loadData(classes);
	printf("> Load %d classes.\n", count);

	while(1){
		printf("\n> Menu 1.List 2.Add 3.Modify 4.Search 5.Apply 6.My classes 7.Save 0.Quit\n");
		printf(">> Menu? > ");
		scanf("%d", &no);

		if(no == 1){ 
			printf("> 1.Class list (%d classes)\n", count);
			printAllClasses(classes, count);
		}
		else if(no == 2){ 
			printf("> 2.Add a Class\n");
			count = addNewClass(classes, count);    //class list의 정보 넘겨줌
		}
		else if(no == 3){ 
			printf("> 3.Modify a Class\n");
			editClass(classes, count);
		}
		else if(no == 4){
			printf("> 4.Search a Class\n");
			printf(">> Enter class name > ");
			char name[30];
			scanf("%s", name);
			findClasses(name, classes, count);
		}
		else if(no == 5){
			printf("> 5.Apply a class\n");
			mycount = applyMyClasses(myclass, mycount, classes, count);
			printf("%d classes has been applied.\n", mycount);
		}
		else if(no == 6){
			printf("> 6.My classes\n");
			printMyClasses(myclass, mycount, classes, count);
		}
		else if(no == 7){
			printf("> 7.Save\n");
			saveMyClass(myclass, mycount, classes, count);
			printf("\n> All my classes ware saved to my_classes.txt.\n");
			saveAllClasses(classes, count);
			printf("\n> All of class list ware saved to classes.txt.\n");
		}
		else break;
	}
	return 0;
}

int loadData(struct st_class* c[]){
	int count=0;
	FILE* file;

	file=fopen("classes.txt", "r");
	while(!feof(file)){
		c[count] = (struct st_class*)malloc(sizeof(struct st_class));
		int r = fscanf(file, "%d %s %d %d", &(c[count]->code),c[count]->name, &(c[count]->unit), &(c[count]->grading));
		if(r < 4) break;
		count++;
	}
	fclose(file);
	return count;
}

void printAllClasses(struct st_class* c[], int csize){
	for(int i=0; i<csize; i++){
		printf("[%d] %s [credit %d - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
	}
}

void saveAllClasses(struct st_class* c[], int csize){
	FILE* file;
	file = fopen("classes.txt", "w");
	for(int i=0; i<csize; i++){
		fprintf(file, "%d %s %d %d\n",c[i]->code, c[i]->name, c[i]->unit, c[i]->grading);
	}
	fclose(file);	
}

void findClasses(char* name, struct st_class* c[], int csize){
	int count = 0;

	printf("Searching (keyword : %s)\n", name);
	for(int i=0; i<csize; i++){
		if(strstr(c[i]->name, name)){
			printf("[%d] %s [credit %d - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
			count++;
		}
	}
	printf("%d classes found.\n", count);
}

// You must complete these functions.
/*
하는 일: 현재 교과목 목록에 새로운 과목을 추가하고, 증가한 과목 개수를 리턴한다.
> 수정해야 하는 내용: 과목 추가 시, 이미 등록된 과목코드가 추가되지 않도록 코드를 수정하라.

*/
int addNewClass(struct st_class* c[], int csize){
// Caution : Don't allow the duplicate class code.
// You must complete this function.

	struct st_class* p = (struct st_class*)malloc(sizeof(struct st_class));     //변수를 담을 임시 구조체 포인터 생성

    while(1){
        int mark =1;    //0=중복, 1=통과
        printf(">> code number > ");        //코드 번호 및 정보 입력받기
        scanf("%d", &(p->code));
        //이미 있으면 빠꾸, 다시 입력받기
        for(int i=0; i<csize; i++){
            if(p->code == c[i]->code) mark=0;    //입력한 코드가 중복이면 다시 while문 돌리기
        }
        if(mark==0) printf(">> Code duplicated! Retry.\n");
        if(mark==1) break;  //중복없으면 while문 나가기
    }

	printf(">> class name > ");     
	scanf("%s", p->name);
	printf(">> credits > ");
	scanf("%d", &(p->unit));
	printf(">> grading (1: A+~F, 2: P/F) > ");
	scanf("%d", &(p->grading));

	c[csize] = p;   //새롭게 정보를 담은 주소 넣기
	return csize+1;
}

/*
하는 일: 현재 교과목 목록에서 입력된 과목코드에 해당하는 과목 정보를 새로 입력받아 수정한다.
> 수정해야 하는 내용: 과목코드를 입력받은 후, 수정작업을 진행하기 위해 과목구조체 포인터의 값을 할당하는 과정을 코드에 반영하여 수정하라.
 과목코드가 존재하지 않는 경우도 적절하게 처리하라.
 1. 새로 바꿀 과목코드 입력받기
  -> 과목코드 없으면 에러메시지 실행& 다시 입력받기
 2. 해당 과목코드가 n번쨰 배열에 있는지 찾기
 3. 새로운 정보들, 임시 구조체에 입력받기
 4. c[n] = &p. 새롭게 업뎃한 정보의 주소값으로 바꿔넣기. 
*/

void editClass(struct st_class* c[], int csize){
	struct st_class* p;     //변수를 담을 임시 구조체 포인터 생성
	int code;
    int num;
    while(1){
	printf(">> Enter a code of class > ");  //코드입력
	scanf("%d", &code);
	
        int mark =0;
        for(int i=0; i<csize; i++){
            if( code == c[i]->code ) {
                num=i;
                mark=1;
            }
        }
        if(mark==1) break;
        if(mark==0) printf("> No such class.\n");
    }
    p = c[num];
	// 3. p라는 구조체에 기존의 주소값을 연결한다. 
	printf("> Current: [%d] %s [credits %d - %s]\n",p->code, p->name, p->unit, kname[p->grading-1]);
	printf("> Enter new class name > ");
	scanf("%s", p->name);
	printf("> Enter new credits > ");
	scanf("%d", &(p->unit));
	printf("> Enter new grading(1:Grade, 2: P/F) > ");
	scanf("%d", &(p->grading));

	printf("> Modified.\n");
    // 4. c[n] = &p. 새롭게 업뎃한 정보의 주소값으로 바꿔넣기. 

}
// You must make all these functions.
/*
하는 일 : 과목코드를 입력받아 내 수강신청 과목을 추가로 등록하는 과정을 반복하다가 끝나면
최종 등록된 내 수강과목의 개수를 리턴한다.
> 반드시 과목코드가 중복되는 경우, 과목코드가 존재하지 않는 경우를 검사해야 한다.

0. 임의 구조체 생성
1. 추가하고픈 과목코드 입력
-> 추가하려는 과목코드가 존재하지 않는지 전체 수강과목에서 검사
-> 추가하려는 과목코드가 중복되는지 내 과목에서 검사
2. 해당 과목코드의 정보와 임의 구조체의 정보와 연결. 
3. 추가하려는 과목의 정보 등록
4. csize+1 return;
*/
int applyMyClasses(int my[], int msize, struct st_class* c[], int csize){



	
	return 0;
}

void printMyClasses(int my[], int msize, struct st_class* c[], int csize){


	

}

void saveMyClass(int my[], int msize, struct st_class* c[], int csize){



	
}
