#include <iostream>
#include <cstring> // dùng để memset
#define MAX 1000
using namespace std;

int main() {
    int n, S;
    cin >> n >> S; // Nhập số lượng vật phẩm và trọng lượng tối đa

    int w[n + 1], v[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i]; // Nhập trọng lượng và giá trị của từng vật
    }

    int dp[n + 1][S + 1];
    memset(dp, 0, sizeof(dp)); // Khởi tạo mảng dp về 0

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= S; j++) {
            dp[i][j] = dp[i - 1][j]; // Không chọn vật thứ i
            if (j >= w[i]) {
                // Có thể chọn vật i: chọn giá trị lớn hơn giữa chọn và không chọn
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[n][S] << endl; // In ra kết quả tối ưu
    return 0;
}
