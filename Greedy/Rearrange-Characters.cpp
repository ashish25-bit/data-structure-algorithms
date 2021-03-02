#include <bits/stdc++.h>
using namespace std;
typedef pair<char, int> freq;

struct comparator {
    bool operator() (freq p1, freq p2) {
        return p2.second > p1.second;
    }
};

string rearrangeString(priority_queue<freq, vector<freq>, comparator> maxHeap) {
    freq prev = std::make_pair(' ', -1);
    string str = "";

    while (!maxHeap.empty()) {
        freq curr = maxHeap.top();
        maxHeap.pop();
        str = str + curr.first;

        if (prev.first != ' ')
            maxHeap.push(prev);

        curr.second = curr.second - 1;

        if (maxHeap.empty() && curr.second >= 1)
            maxHeap.push(curr);

        else {
            if (curr.second >= 1)
                prev = curr;
            else
                prev = std::make_pair(' ', -1);
        }
    }

    return str;
}

bool hasDuplicate(string s) {
    for (int i=0; i < s.length() - 1; i++) {
        if (s[i] == s[i+1])
            return false;
    }
    return true;
}

// axiqenxohssbtwwwwwwwwwwwwwww
// aabbbghdfdzziz

int main() {
	string str = "axiqenxohssbtwwwwwwwwwwwwwww";
    unordered_map<char, int> hashMap;
    priority_queue<freq, vector<freq>, comparator> maxHeap;

    for (int i=0; i < str.length(); i++) 
        hashMap[str[i]]++;

    for (auto it: hashMap) {
        freq p = std::make_pair(it.first, it.second);
        maxHeap.push(p);
    }

    string r = rearrangeString(maxHeap);
    cout << hasDuplicate(r) << endl;
    
	return 0;
}