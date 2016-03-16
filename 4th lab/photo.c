//
//  photo.c
//  4th lab
//
//  Created by Admin on 16.03.16.
//  Copyright © 2016 Admin. All rights reserved.
//

#include <stdio.h>
#include "db_options.h"

void getPhoto(sqlite3* db, char* sql, char* zErrMsg)
{
    char id[3];
    printf("Enter id user: ");
    scanf("%s", id);
    
    FILE *fp = fopen("/Users/admin/Documents/4lth ab/4th lab/photo.jpg", "wb");
    
    if (fp == NULL) {
        
        fprintf(stderr, "Cannot open image file\n");
        return;
    }
    
    int rc = -1;
    sql = "SELECT photo FROM worker WHERE photo IS NOT NULL AND id = %s";
    sprintf(sql,sql,id);
    printf(sql);
    
    sqlite3_stmt *pStmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &pStmt, 0);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "Failed to prepare statement\n");
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        
        sqlite3_close(db);
        
        return;
    }
    
    rc = sqlite3_step(pStmt);
    
    int bytes = 0;
    
    if (rc == SQLITE_ROW) {
        
        bytes = sqlite3_column_bytes(pStmt, 0);
    }
    
    int c;
    c = fwrite(sqlite3_column_blob(pStmt, 0), bytes, 1, fp);
    
    if (c < 1)
        printf("\nThe photo of this user is empty!\n");
    else
    {
        printf("\nYou can view the photo photo.jpg\n");
    }
    
    if (ferror(fp)) {
        
        fprintf(stderr, "fwrite() failed\n");
        
        return;
    }
    
    int r = fclose(fp);
    
    if (r == EOF) {
        fprintf(stderr, "Cannot close file handler\n");
    }
    
    rc = sqlite3_finalize(pStmt);
    
    
}