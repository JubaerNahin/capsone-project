#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void addstudent();
void studentrecord();
void searchstudent();
void delete();

  struct student{
    char first_name[20];
    char last_name[20];
    int id;
    float cgpa;
};

void main()
{

  int choice;
  while(choice!=5){

    printf("\t\t\t\t=====Student Data Storing Management=====");
    printf("\n\n\n\t\t\t\t     1. Add Student Data\n");
    printf("\t\t\t\t     2. Students Data\n");
    printf("\t\t\t\t     3. Search Students\n");
    printf("\t\t\t\t     4. Delete Data\n");
    printf("\t\t\t\t     5. Exit\n");
    printf("\t\t\t\t     __________________________\n");
    printf("\t\t\t\t     Enter your choice:");
    scanf("%d",&choice);

    switch(choice){
       case 1:
          system("cls");
          addstudent();
          system("cls");
          break;
      case 2:
          system("cls");
          studentrecord();
          printf("\t\t\t\t press any key to exit....... \n");
          getch();
          system("cls");
          break;
      case 3:
          system("cls");
          searchstudent();
          printf("\t\t\t\t press any key to exit....... \n");
          getch();
          system("cls");
          break;
      case 4:
          system("cls");
          delete();
          printf("\t\t\t\t press any key to exit....... \n");
          getch();
          system("cls");
          break;
      case 5:
          system("cls");
          printf("Thank You for using this software.\n\n");
          exit(0);
          break;
      default:
          system("cls");
          getch();
          printf("\n\t\t\t\tEnter a valid number\n\n");
          printf("\t\t\t\tPress any key to continue........");
          getch();
          system("cls");
          break;
    }
  }
  getch();
}

void addstudent(){

  char next;
  FILE *fp;
  struct student data;
do{
  system("cls");
  printf("\t\t\t\t=======Add Student Data=======\n\n\n");
  fp=fopen("Data.txt","a");

    printf("\n\t\t\tEnter First Name    : ");
    scanf("%s",&data.first_name);
    printf("\n\t\t\tEnter Last Name     : ");
    scanf("%s",&data.last_name);
    printf("\n\t\t\tEnter Id            : ");
    scanf("%d",&data.id);
    printf("\n\t\t\tEnter Cgpa          : ");
    scanf("%f",&data.cgpa);
    printf("\n\t\t\t------------------------------\n");

    if(fp==NULL){
      printf("can't open file\n");
    }
    else{
      printf("\t\t\tRecord stored successfully\n");
    }
    fwrite(&data, sizeof(struct student),1,fp);
    fclose(fp);

    printf("\t\t\tYou want to add another record?(y/n) : ");

    scanf("%s",&next);
  }  while(next=='y' || next=='Y');
}

void studentrecord(){

  FILE *fp;

  struct student data;
  fp=fopen("Data.txt","r");

   printf("\t\t\t\t=======Students Record=======\n\n\n");

  if(fp==NULL){

    printf("can't open file\n");
    exit(0);
  }
  else{
    printf("\t\t\t\tRecords :\n");
    printf("\t\t\t\t___________\n\n");
  }
  while(fread(&data,sizeof(struct student),1,fp)){
    printf("\n\t\t\t\t Student Name : %s %s",data.first_name,data.last_name);
    printf("\n\t\t\t\t Id           : %d",data.id);
    printf("\n\t\t\t\t Cgpa         : %.2f",data.cgpa);
    printf("\n\t\t\t\t_________________________________\n");

  }
  fclose(fp);
  getch();
}

void searchstudent(){
  struct student data;
  FILE *fp;
  int id,found=0;

  fp=fopen("Data.txt","r");
  printf("\t\t\t\t=======Search Record of a Student=======\n\n\n");
  printf("\t\t\tEnter The id : ");

  scanf("%d",&id);

  while(fread(&data,sizeof(struct student),1,fp)>0){

    if(data.id==id){

      found=1;
      printf("\n\n\t\t\tStudent Name : %s %s",data.first_name,data.last_name);
      printf("\n\n\t\t\tId           : %d",data.id);
      printf("\n\n\t\t\tCgpa         : %.2f",data.cgpa);
      printf("\n\t\t\t_____________________________________________\n");
    }
  }
  if(!found){
    printf("\n\t\t\tRecord not found\n");
  }
  fclose(fp);
  getch();
}

void delete(){
  struct student data;
  FILE *fp, *fp1;

  int id,found=0;

  printf("\t\t\t\t========Delete students record=======\n\n\n");
  fp=fopen("Data.txt","r");
  fp1=fopen("temp.txt","w");
  printf("\t\t\t\tEnter the id : ");
  scanf("%d",&id);
  if(fp==NULL){
    printf("can't open file");
    exit(0);
  }

  while(fread(&data,sizeof(struct student),1,fp)){
    if(data.id==id){
      found=1;
    }
    else{
      fwrite(&data,sizeof(struct student),1,fp1);
    }
  }
   fclose(fp);
   fclose(fp1);

  if(!found){
    printf("\n\t\t\t\tRecord not found\n");
  }
  if(found){
    remove("Data.txt");
    rename("temp.txt","Data.txt");

    printf("\n\t\t\t\tRecord deleted successfully\n");
  }
   getch();
}
