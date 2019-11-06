#pragma once
#include"pch.h"

class NumBase{
private:
	int64_t* Bits;
public:
	NumBase& operator=(const NumBase& num);
public:
	NumBase Negative(const NumBase* num);
public:
	NumBase();
	NumBase(const NumBase& num);
	virtual ~NumBase();
};

