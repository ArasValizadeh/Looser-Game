#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<stdbool.h>
int main(void) {
    FILE* fptr = fopen("Users.text", "r+");
    if (fptr == NULL) {
        printf("File is empty!.");
        fclose(fptr);
    }
    int tedad = 0;
    char User[100], Password[100], temp[100], temp2[100];
    printf("Enter the Username:");
    scanf("%s", User);
    printf("Enter the Password:");
    scanf("%s", Password);
    fscanf(fptr, " %d", &tedad);
    bool found = false;
    for (int i = 0; i < tedad * 3; i++) {
        fscanf(fptr, "%s", temp);
        if (i % 3 == 0 && strcmp(User, temp) == 0) {
            fscanf(fptr, "%s", temp2);
            if (strcmp(temp2, Password) == 0) {
                printf("Successfully logedin!");
                found = true;
                break;
            }
        }
    }
    if (found == false) {
        printf("Wrong!");
    }
    fclose(fptr);
}