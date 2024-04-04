#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}TreeNode;

TreeNode* BuyTreeNode(int x)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	assert(node);

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

TreeNode* CreatTree()
{

	TreeNode* node1 = BuyTreeNode(1);

	TreeNode* node2 = BuyTreeNode(2);

	TreeNode* node3 = BuyTreeNode(3);

	TreeNode* node4 = BuyTreeNode(4);

	TreeNode* node5 = BuyTreeNode(5);

	TreeNode* node6 = BuyTreeNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	//node2->right = NULL;
	//node3->left = NULL;
	//node3->right = NULL;
	node4->left = node5;
	node4->right = node6;
	//node5->left = NULL;
	//node5->right = NULL;
	//node6->left = NULL;
	//node6->right= NULL;

	return node1;
}

void PrevOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void LaterOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	LaterOrder(root->left);
	LaterOrder(root->right);
	printf("%d ", root->data);
}

//总结点个数
int TreeSize(TreeNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->left) +
		TreeSize(root->right) + 1;
}

//叶子结点个数
int TreeLeafSize(TreeNode* root)
{
	//空树 返回0
	if (root == NULL)
		return 0;

	//非空树，但是没有左右子树（叶子结点/仅有一个结点的树）返回1
	if (root->left == NULL && root->right == NULL)
		return 1;

	//不是空 也不是叶子结点
	return TreeLeafSize(root->left) +
		TreeLeafSize(root->right);
}

//树的高度
int TreeHeight(TreeNode* root)
{
	if (root == NULL)
		return 0;
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

//第k层结点的个数
int TreeLevelK(TreeNode* root, int k)
{
	assert(k > 0);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;

	return TreeLevelK(root->left, k - 1) +
		TreeLevelK(root->right, k - 1);
}

//查找值为x的结点,返回值为指针
TreeNode* TreeFind(TreeNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;

	TreeNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;
	TreeNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;

	return NULL;
}

//查找值为x的结点, 返回值为布尔类型
//bool TreeFind(TreeNode* root, BTDataType x)
//{
//	if (root == NULL)
//		return NULL;
//	if (root->data == x)
//		return root;
//
//	return TreeFind(root->left, x) || TreeFind(root->right, x);
//}

int main()
{
	TreeNode* root = CreatTree();
	//前、中、后序遍历
	PrevOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	LaterOrder(root);
	printf("\n");

	//获取二叉树中的结点个数 
	printf("TreeSize：%d\n", TreeSize(root));

	//叶子结点个数
	printf("TreeLeafSize：%d\n", TreeLeafSize(root));

	//树的高度
	printf("TreeHeight：%d\n", TreeHeight(root));

	//第k层结点个数
	int k = 2;
	printf("TreeLevelK： % d\n", TreeLevelK(root, k));

	//查找值为x的结点
	int x = 2;
	printf("TreeLevelK： % d\n", TreeLevelK(root, x));

	//查找值为x的结点
	if (TreeFind(root, 5))
		printf("找到了\n");
	else
		printf("没找到\n");

	return 0;
}
