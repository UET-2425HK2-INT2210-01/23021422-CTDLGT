// Chương trình xác định số lượng thành phần liên thông trong đồ thị vô hướng bằng thuật toán DFS
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj; // Danh sách các đỉnh kề (adjacency list)
vector<bool> visited;    // Mảng kiểm tra trạng thái đã thăm của từng đỉnh

// Hàm duyệt DFS bắt đầu từ một đỉnh cụ thể
void dfs(int node) {
  visited[node] = true; // Đánh dấu đỉnh hiện tại đã được thăm
  for (size_t i = 0; i < adj[node].size(); i++) { // Duyệt qua từng đỉnh kề với đỉnh hiện tại
    int neighbor = adj[node][i];
    if (!visited[neighbor]) {
      dfs(neighbor); // Nếu đỉnh kề chưa được thăm, tiếp tục duyệt đệ quy
    }
  }
}

// Hàm trả về số lượng thành phần liên thông trong đồ thị
int countConnectedComponents(int n) {
  int count = 0; // Biến đếm số thành phần liên thông được tìm thấy
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      count++;    // Mỗi lần bắt đầu DFS từ một đỉnh chưa thăm là gặp một thành phần mới
      dfs(i);     // Duyệt toàn bộ thành phần liên thông bắt đầu từ đỉnh đó
    }
  }
  return count;
}

int main() {
  int n, m; // n: số lượng đỉnh, m: số lượng cạnh
  cin >> n >> m;

  // Ví dụ minh họa:
  // Input:
  // 5 3
  // 1 2
  // 2 3
  // 4 5
  // → Đồ thị có 2 nhóm đỉnh riêng biệt: {1,2,3} và {4,5}
  // → Output là: 2

  adj.resize(n + 1);              // Khởi tạo danh sách kề cho n đỉnh (đánh số từ 1)
  visited.assign(n + 1, false);   // Gán trạng thái ban đầu là chưa thăm cho toàn bộ đỉnh

  // Đọc danh sách các cạnh
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y); // Thêm cạnh từ x đến y
    adj[y].push_back(x); // Vì là đồ thị vô hướng, thêm chiều ngược lại y đến x
  }

  cout << countConnectedComponents(n) << endl; // Xuất kết quả: số thành phần liên thông

  return 0;
}
