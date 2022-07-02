
/*

Object Computing Lab
20XD26

Car Rental System

Program by Harish R ( 21pd11 ) and Sanjay Ram RR ( 21pd32 )

*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <windows.h>
#include <time.h>
#include <dos.h>                                            //  Importing all the necessary Libraries
using namespace  std;

class Profile;
class Cars;

int convert_int(string s)
{
    int num=0;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        num=num*10+(int(s[i])-48);
    }
    return num;
}


class Cars                                                  // Class Cars
{

protected:

    string passenger[7]   = {"Swift", "Altroz", "i10", "i20", "Santro", "Celerio", "WagonR"};
    string pass_luxury[7] = {"Land Rover", "Mercedez", "BMW", "Lexus", "Bentley", "Wraith", "Audi" };
    string suv[7]         = {"Creta", "Venue", "Punch", "kiger", "Citroen", "MG Hector", "Taigun"};
    string suv_luxury[7]  = {"Cayenne", "Lincoln Nautilis", "Rivian R1s", "Acura", "Genesis", "Cullinan", "Porsche" };

    string colour[7]      = {"Grey","White","Black","Silver","Blue","Red","Brown"};

    string model [7]      = {"2016MD","2018AS","2018DS","2017LA","2018OW","2005Ps","2010QW"};

    string plate_passenger[7]   = {"TN 42 BP 1444", "TN 42 BL 5343", "TN 42 RC 8592", "TN 42 AP 4105", "TN 42 AT 9066", "TN 42 AR 2222", "TN 42 BC 9009" };
    string plate_pass_luxury[7] = {"TN 42 CP 1212", "TN 42 RC 1442", "TN 42 CP 0090", "TN 42 ER 5647", "TN 42 AR 1267", "TN 42 BE 0991", "TN 42 MC 7544" };
    string plate_suv[7]         = {"TN 42 OP 1287", "TN 42 AW 8769", "TN 42 CX 7892", "TN 42 EI 1112", "TN 42 PZ 2322", "TN 42 PP 1211", "TN 42 UI 1122" };
    string plate_suv_luxury[7]  = {"TN 42 QW 1112", "TN 42 KL 2221", "TN 42 TS 1211", "TN 42 OQ 1123", "TN 42 MP 2099", "TN 42 PY 1134", "TN 42 NC 3232" };

};

class Profile;
class Login_Reg;

int checkString(char str1[])                                // Function validating the name
{
    int i,x=0,p;
    p=strlen(str1);

    for (i = 0; i < p ; i++)
    {
        if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] == ' '))
        {
            continue;
        }
        else
        return 0;
    }
    return 1;
}

void deleteLine(int n)
{
    int lineno = 1;

    ifstream is("Users.csv");
    ofstream out("temp.csv",ios::app);
    ifstream lis("Logins.csv");
    ofstream lout("temp1.csv",ios::app);

    char c;
    while (is.get(c))
    {
        if (c == '\n')
        lineno++;

        if (lineno != n)
        out << c;
    }

    lineno = 1;

    while (lis.get(c))
    {
        if (c == '\n')
        lineno++;

        if (lineno != n)
        lout << c;
    }

    lout.close();
    out.close();
    lis.close();
    is.close();

    remove("Users.csv");
    rename("temp.csv", "Users.csv");

    remove("Logins.csv");
    rename("temp1.csv", "Logins.csv");

    getch();

}

void deleteLineR(int n)
{
    int lineno = 1;

    ifstream is("Rented.csv");
    ofstream out("temp.csv",ios::app);

    char c;
    while (is.get(c))
    {
        if (c == '\n')
        lineno++;

        if (lineno != n)
        out << c;
    }
    out.close();
    is.close();

    remove("Rented.csv");
    rename("temp.csv", "Rented.csv");

    getch();

}

class Profile
{

    public:

void login()
{
    int flag = 0, count = 0,c ;
    string userID,password,id,pass;

    l2 : system("cls");
    count++;

    string dest, name, model, color, plate, time;

    fflush(stdin);
    cout << "\n\t\t\t\t\t    *********************** ||   Welcome user !  || ***********************" << endl;
    cout << "\n\n\t Username : ";
    getline(cin ,userID, '\n');
    fflush(stdin);
    cout << "\n\t Password : ";

    char cp;

    while(cp != '\r')
    {
        cp = getch();
        if(cp == '0')
        {
            switch(getch())
            {
               default:
                    break;
            };
        }

        else if(cp == '\b')
        {
            if(password.size() != 0)
            {
               cout << "\b \b";
               password.erase(password.size() - 1, 1);
            }
            continue;
        }

         else if(cp <= '9' && cp >= '0' || cp >= 'a' && cp <= 'z' || cp >= 'A' && cp <= 'Z')
        {
            password += cp;
            cout << "*";
        }

         else
            continue;
         }

    ifstream fin;
    fin.open("Logins.csv");

    string line, temp;
    string arr[5];

    while(fin)
    {
        int i = 0;
        temp = '\0';

        getline(fin,line);

        for(int j = 0 ; j < line.length() ; j++ )
        {
            if(line[j] != ',')
            {
                temp = temp + line[j];
            }
            else
            {
                string word;

                for(int k = 0 ; k < temp.length();k++)
                {
                    if(temp[k] != '\0')
                    {
                        word = word + temp[k];
                    }
                }

                arr[i] = word;
                i++;
                temp = '\0';
            }
        }

        if(userID == arr[0])
        {
            id = arr[0];
            pass = arr[1];
        }
    }
    fin.close();

    if(id == userID && pass == password)
    {
        cout << "\n Login successful !\n";
        Sleep(2000);
        system("cls");
        main_menu(id);
    }

    else
    {
        if(count < 2)
        {
            cout<<"\n\n\n\t Login Unsuccesfull !\n\t Please check your credentials\n";
            Sleep(2000);
            goto l2;
        }

        else if(count >= 2)
        {
            cout << "\n\n\n\t Forgot Password ? Didnt Register yet ?" << endl;
            cout << "\n\t Press 1 to know Password";
            cout << "\n\t Press 2 to register" << endl << endl;

            int ch = getch();

            if(ch == 49)
            forgot();

            else if(ch == 50)
            registration();
        }
    }
}

void registration()
{
    string ruserid,rid,pass,rpassword,rcity,rstate, email;
    char phone[10];
    int flag;

    system("cls");

    cout << "\n\t\t\t\t\t    *********************** ||   Welcome user !  || ***********************" << endl;

    fflush(stdin);
    cout << "\n\n\t Username : ";
    getline (cin , ruserid, '\n');
    fflush(stdin);
    cout << "\n\n\t Password : ";
    getline (cin , rpassword, '\n');
    fflush(stdin);
    cout<<"\n\n\t City : ";
    getline(cin, rcity, '\n');
    fflush(stdin);
    cout<<"\n\n\t State : ";
    getline(cin, rstate, '\n');
    fflush(stdin);
    l3: cout << "\n\n\t Mobile Number : ";
    scanf("%s",&phone);


    flag = 0;

    if(strlen(phone) == 10)                                         //checking the phone number
    {
        for(int i = 0; i<10; i++)
        {
            if(phone[i] == '1' || phone[i] == '2' || phone[i] == '3' || phone[i] == '4' || phone[i] == '5' || phone[i] == '6' || phone[i] == '7' || phone[i] == '8' || phone[i] == '9' || phone[i] == '0')
            flag++;
        }
    }

    if(flag != 10)
    {
        cout << "\a" ;
        cout << "\n\n\n\t Invalid number\n\n";
        goto l3;
        Sleep(2000);
    }

    ofstream f( "Users.csv", ios::app);
    f << ruserid << ',' << rpassword << ',' << phone << ',' << rcity << ',' << rstate << ',' << ' ' << endl;

    ofstream fin( "Logins.csv", ios::app);
    fin << ruserid << ',' << rpassword << ',' << ' ' << endl;


    cout<<"\n\n\n\t Registration is successfull ! \n";
    Sleep(2000);
    login();

    f.close();
}

void forgot()
{
    int option, count = 99;
    string suserID, sid, spass, semail, sphone;

    system("cls");

    cout << "\n\t\t\t\t\t    *********************** ||   Welcome user !  || ***********************" << endl;

    cout<<"\n\t\t\t Enter the username :";
    cin>>suserID;

    ifstream f2("Logins.csv");

    while(f2 >> sid >> spass)
    {
        if(sid == suserID)
        {
            cout << "\n\n Your account is found ! \n";
            cout << " Your password is :" <<spass;
            count = 0;
        }
    }

    if(count != 0)
    {
        cout<<"\n\t Sorry ! Your account is not found:\n";
    }

    cout << "\n\n Do you want to continue ? (Y / N) : " << endl;
    char getc = getch();

    if(getc == 'Y' || getc == 'y')
    login();

    else if(getc == 'N' || getc == 'n')
    {
        system("color 0F0");
        system("cls");
        cout << "\n\n\n\n\t\t\t\t Exiting";
        Sleep(500);
        cout << ". ";
        Sleep(500);
        cout << ". ";
        Sleep(500);
        cout << ". ";
        Sleep(500);

        system("cls");
        cout << "\n\n\n\n\t\t\t\t Exiting";
        Sleep(500);
        cout << ". ";
        Sleep(500);
        cout << ". ";
        Sleep(500);
        cout << ". ";
        Sleep(500);

        cout << endl << endl << endl;

        exit (0);
    }

}

void main_menu(string id)
{
    int c;
    system("cls");

        cout<<"\n\t\t\t\t\t    *********************** ||   Welcome user !  || ***********************  ";
        cout<<"\n\t\t\t\t\t    *                                                                     *  ";
        cout<<"\n\t\t\t\t\t    *                                                                     *  ";
        cout<<"\n\t\t\t\t\t    *                                                                     *  ";
        cout<<"\n\t\t\t\t\t    *                                                                     *  ";
        cout<<"\n\t\t\t\t\t    *                                                                     *  ";
        cout<<"\n\t\t\t\t\t    *                                                                     *  ";
        cout<<"\n\t\t\t\t\t    *                                                                     *  ";
        cout<<"\n\t\t\t\t\t    *                          1. View profile                            *  ";
        cout<<"\n\t\t\t\t\t    *                          2. Update profile                          *  ";
        cout<<"\n\t\t\t\t\t    *                          3. Cars                                    *  ";
        cout<<"\n\t\t\t\t\t    *                          4. Exit                                    *  ";
        cout<<"\n\t\t\t\t\t    *                                                                     *  ";
        cout<<"\n\t\t\t\t\t    *                                                                     *  ";
        cout<<"\n\t\t\t\t\t    *                                                                     *  ";
        cout<<"\n\t\t\t\t\t    *                                                                     *  ";
        cout<<"\n\t\t\t\t\t    *                                                                     *  ";
        cout<<"\n\t\t\t\t\t    *                                                                     *  ";
        cout<<"\n\t\t\t\t\t    **************************  ||  -------  ||  **************************  ";
        cout<<"\n\n\n\t\t\t\t\tEnter your choice: ";
        cin>>c;
        switch (c)
        {
            case 1:
            {
                system("cls");
                view_profile(id);
                Sleep(2000);
                system("cls");
                break;
            }

            case 2:
            {
                system("cls");
                update_profile(id);
                break;
            }

            case 3:
            {
                system("cls");
                break;
            }

            case 4:
            {
                system("color 0F0");
                system("cls");
                cout << "\n\n\n\n\t\t\t\t Exiting";
                Sleep(500);
                cout << ". ";
                Sleep(500);
                cout << ". ";
                Sleep(500);
                cout << ". ";
                Sleep(500);

                system("cls");
                cout << "\n\n\n\n\t\t\t\t Exiting";
                Sleep(500);
                cout << ". ";
                Sleep(500);
                cout << ". ";
                Sleep(500);
                cout << ". ";
                Sleep(500);

                cout << endl << endl << endl;

                exit (0);

            }

            default:
            {
                cout<<"\n\n\t\t Invalid Choice !!"<<endl;
                break;
            }

        }
}



void view_profile(string id)
{
    cout << "\n\t\t\t\t\t    *********************** ||   Welcome user !  || ***********************" << endl;

    ifstream in("Users.csv");

    string cuserid,cpassword,cphone,ccity,cstate,userid;

    ifstream fin;
    fin.open("Users.csv");

    string line, temp;
    string arr[5];

    while(fin)
    {
        int i = 0;
        temp = '\0';

        getline(fin,line);

        for(int j = 0 ; j < line.length() ; j++ )
        {
            if(line[j] != ',')
            {
                temp = temp + line[j];
            }
            else
            {
                string word;

                for(int k = 0 ; k < temp.length();k++)
                {
                    if(temp[k] != '\0')
                    {
                        word = word + temp[k];
                    }
                }

                arr[i] = word;
                i++;
                temp = '\0';
            }
        }

        if(id == arr[0])
        {
            cuserid = arr[0];
            cpassword   = arr[1];
            cphone  = arr[2];
            ccity = arr[3];
            cstate = arr[4];
        }

    }
    fin.close();

    cout<<"\n\n\t\t User Name      : " << cuserid<<endl;
    cout<<"\n\n\t\t Phone Number   : " << cphone<<endl;
    cout<<"\n\n\t\t City           : " << ccity<<endl;
    cout<<"\n\n\t\t State          : " << cstate<<endl;

    in.close();
    int i;
    cout<<"\n\n\t\t Press 1 to exit";
    do{
        int i = getch();
        if(i==49)
        {
            system("cls");
            main_menu(id);

            break;
        }
        else
        {
            cout<<"Invalid choice :";
        }

    }while(i!=49);


}

void update_profile(string id)
{
    string uuserid,upassword,uphone,ucity,ustate,userid,temp;
    int ch, lineno = 0, templine = 0;

    ifstream is("Users.csv");
    ofstream out("Users.csv",ios::app);
    ifstream lis("Logins.csv");
    ofstream lout("Logins.csv",ios::app);

    cout << "\n\t\t\t\t\t    *********************** ||   Welcome user !  || ***********************" << endl;
    cout<<"\n\t Enter your Username :";
    cin>>userid;

    ifstream fin;
    fin.open("Users.csv");

    string line;
    string arr[5];

    while(getline(fin,line))
    {
        int i = 0;
        temp = '\0';

        templine++;

        for(int j = 0 ; j < line.length() ; j++ )
        {
            if(line[j] != ',')
            {
                temp = temp + line[j];
            }
            else
            {
                string word;

                for(int k = 0 ; k < temp.length();k++)
                {
                    if(temp[k] != '\0')
                    {
                        word = word + temp[k];
                    }
                }

                arr[i] = word;
                i++;
                temp = '\0';
            }
        }

        if(userid == arr[0])
        {
            lineno = templine;
            uuserid    = arr[0];
            upassword  = arr[1];
            uphone      = arr[2];
            ucity     = arr[3];
            ustate     = arr[4];
        }

    }
    fin.close();


    is.close();
    out.close();
    lis.close();
    lout.close();

    fflush(stdin);
    cout<<"\n\n\t\t Enter which data you want to update :";
    cout<<"\n\n\t\t 1. User name \n\n\t\t 2. Password \n\n\t\t 3. Phone number \n\n\t\t 4. City \n\n\t\t 5. State\n\n\t\t 6. Exit";
    cout<<"\t\t\t Enter your choice :";
    cin>>ch;

    l1:switch(ch)
    {
        case 1:
        {
            system("cls");
            fflush(stdin);
            cout<<"\n\n\t Enter the new user name :";
            getline(cin, temp, '\n');
            uuserid=temp;

            deleteLine(lineno);

            ofstream out("Users.csv",ios::app);
            ofstream lout("Logins.csv",ios::app);

            out << uuserid << ',' << upassword << ',' << uphone << ',' << ucity << ',' << ustate << ',' << ' ' << endl;
            lout << uuserid << ',' << upassword << ',' << ' ' << endl;

            out.close();
            lout.close();

            deleteLine(1);

            cout<<"\n\n\t\t Update Successful!!"<<endl;
            Sleep(2000);
            main_menu(uuserid);
            break;
        }

        case 2:
        {
            system("cls");
            fflush(stdin);
            cout<<"\n\n\t Enter the new password :";
            getline(cin, temp, '\n');
            upassword=temp;

            deleteLine(lineno);

            ofstream out("Users.csv",ios::app);
            ofstream lout("Logins.csv",ios::app);

            out << uuserid << ',' << upassword << ',' << uphone << ',' << ucity << ',' << ustate << ',' << ' ' << endl;
            lout << uuserid << ',' << upassword << ',' << ' ' << endl;

            out.close();
            lout.close();

            deleteLine(1);

            cout<<"\n\n\t\t Update Successful!!"<<endl;
            Sleep(2000);
            main_menu(uuserid);
            break;
        }

        case 3:
        {
            system("cls");
            fflush(stdin);
            cout<<"\n\n\t Enter the new number :";
            getline(cin, temp, '\n');
            uphone=temp;

            deleteLine(lineno);

            ofstream out("Users.csv",ios::app);
            ofstream lout("Logins.csv",ios::app);

            out << uuserid << ',' << upassword << ',' << uphone << ',' << ucity << ',' << ustate << ',' << ' ' << endl;
            lout << uuserid << ',' << upassword << ',' << ' ' << endl;

            out.close();
            lout.close();

            deleteLine(1);

            cout<<"\n\n\t\t Update Successful!!"<<endl;
            Sleep(2000);
            main_menu(uuserid);
            break;
        }

        case 4:
        {
            system("cls");
            fflush(stdin);
            cout << "\n\n\t Enter the new city :";
            getline(cin, temp, '\n');
            ucity =temp;

            deleteLine(lineno);

            ofstream out("Users.csv",ios::app);
            ofstream lout("Logins.csv",ios::app);

            out << uuserid << ',' << upassword << ',' << uphone << ',' << ucity << ',' << ustate << ',' << ' ' << endl;
            lout << uuserid << ',' << upassword << ',' << ' ' << endl;

            out.close();
            lout.close();

            deleteLine(1);

            cout<<"\n\n\t\t Update Successful!!"<<endl;
            Sleep(2000);
            main_menu(uuserid);
            break;
        }

        case 5:
        {
            system("cls");
            fflush(stdin);
            cout<<"\n\n\t Enter the new state :";
            getline(cin, temp, '\n');
            ustate=temp;

            deleteLine(lineno);

            ofstream out("Users.csv",ios::app);
            ofstream lout("Logins.csv",ios::app);

            out << uuserid << ',' << upassword << ',' << uphone << ',' << ucity << ',' << ustate << ',' << ' ' << endl;
            lout << uuserid << ',' << upassword << ',' << ' ' << endl;

            out.close();
            lout.close();

            deleteLine(1);

            cout<<"\n\n\t\t Update Successful!!"<<endl;
            Sleep(2000);
            main_menu(uuserid);
            break;
        }

        case 6:
        {
            main_menu(id);
        }

        default:
        {
            cout<<"\n\n\t\t Invalid Choice !!"<<endl;
            goto l1;
        }
    }

}
};


class Rent: public Cars, public Profile
{
    int i, n = 7;
    int ch;

    int ppassenger[7]   = {2000, 1500, 1000, 1000, 1000, 2500, 2500};
    int ppass_luxury[7] = {7500, 6000, 7000, 8000, 8000, 6000, 7500};
    int psuv[7]         = {3000, 3000, 3500, 4000, 4000, 6000, 3500};
    int psuv_luxury[7]  = {9000, 10000, 8500, 11000, 10000, 12000, 17000};

public:

    void view()
    {
        int choice;
        system("cls");
        cout << endl << endl;
        printf("\n\t\t\t\t\t    *********************** ||   Welcome user !  || ***********************  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                         Choose the Type :                           *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                         1. Passenger                                *  ");
        printf("\n\t\t\t\t\t    *                         2. Luxury                                   *  ");
        printf("\n\t\t\t\t\t    *                         3. SUV                                      *  ");
        printf("\n\t\t\t\t\t    *                         4. SUV_Luxury                               *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    **************************  ||  -------  ||  **************************  ");


        printf("\n\n\n\t\t\t\t\tEnter your choice: ");
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                system("cls");
                cout << endl << endl;

                for(i=0 ; i<n; i++)
                {
                    cout << "\t" << i+1 << ") " << left << setw(20) << passenger[i] << " - Rs. " <<  ppassenger[i] << endl;
                }

                cout << "\n\n\tPress Enter to Continue";
                getch();
                break;

            }

            case 2:
            {
                system("cls");
                cout << endl << endl;

                for(i=0 ; i<n; i++)
                {
                    cout << "\t" << i+1 << ") " << left << setw(20) << pass_luxury[i] << " - Rs. " <<  ppass_luxury[i] << endl;
                }

                cout << "\n\n\tPress Enter to Continue";
                getch();
                break;
            }

            case 3:
            {
                system("cls");
                cout << endl << endl;

                for(i=0 ; i<n; i++)
                {
                    cout << "\t" << i+1 << ") " << left << setw(20) << suv[i] << " - Rs. " <<  psuv[i] << endl;
                }

                cout << "\n\n\tPress Enter to Continue";
                getch();
                break;
            }

            case 4:
            {
                system("cls");
                cout << endl << endl;

                for(i=0 ; i<n; i++)
                {
                    cout << "\t" << i+1 << ") " << left << setw(20) << suv_luxury[i] << " - Rs. " <<  psuv_luxury[i] << endl;
                }

                cout << "\n\n\tPress Enter to Continue";
                getch();
                break;
            }
        }



    }

    void menu()
    {
        int choice;


        time_t timea;
        time(&timea);

        string user, destination;
        int rdate;

        ofstream rentc("Rented.csv", ios::app);

        fflush(stdin);
        cout << "\n\n\tEnter username : ";
        getline(cin, user, '\n');

        fflush(stdin);
        cout << "\n\tWhere are you headed to ? ";
        getline(cin, destination, '\n');

        fflush(stdin);
        cout << "\n\tReturn Date ";
        cin  >> rdate;

        system("cls");
        cout << endl << endl;
        printf("\n\t\t\t\t\t    *********************** ||   Welcome user !  || ***********************  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                         Choose the Type :                           *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                         1. Passenger                                *  ");
        printf("\n\t\t\t\t\t    *                         2. Luxury                                   *  ");
        printf("\n\t\t\t\t\t    *                         3. SUV                                      *  ");
        printf("\n\t\t\t\t\t    *                         4. SUV_Luxury                               *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t\t\t    **************************  ||  -------  ||  **************************  ");


        printf("\n\n\n\t\t\t\t\tEnter your choice: ");
        cin >> choice;

        system("cls");
        cout << endl << endl;

        l5 : switch(choice)
        {
            case 1:
            {
                for(i=0 ; i<n; i++)
                {
                    cout << "\t" << i+1 << ") " << left << setw(20) << passenger[i] << " - Rs. " <<  ppassenger[i] << endl;
                }

                cout << "Enter your choice :";
                cin  >> ch;

                if(ch != 1 && ch != 2 && ch != 3 && ch != 4 && ch != 5 && ch != 6 && ch != 7)
                {
                    cout << "\n\tInvalid Entry !";
                    goto l5;
                }

                system("cls");
                cout << endl << endl;

                cout << "\tYour Car :" << endl;
                cout << "\t----------" << endl << endl;
                cout << "\tName   :"  << passenger[ch-1] << endl;
                cout << "\tModel  :"  << model[ch-1]     << endl;
                cout << "\tColour :"  << colour[ch-1]    << endl;
                cout << "\tNumber :" << plate_pass_luxury[ch-1] << endl;

                rentc << user << ',' << destination << ',' << passenger[ch-1] << ',' << model[ch-1] << ',' << colour[ch-1] << ',' << plate_passenger[ch-1] << ',' << "1" << ',' << ch-1 << ',' << ctime(&timea) << ',' << ' ' << endl;

                cout << "\n\n\tThis Car is now rented to you ! \n\tPress Enter to Exit";
                getch();
                break;

            }

            case 2:
            {
                for(i=0 ; i<n; i++)
                {
                    cout << "\t" << i+1 << ") " << left << setw(20) << pass_luxury[i] << " - Rs. " <<  ppass_luxury[i] << endl;
                }

                cout << "Enter your choice :";
                cin  >> ch;

                if(ch != 1 && ch != 2 && ch != 3 && ch != 4 && ch != 5 && ch != 6 && ch != 7)
                {
                    cout << "\n\tInvalid Entry !";
                    goto l5;
                }

                system("cls");
                cout << endl << endl;

                cout << "\tYour Car :" << endl;
                cout << "\t----------" << endl << endl;
                cout << "\tName  :"  << pass_luxury[ch-1] << endl;
                cout << "\tModel :"  << model[ch-1]     << endl;
                cout << "\tColour :" << colour[ch-1]    << endl;
                cout << "\tNumber :" << plate_pass_luxury[ch-1] << endl;

                rentc << user << ',' << destination << ',' << pass_luxury[ch-1] << ',' << model[ch-1] << ',' << colour[ch-1] << ',' << plate_pass_luxury[ch-1] << ',' << "2" << ',' << ch-1 << ',' << ctime(&timea) << ',' << ' ' << endl;

                cout << "\n\n\tThis Car is now rented to you ! \n\tPress Enter to Exit";
                getch();
                break;
            }

            case 3:
            {
                for(i=0 ; i<n; i++)
                {
                    cout << "\t" << i+1 << ") " << left << setw(20) << suv[i] << " - Rs. " <<  psuv[i] << endl;
                }

                cout << "Enter your choice :";
                cin  >> ch;

                if(ch != 1 && ch != 2 && ch != 3 && ch != 4 && ch != 5 && ch != 6 && ch != 7)
                {
                    cout << "\n\tInvalid Entry !";
                    goto l5;
                }

                system("cls");
                cout << endl << endl;

                cout << "\tYour Car :" << endl;
                cout << "\t----------" << endl << endl;
                cout << "\tName  :"  << suv[ch-1] << endl;
                cout << "\tModel :"  << model[ch-1]     << endl;
                cout << "\tColour :" << colour[ch-1]    << endl;
                cout << "\tNumber :" << plate_suv[ch-1] << endl;

                rentc << user << ',' << destination << ',' << suv[ch-1] << ',' << model[ch-1] << ',' << colour[ch-1] << ',' << plate_suv[ch-1] << ',' << "3" << ',' << ch-1 << ',' << ctime(&timea) << ',' << ' ' << endl;

                cout << "\n\n\tThis Car is now rented to you ! \n\tPress Enter to Exit";
                getch();
                break;
            }

            case 4:
            {
                for(i=0 ; i<n; i++)
                {
                    cout << "\t" << i+1 << ") " << left << setw(20) << suv_luxury[i] << " - Rs. " <<  psuv_luxury[i] << endl;
                }

                cout << "Enter your choice :";
                cin  >> ch;

                if(ch != 1 && ch != 2 && ch != 3 && ch != 4 && ch != 5 && ch != 6 && ch != 7)
                {
                    cout << "\n\tInvalid Entry !";
                    goto l5;
                }

                system("cls");
                cout << endl << endl;

                cout << "\tYour Car :" << endl;
                cout << "\t----------" << endl << endl;
                cout << "\tName  :"  << suv_luxury[ch-1] << endl;
                cout << "\tModel :"  << model[ch-1]     << endl;
                cout << "\tColour :" << colour[ch-1]    << endl;
                cout << "\tNumber :" << plate_suv_luxury[ch-1] << endl;

                rentc << user << ',' << destination << ',' << suv_luxury[ch-1] << ',' << model[ch-1] << ',' << colour[ch-1] << ',' << plate_suv_luxury[ch-1] << ',' << "4" << ',' << ch-1 << ',' << ctime(&timea) << ',' << ' ' << endl;

                cout << "\n\n\tThis Car is now rented to you ! \n\tPress Enter to Exit";
                getch();
                break;
            }
        }

        rentc.close();

    }

    void returnc()
    {
        string userID, id, dest, car, model, colour, plate, chp, time;
        string pricei;
        int pricep, ch,price;

        int lineno = 0, templine = 0;

        system("cls");

        fflush(stdin);
        cout << "\n\n\tEnter user name : ";
        getline(cin, userID, '\n');
        fflush(stdin);
        string line, temp;
        string arr[9];

        ifstream fin("Rented.csv");

        while(fin)
        {
            int i = 0;
            temp = '\0';
            templine++;

            getline(fin,line);

            for(int j = 0 ; j < line.length() ; j++ )
            {
                if(line[j] != ',')
                {
                    temp = temp + line[j];
                }

                else
                {
                    string word;

                    for(int k = 0 ; k < temp.length();k++)
                    {
                        if(temp[k] != '\0')
                        {
                            word = word + temp[k];
                        }
                    }

                    arr[i] = word;
                    i++;
                    temp = '\0';
                }
            }
            if(userID == arr[0])
            {
                lineno = templine;
                id     = arr[0];
                dest   = arr[1];
                car    = arr[2];
                model  = arr[3];
                colour = arr[4];
                plate  = arr[5];
                pricei = arr[6];
                chp     = arr[7];
                time   = arr[8];
            }

            pricep=convert_int(pricei);
            ch=convert_int(chp);

            if (pricep == 1)
            {
                price = ppassenger[ch];
            }

            if (pricep== 2)
            {
                price = ppass_luxury[ch];
            }

            if (pricep == 3)
            {
                price = psuv[ch];
            }

            if (pricep== 4)
            {
                price = psuv_luxury[ch];
            }
        }
        fin.close();
        if(id == userID)
        {
            deleteLineR(lineno);

            fflush(stdin);

            int total=0, days=0;
            cout << "\n\n\n\tEnter the no of days you had it : ";
            cin  >> days;
            cout<<"\n\n\n\tPrice per day is "<<price<<endl;
            total = days*price;

            cout << "\n\n\tYour Car has been Returned !" << endl;
            cout << "\t---------------------------";

            cout << "\n\n\tYour Bill : " << total;
            cout << "\n\n\n\n\n\t\t\tThank you !";

        }

        else
        {
            cout << "\n\n\tSorry Profile not found !"
;       }

    }
};

int main()
{
    class Rent r;

    int c;

    system("cls");
    system("color 0F0");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tCar Rental System";
    Sleep(2000);                                                                           // sleep
    system("cls");

    l1 : system("cls");
    cout << endl << endl;
    cout<<"\n\t\t\t\t\t    *********************** ||   Welcome user !  || ***********************  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                          1. Login                                   *  ";
    cout<<"\n\t\t\t\t\t    *                          2. Register                                *  ";
    cout<<"\n\t\t\t\t\t    *                          3. Exit                                    *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    **************************  ||  -------  ||  **************************  ";


    cout<<"\n\n\n\t\t\t\t\tEnter your choice: ";
    cin  >> c;

    switch(c)
    {
        case 1:
        {
            r.login();
            break;
        }

        case 2:
        {

            r.registration();
            break;
        }

        case 3:
        {
            system("color 0F0");
            system("cls");
            cout << "\n\n\n\n\t\t\t\t Exiting";
            Sleep(500);
            cout << ". ";
            Sleep(500);
            cout << ". ";
            Sleep(500);
            cout << ". ";
            Sleep(500);

            system("cls");
            cout << "\n\n\n\n\t\t\t\t Exiting";
            Sleep(500);
            cout << ". ";
            Sleep(500);
            cout << ". ";
            Sleep(500);
            cout << ". ";
            Sleep(500);

            cout << endl << endl << endl;

            return 0;
        }

        default:
        {
            system("cls");
            cout<<"\n\n\n\t\t\t Please Enter a valid choice ! ";
            goto l1;
        }
    }

    l4 : system("cls");
    cout << endl << endl;
    cout<<"\n\t\t\t\t\t    *********************** ||   Welcome user !  || ***********************  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                          1. View Cars                               *  ";
    cout<<"\n\t\t\t\t\t    *                          2. Rent Cars                               *  ";
    cout<<"\n\t\t\t\t\t    *                          3. Return Car                              *  ";
    cout<<"\n\t\t\t\t\t    *                          4. Exit                                    *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    *                                                                     *  ";
    cout<<"\n\t\t\t\t\t    **************************  ||  -------  ||  **************************  ";


    cout<<"\n\n\n\t\t\t\t\tEnter your choice: ";
    cin  >> c;

    switch(c)
    {
        case 1:
        {
            r.view();
            goto l4;
        }

        case 2:
        {

            r.menu();
            break;
        }

        case 3:
        {

            r.returnc();
            break;
        }

        case 4:
        {
            system("color 0F0");
            system("cls");
            cout << "\n\n\n\n\t\t\t\t Exiting";
            Sleep(500);
            cout << ". ";
            Sleep(500);
            cout << ". ";
            Sleep(500);
            cout << ". ";
            Sleep(500);

            system("cls");
            cout << "\n\n\n\n\t\t\t\t Exiting";
            Sleep(500);
            cout << ". ";
            Sleep(500);
            cout << ". ";
            Sleep(500);
            cout << ". ";
            Sleep(500);

            cout << endl << endl << endl;

            return 0;
        }

        default:
        {
            system("cls");
            cout<<"\n\n\n\t\t\t Please Enter a valid choice ! ";
            goto l1;
        }


    }

}



/*

References :

1. GeekforGeeks     ( Website )
2. Tutorial Point   ( Website )
3. w3schools        ( Website )
4. Notes            ( Slides )
5. C++ Primer       ( Book )

*/
