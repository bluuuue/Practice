#include <iostream>
using namespace std;

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

BST::BST() {
    root = NULL; 
}
BST::~BST() {
    MakeEmpty();
}

TreeNode* BST::MakeEmpty() {
    return MakeEmptyTree(root);
}

TreeNode* BST::MakeEmptyTree(TreeNode *root) {
    if (root != NULL) {
        MakeEmptyTree(root->left);
        MakeEmptyTree(root->right);
        delete root;
    }
    return NULL;
}

TreeNode* BST::FindValue(int value) {
    TreeNode *T = Find(root, value);
    if (T != NULL)
        cout << "Has found the value: " << T->val << endl;
    else
        cout << value << " is not found." << endl;
    return T;
}

TreeNode* BST::Find(TreeNode *root, int value) {
    //返回查找值的位置，若找不到返回NULL
    if (root == NULL || root->val == value)
        return root;
    if (root->val > value)
        return Find(root->left, value);
    else 
        return Find(root->right, value);
}

TreeNode* BST::FindMaxValue() {
    TreeNode *T = FindMax(root);
    if (T != NULL)
        cout << "Max value is: " << T->val << endl;
    else
        cout << "The tree is null." << endl;
    return T;
}

TreeNode* BST::FindMax(TreeNode *root) {
    if (root == NULL) 
        return root;
    if (root->right != NULL)
        return FindMax(root->right);
    else
        return root;
}

TreeNode* BST::FindMinValue() {
    TreeNode *T = FindMin(root);
    if (T != NULL)
        cout << "Min value is: " << T->val << endl;
    else
        cout << "The tree is null." << endl;
    return T;
}

TreeNode* BST::FindMin(TreeNode *root) {
    if (root != NULL)
        while (root->left != NULL)
            root = root->left;
    return root;
}

void BST::InsertValue(int value) {
    root = Insert(root, value);
}

TreeNode* BST::Insert(TreeNode *root, int value) {
    if (root != NULL) {
        if (value < root->val)
            root->left = Insert(root->left, value);
        else if (value > root->val)
            root->right = Insert(root->right, value);
        /*若root->val与value相待，则不做操作*/
    }
    else {
        root = new TreeNode();
        root->val = value;
        root->left = NULL;
        root->right = NULL;
    }
    return root;
}

void BST::DeleteNode(int value) {
    root = Delete(root, value);
}

TreeNode* BST::Delete(TreeNode *root, int value) {
    //将右子树中最小结点移到要删除的结点处
    if (root == NULL) {
        cout << "The tree is empty." << endl;
        return NULL;
    }
    TreeNode *T = Find(root, value);
    if (T == NULL) {
        cout << "The tree does not have the element." << endl;
        return NULL;
    }
    if (T->left != NULL && T->right != NULL) {
        TreeNode *RightMin = FindMin(T->right);
        T->val = RightMin->val;
        T->right = Delete(T->right, T->val);
    }
    else {
        //cout << "T1: " << T->val << endl;
        //T = T->right;
        //cout << "T2: " << T->val << endl;
        T->val = T->right->val;
        T->left = T->right->left;
        T->right = T->right->right;
    }

    return root;
}

void BST::PreorderPrint() {
    cout << "Preorder: ";
    PreorderPrintTree(root);
    cout << endl;
}

void BST::PreorderPrintTree(TreeNode *root) {
    if (root == NULL)
        return;
    cout << root->val << " ";
    PreorderPrintTree(root->left);
    PreorderPrintTree(root->right);
}

void BST::InorderPrint() {
    cout << "Inorder: ";
    InorderPrintTree(root);
    cout << endl;
}

void BST::InorderPrintTree(TreeNode *root) {
    if (root == NULL)
        return;
    InorderPrintTree(root->left);
    cout << root->val << " ";
    InorderPrintTree(root->right);
}

int main() {
    BST TempTree;
    TempTree.InsertValue(16);
    TempTree.InsertValue(18);
    TempTree.InsertValue(8);
    TempTree.InsertValue(12);
    TempTree.InsertValue(11);
    TempTree.InsertValue(14);
    TempTree.InsertValue(9);
    TempTree.InsertValue(10);
    TempTree.InsertValue(4);
    TempTree.InsertValue(2);
    TempTree.InsertValue(6);
    TempTree.InsertValue(5);
    TempTree.FindValue(4);
    TempTree.FindValue(7);
    TempTree.FindMaxValue();
    TempTree.FindMinValue();
    TempTree.InorderPrint();
    TempTree.PreorderPrint();

    TempTree.DeleteNode(8);
    TempTree.InorderPrint();
    TempTree.PreorderPrint();

    return 0;
}
