#include <iostream>
using namespace std;

long long power(int n) {
    if (n == 0) return 1;
    long long tmp = power(n / 2);
    if (n % 2 == 0) return tmp * tmp;
    return tmp * tmp * 2;
}

int main() {
    int n;
    cin >> n;
    cout << "2^" << n << " = " << power(n);
    return 0;
}


