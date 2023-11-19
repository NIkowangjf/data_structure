#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    // ���������
    TreeNode* constructTree() {
        int val;
        std::cout << "Enter the root value (or -1 to end): ";
        std::cin >> val;

        if (val == -1) {
            return nullptr;
        }

        TreeNode* newNode = new TreeNode(val);

        std::cout << "Enter left child of " << val << ":\n";
        newNode->left = constructTree();

        std::cout << "Enter right child of " << val << ":\n";
        newNode->right = constructTree();

        return newNode;
    }

    // ���ƶ�����
    TreeNode* copyTree(TreeNode* original) {
        if (original == nullptr) {
            return nullptr;
        }

        TreeNode* newNode = new TreeNode(original->data);
        newNode->left = copyTree(original->left);
        newNode->right = copyTree(original->right);

        return newNode;
    }

    // ���ٶ�����
    void destroyTree(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        destroyTree(root->left);
        destroyTree(root->right);

        delete root;
    }

    // �������������
    void preOrderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        std::cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    // �������������
    void inOrderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
    }

    // �������������
    void postOrderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout << root->data << " ";
    }

    // ������������
    int getTreeDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = getTreeDepth(root->left);
        int rightDepth = getTreeDepth(root->right);

        return std::max(leftDepth, rightDepth) + 1;
    }

    // ��������Ľ����
    int getNodeCount(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return getNodeCount(root->left) + getNodeCount(root->right) + 1;
    }

    // ���������Ҷ�ӽ����
    int getLeafNodeCount(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        return getLeafNodeCount(root->left) + getLeafNodeCount(root->right);
    }

    // ��������������������
    void swapLeftRight(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        std::swap(root->left, root->right);
        swapLeftRight(root->left);
        swapLeftRight(root->right);
    }

    TreeNode* root;
};

int main() {
    BinaryTree tree;

    // ���������
    tree.root = tree.constructTree();

    // ���ƶ�����
    TreeNode* copiedTree = tree.copyTree(tree.root);

    // ���ٶ�����
    tree.destroyTree(tree.root);

    // ����������
    std::cout << "Pre-order traversal: ";
    tree.preOrderTraversal(copiedTree);
    std::cout << std::endl;

    std::cout << "In-order traversal: ";
    tree.inOrderTraversal(copiedTree);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    tree.postOrderTraversal(copiedTree);
    std::cout << std::endl;

    // ������������
    std::cout << "Tree depth: " << tree.getTreeDepth(copiedTree) << std::endl;

    // ��������Ľ����
    std::cout << "Node count: " << tree.getNodeCount(copiedTree) << std::endl;

    // ���������Ҷ�ӽ����
    std::cout << "Leaf node count: " << tree.getLeafNodeCount(copiedTree) << std::endl;

    // ��������������������
    tree.swapLeftRight(copiedTree);

    std::cout << "After swapping left and right subtrees, in-order traversal: ";
    tree.inOrderTraversal(copiedTree);
    std::cout << std::endl;

    // ���ٸ��ƵĶ�����
    tree.destroyTree(copiedTree);

    system("pause");
    return 0;
}
