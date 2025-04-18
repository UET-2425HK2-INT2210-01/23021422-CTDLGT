#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ifstream in("matrix.txt");
    ofstream out("matrix.out");

    int m, n;
    in >> m >> n;  // Đọc kích thước ma trận
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i)     // Đọc dữ liệu ma trận
        for (int j = 0; j < n; ++j)
            in >> a[i][j];

    // Khởi tạo biến lưu kết quả tốt nhất
    int maxSum = INT_MIN, r1 = 0, c1 = 0, r2 = 0, c2 = 0;

    // Duyệt tất cả cặp dòng top - bottom
    for (int top = 0; top < m; ++top) {
        vector<int> temp(n, 0); // Tổng cột giữa top và bottom
        for (int bottom = top; bottom < m; ++bottom) {
            for (int col = 0; col < n; ++col)
                temp[col] += a[bottom][col];

            // Áp dụng Kadane’s algorithm trên mỗi dải cột
            int sum = 0, startCol = 0;
            for (int col = 0; col < n; ++col) {
                if (sum <= 0) {
                    sum = temp[col];
                    startCol = col;
                } else {
                    sum += temp[col];
                }
                if (sum > maxSum) {
                    maxSum = sum;
                    r1 = top + 1;           // +1 vì đánh số từ 1
                    c1 = startCol + 1;
                    r2 = bottom + 1;
                    c2 = col + 1;
                }
            }
        }
    }

    out << r1 << " " << c1 << " " << r2 << " " << c2 << " " << maxSum << endl;
    return 0;
}
