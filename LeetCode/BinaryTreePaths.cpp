#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root == NULL) return paths;
        vector<TreeNode*> onePath;
        Traverse(onePath, root, paths);
        return paths;
    }

    void Traverse(vector<TreeNode*> onePath, TreeNode *root, vector<string> &paths) {
        //if (root == NULL)
        //    return;
        onePath.push_back(root);
        if (root->left == NULL && root->right == NULL)
            paths.push_back(getPath(onePath));
        if (root->left != NULL)
            Traverse(onePath, root->left, paths);
        if (root->right != NULL)
            Traverse(onePath, root->right, paths);
    }

    string getPath(vector<TreeNode*> onePath) {
        string s;
        //if (onePath.empty())
        //    return s;
        
        for (int i = 0; i < onePath.size() - 1; i++) {
            stringstream ss;
            ss << onePath[i]->val;
            string tmp = ss.str();
            s += tmp;
            s += "->";
        }
        stringstream ss;
        ss << onePath[onePath.size() - 1]->val;
        s += ss.str();
        return s;
    }
};
