#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int data;
	struct Node *left = NULL;
	struct Node *right = NULL;
};

struct Node* getnode(int key)
{
	struct Node* root = (struct Node*) malloc(sizeof(Node));
	root->data = key;
	root->left = NULL;
	root->right = NULL;

	return root;
}

void inorder(struct Node* root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	cout << root->data << " ";
	//cout << "rubee" << endl;
	inorder(root->right);
}

void inorder1(struct Node* root, vector<int> &arr)
{
	if (root == NULL)
		return;

	inorder1(root->left, arr);
	arr.push_back(root->data);
	inorder1(root->right, arr);
}
void replace_sun(struct Node* root, vector<int> arr, int* i)
{
	if (root == NULL)
		return;

	replace_sun(root->left, arr, i);
	root->data = arr[*i-1] + arr[*i+1];
	++*i;
	replace_sun(root->right, arr, i);
}
void fun1(struct Node* root)
{
	vector <int> arr;
	arr.push_back(0);
	int i = 1;

	inorder1(root, arr);
	//cout <<endl << "1 " << endl;
	//for (int i=0; i<arr.size(); i++)
	//	cout << arr[i] << " " << endl;
	replace_sun(root, arr, &i);
}

int main()
{
	struct Node *root = getnode(1);
	root->left = getnode(2);
	//cout << "rubee = " << root->left->left;
	root->right = getnode(3);
	root->left->left = getnode(4);
	root->left->right = getnode(5);
	root->right = getnode(6);
	root->right->right = getnode(7);
	inorder(root);
	fun1(root);
	//cout << "2 " << endl;

	cout << endl <<"after replacing node data sum inorder predecessor successor" << endl;
	inorder(root);

	return 0;
}
