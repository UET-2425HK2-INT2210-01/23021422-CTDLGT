#include <iostream>
using namespace std;

// Định nghĩa một node trong cây nhị phân tìm kiếm
struct TreeNode {
    int value;            // Dữ liệu của node
    TreeNode* leftChild;  // Con trỏ trỏ đến node con bên trái
    TreeNode* rightChild; // Con trỏ trỏ đến node con bên phải

    // Constructor khởi tạo node với giá trị
    TreeNode(int val) {
        value = val;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

// Lớp quản lý cây nhị phân tìm kiếm
class BinarySearchTree {
public:
    TreeNode* rootNode; // Con trỏ trỏ đến gốc cây

    // Constructor khởi tạo cây rỗng
    BinarySearchTree() {
        rootNode = nullptr;
    }

    // Hàm chèn giá trị vào cây
    void insert(int newValue) {
        rootNode = insertRecursively(rootNode, newValue);
    }

    // Hàm duyệt cây trung tố (inorder)
    void inOrderTraversal() {
        inOrderRecursively(rootNode);
        cout << endl;
    }

    // Hàm xóa node khỏi cây
    void remove(int valueToDelete) {
        rootNode = deleteRecursively(rootNode, valueToDelete);
    }

private:
    // Hàm đệ quy chèn giá trị vào cây
    TreeNode* insertRecursively(TreeNode* currentNode, int newValue) {
        if (currentNode == nullptr) {
            return new TreeNode(newValue);
        }

        if (newValue < currentNode->value) {
            currentNode->leftChild = insertRecursively(currentNode->leftChild, newValue);
        } else {
            currentNode->rightChild = insertRecursively(currentNode->rightChild, newValue);
        }

        return currentNode;
    }

    // Hàm đệ quy duyệt cây trung tố
    void inOrderRecursively(TreeNode* currentNode) {
        if (currentNode == nullptr) {
            return;
        }

        inOrderRecursively(currentNode->leftChild);
        cout << currentNode->value << " ";
        inOrderRecursively(currentNode->rightChild);
    }

    // Hàm đệ quy xóa node khỏi cây
    TreeNode* deleteRecursively(TreeNode* currentNode, int valueToDelete) {
        if (currentNode == nullptr) {
            return currentNode;
        }

        if (valueToDelete < currentNode->value) {
            currentNode->leftChild = deleteRecursively(currentNode->leftChild, valueToDelete);
        } else if (valueToDelete > currentNode->value) {
            currentNode->rightChild = deleteRecursively(currentNode->rightChild, valueToDelete);
        } else {
            // Trường hợp không có con
            if (currentNode->leftChild == nullptr && currentNode->rightChild == nullptr) {
                delete currentNode;
                currentNode = nullptr;
            }
            // Chỉ có con phải
            else if (currentNode->leftChild == nullptr) {
                TreeNode* temp = currentNode;
                currentNode = currentNode->rightChild;
                delete temp;
            }
            // Chỉ có con trái
            else if (currentNode->rightChild == nullptr) {
                TreeNode* temp = currentNode;
                currentNode = currentNode->leftChild;
                delete temp;
            }
            // Có cả hai con
            else {
                TreeNode* minNode = findMinNode(currentNode->rightChild);
                currentNode->value = minNode->value;
                currentNode->rightChild = deleteRecursively(currentNode->rightChild, minNode->value);
            }
        }

        return currentNode;
    }

    // Hàm tìm node có giá trị nhỏ nhất
    TreeNode* findMinNode(TreeNode* currentNode) {
        while (currentNode && currentNode->leftChild != nullptr) {
            currentNode = currentNode->leftChild;
        }
        return currentNode;
    }
};

// Hàm main để chạy chương trình
int main() {
    BinarySearchTree bst;

    int initialValues[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    int initialSize = sizeof(initialValues) / sizeof(initialValues[0]);

    for (int i = 0; i < initialSize; i++) {
        bst.insert(initialValues[i]);
    }

    cout << "Cây sau khi chèn danh sách ban đầu: ";
    bst.inOrderTraversal();

    int additionalValues[] = {14, 0, 35};
    int addSize = sizeof(additionalValues) / sizeof(additionalValues[0]);

    for (int i = 0; i < addSize; i++) {
        bst.insert(additionalValues[i]);
    }

    cout << "Cây sau khi chèn thêm các node mới: ";
    bst.inOrderTraversal();

    bst.remove(6);
    bst.remove(13);
    bst.remove(35);

    cout << "Cây sau khi xóa các node: ";
    bst.inOrderTraversal();

    return 0;
}
