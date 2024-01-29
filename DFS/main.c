#include "tree-traversal-algorithms.c"
#include <stdio.h>
int main(){
	struct Node * node = newNode(1);
	node->left = newNode(2);
	node->right = newNode(3);
	node->left->left = newNode(4);
	node->left->right = newNode(5);
	printf("inorder traverse\n");
	inorder_traverse(node);
	printf("\npreorder traverse\n");
	preorder_traverse(node);
	printf("\npost traverse\n");
	postorder_traverse(node);

}

