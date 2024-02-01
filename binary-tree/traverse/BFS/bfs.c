#ifndef BFS
#define BFS
#include "node.h"
#include <stdio.h>


void depth(Node * node,int level);
void depth(Node * node,int level) {
	if (node == NULL)
		return;
	if(level == 1)
		printf("%i\n",node->data);
	depth(node->left,level -1);
	depth(node-right,level -1);

}

#endif
