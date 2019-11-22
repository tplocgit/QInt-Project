#pragma once
#include "pch.h"
#include "Task.h"
#include "Tokenizer.h"

vector <Task*> readFile(string fileName);

Task*readLine(string lineInfo);
//----------------------

void outputFile(vector <string> output, string outputName);

