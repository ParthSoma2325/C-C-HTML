#include <stdio.h>

int main()
{
    int choice;

    /* Sample Match Data */
    int totalRuns = 245;
    int wickets = 8;
    float overs = 50.0;

    /* Bowler Details */
    char bowlerName[] = "J Bumrah";
    float bowlerOvers = 10.0;
    int runsGiven = 42;
    int wicketsTaken = 3;
    float economyRate = runsGiven / bowlerOvers;

    /* Match Records */
    int maxRuns = 120;
    int maxSixes = 6;
    int maxFours = 12;
    int maxWickets = 5;

    do
    {
        printf("\n===== CRICKET SCORE DISPLAY SYSTEM =====\n");
        printf("1. Print Match Statistics\n");
        printf("2. Print Runs Scored / Bowler Details\n");
        printf("3. Show Match Summary\n");
        printf("4. Display Match Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n--- Match Statistics ---\n");
            printf("Total Runs   : %d\n", totalRuns);
            printf("Wickets Lost : %d\n", wickets);
            printf("Overs Played : %.1f\n", overs);
            break;

        case 2:
            printf("\n--- Bowler Details ---\n");
            printf("Bowler Name   : %s\n", bowlerName);
            printf("Overs Bowled  : %.1f\n", bowlerOvers);
            printf("Runs Given    : %d\n", runsGiven);
            printf("Wickets Taken : %d\n", wicketsTaken);
            printf("Economy Rate : %.2f\n", economyRate);
            break;

        case 3:
            printf("\n--- Match Summary ---\n");
            printf("Total Score : %d/%d\n", totalRuns, wickets);
            printf("Overs       : %.1f\n", overs);
            printf("Result      : Team A won by %d runs\n", totalRuns - 220);
            break;

        case 4:
            printf("\n--- Match Records ---\n");
            printf("Maximum Runs Scored  : %d\n", maxRuns);
            printf("Maximum Sixes Hit    : %d\n", maxSixes);
            printf("Maximum Fours Hit    : %d\n", maxFours);
            printf("Maximum Wickets Taken: %d\n", maxWickets);
            break;

        case 5:
            printf("\nExiting the program...\n");
            break;

        default:
            printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
