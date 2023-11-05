#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

	void login();
	void registration();
	void forgot();
	void mainMenu();
int single=65,twin=100;
int Qsingle=20,Qtwin=40,Qtowel=10,Qdrinks=10,Qsnacks=10,Qpillow=10;	
int quant,choice,total_room=0;
	//items sold
int Ssingle=0,Stwin=0,Stowel=10,Sdrinks=10,Ssnacks=10,Spillow=10;	
	//Price
int Total_rooms=0,Total_towel=0,Total_drinks=0,Total_snacks=0,Total_pillow=0;
int count = 0;
string userID, password, id, pass;
void AdminMenu();

int main()
{

	int c;
	cout<<"\t\t\t_________________________________________________________________\n\n\n";
	cout<<"\t\t\t                  Welcome to the login page                      \n\n\n";
	cout<<"\t\t\t ___________________         Menu        _______________________ \n\n\n";
	cout<<" ";
	cout<<"\t| Press 1 to REGISTER "<<endl;
	cout<<"\t| Press 2 to LOGIN"<<endl;
	cout<<"\t| Press 3 if you forgot your password"<<endl;
	cout<<"\t| Press 4 to EXIT"<<endl;
	cout<<"\n\t\t\t Please enter your choice: ";
	cin>>c;
	cout<<endl;
	
	switch(c){
		case 1:
			registration();
			break;
		case 2:
			login();
			break;
		case 3:
			forgot();
			break;
		case 4:
			cout<<"\t\t\t Thank you! \n\n";
			break;
		default:
			system("cls");
			cout<<"\t\t\t Please select from the option given above \n"<<endl;
			main();
	}
	
	
}

void login(){
    system("cls");
    cout<<"\t\t\t Please enter the username and password: "<<endl;
    cout<<"\t\t\t USERNAME: ";
    cin>>userID;
    cout<<"\t\t\t PASSWORD: ";
    cin>>password;
    
    // Special case for admin login
    if (userID == "admin" && password == "admin") {
        AdminMenu();
        return; // Exit the login function after admin login
    }

    ifstream input("records.txt");
    while(input >> id >> pass){
        if(id == userID && pass == password){
            count = 1;
            system("cls");
        }
    }
    input.close();
    if(count == 1){
        cout<<userID<<"\n Your LOGIN is successful \n Thanks for logging in! \n\n";
        mainMenu(); // Call the main menu function for regular users
        
    } else {
        cout<<"\n LOGIN ERROR \n Please check your username and password \n";
        main(); // Go back to the main menu if login fails
    }
}

void registration(){
	string ruserID,rpassword,rid,rpass;
	system("cls");
	cout<<"\t\t\t Enter the username: ";
	cin>>ruserID;
	cout<<"\t\t\t Enter the password: ";
	cin>>rpassword;
	
	ofstream f1("records.txt",ios::app);
	f1<<ruserID<<' '<<rpassword<<endl;
	system("cls");
	cout<<"\n\t\t\t Registration is successfull! \n";
	main();
}

void forgot(){
	int option;
	system("cls");
	cout<<"\t\t\t You forgot the password? No worries \n";
	cout<<"\t\t\t Press 1 to search your id by username "<<endl;
	cout<<"\t\t\t Press 2 to go back to the main menu "<<endl;
	cout<<"\t\t\t Enter your choice: ";
	cin>>option;
	switch(option){
		case 1 :{
			int count=0;
			string suserID,sID,spass;
			cout<<"\n\t\t\t Enter the username which you remembered: ";
			cin>>suserID;
			
			ifstream f2("records.txt");
			while(f2>>sID>>spass){
				if(sID==suserID){
					count=1;
					
				}
			}
			f2.close();
			if(count==1){
				cout<<"\n\n Your account is fount! \n" ;
				cout<<"\n\n Your password is: \n"<<spass;
				main();
				
			}else{
				cout<<"\n\t Sorry! Your account is not found! \n"<<endl;
				main();
				
			}
			break;
			}
			case 2 : {
				main();
				break;
				}
			default:
				cout<<"\t\t\t Wrong Choice! Please try again"<<endl;
				main();
			}

	}
	
void AdminMenu() {
	int choice;
    cout<< "Hello Admin, what would you like to review?"<<endl;
    cout<<"___________________________________________"<<endl;
    cout<<"1. Available rooms left \n2. Available ammenities left \n3. Revenue of the day"<<endl;
    cout<<"Choice of action: ";
    cin>>choice;
    switch (choice){
    	case 1:{
    		
			
		}
    		
	}
    

}

void mainMenu() {
    int choice;
    cout << "Do you want to book a room?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No, I just want to see my report" << endl;
    cout << "Choice of action: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "\nWhat room do you want?" << endl;
            cout << "1. Single = RM65 \n2. Twin = RM100" << endl;
            int roomChoice;
            cout << "Room choice: ";
            cin >> roomChoice;
            while (roomChoice != 1 && roomChoice != 2) {
                cout << "Pick either 1 or 2 only: " << endl;
                cin >> roomChoice;
            }
            if (roomChoice == 1) {
                total_room += single;
            } else {
                total_room += twin;
            }

            // Generate the filename based on userID
            string fileName = "registration_report_" + userID + ".txt";
            ofstream outFile(fileName.c_str(), ios::app);
            if (outFile.is_open()) {
                // Writing registration details to the file
                outFile << "Registration ID: " << userID << endl;
                outFile << "Room Type: " << roomChoice << endl;
                outFile << "Cost: $" << total_room << endl;
                outFile << "----------------------" << endl;

                cout << endl << "Registration details saved to " << fileName << endl;
                outFile.close(); // Close the file
                int choice;
                cout<<"Exit? \n1. Yes\n2. No"<<endl<<"Action :";
                if (choice=1){
                	break;
				}else{
				main();}
            } else {
                cout << "Error opening the file." << endl;
            }
            break;
        }
        case 2: {
            // Generate the filename based on userID
            string fileName = "registration_report_" + userID + ".txt";
            // Open and display the file
            ifstream selectedFile(fileName.c_str());
            if (selectedFile.is_open()) {
                string line;
                while (getline(selectedFile, line)) {
                    cout << line << endl;
                }
                selectedFile.close();
                cout<<"Exit? \n1. Yes\n2. No"<<endl<<"Action :";
                cin>>choice;
                if (choice==1){
                	break;
				}else{
				main();}
            } else {
                cout << "File not found or error opening the file." << endl;
            }
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}
