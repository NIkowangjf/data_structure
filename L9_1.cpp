#include <iostream>

using namespace std;

// 线索二叉树节点结构
struct ThreadedTreeNode {
    int data;
    ThreadedTreeNode* left;
    ThreadedTreeNode* right;
    bool isThreadLeft;  // 左指针是否是线索
    bool isThreadRight; // 右指针是否是线索

    ThreadedTreeNode(int val) : data(val), left(nullptr), right(nullptr), isThreadLeft(false), isThreadRight(false) {}
};

// 建立先序线索二叉树
void createPreOrderThreadedTree(ThreadedTreeNode* &root, ThreadedTreeNode* &prev) {
    if (!root) return;

    createPreOrderThreadedTree(root->left, prev);

    // 处理当前节点
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

// 建立中序线索二叉树
void createInOrderThreadedTree(ThreadedTreeNode* &root, ThreadedTreeNode* &prev) {
    if (!root) return;

    createInOrderThreadedTree(root->left, prev);

    // 处理当前节点
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

// 建立后序线索二叉树
void createPostOrderThreadedTree(ThreadedTreeNode* &root, ThreadedTreeNode* &prev) {
    if (!root) return;

    createPostOrderThreadedTree(root->left, prev);
    createPostOrderThreadedTree(root->right, prev);

    // 处理当前节点
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

// 先序遍历线索二叉树
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

// 中序遍历线索二叉树
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

// 后序遍历线索二叉树
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

    // 建立先序线索二叉树
    createPreOrderThreadedTree(root, prev);

    // 先序遍历线索二叉树
    cout << "先序遍历线索二叉树: ";
    preOrderTraversal(root);
    
    // 重置线索
    prev = nullptr;

    // 建立中序线索二叉树
    createInOrderThreadedTree(root, prev);

    // 中序遍历线索二叉树
    cout << "中序遍历线索二叉树: ";
    inOrderTraversal(root);

    // 重置线索
    prev = nullptr;

    // 建立后序线索二叉树
    createPostOrderThreadedTree(root, prev);

    // 后序遍历线索二叉树
    cout << "后序遍历线索二叉树: ";
    postOrderTraversal(root);

    return 0;
}
