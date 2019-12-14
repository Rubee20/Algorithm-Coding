#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

struct Node* newnode(int k)
{
	Node* root = (struct Node*) malloc(sizeof(Node));
	root->data = k;
	root->left = NULL;
	root->right = NULL;

	return root;
}

void level_order(Node* root)
{
	if (root == NULL)
		return;

	queue <Node*> q1;
	queue <Node*> q2;

	cout << root->data << " ";

	q1.push(root->left);
	q2.push(root->right);

	while(!q1.empty())
	{
		Node* tmp = q1.front();
		q1.pop();
		cout << tmp->data << " ";

		if (tmp->left)
			q1.push(tmp->left);

		if (tmp->right)
			q1.push(tmp->right);

		tmp = q2.front(); 
		q2.pop();
		cout << tmp->data << " ";

		if (tmp->right)
			q2.push(tmp->right);

		if (tmp->left)
			q2.push(tmp->left);
	}
}
int main()
{
	Node* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right->left = newnode(6);
	root->right->right = newnode(7);
	root->left->left->left = newnode(8);
	root->left->left->right = newnode(9);
	root->left->right->left = newnode(10);
	root->left->right->right = newnode(11);
	root->right->left->left = newnode(12);
	root->right->left->right = newnode(13);
	root->right->right->left = newnode(14);
	root->right->right->right = newnode(15);
	level_order(root);
	return 0;
}