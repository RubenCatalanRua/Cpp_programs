#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    while (cin >> a >> b >> c) {
        for (int i = 0; i < c; ++i) cout << " ";
        for (int i = 0; i < a + 1; ++i) cout << "_";
        cout << endl;
        for (int i = 0; i < c-1; ++i) {
            int x = a, z = c - 1 - i;
            for (int j = 0; j < z; ++j) cout << " ";
            cout << "/";
            for (int j = 0; j < x; ++j) cout << " ";
            cout << "/";
            int sp = c - z - 1;
            for (int j = 0; j < sp; ++j) cout << " ";
            cout << "|" << endl;
        }
        cout << "/";
        for (int i = 0; i < a; ++i) cout << "_";
        cout << "/";
        for (int i = 0; i < c - 1; ++i) cout << " ";
        cout << "|" << endl;
        for (int i = 0; i < b - c; ++i) {
            cout << "|";
            for (int j = 0; j < a; ++j) cout << " ";
            cout << "|";
            for (int j = 0; j < c - 1; ++j) cout << " ";
            cout << "|" << endl;
        }
        for (int i = 0; i < c - 1; ++i) {
            cout << "|";
            for (int j = 0; j < a; ++j) cout << " ";
            cout << "|";
            for (int j = 0; j < c - 1 - i; ++j) cout << " ";
            cout << "/" << endl;
        }
        cout << "|";
        for (int i = 0; i < a; ++i) cout << "_";
        cout << "|" << "/" << endl;
        cout << endl;
    }
}