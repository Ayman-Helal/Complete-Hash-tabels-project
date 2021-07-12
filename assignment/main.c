/* 
Name:- Ayman Mohamed Helal Abouzeid 
Sec:- 1         BN:- 38
Name:- marwan ramzy mohamed
Sec:- 4         BN:- 7
Name:- kareem el saed abdel hafez
Sec:- 3         Bn:- 23
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20


void hashReservation();
int HashFunction(int a);
void InsertInHash_usingName();
void printHash_withNames();
void FindInTable_usingName(char name1[25]);
void DeletFromTable_usingName(char name1[25]);


int keycalc(int day , int month, int year); 
void createHashtable();
int hashfunc(int key);
struct student *search(int key);
struct student *delete1(struct student* item);
void display();


struct student {
    char name[25];
    int id,key;
    int date_of_birth[3];
    int score_of_last_year;
    struct student *nextptr;
    }*hash[28];
 
 
struct student* hasharr[SIZE];
struct student* NULLItem;
struct student* item;   
void insert(int key, char name[25], int id, int day , int month, int year, int score_of_last_year, int a );    



//***************************************************Main function**********************************************************************************
int main()
{
	
 
    int l=1;
int a,E,G, keey, id, score_of_last_year, key, date_of_birth[3];
char name[25];
char name1[25];
printf("welcome to our system\n");
printf("**********************************************************************************************************************\n");
fflush(stdin);
printf("press 1: To use the name as key\n press 2: To use the date of birth as key\n");
scanf("%d",&G);
switch(G)
{
	case 1:
		{
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
		}break;
		
		
case 2:
{
	 createHashtable();
    while(1){
        int c;
        printf(" 1. Insert\n 2. Search\n 3. Delete\n 4. Exit\n");
        scanf("%d", &c);
        if(c==1){
        printf("Choose a method: \n 1. Linear probing\n 2. Quadratic probing \n");
        scanf("%d", &a);
        printf("Enter name :\n");
        scanf("%s", name );
        printf("Enter id:\n");
        scanf("%d", &id );
        printf("Enter date of birth:\n");
        for ( int j = 0; j < 3; ++j)
            scanf("%d", &date_of_birth[j] );
        printf("Enter socre:\n");
        scanf("%d", &score_of_last_year );
        keey = keycalc( date_of_birth[0], date_of_birth[1], date_of_birth[2]);
        insert( keey, name, id, date_of_birth[0], date_of_birth[1], date_of_birth[2], score_of_last_year, a);
        display();
        }
        else if(c==2){
            printf("Enter a key:    (Note: you should enter the sum of day, month and year as a key.)\n");
            scanf("%d", &keey);
            item = search(keey);
            if(item != NULL) {
                printf("Element found: \n");
                printf(" (key: %d, Name: %s, ID: %d, Birthdate: %d/%d/%d, Score: %d\n)",item->key,item->name,item->id,item->date_of_birth[0],item->date_of_birth[1],item->date_of_birth[2],item->score_of_last_year);
            }
            else {
                printf("Element not found\n");
            }
        }
        else if(c==3){
            printf("Enter a key:    (Note: you should enter the sum of day, month and year as a key.)\n");
            scanf("%d", &keey);
            item = search(keey);
            if(item != NULL) {
                printf("Element found: \n");
                printf(" (key: %d, Name: %s, ID: %d, Birthdate: %d/%d/%d, Score: %d\n)",item->key,item->name,item->id,item->date_of_birth[0],item->date_of_birth[1],item->date_of_birth[2],item->score_of_last_year);
                printf("Item is deleted\n");
                delete1(item);
            }
            else {
                printf("Element not found\n");
            }
        }
        else{
            display();
            exit(0);
        }

    }	}break;
			
}
return 0;
}

//************************************************************************************************************************************************
//hashing using birth of date functions
//**********************************************************************************************************************************************
int keycalc(int day , int month, int year){
    int key;
    key = day + month + year;
    return key;
}

//--------------------------------------------------------------------------------
void createHashtable(){
    NULLItem = (struct student*) malloc(sizeof(struct student));
    NULLItem->id = -1;
    NULLItem->key = -1;
}
 //-------------------------------------------------------------------------------
int hashfunc(int key) {
   return key % SIZE;
}
//----------------------------------------------------------------------------------
struct student *search(int key) {
   //get the hash
   int Index = hashfunc(key);

   //move in array until an empty
   while(hasharr[Index] != NULL) {

      if(hasharr[Index]->key == key)
         return hasharr[Index];

      //go to next cell
      ++Index;

      //wrap around the table
      Index %= SIZE;
   }

   return NULL;
}
 //-------------------------------------------------------------------------------------------------------------------
void insert(int key, char name[25], int id, int day , int month, int year, int score_of_last_year, int a ) {

   struct student *item = (struct student*) malloc(sizeof(struct student));
   strcpy(item->name , name);
   item->id = id;
   item->date_of_birth[0] = day;
   item->date_of_birth[1] = month;
   item->date_of_birth[2] = year;
   item->score_of_last_year = score_of_last_year;
   item->key = key;

   //get the hash
   int Index = hashfunc(key);
    int i=0;
    int oldIndex=Index;
   //move in array until an empty or deleted cell
   while(hasharr[Index] != NULL && hasharr[Index]->key != -1) {
      if(a==1){
          //Linear probing
          ++Index;
          key++;
          item->key=key;
      //wrap around the table
      Index %= SIZE;
      }
      else{
        //Quadratic probing
      Index=oldIndex;
      //go to next cell
      Index=Index+(i*i);
      printf("Index is %d\n", Index);
      i++;
      printf("i is %d\n", i);
      //wrap around the table
      Index %= SIZE;
      }
   }
   if(a==2){
       i=i-1;
       item->key=key+(i*i);
   }
 
   hasharr[Index] = item;
}

//------------------------------------------------------------------------------------------------------------------------
struct student* delete1(struct student* item) {
   int key = item->key;

   //get the hash
   int Index = hashfunc(key);

   //move in array until an empty
   while(hasharr[Index] != NULL) {

      if(hasharr[Index]->key == key) {
         struct student* temp = hasharr[Index];

         //assign a dummy item at deleted position
         hasharr[Index] = NULLItem;
         return temp;
      }

      //go to next cell
      ++Index;

      //wrap around the table
      Index %= SIZE;
   }

   return NULL;
}

//------------------------------------------------------------------------------------------------------
void display() {
   int i = 0;

   for(i = 0; i<SIZE; i++) {

      if(hasharr[i] != NULL){
          if(hasharr[i]->id == -1){
        printf(" ~~ ");
      }
      else{
         printf(" (key: %d, Name: %s, ID: %d, Birthdate: %d,%d,%d, Score: %d)",hasharr[i]->key,hasharr[i]->name,hasharr[i]->id,hasharr[i]->date_of_birth[0],hasharr[i]->date_of_birth[1],hasharr[i]->date_of_birth[2],hasharr[i]->score_of_last_year);
      }

      }
      //else if(hasharr[i]->id == -1){
        //printf(" ~~ ");
      //}
      else
         printf(" ~~ ");
   }

   printf("\n");
}


//hashing using the name as key
//**************************************************************************************************************************************************************************************************************************************************************************************

void hashReservation()
{
int i;
for(i=0;i<28;i++)
hash[i]=NULL;
}

//-----------------------------------------------------------------------------------------------------------------

int HashFunction(int a)
{
    int index=a%28;
    return index;
}

//--------------------------------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------------------------------------------------
void FindInTable_usingName(char name1[25])
{
    int k;
    int j,ch;
    struct student *tempstu;


// Handling the name
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    ch = name1[0];
printf("Ascii of the input is: %d\n",ch);
if (ch<=90&ch>=65)
ch=ch+32;
int index=HashFunction(ch);
printf("The index is: %d\n",index);

//finding
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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

//------------------------------------------------------------------------------------------------------------------------------------------

void DeletFromTable_usingName(char name1[25])
{
    
    int k,j,ch;
    struct student *tempstu,*prestu,*nxtstu;
     

// Handling the name
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    ch = name1[0];
printf("Ascii of the input is: %d\n",ch);
if (ch<=90&ch>=65)
ch=ch+32;
int index=HashFunction(ch);
printf("The index is: %d\n",index);

//deleting
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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

//------------------------------------------------------------------------------------------------------------------------------------------

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
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

ch = name1[0];
printf("Ascii of the input is: %d\n",ch);
if (ch<=90&ch>=65)
ch=ch+32;
int index=HashFunction(ch);
printf("The index is: %d\n",index);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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



