//ѧ���ɼ�������Ŀ�������ļ���������
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
                puts("����û������ѧ����Ϣ��");
	}while(option!=0);
}

void instructions(void){
printf("��ѡ������Ҫ�Ĳ���:\n");
		printf("1-��ӡ������ѧ������\n");
		printf("2-��ӡÿ�ſ�ƽ���ɼ�\n");
		printf("3-������������ѧ����Ϣ\n");
		printf("4-��ĳ�ſγɼ���ѧ����������\n");
		printf("5-�������ѧ������Ϣ\n");
		printf("6-д���ļ�\n");
		printf("7-��ȡ�ļ�\n");
		printf("8-����ѧ����Ϣ\n");
		printf("0-�˳�\n");
}

void o1_fail_student(struct student stu[],int n)
{
	int option;
	printf("��ѡ�������ӡ�Ĳ�����γ�������1-3��\n");
	printf("1�γ�1\t2-�γ�2\t3-�γ�3\t");
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
	printf("��һ�ſε�ƽ���ɼ�Ϊ%.2f\n",sum[k]/n);

}

void o3_search(struct student stu[],int n)
{
	char tempName[10];
	printf("������ѧ������:\n");
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

	printf("��ѡ������Ŀγ̣�1-3��\n");
	printf(" 1-�γ�1\n 2-�γ�2 \n3-�γ�3\n");
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
		//���������ṹ��
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
    printf("�������ļ�������Ŀ¼·������һ����б�߻�������б�߸�����");
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
		printf("д��ɹ���");
	}
	fclose(fPtr);
 }

 void o7_readOut(struct student stu[],int n)
{
    getchar();
    char filename[50];
    printf("�������ļ���,��Ŀ¼·������һ����б�߻�������б�߸�����");
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
		printf("��ȡ�ɹ���");
	}
	fclose(fPtr);
 }

int o8_input(struct student stu[])
{
	int n;
	printf("������ѧ����Ŀ(1-50):\n");
	scanf("%d",&n);
	while((n<1)||(n>50)){
		printf("����(1-50)֮��Ŷ:");
		scanf("%d",&n);
	}
	for(int i=0;i<n;i++){
		printf("�������� %d\n",i+1);
		scanf("%s",stu[i].name);
		printf("�����Ա�(0-female,1-male)ѧ��%d\n",i+1);
		scanf("%d",&stu[i].gender);

		for(int k=0;k<3;k++){
            printf("����ѧ�� %d�ĳɼ� %d\n",i+1,k+1);
            scanf("%lf",&stu[i].score[k]);
		}//end for k
	}//end for i
	return n;
}
