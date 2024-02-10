#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TIMESLOTS_COUNT 9

// Structure for a schedule
struct Schedule {
    char day[20];
    char timeslot[20];
    char room[20];
    char instructor[50];
    char course[50];
    struct Schedule* next;
};

// Function to insert a new schedule
void insertSchedule(struct Schedule** head, const char* day, const char* timeslot, const char* room, const char* instructor, const char* course) {
    struct Schedule* newNode = (struct Schedule*)malloc(sizeof(struct Schedule));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newNode->day, day);
    strcpy(newNode->timeslot, timeslot);
    strcpy(newNode->room, room);
    strcpy(newNode->instructor, instructor);
    strcpy(newNode->course, course);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Schedule* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display schedules for a specific day
void displaySchedulesByDay(struct Schedule* head, const char* day) {
    struct Schedule* current = head;

    printf("+---------------------+------------------+------------------+------------------+------------------+\n");
    printf("|        Time         |       Room       |    Instructor    |      Course      |\n");
    printf("+---------------------+------------------+------------------+------------------+------------------+\n");

    while (current != NULL) {
        if (strcmp(current->day, day) == 0) {
            printf("| %-19s | %-16s | %-16s | %-16s |\n", current->timeslot, current->room, current->instructor, current->course);
        }
        current = current->next;
    }

    printf("+---------------------+------------------+------------------+------------------+------------------+\n");
}

// Function to display schedules for a specific instructor
void displaySchedulesByInstructor(struct Schedule* head, const char* instructorName) {
    struct Schedule* current = head;

    printf("+---------------------+------------------+------------------+------------------+\n");
    printf("|        Day          |     Time Slot    |       Room       |      Course      |\n");
    printf("+---------------------+------------------+------------------+------------------+\n");

    while (current != NULL) {
        if (strcmp(current->instructor, instructorName) == 0) {
            printf("| %-19s | %-16s | %-16s | %-16s |\n", current->day, current->timeslot, current->room, current->course);
        }
        current = current->next;
    }

    printf("+---------------------+------------------+------------------+------------------+\n");
}

// Function to choose the day for creating the timetable
void chooseDay(char* day) {
    int choice;
    printf("Choose a day for creating the timetable:\n");
    printf("1. Monday\n");
    printf("2. Tuesday\n");
    printf("3. Wednesday\n");
    printf("4. Thursday\n");
    printf("5. Friday\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            strcpy(day, "Monday");
            break;
        case 2:
            strcpy(day, "Tuesday");
            break;
        case 3:
            strcpy(day, "Wednesday");
            break;
        case 4:
            strcpy(day, "Thursday");
            break;
        case 5:
            strcpy(day, "Friday");
            break;
        default:
            strcpy(day, ""); 
    }
}

// Function to select a time slot
void selectTimeSlot(char* timeslot) {
    int choice;
    printf("Select a time slot:\n");
    printf("1. 08:00AM - 09:00AM\n");
    printf("2. 09:00AM - 10:00AM\n");
    printf("3. 10:00AM - 11:00AM\n");
    printf("4. 11:00AM - 12:00AM\n");
    printf("5. 12:00AM - 01:00PM\n");
    printf("6. 01:00PM - 02:00PM\n");
    printf("7. 02:00PM - 03:00PM\n");
    printf("8. 03:00PM - 04:00PM\n");
    printf("9. 04:00PM - 05:00PM\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            strcpy(timeslot, "08:00AM - 09:00AM");
            break;
        case 2:
            strcpy(timeslot, "09:00AM - 10:00AM");
            break;
        case 3:
            strcpy(timeslot, "10:00AM - 11:00AM");
            break;
        case 4:
            strcpy(timeslot, "11:00AM - 12:00PM");
            break;
        case 5:
            strcpy(timeslot, "12:00PM - 01:00PM");
            break;
        case 6:
            strcpy(timeslot, "01:00PM - 02:00PM");
            break;
        case 7:
            strcpy(timeslot, "02:00PM - 03:00PM");
            break;
        case 8:
            strcpy(timeslot, "03:00PM - 04:00PM");
            break;
        case 9:
            strcpy(timeslot, "04:00PM - 05:00PM");
            break;
        default:
            strcpy(timeslot, ""); 
    }
}

// Function to add a new schedule
void addSchedule(struct Schedule** head) {
    char day[20];
    char timeslot[20];
    char room[20];
    char instructor[50];
    char course[50];

    chooseDay(day);
    selectTimeSlot(timeslot);

    printf("Enter room code: ");
    scanf("%s", room);
    printf("Enter instructor's name: ");
    scanf("%s", instructor);
    printf("Enter course name: ");
    scanf("%s", course);

    insertSchedule(head, day, timeslot, room, instructor, course);
    printf("Schedule added successfully!\n");
}

// Function to display the main menu
void displayMenu() {
    printf("\nMENU\n");
    printf("1. Add Schedule\n");
    printf("2. Display Schedule by Day\n");
    printf("3. Display Schedule by Instructor\n");
    printf("4. Exit\n");
}

// Function to perform login
int performLogin() {
    char username[20];
    char password[20];
    
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, "issa") == 0 && strcmp(password, "123") == 0)
        return 1; 
    else
        return 0;
}

int main() {
	
    if (!performLogin()) {
        printf("Login failed. Exiting program.\n");
        return 0;
    }

    struct Schedule* head = NULL;

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addSchedule(&head);
                break;
            case 2:
                {
                    char day[20];
                    chooseDay(day);
                    displaySchedulesByDay(head, day);
                }
                break;
            case 3:
                {
                    char instructorName[50];
                    printf("Enter instructor's name: ");
                    scanf("%s", instructorName);
                    displaySchedulesByInstructor(head, instructorName);
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);


    struct Schedule* current = head;
    while (current != NULL) {
        struct Schedule* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
