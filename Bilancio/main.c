#include "prototypes.h"


int main(int argc, char **argv) {
    char filename[MAX_STR];
    Day_transaction t[5];
    int arrDim; //test

    printf("Inserisci il nome del file: ");
    scanf("%s", filename);

    //strcpy(filename, argv[1]);

    //printf("%s", filename);

    arrDim = get_daily_transactions(t, filename);

    update_In_and_exp(t, arrDim);


    return 0;
}
