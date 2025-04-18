#include <iostream>
using namespace std;

// Hàm đệ quy tính giai thừa
int factorial(int n) {
    if (n == 0 || n == 1) return 1;   // Trường hợp cơ sở
    return n * factorial(n - 1);     // Gọi lại với n - 1
}

int main() {
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}
