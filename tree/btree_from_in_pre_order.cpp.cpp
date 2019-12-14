#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* newnode(int data)
{
    struct TreeNode* root = (struct TreeNode*) malloc(sizeof(TreeNode));
    root->val = data;
    root->left =NULL;
    root->right = NULL;
    
    return root;
}
int search(vector<int> &B, int data, int start, int end)
{
	int i;
    for (i = start; i<end; i++)
    {
        if (B[i] == data)
            return i;
    }
    return -1;
}

TreeNode* fun1(vector<int> &A, vector<int> &B, int start, int end)
 {
     static int i = 0;
     
     if (start > end)
        return NULL;
    
    cout << "i = " << i << endl;
    cout << "start = " << start << " end = " << end << endl;
    struct TreeNode* root = newnode(A[i]);
    cout << "root->data = " << root->val << endl;
    i++;
    
    if (start == end)
        return root;
        
    int n = search(B, root->val, start, end);
    root->left = fun1(A, B, start, n-1);
    
    root->right = fun1(A, B, n+1, end);
    
    return root;
 }

 TreeNode* buildTree(vector<int> &A, vector<int> &B) {
    if (A.size() == 0 || B.size() == 0)
        return NULL;
        
    TreeNode* root = fun1(A, B, 0, B.size()-1);
    
   return root;
}

void print_inorder(struct TreeNode* root)
{
	if (root == NULL)
		return;
    cout << root->val << " ";
	print_inorder(root->left);
	
	print_inorder(root->right);
}

void print_postorder(struct TreeNode* root)
{
    if (root == NULL)
        return;
    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->val << " ";
}
int main()
{
	vector<int> A{1, 2, 3}; 
	vector<int> B{2, 1, 3};

	cout << A.size() << " " << B.size() << endl;

	TreeNode* root = buildTree(A, B);

    cout << "****** Pre order ******" << endl;
	print_inorder(root);

    cout <<endl << "****** Post order ******" << endl;
    print_postorder(root);
	return 0;
}