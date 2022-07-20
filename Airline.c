#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
struct book{
char code[20];
char name[20];
char date[20];
char from[20];
char to[20];
int cost;
}b;
struct node
{
char *key;
struct node *left, *right;
};
int seat = 60 ;
void insert_details();
void viewAll();
void find();
void book_ticket();
void old_record();
int search();
struct node* insert();
struct node* newNode();
void inorder();
void records()
{
int n,pas,h,age,cpas,pno;
//clrscr();
char eid[30],cid[30],name[30],dob[20];
printf("1.Employee 2.Customer\n");
scanf("%d",&n);
if(n==1)
{
printf("Enter your Id and password\n");
fflush(stdin);
scanf("%s",eid);
scanf("%d",&pas);
if(eid[0]=='E'&&eid[1]=='M'&&strlen(eid)==7)
{
if(pas==123)
{
old_record();
}
else
{
printf("Invalid password\n");getch();
exit(0);
}
}
else
{
printf("Invalid Id"); getch();
exit(0);
}
}
else if(n==2)
{
a:
//clrscr();
printf("1.New Register 2.Registered user\n");
scanf("%d",&h);
if(h==1)
{
printf("Enter your Name,Age,Date of Birth,Passport number\n");
scanf("%s",name);
scanf("%d",age);
scanf("%s",dob);
scanf("%d",pno);
printf("Your Id is CUST123 and Password is 444\n");getch();
goto a;
}
else if(h==2)
{
printf("Enter your ID and password\n");
scanf("%s",cid);
scanf("%d",&cpas);
if(cid[0]=='C'&&cid[1]=='U'&&strlen(cid)==7)
{
if(cpas==444)
{
getch();
}
else
{
printf("Invalid password\n");getch();
exit(0);
}
}
else
{
printf("Invalid Id"); getch();
exit(0);
}
}
}
}
int main(){
int ch=5;
char ch2;
do
{
records();
do{
printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
printf("\n");
printf("\t Plane Ticket booking ");
printf("\n");
printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
printf("\nEnter >1< To Insert Ticket details");
printf("\nEnter >2< To View All Tickets");
printf("\nEnter >3< To Find Ticket ");
printf("\nEnter >4< To Book Tickets");
printf("\nEnter >5< To View All Transactions");
printf("\nEnter >0< To Exit ");
printf("\nEnter your Choice ::");
scanf("%d",&ch);
system("cls");
switch (ch)
{
case 1 :
insert_details();
break;
case 2:
viewAll();
break;
case 3:
find();
break;
case 4:
book_ticket();
break;
case 5:
old_record();
break;
case 0:
break;
default:
printf("Wrong choice !");
break;
}
}while(ch!=0);
printf("do you want to continue 'y/n'");
scanf("%c", &ch2);
}while(ch2=='y'||ch2=='Y');
}
void insert_details(){
FILE *fp;
struct book b;
printf("Enter flight code :- ");
scanf("%s",&b.code);
printf("Enter name :- ");
scanf("%s",&b.name);
printf("Enter Date:- ");
scanf("%s",&b.date);
printf("Enter the starting destination:-");
scanf("%s",&b.from);
printf("Enter the ending destination:-");
scanf("%s",&b.to);
printf("Enter Ticket Price:- ");
scanf("%d",&b.cost);
fp=fopen("data.txt","a");
if(fp == NULL){
printf("FIle not Found");
}
else{
fprintf(fp,"%s %s %s %s %s %d \n",b.code,b.name,b.date,b.from,b.to,b.cost);
printf("Recorded Successfully");
}
printf("\n");
fclose(fp);
system("cls");
}
void find(){
struct book b;
FILE *fp;
char ch[20];
printf("Enter ticket code :");
scanf("%s",ch);
fp = fopen("data.txt","r");
if(fp == NULL){
printf("file does not found !");
exit(1);
}
else{
while(getc(fp) != EOF){
fscanf(fp,"%s %s %s %s %s %d",b.code,b.name,b.date,b.from,b.to,&b.cost);
if(strcmp(b.code,ch) == 0){
printf("\n Record Found\n");
printf("\n\t\tCode ::%s",b.code);
printf("\n\t\tflight name ::%s",b.name);
printf("\n\t\tflight date ::%s",b.date);
printf("\n\t\tThe flight is from::%s",b.from);
printf("\n\t\tThe flight is to::%s",b.to);
printf("\n\t\tprice of ticket ::%d",b.cost);
}
}
}
fclose(fp);
}
void viewAll(){
char ch;
FILE *fp;
fp = fopen("data.txt","r");
if(fp == NULL){
printf("file does not found !");
exit(1);
}
else{
system("cls");
while( ( ch = fgetc(fp) ) != EOF )
printf("%c",ch);
}
fclose(fp);
}
struct node *newNode(char *item){
struct node *temp = (struct node *)malloc(sizeof(struct node));
temp->key = item;
temp->left = temp->right = NULL;
return temp;
}
void inorder(struct node *root)
{
if (root != NULL)
{
inorder(root->left);
inorder(root->right);
}
}
struct node* insert(struct node* node, char *key){
if (node == NULL) return newNode(key);
if (strcmp(key,node->key)<0)
node->left = insert(node->left, key);
else if (strcmp(key,node->key)>0)
node->right = insert(node->right, key);
return node;
}
int search(struct node *root, char *key1){
int i = 0;
while(root != NULL){
if (strcmp(key1,root->key)<0){
root = root -> left;
}
else if(strcmp(key1,root->key)>0){
root = root->right;
}
else{
i = 1;
return i;
}
}
return i;
}
void book_ticket(){
struct book b;
FILE *fp;
FILE *ufp;
int total_seat,mobile,total_amount;
int n = 0;
char name[20];
char ch;
char flight_code[20];
struct node *root = NULL;
root = insert(root, "f");
insert(root,"b");
insert(root,"c");
insert(root,"a");
inorder(root);
fp = fopen("data.txt","r");
if(fp == NULL){
printf("file does not found !");
exit(1);
}
else{
system("cls");
while( ( ch = fgetc(fp) ) != EOF )
printf("%c",ch);
}
fclose(fp);
printf("\n For Book ticket Choice Enter Ticket Code \n");
printf("\n Enter Ticket code :");
scanf("%s",flight_code);
fp = fopen("data.txt","r");
if(fp == NULL){
printf("file does not found !");
exit(1);
}
else{
while(getc(fp) != EOF){
fscanf(fp,"%s %s %s %s %s %d",b.code,b.name,b.date,b.from,b.to,&b.cost);
if(strcmp(b.code,flight_code) == 0){
printf("\n Record Found\n");
printf("\n\t\tCode ::%s",b.code);
printf("\n\t\tFlight name ::%s",b.name);
printf("\n\t\tDate name ::%s",b.date);
printf("\n\t\tFrom ::%s",b.from);
printf("\n\t\tTo ::%s",b.to);
printf("\n\t\tPrice of ticket::%d",b.cost);
}
}
}
printf("\n* Fill Details *");
printf("\n your name :");
scanf("%s",name);
printf("\n mobile number :");
scanf("%d",&mobile);
printf("\n Total number of tickets :");
scanf("%d",&total_seat);
n = search(root, name);
if(n == 1){
printf("user is not allowed in flight");
exit(1);
}
total_amount = b.cost * total_seat;
printf("\n ENJOY FLIGHT \n");
printf("\n\t\tName : %s",name);
printf("\n\t\tMobile Number : %d",mobile);
printf("\n\t\tFlight name : %s",b.name);
printf("\n\t\tTotal seats : %d",total_seat);
printf("\n\t\tCost per ticket : %d",b.cost);
printf("\n\t\tTotal Amount : %d",total_amount);
int i,j,a,d[50],sum=0,l,p,found,choice;
char m;
do{
found=0;
printf("\n\n**************seat allotment******************\n\n");
printf("w1 2 3 4 5 6w\n");
printf("w7 8 9 10 11 12w\n");
printf("w13 14 15 16 17 18w\n");
printf("if you want front row seat enter f \n");
printf("if you want middle seat enter m\n");
printf("if you want back seat enter b\n");
scanf("%s",&m);
switch(m){
case 'f':{
printf("if you want window seat :1 or normal :2 seat type anyone: ");
scanf("%d",&choice);
switch(choice){
case 1:{
printf("seat 1 and 6 is available type anyone ");
scanf("%d",&a);
if((a==1) || (a==6))
{
for (l=0;l<sum;l++)
{
if (d[l]==a)
{
found=1;
}
}
if (found==0)
{
printf("your window seat no %d boOked\n",a);
d[sum]=a;
sum++;
}
else if (found==1)
{
printf("This seat is already booked:\nChoose another one seat\n");
}
}
break;
}
case 2:
{
printf("seat 2,3,4 and 5 are availabe type anyone");
scanf("%d",&a);
if(a==2 || a==3 || a==4 || a==5)
{
for (l=0;l<sum;l++)
{
if (d[l]==a)
{
found=1;
}
}
if (found==0)
{
printf("your window seat no %d boOked\n",a);
d[sum]=a;
sum++;
}
else if (found==1)
{
printf("This seat is already booked:\nChoose another one seat");
}
}
break;
}
}
break;
}
case 'm':
{
printf("if you want window seat:1 or normal:2 seat type anyone: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
printf("seat 7 and 12 is available type anyone ");
scanf("%d",&a);
if(a==7 || a==12)
{
for (l=0;l<sum;l++)
{
if (d[l]==a)
{
found=1;
}
}
if (found==0)
{
printf("your window seat no %d booked\n",a);
d[sum]=a;
sum++;
}
else if (found==1)
{
printf("This seat is already booked:\nChoose another one seat");
}
}
break;
}
case 2:
{
printf("seat 8,9,10 and 11 are availabe type anyone ");
scanf("%d",&a);
if(a==8 || a==9 || a==10 || a==11)
{
for (l=0;l<sum;l++)
{
if (d[l]==a)
{
found=1;
}
}
if (found==0)
{
printf("your window seat no %d booked\n",a);
d[sum]=a;
sum++;
}
else if (found==1)
{
printf("This seat is already booked:\nChoose another one seat\n");
}
}
}
break;
}
break;
}
case 'b':
{
printf("if you want window seat:1 or normal seat:2 type anyone: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
printf("seat 13 and 18 is available type anyone ");
scanf("%d",&a);
if(a==13 || a==18)
{
for (l=0;l<sum;l++)
{
if (d[l]==a)
{
found=1;
}
}
if (found==0)
{
printf("your window seat no %d bocked\n",a);
d[sum]=a;
sum++;
}
else if (found==1)
{
printf("This seat is already booked:\nChoose another one seat\n");
}
}
break;
}
case 2:
{
printf("seat 14,15,16 and 17 are availabe type anyone");
scanf("%d",&a);
if(a==14 || a==15 || a==16 || a==17)
{
for (l=0;l<sum;l++)
{
if (d[l]==a)
{
found=1;
}
}
if (found==0)
{
printf("your window seat no %d bocked\n",a);
d[sum]=a;
sum++;
}
else if (found==1)
{
printf("This seat is already booked:\nChoose another one seat\n");
}
}
break;
}
}
break;
}
}
printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
printf("\n");
printf("\t Thank you for your booking ");
printf("\n");
printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
printf("\nIf another one man book this flight enter no 1 othewise enter no 2: ");
scanf("%d",&p);
printf("%d",p);
if (sum==18)
{
printf("\nAll of the seat was bocked");
}
}while(p==1 && sum!=18);
ufp=fopen("oldTransection.txt","a");
if(ufp == NULL){
printf("FIle not Found");
}
else{
fprintf(ufp,"%s %d %d %d %s %d \n",name,mobile,total_seat,total_amount,b.name,b.cost);
printf("\n Record insert Successful to the old record file");
}
printf("\n");
fclose(ufp);
fclose(fp);
}
void old_record(){
char ch;
FILE *fp;
fp = fopen("oldTransection.txt","r");
if(fp == NULL){
printf("file does not found !");
exit(1);
}
else{
system("cls");
while( ( ch = fgetc(fp) ) != EOF )
printf("%c",ch);
}
fclose(fp);
}
