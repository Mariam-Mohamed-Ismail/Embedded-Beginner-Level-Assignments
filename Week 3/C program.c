#include <stdio.h>
#include <string.h>

// Function to check if the ID ends with '5' and the password is the same as the ID
int check_student(char *id, char *password) {
    int id_length = strlen(id);
    if (id[id_length - 1] == '5' && strcmp(id, password) == 0) {
        return 1; // True
    }
    return 0; // False
}

// Function to calculate total grade percentage
float calculate_total_grade(float grades[], int num_grades) {
    float total = 0;
    for (int i = 0; i < num_grades; i++) {
        total += grades[i];
    }
    return (float)(total / num_grades);
}

// Function to determine the overall rating based on the total grade percentage
void determine_overall_rating(float total_grade) {
    if (total_grade >= 90) {
        printf("Overall Rating: Excellent\n");
    } else if (total_grade >= 80) {
        printf("Overall Rating: Very Good\n");
    } else if (total_grade >= 70) {
        printf("Overall Rating: Good\n");
    } else if (total_grade >= 50) {
        printf("Overall Rating: Pass\n");
    } else {
        printf("Overall Rating: Failed\n");
    }
}

int main() {
    char id[20];
    char password[20];
    char name[50];
    int num_grades;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your ID: ");
    scanf("%s", id);

    printf("Enter your password: ");
    scanf("%s", password);

    if (check_student(id, password)) {
        printf("Welcome, %s!\n", name);

        printf("Enter the number of grades: ");
        scanf("%d", &num_grades);

        float grades[num_grades];
        for (int i = 0; i < num_grades; i++) {
            printf("Enter grade %d: ", i + 1);
            scanf("%f", &grades[i]);
        }

        float total_grade = calculate_total_grade(grades, num_grades);
        printf("Total Grade: %.2f%%\n", total_grade);

        determine_overall_rating(total_grade);

        if (total_grade >= 50) {
            printf("Congratulations, %s! Keep up the amazing work!\n", name);
        } else {
            printf("Don't worry, %s. Keep working hard!\n", name);
        }
    } else {
        printf("Access Denied. Invalid ID or Password.\n");
    }

    return 0;
}
