#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* str2tree(string s) {
    if (s.empty())
        return nullptr;

    stack<TreeNode*> stk;
    int i = 0;

    while (i < s.length()) {
        if (isdigit(s[i]) || s[i] == '-') {
            // Read the number from the string
            int start = i;
            while (i < s.length() && (isdigit(s[i]) || s[i] == '-'))
                i++;
            int num = stoi(s.substr(start, i - start));

            // Create a new node with the number
            TreeNode* node = new TreeNode(num);

            if (!stk.empty()) {
                // Attach the new node as the left or right child of the top node in the stack
                TreeNode* parent = stk.top();
                if (parent->left == nullptr)
                    parent->left = node;
                else
                    parent->right = node;
            }

            stk.push(node);
        } else if (s[i] == '(') {
            // Skip the opening parenthesis
            i++;
        } else if (s[i] == ')') {
            // Close the current subtree and remove its root from the stack
            stk.pop();
            i++;
        }
    }

    if (stk.empty())
        return nullptr;

    return stk.top();
}

// In-order traversal of the binary tree
void inorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr)
        return;

    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

int main() {
    string s ;

    cin>>s;
    TreeNode* root = str2tree(s);

    vector<int> result;
    inorder(root, result);

    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

