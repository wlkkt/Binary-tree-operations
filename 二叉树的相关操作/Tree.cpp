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

//�ܽ�����
int TreeSize(TreeNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->left) +
		TreeSize(root->right) + 1;
}

//Ҷ�ӽ�����
int TreeLeafSize(TreeNode* root)
{
	//���� ����0
	if (root == NULL)
		return 0;

	//�ǿ���������û������������Ҷ�ӽ��/����һ��������������1
	if (root->left == NULL && root->right == NULL)
		return 1;

	//���ǿ� Ҳ����Ҷ�ӽ��
	return TreeLeafSize(root->left) +
		TreeLeafSize(root->right);
}

//���ĸ߶�
int TreeHeight(TreeNode* root)
{
	if (root == NULL)
		return 0;
	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

//��k����ĸ���
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

//����ֵΪx�Ľ��,����ֵΪָ��
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

//����ֵΪx�Ľ��, ����ֵΪ��������
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
	//ǰ���С��������
	PrevOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	LaterOrder(root);
	printf("\n");

	//��ȡ�������еĽ����� 
	printf("TreeSize��%d\n", TreeSize(root));

	//Ҷ�ӽ�����
	printf("TreeLeafSize��%d\n", TreeLeafSize(root));

	//���ĸ߶�
	printf("TreeHeight��%d\n", TreeHeight(root));

	//��k�������
	int k = 2;
	printf("TreeLevelK�� % d\n", TreeLevelK(root, k));

	//����ֵΪx�Ľ��
	int x = 2;
	printf("TreeLevelK�� % d\n", TreeLevelK(root, x));

	//����ֵΪx�Ľ��
	if (TreeFind(root, 5))
		printf("�ҵ���\n");
	else
		printf("û�ҵ�\n");

	return 0;
}
