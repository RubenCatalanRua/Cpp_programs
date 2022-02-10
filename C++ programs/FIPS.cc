#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Assignatura {
         string nom;                 // Nom de l’assignatura
         double nota;                // Entre 0 i 10, -1 indica NP
};

struct Alumne {
         string nom;                 // Nom de l’alumne
         int dni;                    // DNI de l’alumne
         vector<Assignatura> ass;    // Llista d’assignatures de l’alumne
};

double nota(const vector<Alumne>& alums, int dni, string nom) {
	int i = 0;
	int m = alums.size();
	bool trobat = false;
	while (i < m and not trobat) {
		if (dni == alums[i].dni) trobat = true;
		else ++i;
	}
	if (not trobat) return -1;
	else {
		m = alums[i].ass.size();
		for (int j = 0; j < m; ++j) {
			if (alums[i].ass[j].nom == nom) return alums[i].ass[j].nota;
		}
	}
	return -1;
}

double mitjana(const vector<Assignatura>& ass) {
 	int n = ass.size();
 	double mitj = 0;
 	if (n == 0) return -1;
 	else {
 		bool NP = true;
 		int counter = 0;
 		for (int i = 0; i < n; ++i) {
 			if (ass[i].nota != -1) {			// Suma el valor de la nota si cursó la asignatura
 				mitj += ass[i].nota;
 				NP = false;
 				++counter;
 			}
 		}
 		if (NP) return -1;
 		else return mitj/counter;
 	}
}

void compta(const vector<Alumne>& alums, int dni, string nom, int& com) {
	com = 0;
	double val = nota(alums,dni,nom);
	for (int i = 0; i < alums.size(); ++i) {
		Alumne s = alums[i];
		if (mitjana(s.ass) > val) ++com;
	}
}

int main() {
	int num;
	cin >> num;
	vector <Alumne> alums(num);
	for (int i = 0; i < num; ++i) {
	
		cin >> alums[i].nom >> alums[i].dni;
		int ass_num;
		cin >> ass_num;
		vector <Assignatura> ass(ass_num);
		for (int j = 0; j < ass.size(); ++j) { 
			cin >> ass[j].nom >> ass[j].nota;
		}
		alums[i].ass = ass;
	}

	int dni;
	while (cin >> dni) {
		string nom;
		cin >> nom;
		int com;
		compta(alums,dni,nom,com);
		cout << com << endl;
	}
}
