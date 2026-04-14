//
// Created by Christopher Vaughn on 10/29/25.
//
/**
 * @file GeometryUtils.cpp
 * @brief Implements the geometry utility functions.
 *
 * This file contains the function definitions for calculating the areas
 * of squares, rectangles, and circles. It is responsible for
 * validating input and throwing exceptions on invalid data.
 *
 * @author [Your Name Here]
 * @date [Current Date]
 * @version 1.0
 */

#include "GeometryUtils.h"
#include <iostream>
#include <stdexcept>    // For std::invalid_argument
#include <string>       // For std::to_string

using namespace std;

/**
 * @brief Calculates the area of a square.
 */
double calculateArea(double side) {
    // STUDENT TODO: Replace this 'if' block with a
    // 'throw std::invalid_argument' exception.
    // Example: throw std::invalid_argument("Side cannot be zero or negative: " + std::to_string(side));
    if (side <= 0) {
		throw invalid_argument("Side cannot be zero or negative: " + to_string(side));
        cerr << "Error: Invalid side for square: " << side << endl;
        return 0; // Return 0 on error for now
    }

    return side * side;
}

/**
 * @brief Calculates the area of a rectangle (Overloaded).
 */
double calculateArea(double length, double width) {
    // STUDENT TODO: Replace this 'if' block with a
    // 'throw std::invalid_argument' exception.
    if (length <= 0 || width <= 0) {
		throw invalid_argument("Rectangle dimensions invalid: " + to_string(length) + ", " + to_string(width));
        cerr << "Error: Invalid dimensions for rectangle: "
             << length << ", " << width << endl;
        return 0; // Return 0 on error for now
    }

    return length * width;
}

/**
 * @brief Calculates the area of a circle.
 */
double calculateCircleArea(double radius) {
    // STUDENT TODO: Replace this 'if' block with a
    // 'throw std::invalid_argument' exception.
    if (radius <= 0) {
		throw invalid_argument("Radius cannot be zero or negative: " + to_string(radius));
        cerr << "Error: Invalid radius for circle: " << radius << endl;
        return 0; // Return 0 on error for now
    }

    const double PI = 3.1415926535; // A more precise PI
    return PI * radius * radius;
}

