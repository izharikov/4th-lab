//
//  parametrized.c
//  4th lab
//
//  Created by Admin on 16.03.16.
//  Copyright © 2016 Admin. All rights reserved.
//

#include <stdio.h>
#include "db_options.h"

void param(sqlite3* db, char* sql, char* zErrMsg)
{
    int choice = -1;
    
    printf("Choise a parameter of selecting:\n");
    printf("1. Id\n");
    printf("2. Lastname\n");
    printf("3. Country\n");
    printf("0. Cancel\n");
    scanf("%d", &choice);
    
    
    
    char ide[15];
    switch (choice) {
            
        case 0:
            return;
            break;
        case 1:
            printf("Enter id: ");
            scanf("%s", &ide);
            sql = "SELECT * FROM worker WHERE id = ";
            char *str = malloc(sizeof(char) * 100);
            str[0] = '\0';
            strcat(str, sql);
            strcat(str, ide);
            strcat(str, ";");
            doIt1(str, db, zErrMsg);
            free(str);
            break;
            
        case 2:
            printf("Enter lastname: ");
            scanf("%s", &ide);
            sql = "SELECT * FROM worker WHERE lastname = ";
            char *str1 = malloc(sizeof(char) * 100);
            str1[0] = '\0';
            strcat(str1, sql);
            strcat(str1, "'");
            strcat(str1, ide);
            strcat(str1, "'");
            strcat(str1, ";");
            doIt1(str1, db, zErrMsg);
            free(str1);
            break;
            
        case 3:
            printf("Enter country: ");
            scanf("%s", &ide);
            sql = "SELECT * FROM worker WHERE address = ";
            char *str2 = malloc(sizeof(char) * 100);
            str2[0] = '\0';
            strcat(str2, sql);
            strcat(str2, "'");
            strcat(str2, ide);
            strcat(str2, "'");
            strcat(str2, ";");
            doIt1(str2, db, zErrMsg);
            free(str2);
            break;
            
        default:
            printf("Invalid parameter.\n");
            break;
            
            
    }
    
}