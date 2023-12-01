#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// �������ڵ�ṹ
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ���������
TreeNode* constructBinaryTree() {
    // ������Ը��ݾ���������������������Ϊʾ��
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

// ����������������ǵݹ飩
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

// ����������������ǵݹ飩
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

// ����������������ǵݹ飩
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

// ��α���������
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

// ������������
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

// ���������Ҷ�ӽ����
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

// ��������������������
void swapLeftRight(TreeNode* root) {
    if (!root) return;

    swapLeftRight(root->left);
    swapLeftRight(root->right);

    // ������������
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main() {
    TreeNode* root = constructBinaryTree();

    cout << "�������: ";
    preOrderTraversal(root);

    cout << "�������: ";
    inOrderTraversal(root);

    cout << "�������: ";
    postOrderTraversal(root);

    cout << "��α���: ";
    levelOrderTraversal(root);

    cout << "���������: " << treeDepth(root) << endl;

    cout << "Ҷ�ӽ����: " << leafNodeCount(root) << endl;

    swapLeftRight(root);

    cout << "����������������������: ";
    preOrderTraversal(root);

    system("pause");

    return 0;
}
