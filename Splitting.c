#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    // 256 because ascii + void operator
    char toSort[256];
    printf("Enter a String of ascii characters EG: 1, A, B, #, ?, -\n");
    // 255s because need limit to 255 characters + vo
    scanf("%255s", toSort);
    // initialize all values to 0
    char seen[256] = {0};
    // Accumulate values per time seen
    for (int i = 0; i < strlen(toSort); i++){
        seen[toSort[i]]++;       
    }
    int highest_count = 0;
    int highest_index = 0;
    // Print in Size order
    for (int j = 0; j < sizeof(seen) - 1; j++){
        for(int i = 0; i < sizeof(seen) -1; i++){
            if (seen[i] > 0){
                if(seen[i] >= highest_count){
                    highest_count = seen[i];
                    highest_index = i;
                }
            }     
        }
        if(seen[j] > 0){
            printf("Found: %d %c's\n", highest_count,highest_index);
            seen[highest_index] = 0;
            highest_count = 0;
        }
    }

}   