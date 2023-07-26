/*<assessment example name: Workshop- #5(part -2)
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
#define LOG_DAYS 3

int main(void) {
    int JAN = 1;
    int DEC = 12;
    int year, month, day = 1;
    float morning_rating, evening_rating;
    float morning_total = 0, evening_total = 0, overall_total;
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
    for (int i = 0; i < LOG_DAYS; i++) {
        printf("\n%d-FEB-%d\n", year, day);

        while (1) {
            printf("   Morning rating (0.0-5.0): ");
            if (scanf("%f", &morning_rating) != 1) {
                printf("Invalid input, please try again.\n");
                scanf("%*s");
            }
            else if (morning_rating < 0 || morning_rating > 5) {
                printf("   ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else {
                morning_total += morning_rating;
                break;
            }
        }

        while (1) {
            printf("   Evening rating (0.0-5.0): ");
            if (scanf("%f", &evening_rating) != 1) {
                printf("Invalid input, please try again.\n");
                scanf("%*s");
            }
            else if (evening_rating < 0 || evening_rating > 5) {
                printf("   ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else {
                evening_total += evening_rating;
                break;
            }
        }

        day++;
    }
    overall_total = morning_total + evening_total;
    float morning_avg = morning_total / LOG_DAYS;
    float evening_avg = evening_total / LOG_DAYS;
    float overall_avg = overall_total / (LOG_DAYS * 2);

    // Print the summary
    printf("\nSummary\n=======\n");
    printf("Morning total rating: %.3f\n", morning_total);
    printf("Evening total rating:  %.3f\n", evening_total);
    printf("----------------------------\n");
    printf("Overall total rating: %.3f\n", overall_total);
    printf("\nAverage morning rating: %.1f\n", morning_avg);
    printf("Average evening rating: %.1f\n", evening_avg);
    printf("----------------------------\n");
    printf("Average overall rating: %.1f\n", overall_avg);



}
