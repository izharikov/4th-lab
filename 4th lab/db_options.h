//
//  db_options.h
//  4th lab
//
//  Created by Admin on 16.03.16.
//  Copyright © 2016 Admin. All rights reserved.
//

#ifndef db_options.h
#define db_options.h
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

#define CONNECT_SUCCESS 0;
#define CONNECT_ERROR -1;

void insertInTable(sqlite3 *, char*, char*);

void selectFromTable(sqlite3 *, char*, char*);

void deleteFromTable(sqlite3*, char*, char*);

void parameterizedQuery(sqlite3*, char*, char*);
void photoInFile(sqlite3*, char*, char*);
int callback(void *, int , char **, char **);

#endif