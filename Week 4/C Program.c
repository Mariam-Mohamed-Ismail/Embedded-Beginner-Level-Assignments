#include <stdio.h>
#include <string.h>

#define NUM_STUDENTS 3
#define NUM_SUBJECTS 6

// Define a structure to represent student data
struct Student {
    char id[7]; // Student ID consisting of six numbers
    int grades[NUM_SUBJECTS];
};

// Global array to store subject names
const char *subjectNames[NUM_SUBJECTS] = {"Math", "Circuits", "Chemistry", "English", "Physics", "Science"};

// Function prototypes
void displayAllGrades(struct Student students[]);
void displayGrade(struct Student students[], const char id[], int subjectIndex);

int main() {
    // Initialize an array of structures to store student data
    struct Student students[NUM_STUDENTS] = {
        {"100015", {90, 85, 95, 80, 87, 92}}, // Grades for student 1
        {"100025", {88, 91, 84, 89, 93, 82}}, // Grades for student 2
        {"100035", {82, 90, 88, 91, 85, 89}} // Grades for student 3
    };

    // Display IDs and grades of each student
    displayAllGrades(students);

    // Get user input for student ID and subject number
    char studentID[7];
    int subjectNumber;

    printf("Enter student ID: ");
    scanf("%s", studentID);

    printf("Enter subject number (0-5): ");
    scanf("%d", &subjectNumber);

    // Validate subject number input
    if (subjectNumber < 0 || subjectNumber >= NUM_SUBJECTS) {
        printf("Invalid subject number. Exiting...\n");
        return 1;
    }

    // Display grade for the entered student ID and subject number
    displayGrade(students, studentID, subjectNumber);

    return 0;
}

// Function to display IDs and grades of each student
void displayAllGrades(struct Student students[]) {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Student ID: %s\n", students[i].id);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("%s: %d\n", subjectNames[j], students[i].grades[j]);
        }
        printf("\n");
    }
}

// Function to display grade for a specific student and subject
void displayGrade(struct Student students[], const char id[], int subjectIndex) {
    int studentFound = 0;

    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("Student ID: %s\n", id);
            printf("Grade for subject %d (%s): %d\n", subjectIndex, subjectNames[subjectIndex], students[i].grades[subjectIndex]);
            studentFound = 1;
            break;
        }
    }

    if (!studentFound) {
        printf("Student ID '%s' not found.\n", id);
    }
}
