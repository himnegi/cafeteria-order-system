#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#include<windows.h>

#define ANS 15
#define ACS 4

void gotoxy(int x,int y)
{COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
 struct owner
{
    char name[ANS],code[ACS];
    float rate;
    int quantity;
}item;
struct user{
    char uname[100],pname[100];
    int quant;
    float bill;
    float rate1;

    }item1;
void menu1();
void curser(int);
void d_mainmenu();
void window(int,int,int,int);
void login()
{
	int a=2,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{

    printf("\n------------ LOGIN FORM  ---------------   ");
    printf(" \n\n                  ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n\n                  ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';

	i=0;

    if(strcmp(uname,"1")==0 && strcmp(pword,"1")==0)
	{
	printf("  \n\n\n       WELCOME TO CAFETERIA ORDER SYSTEM !!!! LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();


	 d_mainmenu();}
	else
{   system("cls");
    printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
    printf("\n        attempt left %d\n",a);

if(a==0)
{   printf("\n        Reached max limt, exiting");
    exit(0);}
    a--;
    getch();//holds the screen

	}
}
	while(a<=2);


}
void window(int a,int b,int c,int d)
{
    int i;
    system("cls");
    gotoxy(20,10);

    for (i=1; i<=10; i++)
    printf("\xdb");
    printf(" WELCOME TO CAFOS");
    for (i=1; i<=10; i++)
    printf("\xdb");
    printf("\n\n");
    gotoxy(30,11);
    printf("CAFETERIA ORDER SYSTEM");
for (i=a; i<=b; i++)
    {
    gotoxy(i,17);
    printf("\xdb");
    gotoxy(i,19);
    printf("\xdb");
    gotoxy(i,c);
    printf("\xdb");
    gotoxy(i,d);
    printf("\xdb");
    }

    gotoxy(a,17);
    printf("\xdb");
    gotoxy(a,18);
    printf("\xdb");
    gotoxy(a,19);
    printf("\xdb");
    gotoxy(b,17);
    printf("\xdb");
    gotoxy(b,18);
    printf("\xdb");
    gotoxy(b,19);
    printf("\xdb");

for(i=c; i<=d; i++)
    {
    gotoxy(a,i);
    printf("\xdb");
    gotoxy(b,i);
    printf("\xdb");
    }
    gotoxy(a,c);
    printf("\xdb");
    gotoxy(a,d);
    printf("\xdb");
    gotoxy(b,c);
    printf("\xdb");
    gotoxy(b,d);
    printf("\xdb");

}

int main()
{
    main1();

    return 0;
}
void main1()
{
    window(25,50,20,28);
    gotoxy(33,18);
    printf("SELECT ANYONE");


    gotoxy(33,23);
    printf("ADMIN");
    gotoxy(33,24);
    printf("user");
    gotoxy(33,25);
    printf("exit");
    curser(3);

}

void d_mainmenu()
{
    int i;
    char ch;
    const char *menu[]= {"add item","remove item","record","previous page"};
    system("cls");

    window(25,55,20,32);
    gotoxy(33,18);
    printf("CAFE MENU");
for (i=0; i<=3; i++)
    {
    gotoxy(30,22+i+1);
    printf("%s\n\n\n",menu[i]);
    }
    cursor(4);
}

int user()
{

    window(25,50,20,40);
    gotoxy(30,23);
    printf("menu");
    gotoxy(30,24);
    printf("order");
    gotoxy(30,25);
    printf("search");
    gotoxy(30,26);
    printf("previous page");
    curser(4);
}
void cursor(int no)
{
    int count=1;
    char ch;
    gotoxy(30,23);

    while(1)
    {
        switch(ch)
        {
        case 80:
               count++;

                if (count==no+1) count=1;
                break;
        case 72:
                count--;
                if(count==0) count=no;
                break;
        }
    highlight(no,count);
    ch=getch();
    if(ch=='\r')
{
    if(no==4)
{
    if(count==1) edit();
    else if (count==2) del();
    else if (count==3) record();

    else
    main1();

        }
        }
        }
}
/*function for cursor movement*/
void curser(int no)
{
    int count=1;
    char ch;
    gotoxy(30,23);

    while(1)
    {
        switch(ch)
        {
        case 80:
            count++;

            if (count==no+1) count=1;
            break;
        case 72:
            count--;
            if(count==0) count=no;
            break;
        }
       high(no,count);
        ch=getch();
        if(ch=='\r')
        {

            if(no==3)
            {
                if(count==1)
                {system("cls");
                    login();}
                else if(count==2)
                user();
                else
                    {system("cls");
                    exit(0);}
            }
        if(no==4)
        {if(count==1)
        {
          menu1();
        }
          else if(count==2)
          {
             order();}
             else if(count==3)
             {
             search();}
             else
                {
                    main1();}

        }

        }
    }
}
void high(int no,int count)
{


    if(no==4)
    {
        switch(count)
        {
        case 1:
            gotoxy (30,23);
            printf("menu");
            break;
        case 2:
            gotoxy (30,24);
            printf("order");
            break;
        case 3:
            gotoxy (30,25);
            printf("search");
            break;
        case 4:
            gotoxy (30,26);
            printf("previous page");
            break;
       } }
        if(no==3)
        {switch(count)
         {

         case 1:
            gotoxy(33,23);
            printf("admin");
            break;
        case 2: gotoxy(33,24);
        printf("user");
        break;
        case 3:gotoxy(33,25);
            printf("exit");
            break;
        }}

}
void menu1()
{system("cls");
int c;
FILE *fp;
fp=fopen("file.txt","r");
if(fp==NULL)
{
    printf("cannot open file");
    exit(0);
}
printf("\t\titem code\t\tname\t\trate\t\t quantity available");

while(fread(&item,sizeof(item),1,fp))
{
printf("\n\n");

printf("\t\t%s\t\t%s\t\t%f\t\t%d",item.code,item.name,item.rate,item.quantity);

}

    fclose(fp);
getch();
user();
}


 void order()
 {system("cls");

 int flag;
  item1.bill=0;
     char code1[10];
  char ask[4];
 FILE *fp,*fc;
fp=fopen("file.txt","r");
if(fp==NULL)
{
    printf("cannot open file");
    exit(0);
}
 fc=fopen("record.txt","a+");


 if(fc==NULL)
  {printf("cannot open a file ");
 exit(0);}
printf("\nenter your name\n");
gets(item1.uname);


do{
        printf("enter PRODUCT ID or NAME to place an order\n");
 scanf("%s",code1);

while(fread(&item,sizeof(item),1,fp))
{if(strcmp(code1,item.code)==0)
{flag=1;

break;}

else if(strcmp(code1,item.name)==0)
    {flag=1;
break;}
else

    flag=0;
}

if(flag==1)
{   printf("item found..!!\n");
    printf("item rate=%f",item.rate);
   item1.rate1=item.rate;
    printf("\nquantity available=%d");
    printf("%d",item.quantity);
    printf("\nenter number of QUANTITY \n");
    scanf("%d",&item1.quant);

    if(item1.quant>item.quantity)
    {
    printf("such items are not available");
break;}

    strcpy(item1.pname,item.name);
    item1.bill=item1.bill+(item1.rate1*item1.quant);
fwrite(&item1,sizeof(item1),1,fc);


}else
{printf("\nitem not found...!!!");}

printf("\n do u want to continue....(yes/no)");
scanf("%s",ask);
rewind(fp);
}while(strcmp(ask,"yes")==0);
if(item1.bill==0)
{

}
else
{

printf("do u want t print a reciept \n");
scanf("%s",ask);
if(strcmp(ask,"yes")==0)
{


print(item1);
}
else
printf("total bill=%f",item1.bill);
}
fclose(fp);
fclose(fc);



getch();
user();
 }
 void print( struct user item1)
 {
     FILE *fp;
  char command[20];
 fp=fopen(item1.uname,"w");
 if(fp==NULL)
 {
     printf("cannt open a file");
     exit(0);
 }
 fprintf(fp,"  \nname=%s\n",item1.uname);
fprintf(fp,"    item name=%s\n",item1.pname);
fprintf(fp,"    quantity=%d\n",item1.quant);
fprintf(fp,"    total bill=%f\n",item1.bill);




fclose(fp);

     sprintf(command,"NOTEPAD  %s",item1.uname);
system(command);

 }
  void search()
  { system("cls");
      int flag;
      char name1[100];
  printf("enter name of PRODUCT or ID  to search a item\n");
  scanf("%s",&name1);
  FILE *fp;
fp=fopen("file.txt","r");
if(fp==NULL)
{
    printf("cannot open file");
    exit(0);
}
while(fread(&item,sizeof(item),1,fp))
{if(strcmp(name1,item.name)==0)
{flag=1;
break;}
else if(strcmp(name1,item.code)==0)
{
    flag=1;
    break;
}
else

flag=0;

}
if(flag ==1)
 {printf("\n\nItem found.....!!!!");
 printf("item name=%s",item.name);
 printf("\nRATE =%f",item.rate);
 }
 else
    printf("\n\nItem not found.....!!!1");
  fclose(fp);
getch();
user();
  }


void highlight(int no,int count)
{


    if(no==4)
    {
        switch(count)
        {
        case 1:
            gotoxy (30,23);
            printf("add item");
            break;
        case 2:
            gotoxy (30,24);
            printf("remove item ");
            break;
        case 3:
            gotoxy (30,25);
            printf("record ");
            break;
case 4:
            gotoxy (30,26);
            printf("previous page");

            break;
       } }
        if(no==3)
        {switch(count)
         {

         case 1:
            gotoxy(33,23);
            printf("admin");
            break;
        case 2: gotoxy(33,24);
        printf("user");
        break;
        case 3:gotoxy(33,25);
            printf("exit");
            break;
        }}

}
int record()
{ system("cls");
printf("\ncustomer name\t\t\titem name\t\t rate\t\t\t quantity \t\t\tbill");
printf("\n\n");
FILE *fd;
 fd=fopen("record.txt","r");
 if(fd==NULL)
  {printf("cannot open a file ");
 exit(0);
  }
 while(fread(&item1,sizeof(item1),1,fd))
 {
     printf("%s\t\t\t%s\t\t\t%0.2f\t\t\t%d\t\t\t%0.2f\n",item1.uname,item1.pname,item1.rate1,item1.quant,item1.bill);
 }
 getch();
 d_mainmenu();

 fclose(fd);}
void edit()
{ system("cls");
   char ch[10];
   char code1[100];
    FILE *fp,*fe;
fp=fopen("file.txt","a+");
if(fp==NULL)
{printf("file not found");
exit(0);}
do{
window(25,50,20,40);
gotoxy(30,23);
char code1[100];
    printf("enter item code\n");
gotoxy(30,24);
scanf("%s",&code1);

 int d=check(code1);

if(d==1)
{gotoxy(27,25);
    printf("id is already taken,");
    gotoxy(27,26);
    printf("provide another id");
   getch();
    edit();
}
else{
strcpy(item.code,code1);
gotoxy(30,25);
printf("enter product name\n");
gotoxy(30,26);
scanf("%s",&item.name);
gotoxy(30,27);
printf("enter price \n");
gotoxy(30,28);
scanf("%f",&item.rate);
 gotoxy(30,29);
 printf("enter quantity\n");
gotoxy(30,30);
 scanf("%d",&item.quantity);
 fwrite(&item,sizeof(item),1,fp);
 gotoxy(30,31);
}
//}
 printf("do u want to contniue");
 gotoxy(30,32);
 printf(",....(yes/no)");
 gotoxy(30,33);
 scanf("%s",ch);
}while(strcmp(ch,"yes")==0);
fclose(fp);
d_mainmenu();

}
int check(char *code1)
{int c;

FILE *fe;
fe=fopen("file.txt","r+");
if(fe==NULL)
{
printf("cannt open a file");
exit(0);
}
while(fread(&item,sizeof(item),1,fe))
{
    if(strcmp(item.code,code1)==0)

    {
        c=1;
        break;
    }
}
return c;


}

 void del()

 {  system("cls");

    int a;
     char ask[100];
     FILE *fp,*fc;
 fp=fopen("temp.txt","w+");
 if(fp==NULL)
{ printf("cannt open a file");
exit(0);}
 printf("enter item code, u wnat to delete");
 scanf( "%s",ask);
     fc=fopen("file.txt","r");
if(fc==NULL)
{ printf("cannt open a file");
exit(0);}
    while(fread(&item,sizeof(item),1,fc))
     { if(strcmp(ask,item.code)==0)
{printf("item name =%s",item.name);
printf("\n");
printf("item rate =%f",item.rate);
a=1;}
}
rewind(fc);
     while(fread(&item,sizeof(item),1,fc))
     { if(strcmp(ask,item.code)!=0)
     fwrite(&item,sizeof(item),1,fp);
}fclose(fp);
fclose(fc);
  fp=fopen("temp.txt","r");
    fc=fopen("file.txt","w+");
    while( fread(&item,sizeof(item),1,fp))
    {
    fwrite(&item,sizeof(item),1,fc);
    }if(a==1)
    {gotoxy(23,23);
        printf("item removed succefully");

}else
    {gotoxy(23,23);
        printf("item not found");}
 fclose(fp);
fclose(fc);
getch();
d_mainmenu();
 }
