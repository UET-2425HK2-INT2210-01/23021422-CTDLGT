#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream inFile("numbers.txt");            // Mở file đầu vào
    ofstream outFile("numbers.sorted");        // Mở file đầu ra
    vector<double> numbers;
    double num;

    // Đọc tất cả số thực từ file
    while (inFile >> num) {
        numbers.push_back(num);
    }

    // Sắp xếp dãy số theo thứ tự tăng dần
    sort(numbers.begin(), numbers.end());

    // Ghi kết quả vào file, cách nhau bởi dấu cách
    for (size_t i = 0; i < numbers.size(); ++i) {
        outFile << numbers[i];
        if (i < numbers.size() - 1)
            outFile << " ";
    }

    return 0;
}
