#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;
int A[MAX];

// Hàm sắp xếp nhanh (Quick Sort)
void quick_sort(int start, int end) {
    if (start >= end) return; // Điều kiện dừng đệ quy: khi đoạn con không còn phần tử nào
    int pivot = A[start];     // Chọn phần tử đầu tiên làm chốt (pivot)
    int left = start, right = end;

    while (left <= right) {
        while (A[left] < pivot) left++; // Tìm phần tử lớn hơn hoặc bằng pivot bên trái
        while (A[right] > pivot) right--; // Tìm phần tử nhỏ hơn hoặc bằng pivot bên phải
        if (left <= right) {
            swap(A[left], A[right]); // Đổi chỗ nếu cần
            left++;
            right--;
        }
    }

    // Gọi đệ quy với hai phần của mảng
    quick_sort(start, right);
    quick_sort(left, end);
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i]; // Nhập mảng
    }
    quick_sort(0, N - 1); // Gọi hàm sắp xếp

    for (int i = 0; i < N; i++) {
        cout << A[i] << " "; // In ra mảng đã sắp xếp
    }
    return 0;
}
