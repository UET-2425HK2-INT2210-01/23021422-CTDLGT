#include <iostream>
using namespace std;

// Hàm phụ để hỗ trợ đảo ngược
int reverseNumber(int n, int rev = 0) {
    if (n == 0) return rev;                          // Khi đã chia hết
    return reverseNumber(n / 10, rev * 10 + n % 10); // Dồn chữ số vào rev
}

int main() {
    int n;
    cin >> n;
    cout << reverseNumber(n) << endl;
    return 0;
}
