//
// Created by Christopher Vaughn on 10/29/25.
//
/**
 * @file FileUtils.cpp
 * @brief Implements utility functions for handling file operations.
 *
 * @author [Your Name Here]
 * @date [Current Date]
 * @version 1.0
 */

#include "FileUtils.h"
#include "Exceptions.h"     // Include for student's custom exceptions
#include <iostream>         // For cout, cerr, cin
#include <string>           // For string
#include <fstream>          // For ifstream

using namespace std;

/**
 * @brief Attempts to open a file, handling failures and retries.
 * * This function contains the logic that the student must
 * convert to use try...catch with FileOpenException.
 *
 * @param file The ifstream object to be opened (passed by reference).
 * @param initialFilename The first filename to try.
 */
void openFileForReading(std::ifstream& file, std::string initialFilename) {

    try {
        file.open(initialFilename);

        if (!file.is_open()) {
            throw FileOpenException("Could not open file: " + initialFilename);
        }

		cout << "File opened successfully: " << initialFilename << endl;
    }
    catch (const FileOpenException& e) {
        cerr << "Error: " << e.what() << endl;

        string alternativeFilename;
        cout << "Enter alternative filename: ";
        cin >> alternativeFilename;

		file.open(alternativeFilename);

        if (!file.is_open()) {
            cerr << "Error: Failed to open alternative file. Exiting." << endl;
            exit(1); // Exit the program with an error code
		}
        
		cout << "Alternative file opened successfully: " << alternativeFilename << endl;
    }

    file.open(initialFilename);
    if (!file.is_open()) {
        cerr << "Error: File could not be opened: " << initialFilename << endl;

        // This logic should be inside your 'catch' block
        string alternativeFilename;
        cout << "Enter alternative filename: ";
        cin >> alternativeFilename;
        file.open(alternativeFilename);

        if (!file.is_open()) {
            cerr << "Error: Failed to open alternative file. Exiting." << endl;
            // In a real program, you might throw a PersistentFileError here,
            // but for this lab, we will just exit.
            exit(1); // Exit the program with an error code
        }
        cout << "Alternative file opened successfully: " << alternativeFilename << endl;
    } else {
        cout << "File opened successfully: " << initialFilename << endl;
    }
}

