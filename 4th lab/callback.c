//
//  callback.c
//  4th lab
//
//  Created by Admin on 16.03.16.
//  Copyright © 2016 Admin. All rights reserved.
//

#include <stdio.h>
#include "db_options.h"
int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
