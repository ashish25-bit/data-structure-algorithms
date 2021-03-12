
/**
 * TIME COMPLEXITY FOR THIS : O(N)
 */

/**
 * Maintain a hash map of the frequencies of the elements
 * Initialize a variable l = 0
 * Iterate the hash map
 * For every key check whether the previous and next number is present or not
 * If present then compare l and current key frequency + next/previous key frequency for max val
 * If not present then check whether the current key freq is greater than l only if freq > 1.
 */

int pickingNumbers(vector<int> a) {
    unordered_map<int, int> freq;
    int l = 0;
    
    for (int num: a) freq[num]++;
    
    for (auto it: freq) {
        int next = it.first + 1;
        int prev = it.first - 1;
        
        if (freq.find(next) != freq.end())
            l = max(l, it.second + freq[next]);
        else {
            if (it.second > 1)
                l = max(l, it.second);
        }
        
        if (freq.find(prev) != freq.end())
            l = max(l, it.second + freq[prev]);
        else {
            if (it.second > 1)
                l = max(l, it.second);
        }     
    }
    return l;
}

// ---------------------------------------------------------------------------------------------

/**
 * TIME COMPLEXITY FOR THIS : O(NlogN)
 */

/**
 * The idea here is to get all the unique numbers and freq of every unique number
 * iterater the set of unique numbers (log N)
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