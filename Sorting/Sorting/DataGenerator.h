#ifndef  _DATAGENERATOR_H_
#define _DATAGENERATOR_H_

#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;

void Swap(int& a, int& b);
void GenerateRandomData(int a[], int n); 
void GenerateSortedData(int a[], int n); 
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

#endif // _DATAGENERATOR_H_
