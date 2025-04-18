#include <iostream>
#include <string>
using namespace std;

// Hàm sinh chuỗi nhị phân bằng đệ quy
void generateBinary(int n, string s = "") {
    if (s.length() == n) {
        cout << s << endl;
        return;
    }
    generateBinary(n, s + "0");
    generateBinary(n, s + "1");
}

int main() {
    int n;
    cin >> n;
    generateBinary(n);
    return 0;
}
