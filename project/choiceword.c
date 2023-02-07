#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
int main(void) {
    FILE* fptr = fopen("source.text", "r");
    char buffer[50];
    int tedad = 0;
    fscanf(fptr, "%d", &tedad);
    srand(time(NULL));
    int r = rand();
    int number = (r % tedad);
    for (int i = 0; i <= number + 1;i++) {
        fscanf(fptr, "%s", buffer);
        if (number == i) {
            for(int j = 0 ; j<strlen(buffer) ; j++){
                printf("- ");
            }
        }
    }
}