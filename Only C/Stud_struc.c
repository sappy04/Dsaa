#include <stdio.h>
#include <string.h>

// Define the structure for student
struct Student {
    int roll_no;
    char stud_name[50];
    char course[50];
};

// Function to display student details
void displayStudent(struct Student s) {
    printf("\nStudent Details:\n");
    printf("Roll Number: %d\n", s.roll_no);
    printf("Student Name: %s\n", s.stud_name);
    printf("Course: %s\n", s.course);
}

int main() {
    // Declare a student structure
    struct Student s;
    
    // Accept student details
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll_no);
    printf("Enter Student Name: ");
    scanf("%s", s.stud_name);
    printf("Enter Course: ");
    scanf("%s", s.course);
    
    // Pass the structure to the function to display details
    displayStudent(s);
    
    return 0;
}


