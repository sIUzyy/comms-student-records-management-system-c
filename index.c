#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to represent a single student record
struct student {
    int id;
    char name[128];
    char major[128];
    float gpa;
};

int main() {
    // Array to store student records
    struct student students[MAX_STUDENTS];
    int numStudents = 0; // Number of students in the array

    // Add a new student to the array
    printf("Enter the ID of the new student: ");
    scanf("%d", &students[numStudents].id);

    printf("Enter the name of the new student: ");
    scanf("%s", students[numStudents].name);

    printf("Enter the major of the new student: ");
    scanf("%s", students[numStudents].major);

    printf("Enter the GPA of the new student: ");
    scanf("%f", &students[numStudents].gpa);

    numStudents++;
    printf("Added student successfully.\n");

    // Modify an existing student in the array
    printf("Enter the ID of the student to modify: ");
    int id;
    scanf("%d", &id);

    int i;
    for (i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            // Found the student, update their name
            printf("Enter the new name of the student: ");
            scanf("%s", students[i].name);
            printf("Modified student successfully.\n");
            break;
        }
    }
    if (i == numStudents) {
        printf("Error: No student found with ID %d.\n", id);
    }

    // View a single student record
    printf("Enter the ID of the student to view: ");
    scanf("%d", &id);

    for (i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            // Found the student, display their record
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Major: %s\n", students[i].major);
            printf("GPA: %.2f\n", students[i].gpa);
            break;
        }
    }
    if (i == numStudents) {
        printf("Error: No student found with ID %d.\n", id);
    }

    // View all student records
    printf("All student records:\n");
    for (i = 0; i < numStudents; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Major: %s\n", students[i].major);
        printf("GPA: %.2f\n", students[i].gpa);
        printf("\n");
    }

    // Calculate and display the average GPA of all students
    float totalGPA = 0.0;
    
    for (i = 0; i < numStudents; i++) {
        totalGPA += students[i].gpa;
    }
    float averageGPA = totalGPA / numStudents;
    printf("Average GPA: %.2f\n", averageGPA);

    // Calculate and display the number of students in a particular major
    char major[128];
    printf("Enter the major to search for: ");
    scanf("%s", major);

    int numInMajor = 0;
    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].major, major) == 0) {
            numInMajor++;
        }
    }
    printf("Number of students in major %s: %d\n", major, numInMajor);

    return 0;
}

