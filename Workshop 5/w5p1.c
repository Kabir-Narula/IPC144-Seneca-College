/*<assessment example name: Workshop- #5(part -1)
Full name : Kabir Narula
Student id#: 127962223
Email : knarula9@myseneca.ca
Section : NAA
Authenticity Declartion:
I Declare this submission is the result of my own work and has not been
shared with any other student or third party provider. This submitted
piece of work is enitrely of my own creation*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void) {
    int JAN = 1;
    int DEC = 12;
    int year, month;

    printf("General Well-being Log\n======================\n");

    while (1) {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d%d", &year, &month);

        if (year < MIN_YEAR || year > MAX_YEAR) {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
         if (month < JAN || month > DEC) {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
         else if ((year >= MIN_YEAR && year <= MAX_YEAR) && (month >= 01 && month <= 12))
        {
            break;
        }
    }

    printf("\n*** Log date set! ***\n");
    printf("\nLog starting date: %d-", year);

    switch (month) {
    case 1: printf("JAN-"); break;
    case 2: printf("FEB-"); break;
    case 3: printf("MAR-"); break;
    case 4: printf("APR-"); break;
    case 5: printf("MAY-"); break;
    case 6: printf("JUN-"); break;
    case 7: printf("JUL-"); break;
    case 8: printf("AUG-"); break;
    case 9: printf("SEP-"); break;
    case 10: printf("OCT-"); break;
    case 11: printf("NOV-"); break;
    case 12: printf("DEC-"); break;
    }

    printf("01\n");

    return 0;
}
