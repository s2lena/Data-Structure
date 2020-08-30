#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#define NO_COLOR 0
#define RED 1
#define GREEN 2

#include <vector>
#include <iostream>

using namespace std;

bool CompleteGraph(bool** a, int n);
bool CircularGraph(bool** a, int n);
bool BiGraph(bool** a, int n);

#endif // _FUNCTION_H_
