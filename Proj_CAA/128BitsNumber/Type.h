#pragma once

enum BASE {
	BINARY,
	DECIMAL,
	HEXADECIMAL,
	NONE
};

enum CASE1 {//convert
	CON_BIN,
	CON_HEX,
	CON_DEC,
	ROL,
	ROR,
	NOT,	//~
	NONE1
};

enum CASE2 {//caculate
	AND,	// &
	OR,		// |
	XOR,	// ^
	//-----
	ADD,
	MINUS,
	MULTIPLY,
	DIVIDE,
	//-----
	MOVE_LEFT,	//<<
	MOVE_RIGHT,	//>>
	NONE2
};