/**
 * NOTE: IN THIS SOLUTION ORDER IN WHICH THE STRING HAS BEEN INPUTED WILL BE MAINTAINED.
 * INPUT:
 bbaaffCCd
 * OUTPUT:
 b: 2
 a: 2
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
    vector<int> order;

    for (int i=0; i<str.length(); i++) {
        char ch = tolower(str[i]);
        if (!hashMap[ch-97])
            order.push_back(ch-97);
        hashMap[ch-97]++;
    }

    for (int x: order) {
        if (hashMap[x] > 1) {
            char ch = x + 97;
            cout << ch << ": " << hashMap[x] << endl;
        }
    }
        return 0;
}