#include<stdio.h>
#include<stdlib.h>

#define MAX_N 100 // Maximum number of 2-grams
//I used fscanf fopen fprintf fclose
int main() {
    FILE *input, *output;//*fpointer (fptr)
    input = fopen("input.txt", "r");//r to read
    output = fopen("output.txt", "w");//w to write

    if (input == NULL || output == NULL) {
        printf("Error opening files.\n");//if there is not those files program prints this message
        return 1;
    }

    int previous, current;
    int n = 0; // Count of 2 grams
    int twoGrams[MAX_N][2]; // Array to store 2 grams
    int counter[MAX_N]={0}; // Array to store counts of 2 grams

    if (fscanf(input,"%d", &previous) != 1) {
        printf("Error reading from input file.\n");//if there is nothing program prints this message
        return 1;
    }

    while (fscanf(input,"%d",&current) == 1) {
        int same = 0;
        for (int i = 0; i < n; i++) {
            //chacking previous and current value are same or not
            if (twoGrams[i][0]== previous && twoGrams[i][1] == current) {//double check
                counter[i]++;
                same = 1;
                break;
            }
        }

        if (!same) {//if not same adding new 2 gram and adding to counter
            if (n < MAX_N) {
                twoGrams[n][0] = previous;
                twoGrams[n][1] = current;
                counter[n] = 1;
                n++;
            } else {
                break;
            }
        }

        previous = current;//passing next 2 gram after all process 
    }
    for (int i = 0; i < n; i++) {
        fprintf(output,"%d %d:%d\n", twoGrams[i][0], twoGrams[i][1], counter[i]);
        //writing 2 grams on output file in the desired format
    }

    fclose(input);//closing stream on input file
    fclose(output);//closing stream on output file

    return 0;
}


