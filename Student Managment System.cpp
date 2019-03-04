#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<iomanip>
#include<conio.h>

using namespace std;

void line(void);

/*structure to store data*/
struct student
{
    char name[20];      /*to store the name of the student*/
    int age;
    char branch[30];
    int roll;
    char phone[15];
    char mail[30];
    student *link;
};

student *start = NULL;


//function to show the menu to the user
int menu()
{
    cout<<endl;
    cout<<setw(76)<<"1. Add student \n";
    cout<<setw(99)<<"2. Show details of a specific student \n";
    cout<<setw(89)<<"3. Show all student details \n";
    cout<<setw(93)<<"4. Count the number of students \n";
    cout<<setw(88)<<"5. Know about the Developer\n";
    cout<<setw(68)<<"6. Exit\n";
    int choice;
    cout<<endl;
    cout<<setw(80)<<"Enter your choice : ";
    cin>>choice;
    return (choice);
}

void show_full_list()
{
    student *temp;
    temp = start;
    if(temp == NULL)
    {
        cout<<endl;
        line();
        cout<<setw(88)<<"No information available !!\n";
        cout<<setw(94)<<"Please Add some students first !!\n";
        line();
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<endl;
            cout<<setw(95)<<"Here is the list of all students :-"<<endl;
            line();
            cout<<setw(75)<<"Roll no   :    "<<temp->roll<<endl;
            cout<<setw(75)<<"Name      :    "<<temp->name<<endl;
            cout<<setw(75)<<"Branch    :    "<<temp->branch<<endl;
            cout<<setw(75)<<"Age       :    "<<temp->age<<endl;
            cout<<setw(75)<<"Phone no  :    "<<temp->phone<<endl;
            cout<<setw(75)<<"Mail id   :    "<<temp->mail<<endl;
            line();
            temp = temp->link;
        }
    }
}



//function to create a variable for one student details
student * createNode()
{
    student *temp;
    temp = (student *)malloc(sizeof(student));
    return temp;
}


//function to add student in the list

void add_student()
{
    student *temp;
    temp = createNode();
    temp->link = NULL;
    cout<<endl;
    cout<<setw(92)<<"Enter the Name of the Student : ";
    cin.ignore();
    cin.getline(temp->name,sizeof(temp->name));
    cout<<endl;
    cout<<setw(94)<<"Enter the branch of the student : ";
    cin.getline(temp->branch,sizeof(temp->branch));
    cout<<endl;
    cout<<setw(95)<<"Enter the Roll no of the student : ";
    cin>>temp->roll;
    cout<<endl;
    cout<<setw(100)<<"Enter the phone number of the student : ";
    cin.ignore();
    cin.getline(temp->phone,sizeof(temp->phone));
    cout<<endl;
    cout<<setw(91)<<"Enter the age of the student : ";
    cin>>temp->age;
    cout<<endl;
    cout<<setw(92)<<"Enter the mail of the student : ";
    cin.ignore();
    cin.getline(temp->mail,sizeof(temp->mail));
    cout<<endl;

    if(start == NULL)
        start = temp;
    else
    {
        student *n;
        n = start;
        while(n->link!=NULL)
        {
            n = n->link;
        }
        n->link = temp;
    }

    line();
    cout<<setw(99)<<"Student has been added successfully!!\n";
    line();
}

//function to print the details of a student using roll no;
void show_specific()
{
        int flag = 0;
        student *s;
        s = start;
        if(s==NULL)
        {
            cout<<endl;
            line();
            cout<<setw(83)<<"No Entries available !!"<<endl;
            cout<<setw(94)<<"Please choose 1 to add student !!\n";
            line();
        }
        else
        {
            cout<<endl;
            cout<<setw(95)<<"Enter the roll no of the student : ";
            int roll;
            cin>>roll;
            while(s!=NULL)
                {
                    if(s->roll == roll)
                    {
                        flag++;
                        cout<<endl;
                        line();
                        cout<<setw(75)<<"Roll no   :    "<<s->roll<<endl;
                        cout<<setw(75)<<"Name      :    "<<s->name<<endl;
                        cout<<setw(75)<<"Branch    :    "<<s->branch<<endl;
                        cout<<setw(75)<<"Age       :    "<<s->age<<endl;
                        cout<<setw(75)<<"Phone no  :    "<<s->phone<<endl;
                        cout<<setw(75)<<"Mail id   :    "<<s->mail<<endl;
                        line();
                    }
                    s = s->link;
                }
            if(flag==0)
            {
                cout<<endl;
                line();
                cout<<setw(78)<<"No record found !!"<<endl;
                line();
            }

        }
}

//function to count the number of student available

int count_student()
{
    student *temp;
    temp = start;
    if(temp == NULL)
    {
        cout<<endl;
        line();
        cout<<setw(82)<<" No record available !!"<<endl;
        cout<<setw(86)<<" Choose 1 to add a student "<<endl;
        line();
        return 0;
    }
    else
    {
        int flag=0;
        while(temp!=NULL)
        {
            flag++;
            temp = temp->link;
        }
        return flag;
    }
}

//function to print a line

void line()
{
    for(int i=1; i<=168; i++)
        cout<<"-";
}


//function to print the details of all students
int main()
{
    system("color 0A");
    cout<<setw(105)<<"****Welcome to Student Management System ***\n\n";
    while(1)
    {
        int choice = menu();
        switch(choice)
            {
                case 1:
                    add_student();
                    break;
                case 2:
                    show_specific();
                    break;
                case 3:
                    show_full_list();
                    break;
                case 4:
                    {
                        int number = count_student();
                        if(number != 0)
                        {
                            cout<<endl;
                            line();
                            cout<<setw(94)<<"Number of students available is : "<<number<<endl;
                            line();
                        }
                        break;
                    }
                case 5:
                    {
                        cout<<endl;
                        line();
                        cout<<setw(86)<<"Developer's Details are :-"<<endl;
                        cout<<setw(92)<<"Name          :    Manish Sharma"<<endl;
                        cout<<setw(89)<<"Contact       :    9599397936"<<endl;
                        cout<<setw(107)<<"Mail id       :    manishsharma959939@gmail.com"<<endl;
                        cout<<setw(112)<<"Follow on     :    www.instagram.com/manish_sharma44"<<endl;
                        line();
                        break;
                    }
                case 6:
                    {
                        cout<<endl;
                        line();
                        cout<<setw(92)<<"Thanks for using our Service :-)"<<endl;
                        line();
                        getch();
                        exit(0);
                    }

                default:
                    cout<<setw(76)<<"Invalid input !!"<<endl<<setw(89)<<"Please Enter a valid input !!"<<endl<<endl;
                    break;
            }
    }
}
