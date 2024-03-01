#include <stdio.h>

int main() {
    char name[50];
    int id;
    float grades[6], total = 0, percentage;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your ID: ");
    scanf("%d", &id);

    if (id % 10 != 5) {
        printf("Invalid ID\n");
        return 0;
    }

    for (int i = 0; i < 6; i++) {
        printf("Enter grade for subject %d: ", i + 1);
        scanf("%f", &grades[i]);
        total += grades[i];
    }

    percentage = total / 6;

    printf("Percentage: %.2f%%\n", percentage);

    if (percentage >= 85) {
        printf("Excellent\n");
    } else if (percentage >= 75) {
        printf("Very good\n");
    } else if (percentage >= 65) {
        printf("Good\n");
    } else if (percentage >= 50) {
        printf("Pass\n");
    } else {
        printf("Failed\n");
    }

    if (percentage >= 50) {
        printf("Keep up the amazing work, %s!\n", name);
    } else {
        printf("Don't give up, %s! stay positive Keep working hard.\n", name);
    }

    return 0;
}
