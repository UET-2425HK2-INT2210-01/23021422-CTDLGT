#include <iostream>
using namespace std;

// Định nghĩa cấu trúc nút của cây
struct CayNode {
    int giaTri;             // Giá trị của nút
    CayNode* nutTrai;       // Con trái
    CayNode* nutPhai;       // Con phải

    CayNode(int val) {
        giaTri = val;
        nutTrai = nullptr;
        nutPhai = nullptr;
    }
};

// Lớp MinHeap để quản lý cây Heap
class MinHeap {
private:
    int duLieuHeap[100]; // Mảng lưu trữ heap
    int kichThuoc;       // Kích thước hiện tại của heap
    CayNode* gocCay;     // Gốc của cây nhị phân

    // Hàm điều chỉnh heap từ chỉ số i
    void dieuChinhHeap(int i) {
        int nhoNhat = i;
        int chiSoTrai = 2 * i + 1;
        int chiSoPhai = 2 * i + 2;

        if (chiSoTrai < kichThuoc && duLieuHeap[chiSoTrai] < duLieuHeap[nhoNhat])
            nhoNhat = chiSoTrai;

        if (chiSoPhai < kichThuoc && duLieuHeap[chiSoPhai] < duLieuHeap[nhoNhat])
            nhoNhat = chiSoPhai;

        if (nhoNhat != i) {
            swap(duLieuHeap[i], duLieuHeap[nhoNhat]);
            dieuChinhHeap(nhoNhat);
        }
    }

    // Hàm xây dựng cây nhị phân từ mảng heap
    CayNode* xayDungCay(int i) {
        if (i >= kichThuoc) return nullptr;
        CayNode* nodeMoi = new CayNode(duLieuHeap[i]);
        nodeMoi->nutTrai = xayDungCay(2 * i + 1);
        nodeMoi->nutPhai = xayDungCay(2 * i + 2);
        return nodeMoi;
    }

    // Duyệt cây theo Inorder
    void duyetInorder(CayNode* nut) {
        if (!nut) return;
        duyetInorder(nut->nutTrai);
        cout << nut->giaTri << " ";
        duyetInorder(nut->nutPhai);
    }

public:
    // Constructor
    MinHeap() {
        kichThuoc = 0;
        gocCay = nullptr;
    }

    // Hàm chèn giá trị vào heap
    void chen(int giaTriMoi) {
        duLieuHeap[kichThuoc] = giaTriMoi;
        int viTri = kichThuoc;
        kichThuoc++;

        while (viTri > 0 && duLieuHeap[(viTri - 1) / 2] > duLieuHeap[viTri]) {
            swap(duLieuHeap[viTri], duLieuHeap[(viTri - 1) / 2]);
            viTri = (viTri - 1) / 2;
        }
    }

    // Xây dựng heap từ mảng
    void xayDungHeap() {
        for (int i = kichThuoc / 2 - 1; i >= 0; i--) {
            dieuChinhHeap(i);
        }
        gocCay = xayDungCay(0);
    }

    // Inorder traversal
    void inOrder() {
        duyetInorder(gocCay);
        cout << endl;
    }

    // Xóa phần tử khỏi heap
    void xoaPhanTu(int giaTriCanXoa) {
        int viTriCanXoa = -1;

        for (int i = 0; i < kichThuoc; i++) {
            if (duLieuHeap[i] == giaTriCanXoa) {
                viTriCanXoa = i;
                break;
            }
        }

        if (viTriCanXoa == -1) {
            cout << "Không tìm thấy phần tử " << giaTriCanXoa << " để xóa." << endl;
            return;
        }

        duLieuHeap[viTriCanXoa] = duLieuHeap[kichThuoc - 1];
        kichThuoc--;

        dieuChinhHeap(viTriCanXoa);
        xayDungHeap();
    }
};

// Hàm chính
int main() {
    MinHeap heap; // Tạo đối tượng MinHeap
    int duLieuDauVao[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};

    // 1. Chèn các phần tử ban đầu
    for (int giaTri : duLieuDauVao) {
        heap.chen(giaTri);
    }

    heap.xayDungHeap();
    cout << "Cây Min Heap ban đầu: ";
    heap.inOrder();

    // 2. Thêm các phần tử mới
    heap.chen(14);
    heap.chen(0);
    heap.chen(35);

    heap.xayDungHeap();
    cout << "Cây Min Heap sau khi chèn 14, 0, 35: ";
    heap.inOrder();

    // 3. Xóa các phần tử
    heap.xoaPh
