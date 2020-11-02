/**
 * NOTE: IN THIS SOLUTION ORDER IN WHICH THE STRING HAS BEEN INPUTED WILL NO BE MAINTAINED.
 * INPUT:
 bbaaccffd
 * OUTPUT:
 a: 2
 b: 2
 c: 2
 f: 2
 */

#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cout << "Input String: \n";
    cin >> str;

    vector<int> hashMap(26, 0);

    for (int i=0; i<str.length(); i++) {
        char ch = tolower(str[i]);
        hashMap[ch-97]++;
    }

    for (int i=0; i<hashMap.size(); i++) {
        if (hashMap[i] > 1) {
            char ch = i+97;
            cout << ch << ": " << hashMap[i] << endl;
        }
    }

    return 0;
}