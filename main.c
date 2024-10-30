#include <stdio.h>
#include <string.h>

struct login {
    char first_name[20];
    char last_name[20];
    char gender[20];
    int age;
    char nationality[20];
    char address[100];
    char nid[20];
    char user_name[20];
    char password[20];
};

void display_menu();
void login();
void registe();

void registe() {
    FILE *log = fopen("login12.csv", "a");
    if (!log) {
        perror("Error opening file");
        return;
    }

    struct login l;

    printf("Enter your first name: ");
    scanf("%s", l.first_name);
    printf("Enter your last name: ");
    scanf("%s", l.last_name);
    printf("Enter your gender: ");
    scanf("%s", l.gender);
    printf("Enter your age: ");
    scanf("%d", &l.age);
    printf("Enter your nationality: ");
    scanf("%s", l.nationality);
    printf("Enter your address: ");
    scanf(" %[^\n]s", l.address);
    printf("Enter your NID: ");
    scanf("%s", l.nid);
    printf("Enter your username: ");
    scanf("%s", l.user_name);
    printf("Enter your password: ");
    scanf("%s", l.password);

    fprintf(log, "%s,%s,%s,%d,%s,%s,%s,%s,%s\n",
            l.first_name, l.last_name, l.gender, l.age, l.nationality, l.address, l.nid, l.user_name, l.password);

    fclose(log);

    printf("\nRegistration complete.\n\n");
}

void login() {
    char user_name[20], password[20];
    FILE *log = fopen("login12.csv", "r");
    if (!log) {
        perror("Error opening file");
        return;
    }

    struct login l;
    int found = 0;

    printf("Enter Username: ");
    scanf("%s", user_name);
    printf("Enter Password: ");
    scanf("%s", password);

    char line[256];
    while (fgets(line, sizeof(line), log)) {
        sscanf(line, "%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%s",
               l.first_name, l.last_name, l.gender, &l.age, l.nationality, l.address, l.nid, l.user_name, l.password);

        if (strcmp(user_name, l.user_name) == 0 && strcmp(password, l.password) == 0) {
            printf("Login successful!\n");
            found = 1;
            break;
        }
    }

    fclose(log);

    if (found) {
        display_menu();
    } else {
        printf("Invalid Username or Password.\n");
    }
}

void display_menu() {
    int choice;
    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Room\n");
        printf("2. Food\n");
        printf("3. Services\n");
        printf("4. Customer & Feedback\n");
        printf("5. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("call room function here.\n");
                break;
            case 2:
                printf("call food function here\n");
                break;
            case 3:
                printf("call service function here\n");
                break;
            case 4:
                printf("call customer & feedback function here\n");
                break;
            case 5:
                printf("Logout\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    int choice;
    while (1) {
        printf("Please select an option:\n");
        printf("1. Registration\n");
        printf("2. Login\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            registe();
        } else if (choice == 2) {
            login();
        } else {
            printf("Invalid selection.\n");
        }
    }

    return 0;
}
