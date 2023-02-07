#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include"clui.h"
char kalame[100], loggedin[100], jakhali[100], vorodi[100], eshtebah[100];
int counter = 0;
int emtiaz = 0;
void initializearray(char arr[], int size);
void initializejakhali(int size);
void printloose(int number);
void addscore(char loggedin[100], int ezafe);
void bubblesort(int score[], char user[][100], int size);
int lenstring(char kalame[]);
void printeshtebah(char eshtebah[]);
int checkwordinarray(char vorodi[], char input, int size);
int choiceword();
void printarrint(int arr[], int size);
void printarrchar(char arr[], int size);
void addword();
void showscore();
void changepass();
int login();
void signup();
int playgame();
int secondmenu();
int firstmenu();
bool checkpass(char pass[], int size);
void gethelp();
int main(void) {
    firstmenu();
}
void printloose(int number) {
    change_color_rgb(150, 10, 15);
    if (number == 1) {
        printf(" _\n");
        printf("| |\n");
        printf("| |\n");
        printf("|_|\n");
    }
    if (number == 2) {
        printf(" _   ___\n");
        printf("| | / _ \\ \n");
        printf("| || (_) |\n");
        printf("|_| \\___/\n");
    }
    if (number == 3) {
        printf(" _    ___    ___  \n");
        printf("| |  / _ \\  / __|\n");
        printf("| | | (_) | \\__ \\ \n");
        printf("|_|  \\___/  |___/  \n");
    }
    if (number == 4) {
        printf(" _    ___    ___    ___  \n");
        printf("| |  / _ \\  / __|  / _ \\\n");
        printf("| | | (_) | \\__ \\ |  __/\n");
        printf("|_|  \\___/  |___/  \\___| \n");
    }
    if (number == 5) {
        printf(" _    ___    ___    ___   _ __ \n");
        printf("| |  / _ \\  / __|  / _ \\ | '__|\n");
        printf("| | | (_) | \\__ \\ |  __/ | | \n");
        printf("|_|  \\___/  |___/  \\___| |_| \n");
    }
    reset_color();
}
void changepass() {
    clear_screen();
    char passwordghabli[100];
    char passwordjadid[100];
    printf("Enter current password :\n");
    scanf("%s", passwordghabli);
    printf("Enter new password :\n");
    scanf("%s", passwordjadid);
    char user[100][100], pass[100][100];
    int score[100][1];
    FILE* fptr = fopen("Users.text", "r+");
    int tedadkarbar;
    fscanf(fptr, "%d", &tedadkarbar);
    if (checkpass(passwordjadid, lenstring(passwordjadid)) == false) {
        printf("Password is incorect.\n(atleast 8 characters(with Capital and number and symbols(! @ ...)))\n");
    }
    else {
        for (int i = 0; i < tedadkarbar; i++) {
            int score2 = 0;
            fscanf(fptr, "%s %s %d", user[i], pass[i], &score2);
            if (strcmp(user[i], loggedin) == 0) {
                if (strcmp(passwordghabli, pass[i]) != 0) {
                    printf("Password is incorrect!\n");
                    secondmenu();
                }
                else if (strcmp(passwordghabli, pass[i]) == 0) {
                    printf("Password Changed!.\n");
                    strcpy(pass[i], passwordjadid);
                }
            }
            score[i][0] = score2;
        }
        fseek(fptr, 0, SEEK_SET);
        fprintf(fptr, "%d\n", tedadkarbar);
        for (int i = 0; i < tedadkarbar; i++) {
            if (i == tedadkarbar - 1) {
                fprintf(fptr, "%s %s %d", user[i], pass[i], score[i][0]);
            }
            else {
                fprintf(fptr, "%s %s %d\n", user[i], pass[i], score[i][0]);
            }
        }
    }
    fclose(fptr);
    secondmenu();
}
void addscore(char loggedin[100], int ezafe) {
    char user[100][100], pass[100][100];
    int score[100][1];
    FILE* fptr = fopen("Users.text", "r+");
    int tedadkarbar;
    fscanf(fptr, "%d", &tedadkarbar);
    for (int i = 0; i < tedadkarbar; i++) {
        int score2 = 0;
        fscanf(fptr, "%s %s %d", user[i], pass[i], &score2);
        if (strcmp(loggedin, user[i]) == 0) {
            score2 += ezafe;
        }
        score[i][0] = score2;
    }
    fseek(fptr, 0, SEEK_SET);
    fprintf(fptr, "%d\n", tedadkarbar);
    for (int i = 0; i < tedadkarbar; i++) {
        if (i == tedadkarbar - 1) {
            fprintf(fptr, "%s %s %d", user[i], pass[i], score[i][0]);
        }
        else {
            fprintf(fptr, "%s %s %d\n", user[i], pass[i], score[i][0]);
        }
    }
    fclose(fptr);
}
void bubblesort(int score[], char user[][100], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i;j++) {
            if (score[j] < score[j + 1]) {
                int temp = score[j + 1];
                score[j + 1] = score[j];
                score[j] = temp;
                char temp2[100];
                strcpy(temp2, user[j + 1]);
                strcpy(user[j + 1], user[j]);
                strcpy(user[j], temp2);
            }
        }
    }
}
int lenstring(char kalame[]) {
    int i = 0;
    while (kalame[i] != '\0') {
        i++;
    }
    return i;
}
void printeshtebah(char eshtebah[]) {
    int i = 0;
    while (eshtebah[i] != '\0') {
        printf("%c ", eshtebah[i]);
        i++;
    }
    puts(" ");
}
int checkwordinarray(char vorodi[], char input, int size) {
    for (int i = 0; i < size; i++) {
        if (vorodi[i] == input) {
            return true;
        }
    }
    return false;
}
int choiceword() {
    FILE* fptr = fopen("source.text", "r");
    char buffer[100];
    int score3 = 0;
    int tedad = 0;
    fscanf(fptr, "%d", &tedad);
    if (tedad == 0) {
        printf("File is emty\nEnsert a word!\n");
        fclose(fptr);
        return 0;
    }
    else {
        srand(time(NULL));
        int r = rand();
        int number = (r % tedad);
        for (int i = 0; i <= number;i++) {
            fscanf(fptr, "%s", buffer);
            fscanf(fptr, " %d", &score3);
            if (number == i) {
                for (int j = 0; j < lenstring(buffer); j++) {
                    jakhali[j] = '_';
                }
                strcpy(kalame, buffer);
                fclose(fptr);
                return 1;
            }
        }
    }
}
void printarrint(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
void printarrchar(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
}
void addword() {
    FILE* fptr = fopen("source.text", "r+");
    int tedadkalame = 0;
    char pishnahad[100];
    char check[100];
    int emtiaz = 0;
    bool found = false;
    fscanf(fptr, " %d", &tedadkalame);
    printf("Enter word:\n");
    scanf("%s", pishnahad);
    if (fptr == NULL) {
        printf("File is empty!\n");
        fclose(fptr);
    }
    else {
        for (int i = 0; i < tedadkalame * 2; i++) {
            fscanf(fptr, "%s", check);
            fscanf(fptr, "%d", &emtiaz);
            if (strcmp(pishnahad, check) == 0) {
                found = true;
                break;
            }
        }
        if (found) {
            printf("Exist!\n");
            fclose(fptr);
        }
        else {
            printf("Added!\n");
            fprintf(fptr, "\n%s", pishnahad);
            fprintf(fptr, " %d", lenstring(pishnahad));
            fseek(fptr, 0, SEEK_SET);
            fprintf(fptr, "%d", tedadkalame + 1);
            fclose(fptr);
        }
    }
    secondmenu();
}
void showscore() {
    FILE* fptr = fopen("Users.text", "r+");
    if (fptr == NULL) {
        printf("File is empty!.");
        fclose(fptr);
    }
    int tedad = 0;
    char user[100][100], pass[100][100];
    int score[100];
    fscanf(fptr, " %d", &tedad);
    for (int i = 0; i < tedad; i++) {
        fscanf(fptr, "%s %s %d", user[i], pass[i], &score[i]);
    }
    bubblesort(score, user, tedad);
    change_color_rgb(153, 255, 51);
    for (int i = 0; i < tedad; i++) {
        printf("%d. %s : %d\n", i + 1, user[i], score[i]);
    }
    fclose(fptr);
    reset_color();
    secondmenu();
}
int login() {
    FILE* fptr = fopen("Users.text", "r+");
    if (fptr == NULL) {
        printf("File is empty!.");
        fclose(fptr);
    }
    int tedadaccount = 0;
    char User[100], Password[100], temp[100], temp2[100];
    printf("Enter the Username:");
    scanf("%s", User);
    printf("Enter the Password:");
    scanf("%s", Password);
    fscanf(fptr, " %d", &tedadaccount);
    bool found = false;
    for (int i = 0; i < tedadaccount * 3; i++) {
        fscanf(fptr, "%s", temp);
        if (i % 3 == 0 && strcmp(User, temp) == 0) {
            fscanf(fptr, "%s", temp2);
            if (strcmp(temp2, Password) == 0) {
                fscanf(fptr, " %d", &emtiaz);
                printf("Successfully logedin!\n");
                strcpy(loggedin, User);
                found = true;
                fclose(fptr);
                return true;
            }
        }
    }
    if (found == false) {
        printf("First signup please!\n");
        fclose(fptr);
        return false;
    }
}
void signup() {
    bool found = false;
    char user[100], pass[100], temp[100];
    int tedad = 0;
    FILE* fptr = fopen("Users.text", "r+");
    fscanf(fptr, " %d", &tedad);
    printf("Enter your username :");
    scanf("%s", user);
    for (int i = 0; i < tedad * 3;i++) {
        fscanf(fptr, "%s", temp);
        if (i % 3 == 0 && strcmp(user, temp) == 0) {
            printf("This username exist!\n");
            found = true;
            fclose(fptr);
        }
    }
    if (found == false) {
        printf("Enter your password (atleast 8 characters(with Capital and number and symbols(! @ ...))) :");
        scanf("%s", pass);
        if (checkpass(pass, lenstring(pass))) {
            fprintf(fptr, "\n%s", user);
            fprintf(fptr, " %s", pass);
            fprintf(fptr, " %d", 0);
            fseek(fptr, 0, SEEK_SET);
            fprintf(fptr, "%d", tedad + 1);
            printf("Account successfully createad . \n");
            fclose(fptr);
        }
        else {
            printf("Password is invalid!\n");
            fclose(fptr);
        }
    }
}
int playgame() {
    FILE* fptr = fopen("Users.text", "r+");
    int tedadkarbar = 0;
    fscanf(fptr, " %d", &tedadkarbar);
    int programe = choiceword();
    bool help = false;
    char temp[100];
    char tempemtiaz[100];
    for (int i = 0; i < tedadkarbar * 3; i++) {
        fscanf(fptr, "%s", temp);
        if (i % 3 == 0 && strcmp(loggedin, temp) == 0) {
            fscanf(fptr, "%s %d", tempemtiaz, &emtiaz);
        }
    }
    if (programe == 0) {
        secondmenu();
    }
    else {
        clear_screen();
        int tool = lenstring(kalame);
        for (int d = 0; d < tool; d++) {
            printf("%c ", jakhali[d]);
        }
        puts(" ");
        int wrong = 0;
        int index = 0;
        counter = 0;
        int mojaz = 0;
        if (tool > 8) {
            mojaz = 10;
        }
        else {
            mojaz = 5;
        }
        while (wrong != mojaz) {
            bool check = false;
            char input = '\0';
            printf("Enter a character (Help is : H (just once!)):\n");
            scanf(" %c", &input);
            clear_screen();
            if (input == 'H' && help == false && emtiaz > 0) {
                help = true;
                gethelp();
            }
            else if (input == 'H' && help == true) {
                printf("Help was used !\n");
            }
            else if (input == 'H' && help == false && emtiaz == 0) {
                printf("Not enough score\n");
            }
            if (input != 'H') {
                if (checkwordinarray(vorodi, input, 100) == false) {
                    vorodi[index] = input;
                    index++;
                }
                else {
                    printf("Repeated Character!\n");
                    check = true;
                }
                if (check == false) {
                    if (checkwordinarray(kalame, input, tool) == true) {
                        for (int i = 0; i < tool; i++) {
                            if (kalame[i] == input) {
                                jakhali[i] = input;
                                counter++;
                            }
                        }
                    }
                    else {
                        eshtebah[wrong] = input;
                        wrong++;
                    }
                }
            }
            printf("\n\n");
            printarrchar(jakhali, tool);
            puts(" ");
            if (counter == tool) {
                printf("YOU WON!\n");
                addscore(loggedin, tool);
                initializearray(eshtebah, 100);
                initializearray(vorodi, 100);
                initializejakhali(100);
                secondmenu();
            }
            if (wrong == mojaz) {
                printloose(5);
                initializearray(eshtebah, 100);
                initializearray(vorodi, 100);
                initializejakhali(100);
                secondmenu();

            }
            printf("Wrong characters : \n");
            printeshtebah(eshtebah);
            if (mojaz == 5) {
                printloose(wrong);
            }
            else {
                printloose(((int)wrong) / 2);
            }
            printf("%d Chance To Wrong !\n", mojaz - wrong);
        }
    }
    fclose(fptr);
}
int secondmenu() {
    change_color_rgb(0, 102, 255);
    printf("1.Start game\n2.Show leaderboard\n3.New word\n4.Exit\n5.Change password\n");
    reset_color();
    int input = 0;
    scanf("%d", &input);
    clear_screen();
    if (input == 1) {
        playgame();
    }
    else if (input == 2) {
        showscore();
    }
    else if (input == 3) {
        addword();
    }
    else if (input == 5) {
        changepass();
    }
    else {
        exit(1);
    }
}
int firstmenu() {
    change_color_rgb(0, 102, 255);
    printf("1.Login\n2.Signup\n3.Exit\n(1 or 2 or 3 )\n");
    int choice = 0;
    reset_color();
    scanf("%d", &choice);
    int javab = 0;
    clear_screen();
    if (choice == 1) {
        javab = login();
        if (javab) {
            secondmenu();
        }
        else {
            firstmenu();
        }
    }
    else if (choice == 2) {
        signup();
        firstmenu();
    }
    else {
        exit(1);
    }
}
bool checkpass(char pass[], int size) {
    bool number = false;
    bool special = false;
    bool big = false;
    bool low = false;
    if (size >= 8) {
        for (int i = 0; i < size; i++) {
            int ascii = (int)pass[i];
            if (ascii >= 48 && ascii <= 57) {
                number = true;
            }
            else if ((ascii >= 58 && ascii <= 64) || (ascii >= 33 && ascii <= 47) || (ascii >= 91 && ascii <= 96) || (ascii >= 123 && ascii <= 126)) {
                special = true;
            }
            else if (ascii >= 65 && ascii <= 90) {
                big = true;
            }
            else if (ascii >= 97 && ascii <= 122) {
                low = true;
            }
            if (low == true && big == true && special == true && number == true) {
                return true;
            }
        }
        return false;
    }
    else {
        return false;
    }
}
void initializearray(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = '\0';
    }
}
void initializejakhali(int size) {
    for (int i = 0; i < size; i++) {
        jakhali[i] = '_';
    }
}
void gethelp() {
    srand(time(NULL));
    int r = 0;
    int number = 0;
    do {
        srand(time(NULL));
        r = rand();
        number = (r % lenstring(kalame));
    } while (checkwordinarray(jakhali, kalame[number], lenstring(kalame)) == true);
    for (int i = 0; i < lenstring(kalame); i++) {
        if (kalame[i] == kalame[number]) {
            jakhali[i] = kalame[number];
            counter++;
        }
    }
    addscore(loggedin, -1);
}