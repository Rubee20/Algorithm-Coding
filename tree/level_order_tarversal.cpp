#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* getnode(int data)
{
	struct Node* root = (struct Node *) malloc(sizeof(Node));
	root->data = data;
	root->left = NULL;
	root->right = NULL;

	return root;
}

void level_order_traversal(struct Node* root)
{
	queue<Node*> queue;
	if (root == NULL)
		return;

	queue.push(root);

	while (!queue.empty())
	{
		struct Node* tmp = queue.front();
		cout << tmp->data << " ";
		queue.pop();

		if (tmp->left)
			queue.push(tmp->left);

		if (tmp->right)
			queue.push(tmp->right);
	}
}

int main()
{
	struct Node* root = getnode(1);
	root->left = getnode(2);
	root->right = getnode(3);
	root->left->right = getnode(4);
	root->left->left = getnode(5);

	cout << "Level order traversal" << endl;
	level_order_traversal(root);
	return 0;
}
