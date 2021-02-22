/**
 * The idea here is to get all the unique numbers and freq of every unique number
 * iterater the set o9f unique numbers
 * for each number(n) in the set find the freq of n and n + 1 from the freq hashMap
 * the sum of frequency of n and n + 1 will be the length
 * compare it with the previous length 
 */

int pickingNumbers(vector<int> a) {
    set<int> unique;
    unordered_map<int, int> freq;
    int l = 0;
    
    for (int num: a) {
        freq[num]++;
        unique.insert(num);
    }
    
    for (auto it = unique.begin(); it != unique.end(); it++) {
        auto next = freq.find(*it + 1);
        if (next != freq.end()) {
            l = max(l, freq[*it] + freq[*it + 1]);
        }
        else {
            if (freq[*it] > 1) 
                l = max(l, freq[*it]);
        }
    }
    
    return l;
}