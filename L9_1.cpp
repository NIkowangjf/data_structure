#include <iostream>

using namespace std;

// �����������ڵ�ṹ
struct ThreadedTreeNode {
    int data;
    ThreadedTreeNode* left;
    ThreadedTreeNode* right;
    bool isThreadLeft;  // ��ָ���Ƿ�������
    bool isThreadRight; // ��ָ���Ƿ�������

    ThreadedTreeNode(int val) : data(val), left(nullptr), right(nullptr), isThreadLeft(false), isThreadRight(false) {}
};

// ������������������
void createPreOrderThreadedTree(ThreadedTreeNode* &root, ThreadedTreeNode* &prev) {
    if (!root) return;

    createPreOrderThreadedTree(root->left, prev);

    // ����ǰ�ڵ�
    if (!root->left) {
        root->left = prev;
        root->isThreadLeft = true;
    }
    if (prev && !prev->right) {
        prev->right = root;
        prev->isThreadRight = true;
    }

    prev = root;

    createPreOrderThreadedTree(root->right, prev);
}

// ������������������
void createInOrderThreadedTree(ThreadedTreeNode* &root, ThreadedTreeNode* &prev) {
    if (!root) return;

    createInOrderThreadedTree(root->left, prev);

    // ����ǰ�ڵ�
    if (!root->left) {
        root->left = prev;
        root->isThreadLeft = true;
    }
    if (prev && !prev->right) {
        prev->right = root;
        prev->isThreadRight = true;
    }

    prev = root;

    createInOrderThreadedTree(root->right, prev);
}

// ������������������
void createPostOrderThreadedTree(ThreadedTreeNode* &root, ThreadedTreeNode* &prev) {
    if (!root) return;

    createPostOrderThreadedTree(root->left, prev);
    createPostOrderThreadedTree(root->right, prev);

    // ����ǰ�ڵ�
    if (!root->left) {
        root->left = prev;
        root->isThreadLeft = true;
    }
    if (prev && !prev->right) {
        prev->right = root;
        prev->isThreadRight = true;
    }

    prev = root;
}

// �����������������
void preOrderTraversal(ThreadedTreeNode* root) {
    while (root) {
        cout << root->data << " ";

        if (!root->isThreadLeft) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    cout << endl;
}

// �����������������
void inOrderTraversal(ThreadedTreeNode* root) {
    while (root) {
        while (root && !root->isThreadLeft) {
            root = root->left;
        }

        cout << root->data << " ";

        if (root->isThreadRight) {
            root = root->right;
        } else {
            root = root->right;
            while (root && !root->isThreadLeft) {
                root = root->left;
            }
        }
    }

    cout << endl;
}

// �����������������
void postOrderTraversal(ThreadedTreeNode* root) {
    ThreadedTreeNode* temp = root;

    while (root) {
        while (root && !root->isThreadLeft) {
            root = root->left;
        }

        cout << root->data << " ";

        if (root->isThreadRight) {
            root = root->right;
        } else {
            root = root->right;
            while (root && !root->isThreadLeft) {
                root = root->left;
            }
        }
    }

    cout << endl;
}

int main() {
    ThreadedTreeNode* root = new ThreadedTreeNode(1);
    root->left = new ThreadedTreeNode(2);
    root->right = new ThreadedTreeNode(3);
    root->left->left = new ThreadedTreeNode(4);
    root->left->right = new ThreadedTreeNode(5);
    root->right->left = new ThreadedTreeNode(6);
    root->right->right = new ThreadedTreeNode(7);

    ThreadedTreeNode* prev = nullptr;

    // ������������������
    createPreOrderThreadedTree(root, prev);

    // �����������������
    cout << "�����������������: ";
    preOrderTraversal(root);
    
    // ��������
    prev = nullptr;

    // ������������������
    createInOrderThreadedTree(root, prev);

    // �����������������
    cout << "�����������������: ";
    inOrderTraversal(root);

    // ��������
    prev = nullptr;

    // ������������������
    createPostOrderThreadedTree(root, prev);

    // �����������������
    cout << "�����������������: ";
    postOrderTraversal(root);

    return 0;
}
