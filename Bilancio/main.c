#include "prototypes.h"


int main(int argc, char **argv) {
    char filename[MAX_STR];

    printf("Inserisci il nome del file: ");
    scanf("%s", filename);

    //strcpy(filename, argv[1]);

    //printf("%s", filename);

    update_Income(filename);




    return 0;
}
