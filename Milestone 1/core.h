/*
*****************************************************************************
                        Assignment 1 - Milestone 1
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#pragma once
#include <stdio.h>

// Clear the standard input buffer 
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue 
void suspend(void);

// This function guarantees that an integer value is entered and returned. If an invalid value is entered, an error message would be displayed.
int inputInt(void);

// This function guarantees a positive integer value is entered and returned. If a zero or a negative value in entered, an error message would be displayed.
int inputIntPositive(void);

// This function guarantees that an integer value is entered within the range (inclusive) and returned. If a value from outside the range is entered, display an error message and continue to prompt until a value in the given range is entered.
int inputIntRange(int lowerBound, int upperBound);

// This function guarantees a single character value is entered within the list of valid characters and returned. If an entered character is not in the list of valid characters, display an error message and prompt again.
char inputCharOption(char str[]);

// This function guarantees a C string value is entered containing the number of characters within the range specified by the 2nd and 3rd arguments.
void inputCString(char* str, int minChar, int maxChar);

// The purpose of this function is to display an array of 10-character digits as a formatted phone number.
void displayFormattedPhone(char str[]);
