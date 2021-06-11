#include <bits/stdc++.h>
using namespace std;

bool prime[101];

void primeNumbers() {
  memset(prime, true, sizeof(prime));

  for (int p = 2; p * p <= 100; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= 100; i += p)
        prime[i] = false;
    }
  }
}

int main() {
  primeNumbers();

  for (int p = 2; p <= 100; p++)
    if (prime[p])
      cout << p << " ";
  
  return 0;
}
