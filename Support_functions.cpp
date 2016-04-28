#include "LexicalAnalys.h"



string filename()
{
	string filename;
	cout << "Введiть назву файлу [.asm]: ";
	cin >> filename;
	filename = filename + ".asm";
	return filename;
}

void create_sub_files()
{
	ofstream ofs("lexems.txt");
	ofs.close();
	return;
}

void print_list(lexem* Head, int i_str)
{
	fstream file("lexems.txt", ios::app);
	int i_lex = 1;
	lexem* buf = Head;
	char* mytype = "";
	TokenType buftype;
	file << "РЯДОК № ";
	file << i_str + 1 << endl;
	file << "---------------------------------------------------------------------------------------" << endl;
	file << "| № |     ЛЕКСЕМА     |      ДОВЖИНА     |                  ТИП ЛЕКСЕМИ               |" << endl;
	file << "---------------------------------------------------------------------------------------" << endl;
	if (buf->tokenType == EOT) file << "ПОРОЖНІЙ РЯДОК";
	while (buf->next)
	{
		file << "|" << setw(3) << i_lex << "|";
		file << setw(17) << buf->lexem_view << "|";
		file << setw(18) << buf->lexem_length << "|";
		buftype = buf->tokenType;
		if (buftype == CONST_STR) mytype = "Строкова константа";
		else if (buftype == DIRECTIVE) mytype = "Ідентифікатор директиви";
		else if (buftype == DIR_TYPE) mytype = "Ідентифікатор директиви данних тип 1";
		else if (buftype == REG_32) mytype = "Iдентифікатор 32-бітного регістру";
		else if (buftype == REG_8) mytype = "Iдентифікатор 8-бітного регістру";
		else if (buftype == SEG_REG) mytype = "Ідентифікатор сегментного регістру";
		else if (buftype == COMMAND) mytype = "Ідентифікатор мнемокоду машинної інструкції";
		else if (buftype == TYPE_4) mytype = "Ідентифікатор тип 4";
		else if (buftype == FAR_NEAR) mytype = "Атрибут відстані";
		else if (buftype == IDENTIFIER) mytype = "Iдентифікатор користувача або невизначенний";
		else if (buftype == CONST_BIN) mytype = "Двiйкова константа";
		else if (buftype == CONST_10) mytype = "Десяткова константа";
		else if (buftype == CONST_16) mytype = "Шіснадцяткова константа";
		else if (buftype == ONESYMB) mytype = "Односимвольна";
		else if (buftype == DEF_TYPE) mytype = "Ідентифікатор оператора визначення типу";
		else if (buftype == ERR) mytype = "ПОМИЛКА";
		file << setw(44) << mytype << "|";
		buf = buf->next;
		file << endl;
		file << "---------------------------------------------------------------------------------------" << endl;
		i_lex++;
	}
	file << endl;
	file << endl;
	return;

}



string string_correction(string bufstr)
{
	if (bufstr.empty()) return bufstr;
	for (int i = 0; i < bufstr.length(); i++){
		if (bufstr[i] == 'а') bufstr[i] = 'a';
		else if (bufstr[i] == 'А') bufstr[i] = 'A';
		else if (bufstr[i] == 'е') bufstr[i] = 'e';
		else if (bufstr[i] == 'Е') bufstr[i] = 'E';
		else if (bufstr[i] == 'і') bufstr[i] = 'i';
		else if (bufstr[i] == 'І') bufstr[i] = 'I';
		else if (bufstr[i] == 'у') bufstr[i] = 'y';
		else if (bufstr[i] == 'о') bufstr[i] = 'o';
		else if (bufstr[i] == 'О') bufstr[i] = 'O';
		else if (bufstr[i] == 'р') bufstr[i] = 'p';
		else if (bufstr[i] == 'Р') bufstr[i] = 'P';
		else if (bufstr[i] == 'Н') bufstr[i] = 'H';
		else if (bufstr[i] == 'К') bufstr[i] = 'K';
		else if (bufstr[i] == 'х') bufstr[i] = 'x';
		else if (bufstr[i] == 'Х') bufstr[i] = 'X';
		else if (bufstr[i] == 'с') bufstr[i] = 'c';
		else if (bufstr[i] == 'С') bufstr[i] = 'C';
		else if (bufstr[i] == 'В') bufstr[i] = 'B';
		else if (bufstr[i] == 'М') bufstr[i] = 'M';
		else if (bufstr[i] == 'Т') bufstr[i] = 'T';
	}
	return bufstr;
}