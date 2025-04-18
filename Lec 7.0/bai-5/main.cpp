#include <iostream>
using namespace std;

// Hàm đệ quy đếm số chữ số
int countDigits(int n) {
    if (n < 10) return 1;           // Nếu chỉ còn 1 chữ số
    return 1 + countDigits(n / 10); // Chia n cho 10 và cộng 1
}

int main() {
    int n;
    cin >> n;
    cout << countDigits(n) << endl;
    return 0;
}
