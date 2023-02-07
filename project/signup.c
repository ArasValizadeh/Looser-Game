#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<"clui.h">
int main(void) {
    bool found = false;
    char user[100], pass[100], temp[100];
    int tedad = 0;
    FILE* fptr = fopen("Users.text", "r+");
    fscanf(fptr, " %d", &tedad);
    printf("enter your username :");
    scanf("%s", user);
    for (int i = 0; i < tedad * 2;i++) {
        fscanf(fptr, "%s", temp);
        if (i % 2 == 0 && strcmp(user, temp) == 0) {
            printf("This username exist!");
            found = true;
            fclose(fptr);
        }
    }
    if (found == false) {
        fprintf(fptr, "\n%s", user);
        printf("enter your password :");
        scanf("%s", pass);
        fprintf(fptr, " %s", pass);
        fprintf(fptr," %d",0);
        fseek(fptr, 0, SEEK_SET);
        fprintf(fptr, "%d", tedad + 1);
    }
    fclose(fptr);
    return 0;
}