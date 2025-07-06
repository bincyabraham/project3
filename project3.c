#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
void main()
{
    char names[MAX][50];
    int rolls[MAX];
    float marks[MAX];
    int count = 0;
    int choice;
    do 
    {
        printf("\n====== Student Record System ======\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student (Roll No or Name)\n");
        printf("4. Sort Students\n");
        printf("5. Top Scorer\n");
        printf("6. Average Marks\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        if (choice == 1)
        {
            if (count >= MAX)
            {
                printf("Student list full!\n");
                continue;
            }
            printf("Enter name: ");
            fgets(names[count], 50, stdin);
            names[count][strcspn(names[count], "\n")] = 0;

            printf("Enter roll number: ");
            scanf("%d", &rolls[count]);

            printf("Enter marks: ");
            scanf("%f", &marks[count]);
            getchar();  

            count++;
            printf("Student added successfully!\n");

        } 
        else if (choice == 2)
        {
            printf("\n--- Student Records ---\n");
            for (int i = 0; i < count; i++) 
            {
                printf("%d. Name: %s | Roll: %d | Marks: %.2f\n", i + 1,
                       names[i], rolls[i], marks[i]);
            }

        }
        else if (choice==3)
        {
            int opt;
            printf("Search by: 1. Roll Number  2. Name\nEnter option: ");
            scanf("%d", &opt);
            getchar();

            if (opt == 1)
            {
                int r;
                printf("Enter roll number: ");
                scanf("%d", &r);
                int found = 0;
                for (int i = 0; i < count; i++)
                {
                    if (rolls[i] == r)
                    {
                        printf("Found: %s | Roll: %d | Marks: %.2f\n",
                               names[i], rolls[i], marks[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Student not found.\n");

            } 
            else if (opt == 2)
            {
                char searchName[50];
                printf("Enter name: ");
                fgets(searchName, 50, stdin);
                searchName[strcspn(searchName, "\n")] = 0;

                int found = 0;
                for (int i = 0; i < count; i++) 
                {
                    if (strcasecmp(names[i], searchName) == 0) 
                    {
                        printf("Found: %s | Roll: %d | Marks: %.2f\n",
                               names[i], rolls[i], marks[i]);
                        found = 1;
                    }
                }
                if (!found) printf("Student not found.\n");
            }

        } else if (choice == 4) {
            int sortChoice;
            printf("Sort by: 1. Marks (Descending)  2. Name (Alphabetically)\nEnter option: ");
            scanf("%d", &sortChoice);

            if (sortChoice == 1) {
                for (int i = 0; i < count - 1; i++) 
                {
                    for (int j = i + 1; j < count; j++) 
                    {
                        if (marks[i] < marks[j])
                        {
                            float tempMark = marks[i];
                            marks[i] = marks[j];
                            marks[j] = tempMark;

                            int tempRoll = rolls[i];
                            rolls[i] = rolls[j];
                            rolls[j] = tempRoll;

                            char tempName[50];
                            strcpy(tempName, names[i]);
                            strcpy(names[i], names[j]);
                            strcpy(names[j], tempName);
                        }
                    }
                }
                printf("Sorted by marks.\n");

            } 
            else if (sortChoice == 2)
            {
                for (int i = 0; i < count - 1; i++)
                {
                    for (int j = i + 1; j < count; j++)
                    {
                        if (strcasecmp(names[i], names[j]) > 0)
                        {
                            float tempMark = marks[i];
                            marks[i] = marks[j];
                            marks[j] = tempMark;

                            int tempRoll = rolls[i];
                            rolls[i] = rolls[j];
                            rolls[j] = tempRoll;

                            char tempName[50];
                            strcpy(tempName, names[i]);
                            strcpy(names[i], names[j]);
                            strcpy(names[j], tempName);
                        }
                    }
                }
                printf("Sorted by name.\n");
            }

        } else if (choice == 5)
        {
            if (count == 0) 
            {
                printf("No students in list.\n");
                continue;
            }
            int topIndex = 0;
            for (int i = 1; i < count; i++)
            {
                if (marks[i] > marks[topIndex])
                {
                    topIndex = i;
                }
            }
            printf("Top Scorer: %s | Roll: %d | Marks: %.2f\n",
                   names[topIndex], rolls[topIndex], marks[topIndex]);

        }
        else if (choice == 6)
        {
            if (count == 0)
            {
                printf("No students in list.\n");
                continue;
            }
            float sum = 0;
            for (int i = 0; i < count; i++) 
            {
                sum += marks[i];
            }
            printf("Average marks: %.2f\n", sum / count);

        } 
        else if (choice == 7) 
        {
            printf("Exiting program.\n");
        } else
        {
            printf("Invalid choice. Try again.\n");
        }

    }
    while (choice != 7);
}