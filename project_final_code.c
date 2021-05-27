//program to create a library management system for our college
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct library//main stucture
{
	char bk_name[30];
	char author[30];
	int sem;
	int id;//unique book id
};
struct date
{
	int dd,mm,yy;
};
struct issue//structure to hold issued book details
{
	char bk_name[30];
	char author[30];
	int id;
	int sem;
	char srn[30];//srn of student who borrowed the book
	struct date issue_date;
};
struct issue i[100] = {0};
struct returnb//structure to hold returned book details
{
	int id;
	int sem;
	char srn[30];
	struct date return_date;
};
struct returnb r[100];	
	
struct library l[100] = {0};//array of structure object
int count_library=0;
int count_issue=0;
int count_return=0;
int n;
int day,month,year = 0;
int due_day;
int due_month;
int due_year;
void add_book()//function to add n number of books to the library
{
printf("enter number of books to be added");
scanf("%d",&n);
for (int i=0;i<n;i++)
{
	printf ("Enter book name = ");
	scanf ("%s",&l[count_library].bk_name);
	printf ("Enter author name = ");
	scanf ("%s",&l[count_library].author);
	printf ("Enter semester = ");
	scanf ("%d",&l[count_library].sem);
	printf ("Enter id = ");
	scanf ("%d",&l[count_library].id);
	count_library++;
}
}
void view_book()//function to view book details
{ 
  int uid,chk=0;
  printf("Please enter unique id of the book you want to view");
  scanf("%d",&uid);
  for(int i=0;i<count_library;i++)
  {
    if(l[i].id==uid)
      {
        printf("The book details are:\n");
        printf("Book name:%s\n",l[i].bk_name);
        printf("Author name:%s\n",l[i].author);
        printf("Sem:%d\n",l[i].sem);
	chk++;
      }
  } 
  if(chk==0)
	printf("Invalid id OR Book has already been issued\n");  

}
void modify_book()//function to update book details
{ 
  int uid,chk=0;
  char nbook[20];
  char nauthor[20];
  int nsem=0;
  printf("Enter the ID of the book you wish to edit...\n");
  scanf("%d",&uid);
  getchar();
  for(int i=0;i<count_library;i++)
  {
    if(uid==l[i].id)
    {
      printf("Enter new book name\n");
      fgets(nbook,20,stdin);
      printf("Enter new author name\n");
      fgets(nauthor,20,stdin);
      printf("Enter new sem..\n");
      scanf("%d",&nsem);
      l[i].sem=nsem;
      strcpy(l[i].bk_name,nbook);
      strcpy(l[i].author,nauthor);
      printf("Updated book details are\n");
      printf("Book name:%s\n",l[i].bk_name);
      printf("Author name:%s\n",l[i].author);
      printf("Unique ID:%d\n",l[i].id);
      printf("Sem:%d\n",l[i].sem);
      chk++;

    }
    if(chk==0)
	printf("Book not found\n");  

  }

}
void issue_book()//function to issue book
{
	int temp_id,chk=0;
	printf("Enter id = ");
	scanf("%d",&temp_id);
	for(int j=0;j<100;j++)
	{
		if(temp_id==l[j].id)
		{
			printf("enter srn");
			scanf("%s",i[count_issue].srn); 
			i[count_issue].id=temp_id;//code to add book details to issue library
			i[count_issue].sem=l[j].sem;
			strcpy(i[count_issue].bk_name,l[j].bk_name);
			strcpy(i[count_issue].author,l[j].author); 
			printf("enter issue date");
			scanf("%d%d%d",&i[count_issue].issue_date.dd,&i[count_issue].issue_date.mm,&i[count_issue].issue_date.yy);
			for(int k=j;k<count_library;k++)
			{
				strcpy(l[k].bk_name,l[k+1].bk_name);//code to delete book details from main library
				strcpy(l[k].author,l[k+1].author);
				l[k].id=l[k+1].id;
				l[k].sem=l[k+1].sem;
			}
			day=i[count_issue].issue_date.dd;
			month=i[count_issue].issue_date.mm;
			year=i[count_issue].issue_date.yy;
			count_issue++;
			count_library--;
			due_date();
			chk++;
			break;
		}
		
	}
	if(chk==0)
		printf("Book not available");
}

void fine()//function to calculate fine 
{
	int days_after_due_date=0,fine=0;
	printf("enter number of days after due date ");
	scanf("%d",&days_after_due_date);
	if(days_after_due_date==0)
		fine=0;
	if (days_after_due_date>=30)//beyond 30 days student is blacklisted
	{
		printf("Blacklisted\n");
		fine=5*5+10*10+20*15+(days_after_due_date-30)*50;//fine for first five days is rupess 5
	}
	if(days_after_due_date<30 && days_after_due_date>=15)
		fine=5*5+10*10+20*(days_after_due_date-15);//fine for next 10 days is rupees 10
	if (days_after_due_date<15 && days_after_due_date>=5)
		fine=5*5+(days_after_due_date-5)*10;//fine for next 15 days is rupees 20
	if(days_after_due_date<5 && days_after_due_date!=0)
		fine=5*days_after_due_date;
	printf("Fine is=%d\n",fine);
}
		



void return_book()//function to return book
{
	int temp_id,chk=0;
	printf("Enter id = ");
	scanf("%d",&temp_id);
	for(int x=0;x<100;x++)
	{
		if(temp_id==i[x].id)
		{
			l[count_library].id=temp_id;//code to add book details to main library
			l[count_library].sem=i[x].sem;
			strcpy(l[count_library].bk_name,i[x].bk_name);
			strcpy(l[count_library].author,i[x].author);
			r[count_return].id=temp_id;//code to add book to return library
			r[count_return].sem=l[x].sem;
			printf("enter srn");
			scanf("%s",r[count_return].srn); 
			printf("enter return date");
			scanf("%d%d%d",&r[count_return].return_date.dd,&r[count_return].return_date.mm,&r[count_return].return_date.yy);
			fine();
      
      			for(int q=x;q<count_issue;q++)
			{
				strcpy(i[q].bk_name,i[q+1].bk_name);//code to delete book details from issue library
				strcpy(i[q].author,i[q+1].author);
				i[q].id=i[q+1].id;
				i[q].sem=i[q+1].sem;
			}
			count_library++;
			count_return++;
			chk++;
			break;
		}
		
	}
	if(chk==0)
		printf("Book not issued");
		
}
void due_date()//function to find due date
{
	int temp_id;
	printf("Enter id = ");
	scanf("%d",&temp_id);
	for(int y=0;y<100;y++)
	{
		if(temp_id==i[y].id)
		{
			printf("The date of issue is %d %d %d",day, month, year);
			if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10)//month with 31 days
			{
				if(day<18)
				{
					day=day+14;
			    	printf("\nThe due date is %d %d %d\n", day,month,year);
				}
				else
				{
					month=month+1;
					day=14-(31-day);
					printf("\nThe due date is %d %d %d\n", day,month,year);
				}
			}
			if(month==4 || month==6 || month==9 || month==11)//month has 30 days
			{
				if(day<17)
				{
					day=day+14;
					printf("\nThe due date is %d %d %d\n", day,month,year);
				}
				else
				{
					month=month+1;
					day=14-(30-day);
			    	printf("\nThe due date is %d %d %d\n", day,month,year);
				}
			}
			if(month==12)//month is december
			{
				if(day<18)
				{
					day=day+14;
		        	printf("\nThe due date is %d %d %d\n", day,month,year);
				}
				else
				{
					month=1;
					year=year+1;
					day=14-(31-day);
					printf("\nThe due date is %d %d %d\n", day,month,year);
				}
			}
			if(((year%4==0)&&(year%100!=0)) || (year%400==0))//year is leap year
			{
				if(month==2)
				{
					if(day<16)
					{
						day=day+14;
				    	printf("\nThe due date is %d %d %d\n", day,month,year);
					}
					else
					{
						month=month+1; 
						day=14-(29-day);
						printf("\nThe due date is %d %d %d\n", day,month,year);
					}
				}	
			}
			else
			{
				if(month==2)
				{
					if(day<15)
					{
						day=day+14;
						printf("\nThe due date is %d %d %d\n", day,month,year);
					}
					else
					{
						month=month+1; 
						day=14-(28-day);
						printf("\nThe due date is %d %d %d\n", day,month,year);
					}
				}
			}
		}	
	}
 due_day=day;
 due_month=month;
 due_year=year;

}
	
void view_borrowed()//to track which student has issued the book
{
	int uid=0;
	printf("enter ID of book whose borrower details are to be found");
	scanf("%d",&uid);
	for(int k=0;k<100;k++)
	{
		if(uid==i[k].id)
		{
			printf("borrower semester is %d\n",i[k].sem);
			printf("borrower srn is %s\n",i[k].srn);
		}
	}
}

void book_sort_sem()//view details of books of particular sem
{
	int temp_sem=0,chk=0;
	printf("enter sem");
	scanf("%d",&temp_sem);
	for(int k=0;k<count_library;k++)
	{
		if(temp_sem==l[k].sem)
		{
			printf("Book name:%s\n",l[k].bk_name);
      			printf("Author name:%s\n",l[k].author);
      			printf("Unique ID:%d\n",l[k].id);
			chk++;
		}
		printf("\n");
		
	}
	if(chk==0)
		printf("Book not found\n");
}	

void book_sort_author()//view details of book of particular author
{
	char temp_author[50]={0};
	int chk=0;
	printf("enter Author");
	scanf("%s",&temp_author);
	for(int k=0;k<count_library;k++)
	{
		if(strcmp(l[k].author,temp_author)==0)
		{
			printf("Semester:%d\n",l[k].sem);
      			printf("Book name:%s\n",l[k].bk_name);
      			printf("Unique ID:%d\n",l[k].id);
			chk++;
		}
		printf("\n");
		
	}
	if(chk==0)
		printf("Book not found\n");
}	
		
void welcome_message()
{
        printf("\n\n\n\n\n");
        printf("\n\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
        printf("\n\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t        =                 WELCOME                   =");
        printf("\n\t        =                   TO                      =");
	printf("\n\t        =                   PES                     =");
        printf("\n\t        =                 LIBRARY                   =");
        printf("\n\t        =               MANAGEMENT                  =");
        printf("\n\t        =                 SYSTEM                    =");
        printf("\n\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
        printf("\n\n\n\t Enter any key to continue.....");
        getchar();
}		

void main()
{ int a;
  welcome_message();
  printf("Choose an option\n");
  do
  { 
	printf("1.Add Book\n2.Issue_book\n3.Return Book\n4.View Book\n5.Modify Book\n6.View borrower details\n7.Find all books of a particular sem\n8.Find all books of particular author\n9.Exit\n");      	
    	scanf("%d",&a);
    	switch (a)
    	{
    	case 1:add_book(); 
            	break;
    	case 2: issue_book();
            	break;
    	case 3: return_book();
            	break;
    	case 4: view_book();
            	break;
    	case 5: modify_book();
            	break;
    	case 6: view_borrowed();
	    	break;
    	case 7:book_sort_sem();
	    	break;
	case 8:book_sort_author();
		break;
    	default:printf("Exiting!");
      		break;
    }
    
  } while (a!=9);
}


