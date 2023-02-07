#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int main(void) {
    bool found = false;
    char kalame[100], temp[100];
    int tedad = 0;
    FILE* fptr = fopen("source.text", "r+");
    fscanf(fptr, " %d", &tedad);
    printf("enter a word :");
    scanf("%s", kalame);
    for (int i = 0; i < tedad;i++) {
        fscanf(fptr, "%s", temp);
        if (strcmp(kalame, temp) == 0) {
            printf("This word exist!");
            found = true;
            fclose(fptr);
            break;
        }
    }
    if (found == false) {
        fprintf(fptr, "\n%s", kalame);
        fseek(fptr, 0, SEEK_SET);
        fprintf(fptr, "%d", tedad + 1);
    }
    fclose(fptr);
    return 0;
}