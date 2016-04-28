#pragma once
# include <iostream>
# include <fstream>
# include <string>
# include <stdlib.h>
# include <stdio.h>
# include <conio.h>
# include <ctype.h>
#include <iomanip>
using namespace std;

typedef enum
{
	IDENTIFIER,
	REG_32,
	REG_8,
	COMMAND,
	SEG_REG,
	ONESYMB,
	DIRECTIVE,
	DIR_TYPE,
	FAR_NEAR,
	TYPE_4,
	DEF_TYPE,
	CONST_16,
	CONST_10,
	CONST_BIN,
	CONST_STR,
	EOT,
	ERR
}TokenType;

struct lexem
{
	TokenType tokenType;
	char* lexem_view;
	int lexem_length;
	struct lexem *next;
};

bool isStartChar(char ch);
bool isOperators(char ch);
bool isDelimeters(char ch);
bool isSymbol(char ch);
TokenType analyze_word(char* mToken);
TokenType analyze_number(char* mToken);
bool isDirective(char* mToken);
bool isDir_Type(char* mToken);
bool isReg_32(char* mToken);
bool isReg_8(char* mToken);
bool isSegmentReg(char* mToken);
bool isCommand(char* mToken);
bool isFar_Near(char* mToken);
bool isBinary_Const(char* mToken);
bool is10_Const(char* mToken);
bool is16_Const(char* mToken);
bool isType4(char* mToken);
bool isDef_type(char* mToken);
bool isIdentifier(char* mToken);
bool isUnaccetable(char ch);
lexem* lexical_analys(string bufstr);



