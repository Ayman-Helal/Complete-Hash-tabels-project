#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hashReservation();
int HashFunction(int a);
void InsertInHash_usingName();
void printHash_withNames();
void FindInTable_usingName(char name1[25]);
void DeletFromTable_usingName(char name1[25]);

  struct student {
    char name[25];
    int id;
    int date_of_birth[3];
    int score_of_last_year;
    struct student *nextptr;
    }*hash[28];

int main()
{
 char name1[25];
    int l=1;
    int E;
printf("welcome to our system\n");
printf("**********************************************************************************************************************\n");
hashReservation();
while(l==1){
    printf("**********************************************************************************************************************\n");
    printf("press 1:to insert\n press 2:to search\n press 3: to delete\n press 0: to end the program\n");
    scanf("%d",&E);
    switch(E){
case 1:
   InsertInHash_usingName();break;
case 2:
    {
        fflush(stdin);
        printf("Enter the student name\n");
        gets(name1);
        printf("you entered : %s\n",name1);
        FindInTable_usingName(name1);
    }break;
case 3:
{
   fflush(stdin);
        printf("Enter the student name\n");
        gets(name1);
        printf("you entered : %s\n",name1);
        DeletFromTable_usingName(name1);  
}break;
case 0:
    l=0;break;

}
}
printf("\n Data entered in the table : \n");
printHash_withNames();
    return 0;
}




void hashReservation()
{
int i;
for(i=0;i<28;i++)
hash[i]=NULL;
}


int HashFunction(int a)
{
    int index=a%28;
    return index;
}



void printHash_withNames()
{
    int i,j,ch;
    struct student *tempstu;
    for(i=0;i<28;i++)
    {
    printf("**********************************************************************************************************\n");
    if(hash[i] == NULL)
    {
       printf(" chain[%d] is empty.\n",i);
    }
    else
    {
        printf(" chain[%d] is: \n",i);
        tempstu = hash[i];

        while(tempstu != NULL)
        {
             printf("--------------------------------------------------------------------------------------------\n");
         printf(" name = %s\n", tempstu->name);
         printf(" ID = %d\n", tempstu->id);
         printf(" date of birth= ");
            for (j=0;j<=2;j++)
            {
                printf(" %d",tempstu->date_of_birth[j]);
            }
            printf("\n score of last year= %d\n",tempstu->score_of_last_year);
            printf("--------------------------------------------------------------------------------------------\n");

            tempstu = tempstu->nextptr;                     // advances the position of current node
        }
   } }
}




void FindInTable_usingName(char name1[25])
{
    int k;
    int j,ch;
    struct student *tempstu;


// Handling the name
//------------------------------------------------------------------------------------------------------------------
    ch = name1[0];
printf("Ascii of the input is: %d\n",ch);
if (ch<=90&ch>=65)
ch=ch+32;
int index=HashFunction(ch);
printf("The index is: %d\n",index);

//finding
//------------------------------------------------------------------------------------------------------------------
if (hash[index]==NULL)
    printf("the program didn't find this name\n");
    else
{
  tempstu = hash[index];
  while(tempstu != NULL)
  {
      if (!strcmp(name1,tempstu->name))
      {
        printf("--------------------------------------------------------------------------------------------\n");
        printf("Name Exist\n");
         printf(" name = %s\n", tempstu->name);
         printf(" ID = %d\n", tempstu->id);
         printf(" date of birth= ");
            for (j=0;j<=2;j++)
            {
                printf(" %d",tempstu->date_of_birth[j]);
            }
            printf("\n score of last year= %d\n",tempstu->score_of_last_year);
         printf("--------------------------------------------------------------------------------------------\n");
          k=1;
          break;
      }
      else{
        tempstu = tempstu->nextptr;
     k=0; }
  }
if (k==0){
printf("the program didn't find this name\n");}
}
}




void DeletFromTable_usingName(char name1[25])
{
    
    int k,j,ch;
    struct student *tempstu,*prestu,*nxtstu;
     

// Handling the name
//------------------------------------------------------------------------------------------------------------------
    ch = name1[0];
printf("Ascii of the input is: %d\n",ch);
if (ch<=90&ch>=65)
ch=ch+32;
int index=HashFunction(ch);
printf("The index is: %d\n",index);

//finding
//------------------------------------------------------------------------------------------------------------------
if (hash[index]==NULL)
    printf("the program didn't find this name deleting not possible\n");
    else
{
  tempstu = hash[index];
  prestu = hash[index];
  while(tempstu != NULL)
  {
      
      if (!strcmp(name1,tempstu->name))
      {
        printf("--------------------------------------------------------------------------------------------\n");
        printf("Name Exist\n");
         printf(" ID = %d\n", tempstu->id);
          k=1;
          break;
      }
      else{
        tempstu = tempstu->nextptr;
      
     k=0; }
  }
if (k==0){
printf("the program didn't find this name deleting not possible\n");}
else{
    if (tempstu == hash[index]){
      hash[index] = hash[index]->nextptr;
      free(tempstu);  
    }
    else{
        while(prestu->nextptr!=tempstu)
        {
             prestu=prestu->nextptr;
        }
        nxtstu=tempstu->nextptr;
        prestu->nextptr = nxtstu;
        free(tempstu);
    }

   printf("sucessfull Deleting \n");
}
}
}




void InsertInHash_usingName()
{
    char name1[25];
    struct student *newstu;
    int ch,j,num,c,date[3],score;

newstu=(struct student *)malloc(sizeof(struct student));


if(newstu == NULL) //check whether the newstu is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
      // reads data for the first student through keyboard
 fflush(stdin); // to solve buffer problem

      printf("  enter name of the new student  : ");
         gets(name1);
       strcpy(newstu->name,name1);


        printf(" enter ID of the new student: ");
        scanf("%d", &num);
        newstu->id = num;

   printf(" enter birth of date of the new student :     (press enter key after every number)\n ");
    for(j=0;j<=2;j++)
        {
        scanf(" %d",&date[j]);
        newstu->date_of_birth[j]=date[j];
        }

       printf(" enter score of last year of the new student : ");
       scanf("%d",&score);
       newstu->score_of_last_year=score;
}
// Handling the name
//------------------------------------------------------------------------------------------------------------------

ch = name1[0];
printf("Ascii of the input is: %d\n",ch);
if (ch<=90&ch>=65)
ch=ch+32;
int index=HashFunction(ch);
printf("The index is: %d\n",index);

//--------------------------------------------------------------------------------------------------------------------
 if(hash[index]==NULL)
   {
     hash[index]= newstu;
   }
 else
 {
     newstu->nextptr = NULL;
     newstu-> nextptr = hash[index];
     hash[index] = newstu;
      
 }
}



