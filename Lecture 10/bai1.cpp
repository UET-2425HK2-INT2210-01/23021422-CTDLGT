#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 1001

using namespace std;

// Lớp Solution dùng để giải bài toán tìm đường đi trong đồ thị có hướng
class Solution {
  private:
   int n, m, s, t;                // n: số lượng đỉnh, m: số lượng cạnh, s: đỉnh xuất phát, t: đỉnh đích
   vector<int> adj[MAX];          // adj[u]: chứa các đỉnh có đường đi trực tiếp từ u
   bool visited[MAX];             // visited[u]: đánh dấu u đã được duyệt hay chưa
   int parent[MAX];               // parent[v]: lưu đỉnh liền trước v trong đường đi

  public:
   // Hàm để đọc dữ liệu đầu vào của đồ thị
   void input() {
      cout << "Nhap so dinh : ";
      cin >> n;
      cout << "Nhap so canh : ";
      cin >> m;
      cout << "Nhap dau duong di : ";
      cin >> s;
      cout << "Nhap cuoi duong di : ";
      cin >> t;
      for (int i = 0; i < m; i++) {
         int x, y;
         cin >> x >> y;
         adj[x].push_back(y);  // Thêm cung có hướng từ x đến y
      }
   }

   // Thuật toán duyệt theo chiều sâu bắt đầu từ đỉnh u
   void dfs(int u) {
      visited[u] = true;           // Ghi nhận đỉnh u đã được ghé qua
      for (int v : adj[u]) {       // Xét từng đỉnh v kề với u
         if (!visited[v]) {        // Nếu v chưa được duyệt
            parent[v] = u;         // Cập nhật u là đỉnh đến trước v
            dfs(v);                // Tiếp tục duyệt sâu từ đỉnh v
         }
      }
   }

   // Thuật toán duyệt theo chiều rộng bắt đầu từ đỉnh u
   void bfs(int u) {
      queue<int> q;
      q.push(u);                   // Khởi tạo hàng đợi với u
      visited[u] = true;           // Đánh dấu u là đã ghé qua
      while (!q.empty()) {
         int v = q.front(); q.pop();
         for (int x : adj[v]) {    // Duyệt từng đỉnh x kề với v
            if (!visited[x]) {     // Nếu x chưa được xử lý
               q.push(x);          // Thêm x vào hàng đợi để xử lý tiếp
               visited[x] = true;  // Đánh dấu x đã được duyệt
               parent[x] = v;      // Lưu lại v là đỉnh trước x
            }
         }
      }
   }

   // Truy tìm và hiển thị đường đi từ s đến t, nếu tồn tại
   void path() {
      memset(visited, false, sizeof(visited)); // Reset trạng thái của tất cả các đỉnh
      memset(parent, 0, sizeof(parent));       // Xoá thông tin đường đi trước đó
      bfs(s);                                  // Bắt đầu tìm đường từ đỉnh s

      if (!visited[t]) {                       // Nếu không thể đi đến t
         cout << "Khong co duong di" << endl;
      } else {
         vector<int> Path;                     // Dùng để lưu các đỉnh tạo thành đường đi
         int cur = t;
         while (cur != s) {                    // Lần theo mảng parent để dựng lại đường đi
            Path.push_back(cur);
            cur = parent[cur];
         }
         Path.push_back(s);                    // Thêm đỉnh bắt đầu s vào
         reverse(Path.begin(), Path.end());    // Đảo thứ tự để ra đường đi từ s -> t
         int len = Path.size() - 1;            // Độ dài = số đỉnh - 1 (vì cạnh = đỉnh - 1)
         cout << "Độ dài đường đi là: " << len << endl;
         cout << "Duong di la: ";
         for (int x : Path) {
            cout << x << " ";
         }
      }
   }
};

int main() {
   Solution s;
   s.input();   // Đọc thông tin đồ thị từ người dùng
   s.path();    // Tìm và hiển thị đường đi từ s đến t
}
