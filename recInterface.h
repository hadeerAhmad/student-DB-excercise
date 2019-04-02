/*Interfaces*/
student* AddRecord(char ID,gender sex,char name[],float quiz1,float quiz2,float mid,float final);
void DeleteRecord(student*record, int ArrPos);
int UpdateRecord(int index);
void ViewAllRecords(void);
float CalcAvg(student*record);
student* GetMax(void);
student* GetMin(void);
student* FindStudent(char ID);
int SortRecords(void);