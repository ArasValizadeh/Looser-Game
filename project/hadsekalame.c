#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
char kalame[100];
char jakhali[100];
char vorodi[100];
char eshtebah[100];
int lenstring(char kalame[]) {
    int i = 0;
    while (kalame[i] != '\0') {
        i++;
    }
    return i;
}
void printarrchar(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
}
void printeshtebah(char eshtebah[]){
    int i = 0 ; 
    while(eshtebah[i]!= '\0'){
        printf("%c ",eshtebah[i]);
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
void choiceword() {
    FILE* fptr = fopen("source.text", "r");
    char buffer[100];
    int tedad = 0;
    fscanf(fptr, "%d", &tedad);
    srand(time(NULL));
    int r = rand();
    int number = (r % tedad);
    for (int i = 0; i <= number + 1;i++) {
        fscanf(fptr, "%s", buffer);
        if (number == i) {
            printf("%s\n", buffer);
            for (int j = 0; j < strlen(buffer); j++) {
                jakhali[j] = '_';
            }
            strcpy(kalame, buffer);
        }
    }
}
int main(void) {
    choiceword();
    int tool = lenstring(kalame);
    for (int d = 0; d < tool; d++) {
        printf("%c ", jakhali[d]);
    }
    puts(" ");
    int wrong = 0;
    int index = 0;
    int counter = 0;
    while (wrong != 5) {
        bool check = false;
        char input = '\0';
        printf("Enter a character :\n");
        scanf(" %c", &input);
        if (checkwordinarray(vorodi, input, 100) == false) {
            vorodi[index] = input;
            index++;
        }
        else {
            printf("Repeated Character\n");
            check = true;
        }
        if (check == false) {
            if (checkwordinarray(kalame, input, tool) == true) {
                for (int i = 0; i < tool; i++) {
                    if (kalame[i] == input) {
                        jakhali[i] = input;
                        counter ++ ; 
                    }
                }
            }
            else {
                eshtebah[wrong] = input;
                wrong++;
            }
        }
        printf("\n\n");
        printarrchar(jakhali, tool);
        puts(" ");
        if (counter == tool) {
            printf("YOU WON!");
            return 0;
        }
        if (wrong == 5) {
            printf("YOU LOOSE !");
            return 0;
        }
        printf("Wrong characters : \n");
        printeshtebah(eshtebah);
        printf("%d Chance To Wrong !\n", 5 - wrong);
    }
}