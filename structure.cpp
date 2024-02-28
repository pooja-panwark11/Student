#include <iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct student
{ int roll;
  char name[15];
  char add[30];
  char cl[6];
  int tmarks;
  char grade;
};
void create_rec();
void dline();
void disp_rec();
void search1(int);
void del_rec(int);
void modify_rec(student);
int main()
 {system("cls");
  int choice,rno;
  student rec;
  do
  {   system("cls");
      cout<<"\n     Menu";
      cout<<"\n1. Create new record";
      cout<<"\n2. Display record";
      cout<<"\n3. Search record";
      cout<<"\n4. Delete record";
      cout<<"\n5. Modify";
      cout<<"\n6. Exit";
      cout<<"\n\n Enter your choice(1-6):";
      cin>>choice;
    switch(choice)
    {   case 1:  create_rec();
		 getch();
		 break;
	case 2:  disp_rec();
		  getch();
		  break;
	case 3: cout<<"\n Roll no:";
		 cin>>rno;
		 search1(rno);
		 getch();
		 break;
	case 4: cout<<"\n enter roll no to delete:";
		cin>>rno;
		del_rec(rno);
		getch();
		break;
	case 5: cout<<"\nenter roll no:";cin>>rec.roll;
        fflush(stdin);
		cout<<"\n Enter name:";gets(rec.name);
        fflush(stdin);
		cout<<"\n enter address:";gets(rec.add);
        fflush(stdin);
		cout<<"\n enter class:";gets(rec.cl);
		cout<<"\n Enter marks:";cin>>rec.tmarks;
		cout<<"\n enter grade:";cin>>rec.grade;
		modify_rec(rec);
		getch();
		break;
     }
   }while(choice!=6);
   return 0;
}//endofmain
void create_rec()
{ int n;
  ofstream fout;
  fout.open("stud.dat",ios::app|ios::binary);
  student rec;
  cout<<"\n How many records:";cin>>n;
  for(int i=1;i<=n;i++)
  {
      cout<<"\nenter roll no:";cin>>rec.roll;
          fflush(stdin);
      cout<<"\n Enter name:";gets(rec.name);
          fflush(stdin);
      cout<<"\n enter address:";gets(rec.add);
          fflush(stdin);
      cout<<"\n enter class:";gets(rec.cl);
      cout<<"\n Enter marks:";cin>>rec.tmarks;
      cout<<"\n enter grade:";cin>>rec.grade;
      fout.write((char*)&rec,sizeof(rec));
  }
  fout.close();
  cout<<"\n Data successfuly entered";
}
void dline()
{
    cout<<'\n';
    for(int i=1;i<=40;i++)
        cout<<"=";
}
void disp_rec()
{ ifstream fin;
  fin.open("stud.dat",ios::binary);
  student rec;
  while(fin.read((char*)&rec,sizeof(rec)))
  {   dline();
      cout<<"\nroll no:"<<rec.roll;
      cout<<"\nname:"<<rec.name;
      cout<<"\naddress:"<<rec.add;
      cout<<"\nclass:"<<rec.cl;
      cout<<"\nmarks:"<<rec.tmarks;
      cout<<"\ngrade:"<<rec.grade;
  }
  fin.close();
}
void search1(int r)
{ student rec;
  int flag=0;
  ifstream fin;
  fin.open("stud.dat",ios::binary);
  while(fin.read((char*)&rec,sizeof(rec)))
  {  if(rec.roll==r)
     { dline();
      cout<<"\nroll no:"<<rec.roll;
      cout<<"\nname:"<<rec.name;
      cout<<"\naddress:"<<rec.add;
      cout<<"\nclass:"<<rec.cl;
      cout<<"\nmarks:"<<rec.tmarks;
      cout<<"\ngrade:"<<rec.grade;
      dline();
      flag=1;
     // break;
     }
  }
  
  
  fin.close();
}
void modify_rec(student nrec)
{   student rec;
    fstream fino;
    int flag=0,c=0;
    fino.open("stud.dat",ios::in|ios::out|ios::binary);
 while(fino.read((char*)&rec,sizeof(rec)))
  { c++;
    if(rec.roll==nrec.roll)
     { fino.seekp((c-1)*sizeof(rec),ios::beg);
       fino.write((char*)&nrec,sizeof(nrec));
       flag=1;
       cout<<"\n Record Modified successfully.";
      }
  }
  if(flag==0)
   cout<<"\n No such roll no exists.";
   fino.close();
}
void del_rec(int r)
{ student rec;
  int flag=0;
  ifstream fin;
  fin.open("stud.dat",ios::binary);
  ofstream fout;
  fout.open("temp.dat",ios::binary);
  while(fin.read((char*)&rec,sizeof(rec)))
  {  if(rec.roll!=r)
     {fout.write((char*)&rec,sizeof(rec));
     }
     else
      flag=1;
   }
   if(flag==0)
   cout<<"\n No such roll no exists.";
   else
   cout<<"\n Record deleted successfully.";
   fin.close();
   fout.close();
   remove("stud.dat");
   rename("temp.dat","stud.dat");
 }