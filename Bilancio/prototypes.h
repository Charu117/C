//
// Created by Warnakulasuriya Charu on 18/03/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 20
#define MAX 100
#define MAX_FIELDS 3
#define USCITE "uscite.dat"
#define ENTRATE "entrate.dat"

typedef struct {
    char mode[2];
    float import;
    char motive[MAX_STR];
} Transaction;

typedef struct {
    int day;
    Transaction t;
} Day_transaction;

int get_daily_transactions(Day_transaction transaction[], char filename[]); //ritorna il numero delle transazioni del file dato in input, oltre a caricare l'array "transaction"

void update_In_and_exp(Day_transaction transaction[], int); //aggiunge i nuovi transazioni ai files di ENTRATE e USCITE

float getTotalValues(char *fileName); //legge le righe dal file passato e ritorna la somma di importi di tutte le righe