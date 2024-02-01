#ifndef MAX_DEPTH
#define MAX_DEPTH


#include "node.c"
#include <stdio.h>

int maxDepth(Node * node);
int maxDepth(Node * node){
	if(node == NULL)
		return 0;

	int leftDepth = maxDepth(node->left);
	int rightDepth = maxDepth(node->right);

	if (leftDepth > rightDepth)
		return leftDepth +1;
	else
		return rightDepth +1;
}

#endif


