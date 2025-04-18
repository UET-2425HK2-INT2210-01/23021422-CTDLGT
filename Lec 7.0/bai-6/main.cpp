#include <iostream>
using namespace std;

// Hàm đệ quy tính tổng các chữ số
int digitSum(int n) {
    if (n == 0) return 0;                   // Trường hợp cơ sở
    return (n % 10) + digitSum(n / 10);     // Lấy chữ số cuối + tổng phần còn lại
}

int main() {
    int n;
    cin >> n;
    cout << digitSum(n) << endl;
    return 0;
}
