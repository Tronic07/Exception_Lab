//
// Created by Christopher Vaughn on 10/29/25.
//
/**
 * @file GeometryUtils.h
 * @brief Declares a library of utility functions for calculating shape areas.
 *
 * This file contains the function declarations (prototypes) for an
 * overloaded 'calculateArea' function and a 'calculateCircleArea' function.
 *
 * @author [Your Name Here]
 * @date [Current Date]
 * @version 1.0
 */
//this is an alternative method of preventing multiple compile attempts on this file
#pragma once

#include <stdexcept> // For std::invalid_argument

/**
 * @brief Calculates the area of a square.
 *
 * @param side The length of the square's side.
 * @return The area of the square.
 * @throws std::invalid_argument if the side is zero or negative.
 */
double calculateArea(double side);

/**
 * @brief Calculates the area of a rectangle (Overloaded).
 *
 * @param length The length of the rectangle.
 * @param width The width of the rectangle.
 * @return The area of the rectangle.
 * @throws std::invalid_argument if length or width is zero or negative.
 */
double calculateArea(double length, double width);

/**
 * @brief Calculates the area of a circle.
 *
 * @param radius The radius of the circle.
 * @return The area of the circle.
 * @throws std::invalid_argument if the radius is zero or negative.
 */
double calculateCircleArea(double radius);
