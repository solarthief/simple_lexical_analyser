#include "LexicalAnalys.h"



TokenType analyze_word(char* mToken)
{
	if (isDirective(mToken)) return DIRECTIVE;
	else if (isDir_Type(mToken)) return DIR_TYPE;
	else if (isReg_32(mToken)) return REG_32;
	else if (isReg_8(mToken)) return REG_8;
	else if (isSegmentReg(mToken)) return SEG_REG;
	else if (isCommand(mToken)) return COMMAND;
	else if (isType4(mToken)) return TYPE_4;
	else if (isDef_type(mToken)) return DEF_TYPE;
	else if (isFar_Near(mToken)) return FAR_NEAR;
	else if (isIdentifier(mToken))return IDENTIFIER;
	else return ERR;
}

TokenType analyze_number(char* mToken)
{
	if (isBinary_Const(mToken)) return CONST_BIN;
	else if (is10_Const(mToken)) return CONST_10;
	else if (is16_Const(mToken)) return CONST_16;
	else return ERR;
}

bool isIdentifier(char* mToken)
{
	/*for (int iCount = 1; iCount <strlen(mToken) - 1; iCount++)
	{
		if (!isUnaccetable(mToken[iCount]))
			return false;
	}*/
	return true;
}

bool isType4(char* mToken)
{
	if (strlen(mToken) == 0) return false;
	char sKeywords[2][8] =
	{
		"DWORD","BYTE"
	};
	for (int iCount = 0; iCount <2; iCount++)
	{
		if (_stricmp(sKeywords[iCount], mToken) == 0)
			return true;
	}
	return false;
}
bool isDef_type(char* mToken)
{
	if (strlen(mToken) == 0) return false;
	char* sKeyword = "PTR";
	if (_stricmp(sKeyword, mToken) == 0)
			return true;
	return false;
}


bool isDirective(char* mToken)
{
	if (strlen(mToken) == 0) return false;
	char sKeywords[4][8] =
	{
		"SEGMENT","END", "ENDS", "ASSUME"
	};
	for (int iCount = 0; iCount <4; iCount++)
	{
		if (_stricmp(sKeywords[iCount], mToken) == 0)
			return true;
	}

	return false;
}

bool isDir_Type(char* mToken)
{
	if (strlen(mToken) == 0) return false;
	char sKeywords[3][3] =
	{
		"DB","DD","DW"
	};
	for (int iCount = 0; iCount <3; iCount++)
	{
		if (_stricmp(sKeywords[iCount], mToken) == 0)
			return true;
	}
	return false;
}

bool isReg_32(char* mToken)
{
	if (strlen(mToken) == 0) return false;
	char sKeywords[8][4] =
	{
		"EAX","EBX", "ECX","EDX","ESP","EBP","ESI","EDI"
	};
	for (int iCount = 0; iCount <8; iCount++)
	{
		if (_stricmp(sKeywords[iCount], mToken) == 0)
			return true;
	}
	return false;
}

bool isReg_8(char* mToken)
{
	if (strlen(mToken) == 0) return false;
	char sKeywords[8][3] =
	{
		"AL","CL", "DL","BL","AH","CH","DH","BH"
	};
	for (int iCount = 0; iCount <8; iCount++)
	{
		if (_stricmp(sKeywords[iCount], mToken) == 0)
			return true;
	}
	return false;
}

bool isFar_Near(char* mToken)
{

	if (strlen(mToken) == 0) return false;
	char sKeywords[2][5] =
	{
		"FAR","NEAR"
	};
	for (int iCount = 0; iCount <2; iCount++)
	{
		if (_stricmp(sKeywords[iCount], mToken) == 0)
			return true;
	}
	return false;

}

bool isSegmentReg(char* mToken)
{
	if (strlen(mToken) == 0) return false;
	char sKeywords[6][3] =
	{
		"CS","DS", "ES","GS","FS","SS"
	};
	for (int iCount = 0; iCount <6; iCount++)
	{
		if (_stricmp(sKeywords[iCount], mToken) == 0)
		return true;
	}
	return false;
}


bool isCommand(char* mToken)
{
	if (strlen(mToken) == 0) return false;
	char sKeywords[10][6] =
	{
		"MOV","PUSH", "NEG","ADC","SBB","LDS","AND","JNAE",
		"JMP","POPAD"
	};
	for (int iCount = 0; iCount <10; iCount++)
	{
		if (_stricmp(sKeywords[iCount], mToken) == 0)
			return true;
	}
	return false;
}

bool isBinary_Const(char* mToken)
{
	if (strlen(mToken) == 0) return false;
	if (mToken[strlen(mToken) - 1] != 'B'&& mToken[strlen(mToken) - 1] != 'b')
		return false;
	return true;
}


bool is10_Const(char* mToken)
{
	if (strlen(mToken) == 0) return false;
	char* numbers = "0123456789";
	for (int iCount = 1; iCount <strlen(mToken) - 1; iCount++)
	{
		if (strrchr(numbers, mToken[iCount]) == NULL)
			return false;
	}
	if (mToken[strlen(mToken) - 1] != 'D'&& mToken[strlen(mToken) - 1] != 'd'&& strrchr(numbers, mToken[strlen(mToken) - 1]) == NULL)
	return false;
	return true;
}

bool is16_Const(char* mToken)
{
	if (strlen(mToken) == 0) return false;
	char* numbers = "0123456789ABCDEFabcdef";
	for (int iCount = 1; iCount <strlen(mToken) - 1; iCount++)
	{
		if (strrchr(numbers, mToken[iCount]) == NULL)
			return false;
	}

	if (mToken[strlen(mToken) - 1] != 'H'&& mToken[strlen(mToken) - 1] != 'h')
		return false;

	return true;
}

bool isUnaccetable(char ch)
{
	char* unacc = "ÉÖÓÊÅÍÃØÙÇÕ¯Ô²ÂÀÏÐÎËÄÆªß×ÑÌÈÒÜÁÞéöóêåíãøùçõ¿ô³âàïðîëäæºÿ÷ñìèòüáþ";
	if (strrchr(unacc, ch) == NULL)	return true;
	return false;
}

bool isStartChar(char ch)
{
	if (ch == '@' || ch == '$' || ch == '?' || ch == '_') return true;
	return false;
};

bool isOperators(char ch)
{
	if (ch == '+' || ch == '*'||ch=='/') return true;
	return false;
};

bool isDelimeters(char ch)
{
	if (ch == ' ' || ch == '	' || ch == ';') return true;
	return false;
};

bool isSymbol(char ch)
{
	if (ch == ':' || ch == ',' || ch == '[' || ch == ']'|| ch == '(' || ch == ')'|| ch == '='||ch=='&') return true;
	return false;
};


lexem* lexical_analys(string bufstr)
{
	char lookahead;
	struct lexem *head;
	struct lexem *buf;
	head = new lexem;
	buf = head;
	buf->tokenType = EOT;
	buf->lexem_view = 0;
	buf->lexem_length = 0;
	buf->next = NULL;
	if (!bufstr.empty())
	{
			
		for (int i = 0; i < bufstr.length(); i++) {

			lookahead = bufstr[i];

			if (lookahead == ';') i = bufstr.length();
			else if (!isUnaccetable(lookahead))
			{
				char* tokensymb = new char[2];
				int j = 0;
				tokensymb[j] = lookahead;
				char next_lookahead = bufstr[i + 1];
				tokensymb[j + 1] = 0;
				buf->tokenType = ERR;
				buf->lexem_view = tokensymb;
				buf->lexem_length = strlen(tokensymb);
				if (next_lookahead != '\n')
				{
					buf->next = new lexem;
					buf = buf->next;
					buf->next = NULL;
				}
			}
			else if (lookahead == '"' || lookahead == static_cast<char>(39))
			{
				char* tokenstring = new char[255];
				int j = 0;
				char next_lookahead = bufstr[i + 1];
				while (next_lookahead != '"' && next_lookahead != static_cast<char>(39) && next_lookahead != '\0')
				{
					tokenstring[j] = next_lookahead;
					i++;
					j++;
					next_lookahead = bufstr[i + 1];
				}
				i++;
				tokenstring[j] = 0;
				buf->tokenType = CONST_STR;
				buf->lexem_view = tokenstring;
				buf->lexem_length = strlen(tokenstring);
				if (next_lookahead != '\n')
				{
					buf->next = new lexem;
					buf = buf->next;
					buf->next = NULL;
				}
			}
			else if (isalpha(lookahead) || isStartChar(lookahead))
			{

				char* tokenword = new char[32];
				int j = 0;
				tokenword[j] = lookahead;
				char next_lookahead = bufstr[i + 1];
				while (!isSymbol(next_lookahead) && !isDelimeters(next_lookahead) && !isOperators(next_lookahead) && next_lookahead != '\0')
				{
					tokenword[j + 1] = next_lookahead;
					i++;
					j++;
					next_lookahead = bufstr[i + 1];

				}
				tokenword[j + 1] = 0;
				if (strlen(tokenword) > 7) buf->tokenType = ERR;
				else buf->tokenType = analyze_word(tokenword);
				for (int count = 0; count < strlen(tokenword); count++) {
					tokenword[count] = toupper(tokenword[count]);
				};
				buf->lexem_view = tokenword;
				buf->lexem_length = strlen(tokenword);
				if (next_lookahead != '\n')
				{
					buf->next = new lexem;
					buf = buf->next;
					buf->next = NULL;
				}

			}
			else if (isdigit(lookahead))
			{
				char* tokennumber = new char[32];
				int j = 0;
				tokennumber[j] = lookahead;
				char next_lookahead = bufstr[i + 1];
				while (!isSymbol(next_lookahead) && !isDelimeters(next_lookahead) && !isOperators(next_lookahead) && next_lookahead != '\0')
				{
					tokennumber[j + 1] = next_lookahead;
					i++;
					j++;
					next_lookahead = bufstr[i + 1];
				}
				tokennumber[j + 1] = 0;
				buf->tokenType = analyze_number(tokennumber);
				buf->lexem_view = tokennumber;
				buf->lexem_length = strlen(tokennumber);
				if (next_lookahead != '\n')
				{
					buf->next = new lexem;
					buf = buf->next;
					buf->next = NULL;
				}
			}
			else if (isSymbol(lookahead) || isOperators(lookahead))
			{
				char* tokensymb = new char[2];
				int j = 0;
				tokensymb[j] = lookahead;
				char next_lookahead = bufstr[i + 1];
				tokensymb[j + 1] = 0;
				buf->tokenType = ONESYMB;
				buf->lexem_view = tokensymb;
				buf->lexem_length = strlen(tokensymb);
				if (next_lookahead != '\n')
				{
					buf->next = new lexem;
					buf = buf->next;
					buf->next = NULL;
				}
			}
			
		}
	}

	return head;
}