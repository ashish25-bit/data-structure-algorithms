// takes 2 strings which are actually numbers add them and returns the string 
string findSum(string str1, string str2) {
    int n1 = str1.length();
    int n2 = str2.length();
    
    if (n1 > n2) {
        swap(str1, str2);
        int t = n1;
        n1 = n2;
        n2 = t;
    }
        
    string str = "";
    
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    
    int carry = 0;
    
    for (int i=0; i<n1; i++) {
        int sum = ( (str1[i] - '0' ) + (str2[i] - '0' ) + carry); 
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    
    for (int i = n1; i < n2; i++) {
            int sum = ( (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    
    if (carry)
        str.push_back(carry+'0');
        
    reverse(str.begin(), str.end());
    
    str.erase(0, str.find_first_not_of('0'));
    return str;
}

/**
 * The idea here is sort the array.
 * Iterate the array and alternaltely add the number to a form the numbers
 * FOR EXAMPLE:
 * 6 8 4 2 5 3
 * First Sort the array: 2 3 4 5 6 8
 * 1st number: 246
 * 2nd number: 358
 */

string solve(int arr[], int n) {
    // sorting the array
    sort(arr, arr + n);
    string num1 = "";
    string num2 = "";
    
    for (int i=0; i<n; i++) {
        
        // if the index is odd add to the second number
        if (i%2)
            num2 = num2 + to_string(arr[i]);
        
        // add to the first number
        else 
            num1 = num1 + to_string(arr[i]);
    }
    
    return findSum(num1, num2);
}