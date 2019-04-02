#include<stdio.h>
#include"def.h"
#include"recInterface.h"

/********************************************************************************************************************************************************************/
/*Array of pointers to structure*/
 student*ArrOfSt[CAPACITY];
char GlobalIndex;

/*Main function*/
int main(void){
	char choice ;
	char EndChoice;
	int i;
	int searchFlag=0;
while(1){
printf("Welcome to Student Management System\n");
printf("To Add student Record please press 1\n");
printf("To Update student Record please press 2\n");
printf("To Delete a student Record please press 3\n");
printf("To View All students Records please press 4\n");
printf("To Calculate the average of a student  please press 5\n");
printf("To get the max record please press 6\n");
printf("To get the min record please press 7\n");
printf("To search for a student  please press 8\n");
printf("To sort students  please press 9\n");
scanf("%d",&choice);

switch(choice){
		char ID;
		gender sex;
		char name[9];
		float quiz1;
		float quiz2;
		float mid;
		float final;
		float total;
	
	case 1:{
		printf("Welcome To Add Student Screen\n");
		if(GlobalIndex<CAPACITY){
	
		printf("Please Enter Student ID\n");
		scanf("%d",&ID);
		printf("Please Enter Student name\n");
		scanf("%s",name);
		printf("Please Enter student sex: 0 for male, 1 for female\n");
		scanf("%d",&sex);	
		printf("Please Enter quiz1 marks\n");
		scanf("%f",&quiz1);
		printf("Please Enter quiz2 marks\n");
		scanf("%f",&quiz2);
		printf("Please Enter mid marks\n");
		scanf("%f",&mid);
		printf("Please Enter  final marks\n");
		scanf("%f",&final);
		ArrOfSt[GlobalIndex]=AddRecord(ID,sex,name,quiz1,quiz2, mid, final);
			GlobalIndex++;
		}
		else{
			printf("No more Space. Please Delete some records first\n");
		}
		
		break;
	}
	
		case 2:
		{	
		if(GlobalIndex<1){
			printf("No Students recorded. Please Add some records first\n");
		}
		else{
		printf("PLEASE enter the ID of the record you want to update\n");
		scanf("%d",&ID);
		
			for(i=0;i<=GlobalIndex;i++){
				/*printf("I am inside loop and outside cond\n");
				printf("ID  inside struct is %d\n",ArrOfSt[i]->ID);
				printf("ID  entered is %d\n",ID);
				printf("I am inside loop and outside cond\n");
				printf("%s\n",ArrOfSt[i]->name);*/
				if(ArrOfSt[i]->ID==ID){
					searchFlag=1;
						
					break;
					
				}
				
			}
		
			if(searchFlag==0){
				printf("Wrong ID\n");
			}
			else{
				searchFlag=0;
				if(!UpdateRecord(i)){
					printf("Successfully updated!\n");
				}
				else{
					printf("An error occured during Update\n");
				}
			}
		}
		
		break;
	}
	
		case 3:{
			if(GlobalIndex<1){
				printf("No records to delete\n");
			}
			else{
			printf("Enter the ID of the student you want to delete\n");
			scanf("%d",&ID);
			for(i=0;i<GlobalIndex;i++){
				if(ArrOfSt[i]->ID==ID){
					searchFlag=1;
						
					break;
					
				}
				
			}
		
			if(searchFlag==0){
				printf("No such an ID\n");
			}
			else{
				searchFlag=0;
			DeleteRecord(ArrOfSt[i],i);
				
			}
			}
		break;
	}
	
		case 4:{
				if(GlobalIndex<1){
				printf("No records to view\n");
			}
			else{
			ViewAllRecords();}
		break;
	}
	
	case 5: {
		float avg;
		if(GlobalIndex<1){
				printf("No records to Calculate the average for\n");
			}
			else{
				printf("Enter the ID of the student you want to get the avg of \n");
			scanf("%d",&ID);
			for(i=0;i<GlobalIndex;i++){
				if(ArrOfSt[i]->ID==ID){
					searchFlag=1;
						
					break;
					
				}
				
			}
		
			if(searchFlag==0){
				printf("No such an ID\n");
			}
			else{
				searchFlag=0;
			avg=CalcAvg(ArrOfSt[i]);
				printf("Avg is %f\n",avg);
			}
			}
		break;
	}
	
	case 6: {
			if(GlobalIndex<1){
				printf("No records to Calculate the max\n");
			}
			else{
			student*max=GetMax();
			printf("Info of the student who got max\n");
			printf("%d\n",max->ID);
			printf("%s\n",max->name);
			printf("%f\n",max->total);
		}
		break;
	
	
	
	
	
}
	
	case 7: {
			if(GlobalIndex<1){
				printf("No records to Calculate the min\n");
			}
			else{
			student*min=GetMin();
			printf("Info of the student who got min\n");
			printf("%d\n",min->ID);
			printf("%s\n",min->name);
			printf("%f\n",min->total);
		}
		break;
	
	
	
	
	
}

	case 8: {
			if(GlobalIndex<1){
				printf("No records to search\n");
			}
			else{
				char ID;
				printf("Please Enter the ID you want to search for\n");
				scanf("%d",&ID);
				student*found=FindStudent(ID);
				if(found){
			
			printf("Info of the student who has the ID: %d\n",ID);
			printf("%d\n",found->ID);
			printf("%s\n",found->name);
			printf("%f\n",found->quiz1);
			printf("%f\n",found->quiz2);
			printf("%f\n",found->mid);
			printf("%f\n",found->total);
				}
				else{
					printf("No such a student\n");
				}
		}
		break;
	
	
	
	
	
}
	case 9: {
			if(GlobalIndex<1){
				printf("No records to sort\n");
			}
			else{
		if(SortRecords()){
			printf("Successfully Sorted!");
		}
		}
		break;
	
	
	
	
	
}

default: {printf("wrong choice\n");
continue;
}






}
printf("To End program, please press 0. To continue press 1\n");
scanf("%d",&EndChoice);
if(EndChoice==0){
	return 0;
}

else if(EndChoice==1){
	continue;
}
}
//return 0;
}