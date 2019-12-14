#include <iostream>
#include <string.h>

using namespace std;

#define MAX 255

string *trim(string *str);

void lerRegritas(string linha) {
	string stateFrom	= linha.substr(0, linha.find("=")-1);
	string stateTo		= linha.substr(linha.find("=")+1, linha.size());

//	cout << stateFrom << endl;
//	cout << stateTo << endl;

	stateFrom = stateFrom.substr(stateFrom.find("(")+1, stateFrom.find(")")-1);
	stateTo = stateTo.substr(stateTo.find("(")+1, stateTo.find(")")-2);

	cout << stateFrom << endl;
	cout << stateTo << endl;

	string estadoAtual = stateFrom.substr(0, stateFrom.find(","));
	string simbFita = stateFrom.substr(0, stateFrom.find(","));
//	estadoAtual.copy(trim(estadoAtual), n, 0);

	cout << estadoAtual << endl;

}

// char *trim(string str) {
// 	char newStr[MAX];
// 	unsigned int ind;

// 	strcpy(newStr, str->c_str());

// 	for(ind = 0; isspace(newStr[ind++]);)
// 		;

// 	for(ind = str->size()-1; isspace(newStr[ind--]);)
// 		;

// 	str->copy(newStr, str->size(), 0);

// 	return str;
// }

int main(int argc, char const *argv[]) {
	lerRegritas("(q0    ,@,     @           ) = (q1,$)");


	return 0;
}