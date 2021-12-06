

/*void add_sepoy_to_section_(sepoy &s) 
{
    ofstream file;
    file.open("section.bin", ios::binary | ios::app);
    if (!file.is_open())
    {
        cout << "File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get(); //////////handle here correctly
        return;
    }
    section_army obj;
    obj.getter_section_army(s);
    int n;
    for (int i = 0; i < n; i++)
    {
        ifstream fl;
        fl.open("sepoy.bin", ios::binary | ios::in);
        if (!fl.is_open())
        {
            cout << "File could not be opened !! Press any Key to exit";
            cin.ignore();
            cin.get(); //////////handle here correctly
            return;
        }
        obj.getter_section_army(s);
        file.write((char *)&obj, sizeof(section_army));
    }
    file.close();
    cin.ignore();
    cin.get();
}*/






// // class company
// // {
// // private:
// //     //vector<section_army> sec; //has the list of sections -> section id , lietinant_id, lietunant name
// //     string company_id;
// //     string major_id;

// // public:
// //     //unsigned num_section();
// //     //void getter_company(); //this is a temporary function just to enter initial values
// //     //void print_company_info()
// //     //{
// //         // cout << "Company Id: " << company_id << endl;
// //         // cout << "The sections in this company are:-\n";
// //         // for (int i = 0; i < sec.size() - 1; i++)
// //         // {
// //         //     sec.at(i).print_section_info();
// //         //     cout << endl
// //         //          << endl;
// //         // }
// //         // cout << " \nMajor Id: " << major_id << endl;
// //     //}
// // };

//will changes in the sepoy reflect in the platoon binary file implicitly or do we have to handle it explicitly
// class platoon
// {
// private:
//     vector<company> com;
//     //instead of platoon id to be string i was thinking of it as unsigned
//     string platoon_id;
//     string lieutinant_gen_id;

// public:
//     //unsigned num_companies();
//     void getter_platoon();
//     //temporary input function required
//     void print_platoon_info() const;
// };



// class squadron //which sections are in which company/platoon is hardcoded.
// {
// private:
//     vector<section_airforce> sec; //has the list of sections -> section id , lietinant_id, lietunant name
//     string squadron_id;
//     string squadron_leader_id;
//     // string weapon_id;    //it may be removed
// public:
//     // unsigned num_section();
//     void print_squadron_info()
//     {
//         cout << "Squadron ID" << squadron_id << endl;
//         cout << "The Sections in this Squadron are:-\n";
//         for (int i = 0; i < sec.size() - 1; i++)
//         {
//             sec.at(i).print_section_info();
//             cout << endl
//                  << endl;
//         }
//         cout << "Squadron Leader ID: " << squadron_leader_id << endl;
//     };
//     void get_squadron_info();
//     // void print_weapon_info();
// };
// class command
// {
// private:
//     vector<squadron> com;
//     //instead of platoon id to be string i was thinking of it as unsigned
//     string command_id;
//     string marshall_id;
//     // string weapon_id;
// public:
//     // unsigned num_squadron();
//     void print_command_info() const;
//     void get_command_info();
//     // void print_weapon_info();
// };



//function that General can do
    //edit or modify details of any soldier
    //add and remove any soldier
    //view all the arsenal data which army has
    //can view/modify and delete all the info related to war and conflicts
    //add functions accordingly

        //function that Air Cheif Marshal can do
    //edit or modify details of any soldier
    //add and remove any soldier
    //view all the arsenal data which army has
    //can view/modify and delete all the info related to war and conflicts
    //add functions accordingly



    // void change_pass_sepoy(string id, string password)
// {
//     bool found = false;
//     sepoy obj;
//     fstream fl;
//     fl.open("sepoy.bin", ios::binary | ios::in | ios::out);
//     if (!fl.is_open())
//     {
//         cout << "File could not be opened. Press any Key to exit...";
//         cin.ignore();
//         cin.get();
//         return; /////////////////handle here correctly
//     }
//     fl.seekg(0, ios::beg);
//     while (!fl.eof() && found == false)
//     {
//         fl.read((char *)(&obj), sizeof(sepoy));
//         if (obj.ret_sep_id() == id)
//         {
//             obj.set_password(password);
//             int pos = (-1) * static_cast<int>(sizeof(obj));
//             fl.seekp(pos, ios::cur);
//             fl.write((char *)(&obj), sizeof(sepoy));
//             cout << "\n\n\t Record Updated";
//             found = true;
//         }
//     }
//     fl.close();
//     if (found == false)
//         cout << "\n\n Record Not Found ";
//     cin.ignore();
//     cin.get();
// }

    // if (found)
    // {
    //     string new_password;
    //     cout << "\nWant to change password: ";
    //     char ch;
    //     cin>>ch;
    //     cin >> new_password;
    //     change_pass(sepoy_id, new_password);
    // }
    // else
    // cout << "\nRecords not found!!";


    // if (found)
    // {
    //     string new_password;
    //     cout << "\nWant to change password: ";
    //     char ch;
    //     cin>>ch;
    //     cin >> new_password;
    //     change_pass(sepoy_id, new_password);
    // }
    // else
    // cout << "\nRecords not found!!";

    // void change_passwd_general(string usrnme, string password)
// {
//     bool found = false;
//     general obj;
//     fstream fl;
//     fl.open("general.bin", ios::binary | ios::in | ios::out);
//     if (!fl.is_open())
//     {
//         cout << "General Information could not be fetched\n";
//         cout << "Error: File could not be opened.\n";
//         cout << "Press any Key to exit..."; //////
//         cin.ignore();
//         cin.get();
//         return;
//     }
//     fl.seekg(0, ios::beg);
//     while (!fl.eof() && found == false)
//     {
//         fl.read((char *)(&obj), sizeof(general));
//         if (obj.ret_gene_username() == usrnme)
//         {
//             obj.set_password(password);
//             int pos = (-1) * static_cast<int>(sizeof(obj));
//             fl.seekp(pos, ios::cur);
//             fl.write((char *)(&obj), sizeof(general));
//             cout << "\n\n\t Record Updated";
//             found = true;
//         }
//     }
//     fl.close();
//     if (found == false)
//         cout << "\n\n Record Not Found ";
//     cin.ignore();
//     cin.get();
// }



// void delete_airforce_personel(string post_name)
// {
//     string id;
//     cout << "Enter the Id: ";
//     cin >> id;
//     ifstream iFile;
//     ofstream oFile;
//     oFile.open("temp.bin", ios::binary | ios::out);
//     oFile.seekp(0, ios::beg);
//     if (post_name == "Sepoy")
//     {
//         iFile.open("sepoy.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         sepoy obj;
//         while (iFile.read((char *)(&obj), sizeof(sepoy)))
//         {
//             if (obj.ret_sep_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(sepoy));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("sepoy.bin");
//         rename("temp.bin", "sepoy.bin");
//     }
//     else if (post_name == "Lieutenant")
//     {
//         iFile.open("lieu.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         lieutenant obj;
//         while (iFile.read((char *)(&obj), sizeof(lieutenant)))
//         {
//             if (obj.ret_lieu_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(lieutenant));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("lieu.bin");
//         rename("temp.bin", "lieu.bin");
//     }
//     else if (post_name == "Major")
//     {
//         iFile.open("major.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         Major obj;
//         while (iFile.read((char *)(&obj), sizeof(Major)))
//         {
//             if (obj.ret_maj_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(Major));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("major.bin");
//         rename("temp.bin", "major.bin");
//     }
//     else
//     {
//         cout << "\nInvalid Post.....";
//         return;
//     }
//     cout << "\n\n\tRecord Deleted ..";
//     cin.ignore();
//     cin.get();
// }




// {
//     ofstream fl;
//     fl.open("war.bin", ios::binary | ios::app);
//     if (!fl.is_open())
//     {
//         cout << "File could not be opened... Press any Key to exit...";
//         cin.ignore();
//         cin.get();
//         return;
//     }
//     war obj;
//     obj.getter_war();
//     fl.write((char *)&obj, sizeof(war));
//     fl.close();
//     cin.ignore();
//     cin.get();
// }
// break;
// default:
// cout << "\nEnter correct choice...";
// break;
// }
// }
// }


// void change_pass_sepoy(string id, string password)
// {
//     bool found = false;
//     sepoy obj;
//     fstream fl;
//     fl.open("sepoy.bin", ios::binary | ios::in | ios::out);
//     if (!fl.is_open())
//     {
//         cout << "File could not be opened. Press any Key to exit...";
//         cin.ignore();
//         cin.get();
//         return; /////////////////handle here correctly
//     }
//     fl.seekg(0, ios::beg);
//     while (!fl.eof() && found == false)
//     {
//         fl.read((char *)(&obj), sizeof(sepoy));
//         if (obj.ret_sep_id() == id)
//         {
//             obj.set_password(password);
//             int pos = (-1) * static_cast<int>(sizeof(obj));
//             fl.seekp(pos, ios::cur);
//             fl.write((char *)(&obj), sizeof(sepoy));
//             cout << "\n\n\t Record Updated";
//             found = true;
//         }
//     }
//     fl.close();
//     if (found == false)
//         cout << "\n\n Record Not Found ";
//     cin.ignore();
//     cin.get();
// }


// void change_passwd_general(string usrnme, string password)
// {
//     bool found = false;
//     general obj;
//     fstream fl;
//     fl.open("general.bin", ios::binary | ios::in | ios::out);
//     if (!fl.is_open())
//     {
//         cout << "General Information could not be fetched\n";
//         cout << "Error: File could not be opened.\n";
//         cout << "Press any Key to exit..."; //////
//         cin.ignore();
//         cin.get();
//         return;
//     }
//     fl.seekg(0, ios::beg);
//     while (!fl.eof() && found == false)
//     {
//         fl.read((char *)(&obj), sizeof(general));
//         if (obj.ret_gene_username() == usrnme)
//         {
//             obj.set_password(password);
//             int pos = (-1) * static_cast<int>(sizeof(obj));
//             fl.seekp(pos, ios::cur);
//             fl.write((char *)(&obj), sizeof(general));
//             cout << "\n\n\t Record Updated";
//             found = true;
//         }
//     }
//     fl.close();
//     if (found == false)
//         cout << "\n\n Record Not Found ";
//     cin.ignore();
//     cin.get();
// }

//adds the cds details into the file
// void add_cds_details(void)
// {
//     ofstream file;
//     file.open("cds.bin", ios::binary | ios::app);
//     if (!file.is_open())
//     {
//         cout << "Error: File couldn't be opened...";
//         cout << "Exiting the program...";
//         exit(0);
//     }
//     cds obj;
//     obj.getter_cds();
//     file.write((char *)&obj, sizeof(cds));
//     cout << "\nImfomation stored successfully...";
//     file.close();
//     cin.ignore();
//     cin.get();
// }


// void delete_personel(string post_name)
// {
//     string id;
//     cout << "Enter the Id: ";
//     cin >> id;
//     ifstream iFile;
//     ofstream oFile;
//     oFile.open("temp.bin", ios::binary | ios::out);
//     oFile.seekp(0, ios::beg);
//     if (post_name == "Sepoy")
//     {
//         iFile.open("sepoy.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         sepoy obj;
//         while (iFile.read((char *)(&obj), sizeof(sepoy)))
//         {
//             if (obj.ret_sep_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(sepoy));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("sepoy.bin");
//         rename("temp.bin", "sepoy.bin");
//     }
//     else if (post_name == "Lieutenant")
//     {
//         iFile.open("lieu.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         lieutenant obj;
//         while (iFile.read((char *)(&obj), sizeof(lieutenant)))
//         {
//             if (obj.ret_lieu_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(lieutenant));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("lieu.bin");
//         rename("temp.bin", "lieu.bin");
//     }
//     else if (post_name == "Major")
//     {
//         iFile.open("major.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         Major obj;
//         while (iFile.read((char *)(&obj), sizeof(Major)))
//         {
//             if (obj.ret_maj_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(Major));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("major.bin");
//         rename("temp.bin", "major.bin");
//     }
//     else
//     {
//         cout << "\nInvalid Post.....";
//         return;
//     }
//     cout << "\n\n\tRecord Deleted ..";
//     cin.ignore();
//     cin.get();
// }




