#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
int n, m, s, e;

// Cấu trúc dữ liệu biểu diễn một cạnh có hướng và trọng số
struct Edge {
    int u, v, w;
};

vector<Edge> edges;
vector<int> dist;
vector<int> parent;

// Hàm Bellman-Ford tìm đường đi ngắn nhất từ đỉnh s đến tất cả các đỉnh khác
bool bellman_ford(int s) {
    dist.assign(n + 1, INF);         // Khởi tạo khoảng cách ban đầu là vô hạn
    parent.assign(n + 1, -1);        // Mỗi đỉnh chưa có cha trên đường đi
    dist[s] = 0;                     // Khoảng cách từ s đến chính nó là 0

    // Thực hiện n-1 lượt cập nhật để đảm bảo độ chính xác
    for (int i = 1; i <= n - 1; i++) {
        for (auto edge : edges) {
            // Nếu tìm được đường đi ngắn hơn tới v thông qua u
            if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;  // Cập nhật khoảng cách
                parent[edge.v] = edge.u;               // Lưu vết đường đi
            }
        }
    }

    // Kiểm tra xem có tồn tại chu trình âm hay không
    for (auto edge : edges) {
        if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
            return false; // Phát hiện chu trình âm
        }
    }

    return dist[e] != INF; // Trả về true nếu có đường đi tới e
}

// Truy vết đường đi từ s đến e sau khi chạy Bellman-Ford
vector<int> get_path(int e) {
    vector<int> path;
    while (e != -1) {
        path.push_back(e);
        e = parent[e];
    }
    reverse(path.begin(), path.end());
    return path;
}

// Thuật toán Floyd-Warshall: tìm khoảng cách ngắn nhất giữa mọi cặp đỉnh
vector<vector<int>> floyd_warshall() {
    vector<vector<int>> dist_fw(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; ++i)
        dist_fw[i][i] = 0; // Khoảng cách từ một đỉnh tới chính nó là 0

    for (auto edge : edges)
        dist_fw[edge.u][edge.v] = min(dist_fw[edge.u][edge.v], edge.w);

    // Cập nhật khoảng cách bằng cách xét đỉnh trung gian k
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist_fw[i][k] < INF && dist_fw[k][j] < INF) {
                    dist_fw[i][j] = min(dist_fw[i][j], dist_fw[i][k] + dist_fw[k][j]);
                }
            }
        }
    }

    return dist_fw;
}

int main() {
    ifstream fin("dirty.txt");
    ofstream fout("dirty.out");

    fin >> n >> m >> s >> e;

    // Đọc danh sách các cạnh từ file input
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        fin >> u >> v >> d;
        edges.push_back({u, v, d});
    }

    // Phần a: Tìm đường đi ngắn nhất từ s đến e bằng Bellman-Ford
    if (bellman_ford(s)) {
        fout << dist[e] << "\n";  // In ra độ dài đường đi ngắn nhất
        vector<int> path = get_path(e);
        for (int city : path)
            fout << city << " ";  // In ra các đỉnh trên đường đi
        fout << "\n";
    } else {
        fout << "INF\n";         // Không tồn tại đường đi
        fout << "NO PATH\n";
    }

    // Phần b: In ra ma trận khoảng cách ngắn nhất giữa mọi cặp đỉnh
    vector<vector<int>> fw = floyd_warshall();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (fw[i][j] == INF)
                fout << "INF ";
            else
                fout << fw[i][j] << " ";
        }
        fout << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
