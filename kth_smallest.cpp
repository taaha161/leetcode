class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;

        for (int i = 1; i < k; i++) {
            findAndDeleteSmallest(root);
        }

        // Find the leftmost node (smallest remaining)
        while (root->left) {
            root = root->left;
        }

        return root->val;
    }

    void findAndDeleteSmallest(TreeNode* &root) {
        if (!root) return;

        TreeNode* prev = nullptr;
        TreeNode* current = root;

        // Traverse to the leftmost node
        while (current->left) {
            prev = current;
            current = current->left;
        }

        // If current is root and has no left child
        if (!prev) {
            // If root has right child, make it new root
            if (current->right) {
                root = current->right;
            }
            // If no right child, set root to nullptr
            else {
                root = nullptr;
            }
        }
        // If current is a left child
        else {
            // If current has right child
            if (current->right) {
                prev->left = current->right;
            }
            // If no right child, simply remove the node
            else {
                prev->left = nullptr;
            }
        }
    }
};