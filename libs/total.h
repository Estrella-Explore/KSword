#ifndef _TOTAL_H_

#define _TOTAL_H_

#include "../functions/show_logo.cpp"
#include <cctype>
#include <conio.h>
#include <cstring>
#include <iostream>
#include <lmcons.h>
#include <stdlib.h>
#include <time.h>
#include <userenv.h>
#include <windows.h>

int pw();
int options();
int show_logo();
int shell();
int loadcmd();
int wintop(); // no input and output,put window to top
int winuntop();
int fread();      // fast read,int i;i=fread();
void strtochar(); // copy: charusrname,usrname;chardoname,doname
void cprint(const char *,
            int); // colorful print not c++ print,only print char,you can change it but i suggest dont do that;
void ready();     // some loading process;
void getpcname(std::string &, std::string &);
void toLowerCase(std::string &, std::string &);
void cutpth(string, const char);           // has something with cmd"cd" and "cd..".It is already shit so dont touch it.
bool directoryExists(const std::string &); // input a output a bool.

string getCmdResult(const string &); // get cmd result.Need a command in string'

#endif // !_TOTAL_H_