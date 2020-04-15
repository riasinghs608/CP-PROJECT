//HEADER FILES USED		 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//FUNCTION PROTOTYPE
void member();                   //FUNCTION FOR THE MEMBERS OF THE SALON
void nonmember();                //FUNCTION SHOWING THE OPTIONS FOR THE NON MEMBERS 
void menu();                     //FUNCTION SHOWING THE MENU OF THE SALON
int homepage();                  //WELCOMES USER TO THE SALON
void timeslot();                 //ALLOWS A MEMBER TO BOOK AN APPOINTMENT
int offer();                     //SHOWS THE OFFERS OF THE MEMBERS OF THE SALON
void print_offer(int c);         //PRINTS THE OFFERS CHOOSEN BY THE MEMBER
void timeslot_nonmember();       //ALLOWS A NON MEMBER TO BOOK AN APPOINTMENT
void total_amount(int beauty[50],int n); //PRINTS THE TOTAL AMOUNT TO BE PAID BY THE MEMBER OR NONMEMBER
void display_treatments(int beauty[50],int cho); //PRINTS THE TREATMENTS CHOOSEN BY THE MEMBER OR NONMEMBER	
void bye();                             //THANKS THE USER TO VISIT THE SALON
void employee_data();                   //SHOWS THE DETAILS OF THE EMPLOYEES
void flush();                           
void member_data();              //OPENS THE DATA FILES FOR A MEMBER

//STRUCTURE TO STORE DTAILS OF THE MEMBER
struct MEMBER
{
	int membership_no; //MEMBERSHIP NUMBER OF THE MEMBER
	char name[20];     //NAME OF THE MEMBER
	int age;           //AGE OF THE MEMBER
	char address[100];  //ADDRESSOF THE MEMBER
	int phoneno;       //PHONE NUMBER OF THE MEMBER
}M1;

main()
{
	int x;
	while(1)
	{
	 printf("\n\n **************************");
	 printf("\n *****WELCOME TO SALON*****");
	 printf("\n **************************");
	 printf("\n\n ENTER 1 TO BECOME A MEMBER  ");
	 printf("\n\n ENTER 2 TO CONTINUE WITHOUT MEMBERSHIP  ");
	 printf("\n\n ENTER 3 TO SEE THE STAFF'S DETAILS'");
	 printf("\n\n ENTER 4 TO SEE THE MEMBER'S DETAILS");
	 printf("\n\n ENTER 5 TO EXIT ");
	 scanf("%d",&x);
	 
	if(x==1)
      member();
	if(x==2)
	  nonmember();
	if(x==3)
	 employee_data(); 
	if(x==4)
	  member_data(); 
	if(x==5)
	{
	  bye();
	  exit(0);

   }
 } 
}
void member()  // IF THE USER WANTS TO BE A MEMBER
{
   	printf("\n ENTER YOUR FULL NAME : ");
	scanf("%s",&M1.name);
	printf("\n ENTER YOUR AGE : ");
	scanf("%d",&M1.age);
	printf("\n ENTER YOUR ADDRESS : ");
	scanf("%s",&M1.address);
	printf("\n ENTER YOUR CONTACT NUMBER :");
	scanf("%d",&M1.phoneno);
	printf("\n\n ######MEMBER ADDED SUCCESSFULLY#######");
	
 	char ch;
	int c,word,cho;
	c=offer();
	
	if(c==8)
	  menu();
	   else if(c==9)
	     exit(0);
	      else
	        print_offer(c);

}

void menu()
{

    int beauty[50],sum[20];
    int t_sum=0,i,time;
    int cho;
	printf("\n##### MENU #####");
	printf("\n1. Hair cut \t\t\t @ 150\n2. Hair cut with conditioning \t @ 200\n3. Threading \t\t\t @ 50");
	printf("\n4. Waxing (only hand) \t\t @ 200\n5. Waxing(full legs and hands) \t @ 500");
	printf("\n6. Fruit Facial \t\t @ 550\n7. Facial with Bleach \t\t @ 699\n8. Bleach \t\t\t @ 350");
	printf("\n9. Manicure \t\t\t @ 499\n10.Pedicure \t\t\t @ 499");
	
	printf("\n\n How many treatments do you want to choose (utmost 4)");
	printf("\n\n1. Only 1\n2. Only 2\n3. Only 3\n4. Only 4\n");
	printf("\n\nEnter your choice : ");
	scanf("%d",&cho);
	
	if(cho==1)     // if user enters only 1 choice
	{
	    printf("\n\nEnter your favourite beauty treatment : ");
     	for(int i=0;i<cho;i++)
    	scanf("\n%d",&beauty[i]);
    display_treatments(beauty,cho);    
	timeslot_nonmember();	
	total_amount(beauty,cho);
   }
  
  
  else if(cho==2)             // if user enters 2 choices
  {
  	printf("\n\n Enter any beauty treatment of your choice : ");
  	for(int i=0;i<cho;i++)
	scanf("\n%d",&beauty[i]);
    display_treatments(beauty,cho); 
	timeslot_nonmember();	
	total_amount(beauty,cho);
  }
  
  else if(cho==3)       // if user enters 3 choices 
  {

  	printf("\n\nEnter any beauty treatment of your choice : ");
  	for(int i=0;i<cho;i++)
   	scanf("\n%d",&beauty[i]);
     
    display_treatments(beauty,cho); 
   	timeslot_nonmember();	
	total_amount(beauty,cho);
  }
  
  else if(cho==4)                // if user enters 4 choices
  {
  	printf("\n\nEnter any beauty treatment of your choice : ");
  	for(int i=0;i<cho;i++)
    scanf("\n%d",&beauty[i]);
	
	display_treatments(beauty,cho); 	
	timeslot_nonmember();	
	total_amount(beauty,cho);
  }   

}

void nonmember()  
{
	menu();
 }

//FOR BOOKING THE TIME SLOT
void timeslot()
{       
        int time;
   	    printf("\n\n TIME SLOT ");
		printf("\n1. 12pm to 2pm \n2. 2pm to 4pm \n3. 4pm to 6pm \n4. 6pm to 8pm");
		printf("\n\n Enter your preffered time slot : ");
		scanf("%d",&time);
		
		if(time==1)
		 printf("\n You have booked from 12pm to 2pm ");
		
		if(time==2)
		 printf("\n You have booked from 2pm to 4pm ");
		
		if(time==3)
	     printf("\n You have booked from 4pm to 6pm ");
	    
		if(time==4)
	     printf("\n You have booked from 6pm to 8pm ");
		 
		printf("\n\n$$ THANK YOU FOR BOOKING WITH US $$");
 }
 
 int offer()
{
        int d;	
        printf("\nTHE VARIOUS OFFERS AVAILABLE");
		printf("\n## 1.LADIES SPECIAL SUMMER PACKAGE @ JUST 3999 ##");
		printf("\n1. Anti-Tan pedicure \n2.Facial\n3.Waxing full arms\n4.Face detan\n5.Threading\n6.Hair cut");
		printf("\n\n\n## 2.SUMMER SAUNA @ JUST 4999 ##");
		printf("\n1.Gold facial\n2.Anti tan pedicure\n3.Anti tan manicure\n4.Hair spa\n5.Waxing\n6.Hair trim and blow dry\n");
		printf("\n\n\n## 3. CLEANUP WAXING AND THREADING @ JUST 899");
		printf("\n\n\n## 4. FACE DETAN COLOUR TOUCH UP AND THREADING @ JUST 999");
		printf("\n\n\n## 5. PEDICURE MANICURE AND DEEP CONDITIONING @JUST 799");
		printf("\n\n\n## 6. PEDICURE MANICURE AND BASIC HAIRCUT @ JUST 699");
		printf("\n\n\n## 7. FRUIT FACIAL BLEACH AND HAND WAXING @ JUST 899");
        printf("\n\n\n## 8. TO GO TO THE MENU PAGE");
        printf("\n\n\n## 9. TO EXIT ");
		printf("\n\n\nPlease Enter the package as per your choice : ");
		scanf("%d",&d);
        if((d!=8)&&(d!=9))
        timeslot();
        return d;
}

void print_offer(int c)
{
	    printf("\nYou have succesfully booked the following package : ");
		if(c==1)
		{
				printf("\n\n## 1.LADIES SPECIAL SUMMER PACKAGE @ JUST 3999 ##");
	         	printf("\n1. Anti-Tan pedicure \n2.Facial\n3.Waxing full arms\n4.Face detan\n5.Threading\6.Hir cut");
		}
		else if(c==2)
		{
			printf("\n\n\n## 2.SUMMER SAUNA @ JUST 4999 ##");
		    printf("\n1.Gold facial\n2.Anti tan pedicure\n3.Anti tan manicure\n4.Hair spa\n5.Waxing\n6.Hair trim and blow dry\n");
		}
		else if(c==3)
		printf("\n\n\n## 3. Cleanup Waxing and Threading @ JUST 899");	
		
		else if(c==4)
		printf("\n\n\n## 4. Face detan Colour touch up and Threading @ JUST 999");	
		
		else if(c==5)
		printf("\n\n\n## 5. Pedicure Manicure and Deep Conditioning @JUST 799");	
	
		else if(c==6)
	   	printf("\n\n\n## 6. Pedicure Manicure and Basic Haircut @ JUST 699");	
		
		else if(c==7)
		printf("\n\n\n## 7. Fruit facial Bleach and Hand Waxing @ JUST 899");
        
        else
        {
        	bye();
        	exit(0);
		}
}

void total_amount(int beauty[50],int n) //FOR CALCULATING THE TOTAL AMOUNT
{   int sum[20];
    int t_sum=0,i;

	for(int i=0;i<n;i++) 
	{
		if(beauty[i]==1)
		  sum[i]=150;
		if(beauty[i]==2)
		  sum[i]=200;
		if(beauty[i]==3)
		  sum[i]=50;
		if(beauty[i]==4)
		  sum[i]=200;
		if(beauty[i]==5)
		  sum[i]=500;
		if(beauty[i]==6)
		  sum[i]=550;
		if(beauty[i]==7)
		  sum[i]=699;
		if(beauty[i]==8)
		  sum[i]=350;
		if(beauty[i]==9)
		  sum[i]=499;
		if(beauty[i]==10)
		  sum[i]=499;
		  
	t_sum=t_sum+sum[i];
	}
	printf("\n THE TOTAL AMOUNT TO BE PAID : %d", t_sum);
  }
  
void timeslot_nonmember()
 {      int time;
	 	printf("\n\n TIME SLOT ");
		printf("\n1. 10am to 11am \n2. 11am to 12pm \n3. 12pm to 1pm \n4. 1pm to 2pm \n5. 2pm to 3pm \n6. 3pm to 4pm");
		printf("\n\n Enter your preffered time slot : ");
		scanf("%d",&time);
		if(time==1)
		 printf("\n You have booked from 10am to 11am ");
		if(time==2)
		 printf("\n You have booked from 11am to 12pm ");
		if(time==3)
	     printf("\n You have booked from 12pm to 1pm ");
	    if(time==4)
	     printf("\n You have booked from 1pm to 2pm ");
	    if(time==5)
	     printf("\n You have booked from 2pm to 3pm ");
	    if(time==6)
	     printf("\n You have booked from 1pm to 2pm ");
}
	
void display_treatments(int beauty[50],int cho)
{
	
	printf("\n\nYou selected following treatments : ");
	  for(int i=0;i<cho;i++)
	  {
		if(beauty[i]==1)
		  printf("\n Hair cut");
		if(beauty[i]==2)
		  printf("\n Hair cut with conditioning");
		if(beauty[i]==3)
		  printf("\n Threading");
		if(beauty[i]==4)
		  printf("\n Waxing only hand");
		if(beauty[i]==5)
		  printf("\n Waxing full legs and hands");
		if(beauty[i]==6)
		  printf("\n Fruit facial");
		if(beauty[i]==7)
		  printf("\n Fruit facial with bleach");
		if(beauty[i]==8)
		  printf("\n Bleach");
		if(beauty[i]==9)
		  printf("\n Manicure");
		if(beauty[i]==10)
		  printf("\n Pedicure");
    	}
}

 void bye()
 { 
 printf("/n/n THANK YOU FOR VISITING US, HOPE TO SEE YOU AGAIN");
 }

void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
 
void employee_data()
{
    FILE *fp, *ft;   //FILE POINTERS
    char another,choice;
  
    //STRUCTURE SHOWING THE DETAILS OF THE EMPLOYEES
    struct emp
	{
        char name[40];     //NAME OF THE EMPLOYEE
        int age;           //AGE OF THE EMPLOYEE
        float bs;          //BASIC SALALRY OF THE EMPLOYEE
    }e;
    
    char empname[40]; 
    long int recsize; 
    
    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL)
	{
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL)
		{
            printf("CANNOT OPEN FILE");
            exit(1);
        }
    }
    recsize = sizeof(e);
    while(1)
	{
        printf("\n 1. ADD RECORDS");    
        printf("\n 2. LIST RECORDS");   
        printf("\n 3. MODIFY RECORDS"); 
        printf("\n 4. DELETE RECORDS"); 
        printf("\n 5. EXIT");            
        printf("\n ENTER YOUR CHOICE: "); 
        fflush(stdin); 
        scanf("\n %c", &choice); 
        
		switch(choice)
		{
            case '1':   fseek(fp,0,SEEK_END); 
                        another = 'y';
                        while(another == 'y')
						{ 
                           flush();
                           printf("\nENTER NAME: ");
                           fgets(e.name, 40, stdin);
                           printf("\nENTER AGE : ");
                           scanf("%d", &e.age);
                           printf("\nENTER BASIC SALARY : ");
                           scanf("%f", &e.bs);
                           fwrite(&e,recsize,1,fp); 
                           printf("\nDO YOU WANT TO ADD ANOTHER RECORD (y/n) ");
                           fflush(stdin);
                           scanf("\n%c", &another);
                        }
                        break;
            
			case '2':  rewind(fp); 
                       while(fread(&e,recsize,1,fp)==1)
					   { 
                          printf("NAME OF THE EMPLOYEE %s\n AGE OF THE EMPLOYEE %d\n BASIC SALARY OF THE EMPLOYEE %.2f\n",e.name,e.age,e.bs); 
                       }    
                        break;
  
            case '3':   another = 'y';
                        while(another == 'y')
						{
                          printf("ENTER THE EMPLOYEE NAME TO MODIFY: ");
                          scanf("%s", empname);
                          rewind(fp);
                          while(fread(&e,recsize,1,fp)==1)
						  { 
                            if(strcmp(e.name,empname) == 0)
							{
                            printf("\nENTER THE NEW NAME, AGE AND BASIC SALARY : ");
                            scanf("%s %d %f",e.name,&e.age,&e.bs);
                            fseek(fp,-recsize,SEEK_CUR); 
                            fwrite(&e,recsize,1,fp); 
                            break;
                          }
                        }
                        printf("\nTO MODIFY ANOTHER RECORD (y/n)");
                        fflush(stdin);
                        scanf("\n %c", &another);
                        }
                       break;

            case '4':  another = 'y';
                       while(another == 'y')
					   { 
					    flush();
                        printf("\nENTER THE NAME OF THE EMPLOYEE TO DELETE : ");
                        fgets(empname,40, stdin);
                        ft = fopen("Temp.dat","wb");  
                        rewind(fp); 
                        while(fread(&e,recsize,1,fp) == 1)
						{ 
                        if(strcmp(e.name,empname) != 0)
                            fwrite(&e,recsize,1,ft); 
                        }   
                        fclose(fp);
                        fclose(ft);
                        remove("EMP.DAT"); 
                        rename("Temp.dat","EMP.DAT"); 
                        fp = fopen("EMP.DAT", "rb+");
                        printf("TO DELETE ANOTHER RECORD (y/n)");
                        fflush(stdin);
                        scanf("\n %c", &another);
                       }  
                       break;
                
            case '5': fclose(fp);
                      exit(0); 
        }
    }
}

void member_data()
{
	char another;
	long int resize;
	FILE *ft;
	FILE *fp =fopen("MEMBER.DAT", "rb+");
    if(fp == NULL)
	{
        fp = fopen("MEMBER.DAT","wb+");
        if(fp == NULL)
		{
            printf("CANNOT OPEN FILE");
            exit(1);
        }
    }
	
long int recsize; 

int choice;
while(1)
{

 printf("\n\nENTER 1. TO WRITE DATA IN THE FILE");
 printf("\n\nENTER 2. TO DISPLAY THE CONTENTS OF THE FILE");
 printf("\n\nENTER 3. TO DELETE A RECORD FROM THE FILE");
 printf("\n\nENTER 4. TO MODIFY A RECORD");
 printf("\n\nENTER 5. TO EXIT");
 scanf("%d",&choice);

 if(choice==1)
 {
 	resize = sizeof(M1);
    fseek(fp,0,SEEK_END); 
    another = 'y';
    while(another == 'y')
	{ 
     printf("\n \n ENTER THE CONTENTS IN THE FILE");
	 printf("\n \n THE NAME OF THE MEMBER : ");
	 scanf("%s",&M1.name);
	 printf("\n\n THE MEMBERSHIP NUMBER OF THE MEMBER : ");
	 scanf("%d",&M1.membership_no);
	 printf("\n \n THE AGE OF THE MEMBER : ");
	 scanf("%d",&M1.age);
	 printf("\n \n THE PHONE NUMBER OF THE MEMBER : ");
	 scanf("%d",&M1.phoneno);
	 printf("\n \n THE ADDRESS OF THE MEMBER : ");
	 scanf("%s",&M1.address); 
     fwrite(&M1,resize,1,fp); 
     printf("\nDO YOU WANT TO ADD ANOTHER RECORD (y/n) ");
     fflush(stdin);
     scanf("\n%c", &another);
    }
}
 
 else if(choice==2)
 {
   rewind(fp); 
   while(fread(&M1,resize,1,fp)==1)
   { 
     printf("\n NAME OF THE MEMBER %s\n AGE OF THE MEMBER %d\n MEMBERSHIP NUMBER OF THE MEMBER %d\n",M1.name,M1.age,M1.membership_no);
	 printf("\n PHONE NUMBER OF THE MEMBER %d \n ADDRESS OF THE MEMBER %s ",M1.phoneno,M1.address); 
   }
}

else if(choice==3)
{
    char memname[20];
	another = 'y';
    while(another == 'y')
   { 
     
     printf("\nENTER THE NAME OF THE MEMBER TO DELETE : ");
     scanf("%s",&memname);
     ft = fopen("Temp.DAT","wb");  
     rewind(fp); 
     while(fread(&M1,resize,1,fp) == 1)
	{ 
       if(strcmp(M1.name,memname) != 0)
        fwrite(&M1,recsize,1,ft); 
	}   
    fclose(fp);
    fclose(ft);
    remove("MEMBER.DAT"); 
    rename("Temp.txt","MEMBER.DAT"); 
    fp = fopen("MEMBER.DAT", "rb+");
    printf("TO DELETE ANOTHER RECORD (y/n)");
    fflush(stdin);
    scanf("\n %c", &another);
    } 
	 
}

else if(choice==4)
{
   char memname[20];
   another = 'y';
   while(another == 'y')
  {
    printf("ENTER THE MEMBER NAME TO MODIFY: ");
    scanf("%s", memname);
    rewind(fp);
    while(fread(&M1,resize,1,fp)==1)
	{ 
      if(strcmp(M1.name,memname) == 0)
       {
         printf("\n\nENTER THE NEW DATA");
		 printf("\n\n THE NAME OF THE MEMBER : ");
	     scanf("%s",&M1.name);
	     printf("\n\n THE MEMBERSHIP NUMBER OF THE MEMBER : ");
	     scanf("%d",&M1.membership_no);
	     printf("\n\n THE AGE OF THE MEMBER : ");
	     scanf("%d",&M1.age);
	     printf("\n\n THE PHONE NUMBER OF THE MEMBER : ");
	     scanf("%d",&M1.phoneno);
	     printf("\n\n THE ADDRESS OF THE MEMBER : ");
	     scanf("%s",&M1.address); 
         fseek(fp,-resize,SEEK_CUR); 
         fwrite(&M1,resize,1,fp); 
        }
    }
    printf("\nTO MODIFY ANOTHER RECORD (y/n)");
    fflush(stdin);
    scanf("\n %c", &another);
 }
}
else if(choice==5)
       exit(0);

}
fclose(fp);
}





















