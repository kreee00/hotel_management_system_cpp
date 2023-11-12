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
void viewAmenities();  // Function prototype for the viewAmenities function
void bookRoom();  // Function prototype for the bookRoom function
void viewPrices();  // Function prototype for the viewPrices function
void salesReport();  // Function prototype for the salesReport function
void userMenu();  // Function prototype for the user menu

// Declare variables for room prices and quantities
int single = 65, twin = 100;
int Qsingle = 20, Qtwin = 40, Qtowel = 75, Qwater = 100, Qbiscuit = 100, Qpillow = 75;
int quant, choice, total_room = 0;

// Declare variables to keep track of items sold
int Ssingle = 0, Stwin = 0, Stowel = 0, Swater = 0, Sbiscuit = 0, Spillow = 0;

// Declare variables to track the total price for each item
int Total_rooms = 0, Total_towel = 0, Total_water = 0, Total_biscuit = 0, Total_pillow = 0;

int count = 0;  // A variable to track login attempts
string userID, password, id, pass;  // Strings to store user credentials

int main(){
    int mainmenuchoice;
    
        cout << "\t\t\t_________________________________________________________________\n\n\n";
        cout << "\t\t\t                  Welcome to the login page                      \n\n\n";
        cout << "\t\t\t ___________________         Menu        _______________________ \n\n\n";
        cout << " ";
        cout << "\t| Press 1 to REGISTER " << endl;
        cout << "\t| Press 2 to LOGIN" << endl;
        cout << "\t| Press 3 if you forgot your password" << endl;
        cout << "\t| Press 4 to EXIT" << endl;
        cout << "\n\t\t\t Please enter your choice: ";
        cin >> mainmenuchoice;  // Read the user's choice from the input
        cout << endl;

        switch (mainmenuchoice)
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
        if(userID == "admin69" && password == "beverlyHills178"){
            cout << "\n\t\t\t Login admin successful! \n\n";
            AdminMenu();  // Call the admin menu function
        }
        ifstream input("credentials.txt");  // Open the file for reading user records
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
        userMenu();  // Call the main menu function for regular users
    }
    else
    {
        cout << "\n LOGIN ERROR \n Please check your username and password \n";
        main();  // Return to the main menu if login fails
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

    void userMenu()
{
    int choice;
    cout << "\t\t\t ___________________         Customer Menu        _______________________ \n\n\n";
            cout << " ";
            cout << "\t| Press 1 to book room" << endl;
            cout << "\t| Press 2 to request amenities" << endl;
            cout << "\t| Press 3 to view current bill" << endl;
            cout << "\t| Press 4 to log out" << endl;
            cout << "\n\t\t\t Please enter your choice: ";
            cin >> choice;  // Read the user's choice from the input
            cout << endl;

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
            outFile << "Cost: RM" << total_room << endl;
            outFile << "----------------------" << endl;

            cout << endl << "Registration details saved to " << fileName << endl;
            outFile.close();  // Close the file
            int choice;
            cout << "Exit? \n1. Yes\n2. No" << endl << "Action: ";
            cin >> choice;
            if (choice == 1)
            {
                break;
            }
            else
            {
                userMenu();
            }
        }
        else
        {
            cout << "Error opening the file." << endl;
            userMenu();
        }
    }
    case 2:
    {
        
    }
    case 3:
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
                userMenu();
            }
        }
        else
        {
            cout << "File not found or error opening the file." << endl;
            userMenu();
        }
        
    }
    case 4:
    {
        cout << "\t\t\t Logging out... \n\n";  // Display a logout message
        break;
    }
    default:
        cout << "Invalid choice. Please try again." << endl;
        userMenu();
    }
}


    void AdminMenu(){

            cout << "\t\t\t ___________________         Admin Menu        _______________________ \n\n\n";
            cout << " ";
            cout << "\t| Press 1 to view room availability" << endl;
            cout << "\t| Press 2 to view amenities availability" << endl;
            cout << "\t| Press 3 to view sales report" << endl;
            cout << "\t| Press 4 to log out" << endl;
            cout << "\n\t\t\t Please enter your choice: ";
            cin >> choice;  // Read the user's choice from the input
            cout << endl;

            switch (choice)
            {
                case 1:
                    viewRooms();  // Call the viewRooms function to display room availability
                    break;
                case 2:
                    viewAmenities();  // Call the viewAmenities function to display amenities availability
                    break;
                case 3:
                    salesReport();  // Call the salesReport function to display the sales report
                    break;
                case 4:
                    cout << "\t\t\t Logging out... \n\n";  // Display a logout message
                    system("cls");
                    main();
                default:
                    cout << "\t\t\t Invalid choice. Please select from the options given above \n" << endl;
                    AdminMenu();  // Call the AdminMenu function recursively
            }
    }

    void viewRooms(){
        // Display the number of available single and twin rooms
        int choice;
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t\t Room Availability \n\n\n";
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t Single Rooms: " << Qsingle << endl;
        cout << "\t\t\t\t\t\t Twin Rooms: " << Qtwin << endl;
        cout << "\n\n";

        cout << "Do you want to exit? \n1. Yes\n2. No" << endl << "Action: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "\t\t\t Logging out... \n\n";  // Display a logout message
        }
        else
        {
            system("cls");
            AdminMenu();
        }
    }

    void viewAmenities(){
        //Display number of available amenities
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t\t Amenities Availability \n\n\n";
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t Towel: " << Qtowel - Stowel << endl;
        cout << "\t\t\t\t\t\t Pillow: " << Qpillow - Spillow << endl;
        cout << "\t\t\t\t\t\t Water: " << Qwater - Swater << endl;
        cout << "\t\t\t\t\t\t Biscuit: " << Qbiscuit - Sbiscuit << endl;
        cout << "\n\n\n";

        cout << "Do you want to exit? \n1. Yes\n2. No" << endl << "Action: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "\t\t\t Logging out... \n\n";  // Display a logout message
        }
        else
        {
            system("cls");
            AdminMenu();
        }
    }

    void bookRoom(){
        // Prompt the user to select a room type and quantity
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t\t Room Booking \n\n\n";
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t Room Type \t Price \t Quantity \n\n";
        cout << "\t\t\t\t\t\t 1. Single \t RM65 \t " << Qsingle << endl;
        cout << "\t\t\t\t\t\t 2. Twin \t RM100 \t " << Qtwin << endl;
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
                cout << "\t\t\t\t\t\t Single \t " << quant << " \t\t RM" << Total_rooms << endl;
                break;
            case 2:
                cout << "\t\t\t\t\t\t Twin \t\t " << quant << " \t\t RM" << Total_rooms << endl;
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
        cout << "\t\t\t\t\t\t Single \t RM65 \n";
        cout << "\t\t\t\t\t\t Twin \t\t RM100 \n";
        cout << "\n\n\n";
    }

    void salesReport(){
        // Calculate the total sales for each item
        Total_towel = Stowel * 0;
        Total_water = Swater * 2;
        Total_biscuit = Sbiscuit * 6;
        Total_pillow = Spillow * 0;

        // Calculate the total sales for all items
        int total_sales = Total_rooms + Total_towel + Total_water + Total_biscuit + Total_pillow;

        // Display the sales report
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t\t Sales Report \n\n\n";
        cout << "\t\t\t _________________________________________________________________ \n\n\n";
        cout << "\t\t\t\t\t\t Item \t\t Quantity \t Total Sales \n\n";
        cout << "\t\t\t\t\t\t Single Rooms \t " << Ssingle << " \t\t RM" << Total_rooms << endl;
        cout << "\t\t\t\t\t\t Twin Rooms \t " << Stwin << " \t\t RM" << Total_rooms << endl;
        cout << "\t\t\t\t\t\t Towels \t " << Stowel << " \t\t RM" << Total_towel << endl;
        cout << "\t\t\t\t\t\t Drinks \t " << Swater << " \t\t RM" << Total_water << endl;
        cout << "\t\t\t\t\t\t Snacks \t " << Sbiscuit << " \t\t RM" << Total_biscuit << endl;
        cout << "\t\t\t\t\t\t Pillows \t " << Spillow << " \t\t RM" << Total_pillow << endl;
        cout << "\t\t\t\t\t\t Total Sales: RM" << total_sales << endl;
        cout << "\n";

        cout << "Do you want to exit? \n1. Yes\n2. No" << endl << "Action: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "\t\t\t Logging out... \n\n";  // Display a logout message
        }
        else
        {
            system("cls");
            AdminMenu();
        }
    }

/*void bookRoom(){
    // Prompt the user to select a room type
    cout << "\t\t\t _________________________________________________________________ \n\n\n";
    cout << "\t\t\t\t\t\t\t Room Booking \n\n\n";
    cout << "\t\t\t _________________________________________________________________ \n\n\n";
    cout << "\t\t\t\t\t\t Room Type \t Price \n\n";
    cout << "\t\t\t\t\t\t 1. Single \t $65 \n";
    cout << "\t\t\t\t\t\t 2. Twin \t\t $100 \n";
    cout << "\n\n\n";
    cout << "\t\t\t\t\t\t Enter your choice: ";
    cin >> choice;

    // Prompt the user to enter the number of rooms to book
    cout << "\n\n\n";
    cout << "\t\t\t _________________________________________________________________ \n\n\n";
    cout << "\t\t\t\t\t\t Room Booking \n\n\n";
    cout << "\t\t\t _________________________________________________________________ \n\n\n";
    cout << "\t\t\t\t\t\t Enter the number of rooms to book: ";
    cin >> quant;

    // Calculate the total price for the booking
    if (choice == 1){
        total_room = single * quant;
        Qsingle -= quant;
        Ssingle += quant;
        Total_rooms += total_room;
    }
    else if (choice == 2){
        total_room = twin * quant;
        Qtwin -= quant;
        Stwin += quant;
        Total_rooms += total_room;
    }

    // Write the booking data to a file
    ofstream bookingFile;
    bookingFile.open("booking.txt", ios::app);
    bookingFile << "Room Type: " << choice << "\n";
    bookingFile << "Number of Rooms: " << quant << "\n";
    bookingFile << "Total Price: " << total_room << "\n\n";
    bookingFile.close();

    // Display the booking confirmation
    cout << "\n\n\n";
    cout << "\t\t\t _________________________________________________________________ \n\n\n";
    cout << "\t\t\t\t\t\t Room Booking Confirmation \n\n\n";
    cout << "\t\t\t _________________________________________________________________ \n\n\n";
    cout << "\t\t\t\t\t\t Room Type \t Quantity \t Total Price \n\n";
    if (choice == 1){
        cout << "\t\t\t\t\t\t Single \t " << quant << " \t\t $" << total_room << endl;
    }
    else if (choice == 2){
        cout << "\t\t\t\t\t\t Twin \t\t " << quant << " \t\t $" << total_room << endl;
    }
    cout << "\n\n\n";
}
*/