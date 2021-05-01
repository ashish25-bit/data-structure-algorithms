#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 10;

    int *A = (int*)malloc(n * sizeof(int));
    cout << "MALLOC:\n";
    for (int i=0; i<n; i++) {
        A[i] = i+1;
        cout << A[i] << " ";
    }

    int *B = (int *)calloc(n, sizeof(int));
    cout << "\nCALLOC:\n";
    for (int i=0; i<n; i++)
        cout << B[i] << " ";

    int *C = (int*)realloc(B, n*2*sizeof(int));
    cout << "\nREALLOC B:\n";
    for (int i=0; i<n*2; i++)
        cout << C[i] << " ";

    int *D = (int*)realloc(A, n*2*sizeof(int));
    cout << "\nREALLOC A:\n";
    for (int i=0; i<n*2; i++)
        cout << D[i] << " ";

    /**
     * int *A = (int*)realloc(A, 0) is same as free (A)
     * int *A = (int*)realloc(NULL, n*sizeof(int)) is same as (int*)malloc(n*sizeof(int))
     */

    return 0;
}
