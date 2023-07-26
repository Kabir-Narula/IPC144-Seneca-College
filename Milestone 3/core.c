
/*
*****************************************************************************
                        Assignment 1 - Milestone 3
Full Name  : Kabir Narula
Student ID#: 127962223
Email      : Knarula9@myseneca.ca
Section    : NAA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*//*
// ############################################################################
//
//  Assignment:  1 
//  Milestone:   3
//  Description: Main Application Entry Point
//
// +---------------------------------------------------------+
// | *** The contents of this file is NOT to be modified *** |    
// +---------------------------------------------------------+
//
// ###########################################################################
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue 
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// This function guarantees that an integer value is entered and returned. If an invalid value is entered, an error message would be displayed.
int inputInt(void) {
    char character = ' ';
    int value;

    do {
        scanf("%d%c", &value, &character);

        if (character != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (character != '\n');

    // If the character after the integer is a new line character that means an appropriate value was entered
    return value;
}

// This function guarantees a positive integer value is entered and returned. If a zero or a negative value in entered, an error message would be displayed.
int inputIntPositive(void) {
    char character = ' ';
    int value;

    do {
        scanf("%d%c", &value, &character);

        if (character != '\n') {
            clearInputBuffer();
            printf("Error! Input a number: ");
        }

        if (value <= 0) {
            printf("ERROR! Value must be > 0: ");
        }
    } while (value <= 0);

    // After checks are completed we can return the value
    return value;
}

// This function guarantees that an integer value is entered within the range (inclusive) and returned. If a value from outside the range is entered, display an error message and continue to prompt until a value in the given range is entered.
int inputIntRange(int lowerBound, int upperBound) {
    char character = ' ';
    int value;

    do {
        scanf("%d%c", &value, &character);

        if (character != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

        else if (!(value <= upperBound && value >= lowerBound)) {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }
    } while (!(value <= upperBound && value >= lowerBound));

    // After checks are completed we can return the value
    return value;
}

// This function guarantees a single character value is entered within the list of valid characters and returned. If an entered character is not in the list of valid characters, display an error message and prompt again.
char inputCharOption(char str[]) {
    int i, count = 0;
    char input;

    do {
        scanf(" %c", &input);

        for (i = 0; str[i] != '\0'; i++) {
            if (input == str[i]) {
                count++;
            }
        }

        if (count == 0) {
            printf("ERROR: Character must be one of [%s]: ", str);
        }
    } while (count == 0);

    // After all checks are passed we will return the input value
    clearInputBuffer();
    return input;
}

// This function guarantees a C string value is entered containing the number of characters within the range specified by the 2nd and 3rd arguments.
void inputCString(char* str, int minChar, int maxChar) {
    int flag = 1;
    char ch = 'a';

    while (flag) {
        int len = 0;
        // Takes a string as input until it sees a newline character
        while (ch != '\n' && len <= maxChar) {
            ch = getchar();
            str[len] = ch;
            len++;
        };

        // If the string is less than or equal to the maxChars we will just add '\0' to the end to mark the end of the string
        if (ch == '\n' && len <= (maxChar + 1)) {
            len--;
            str[len] = '\0';
        }
        // If length is more than maxChar, we will add '\0' to the end and ignore the extra characters. We will also remove the extra characters from the buffer.
        else {
            str[maxChar] = '\0';
            clearInputBuffer();
        }

        if (minChar == maxChar && len != minChar) {
            printf("ERROR: String length must be exactly %d chars: ", minChar);
            ch = 'a';
        }
        else if (len < minChar || len > maxChar) {
            if (len > maxChar) {
                printf("ERROR: String length must be no more than %d chars: ", maxChar);
                ch = 'a';
            }
            else if (len < minChar) {
                printf("ERROR: String length must be between %d and %d chars: ", minChar, maxChar);
                ch = 'a';
            }
        }
        else {
            flag = 0;
        }
    }
}

// This function is the same as inputCString but is exclusively for numbers
void inputCStringNumbers(char* str, int minChar, int maxChar) {
    int flag = 1;
    char ch = 'a';

    while (flag) {
        int len = 0;
        // Takes a string as input until it sees a newline character
        while (ch != '\n' && len <= maxChar) {
            ch = getchar();
            str[len] = ch;
            len++;
        };

        // If the string is less than or equal to the maxChars we will just add '\0' to the end to mark the end of the string
        if (ch == '\n' && len <= (maxChar + 1)) {
            len--;
            str[len] = '\0';
        }
        // If length is more than maxChar, we will add '\0' to the end and ignore the extra characters. We will also remove the extra characters from the buffer.
        else {
            str[maxChar] = '\0';
            clearInputBuffer();
        }

        if (minChar == maxChar && len != minChar) {
            printf("Invalid 10-digit number! Number: ");
            ch = 'a';
        }
        else {
            flag = 0;
        }
    }
}

// The purpose of this function is to display an array of 10-character digits as a formatted phone number.
void displayFormattedPhone(const char* str) {
    int len = 0, i;

    len = strlen(str);

    if (len == 10) {
        i = 0;
        printf("(");
        while (i < 3) {
            printf("%c", str[i]);
            i++;
        }
        printf(")");
        while (i < 6) {
            printf("%c", str[i]);
            i++;
        }
        printf("-");
        while (i < 10) {
            printf("%c", str[i]);
            i++;
        }
    }
    else {
        printf("(___)___-____");
    }
    if (str != 0) {
        for (i = 0; str[i] != '\0'; i++)
            len++;
    }
}