#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversalHelper(TreeNode* root, vector<int>& ret) {
    if (root != nullptr) {
        ret.push_back(root->val);
        preorderTraversalHelper(root->left, ret);
        preorderTraversalHelper(root->right, ret);
    }

    return ret;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ret;

    return preorderTraversalHelper(root, ret);
}

int main() {
    TreeNode n3(3, nullptr, nullptr);
    TreeNode n2(2, &n3, nullptr);
    TreeNode n1(1, nullptr, &n2);

    vector<int> vi = preorderTraversal(&n1);

    for (auto& c : vi) {
        cout << c << " ";
    }

    return 0;
}