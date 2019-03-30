#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class School{
char name[30];
char type[20];
int locality,pincode;

public:
    void Read()
    {
      cout<<"\nWelcome Institution!\n \t\t\tWe sincerely appreciate your effort towards an Educated India\nKindly enter your details:"<<endl;
      cout<<"Enter your School Name: "<<endl;
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cin.getline(name,30);
      cout<<"Enter your School Type: "<<endl;

      cin.getline(type,20);
      cout<<"Select nearest locality: \n1.Bannimantap    2.VV Mohalla   3.Mysore Bus Stand   4.Mysore Palace    5.Hebbal\n";
      cin>>locality;cout<<endl;
      cout<<"Enter the School Pincode: "<<endl;
      cin>>pincode;
    }
    void Disp()
    {
        cout<<name<<endl;
        cout<<type<<endl;
        cout<<locality<<endl;
        cout<<pincode<<endl;
    }
    int getlocality()
    {
        return locality;
    }

};
void CreateSch()
{
    fstream G;
    G.open("School.dat",ios::binary|ios::app);
    School S;

    S.Read();
    G.write((char*)&S,sizeof(S));

    G.close();
}
void ReadSch()
{
    fstream G;
        G.open("School.dat",ios::binary|ios::in);
        School S;
        while(G.read((char*)&S,sizeof(S)))
        {

        S.Disp();}

        G.close();
}

class Volunteer{
int ID;
char name[30],quali[50];
char gender;
int age,slot,locality;

public:
    void Read()
    {
        cout<<"\nWelcome Volunteer!\n \t\t\tWe sincerely appreciate your effort towards an Educated India\nKindly enter your details:"<<endl;
        cout<<"Enter your Name:"<<endl;
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin.getline(name,30);
        cout<<"Gender (M/F/O): ";
        cin>>gender;
        cout<<"Age: ";
        cin>>age;cout<<endl;
        cout<<"Qualification: ";
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin.getline(quali,50);cout<<endl;
        cout<<"Select preferred slot: \n1.Morning    2.Afternoon    3.Evening\n";
        cin>>slot;cout<<endl;
        cout<<"Select nearest locality: \n1.Bannimantap    2.VV Mohalla   3.Mysore Bus Stand   4.Mysore Palace    5.Hebbal\n";
        cin>>locality;cout<<endl;
        cout<<"Choose a User ID: ";
        cin>>ID;
    }
    void Disp()
    {
        cout<<name<<endl;
        cout<<gender<<endl;
        cout<<age<<endl;
        cout<<quali<<endl;
        cout<<slot<<endl;
        cout<<locality<<endl;
        cout<<ID<<endl;

    }
    int getlocality()
    {
        return locality;
    }
};
void CreateVol()
{
    fstream F;
    F.open("Volunteer.dat",ios::binary|ios::app);
    Volunteer V;

    V.Read();
    F.write((char*)&V,sizeof(V));

    F.close();
}
void ReadVol()
{
    fstream F;
        F.open("Volunteer.dat",ios::binary|ios::in);
        Volunteer V;
        while(F.read((char*)&V,sizeof(V)))
        {

        V.Disp();}

        F.close();
}

void Assigned()
{
    fstream H;
    H.open("Assigned.txt",ios::binary|ios::app);

}
int main()
{
    int n;

    cout<<setw(60)<<"ENROLLMENT FORM"<<endl;
    cout<<"You are\n1)VolunteerC\n2)VolunteerD\n3)SchoolC\n4)SchoolD"<<endl;
    cout<<"Enter the respective number"<<endl;
    cin>>n;
    system("cls");
    switch(n)
    {
      case 1:CreateVol();break;
      case 2:ReadVol();break;
      case 3:CreateSch();break;
      case 4:ReadSch();break;
      default: break;
    }
  return 0;
}

