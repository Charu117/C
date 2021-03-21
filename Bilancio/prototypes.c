//
// Created by Warnakulasuriya Charu on 18/03/2021.
//

#include "prototypes.h"

//una funzione "privata"
void prepData(char* array[3], char temp[100]);


int get_daily_transactions(Day_transaction transactions[], char filename[]){
    FILE *fp1 = fopen(filename, "r");
    char str_temp[100];
    char* token;
    int num_tokens, i = 0, day = 0;
    char* array[3];

    while (!feof(fp1)){
        fgets(str_temp, 100, fp1);

        if (i == 0){
            day = atoi(str_temp);
        } else{
            num_tokens = 0;
            prepData(array, str_temp);

            transactions[i-1].day = day;
            strcpy(transactions[i-1].t.mode,array[0]);
            transactions[i-1].t.import = atof(array[1]);
            strcpy(transactions[i-1].t.motive, array[2]);

        }
        i++;
    }
    fclose(fp1);
   return i-1;
}

void prepData(char* array[3], char temp[100]) {
    char* p = strtok(temp, ";\n");
    int i = 0;

    while (p != NULL){
        array[i++] = p;
        p = strtok(NULL, ";\n");
    }
}

void update_In_and_exp(Day_transaction transaction[], int rows){
    FILE *ent = fopen("entrate.dat", "a");
    FILE *usc = fopen("uscite.dat", "a");

    for (int i = 0; i < rows; ++i) {
        if (strcmp(transaction[i].t.mode, "E") == 0){
            fprintf(ent, "%d;%.2f;%s;\n", transaction[i].day, transaction[i].t.import, transaction[i].t.motive);
        } else{
            fprintf(usc, "%d;%.2f;%s;\n", transaction[i].day, transaction[i].t.import, transaction[i].t.motive);
        }
    }

    fclose(ent);
    fclose(usc);

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