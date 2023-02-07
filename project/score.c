#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<stdbool.h>
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
void printarrint(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}
void printarrchar(char arr[][100], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }
}
int main(void) {
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
    printarrint(score, tedad);
    printarrchar(user, tedad);
    for (int i = 0; i < tedad; i++) {
        printf("%d. %s : %d\n", i + 1, user[i], score[i]);
    }
}