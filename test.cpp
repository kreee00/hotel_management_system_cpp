#include <iostream>  // Include the input/output library
#include <fstream>   // Include the file handling library
#include <string.h>  // Include the string manipulation library

using namespace std;

// Function prototypes
void login();
void registration();
void forgot();
void AdminMenu();  // Function prototype for the admin menu
void viewRooms();  // Function prototype for the viewRooms function
void bookRoom();  // Function prototype for the bookRoom function
void viewPrices();  // Function prototype for the viewPrices function
void salesReport();  // Function prototype for the salesReport function

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

int main(){
    int choice;
    
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

        switch (choice)
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
                main();  // Call the main function recursively
        }
    

        return 0;
    }

    void login(){
        // Prompt the user to enter their credentials
        cout << "\t\t\t Enter your User ID: ";
        cin >> userID;
        cout << "\t\t\t Enter your Password: ";
        cin >> password;

        // Check if the user ID and password match the stored credentials
        if(userID == id && password == pass){
            cout << "\n\t\t\t Login successful! \n\n";
            AdminMenu();  // Call the admin menu function
        }
        else{
            count++;  // Increment the login attempts counter
            cout << "\n\t\t\t Invalid credentials. Please try again. \n\n";
            if(count < 3){
                login();  // Call the login function recursively
            }
            else{
                cout << "\n\t\t\t Too many failed login attempts. Please try again later. \n\n";
                exit(0);  // Terminate the program
            }
        }
    }

    void registration(){
        // Prompt the user to enter their desired credentials
        cout << "\t\t\t Enter your desired User ID: ";
        cin >> id;
        cout << "\t\t\t Enter your desired Password: ";
        cin >> pass;

        // Store the user's credentials in a file
        ofstream file;
        file.open("credentials.txt", ios::app);
        file << id << " " << pass << endl;
        file.close();

        cout << "\n\t\t\t Registration successful! \n\n";
        login();  // Call the login function to log the user in after registration
    }

    void forgot(){
        // Prompt the user to enter their user ID
        cout << "\t\t\t Enter your User ID: ";
        cin >> userID;

        // Search for the user's credentials in the file
        ifstream file;
        file.open("credentials.txt");
        bool found = false;
        string line;
        while(getline(file, line)){
            if(line.find(userID) != string::npos){
                found = true;
                break;
            }
        }
        file.close();

        // If the user's credentials are found, prompt them to enter a new password
        if(found){
            cout << "\t\t\t Enter your new Password: ";
            cin >> password;

            // Update the user's password in the file
            file.open("credentials.txt");
            ofstream temp;
            temp.open("temp.txt");
            while(getline(file, line)){
                if(line.find(userID) != string::npos){
                    temp << userID << " " << password << endl;
                }
                else{
                    temp << line << endl;
                }
            }
            file.close();
            temp.close();
            remove("credentials.txt");
            rename("temp.txt", "credentials.txt");

            cout << "\n\t\t\t Password updated successfully! \n\n";
            login();  // Call the login function to log the user in with the new password
        }
        else{
            cout << "\n\t\t\t User ID not found. Please try again. \n\n";
            forgot();  // Call the forgot function recursively
        }
    }

    void AdminMenu(){

        do{
            cout << "\t\t\t ___________________         Menu        _______________________ \n\n\n";
            cout << " ";
            cout << "\t| Press 1 to view room availability" << endl;
            cout << "\t| Press 2 to book a room" << endl;
            cout << "\t| Press 3 to view room prices" << endl;
            cout << "\t| Press 4 to view sales report" << endl;
            cout << "\t| Press 5 to log out" << endl;
            cout << "\n\t\t\t Please enter your choice: ";
            cin >> choice;  // Read the user's choice from the input
            cout << endl;

            switch (choice)
            {
                case 1:
                    viewRooms();  // Call the viewRooms function to display room availability
                    break;
                case 2:
                    bookRoom();  // Call the bookRoom function to book a room
                    break;
                case 3:
                    viewPrices();  // Call the viewPrices function to display room prices
                    break;
                case 4:
                    salesReport();  // Call the salesReport function to display the sales report
                    break;
                case 5:
                    cout << "\t\t\t Logging out... \n\n";  // Display a logout message
                    break;
                default:
                    cout << "\t\t\t Invalid choice. Please select from the options given above \n" << endl;
            }
        }while(choice != 5);
    }

    void viewRooms(){
        // Display the number of available single and twin rooms
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t\t Room Availability \n\n\n";
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t Single Rooms: " << Qsingle << endl;
        cout << "\t\t\t\t\t\t Twin Rooms: " << Qtwin << endl;
        cout << "\n\n\n";
    }

    void bookRoom(){
        // Prompt the user to select a room type and quantity
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t\t Room Booking \n\n\n";
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t Room Type \t Price \t Quantity \n\n";
        cout << "\t\t\t\t\t\t 1. Single \t $65 \t " << Qsingle << endl;
        cout << "\t\t\t\t\t\t 2. Twin \t $100 \t " << Qtwin << endl;
        cout << "\n\n\n";
        cout << "\t\t\t Please enter your choice: ";
        cin >> choice;
        cout << "\t\t\t Please enter the quantity: ";
        cin >> quant;

        // Calculate the total price for the selected room type and quantity
        switch (choice)
        {
            case 1:
                if(Qsingle >= quant){
                    Total_rooms = single * quant;
                    Qsingle -= quant;
                    Stwin += quant;
                }
                else{
                    cout << "\t\t\t Insufficient quantity. Please try again. \n\n";
                    bookRoom();  // Call the bookRoom function recursively
                }
                break;
            case 2:
                if(Qtwin >= quant){
                    Total_rooms = twin * quant;
                    Qtwin -= quant;
                    Stwin += quant;
                }
                else{
                    cout << "\t\t\t Insufficient quantity. Please try again. \n\n";
                    bookRoom();  // Call the bookRoom function recursively
                }
                break;
            default:
                cout << "\t\t\t Invalid choice. Please try again. \n\n";
                bookRoom();  // Call the bookRoom function recursively
        }

        // Display the total price for the selected room type and quantity
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t\t Room Booking \n\n\n";
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t Room Type \t Quantity \t Total Price \n\n";
        switch (choice)
        {
            case 1:
                cout << "\t\t\t\t\t\t Single \t " << quant << " \t\t $" << Total_rooms << endl;
                break;
            case 2:
                cout << "\t\t\t\t\t\t Twin \t\t " << quant << " \t\t $" << Total_rooms << endl;
                break;
        }
        cout << "\n\n\n";
    }

    void viewPrices(){
        // Display the prices for each item
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t\t Room Prices \n\n\n";
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t Room Type \t Price \n\n";
        cout << "\t\t\t\t\t\t Single \t $65 \n";
        cout << "\t\t\t\t\t\t Twin \t\t $100 \n";
        cout << "\n\n\n";
    }

    void salesReport(){
        // Calculate the total sales for each item
        Total_towel = Qtowel * 5;
        Total_drinks = Qdrinks * 2;
        Total_snacks = Qsnacks * 3;
        Total_pillow = Qpillow * 10;

        // Calculate the total sales for all items
        int total_sales = Total_rooms + Total_towel + Total_drinks + Total_snacks + Total_pillow;

        // Display the sales report
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t\t Sales Report \n\n\n";
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t Item \t\t Quantity \t Total Sales \n\n";
        cout << "\t\t\t\t\t\t Single Rooms \t " << Ssingle << " \t\t $" << Total_rooms << endl;
        cout << "\t\t\t\t\t\t Twin Rooms \t " << Stwin << " \t\t $" << Total_rooms << endl;
        cout << "\t\t\t\t\t\t Towels \t\t " << Qtowel << " \t\t $" << Total_towel << endl;
        cout << "\t\t\t\t\t\t Drinks \t\t " << Qdrinks << " \t\t $" << Total_drinks << endl;
        cout << "\t\t\t\t\t\t Snacks \t\t " << Qsnacks << " \t\t $" << Total_snacks << endl;
        cout << "\t\t\t\t\t\t Pillows \t " << Qpillow << " \t\t $" << Total_pillow << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Total Sales: $" << total_sales << endl;
        cout << "\n\n\n";
    }