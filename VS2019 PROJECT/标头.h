#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "resource.h"
#include "Class.h"
#include "mmsystem.h"
#include <wininet.h>
#include <string>
#include <TlHelp32.h>
#include <Shlwapi.h>
#include <Psapi.h>
#include <CommCtrl.h>
#pragma comment(lib,"winmm.lib")
#pragma comment( lib, "wininet.lib" ) 

void Start();
void GetResults();
void _continue();
void draw(string str);
void _playsound();
void drawpic();
void randraw();
void _sleep();


long i, j, life, maxrand;
int c;
long f;
long e;
long a;
short N, Y;
int t = 0;
char* input;
char aci = 3;
string  draw_love;
