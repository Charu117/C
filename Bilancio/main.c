#include "prototypes.h"


int main(int argc, char **argv) {
    char filename[MAX_STR];
    Day_transaction t[5];
    int arrDim;

    if (argv[1] != NULL) {
        strcpy(filename, argv[1]);

        arrDim = get_daily_transactions(t, filename);

        update_In_and_exp(t, arrDim);
    } else {
        printf("Errore! Non e' stato inserito il file di input\n");
    }

    printf("Saldo finale: %.2f \n", getTotalValues(ENTRATE) - getTotalValues(USCITE));

    return 0;
}
