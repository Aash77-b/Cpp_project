#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
//Choices
int choice1,choice2,choice3,i;
//maximum donor that can be accepted and you can change it every time
const int MAX=100;
//Donor data
string name_donor[MAX],blood_type[MAX],phone_donor[MAX];
int age_donor[MAX],id_donor[MAX];
int donors=0;
//Ad min password
int pass;
//Volunteer data
string name_volunteer[MAX],phone_volunteer[MAX];
int volunteer=0;
int id_volunteer[MAX];

//For Compatibility
int compatible=0;
string recipent;

start:
    do{
             system("cls");
cout<<"\n==========BLOOD BANK MANAGMENT SYSTEM============\n";
cout<<"1)User"<<endl;
cout<<"2)ADMIN"<<endl;
cout<<"3)Exit"<<endl;
cout<<"Choice:";
cin>>choice1;
switch(choice1)
{
case 1:
{
        cout<<"\n=====USER MENU=====\n";
        cout<<" Register as:\n 1)DONOR \n 2)VOLUNTEER \n";
        cin>>choice2;
        if(choice2==1)
{
            if(donors>=MAX)
    {    cout<<"Thank GOD,donor limit is reached.";
        return 0;}
cout<<"\nDonor page!!\n";
cout<<"Enter your name:";
cin>>name_donor[donors];
cout<<"Enter your age:";
cin>>age_donor[donors];
//Validity and accepting input for blood group
int valid;
do
{valid = 0;
cout << "Enter blood group (A+, A-, B+, B-, O+, O-, AB+, AB-): ";
cin >> blood_type[donors];
// convert to uppercase
for(char &c : blood_type[donors])
c = toupper(c);
if(blood_type[donors] == "A+" || blood_type[donors] == "A-" ||
   blood_type[donors] == "B+" || blood_type[donors] == "B-" ||
   blood_type[donors] == "O+" || blood_type[donors] == "O-" ||
   blood_type[donors] == "AB+" || blood_type[donors] == "AB-")
    {
valid = 1;
    }
    else cout << "Invalid blood group! Try again.\n";
    }
while(valid == 0);
phone:
cout<<"Enter your phone:+251 ";
cin>>phone_donor[donors];
if(phone_donor[donors].length() != 9)
    {cout << "Invalid phone number!Try again\n";
     goto phone;   }
/*check age eligibility 1)>18 and <60 (eligible)
                        2)<18 not eligible and recommended for the volunteer actions.
                        3)>60 not eligible and recommended for other services.*/
if(age_donor[donors]>18&&age_donor[donors]<60){
  id_donor[donors] = 1000+donors+1;
cout<<"Id:"<<id_donor[donors];
 donors++;
cout<<"\nRegistered successfully!\n";}
else if(age_donor[donors]<=18)
    {cout<<"Right now you are not eligible to donate dear future donator.\n";
    cout<<"If you wanna help,register on the volunteer service"<<endl;
    }
else cout<<"Not eligible for donating,Thank you for approaching us."<<endl;

}
        else if(choice2==2)
{
              volunteer:
cout<<"Enter your name:";
cin>>name_volunteer[volunteer];
phone2:
cout<<"Enter your phone:+251 9";
cin>>phone_volunteer[volunteer];
if(phone_volunteer[volunteer].length() != 8)
    {cout << "Invalid phone number!Try again\n";
     goto phone2;   }
     cout<<"Successfully registered!!\n";
     cout<<"We will let you know our upcoming updates\n";
      id_volunteer[volunteer] = 15000+volunteer+1;
     cout<<"Your volunteer ID is:"<<id_volunteer[volunteer]<<endl;
     volunteer++;
          }
        else
{
    cout<<"Invalid input!Try again";
        goto start;}

    break;
}
case 2:
{
    cout<<"Enter Admin password:";
    cin>>pass;
    if(pass==1234)
    {
        cout<<"Access granted\n";
        //Admin accesses
    cout<<"=======ADMIN MENU=======";
    cout<<"\n 1)Emergency(blood request)";
    cout<<"\n 2)View all donors";
    cout<<"\n 3)View all volunteer \n";

    cout<<"Enter choice:";
    cin>>choice3;
    switch(choice3)
    {
 case 1:
     {
int valid;
do
{
valid = 0;
cout << "Enter recipient blood group: ";
cin >> recipent;
for(char &c : recipent)
    c = toupper(c);
if(recipent == "A+" || recipent == "A-" ||
  recipent == "B+" || recipent == "B-" ||
  recipent == "O+" || recipent == "O-" ||
  recipent == "AB+" || recipent == "AB-")
    {
valid = 1;
    }
    else cout << "Invalid blood group! Try again.\n";
} while(valid == 0);
for(int i=0;i<donors;i++)
{
         if(blood_type[i]==recipent)compatible=1;
           else if(blood_type[i]=="O-")compatible=1;
               else if(recipent=="AB+")compatible=1;
if(compatible==1)
    {
        cout<<"Compatible donor found"<<endl;
          cout<<i<<"."<<id_donor[i]<<":"<<name_donor[i]<<"("<<blood_type[i]<<")"<<" -phone:"<<phone_donor[i]<<endl;
        compatible=1;
    }
    }
    if(compatible == 0)
        cout << "\nNo compatible donor found.\n";

         break;
     }
 case 2:
    {   cout<<"\nID"<<setw(13)<<"Name"<<setw(13)<<"Age"<<setw(13)<<"Blood type"<<setw(13)<<"phone\n";
        for(int i=0;i<donors;i++)
        {
            cout<<id_donor[i]<<setw(13)<<name_donor[i]<<setw(13)<<age_donor[i]<<setw(13)<<blood_type[i]<<setw(13)<<"+251"<<phone_donor[i]<<endl;
        }
        break;
    }
 case 3:
    {   cout<<"Name"<<setw(13)<<"phone"<<endl;
        for(i=0;i<volunteer;i++)
        {
            cout<<name_volunteer[i]<<setw(13)<<"09"<<phone_volunteer[i]<<endl;
        }
        break;
    }


    default:
        cout<<"Invalid input!!\n";
    }
    }
    else
        cout<<"Wrong password!!";
    break;}
case 3:
{
cout<<"Thank you for using the system.\n\n\n";
break;}
 default:cout<<"Invalid choice!!";
}
system("pause");
}

while(choice1!=0);
return 0;
}
