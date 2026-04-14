//
// Created by Christopher Vaughn on 10/29/25.
//

#ifndef ERRORHANDLING_UTILITIES_H
#define ERRORHANDLING_UTILITIES_H

/**
 * @file FileUtils.h
 * @brief Declares utility functions for handling file operations.
 *
 * @author [Your Name Here]
 * @date [Current Date]
 * @version 1.0
 */

#pragma once

#include <fstream>  // For ifstream
#include <string>   // For string

/**
 * @brief Attempts to open a file, handling failures and retries.
 * * This function will try to open the 'initialFilename'.
 * If it fails, it will prompt the user for an alternative filename
 * and attempt to open that file.
 *
 * @param file The ifstream object to be opened (passed by reference).
 * @param initialFilename The first filename to try.
 */
void openFileForReading(std::ifstream& file, std::string initialFilename);


#endif //ERRORHANDLING_UTILITIES_H