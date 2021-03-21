//
// Created by Warnakulasuriya Charu on 18/03/2021.
//

#include "prototypes.h"

void update_Income(char filename[]){
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;

    char str_temp[100];
    char* token;

    int num_tokens;
    int row = 0;
    int i = 0;

    Day_transaction  transactions[5];

    fp1 = fopen(filename, "r");
    fp2 = fopen("entrate.dat", "a");
    fp3 = fopen("uscite.dat", "a");

    while (!feof(fp1)){
        fgets(str_temp, 100, fp1);
        row++;
        if (row == 1){
            //transactions[i].day = atoi(str_temp);

        } else{
            num_tokens = 0;
            token = strtok(str_temp, ";\n");

            while (token != NULL){
                if (num_tokens == 0){
                    strcpy(transactions[i].t.mode,"C");
                } else if (num_tokens == 1){

                    transactions[i].t.import = atoi(token);
                } else if (num_tokens == 2){
                    strcpy(transactions[i].t.motive, token);
                }
                token = strtok(NULL, ";\n");
                num_tokens++;
            }
        }
        i++;
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

}