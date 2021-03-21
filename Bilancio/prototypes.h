//
// Created by Warnakulasuriya Charu on 18/03/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 20

typedef struct {
    char mode[2];
    float import;
    char motive[MAX_STR];
} Transaction;

typedef struct {
    int day;
    Transaction t;
} Day_transaction;

void update_Income(char filename[]);
void update_expense(char filename[]);

float total_income();
float total_expense();
