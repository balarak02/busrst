#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
char ch[10][130]={"CHN-BLR Express","CHN - HYD Express","CHN-VIZAG Express","CHN-KOCHIN Express","CHN-PDY Express","CHN-CJB Express"};
char name[32][100]={'\0'}; //contain the passenger details..//
char number[32][2]={'\0'};
int num1[32]={0};
int trno;
void bus();//for list of bus
void name_number(int booking,char numstr[100]);
void booking();//for booking the tickets
int read_number(int trno);//for reading the number from the file
void read_name(int trno);//for reading the name from the file
void status();//for printing the status by user input
void status_1(int trno);//for printing the status while booking ticket
void cancle();
void login();
int main()
{
    login();
    int num,i;
    do{
    system("cls"); //to clear the screen//
    printf("\n\n\n");
   printf("====================================== WELCOME TO BUS ESERVATION SYSTEM ======================================\n\n\n");
    printf("\t\t\t\t\t[1]=> View Bus List\n");
    printf("\n");
    printf("\t\t\t\t\t[2]=> Book Tickets\n");
    printf("\n");
    printf("\t\t\t\t\t[3]=> Cancel Booking\n");
    printf("\n");
    printf("\t\t\t\t\t[4]=> Bus Status Board\n");
    printf("\n");
    printf("\t\t\t\t\t[5]=> Exit\n\n");
    printf("===============================================================================================================\n\n");
    printf("\t\t\tEnter Your Choice:: ");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        bus();//for list of bus//
        break;
    case 2:
        booking();//for booking the tickets//
        break;
    case 3:
        cancle(); //to cancel the booking//
        break;
    case 4:
        status(); //to view the status//
        break;
    }
getch();
    }while(num != 5);
    system("CLS"); //is to clear the scrren//
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    getch();
    return 0;
}


void bus()  //to view all the busses and their name //
{
    printf("\n\n\n");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s\n",ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n",ch[1]);
    printf("\n");
    printf("\t\t\t\t\t[3]  =>  %s\n",ch[2]);
    printf("\n");
    printf("\t\t\t\t\t[4]  =>  %s\n",ch[3]);
    printf("\n");
    printf("\t\t\t\t\t[5]  =>  %s\n",ch[4]);
}

void booking()  //to make the booking//
{

    int i=0;
    char numstr[100];
system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for entering train number
bus();//calling the bus function to give details about all the busses//
printf("Enter the Bus number:--->");
scanf("%d",&trno);
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for selecting coach
printf("Your Bus Number is %d ********** %s",trno,ch[trno-1]); //to give the selectd bus no and it's details//
status_1(trno); //status of seats in each busses//
 FILE *f1, *fopen();//for reading the seats from the user.
 char str1[80]="32",str2[4],str3[4];
 int seat1,seat2,booking=0;
if(trno == 1)  //taking the bus seating details based in the bus no and storing it in the  str1 and it will be in the string//
{
 f1 = fopen("tr1.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(trno == 2)
{
 f1 = fopen("tr2.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(trno == 3)
{
 f1 = fopen("tr3.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
seat1=atoi(str1); //covert the string into number//
if(seat1 <= 0)
{
 printf("There is no blank seat in this bus ");
}else
{
printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n",seat1);
printf("\n\t\t\t\tNumber of Tickets:-----> (max 5 at a time)"); //asking the users no of tickets to book//
scanf("%d",&booking);
printf("\n");

seat1=seat1-booking; //reducing the no of seats in the bus//
itoa(trno,numstr,10);
name_number(booking,numstr);
printf("\n\t\t\t\tThe Total booking amount is %d",200*booking);  //giving the total cost//
itoa(seat1, str1, 10);              // convert the no of seats which is in the integer to string//

//for reading the seats from the user.
if(trno == 1)
{
 f1 = fopen("tr1.txt","w");
 fputs(str1,f1);               //changing the value of no of seats in file//
 fclose(f1);
}
else if(trno == 2)
{
 f1 = fopen("tr2.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 3)
{
 f1 = fopen("tr3.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
}
}
void name_number(int booking,char numstr[100]) //booking will have to no of tickets//
{
char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
int number;
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");  //append /txt to numstr which contain the bus file of the bus//
   strcat(tempstr1,numstr);  //append the numstr value ie the value of the file of the bus to the tempstr1 file//
   strcat(tempstr2,numstr);  // similar to previous one//
   a = fopen(tempstr1,"a");//for open the file to write the name in the file//
   b = fopen(tempstr2,"a");//for open the file for writing the number in the file//
for(i=0; i<booking; i++)//for entering the person name and seat number in the file//
{
    printf("============================Enter the details for ticket no %d============================\n\n\n",i+1);
      printf("\t\t\t\tEnter the seat number:--->");
      scanf("%d",&number);
      printf("\t\t\t\tEnter the name of person:--->");
      scanf("%s",name[number-1]);
    printf("\n======================================================================================================\n\n");
    printf("\n");
      itoa(number, tempstr, 10);
      fprintf(a,"%s ",name[number-1]);
      fprintf(b,"%s ",tempstr);

}
fclose(a);
fclose(b);
}



int read_number(int trno)  //for reading the seatnumbers and storing it in the array//
{
char tempstr[100],tempstr2[12]="number";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
itoa(trno, numstr, 10); // chaging the trno to string and string it in the numstr//
strcat(numstr, ".txt"); // appending it with .txt for eg it is in 5.txt//
strcat(tempstr2, numstr); // eg number5.txt//
a = fopen(tempstr2,"a+");//for open the file to write the name in the file//
while(!feof(a)) //to read all the booked seat numbers for a particular bus no and it details//
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++) //since everything is in string it is being converted to integer and stored in num1 array //
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}

void read_name(int trno) // this function opens a file associated with a specific bus, reads the passenger names from the file, stores them in the name array//
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");//for open the file to write the name in the file
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}

void status()   //to see all the bus details not the particular bus//
{
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i,trno,index=0,j;
    printf("Enter the number of bus:---->");
    scanf("%d",&trno);
    j=read_number(trno);   //reading the seat details from the bus num1 cintains the seat details //
    read_name(trno);  //raeding the bus booking name details name contains the name details//
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no-->%d---->%s                                                            \n",trno,ch[trno-1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]); //cpoying the values of names to the particular pos in tempname //
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);  //printing the seat number and name of the seat owner//
        index++;
            }
            printf("\n");
    }
}

void status_1(int trno)  //to see for the particular bus mainly used in the cancel function//
{
    printf("Your Bus Number is %d ********** %s",trno,ch[trno-1]);
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i,index=0,j;
    j=read_number(trno);
    read_name(trno);
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
}
}
void cancle()
{
 int seat_no,i,j;
 char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
 printf("Enter the bus number:---->");
 scanf("%d",&trno);
 itoa(trno,numstr,10); //chaging the trno to string and string it in the numstr//
 strcat(numstr,".txt");  //appending it with .txt for eg it is in 5.txt//
 strcat(tempstr1,numstr);  //appending the value of the numstr for eg: status5.txt//
 strcat(tempstr2,numstr);  //eg number5.txt//
 read_number(trno); //reading the seat details and storing in num1//
 read_name(trno);  //reading the booking details//
 status_1(trno);  //reading the status//
 printf("Enter the seat number:--->");
 scanf("%d",&seat_no);
 FILE *a,*b;
 a = fopen(tempstr1,"w+"); //a wiill open status5.txt//
 b = fopen(tempstr2,"w+"); //b will open number5.txt//
 for(i=0; i<32; i++)
 {
     if(num1[i] == seat_no) //here it will iterate find the seatnumber to delete//
     {
         for(j=0; j<32; j++)  //it will iterate again to find match seat//
         {
             if(num1[j] != seat_no && num1[j] != 0) //if it is not the same the num1 value will go to b and name will go to it own a//
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",name[j]);
             }
             else if(num1[j] == seat_no && num1[j] != 0) //if it same it the name array will be changed to empty//
             {
                 strcpy(name[j],"Empty ");
             }
         }
     }
 }
fclose(a);
fclose(b);
printf("\n\n");
    printf("======================================================================================================\n");
 printf("\t\t\t\t Your refund amount will be credited to your account  within 3-5 bussiness days\t\t\t\n");
    printf("======================================================================================================\n");
}
void login()
{
    int attempts = 0;
    char username[10];
    char password[10];

    printf("========================= LOGIN FORM =========================\n");

    while (attempts < 2)
    {
        printf("Enter USERNAME: ");
        scanf("%s", username);

        printf("Enter PASSWORD: ");
        scanf("%s", password);

        if (strcmp(username, "user") == 0 && strcmp(password, "pass") == 0)
        {
            printf("\nWELCOME TO OUR BUS RESERVATION SYSTEM! LOGIN IS SUCCESSFUL\n");
            printf("Press any key to continue...");
            getch(); // Holds the screen
            return;
        }
        else
        {
            attempts++;
            printf("\nSORRY! LOGIN IS UNSUCCESSFUL\n");
            printf("Remaining attempts: %d\n", 2 - attempts);
            getch();       // Holds the screen
            system("cls"); // Clear the screen for the next login attempt
        }
    }

    printf("\nSorry, you have exceeded the maximum number of login attempts.\n");
    printf("Press any key to exit...");
    getch(); // Holds the screen
    exit(0); // Exit the program
}