#ifndef NODE_STRUCT
#define NODE_STRUCT
typedef struct Node {
	int data;
	struct Node *left;
        struct Node *right;
}Node; 

struct Node *  newNode(int data) {
	struct Node *temp =  (struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->left = NULL;
	temp->right = NULL;
	return (temp);

}
#endif
