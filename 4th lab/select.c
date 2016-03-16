//
//  select.c
//  4th lab
//
//  Created by Admin on 16.03.16.
//  Copyright © 2016 Admin. All rights reserved.
//

#include <stdio.h>
#include "db_options.h"

void selectFromTable(sqlite3 *db, char* sql, char* zErrMsg){
    int rc;
    sql = "select * from empl_table;";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if ( rc != SQLITE_OK){
        printf("Error select: %s\n", sqlite3_errmsg(db) );
    }
    else{
        printf("Success select\n");
    }
}