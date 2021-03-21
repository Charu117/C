//
// Created by Warnakulasuriya Charu on 18/03/2021.
//

#include "prototypes.h"

//una funzione "privata"
void prepData(char *array[MAX_FIELDS], char temp[MAX]);


int get_daily_transactions(Day_transaction transactions[], char filename[]) {
    FILE *fp1 = fopen(filename, "r");
    char str_temp[MAX];
    int i = 0, day = 0;
    char *array[3];

    if (fp1) {
        while (!feof(fp1)) {
            fgets(str_temp, MAX, fp1);

            if (i == 0) {
                day = atoi(str_temp);
            } else {
                prepData(array, str_temp);

                transactions[i - 1].day = day;
                strcpy(transactions[i - 1].t.mode, array[0]);
                transactions[i - 1].t.import = atof(array[1]);
                strcpy(transactions[i - 1].t.motive, array[2]);

            }
            i++;
        }
        fclose(fp1);
    } else {
        printf("File inserito non e' esistente\n");
    }
    return i - 1;
}

void prepData(char *array[], char temp[]) {
    char *token = strtok(temp, ";\n");
    int i = 0;

    while (token != NULL) {
        array[i++] = token;
        token = strtok(NULL, ";\n");
    }
}

void update_In_and_exp(Day_transaction transaction[], int rows) {
    FILE *ent = fopen("entrate.dat", "a");
    FILE *usc = fopen("uscite.dat", "a");

    for (int i = 0; i < rows; ++i) {
        if (strcmp(transaction[i].t.mode, "E") == 0) {
            fprintf(ent, "%d;%.2f;%s;\n", transaction[i].day, transaction[i].t.import, transaction[i].t.motive);
        } else {
            fprintf(usc, "%d;%.2f;%s;\n", transaction[i].day, transaction[i].t.import, transaction[i].t.motive);
        }
    }

    fclose(ent);
    fclose(usc);

}

float getTotalValues(char *fileName) {
    float incomes = 0;
    FILE *fp = fopen(fileName, "r");
    char str_temp[MAX];
    char *str_temp_arr[3];
    while (!feof(fp)) {
        fgets(str_temp, MAX, fp);
        if (!feof(fp)) {
            prepData(str_temp_arr, str_temp);
            incomes += atof(str_temp_arr[1]);
        }
    }
    fclose(fp);
    return incomes;
}

//cestino

//token = strtok(str_temp, ";\n");

/*while (token != NULL){
    if (num_tokens == 0){
        transactions[i-1].day = day;
        strcpy(transactions[i-1].t.mode,token);
    } else if (num_tokens == 1){
        transactions[i-1].t.import = atof(token);
    } else if (num_tokens == 2){
        strcpy(transactions[i-1].t.motive, token);
    }

    token = strtok(NULL, ";\n");
    num_tokens++;
}*/