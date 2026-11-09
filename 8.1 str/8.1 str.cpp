//ЛР 8.1 str

// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// 1. Вияснити, чи є серед цих символів трійка сусідніх букв "OGO" або "AGA".
// 2. Замінити кожну трійку сусідніх букв "OGO" або "AGA" парою зірочок "**".

#include <iostream>
#include <string> // дає тип string і його методи (find, replace)
using namespace std;

bool Exist(const string s)
{
	if (s.find("OGO") != -1 || s.find("AGA") != -1) // s.find("OGO") повертає позицію, де знайшла “OGO”, а якщо не знайшла, то -1
		return true;
	return false;
}

string Change(string& s) // знак & означає, що ми передаємо сам рядок, а не його копію і всі зміни всередині функції змінюють рядок str у main
{
	size_t pos = 0; //size_t це тип для позицій і довжин, починаємо з 0
	while ((pos = s.find_first_of("OA", pos)) != -1) // шукає в s, починаючи з позиції pos, першу букву з набору “OA”, тобто O або A і повертає її позицію
		if (s[pos + 1] == 'G' && s[pos + 2] == s[pos]) // рухаючись по масиву, наступний символ має бути G, а символ через один має бути таким самим, як перший
			s.replace(pos, 3, "**"); //replace замінює 3 символи, починаючи з позиції pos, на "**"
		else
			pos++; // посуваємо пошук на 1 символ далі якщо ця буква O чи A не початок трійки
	return s; // повертаємо змінений рядок
}

int main()
{
	string str; // сюди записується те, що вводиться
	cout << "Enter string:" << endl;
	getline(cin, str); // getline потрібна для того, щоб зчитати з клавіатури весь рядок тексту повністю, враховуючи пробіли
	if (Exist(str)) //перевірка чи OGO та AGA існують
		cout << "String contains OGO or AGA" << endl;
	else
		cout << "String does not contain OGO or AGA" << endl;
	string result = Change(str); //виклик Change. Вона замінює трійки на ** у самому str
	cout << "Modified string (param) : " << str << endl; //виводимо результату, який змінився всередині функції, бо ми передали його за посиланням
	cout << "Modified string (result): " << result << endl; //виводимо нову змінну, в яку записалося те значення, яке функція повернула через return s
	return 0;
}