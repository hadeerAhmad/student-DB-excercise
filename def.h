#define CAPACITY 10
typedef enum{
	male,female,
}gender;
typedef  struct myStruct{
		char ID;
		gender sex;
		char name[9];
		float quiz1;
		float quiz2;
		float mid;
		float final;
		float total;
}student;