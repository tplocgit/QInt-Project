#include "pch.h"

class Tokenizer
{
public:
	static vector<string> Parse(string line, string seperator)
	{
		vector<string> tokens;
		int startPos = 0;
		size_t foundPos = line.find(seperator, startPos);
		while (foundPos != string::npos)
		{
			int count = foundPos - startPos;
			string token = line.substr(startPos, count);
			tokens.push_back(token);
			startPos = foundPos + seperator.length();
			foundPos = line.find(seperator, startPos);
		}
		int count = line.length() - startPos;
		string token = line.substr(startPos, count);
		tokens.push_back(token);
		return tokens;
	}
};