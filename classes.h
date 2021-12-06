
#include<iostream>
#include<string>

using namespace std;

//-------------------------------------
//class definitions Starts here
//-------------------------------------
class date //for storing dates
{
    private:
        unsigned day, month, year;

    public:
        void getter_date()
        {
            cout << "Enter the day/month/year separated by space: ";
            cin >> day >> month >> year;
        }
        void display_date()
        {
            cout << day << "-" << month << "-" << year;
        }
};

class sepoy
{
    private:
        string sepoy_id; //only for sepoys and hence not inheritable
    protected:
        string name;
        date date_of_birth;   //containership  //age can be calculated by this
        date date_of_joining; //containership
        string password;      //for storing password

    private: //not inheritable information
        string sepoy_section_id;

    public:
        void getter()
        {
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Date of Birth:  ";
            date_of_birth.getter_date();
            cout << "Date of Joining: ";
            date_of_joining.getter_date();
        flag1:
            cout << "Set your password:\n";
            cout << "Enter new password: ";
            string pass1, pass2;
            cin >> pass1;
            cout << "Confirm new password: ";
            cin >> pass2;
            if (pass1 == pass2)
            {
                set_password(pass2);
            }
            else
            {
                cout << "\nPassword Not Matched\n";
                goto flag1;
            }
        }

        void getter_sepoy()   //takes the information input for sepoy
        {
            cout << "Enter Sepoy Id: ";
            cin >> sepoy_id;
            getter();
            cout << "Enter Section Id(sec1 to sec6): "; //there are 6 sections from sec1 to sec6. This means there should be only 6 objects created into the section.bin file
            cin >> sepoy_section_id;                    //sec1, sec2, sec3, ..., sec6
        }
        void display()
        {
            cout <<"\nName : " << name;
            cout <<"\nDate Of Birth : ";
            date_of_birth.display_date();
            cout <<"\nDate Of Joining : ";
            date_of_joining.display_date();
        }
        void display_sepoy()
        {
            cout <<"\nSepoy ID : " << sepoy_id;
            display();
            cout << "\nSection ID : " <<sepoy_section_id;

        }
        void set_password(string pass)
        {
            this->password = pass;
        }
        string get_password()
        {
            return password;
        }
        string ret_sep_id()
        {
            return sepoy_id;
        }
        string ret_sep_name()
        {
            return name;
        }
        int ret_sepoy_sec_id()
        {
            if (sepoy_section_id == "sec1")
                return 1;
            else if (sepoy_section_id == "sec2")
                return 2;
            else if (sepoy_section_id == "sec3")
                return 3;
            else if (sepoy_section_id == "sec4")
                return 4;
            else if (sepoy_section_id == "sec5")
                return 5;
            else if (sepoy_section_id == "sec6")
                return 6;
            return -1;
        }
        void modify()
        {
            cout << "Enter modified Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Modified Date of Birth:  ";
            date_of_birth.getter_date();
            cout << "Modified Date of Joining: ";
            date_of_joining.getter_date();
        }
        void modify_sepoy()
        {
            modify();
            cout << "Enter modified section Id: ";
            cin >> sepoy_section_id;
        }
        
};

class lieutenant : public sepoy
{
    private:
        string lieutenant_id; //every lieutenent has the unique id
        string section_id; //the id of the section he is leading
    public:
        void getter_lieutenant()
        {
            cout << "Enter Lieutenent ID: ";
            cin >> lieutenant_id;
            sepoy::getter();
            cout << "Enter Section ID: ";
            cin >> section_id;
        }
        void display_lieutenant()
        {
            cout << "\nLieutenant Id: " << lieutenant_id;
            sepoy::display();
            cout << "\nSection Id: " << section_id;
        }
        string ret_lieu_id()
        {
            return lieutenant_id;
        }

        void modify_lieutenant()
        {
            sepoy::modify();
            cout << "Enter modified section Id: ";
            cin >> this->section_id;
        }
};

class Major : public lieutenant    //head of a company
{
    private:
        string major_id;
        string company_id;
        // string platoon_id;

    public:
        void getter_major()
        {
            cout << "Enter Major Id: ";
            cin >> major_id;
            sepoy::getter();
            cout << "Enter company id(com1/com2): ";
            cin >> company_id;
        }
        void display_major()
        {
            cout <<"\nMajor ID: " << major_id;
            sepoy::display();
            cout <<"\nCompany Id: " << company_id;
            cout<<endl;
        };

        string ret_maj_id()
        {
            return major_id;
        }
        void modify_major()
        {
            sepoy::modify();
            cout << "Enter modified company Id: ";
            cin >> this->company_id;
        }
};

class section_army
{
    protected:
        unsigned num_sepoys;
        string section_id;
        string lieutenant_id;
        unsigned num_gun;
        unsigned num_tank;
        unsigned num_mortar;
        unsigned num_combat_shotgun;

    public:
        void operator++(int) //adds a sepoys into the required section
        {
            this->num_sepoys++ ;
        }
        void getter_section_army()
        {
            cout<<"Enter Number of sepoy: ";
            cin>>num_sepoys;
            cout << "Enter section Id: ";
            cin.ignore();
            cin >> section_id;
            cout << "Enter lieutenant Id: ";
            cin >> lieutenant_id;
            cout << "Enter numbers of guns: ";
            cin >> num_gun;
            cout << "Enter number of tanks: ";
            cin >> num_tank;
            cout << "Enter number of mortars: ";
            cin >> num_mortar;
            cout << "Enter number of combat shotguns: ";
            cin >> num_combat_shotgun;
        }

        void print_section_info() 
        {
            cout<<"\nNumber of Sepoy: "<<num_sepoys<<endl;
            cout << " \nLieutenant Id: " << lieutenant_id << endl;
        }
        //prints the weapon information
        void print_section_weapon_info() 
        {
            cout << "The weapons alloted to this section are:-\n";
            cout << "No. of Guns: " << num_gun << endl;
            cout << "No. of Tanks: " << num_tank << endl;
            cout << "No. of Mortars: " << num_mortar << endl;
            cout << "No. of Combat Shotguns: " << num_combat_shotgun << endl;
        }
};

// Army_General can access all the class using multiple inheritance
//can edit the details of any employee 
// can modify the war and weapons data
class general : public Major 
{
    private:
        string general_username;
    public:
        friend class cds;
        void getter_general() //temporary for first entry of General 
        {
            cout << "Enter General Username:  ";
            cin >> general_username;
            sepoy::getter();
        }
        void display_general()
        {
            cout << "\nUsername: " << general_username;
            sepoy::display();
        }
        string ret_gene_username() //returns the username of general which is equivalent of sepoy_id for a sepoy
        {
            return general_username;
        }
        string ret_gen_name() 
        {
            return name;
        }
};


//Airforce Personnel
//--------------------

class aircraftman
{
    private:
        string aircraftman_id; //only for aircraftman and hence not inheritable
    protected:
        string name;
        date date_of_birth;   //containership  //age can be calculated by this
        date date_of_joining; //containership
        string password;      //for storing password

    private: //not inheritable information
        string airman_section_id;

    public:
        void getter()
        {
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Date of Birth:  ";
            date_of_birth.getter_date();
            cout << "Date of Joining: ";
            date_of_joining.getter_date();
        flag1:
            cout << "Set your password:\n";
            cout << "Enter new password: ";
            string pass1, pass2;
            cin >> pass1;
            cout << "Confirm new password: ";
            cin >> pass2;
            if (pass1 == pass2)
            {
                set_password(pass2);
            }
            else
            {
                cout << "\nPassword Not Matched\n";
                goto flag1;
            }
        }
        void getter_aircraftsman() //takes the information input for airman
        {
            cout << "Enter Aircraftman Id: ";
            cin >> aircraftman_id;
            getter();
            cout << "Enter Airman Section Id: ";
            cin >> airman_section_id;
        }

        void display()
        {
            cout << "\nName : " << name;
            cout << "\nDate Of Birth : ";
            date_of_birth.display_date();
            cout << "\nDate Of Joining : ";
            date_of_joining.display_date();
        }
        void display_aircraftman()
        {
            cout << "\nAircraftman Id: " << aircraftman_id;
            display();
            cout << "\nSection Id: " << airman_section_id;
        }
        void set_password(string pass)
        {
            this->password = pass;
        }
        string get_password()
        {
            return password;
        }
        string ret_air_id()
        {
            return aircraftman_id;
        }
        string ret_air_name()
        {
            return name;
        }
        int ret_aircraftman_sec_id()
        {
            if (airman_section_id == "sec1")
                return 1;
            else if (airman_section_id == "sec2")
                return 2;
            else if (airman_section_id == "sec3")
                return 3;
            else if (airman_section_id == "sec4")
                return 4;
            else if (airman_section_id == "sec5")
                return 5;
            else if (airman_section_id == "sec6")
                return 6;
            return -1;
        }
        void modify()
        {
            cout << "Enter modified Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Modified Date of Birth: ";
            date_of_birth.getter_date();
            cout << "Modified Date of Joining: ";
            date_of_joining.getter_date();
        }
        void modify_aircraftman()
        {
            modify();
            cout << "Enter modified section Id: ";
            cin >> airman_section_id;
        }
};

class flight_lieutenant : public aircraftman
{
    private:
        string flight_lieu_id; //every flight lieutenent has they unique id
        string section_id; //the id of the section he is leading
    public:
        void getter_flight_lieutenant()
        {
            cout << "Enter Flight Lieutenent ID: ";
            cin >> flight_lieu_id;
            aircraftman::getter();
            cout << "Enter Section ID: ";
            cin >> section_id;
        }
        void display_flight_lieutenant()
        {
            cout << "\nFlight Lieutenant Id: " << flight_lieu_id;
            aircraftman::display();
            cout << "\nSection Id: " << section_id;
        }
        string ret_fli_lieu_id()
        {
            return flight_lieu_id;
        }
        void modify_flight_lieutenant()
        {
            aircraftman::modify();
            cout << "Enter modified section Id: ";
            cin >> this->section_id;
        }
};

class squadron_leader : public flight_lieutenant //head of a squadron
{
    private:
        string squadron_leader_id;
        string squadron_id;
        //string command_id;

    public:
        void getter_squadron_leader()
        {
            cout << "Enter Squadron leader Id: ";
            cin >> squadron_leader_id;
            aircraftman::getter();
            cout << "Enter squadron_id(sqa1/sqa2): ";
            cin >> squadron_id;
        }
        void display_sqa_leader()
        {
            cout << "\nSquadron Leader Id: " << squadron_leader_id;
            aircraftman::display();
            cout << "\nSquadron Id: " << squadron_id;
            cout<<endl;
        }

        string ret_sqdl_id()
        {
            return squadron_leader_id;
        }
        void modify_sqd_leader()
        {
            aircraftman::modify();
            cout << "Enter modified Squadron Id: ";
            cin >> this->squadron_id;
        }
};

class section_airforce
{
    protected:
        unsigned num_aircraftman; 
        string section_airforce_id;
        string flight_lieu_id;
        unsigned num_missile;
        unsigned num_fighter_jet;
        unsigned num_mp5_machine_gun;
        unsigned num_attack_helicopter;

    public:
        void operator ++(int)    //operator overloading
        {
            this->num_aircraftman++ ;
        }
        void getter_section_airforce()
        {
            cout << "Enter airforce section Id: ";
            cin >> section_airforce_id;
            cout<<"Enter the number of aircraftmen: ";
            cin>>num_aircraftman;
            cout << "Enter flight lieutenant Id: ";
            cin >> flight_lieu_id;
            cout << "Enter numbers of missiles: ";
            cin >> num_missile;
            cout << "Enter number of fighter jets: ";
            cin >> num_fighter_jet;
            cout << "Enter number of machine guns: ";
            cin >> num_mp5_machine_gun;
            cout << "Enter number of attack helicopters: ";
            cin >> num_attack_helicopter;
        }
        void print_section_info()
        {
            cout<<"\nNumber of Aircraftmen: "<<num_aircraftman<<endl;
            cout << " \nFlight Lieutenant Id: " << flight_lieu_id << endl;
        } 
        //prints the weapon information
        void print_section_weapon_info()
        {
            cout << "The weapons alloted in the section are:-\n";
            cout << "No. of Missiles: " << num_missile << endl;
            cout << "No. of Fighter Jets: " << num_fighter_jet << endl;
            cout << "No. of Machine Guns: " << num_mp5_machine_gun << endl;
            cout << "No. of Attack Helicopter: " << num_attack_helicopter << endl;
        }
};

// Air Chief Marshal can access all the class using multiple inheritance.
//head of airforce    
//can view all the arsenal which airforce has    
//can edit the details of any employee
class air_chief_marshall : public squadron_leader
{
    private:
        string air_chief_username;
    public:
        friend class cds;
        void getter_air_chief()
        {
            cout << "Enter Air Chief Marshal Username:  ";
            cin >> air_chief_username;
            aircraftman::getter();
        }
        void display_air_chief()
        {
            cout <<"\nUsername: " << air_chief_username;
            aircraftman::display();
        }
        string ret_air_username()
        {
            return air_chief_username;
        }
        string ret_air_chief_name()
        {
            return name;
        }
};


//------------
//class cds
//------------
class cds //Chief of Defence Staff    //only one object should be made
{
    //he can view everythin
    private:
        string cds_id;
        string name;
        string username;
        string password;
        date date_of_birth;   //containership  //age can be calculated by this
        date date_of_joining; //containership
    public:
        void getter_cds()
        {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Date of Birth:  ";
            date_of_birth.getter_date();
            cout << "Date of Joining: ";
            date_of_joining.getter_date();
            flag1:
            cout << "Set your password:\n";
            cout << "Enter new password: ";
            string pass1, pass2;
            cin >> pass1;
            cout << "Confirm new password: ";
            cin >> pass2;
            if (pass1 == pass2)
            {
                this->password = pass1;
            }
            else
            {
                cout << "\nPassword Not Matched\n";
                goto flag1;
            }
        }
        void display_cds()
        {
            cout << " \nName : " << name;
            cout << " \nDate Of Birth : ";
            date_of_birth.display_date();
            cout << " \nDate Of Joining : ";
            date_of_joining.display_date();
            cout << endl;
        }
        string ret_username_cds(void)
        {
        return username;
        }
        void set_password_cds(string pass)
        {
        this->password = pass;
        }
        string ret_password_cds(void)
        {
        return password;
        }
};


//Class War 
//-------------

class war
{
    private:
        date war_start_date;
        date war_end_date;
        string location;
        string opposition; //name of opposing country
        unsigned num_our_casualties;
        unsigned num_thiers_casualties;
        unsigned expenditure;
        string result; //one word win/loss
    public:
        void getter_war()
        {
            cout << "War Beginning Date: ";
            war_start_date.getter_date();
            cout << "War End Date: ";
            war_end_date.getter_date();
            cout << "Enter the location where the war took place: ";
            cin >> location;
            cout << "Enter the name of country against which war took place: ";
            cin >> opposition;
            cout << "Enter the number of casualties from from our side: ";
            cin >> num_our_casualties;
            cout << "Enter the number of casualties from from opposing side: ";
            cin >> num_thiers_casualties;
            cout << "Enter our expenditure(in INR): ";
            cin >> expenditure;
            cout << "Enter the result(win/loss): ";
            cin >> result;
        }
        void display_war()
        {
            war_start_date.display_date();
            cout << '\t';
            war_end_date.display_date();
            cout << '\t' << opposition << '\t' << location<<"\t\t"<<num_our_casualties << "\t\t" << num_thiers_casualties << '\t' << expenditure << '\t' << result << endl;
        }
};


//-----------------------------------------------
//End of Class Definitions
//-----------------------------------------------