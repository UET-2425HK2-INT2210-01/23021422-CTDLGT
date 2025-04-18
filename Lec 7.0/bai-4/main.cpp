#include <iostream>
using namespace std;

// Hàm đệ quy tính x^n
int power(int x, int n) {
    if (n == 0) return 1;         // Cơ sở: x^0 = 1
    return x * power(x, n - 1);   // Gọi lại với n - 1
}

int main() {
    int x, n;
    cin >> x >> n;
    cout << power(x, n) << endl;
    return 0;
}
