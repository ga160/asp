#pragma once
#include <iostream>
#include <string>
using namespace std;


char* convStr(string c);
void RLECompress(string c, char *izlaz);
void RLEDecompress(string c, char *izlaz);

void compressTest();