#include <bits/stdc++.h>
using namespace std;

int main() {
    int B[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "B or &B[0]: " << B << endl;
    cout << "B+1 or &B[1]: " << B + 1 << endl;
    cout << "*B or B[0] or &B[0][0]: " << B << endl;
    cout << "*(B+1) or B[1] or &B[1][0]: " << B + 1 << endl;
    cout << "B[0][0]: " << **B << endl;
    cout << "B[1][2]: " << *(*(B + 1) + 2) << endl;

    /**
     * B[i][j] = *(B[i] + j) = *(*(B + i) + j)
     */

    return 0;
}