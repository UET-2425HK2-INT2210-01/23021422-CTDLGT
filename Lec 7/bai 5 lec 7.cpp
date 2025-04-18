#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    // Tạo dãy từ 1 đến n
    for (int i = 0; i < n; ++i)
        a[i] = i + 1;

    // Dùng next_permutation để sinh hoán vị
    do {
        for (int x : a)
            cout << x;
        cout << endl;
    } while (next_permutation(a.begin(), a.end()));

    return 0;
}
