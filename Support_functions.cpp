#include "LexicalAnalys.h"



string filename()
{
	string filename;
	cout << "����i�� ����� ����� [.asm]: ";
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
	file << "����� � ";
	file << i_str + 1 << endl;
	file << "---------------------------------------------------------------------------------------" << endl;
	file << "| � |     �������     |      �������     |                  ��� �������               |" << endl;
	file << "---------------------------------------------------------------------------------------" << endl;
	if (buf->tokenType == EOT) file << "�����Ͳ� �����";
	while (buf->next)
	{
		file << "|" << setw(3) << i_lex << "|";
		file << setw(17) << buf->lexem_view << "|";
		file << setw(18) << buf->lexem_length << "|";
		buftype = buf->tokenType;
		if (buftype == CONST_STR) mytype = "�������� ���������";
		else if (buftype == DIRECTIVE) mytype = "������������� ���������";
		else if (buftype == DIR_TYPE) mytype = "������������� ��������� ������ ��� 1";
		else if (buftype == REG_32) mytype = "I������������ 32-������ �������";
		else if (buftype == REG_8) mytype = "I������������ 8-������ �������";
		else if (buftype == SEG_REG) mytype = "������������� ����������� �������";
		else if (buftype == COMMAND) mytype = "������������� ��������� ������� ����������";
		else if (buftype == TYPE_4) mytype = "������������� ��� 4";
		else if (buftype == FAR_NEAR) mytype = "������� ������";
		else if (buftype == IDENTIFIER) mytype = "I������������ ����������� ��� �������������";
		else if (buftype == CONST_BIN) mytype = "��i����� ���������";
		else if (buftype == CONST_10) mytype = "��������� ���������";
		else if (buftype == CONST_16) mytype = "س����������� ���������";
		else if (buftype == ONESYMB) mytype = "�������������";
		else if (buftype == DEF_TYPE) mytype = "������������� ��������� ���������� ����";
		else if (buftype == ERR) mytype = "�������";
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
		if (bufstr[i] == '�') bufstr[i] = 'a';
		else if (bufstr[i] == '�') bufstr[i] = 'A';
		else if (bufstr[i] == '�') bufstr[i] = 'e';
		else if (bufstr[i] == '�') bufstr[i] = 'E';
		else if (bufstr[i] == '�') bufstr[i] = 'i';
		else if (bufstr[i] == '�') bufstr[i] = 'I';
		else if (bufstr[i] == '�') bufstr[i] = 'y';
		else if (bufstr[i] == '�') bufstr[i] = 'o';
		else if (bufstr[i] == '�') bufstr[i] = 'O';
		else if (bufstr[i] == '�') bufstr[i] = 'p';
		else if (bufstr[i] == '�') bufstr[i] = 'P';
		else if (bufstr[i] == '�') bufstr[i] = 'H';
		else if (bufstr[i] == '�') bufstr[i] = 'K';
		else if (bufstr[i] == '�') bufstr[i] = 'x';
		else if (bufstr[i] == '�') bufstr[i] = 'X';
		else if (bufstr[i] == '�') bufstr[i] = 'c';
		else if (bufstr[i] == '�') bufstr[i] = 'C';
		else if (bufstr[i] == '�') bufstr[i] = 'B';
		else if (bufstr[i] == '�') bufstr[i] = 'M';
		else if (bufstr[i] == '�') bufstr[i] = 'T';
	}
	return bufstr;
}