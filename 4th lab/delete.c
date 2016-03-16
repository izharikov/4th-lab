//
//  delete.c
//  4th lab
//
//  Created by Admin on 16.03.16.
//  Copyright © 2016 Admin. All rights reserved.
//

#include <stdio.h>
#include "db_options.h"
void deleteFromTable(sqlite3*db, char*sql, char*zErrMsg){
    sql = "delete from empl_table where id = 5";
    int rc = -1;
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    
    if (rc != SQLITE_OK)
    {
        printf ("SQL ERROR: %s\n", sqlite3_errmsg(db));
        sqlite3_free(zErrMsg);
        
    }
    else
    {
        printf ("Records is successfull delete!");
        
    }
}
