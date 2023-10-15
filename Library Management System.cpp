//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<ctype.h>
#include<iomanip>
#include<iostream>

using namespace std;

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************


class book
{
	char bno[6];    // Book Number
	char bname[50]; // Book Name
	char aname[20]; // Author Name
  public:
	void create_book()
	{
	    int flag;
        cout<<"\nNEW BOOK ENTRY...\n";

        flag=0;
        do
        {
            cout<<"\nEnter The Book no :- ";
            fflush(stdin);
            gets(bno);
            int digit=0;
            int l=strlen(bno);
            if(l<=6)
            {
                for(int i=0;i<l;i++)
                {
                    if(isdigit(bno[i]))
                        digit++;
                }

                if(digit==l)
                    flag=1;
                else
                    cout<<"\nPlease check you entered something wrong.....\n";
            }
        }while(flag!=1);

        flag=0;
        do
        {
            cout<<"\nEnter the Book Name :- ";
            fflush(stdin);
            gets(bname);

            int space=0,alphabet=0;
            int l=strlen(bname);
            if(l<=20)
            {
                for(int i=0;i<l;i++)
                {
                    if(isalpha(bname[i]))
                        alphabet++;
                    else if(isspace(bname[i]))
                        space++;
                }

                if((alphabet==l-1 || alphabet==l) && (space==1 || space==0))
                    flag=1;
                else
                    cout<<"\nPlease check you entered something wrong.....\n";
            }
        }while(flag!=1);

        flag=0;
        do
        {
            cout<<"\nEnter the Book Author Name :- ";
            fflush(stdin);
            gets(aname);

            int space=0,alphabet=0;
            int l=strlen(aname);
            if(l<=20)
            {
                for(int i=0;i<l;i++)
                {
                    if(isalpha(aname[i]))
                        alphabet++;
                    else if(isspace(aname[i]))
                        space++;
                }

                if((alphabet==l-1 || alphabet==l) && (space==1 || space==0))
                    flag=1;
                else
                    cout<<"\nPlease check you entered something wrong.....\n";
            }
        }while(flag!=1);

        cout<<"\n\nBook Created..";
    }

    void show_book()
    {
        cout<<"\nBook no. : "<<bno;
        cout<<"\nBook Name : ";
        puts(bname);
        cout<<"Author Name : ";
        puts(aname);
    }

    void modify_book()
    {
        cout<<"\nBook no. : ";
        cin>>bno;
        cout<<"\nModify Book Name : ";
        fflush(stdin);
        gets(bname);
        cout<<"\nModify Author's Name of Book : ";
        fflush(stdin);
        gets(aname);
    }

    char* retbno()
    {
        return bno;
    }

    void report()
    {cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;}


};         //class ends here




class student
{
    char admno[6];  // Student Admission Number
    char name[20];  // Student Name
    char stbno[6];  // Student Book Number
    int token;      // Token
public:
    void create_student()
    {
        int flag=0;

        cout<<"\nNEW STUDENT ENTRY...\n";

        do
        {
            cout<<"\nEnter The admission no :- ";
            fflush(stdin);
            gets(admno);
            int digit=0;
            int l=strlen(admno);
            if(l<=6)
            {
                for(int i=0;i<l;i++)
                {
                    if(isdigit(admno[i]))
                        digit++;
                }

                if(digit==l)
                    flag=1;
                else
                    cout<<"\nPlease check you entered something wrong.....\n";
            }
        }while(flag!=1);

        flag=0;
        do
        {
            cout<<"\nEnter The Name of The Student :- ";
            fflush(stdin);
            gets(name);

            int space=0,alphabet=0;
            int l=strlen(name);
            if(l<=20)
            {
                for(int i=0;i<l;i++)
                {
                    if(isalpha(name[i]))
                        alphabet++;
                    else if(isspace(name[i]))
                        space++;
                }

                if((alphabet==l-1 || alphabet==l) && (space==1 || space==0))
                    flag=1;
                else
                    cout<<"\nPlease check you entered something wrong.....\n";
            }
        }while(flag!=1);

        token=0;
        stbno[0]='\0';
        cout<<"\n\nStudent Record Created..";
    }

    void show_student()
    {
        cout<<"\nAdmission no. : "<<admno;
        cout<<"\nStudent Name : "<<name;
        cout<<"\nNo of Book issued : "<<token;
        if(token==1)
            cout<<"\nBook No "<<stbno;
    }

    void modify_student()
    {
        cout<<"\nAdmission no. : ";
        cin>>admno;
        cout<<"\nModify Student Name : ";
        fflush(stdin);
        gets(name);
    }

    char* retadmno()
    {
        return admno;
    }

    char* retstbno()
    {
        return stbno;
    }

    int rettoken()
    {
        return token;
    }

    void addtoken()
    {token=1;}

    void resettoken()
    {token=0;}

    void getstbno(char t[])
    {
        strcpy(stbno,t);
    }

    void report()
    {cout<<"\t"<<admno<<setw(20)<<name<<setw(10)<<token<<endl;}

};         //class ends here




//***************************************************************
//        global declaration for stream object, object
//****************************************************************

fstream fp,fp1;
book bk;
student st;


//***************************************************************
//        function to write in file
//****************************************************************

void write_book()
{
    char ch;
    fp.open("book.dat",ios::out|ios::app);
    do
    {
        bk.create_book();
        fp.write((char*)&bk,sizeof(book));
        cout<<"\n\nDo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void write_student()
{
    char ch;
    fp.open("student.dat",ios::out|ios::app);
    do
    {
        st.create_student();
        fp.write((char*)&st,sizeof(student));
        cout<<"\n\ndo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}


//***************************************************************
//        function to read specific record from file
//****************************************************************


void display_spb(char n[])
{
    cout<<"\nBOOK DETAILS\n";
    int flag=0;
    fp.open("book.dat",ios::in);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmpi(bk.retbno(),n)==0)
        {
            bk.show_book();
             flag=1;
        }
    }

    fp.close();
    if(flag==0)
        cout<<"\n\nBook does not exist";
    getch();
}

void display_sps(char n[])
{
    cout<<"\nSTUDENT DETAILS\n";
    int flag=0;
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&st,sizeof(student)))
    {
        if((strcmpi(st.retadmno(),n)==0))
        {
            st.show_student();
            flag=1;
        }
    }

    fp.close();
    if(flag==0)
            cout<<"\n\nStudent does not exist";
     getch();
}


//***************************************************************
//        function to modify record of file
//****************************************************************


void modify_book()
{
    char n[6];
    int found=0,flag;

    cout<<"\n\n\tMODIFY BOOK REOCORD.... ";

    flag=0;
        do
        {
            cout<<"\n\nEnter The Book no. of the Book :- ";
            fflush(stdin);
            gets(n);
            int digit=0;
            int l=strlen(n);
            if(l<=6)
            {
                for(int i=0;i<l;i++)
                {
                    if(isdigit(n[i]))
                        digit++;
                }

                if(digit==l)
                    flag=1;
                else
                    cout<<"\nPlease check you entered something wrong.....\n";
            }
        }while(flag!=1);

    fp.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(book)) && found==0)
    {
        if(strcmpi(bk.retbno(),n)==0)
        {
            bk.show_book();
            cout<<"\nEnter The New Details of book"<<endl;
            bk.modify_book();
            int pos=-1*int(sizeof(bk));
                fp.seekp(pos,ios::cur);
                fp.write((char*)&bk,sizeof(book));
                cout<<"\n\n\t Record Updated";
                found=1;
        }
    }

        fp.close();
        if(found==0)
            cout<<"\n\n Record Not Found ";
        getch();
}


void modify_student()
{
    char n[6];
    int found=0,flag1=0;

    cout<<"\n\n\tMODIFY STUDENT RECORD... ";

    do
                    {
                        cout<<"\n\n\tEnter The admission no. of the Student You Want To Delete :- ";
                        fflush(stdin);
                        gets(n);
                        int digit=0;
                        int l=strlen(n);
                        if(l<=6)
                        {
                            for(int i=0;i<l;i++)
                            {
                                if(isdigit(n[i]))
                                    digit++;
                            }

                            if(digit==l)
                                flag1=1;
                            else
                                cout<<"\n\tPlease check you entered something wrong.....\n";
                        }
                    }while(flag1!=1);

    fp.open("student.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmpi(st.retadmno(),n)==0)
        {
            st.show_student();
            cout<<endl;
            cout<<"\nEnter The New Details of student"<<endl;
            st.modify_student();
            int pos=-1*int(sizeof(st));
            fp.seekp(pos,ios::cur);
            fp.write((char*)&st,sizeof(student));
            cout<<"\n\n\t Record Updated";
            found=1;
        }
    }

    fp.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
    getch();
}

//***************************************************************
//        function to delete record of file
//****************************************************************


void delete_student()
{
    char n[6];
    int flag=0,flag1=0;

        cout<<"\n\n\n\tDELETE STUDENT...";
                   do
                    {
                        cout<<"\n\n\tEnter The admission no. of the Student You Want To Delete :- ";
                        fflush(stdin);
                        gets(n);
                        int digit=0;
                        int l=strlen(n);
                        if(l<=6)
                        {
                            for(int i=0;i<l;i++)
                            {
                                if(isdigit(n[i]))
                                    digit++;
                            }

                            if(digit==l)
                                flag1=1;
                            else
                                cout<<"\n\tPlease check you entered something wrong.....\n";
                        }
                    }while(flag1!=1);

        fp.open("student.dat",ios::in|ios::out);
        fstream fp2;
        fp2.open("Temp.dat",ios::out);
        fp.seekg(0,ios::beg);
        while(fp.read((char*)&st,sizeof(student)))
    {
        if(strcmpi(st.retadmno(),n)!=0)
                 fp2.write((char*)&st,sizeof(student));
        else
               flag=1;
    }

    fp2.close();
        fp.close();
        remove("student.dat");
        rename("Temp.dat","student.dat");
        if(flag==1)
             cout<<"\n\n\tRecord Deleted ..";
        else
             cout<<"\n\nRecord not found";
        getch();
}


void delete_book()
{
    char n[6];
    int flag;

    cout<<"\n\n\n\tDELETE BOOK ...";

    flag=0;
        do
        {
            cout<<"\n\nEnter The Book no. of the Book :- ";
            fflush(stdin);
            gets(n);
            int digit=0;
            int l=strlen(n);
            if(l<=6)
            {
                for(int i=0;i<l;i++)
                {
                    if(isdigit(n[i]))
                        digit++;
                }

                if(digit==l)
                    flag=1;
                else
                    cout<<"\nPlease check you entered something wrong.....\n";
            }
        }while(flag!=1);

    fp.open("book.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmpi(bk.retbno(),n)!=0)
        {
            fp2.write((char*)&bk,sizeof(book));
        }
    }

    fp2.close();
        fp.close();
        remove("book.dat");
        rename("Temp.dat","book.dat");
        cout<<"\n\n\tRecord Deleted ..";
        getch();
}



//***************************************************************
//        function to display all students list
//****************************************************************

void display_alls()
{

         fp.open("student.dat",ios::in);
         if(!fp)
         {
               cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
               getch();
               return;
         }

    cout<<"\n\n\t\tSTUDENT LIST\n\n";
    cout<<"==================================================================\n";
    cout<<"\tAdmission No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
    cout<<"==================================================================\n";

    while(fp.read((char*)&st,sizeof(student)))
    {
        st.report();
    }

    fp.close();
    getch();
}


//***************************************************************
//        function to display Books list
//****************************************************************

void display_allb()
{

    fp.open("book.dat",ios::in);
    if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
               getch();
               return;
         }

    cout<<"\n\n\t\tBook LIST\n\n";
    cout<<"=========================================================================\n";
    cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
    cout<<"=========================================================================\n";

    while(fp.read((char*)&bk,sizeof(book)))
    {
        bk.report();
    }
         fp.close();
         getch();
}



//***************************************************************
//        function to issue book
//****************************************************************

void book_issue()
{
    char sn[6],bn[6];
    int found=0,flag=0;

    cout<<"\n\nBOOK ISSUE ...";
    cout<<"\n\n\tEnter The student's admission no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
        fp1.open("book.dat",ios::in|ios::out);
        while(fp.read((char*)&st,sizeof(student)) && found==0)
           {
        if(strcmpi(st.retadmno(),sn)==0)
        {
            found=1;
            if(st.rettoken()==0)
            {
                      cout<<"\n\n\tEnter the book no. ";
                cin>>bn;
                while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                {
                       if(strcmpi(bk.retbno(),bn)==0)
                    {
                        bk.show_book();
                        flag=1;
                        st.addtoken();
                        st.getstbno(bk.retbno());
                               int pos=-1*int(sizeof(st));
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\t Book issued successfully\n\nPlease Note: Write current date in backside of book and submit within 15 days fine Rs. 1 for each day after 15 days period";
                    }
                    }
                  if(flag==0)
                        cout<<"Book no does not exist";
            }
                else
                  cout<<"You have not returned the last book ";

        }
    }
          if(found==0)
        cout<<"Student record not exist...";
    getch();
      fp.close();
      fp1.close();
}

//***************************************************************
//        function to deposit book
//****************************************************************

void book_deposit()
{
    char sn[6],bn[6];
    int found=0,flag=0,day,fine;

    cout<<"\n\nBOOK DEPOSIT ...\n";
    cout<<"\nEnter the student admission no.";
    fflush(stdin);
    gets(sn);
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
       {
        if(strcmpi(st.retadmno(),sn)==0)
        {
            found=1;
            if(st.rettoken()==1)
            {
            while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
            {
               if(strcmpi(bk.retbno(),st.retstbno())==0)
            {
                bk.show_book();
                flag=1;
                cout<<"\n\nBook deposited in no. of days";
                cin>>day;
                if(day>15)
                {
                   fine=(day-15)*1;
                   cout<<"\n\nFine has to deposited Rs. "<<fine;
                }
                    st.resettoken();
                    int pos=-1*int(sizeof(st));
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&st,sizeof(student));
                    cout<<"\n\n\t Book deposited successfully";
            }
            }
          if(flag==0)
            cout<<"Book no does not exist";
              }
         else
            cout<<"No book is issued..please check!!";
        }
       }
      if(found==0)
    cout<<"Student record not exist...";
    getch();
  fp.close();
  fp1.close();
  }




//***************************************************************
//        INTRODUCTION FUNCTION
//****************************************************************

void intro()
{


    cout<<"LIBRARY ";

    cout<<" MANAGEMENT";

    cout<<" SYSTEM";
    cout<<"\n\nMADE BY : RISHABH RAJPUT";
    cout<<"\n\nCOLLEGE : JIMS";
    getch();
}



//***************************************************************
//        ADMINISTRATOR MENU FUNCTION
//****************************************************************

void admin_menu()
{

    int ch2;
    cout<<"\n\n\n\tADMINISTRATOR MENU";
    cout<<"\n\n\t1.CREATE STUDENT RECORD";
    cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORD";
    cout<<"\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
    cout<<"\n\n\t4.MODIFY STUDENT RECORD";
    cout<<"\n\n\t5.DELETE STUDENT RECORD";
    cout<<"\n\n\t6.CREATE BOOK ";
    cout<<"\n\n\t7.DISPLAY ALL BOOKS ";
    cout<<"\n\n\t8.DISPLAY SPECIFIC BOOK ";
    cout<<"\n\n\t9.MODIFY BOOK ";
    cout<<"\n\n\t10.DELETE BOOK ";
    cout<<"\n\n\t11.BACK TO MAIN MENU";
    cout<<"\n\n\tPlease Enter Your Choice (1-11) :- ";
    cin>>ch2;
    int flag;
    switch(ch2)
        {
            case 1:
                write_student();break;
            case 2: display_alls();break;
            case 3:{
                   char num[6];
                   flag=0;
                   do
                    {
                        cout<<"\nEnter The admission no :- ";
                        fflush(stdin);
                        gets(num);
                        int digit=0;
                        int l=strlen(num);
                        if(l<=6)
                        {
                            for(int i=0;i<l;i++)
                            {
                                if(isdigit(num[i]))
                                    digit++;
                            }

                            if(digit==l)
                                flag=1;
                            else
                                cout<<"\nPlease check you entered something wrong.....\n";
                        }
                    }while(flag!=1);

                       display_sps(num);
                       break;
                       }
              case 4: modify_student();break;
              case 5: delete_student();break;
              case 6: write_book();break;
              case 7: display_allb();break;
              case 8: {
                   char num[6];

                   cout<<"\n\n\tPlease Enter The book No. ";
                   cin>>num;
                   display_spb(num);
                   break;
                      }
              case 9: modify_book();break;
              case 10: delete_book();break;
              case 11: return;
              default: cout<<"\n\n\tPlease select correct choice.....";
       }
       admin_menu();
}


//***************************************************************
//        THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main()
{
    char ch;
    intro();
    do
    {

        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t01. BOOK ISSUE";
        cout<<"\n\n\t02. BOOK DEPOSIT";
          cout<<"\n\n\t03. ADMINISTRATOR MENU";
          cout<<"\n\n\t04. EXIT";
          cout<<"\n\n\tPlease Select Your Option (1-4) :- ";
          ch=getche();
          switch(ch)
          {
            case '1':
                 book_issue();
                    break;
              case '2':book_deposit();
                     break;
              case '3':admin_menu();
                 break;
              case '4':exit(0);
              default :cout<<"\n\n\tPlease select correct choice.....";
        }
        }while(ch!='4');
}

//***************************************************************
//                END OF PROJECT
//***************************************************************
