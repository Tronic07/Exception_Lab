/**
 * @file main.cpp
 * @brief Main client program for the ShapeFile Parser.
 *
 * This program reads shape data from a file, validates it, and calculates
 * areas. It handles all file and data exceptions.
 *
 * @author [Luis Fabian Gonzalez]
 * @date [3/28/2025]
 * @version 1.0
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "GeometryUtils.h"
#include "Exceptions.h"
#include "FileUtils.h"

using namespace std;

int main() {
    cout << fixed << setprecision(2);

    string filename;
    ifstream file;
    int lineNumber = 0;

    // --- 1. File Opening Logic ---
    cout << "Enter filename: ";
    cin >> filename;

    // Wrap file opening in try/catch
    try {
        openFileForReading(file, filename);
    }
    catch (const FileOpenException& e) {
        cerr << "File error: " << e.what() << endl;
        return 1;
    }

    // --- 2. File Parsing Logic ---
    cout << "--- Processing Shapes ---" << endl;
    string shapeType;

    // Wrap entire while-loop in try/catch for ParseException
    try {
        while (file >> shapeType) {
            lineNumber++;

            try {
                if (shapeType == "square") {
                    double side;
                    file >> side;

                    double area = calculateArea(side);
                    cout << "Line " << lineNumber << ": Square Area: " << area << endl;
                }
                else if (shapeType == "rectangle") {
                    double length, width;
                    file >> length >> width;

                    double area = calculateArea(length, width);
                    cout << "Line " << lineNumber << ": Rectangle Area: " << area << endl;
                }
                else if (shapeType == "circle") {
                    double radius;
                    file >> radius;

                    double area = calculateCircleArea(radius);
                    cout << "Line " << lineNumber << ": Circle Area: " << area << endl;
                }
                else {
                    // Throw ParseException for unknown shape
                    throw ParseException("Unknown shape type: " + shapeType +
                        " (line " + to_string(lineNumber) + ")");
                }
            }
            catch (const invalid_argument& e) {
                cerr << "Line " << lineNumber << ": Invalid data: " << e.what() << endl;
            }
            catch (const exception& e) {
                cerr << "Line " << lineNumber << ": Unexpected error: " << e.what() << endl;
            }
        }
    }
    catch (const ParseException& e) {
        cerr << "Parse error: " << e.what() << endl;
    }

    // --- 3. Cleanup ---
    cout << "--- Processing Complete ---" << endl;
    file.close();

    return 0;
}


