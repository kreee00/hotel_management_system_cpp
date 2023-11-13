// Calculate the total spending by user
        int totalSpending = total_room + Total_towel + Total_water + Total_biscuit + Total_pillow;

        // Generate the filename based on the user's ID
        string fileName = "bills_report_" + userID + ".txt";
        ofstream outFileUser(fileName.c_str(), ios::app);  // Open the file for appending
        if (outFileUser.is_open())
        {
            // Write registration details to the file
            outFileUser << "Registration ID: " << userID << endl;
            outFileUser << "Room Type: " << roomChoice << endl;
            outFileUser << "----------------------" << endl;

            // Write amenities details to the file
            switch (amenityChoice)
            {
                case 1:
                    outFileUser << "Amenity Type: Towel (RM0) x " << amenityQuantity << endl;
                    break;
                case 2:
                    outFileUser << "Amenity Type: Water (RM2) x " << amenityQuantity << endl;
                    break;
                case 3:
                    outFileUser << "Amenity Type: Biscuit (RM6) x " << amenityQuantity << endl;
                    break;
                case 4:
                    outFileUser << "Amenity Type: Pillow (RM0) x " << amenityQuantity << endl;
                    break;
            }
            outFileUser << "----------------------" << endl;

            // Calculate the total spending by user
            outFileUser << "Total Spending: RM" << totalSpending << endl;

            outFileUser.close();  // Close the file
            int choice;
            cout << endl << "Registration and amenities details saved to " << fileName << endl;
            cout << "Exit? \n1. Yes\n2. No" << endl << "Action: ";
            cin >> choice;
            if (choice == 1)
            {
                exit(0);
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