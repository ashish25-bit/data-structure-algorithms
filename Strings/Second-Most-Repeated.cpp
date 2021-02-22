/**
 * The idea here is to add all the words in a hashMap and count its frequency.
 * Simultaneously calculate the max frequency.
 * Iterate the hashMap and find the second largest frequecy and correspondingly storing the string asscociated to it.
 */

string secFrequent (string arr[], int n) {
    unordered_map<string, int> hashMap;
    int max_freq = -1;
    int sec_max = -1;
    string res = "";
    
    // storing frequency of each word
    // storing the max frequency
    for (int i=0; i < n; i++) {
        hashMap[arr[i]]++;
        max_freq = max(max_freq, hashMap[arr[i]]);
    }
    
    for (auto i = hashMap.begin(); i != hashMap.end(); i++) {
        if (i->second == max_freq)
            continue;
        if (i->second > sec_max) {
            res = i->first;
            sec_max = i->second;
        }
    }
    
    return res;
}