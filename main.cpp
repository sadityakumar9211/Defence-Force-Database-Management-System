/*PROJECT ON DEFENCE FORCE DATABASE MANAGEMENT SYSTEM
---------------------------------
GROUP-5-MEMBERS:
Abhisekh Yadav (2020BCS-003)
Aditya Kumar Singh (2020BCS-004)
Pratham Singh (2020BCS-059)
Mark Verma (2020BCS-078)
Saahil Sabu Hameed (2020BCS-079)
---------------------------------
Defence Force  = Army + Airforce
.................................
Army Personnel
Sepoy->Lieutenant->Major->General
.......................................
Airforce Personnel
Aircraftman->Flight Lieutenant->Squadron Leader->Air Chief Marshal
-------------------------------------------------------------------
Army section - Group of sepoys  (Lieutenant is leader)
Army Company - group of sections (Major is leader)
......................................................
Airforce Section - group of aircraftman (flight lieutenant is the leader)
Airforce Squadron - group of sections (squadron leader, leads here)
-------------------------------------------------------------------------
Note: In this project the structure of groups are:-
For Army
    com1 contains sec1, sec 2 and sec3
    com2 contains sec 4, sec5 and sec6
For Air Force
    sqa1 contains sec1, sec 2 and sec3
    sqa2 contains sec 4, sec5 and sec6
*/



#include <iostream>       //for console input-output
#include <string>        //function using c++ strings
#include <fstream>      //for file input-output
#include <cstdlib>     //for exit function

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;

#include "classes.h"   //header file containing the file definitions

//Global Functions used for army
void add_user(void);     //temporary function used to populate the .bin files 
void add_army_section_detail(void);    //function to add details in army section
void army_field(void);         //function handling all the operations in army field of project
void sepoy_login(void);        //used for sepoy login to his/her personnel dashboard
void lieu_login(void);          //used for lieutenant login to his/her personnel dashboard
void major_login();          //used for major login to his/her personnel dashboard
void general_login(void);    //used for general login
void add_personel(string post_name);  //adds the army personel into the section.bin and seopy.bin
void modify_personel(string post_name);  //used for modifying the details of an army personnel
void delete_personel(string post_name); //used for deleting the details of an army personnel
void army_personal_dashboard(void);    //used for logging into dashboard

//functions for airforce
void add_airforce_user(); //for temporary adding airforce personel
void add_airforce_personel(string post_name);   //used for adding an airforce personnel
void airforce_field();       //function handling all the operations in army field of project
void air_personal_dashboard(void);   //used for logging into dashboard
void flight_lieu_login();      //used for flight lieutenant login to his/her personnel dashboard
void squad_leader_login();    //used for squadron leader login to his/her personnel dashboard
void air_chief_marshal_login();   
void aircraftman_login();
void modify_airforce_personel(string post_name);     //used for modifying the details of an airforce personnel
void delete_airforce_personel(string post_name);    //used for deleting the details of an airforce personnel
void add_airforce_section_detail(void);    //function to add details in airforce section

//functions related to war
void war_details(void);     //for viewing or adding war details into the database
void add_war_details(void);    //for adding the war details into the database

//functions for cds
void add_cds_details(void);
void cds_login(void);
void cds_field(void);

//utility functions
void main_menu();   //handles the Super_Menu


//functions definitions
//-----------------
//main() function
//-----------------
int main()
{
    main_menu();
    return 0;
}

void main_menu()
{
    char choice;
    while (true)
    {
        flag2:
        cout<<"\n\n\n\t\t ------------------------------------------------";
        cout << "\n\t\t|   DEFENCE FORCE DATABASE MANAGEMENT SYSTEM    |";
        cout<<"\n\n\t\t ------------------------------------------------\n\n";
        cout << "\tSuper Menu\n";
        cout<<"     ----------------\n";
        cout << "\n1. Army login";
        cout << "\n2. Air-Force login";
        cout << "\n3. Chief of Defence Staff(CDS) login";
        cout << "\n4. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case '1':
            army_field();
            break;
        case '2':
            airforce_field();
            break;
        case '3':
            cds_field();
            break;
        case '4':
            cout<<"\nExiting the Program...";
            return;
            break;
        default:
            cout << "Error: Invalid Choice Selection\n\n";
        }
        goto flag2;
    }
}

void army_field()
{
    flag5:
    cout << "\n\t\tArmy Menu\n";
    cout<<"\t---------------------\n\n";
    cout << "1. Login to Personal Dashboard\n";
    cout << "2. Section-wise weapon allocation\n"; 
    cout << "3. War Details\n";
    cout << "4. Exit\n";
    cout << "9. Return to Previous Menu\n";
    cout << "\n\nEnter your choice: ";
    char choice;
    cin >> choice;
    switch (choice)
    {
    case '1':
        army_personal_dashboard();
        break;
    case '2':
    {
        ifstream fptr;
        fptr.open("army_section.bin", ios::in | ios::binary);
        if (!fptr.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        section_army sec_amy;
        int i{1};
        fptr.seekg(0 , ios::beg);
        while (fptr.read((char *)&sec_amy, sizeof(section_army)))
        {
            cout << "\nSection " << i << endl;
            cout << "------------" << endl;
            sec_amy.print_section_weapon_info();
            i++;
        }
        fptr.close();
        cin.ignore();
        cin.get();
    }
    break;
    case '3':
    {
        cout<<"\nNote: Only Army General can view and add war details\n\n";
        cout<<"Do you want to continue(y/n)? ";
        char choice;
        cin>>choice;
        if(choice=='y'||choice == 'Y')
        {
            war_details();      //general login dashboard then view history and add war
        }
        else
        {
            cout<<"\nReturning to Previous Menu...\n\n";
            goto flag5;
        }
        break;
    }
    case '4':
        cout <<"\nExiting the Program...\n";
        exit(0);
        break;
    case '9':
        main_menu();
    default:
        cout << "Error: Invalid Choice Selection"<< endl;
    }
    goto flag5;
}
void add_army_section_detail(void)
{
    ofstream fptr;
    fptr.open("army_section.bin", ios::binary|ios::app);
    if (!fptr.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    section_army s;
    s.getter_section_army();
    fptr.write((char*)&s , sizeof(section_army));
    fptr.close();
    cin.ignore();
    cin.get();
}

void army_personal_dashboard(void)
{
    flag3:
        int ch;
        cout << "\n\n\tPersonel Dashboard Login\n";
        cout << "  ----------------------------------\n\n";
        cout << "\n1. Sepoy login";
        cout << "\n2. Lieutenant login";
        cout << "\n3. Major login";
        cout << "\n4. General login";
        cout << "\n5. Exit";
        cout << "\n9. Return to Previous menu";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
            case 1:
                sepoy_login();
                break;
            case 2:
                lieu_login();
                break;
            case 3:
                major_login();
                break;
            case 4:
                general_login();
            case 5:
                cout <<"\nExiting the Program...\n";
                exit(0);
            case 9:
                cout << "Going back to previous menu..." << endl;
                army_field();
                break;
            default:
                cout << "Error: Invalid Choice Selection\n\n";
        }
        goto flag3;
}

void add_user(void)     
{
    int choice;
    cout << "\n\t\tSELECT POST: ";
    cout << "\n1. General-Soldier:"; //sepoy
    cout << "\n2. Lieutenant";
    cout << "\n3. Major";
    cout << "\n4. General";
    cout << "\nEnter your choice: ";
    cin >> choice;
    int n;
    cout << "\nEnter the number of details: ";
    cin >> n;
    if (choice == 1)
    {
        sepoy obj;
        ofstream oFile;
        oFile.open("sepoy.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_sepoy();
            oFile.write((char *)&obj, sizeof(sepoy));
        }
        oFile.close();
        cout << "\n\nSepoy record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 2)
    {
        lieutenant obj;
        ofstream oFile;
        oFile.open("lieu.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_lieutenant();
            oFile.write((char *)&obj, sizeof(lieutenant));
        }
        oFile.close();
        cout << "\n\nlieutinant record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 3)
    {
        Major obj;
        ofstream oFile;
        oFile.open("major.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_major();
            oFile.write((char *)&obj, sizeof(Major));
        }
        oFile.close();
        cout << "\n\nmajor record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 4)
    {
        general obj;
        ofstream oFile;
        oFile.open("general.bin", ios::binary | ios::app);
        obj.getter_general();
        oFile.write((char *)&obj, sizeof(general));
        oFile.close();
        cout << "\n\nGeneral record has Been Created ";
        cin.ignore();
        cin.get();
    }
    else
        cout << "\nEnter correct choice" << endl;
}
void sepoy_login(void)
{
    cout << "\n\n\tWelcome to Sepoy login\n";
    cout << "   ----------------------------------\n\n";
    string sepoy_id;
    string password;
    cout << "\nEnter sepoy Id: ";
    cin >> sepoy_id;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file; //read and write mode
    file.open("sepoy.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg);
    sepoy obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(sepoy)))
    {
        if (obj.ret_sep_id() == sepoy_id && obj.get_password() == password)
        {
            found = true;
            cout <<"\nSepoy Privileges:-\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_sepoy();
                cout <<"\nEnter any key to continue to previous menu...\n\n";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)&(obj), sizeof(sepoy));
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    army_field();
    cin.ignore();
    cin.get();
}

//lieutenant login
void lieu_login(void)
{
    cout << "\n\n\tWelcome to Lieutenant login\n";
    cout << "   ----------------------------------\n\n";
    string lieu_id;
    string password;
    cout << "\nEnter Lieutenant Id: ";
    cin >> lieu_id;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file; //opening in read mode
    file.open("lieu.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg); //setting the file pointer at the beginning of file
    lieutenant obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(lieutenant)))
    {
        if (obj.ret_lieu_id() == lieu_id && obj.get_password() == password)
        {
            found = true;
            cout <<"\nLieutenant Privileges:-\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_lieutenant();
                cout << "\nEnter any key to return to the previous menu...\n\n";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)(&obj), sizeof(lieutenant));
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    army_field();
    cin.ignore();
    cin.get();
}
void major_login()
{
    cout << "\n\n\tWelcome to Major login\n";
    cout << "   ----------------------------------\n\n";
    string major_id;
    string password;
    cout << "\nEnter Major ID: ";
    cin >> major_id;
    cout << "\nEnter the password ";
    cin >> password;
    fstream file; //opening in read and write mode
    file.open("major.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg); //setting the file pointer at the beginning of file
    Major obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(Major)))
    {
        if (obj.ret_maj_id() == major_id && obj.get_password() == password)
        {
            found = true;
            cout <<"\nMajor Privileges:-\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "\nEnter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_major();
                cin.ignore();
                cout << "\nEnter any key to return to previous menu...\n\n";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)(&obj), sizeof(Major));
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    army_field();
    cin.ignore();
    cin.get();
}


void general_login(void)
{
flag:
    cout << "\n\n\tWelcome to General login\n";
    cout << "   ----------------------------------\n\n";
    string general_usrnme;
    string password;
    cout << "\nEnter the username: ";
    cin >> general_usrnme;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file;
    file.open("general.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg);
    general obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(general)))
    {
        if (obj.ret_gene_username() == general_usrnme && obj.get_password() == password)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
    flag1:
        char choice;
        cout << "\nGeneral Privileges:-\n";
        cout << "\na. View your Profile";
        cout << "\nb. Update your Password\n";
        cout << "\n1. Add a Personnel";
        cout << "\n2. Modify detail(s) of a Personnel ";
        cout << "\n3. Remove a Personnel";
        cout<<  "\n4. View War Details";
        cout<<  "\n5. Add War Details";
        cout << "\n6. Exit";
        cout << "\n9. Return to Previous Menu\n";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 'a':
            obj.display_general();
            cin.ignore();
            cout << "\nEnter any key to continue...\n";
            cin.get();
            goto flag1;
            break;
        case 'b':
        {
            flag7:
            cout << "\nEnter your current password: ";
            string pass1;
            cin >> pass1;
            if (pass1 == obj.get_password()) //password is same variable for both sepoy and general
            {
                cout <<"\nEnter the new password: ";
                cin >> pass1;
                obj.set_password(pass1);
                int pos = (-1) * static_cast<int>(sizeof(obj));
                file.seekp(pos, ios::cur);
                file.write((char *)&(obj), sizeof(general));
                cout <<"\nPassword Changed Successfully!" << endl;
                cin.ignore();
                cout<<"\nEnter any key to continue...\n";
                cin.get();
            }
            else
            {
                cout<<"\nIncorrect Password Entered...\n";
                goto flag7;
            }
        }
            army_personal_dashboard();
            break;
        case '1':
        {
            string post_name;
            cout << "\nWhom to add(Sepoy/Lieutenant/Major): ";
            cin >> post_name;
            add_personel(post_name);
            goto flag1;
            break;
        }
        case '2':
        {
            string post_name;
            cout << "\nWhom to add(Sepoy/Lieutenant/Major): ";
            cin >> post_name;
            modify_personel(post_name);
            goto flag1;
            break;
        }
        case '3':
        {
            string post_name;
            cout << "\nWhom to add(Sepoy/Lieutenant/Major): ";
            cin >> post_name;
            delete_personel(post_name);
            goto flag1;
            break;
        }
        case '4':
        {
            cout<<"Details of War are:-\n";
            ifstream fl;
            fl.open("war.bin", ios::binary | ios::in);
            if (!fl.is_open())
            {
                cout << "Error: File couldn't be opened...";
                cout << "Exiting the program...";
                exit(0);
            }
            war w;
            fl.seekg(0, ios::beg);
            cout<<"Start_date\tEnd_date\tOpposition\tLocation\tNo_our_casu.\tNo.their_casu.\tExpend.\tResult\n";
            while (fl.read((char *)&w, sizeof(war)))
            {
                w.display_war();
            }
            fl.close();
            cin.ignore();
            cin.get();
        }
        case '5':
        {
            add_war_details();
            cout<<"Returning to Previous menu...\n";
            goto flag1;
        }
        case '6':
            cout << "\nExiting the program..." << endl;
            exit(0);
        case '9':
            cout << "\n\n";
            army_personal_dashboard();
        default:
            cout << "Error: Invalid Choice Selection....";
            goto flag1;
            break;
        }
    }
    else
    {
        cout << "\nRecord not found in the database...";
        cout << "Do you want to try again(y/n)? ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            goto flag;
        }
        else
        {
            cout << "Exiting the program..." << endl;
            exit(0);
        }
    }
    file.close();
    cin.ignore();
    cin.get();
}
void add_personel(string post_name) //add the army personel into the section.bin and seopy.bin
{
    ofstream oFile;
    if (post_name == "Sepoy")
    {
        sepoy obj;
        oFile.open("sepoy.bin", ios::binary | ios::app);
        obj.getter_sepoy();
        oFile.write((char *)&obj, sizeof(sepoy));
        //adding that object into the section.bin file depending upon the section of the sepoy
        
        section_army sec_amy; //object to change the details in the section_army.bin file
        fstream fptr;
        fptr.open("army_section.bin", ios::binary | ios::in | ios::out);
        int secNo = obj.ret_sepoy_sec_id();
        int pos = (secNo - 1) * static_cast<int>(sizeof(sec_amy));
        fptr.seekg(pos, ios::beg);
        fptr.read((char *)&sec_amy, sizeof(section_army));
        sec_amy++;
        pos = (-1) * static_cast<int>(sizeof(sec_amy));
        fptr.seekp(pos, ios::cur);
        fptr.write((char *)&sec_amy, sizeof(section_army));
        fptr.close();
        cin.ignore();
        cin.get();
        
        cout<<"\nSepoy record has been created successfully!!\n";
    }
    else if (post_name == "Lieutenant")
    {
        lieutenant obj;
        oFile.open("lieu.bin", ios::binary | ios::app);
        obj.getter_lieutenant();
        oFile.write((char *)&obj, sizeof(lieutenant));
        cout<<"\nLieutenant record has been created successfully!!\n";
    }
    else if (post_name == "Major")
    {
        Major obj;
        oFile.open("major.bin", ios::binary | ios::app);
        obj.getter_major();
        oFile.write((char *)&obj, sizeof(Major));
        cout<<"\nMajor record has been created successfully!!\n";
    }
    else
    {
        cout <<"Error: Invalid Post-Name Inputted!!\n";
    }
    oFile.close();
    cin.ignore();
    cin.get();
    general_login();
}
void modify_personel(string post_name)
{
    fstream fl;
    string id;
    cout << "\nEnter the Id:";
    cin >> id;
    bool found = false;
    if (post_name == "Sepoy")
    {
        fl.open("sepoy.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        sepoy obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(sepoy));
            if (obj.ret_sep_id() == id)
            {
                obj.modify_sepoy(); 
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(sepoy));
                cout << "\n\n\tRecord Updated";
                found = true;
            }
        }
    }
    else if (post_name == "Lieutenant")
    {
        fl.open("lieu.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        lieutenant obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(lieutenant));
            if (obj.ret_lieu_id() == id)
            {
                obj.modify_lieutenant(); 
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(lieutenant));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
    }
    else if (post_name == "Major")
    {
        fl.open("major.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        Major obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(Major));
            if (obj.ret_maj_id() == id)
            {
                obj.modify_major(); 
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(Major));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
    }
    else
    {
        cout << "\nInvalid Post-Name...";
        return;
    }
    fl.close();
    if (found == false)
        cout << "\n\n Record Not Found... ";
    cin.ignore();
    cin.get();
}

void delete_personel(string post_name)
{
    string id;
    cout << "Enter the Id: ";
    cin >> id;
    ifstream iFile;
    ofstream oFile;
    oFile.open("temp.bin", ios::binary | ios::out);
    oFile.seekp(0, ios::beg);
    if (post_name == "Sepoy")
    {
        iFile.open("sepoy.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        iFile.seekg(0, ios::beg);
        sepoy obj;
        while (iFile.read((char *)(&obj), sizeof(sepoy)))
        {
            if (obj.ret_sep_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(sepoy));
            }
        }
        oFile.close();
        iFile.close();
        remove("sepoy.bin");
        rename("temp.bin", "sepoy.bin");
    }
    else if (post_name == "Lieutenant")
    {
        iFile.open("lieu.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        iFile.seekg(0, ios::beg);
        lieutenant obj;
        while (iFile.read((char *)(&obj), sizeof(lieutenant)))
        {
            if (obj.ret_lieu_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(lieutenant));
            }
        }
        oFile.close();
        iFile.close();
        remove("lieu.bin");
        rename("temp.bin", "lieu.bin");
    }
    else if (post_name == "Major")
    {
        iFile.open("major.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        iFile.seekg(0, ios::beg);
        Major obj;
        while (iFile.read((char *)(&obj), sizeof(Major)))
        {
            if (obj.ret_maj_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(Major));
            }
        }
        oFile.close();
        iFile.close();
        remove("major.bin");
        rename("temp.bin", "major.bin");
    }
    else
    {
        cout << "\nInvalid Post.....";
        return;
    }
    cout <<"\n\n\tRecord Deleted Successfully...";
    cin.ignore();
    cin.get();
}

void war_details(void)
{
    string username;
    string password;
    cout << "\nEnter Username: ";
    cin >> username;
    cout << "\nEnter Password: ";
    cin >> password;
    ifstream file;
    file.open("general.bin", ios::binary | ios::in);
    if (!file.is_open())
    {
        cout << "\nError: File couldn't be opened...";
        cout << "\nExiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg);
    general obj;
    bool found = false;
    while (!file.eof() && found == false)
    {
        file.read((char *)&obj, sizeof(general));
        if (obj.ret_gene_username() == username && obj.get_password() == password)
        {
            found = true;
            break;
        }
    }
    file.close();     //general file is closed here
    if (found)
    {
        flag:
        int choice;
        cout << "\n\nChoose the following options:- ";
        cout << "\n1. View War History";
        cout << "\n2. Add War Details";
        cout << "\n3. Exit";
        cout << "\n9. Return to Previous Menu";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            ifstream fl;
            fl.open("war.bin", ios::binary | ios::in);
            if (!fl.is_open())
            {
                cout << "Error: File couldn't be opened...";
                cout << "Exiting the program...";
                exit(0);
            }
            war obj;
            fl.seekg(0, ios::beg);
            cin.ignore();
            cout<<"Start_date\tEnd_date\tOpposition\tLocation No_our_casu.\tNo.their_casu.\tExpend.\tResult\n";
            while (fl.read((char *)&obj, sizeof(war)))
            {
                obj.display_war();
            }
            fl.close();
            cin.ignore();
            cin.get();
        }
        break;
        case 2:
        {
            ofstream fl;
            fl.open("war.bin", ios::binary | ios::app);
            if (!fl.is_open())
            {
                cout << "Error: File couldn't be opened...";
                cout << "Exiting the program...";
                exit(0);
            }
            war obj;
            int n;
            cout << "\nEnter the number of details: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                obj.getter_war();
                fl.write((char *)&obj, sizeof(war));
            }
            fl.close();
            cin.get();
            cin.ignore();
        }
        break;
        case 3:
            cout<<"\nExiting the program...";
            exit(0);
        case 9:
            army_field();
            break;
        default:
            cout<<"Error: Invalid Choice Selection\n";
            break;
        }
        goto flag;
    }
    else
    {
        cout<<"\nIncorrect Credentials...\n";
        cout<<"Returning to Previous Menu...\n";
    }
}


void add_airforce_section_detail(void)
{
    ofstream fptr;
    fptr.open("airforce_section.bin", ios::binary|ios::app);
    if (!fptr.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    section_airforce s;
    s.getter_section_airforce();
    fptr.write((char*)&s , sizeof(section_airforce));
    fptr.close();
    cin.ignore();
    cin.get();
}

void add_airforce_personel(string post_name)
{
    ofstream oFile;
    if (post_name == "Aircraftman")
    {
        aircraftman obj;
        oFile.open("aircraftman.bin", ios::binary | ios::app);
        obj.getter_aircraftsman();
        oFile.write((char *)&obj, sizeof(aircraftman));
        
        section_airforce sec_air; //object to change the details in the section_army.bin file
        fstream fptr;
        fptr.open("airforce_section.bin", ios::binary | ios::in | ios::out);
        int secNo = obj.ret_aircraftman_sec_id();
        int pos = (secNo - 1) * static_cast<int> (sizeof(sec_air));
        fptr.seekg(pos, ios::beg);
        fptr.read((char *)&sec_air, sizeof(section_airforce));
        sec_air++;
        pos = (-1) * static_cast<int>(sizeof(sec_air));
        fptr.seekg(pos, ios::cur);
        fptr.write((char *)&sec_air, sizeof(section_airforce));
        fptr.close();
        cin.ignore();
        cin.get();
        cout<<"\nAircraftman record has been created successfully!!\n";
    }
    else if (post_name == "Flight Lieutenant")
    {
        flight_lieutenant obj;
        oFile.open("flight_lieu.bin", ios::binary | ios::app);
        obj.getter_flight_lieutenant();
        oFile.write((char *)&obj, sizeof(flight_lieutenant));
        cout<<"\nFlight Lieutenant record has been created successfully!!\n";
    }
    else if (post_name == "Squadron Leader")
    {
        squadron_leader obj;
        oFile.open("squadron_leader.bin", ios::binary | ios::app);
        obj.getter_squadron_leader();
        oFile.write((char *)&obj, sizeof(squadron_leader));
        cout<<"\nSquadron Leader record has been created successfully!!\n";
    }
    else
    {
       cout <<"Error: Invalid Post-Name Inputted!!\n";
    }
    oFile.close();
    cin.ignore();
    cin.get();
    air_chief_marshal_login();
}


void modify_airforce_personel(string post_name)
{
    fstream fl;
    string id;
    cout << "\nEnter the Id:";
    cin >> id;
    bool found = false;
    if (post_name == "Aircraftman")
    {
        fl.open("aircraftman.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        aircraftman obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(aircraftman));
            if (obj.ret_air_id() == id)
            {
                obj.modify_aircraftman(); 
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(aircraftman));
                cout << "\n\n\tRecord Updated";
                found = true;
            }
        }
    }
    else if (post_name == "Flight Lieutenant")
    {
        fl.open("flight_lieu.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        flight_lieutenant obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(flight_lieutenant));
            if (obj.ret_fli_lieu_id() == id)
            {
                obj.modify_flight_lieutenant(); 
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(flight_lieutenant));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
    }
    else if (post_name == "Squadron Leader")
    {
        fl.open("squadron_leader.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        squadron_leader obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(squadron_leader));
            if (obj.ret_sqdl_id() == id)
            {
                obj.modify_sqd_leader();
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(squadron_leader));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
    }
    else
    {
        cout << "\nInvalid Post-Name...";
        return;
    }
    fl.close();
    if (found == false)
        cout << "\n\n Record Not Found... ";
    cin.ignore();
    cin.get();
}


void war_details_airforce(void)      //air chief marshal accessses war details using this
{
    string username;
    string password;
    cout << "\nEnter Username: ";
    cin >> username;
    cout << "\nEnter Password: ";
    cin >> password;
    ifstream file;
    file.open("airchief.bin", ios::binary | ios::in);
    if (!file.is_open())
    {
        cout << "\nError: File couldn't be opened...";
        cout << "\nExiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg);
    air_chief_marshall obj;
    bool found = false;
    while (!file.eof() && found == false)
    {
        file.read((char *)&obj, sizeof(general));
        if (obj.ret_air_username() == username && obj.get_password() == password)
        {
            found = true;
            break;
        }
    }
    file.close();     //air chief marshall  file is closed here
    if (found)
    {
        flag:
        int choice;
        cout << "\n\nChoose the following options:- ";
        cout << "\n1. View War History";
        cout << "\n2. Add War Details";
        cout << "\n3. Exit";
        cout << "\n9. Return to Previous Menu";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            ifstream fl;
            fl.open("war.bin", ios::binary | ios::in);
            if (!fl.is_open())
            {
                cout << "Error: File couldn't be opened...";
                cout << "Exiting the program...";
                exit(0);
            }
            war obj;
            fl.seekg(0, ios::beg);
            cin.ignore();
            cout<<"Start_date\tEnd_date\tOpposition\tLocation No_our_casu.\tNo.their_casu.\tExpend.\tResult\n";
            while (fl.read((char *)&obj, sizeof(war)))
            {
                obj.display_war();
            }
            fl.close();
            cin.ignore();
            cin.get();
        }
        break;
        case 2:
        {
            ofstream fl;
            fl.open("war.bin", ios::binary | ios::app);
            if (!fl.is_open())
            {
                cout << "Error: File couldn't be opened...";
                cout << "Exiting the program...";
                exit(0);
            }
            war obj;
            int n;
            cout << "\nEnter the number of details: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                obj.getter_war();
                fl.write((char *)&obj, sizeof(war));
            }
            fl.close();
            cin.get();
            cin.ignore();
        }
        break;
        case 3:
            cout<<"\nExiting the program...";
            exit(0);
        case 9:
            airforce_field();
            break;
        default:
            cout<<"Error: Invalid Choice Selection\n";
            break;
        }
        goto flag;
    }
    else
    {
        cout<<"\nIncorrect Credentials\n";
        cout<<"Returning to Previous Menu...\n";
    }
}



void delete_airforce_personel(string post_name)
{
    string id;
    cout << "Enter the Id: ";
    cin >> id;
    ifstream iFile;
    ofstream oFile;
    oFile.open("temp.bin", ios::binary | ios::out);
    oFile.seekp(0, ios::beg);
    if (post_name == "Aircraftman")
    {
        iFile.open("aircraftman.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        iFile.seekg(0, ios::beg);
        aircraftman obj;
        while (iFile.read((char *)(&obj), sizeof(aircraftman)))
        {
            if (obj.ret_air_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(aircraftman));
            }
        }
        oFile.close();
        iFile.close();
        remove("aircraftman.bin");
        rename("temp.bin", "aircraftman.bin");
    }
    else if (post_name == "Flight Lieutenant")
    {
        iFile.open("flight_lieu.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        iFile.seekg(0, ios::beg);
        flight_lieutenant obj;
        while (iFile.read((char *)(&obj), sizeof(flight_lieutenant)))
        {
            if (obj.ret_fli_lieu_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(flight_lieutenant));
            }
        }
        oFile.close();
        iFile.close();
        remove("flight_lieu.bin");
        rename("temp.bin", "flight_lieu.bin");
    }
    else if (post_name == "squadron_leader")
    {
        iFile.open("squadron_leader.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        iFile.seekg(0, ios::beg);
        squadron_leader obj;
        while (iFile.read((char *)(&obj), sizeof(squadron_leader)))
        {
            if (obj.ret_sqdl_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(squadron_leader));
            }
        }
        oFile.close();
        iFile.close();
        remove("squadron_leader.bin");
        rename("temp.bin", "squadron_leader.bin");
    }
    else
    {
        cout << "\nInvalid Post.....";
        return;
    }
    cout <<"\n\n\tRecord Deleted Successfully...";
    cin.ignore();
    cin.get();
}

void airforce_field()
{
    flag5:
    cout <<"\n\t\tAir Force Menu\n";
    cout<<"\t-----------------------\n\n";
    cout << "1. Login to Personal Dashboard\n";
    cout << "2. Section-wise weapon allocation\n";
    cout << "3. War Details\n";
    cout << "4. Exit\n";
    cout << "9. Return to Previous Menu\n";
    cout << "\n\nEnter your choice: ";
    char choice;
    cin >> choice;
    switch (choice)
    {
    case '1':
        air_personal_dashboard();
        break;
    case '2':
        {
            ifstream fptr;
            fptr.open("airforce_section.bin", ios::in | ios::binary);
            if (!fptr.is_open())
            {
                cout << "Error: File couldn't be opened...";
                cout << "Exiting the program...";
                exit(0);
            }
            section_airforce sec_air;
            int i{1};
            fptr.seekg(0 , ios::beg);
            while (fptr.read((char *)&sec_air, sizeof(section_airforce)))
            {
                cout << "Section " << i << endl;
                cout << "------------" << endl;
                sec_air.print_section_weapon_info();
                i++;
            }
            fptr.close();
            cin.ignore();
            cin.get();
    }
    break;
    case '3':
    {
        cout<<"\nNote: Only Air Chief Marshal can view and add war details\n\n";
        cout<<"Do you want to continue(y/n)? ";
        char choice;
        cin>>choice;
        if(choice=='y'||choice == 'Y')
        {
            war_details_airforce();      //air chief login dashboard then view history and add war
        }
        else
        {
            cout<<"\nReturning to Previous Menu...\n\n";
            goto flag5;
        }
        break;
    }
    case '4':
        cout <<"\nExiting the Program...\n";
        exit(0);
        break;
    case '9':
        main_menu();
    default:
        cout << "Error: Invalid Choice Selection"<< endl;
    }
    goto flag5;
}

void air_personal_dashboard(void)
{
    flag3:
        char ch;
        cout << "\n\n\tPersonel Dashboard Login\n";
        cout << "  ----------------------------------\n\n";
        cout << "\n1. Aircraftman login";
        cout << "\n2. Flight Lieutenant login";
        cout << "\n3. Squadron Leader login";
        cout << "\n4. Airforce Cheif Marshal login";
        cout << "\n5. Exit";
        cout << "\n9. Return to Previous menu";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
            case '1':
                aircraftman_login();
                break;
            case '2':
                flight_lieu_login();
                break;
            case '3':
                squad_leader_login();
                break;
            case '4':
                air_chief_marshal_login();
            case '5':
                cout <<"\nExiting the Program...\n";
                exit(0);
            case '9':
                cout << "Going back to previous menu..." << endl;
                airforce_field();
                break;
            default:
                cout << "Error: Invalid Choice Selection\n\n";
        }
        goto flag3;
}

void add_airforce_user(void) ////////////////////
{
    int choice;
    cout << "\n\t\tSELECT POST: ";
    cout << "\n1. Aircraftman:";
    cout << "\n2. Flight Lieutenant";
    cout << "\n3. Squadron Leader";
    cout << "\n4. Air Chief Marshall";
    cout << "\nEnter your choice: ";
    cin >> choice;
    int n;
    cout << "\nEnter the number of details: ";
    cin >> n;
    if (choice == 1)
    {
        aircraftman obj;
        ofstream oFile;
        oFile.open("aircraftman.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_aircraftsman();
            oFile.write((char *)&obj, sizeof(aircraftman));
        }
        oFile.close();
        cout << "\n\nAircraftman record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 2)
    {
        flight_lieutenant obj;
        ofstream oFile;
        oFile.open("flight_lieu.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_flight_lieutenant();
            oFile.write((char *)&obj, sizeof(flight_lieutenant));
        }
        oFile.close();
        cout << "\n\nflight lieutinant record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 3)
    {
        squadron_leader obj;
        ofstream oFile;
        oFile.open("squadron_leader.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_squadron_leader();
            oFile.write((char *)&obj, sizeof(squadron_leader));
        }
        oFile.close();
        cout << "\nSquadron Leader record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 4)
    {
        air_chief_marshall obj;
        ofstream oFile;
        oFile.open("airchief.bin", ios::binary | ios::app);
        obj.getter_air_chief();
        oFile.write((char *)&obj, sizeof(air_chief_marshall));
        oFile.close();
        cout << "\nAir Cheif Marshal record has Been Created\n ";
        cin.ignore();
        cin.get();
    }
    else
        cout << "\nEnter correct choice" << endl;
}

void aircraftman_login(void)
{
    cout << "\n\n\tWelcome to Aircraftman login\n";
    cout << "   ----------------------------------------\n\n";
    string aircraftman_id;
    string password;
    cout << "\nEnter aircraftman Id: ";
    cin >> aircraftman_id;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file; //read mode
    file.open("aircraftman.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg);
    aircraftman obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(aircraftman)))
    {
        if (obj.ret_air_id() == aircraftman_id && obj.get_password() == password)
        {
            found = true;
            cout <<"\nAircraftman Privileges:-\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_aircraftman();
                cin.ignore();
                cout <<"\nEnter any key to continue to previous menu...\n\n";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)&(obj), sizeof(aircraftman));
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    airforce_field();
    cin.ignore();
    cin.get();
}

void flight_lieu_login()
{
    cout << "\n\n\tWelcome to Flight Lieutenant login\n";
    cout << "   ----------------------------------------\n\n";
    string flight_lieu_id;
    string password;
    cout << "\nEnter Flight Lieutenant Id: ";
    cin >> flight_lieu_id;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file; //opening in read mode
    file.open("flight_lieu.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg); //setting the file pointer at the beginning of file
    flight_lieutenant obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(flight_lieutenant)))
    {
        if (obj.ret_fli_lieu_id() == flight_lieu_id && obj.get_password() == password)
        {
            found = true;
            cout <<"\nFlight Lieutenant Privileges:-\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_flight_lieutenant();
                cout << "\nEnter any key to return to the previous menu...\n\n";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)(&obj), sizeof(flight_lieutenant));
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    airforce_field();
    cin.ignore();
    cin.get();
}

void squad_leader_login()
{
    cout << "\n\n\tWelcome to Squadron Leader login\n";
    cout << "   ---------------------------------------------\n\n";
    string squadron_leader_id;
    string password;
    cout << "\nEnter Squadron Leader ID: ";
    cin >> squadron_leader_id;
    cout << "\nEnter the password ";
    cin >> password;
    fstream file; //opening in read and write mode
    file.open("squadron_leader.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg); //setting the file pointer at the beginning of file
    squadron_leader obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(squadron_leader)))
    {
        if (obj.ret_sqdl_id() == squadron_leader_id && obj.get_password() == password)
        {
            found = true;
            cout <<"\nSquadron Leader Privileges:-\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_sqa_leader();
                cout << "\nEnter any key to return to previous menu...\n\n";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)(&obj), sizeof(squadron_leader));
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    airforce_field();
    cin.ignore();
    cin.get();
}

void air_chief_marshal_login(void)
{
flag:
    cout << "\n\n\tWelcome to Air Chief Marshal login\n";
    cout << "   ----------------------------------\n\n";
    string air_cheif_usrnme;
    string password;
    cout << "\nEnter the username: ";
    cin >> air_cheif_usrnme;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file;
    file.open("airchief.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg);
    air_chief_marshall obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(air_chief_marshall)))
    {
        if (obj.ret_air_username() == air_cheif_usrnme && obj.get_password() == password)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
    flag1:
        char choice;
        cout << "\nAir Chief Marshal Privileges:-\n";
        cout << "\na. View your Profile";
        cout << "\nb. Update your Password\n";
        cout << "\n1. Add a Personel";
        cout << "\n2. Modify detail(s) of a Personel";
        cout << "\n3. Remove a Personel: ";
        cout<<  "\n4. View War Details";
        cout<<  "\n5. Add War Details";
        cout << "\n6. Exit";
        cout << "\n9. Return to Previous Menu\n";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 'a':
            obj.display_air_chief();
            cin.ignore();
            cout << "\nEnter any key to continue...\n";
            cin.get();
            goto flag1;
            break;
        case 'b':
        {
            flag7:
            cout << "\nEnter your current password: ";
            string pass1;
            cin >> pass1;
            if (pass1 == obj.get_password()) //password is same variable for both sepoy and general
            {
                cout << "Enter the new password: ";
                cin >> pass1;
                obj.set_password(pass1);
                int pos = (-1) * static_cast<int>(sizeof(obj));
                file.seekp(pos, ios::cur);
                file.write((char *)&(obj), sizeof(air_chief_marshall));
                cout <<"\nPassword Changed Successfully!" << endl;
                cin.ignore();
                cout<<"\nEnter any key to continue...\n";
                cin.get();
            }
            else 
            {
                cout<<"\nIncorrect Password Entered...\n";
                goto flag7;
            }
        }
            air_personal_dashboard();
            break;
        case '1':
        {
            string post_name;
            cout << "\nWhom to add(Aircraftman/Flight Lieutenant/Squadron Leader): ";
            cin >> post_name;
            add_airforce_personel(post_name);
            goto flag1;
            break;
        }
        case '2':
        {
            string post_name;
            cout << "\nWhom to modify(Aircraftman/Flight Lieutenant/Squadron Leader): ";
            cin >> post_name;
            modify_airforce_personel(post_name);
            goto flag1;
            break;
        }
        case '3':
        {
            string post_name;
            cout << "\nWhom to remove(Aircraftman/Flight Lieutenant/Squadron Leader): ";
            cin >> post_name;
            delete_airforce_personel(post_name);
            goto flag1;
            break;
        }
        case '4':
        {
            cout<<"Details of War are:-\n";
            ifstream fl;
            fl.open("war.bin", ios::binary | ios::in);
            if (!fl.is_open())
            {
                cout << "Error: File couldn't be opened...";
                cout << "Exiting the program...";
                exit(0);
            }
            war w;
            fl.seekg(0, ios::beg);
            cout<<"Start_date\tEnd_date\tOpposition\tLocation\tNo_our_casu.\tNo.their_casu.\tExpend.\tResult\n";
            while (fl.read((char *)&w, sizeof(war)))
            {
                w.display_war();
            }
            fl.close();
            cin.ignore();
            cin.get();
        }
        case '5':
        {
            add_war_details();
            cout<<"Returning to Previous menu...\n";
            goto flag1;
        }
        case '6':
            cout << "\nExiting the program..." << endl;
            exit(0);
        case '9':
            cout << "\n\n";
            air_personal_dashboard();
        default:
            cout << "Error: Invalid Choice Selection....";
            goto flag1;
            break;
        }
    }
    else
    {
        cout << "\nRecord not found in the database...";
        cout << "Do you want to try again(y/n)? ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            goto flag;
        }
        else
        {
            cout << "Exiting the program..." << endl;
            exit(0);
        }
    }
    file.close();
    cin.ignore();
    cin.get();
}


void cds_field(void)
{
    cds_login();
}
void cds_login(void)
{
    cout<<"\n\n\tCheif of Defence Staff\n";
    cout<<"    ---------------------------\n\n";
    string username;
    string password;
    cout << "\nEnter Username: ";
    cin >> username;
    cout << "\nEnter Password: ";
    cin >> password;
    fstream file;
    file.open("cds.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    bool found = false;
    cds obj;
    file.seekg(0, ios::beg);
    while (!file.eof() && found == false)
    {
        file.read((char *)&obj, sizeof(cds));
        if (obj.ret_username_cds() == username && obj.ret_password_cds() == password)
        {
            found = true;
            cout<<"\nYour Profile:-\n";
            obj.display_cds();
            break;
        }
    }
    if (found)
    {
        flag:
        int ch;
        cout<<"\n\tCDS Previlages\n";
        cout<<"   --------------------\n";
        cout << "\n1. Password Change ";
        cout << "\n2. Army Details";
        cout << "\n3. Airforce Details";
        cout << "\n4. War Details";
        cout<<"\n5. Logout";
        cout<<"\n6. Exit";
        cout << "\n\nEnter your Choice ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter your current password: ";
            string pass1;
            cin >> pass1;
            if (pass1 == obj.ret_password_cds())
            {
                cout << "Enter the new password: ";
                cin >> pass1;
                // change_pass_sepoy(obj.ret_sep_id(), pass1, "Sepoy");
                obj.set_password_cds(pass1);
                int pos = (-1) * static_cast<int>(sizeof(obj));
                file.seekp(pos, ios::cur);
                file.write((char *)&(obj), sizeof(cds));
                cout << "\nPassword Changed Successfully!" << endl;
            }
            break;
        }
        case 2:
        {
            int choice;
            cout << "\n1. Weapon Details: ";
            cout << "\n2. Sepoy Details: ";
            cout << "\n3. Lieutenant Details:";
            cout << "\n4. Major Details: ";
            cout << "\n5. General Details: ";
            cout << "\nEnter the choice: ";
            cin >> choice;
            if (choice == 1)
            {
                ifstream fptr;
                fptr.open("army_section.bin", ios::in | ios::binary);
                if (!fptr.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                section_army sec_amy;
                int i{1};
                fptr.seekg(0 , ios::beg);
                while (fptr.read((char *)&sec_amy, sizeof(section_army)))
                {
                    cout << "\nSection " << i << endl;
                    cout << "------------" << endl;
                    sec_amy.print_section_weapon_info();
                    i++;
                }
                fptr.close();
                cin.ignore();
                cin.get();
            }
            else if (choice == 2)
            {
                ifstream fl;
                fl.open("sepoy.bin", ios::binary | ios::in);
                if (!fl.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                sepoy s;
                fl.seekg(0, ios::beg);
                while (fl.read((char *)&s, sizeof(sepoy)))
                {
                    s.display_sepoy();
                    cout << endl
                         << endl;
                }
                fl.close();
                cin.ignore();
                cin.get();
            }
            else if (choice == 3)
            {
                ifstream fl;
                fl.open("lieu.bin", ios::binary | ios::in);
                if (!fl.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                lieutenant l;
                fl.seekg(0, ios::beg);
                while (fl.read((char *)&l, sizeof(lieutenant)))
                {
                    l.display_lieutenant();
                    cout << endl<< endl;
                }
                fl.close();
                cin.ignore();
                cin.get();
            }
            else if (choice == 4)
            {
                ifstream fl;
                fl.open("major.bin", ios::binary | ios::in);
                if (!fl.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                Major m;
                fl.seekg(0, ios::beg);
                while (fl.read((char *)&m, sizeof(Major)))
                {
                    m.display_major();
                    cout << endl<< endl;
                }
                fl.close();
                cin.ignore();
                cin.get();
            }
            else if (choice == 5)
            {
                ifstream fl;
                fl.open("general.bin", ios::binary | ios::in);
                if (!fl.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                general g;
                fl.seekg(0, ios::beg);
                while (fl.read((char *)&g, sizeof(general)))
                {
                    g.display_general();
                    cout << endl << endl;
                }
                fl.close();
                cin.ignore();
                cin.get();
            }
            else
            {
                cout << "\nInvalid Operation.....";
            }
            goto flag;
            break;
        }
        case 3:
        {
            int choice;
            cout <<" CDS Air Force Privileges:-\n";
            cout << "\n1. Weapon Details ";
            cout << "\n2. Aircraftman Details";
            cout << "\n3. Flight Lieu Details";
            cout << "\n4. Squadraon Leader Details";
            cout << "\n5. Chief Air Marshall Details";
            cout << "\nEnter your choice: ";
            cin >> choice;
            if (choice == 1)
            {
                ifstream fptr;
                fptr.open("airforce_section.bin", ios::in | ios::binary);
                if (!fptr.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                section_airforce sec_air;
                int i{1};
                fptr.seekg(0 , ios::beg);
                while (fptr.read((char *)&sec_air, sizeof(section_airforce)))
                {
                    cout << "\nSection " << i << endl;
                    cout << "------------" << endl;
                    sec_air.print_section_weapon_info();
                    i++;
                }
                fptr.close();
                cin.ignore();
                cin.get();
            }
            else if (choice == 2)
            {
                ifstream fl;
                fl.open("aircraftman.bin", ios::binary | ios::in);
                if (!fl.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                aircraftman s;
                fl.seekg(0, ios::beg);
                while (fl.read((char *)&s, sizeof(aircraftman)))
                {
                    s.display_aircraftman();
                    cout << "\n\n";
                }
                fl.close();
                cin.ignore();
                cin.get();
            }
            else if (choice == 3)
            {
                ifstream fl;
                fl.open("flight_lieu.bin", ios::binary | ios::in);
                if (!fl.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                flight_lieutenant s;
                fl.seekg(0, ios::beg);
                while (fl.read((char *)&s, sizeof(flight_lieutenant)))
                {
                    s.display_flight_lieutenant();
                    cout << "\n\n";
                }
                fl.close();
                cin.ignore();
                cin.get();
            }
            else if (choice == 4)
            {
                ifstream fl;
                fl.open("squadron_leader.bin", ios::binary | ios::in);
                if (!fl.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                squadron_leader s;
                fl.seekg(0, ios::beg);
                while (fl.read((char *)&s, sizeof(squadron_leader)))
                {
                    s.display_sqa_leader();
                    cout << "\n\n";
                }
                fl.close();
                cin.ignore();
                cin.get();
            }
            else if (choice == 5)
            {
                ifstream fl;
                fl.open("airchief.bin", ios::binary | ios::in);
                if (!fl.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                air_chief_marshall s;
                fl.seekg(0, ios::beg);
                while (fl.read((char *)&s, sizeof(air_chief_marshall)))
                {
                    s.display_air_chief();
                    cout << "\n\n";
                }
                fl.close();
                cin.ignore();
                cin.get();
            }
            goto flag;
            break;
        }
        case 4:
        {
            ifstream fl;
            fl.open("war.bin", ios::binary | ios::in);
            if (!fl.is_open())
            {
                cout << "Error: File couldn't be opened...";
                cout << "Exiting the program...";
                exit(0);
            }
            war w;
            fl.seekg(0, ios::beg);
            cout<<"Start_date\tEnd_date\tOpposition\tLocation\tNo_our_casu.\tNo.their_casu.\tExpend.\tResult\n";
            while (fl.read((char *)&w, sizeof(war)))
            {
                w.display_war();
            }
            fl.close();
            cin.ignore();
            cin.get();
        }
        goto flag;
        break;
        case 5:
            cout<<"\nLogging Out...\n";
            return;
        case 6:
            cout<<"\nExiting the program...\n";
            exit(0);
        default:
            cin.ignore();
            cout << "\nError: Invalid Choice Selection...";
            cout<<"\nEnter any key to continue...\n";
            cin.get();
            goto flag;
        }
    }
    else
        cout << "\nRecord not Found...\n";
    file.close();
    cin.ignore();
    cin.get();
}

void add_war_details(void)  
{
    ofstream file;
    file.open("war.bin", ios::binary | ios::app);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    int n;
    war obj;
    cout << "\nHow many details do you want to enter: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        obj.getter_war();
        file.write((char *)&obj, sizeof(war));
    }
    file.close();
    cin.ignore();
    cin.get();
}






