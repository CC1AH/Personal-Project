//学生成绩分析项目雏形与文件操作初步
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct student{
		char name[10];
		int gender;
		double score[3];
};

void o1_fail_student(struct student stu[],int n);
void o2_average(struct student stu[],int n);
void o3_search(struct student stu[],int n);
void o4_range(struct student stu[],int n);
void o5_print(struct student stu[],int n);
void o6_writeIn(struct student stu[],int n);
void o7_readOut(struct student stu[],int n);
int o8_input(struct student stu[]);
void instructions(void);

int main()
{
	struct student stu[50];
	int n=0;
	int option;
	do{
		instructions();
		scanf("%d",&option);
		switch(option){
			case 1:
				o1_fail_student(stu,n);break;
			case 2:
				o2_average(stu,n);break;
			case 3:
				o3_search(stu,n);break;
			case 4:
				o4_range(stu,n);
				o5_print(stu,n);
				break;
			case 5:
				o5_print(stu,n);;break;
			case 6:
				o6_writeIn(stu,n);break;
			case 7:
                			o7_readOut(stu,n);break;
			case 8:
				n=o8_input(stu);
				break;
		}
            if(n==0)
                puts("您还没有输入学生信息。");
	}while(option!=0);
}

void instructions(void){
printf("请选择你需要的操作:\n");
		printf("1-打印不及格学生名单\n");
		printf("2-打印每门课平均成绩\n");
		printf("3-根据姓名查找学生信息\n");
		printf("4-按某门课成绩对学生进行排序\n");
		printf("5-输出所有学生的信息\n");
		printf("6-写入文件\n");
		printf("7-读取文件\n");
		printf("8-输入学生信息\n");
		printf("0-退出\n");
}

void o1_fail_student(struct student stu[],int n)
{
	int option;
	printf("请选择你想打印的不及格课程名单（1-3）\n");
	printf("1课程1\t2-课程2\t3-课程3\t");
	scanf("%d",&option);

	for(int i=0;i<n;i++){
       if( (option == 1 && stu[i].score[0] < 60)||
		   (option == 2 && stu[i].score[1] < 60)||
		   (option == 3 && stu[i].score[2] < 60) )
		   {
			printf("name\t gender\t score1\t score2\t score3\t average\n");
			printf("%s\t %s\t %f\t %f\t %f\t %.2f\t",stu[i].name,
                    stu[i].gender==0?"female":"male",
                    stu[i].score[0], stu[i].score[1], stu[i].score[2],
                    (stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3);
            }//end if
                        }//end for
}

void o2_average(struct student stu[],int n)
{
	double sum[3] = {0};
	for(int i=0;i<n;i++){
        for(int k=0;k<3;k++)
            sum[k] += stu[i].score[k];
	}
    for(int k=0;k<3;k++)
	printf("第一门课的平均成绩为%.2f\n",sum[k]/n);

}

void o3_search(struct student stu[],int n)
{
	char tempName[10];
	printf("请输入学生姓名:\n");
	scanf("%s",tempName);
	for(int i=0;i<n;i++){
		if(strcmp(tempName,stu[i].name)==0){
			printf("name\t gender\t score1\t score2\t score3\t average\n");
			printf("%s\t %s\t %f\t %f\t %f\t %.2f\t",stu[i].name,
                    stu[i].gender==0?"female":"male",
                    stu[i].score[0], stu[i].score[1], stu[i].score[2],
                    (stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3);
		}
	}
}

void o4_range(struct student stu[],int n)
{
	int option;
	char tempN[10];
	double temp;
	int tempInt;

	printf("请选择排序的课程（1-3）\n");
	printf(" 1-课程1\n 2-课程2 \n3-课程3\n");
	scanf("%d",&option);

	int max;
	for(int i=0;i<n-1;i++){
		max = i;
		for(int j=i+1;j<n;j++){
			if( (option==1 && stu[max].score[0]<stu[j].score[0]) ||
                (option==2 && stu[max].score[1]<stu[j].score[1]) ||
		        (option==3 && stu[max].score[2]<stu[j].score[2]))
        {
			max = j;
		}
		//交换两个结构体
		if(max != i ){
			strcpy(tempN,stu[i].name);
			strcpy(stu[i].name,stu[max].name);
			strcpy(stu[max].name,tempN);

			tempInt = stu[i].gender;
			stu[i].gender = stu[max].gender;
			stu[max].gender = tempInt;

			for(int k=0;k<3;k++){
			temp = stu[i].score[k];
			stu[i].score[k] = stu[max].score[k];
			stu[max].score[k] = temp;
			}//end for k
		}//end if
	}//end for j
}//end for i
}

void o5_print(struct student stu[],int n)
{
	for(int i=0;i<n;i++){
			printf("name\t gender\t score1\t score2\t score3\t average\n");
			printf("%s\t %s\t %.2f\t %.2f\t %.2f\t %.2f\t\n",stu[i].name,
                    stu[i].gender==0?"female":"male",
                    stu[i].score[0], stu[i].score[1], stu[i].score[2],
                    (stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3);
		}
	}

void o6_writeIn(struct student stu[],int n)
{
    getchar();
    char filename[50];
    printf("请输入文件名，分目录路径请用一道左斜线或两道右斜线隔开：");
    gets(filename);
	FILE *fPtr;
	fPtr = fopen(filename,"wb");
	if(fPtr== NULL){
		puts("could not open the file!");
	}
	else{
		for(int i=0;i<n;i++){
			fwrite(&stu[i],sizeof(struct student),1,fPtr);
		}
		printf("写入成功！");
	}
	fclose(fPtr);
 }

 void o7_readOut(struct student stu[],int n)
{
    getchar();
    char filename[50];
    printf("请输入文件名,分目录路径请用一道左斜线或两道右斜线隔开：");
    gets(filename);
	FILE *fPtr;
	fPtr = fopen(filename,"rb");
	if(fPtr== NULL){
		puts("could not open the file!");
	}
	else{
         		for(int i=0;i<n;i++){
            			fread(&stu[i],sizeof(struct student),1,fPtr);
                //or:fread(stu,sizeof(struct student),n,fPtr);
                //or:fread(stu,sizeof(struct student)*n,1,fPtr);
        }
		printf("读取成功！");
	}
	fclose(fPtr);
 }

int o8_input(struct student stu[])
{
	int n;
	printf("请输入学生数目(1-50):\n");
	scanf("%d",&n);
	while((n<1)||(n>50)){
		printf("输在(1-50)之间哦:");
		scanf("%d",&n);
	}
	for(int i=0;i<n;i++){
		printf("输入名字 %d\n",i+1);
		scanf("%s",stu[i].name);
		printf("输入性别(0-female,1-male)学生%d\n",i+1);
		scanf("%d",&stu[i].gender);

		for(int k=0;k<3;k++){
            printf("输入学生 %d的成绩 %d\n",i+1,k+1);
            scanf("%lf",&stu[i].score[k]);
		}//end for k
	}//end for i
	return n;
}
