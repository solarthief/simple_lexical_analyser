#include "LexicalAnalys.h"
#include "Support_functions.h"

void main()
{
	setlocale(LC_ALL, "Ukrainian");
	fstream FILE(filename(), ios::in);
	if (!FILE)
	{
		cout << "Неможливо вiдкрити файл" << endl;
		cout << "Натиснiть будь-яку клавiшу для виходу"<<endl;
		_getch();
		exit(0);
	};
	create_sub_files();
	string bufstr;
	int number_of_strings = 0;
	while (getline(FILE, bufstr))
		number_of_strings++;
	FILE.clear();
	FILE.seekg(0, ios_base::beg);
	int i_str = 0;
	while (getline(FILE, bufstr)) 
	{		
			lexem* head = lexical_analys(string_correction(bufstr));
			print_list(head, i_str);
			i_str++;
	}		
return;
}
