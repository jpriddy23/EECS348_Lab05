#include <stdio.h>

// Creating a function to find the possible combinations of ways to score and printing them
void possibleCombinations(int score, int TD_2pt, int TD_FG, int TD, int FG, int safety) {
    if (score == 0) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3 pt FG, %d Safety\n", TD_2pt, TD_FG, TD, FG, safety);
        return;
    }
    if (score >= 8) {
        // Try subtracting 8 points for a TD and 2 point conversion
        possibleCombinations(score - 8, TD_2pt + 1, TD_FG, TD, FG, safety);
    }
    if (score >= 7) {
        // Try subtracting 7 points for a TD and extra point
        possibleCombinations(score - 7, TD_2pt, TD_FG + 1, TD, FG, safety);
    }
    if (score >= 6) {
        // Try subtracting 6 points for a TD
        possibleCombinations(score - 6, TD_2pt, TD_FG, TD + 1, FG, safety);
    }
    if (score >= 3) {
        // Try subtracting 3 points for a field goal
        possibleCombinations(score - 3, TD_2pt, TD_FG, TD, FG + 1, safety);
    }
    if (score >= 2) {
        // Try subtracting 2 points for a safety
        possibleCombinations(score - 2, TD_2pt, TD_FG, TD, FG, safety + 1);
    }
}

int main() {
    int score;
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &score);

    // Exit if the score is 0 or 1
    if (score <= 1) {
        return 0;
    }
    
     // Recursive call to start finding combinations
    printf("Possible combinations of scoring plays:\n");
    possibleCombinations(score, 0, 0, 0, 0, 0);

    return 0;
}
