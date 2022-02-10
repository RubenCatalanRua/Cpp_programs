#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main() {
    string key;
    cout << "Write the key:" << endl;
    cin >> key;
    cout << "Press 1 to decrypt a message, or 2 to encrypt it." << endl;
    int x;
    cin >> x;
    while (x != 1 and x != 2) {
        cout << "Press 1 to encrypt a message, or 2 to decrypt it." << endl;
        cin >> x;
    }
    if (x == 1) {
        cout << "Write the encrypted message. End the text with -1." << endl;
        vector<int> nums(0);
        cin >> x;
        while (x != -1)  {
            nums.push_back(x);
            cin >> x;
        }
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) cout << " ";
            else cout << key[nums[i] - 1];
        }
    }
    else {
        cout << "Write the message to encrypt. To finish, just press -enter-. Make sure any characters written appear in the key." << endl;
        string text;
        cin.ignore();
        getline(cin, text);
        int n = text.size();
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            if (text[i] == ' ') v[i] = 0;
            else {
                int j = 0;
                bool found = false;
                while (not found and j < 26) {
                    if (key[j] == text[i]) found = true;
                    else ++j;
                }
                v[i] = j + 1;
            }
        }
        for (int i = 0; i < n; ++i) cout << v[i] << " ";
    }
    cout << endl;
}