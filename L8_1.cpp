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

    // 构造二叉树
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

    // 复制二叉树
    TreeNode* copyTree(TreeNode* original) {
        if (original == nullptr) {
            return nullptr;
        }

        TreeNode* newNode = new TreeNode(original->data);
        newNode->left = copyTree(original->left);
        newNode->right = copyTree(original->right);

        return newNode;
    }

    // 销毁二叉树
    void destroyTree(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        destroyTree(root->left);
        destroyTree(root->right);

        delete root;
    }

    // 先序遍历二叉树
    void preOrderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        std::cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    // 中序遍历二叉树
    void inOrderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
    }

    // 后序遍历二叉树
    void postOrderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout << root->data << " ";
    }

    // 求二叉树的深度
    int getTreeDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = getTreeDepth(root->left);
        int rightDepth = getTreeDepth(root->right);

        return std::max(leftDepth, rightDepth) + 1;
    }

    // 求二叉树的结点数
    int getNodeCount(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return getNodeCount(root->left) + getNodeCount(root->right) + 1;
    }

    // 求二叉树的叶子结点数
    int getLeafNodeCount(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        return getLeafNodeCount(root->left) + getLeafNodeCount(root->right);
    }

    // 交换二叉树的左右子树
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

    // 构造二叉树
    tree.root = tree.constructTree();

    // 复制二叉树
    TreeNode* copiedTree = tree.copyTree(tree.root);

    // 销毁二叉树
    tree.destroyTree(tree.root);

    // 遍历二叉树
    std::cout << "Pre-order traversal: ";
    tree.preOrderTraversal(copiedTree);
    std::cout << std::endl;

    std::cout << "In-order traversal: ";
    tree.inOrderTraversal(copiedTree);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    tree.postOrderTraversal(copiedTree);
    std::cout << std::endl;

    // 求二叉树的深度
    std::cout << "Tree depth: " << tree.getTreeDepth(copiedTree) << std::endl;

    // 求二叉树的结点数
    std::cout << "Node count: " << tree.getNodeCount(copiedTree) << std::endl;

    // 求二叉树的叶子结点数
    std::cout << "Leaf node count: " << tree.getLeafNodeCount(copiedTree) << std::endl;

    // 交换二叉树的左右子树
    tree.swapLeftRight(copiedTree);

    std::cout << "After swapping left and right subtrees, in-order traversal: ";
    tree.inOrderTraversal(copiedTree);
    std::cout << std::endl;

    // 销毁复制的二叉树
    tree.destroyTree(copiedTree);

    system("pause");
    return 0;
}
