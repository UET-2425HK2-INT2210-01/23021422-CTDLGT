#include <iostream>
#define MAX 10000
using namespace std;
int A[MAX];

void quick_sort(int start, int end) {
    if (start >= end) return;
    int pivot = A[start];
    int left = start, right = end;

    while (left <= right) {
        while (A[left] < pivot) left++;
        while (A[right] > pivot) right--;
        if (left <= right) {
            swap(A[left], A[right]);
            left++;
            right--;
        }
    }
    quick_sort(start, right);
    quick_sort(left, end);
}

int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    quick_sort(0, N - 1); // Sắp xếp mảng trước

    // Duyệt qua tất cả các dãy con liên tiếp và kiểm tra tổng
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for(int j = i; j < N; j++) {
            sum += A[j];
            if(sum == K) {
                cout << "YES" << endl; // Tìm thấy dãy con có tổng bằng K
                return 0;
            }
        }
    }
    cout << "NO" << endl; // Không tìm thấy dãy phù hợp
    return 0;
}
