#include <bits/stdc++.h>
using namespace std;

// Return the first day any year
int getfirstDayOfTheYear(int year) {
    int day = (year*365 + ((year-1) / 4) - ((year-1) / 100) + ((year-1) / 400)) % 7;
    return day; 
}

int main() {
    
    char *Month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int dayOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Take year from user
    int year;
    printf("Enter your Year: ");
    scanf("%d", &year);

    // Check Leap Year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        dayOfMonth[1] = 29;
    }

    printf("\n\n...............Welcome to %d................\n", year);
    printf("\n\n............................................\n\n\n");

    int totalDay, spaceCounter = 0, weekDay;

    weekDay = getfirstDayOfTheYear(year);

    // Main code starts here
    for (int i = 0; i < 12; i++) {
        printf("______________________%s______________________\n\n", Month[i]);
        printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n\n");

        // Helps to find the first day of the month
        for (spaceCounter = 0; spaceCounter < weekDay; spaceCounter++){
            printf("\t");
        }

        totalDay = dayOfMonth[i];
        for (int j = 1; j <= totalDay; j++) {
            printf("%d\t", j);
            weekDay++;
            if (weekDay > 6) {
                weekDay = 0;
                printf("\n\n");
            }
        }
        printf("\n\n");
    }
    return 0;
}