#ifndef inorder-traversal
#define inorder-traversal
#include <stdio.h>
#include <stdlib.h>
#include "node.c"
void inorder_traverse(Node * node);
void preorder_traverse(Node * node);
void postorder_traverse(Node * node);
struct Node * copy_tree(Node * node);
struct Node * newNode(int data);



struct Node *  newNode(int data) {
	struct Node *temp =  (struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->left = NULL;
	temp->right = NULL;
	return (temp);

}

void inorder_traverse(struct Node * node){
	if(node == NULL)
		return;

	inorder_traverse(node->left);
	printf("%i ",node->data);
	inorder_traverse(node->right);

}

void preorder_traverse(Node * node){
	if (node == NULL)
		return;

	printf("%i ", node->data);
	preorder_traverse(node->left);
	preorder_traverse(node->right);
}

void postorder_traverse(Node * node) {
	if(node == NULL)
		return;

	postorder_traverse(node->left);
	postorder_traverse(node->right);
	printf("%i ",node->data);
}

struct Node *  copy_tree(Node * node){
	if (node == NULL)
		return;
	struct Node * copy = (struct Node*)malloc(sizeof(struct Node));
	copy->data = node->data;
	copy->left = copy_tree(node->left);
	copy->right = copy_tree(node->right);
	return copy;
}

#endif
