#include <iostream>  // Include the input/output library
#include <fstream>   // Include the file handling library
#include <string.h>  // Include the string manipulation library

using namespace std;

// Function prototypes
void login();
void registration();
void forgot();
void userMenu();


// Declare variables for room prices and quantities
int single = 65, twin = 100;
int Qsingle = 20, Qtwin = 40, Qtowel = 10, Qdrinks = 10, Qsnacks = 10, Qpillow = 10;
int quant, choice, total_room = 0;

// Declare variables to keep track of items sold
int Ssingle = 0, Stwin = 0, Stowel = 10, Sdrinks = 10, Ssnacks = 10, Spillow = 10;

// Declare variables to track the total price for each item
int Total_rooms = 0, Total_towel = 0, Total_drinks = 0, Total_snacks = 0, Total_pillow = 0;

int count = 0;  // A variable to track login attempts
string userID, password, id, pass;  // Strings to store user credentials
void adminMenu();  // Function prototype for the admin menu

int main()
{
    int choice;
    bool isValidChoice = false;
    do{
        cout << "\t\t\t_________________________________________________________________\n\n\n";
    cout << "\t\t\t                  Welcome to the login page                      \n\n\n";
    cout << "\t\t\t ___________________         Menu        _______________________ \n\n\n";
    cout << " ";
    cout << "\t| Press 1 to REGISTER " << endl;
    cout << "\t| Press 2 to LOGIN" << endl;
    cout << "\t| Press 3 if you forgot your password" << endl;
    cout << "\t| Press 4 to EXIT" << endl;
    cout << "\n\t\t\t Please enter your choice: ";
    cin >> choice;  // Read the user's choice from the input
    cout << endl;

    switch (choice)  // Handle the user's choice
    {
    case 1:
        registration();  // Call the registration function
        break;
    case 2:
        login();  // Call the login function
        break;
    case 3:
        forgot();  // Call the password recovery function
        break;
    case 4:
        cout << "\t\t\t Thank you! \n\n";  // Display a farewell message
        break;
    default:
    cout << "\t\t\t Invalid choice. Please select from the options given above \n" << endl;
        isValidChoice = false;
    
        
    }
    } while (!isValidChoice);
}

// The 'login()' function handles user login.
void login()
{
    system("cls");  // Clear the screen
    cout << "\t\t\t Please enter the username and password: " << endl;
    cout << "\t\t\t USERNAME: ";
    cin >> userID;  // Read the username from the user
    cout << "\t\t\t PASSWORD: ";
    cin >> password;  // Read the password from the user

    // Special case for admin login
    if (userID == "admin" && password == "iYamAnAdmin3412")
    {
        AdminMenu();  // Call the admin menu function
        return;  // Exit the login function after admin login
    }

    ifstream input("records.txt");  // Open the file for reading user records
    while (input >> id >> pass)
    {
        if (id == userID && pass == password)
        {
            count = 1;  // Set the login attempt count to 1
            system("cls");  // Clear the screen
        }
    }
    input.close();  // Close the file

    if (count == 1)
    {
        cout << userID << "\n Your LOGIN is successful \n Thanks for logging in! \n\n";
        mainMenu();  // Call the main menu function for regular users
    }
    else
    {
        cout << "\n LOGIN ERROR \n Please check your username and password \n";
        main();  // Return to the main menu if login fails
    }
}

// The 'registration()' function allows users to register.
void registration()
{
    string ruserID, rpassword, rid, rpass;
    system("cls");  // Clear the screen
    cout << "\t\t\t Enter the username: ";
    cin >> ruserID;  // Read the username from the user
    cout << "\t\t\t Enter the password: ";
    cin >> rpassword;  // Read the password from the user

    ofstream f1("records.txt", ios::app);  // Open the file for appending
    f1 << ruserID << ' ' << rpassword << endl;  // Write the user's credentials to the file
    system("cls");  // Clear the screen
    cout << "\n\t\t\t Registration is successful! \n";
    main();  // Return to the main menu
}

// The 'forgot()' function allows users to recover their passwords.
void forgot()
{
    int option;
    system("cls");  // Clear the screen
    cout << "\t\t\t You forgot the password? No worries \n";
    cout << "\t\t\t Press 1 to search your id by username " << endl;
    cout << "\t\t\t Press 2 to go back to the main menu " << endl;
    cout << "\t\t\t Enter your choice: ";
    cin >> option;  // Read the user's choice

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string fuserID, sID, spass;
        cout << "\n\t\t\t Enter the username which you remembered: ";
        cin >> fuserID;  // Read the remembered username from the user

        ifstream f2("records.txt");  // Open the file for reading user records
        while (f2 >> sID >> spass)
        {
            if (sID == fuserID)
            {
                count = 1;  // Set the count to 1 if the username is found
            }
        }
        f2.close();  // Close the file

        if (count == 1)
        {
            cout << "\n\n Your account is found! \n";
            cout << "\n\n Your password is: \n" << spass;  // Display the found password
            main();
        }
        else
        {
            cout << "\n\t Sorry! Your account is not found! \n" << endl;
            main();
        }
        break;
    }
    case 2:
        main();  // Return to the main menu
        break;
    default:
        cout << "\t\t\t Wrong Choice! Please try again" << endl;
        
    }
}

// The 'AdminMenu()' function is used for admin actions.
void AdminMenu()
{
    int choice;
    cout << "Hello Admin, what would you like to review?" << endl;
    cout << "___________________________________________" << endl;
    cout << "1. Available rooms left \n2. Available amenities left \n3. Revenue of the day \n4. Reset records" << endl;
    cout << "Choice of action: ";
    cin >> choice;  // Read the admin's choice

    switch (choice)
    {
    case 1:{
        // Handle the case for reviewing available rooms
        // (You can add code here for this functionality)
        break;
    }
    case 2:{
        // Handle the case for reviewing available amenities
        // (You can add code here for this functionality)
        break;
        }
    case 3: {
        // Handle the case for reviewing revenue
        // (You can add code here for this functionality)
        break;
    }   
    case 4: {
        // Handle the case for resetting records
        // (You can add code here for this functionality)
        break;
    }   
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    // Handle other cases for reviewing amenities and revenue (you can add code here)
    }
}

// The 'mainMenu()' function is the main menu for registered users.

void mainMenu()
{
    int choice;
    cout << "Do you want to book a room?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No, I just want to see my report" << endl;
    cout << "Choice of action: ";
    cin >> choice;  // Read the user's choice

    switch (choice)
    {
    case 1:
    {
        cout << "\nWhat room do you want?" << endl;
        cout << "1. Single = RM65 \n2. Twin = RM100" << endl;
        int roomChoice;
        cout << "Room choice: ";
        cin >> roomChoice;  // Read the user's room choice
        while (roomChoice != 1 && roomChoice != 2)
        {
            cout << "Pick either 1 or 2 only: " << endl;
            cin >> roomChoice;  // Validate the room choice
        }
        if (roomChoice == 1)
        {
            total_room += single;  // Calculate the total cost for a single room
        }
        else
        {
            total_room += twin;  // Calculate the total cost for a twin room
        }

        // Generate the filename based on the user's ID
        string fileName = "registration_report_" + userID + ".txt";
        ofstream outFile(fileName.c_str(), ios::app);  // Open the file for appending
        if (outFile.is_open())
        {
            // Write registration details to the file
            outFile << "Registration ID: " << userID << endl;
            outFile << "Room Type: " << roomChoice << endl;
            outFile << "Cost: $" << total_room << endl;
            outFile << "----------------------" << endl;

            cout << endl << "Registration details saved to " << fileName << endl;
            outFile.close();  // Close the file
            int choice;
            cout << "Exit? \n1. Yes\n2. No" << endl << "Action: ";
            if (choice == 1)
            {
                break;
            }
            else
            {
                main();
            }
        }
        else
        {
            cout << "Error opening the file." << endl;
        }
        break;
    }
    case 2:
    {
        // Generate the filename based on the user's ID
        string fileName = "registration_report_" + userID + ".txt";
        ifstream selectedFile(fileName.c_str());  // Open the file for reading
        if (selectedFile.is_open())
        {
            string line;
            while (getline(selectedFile, line))
            {
                cout << line << endl;  // Display the registration report
            }
            selectedFile.close();
            int choice;
            cout << "Exit? \n1. Yes\n2. No" << endl << "Action: ";
            cin >> choice;
            if (choice == 1)
            {
                break;
            }
            else
            {
                main();
            }
        }
        else
        {
            cout << "File not found or error opening the file." << endl;
        }
        break;
    }
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}
