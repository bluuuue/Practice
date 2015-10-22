#ifndef BST_HEAD
#define BST_HEAD

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class BST {
public:
    BST();
    ~BST();
    TreeNode* MakeEmpty(); 
    TreeNode* FindValue(int value);
    TreeNode* FindMaxValue();
    TreeNode* FindMinValue();
    void DeleteNode(int value);
    void InsertValue(int value);
    void InorderPrint();
    void PreorderPrint();

private:
    TreeNode *root;
    TreeNode *MakeEmptyTree(TreeNode *root);
    TreeNode* Find(TreeNode *root, int value);
    TreeNode* FindMax(TreeNode *root);
    TreeNode* FindMin(TreeNode *root);
    TreeNode* Insert(TreeNode *root, int value);
    TreeNode* Delete(TreeNode *root, int value);
    void InorderPrintTree(TreeNode *root);
    void PreorderPrintTree(TreeNode *root);
};




#endif
