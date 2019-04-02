#include"def.h"
#include"recInterface.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern  student*ArrOfSt[CAPACITY];
extern GlobalIndex;
student* AddRecord(char ID,gender sex,char name[],float quiz1,float quiz2,float mid,float final){
	/*char ID;
		gender sex;
		char name[9];
		float quiz1;
		float quiz2;
		float mid;
		float final;
		float total;*/
		
	student* ptrToStr=(student*)malloc(sizeof(student));
	if(ptrToStr!=0){
		
		ptrToStr->ID=ID;
		ptrToStr->sex=sex;
		strcpy(ptrToStr->name,name);
		ptrToStr->quiz1=quiz1;
		ptrToStr->quiz2=quiz2;
		ptrToStr->mid=mid;
		ptrToStr->final=final;
		ptrToStr->total=quiz1+quiz2+mid+final;
		//ArrOfSt[GlobalIndex]=ptrToStr;
		//GlobalID++;
		return ptrToStr;
	}
	else{
		printf("Memory Allocation Failed");
		return 0;
	}
	
}
void DeleteRecord(student*record, int ArrPos){
	int localIndex;
	free(record);
	//shift elements of array of pointers to structs
	for(localIndex=ArrPos;localIndex<GlobalIndex;localIndex++){
		
		ArrOfSt[localIndex]=ArrOfSt[localIndex+1];
	}
	GlobalIndex--;
}
int UpdateRecord(int index){
		printf("Please Enter Student ID\n");
		scanf("%s",&(ArrOfSt[index]->ID));
		printf("Please Enter Student name\n");
		scanf("%s",&(ArrOfSt[index]->name));
		printf("Please Enter student sex: 0 for male, 1 for female\n");
		scanf("%d",&(ArrOfSt[index]->sex));	
		printf("Please Enter quiz1 marks\n");
		scanf("%f",&(ArrOfSt[index]->quiz1));
		printf("Please Enter quiz2 marks\n");
		scanf("%f",&(ArrOfSt[index]->quiz2));
		printf("Please Enter mid marks\n");
		scanf("%f",&(ArrOfSt[index]->mid));
		printf("Please Enter  final marks\n");
		scanf("%f",&(ArrOfSt[index]->final));
		return 0;
}
void ViewAllRecords(void){
	int i;
	for(i=0;i<GlobalIndex;i++){
		printf("ID: %d\n", ArrOfSt[i]->ID);
		printf("Name: %s\n", ArrOfSt[i]->name);
		printf("Sex: %d\n", ArrOfSt[i]->sex);
		printf("quiz1: %f\n", ArrOfSt[i]->quiz1);
		printf("quiz2: %f\n", ArrOfSt[i]->quiz2);
		printf("mid: %f\n", ArrOfSt[i]->mid);
		printf("final: %f\n", ArrOfSt[i]->final);
		printf("total: %f\n", ArrOfSt[i]->total);
		
	}
}
float CalcAvg(student*record){
	float avg;
	avg=(record->total)/4;
	return avg;
}
student* GetMax(void){
	int i;
	float Max=ArrOfSt[0]->total;
	int maxIndex=0;
	for(i=1;i<GlobalIndex;i++){
		if(ArrOfSt[i]->total>Max){
			Max=ArrOfSt[i]->total;
			maxIndex=i;
		}
	}
	return ArrOfSt[maxIndex];
}
student* GetMin(void){
		int i;
	float Min=ArrOfSt[0]->total;
	int minIndex=0;
	for(i=1;i<GlobalIndex;i++){
		if(ArrOfSt[i]->total<Min){
			Min=ArrOfSt[i]->total;
			minIndex=i;
		}
	}
	return ArrOfSt[minIndex];
}
student* FindStudent(char ID){
	int i;
	int flag=0;
	
	for(i=0;i<GlobalIndex;i++){
		if(ArrOfSt[i]->ID==ID){
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("No such an ID");
		return 0;
	}
	else{
		return ArrOfSt[i];
	}
}
int SortRecords(void){
	int i,j;
	student* temp;
	for(i=0;i<GlobalIndex-1;i++){
		for(j=0;j<GlobalIndex-i-1;j++){
			if(ArrOfSt[j]->total<ArrOfSt[j+1]->total){
				temp=ArrOfSt[j];
				ArrOfSt[j]=ArrOfSt[j+1];
				ArrOfSt[j+1]=temp;
			}
		}
	}
	return 1;
}