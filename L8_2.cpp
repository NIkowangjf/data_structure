#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// 二叉树节点结构
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 构造二叉树
TreeNode* constructBinaryTree() {
    // 这里可以根据具体情况构造二叉树，以下为示例
    /*
        1
       / \
      2   3
     / \
    4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    return root;
}

// 先序遍历二叉树（非递归）
void preOrderTraversal(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current || !s.empty()) {
        while (current) {
            cout << current->data << " ";
            s.push(current);
            current = current->left;
        }

        if (!s.empty()) {
            current = s.top();
            s.pop();
            current = current->right;
        }
    }

    cout << endl;
}

// 中序遍历二叉树（非递归）
void inOrderTraversal(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current || !s.empty()) {
        while (current) {
            s.push(current);
            current = current->left;
        }

        if (!s.empty()) {
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }

    cout << endl;
}

// 后序遍历二叉树（非递归）
void postOrderTraversal(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        TreeNode* current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left) s1.push(current->left);
        if (current->right) s1.push(current->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }

    cout << endl;
}

// 层次遍历二叉树
void levelOrderTraversal(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }

    cout << endl;
}

// 求二叉树的深度
int treeDepth(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* current = q.front();
            q.pop();

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        depth++;
    }

    return depth;
}

// 求二叉树的叶子结点数
int leafNodeCount(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int count = 0;

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (!current->left && !current->right) {
            count++;
        } else {
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

    return count;
}

// 交换二叉树的左右子树
void swapLeftRight(TreeNode* root) {
    if (!root) return;

    swapLeftRight(root->left);
    swapLeftRight(root->right);

    // 交换左右子树
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main() {
    TreeNode* root = constructBinaryTree();

    cout << "先序遍历: ";
    preOrderTraversal(root);

    cout << "中序遍历: ";
    inOrderTraversal(root);

    cout << "后序遍历: ";
    postOrderTraversal(root);

    cout << "层次遍历: ";
    levelOrderTraversal(root);

    cout << "二叉树深度: " << treeDepth(root) << endl;

    cout << "叶子结点数: " << leafNodeCount(root) << endl;

    swapLeftRight(root);

    cout << "交换左右子树后的先序遍历: ";
    preOrderTraversal(root);

    system("pause");

    return 0;
}
