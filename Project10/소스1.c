/** C implementation for
Red-Black Tree Insertion**/
#include <stdio.h>
#include <stdlib.h>
// Definition of the structure for a red-black tree node
struct node {
	int d; // 'd' is for storing the data value in the node
	int c; // 'c' represents the color of the node: 1 for red, 0 for black
	struct node* p; // 'p' for parent pointer
	struct node* r; // 'r' for right child pointer
	struct node* l; // 'l' for left child pointer
};
// The root of the red-black tree is initialized to NULL as the tree starts empty
struct node* root = NULL;
// Function to insert a node into a binary search tree (BST)
struct node* bst(struct node* trav, struct node* temp) {
	// If we reach a NULL node, it means we've found the correct place to insert our new node
	if (trav == NULL)
		return temp;
	// We use BST property: left children < parent node < right children
	if (temp->d < trav->d) {
		// Recurse to the left subtree if the new node's data is less than the current node's data
		trav->l = bst(trav->l, temp);
		// Set the new node's parent to the current node
		trav->l->p = trav;
	}
	else if (temp->d > trav->d) {
		// Recurse to the right subtree if the new node's data is greater than the current node's data
		trav->r = bst(trav->r, temp);
		// Set the new node's parent to the current node
		trav->r->p = trav;
	}
	// The current node is returned if no insertion takes place (it's already in the right position)
	return trav;
}
// Function to perform a right rotation on the tree
// This is used to maintain the red-black tree properties
void rightrotate(struct node* temp) {
	// The left child of 'temp' will become 'temp's new parent
	struct node* left = temp->l;
	// The left's right child becomes temp's left child
	temp->l = left->r;
	if (temp->l)
		temp->l->p = temp;
	left->p = temp->p;
	// If the 'temp' was the root, the new root will be 'left'
	if (!temp->p)
		root = left;
	// If 'temp' was a left child, then 'left' becomes a left child
	else if (temp == temp->p->l)
		temp->p->l = left;
	// If 'temp' was a right child, then 'left' becomes a right child
	else
		temp->p->r = left;
	left->r = temp;
	temp->p = left;
}
// Function to perform a left rotation on the tree
// This is used to maintain the red-black tree properties
void leftrotate(struct node* temp) {
	// The right child of 'temp' will become 'temp's new parent
	struct node* right = temp->r;
	// The right's left child becomes temp's right child
	temp->r = right->l;
	if (temp->r)
		temp->r->p = temp;
	right->p = temp->p;
	// If the 'temp' was the root, the new root will be 'right'
	if (!temp->p)
		root = right;
	// If 'temp' was a left child, then 'right' becomes a left child
	else if (temp == temp->p->l)
		temp->p->l = right;
	// If 'temp' was a right child, then 'right' becomes a right child
	else
		temp->p->r = right;
	right->l = temp;
	temp->p = right;
}
// This function is called after BST insertion to fix any red-black tree property violations
void fixup(struct node* root, struct node* pt) {
	struct node* parent_pt = NULL;
	struct node* grand_parent_pt = NULL;
	// We fix the tree as long as 'pt' is not the root and 'pt' is red and parent of 'pt' is also red
	while ((pt != root) && (pt->c != 0) && (pt->p->c == 1)) {
		parent_pt = pt->p;
		grand_parent_pt = pt->p->p;
		// If the parent of 'pt' is the left child of the grandparent of 'pt'
		if (parent_pt == grand_parent_pt->l) {
			struct node* uncle_pt = grand_parent_pt->r;
			// If the uncle is red, we only need to recolor
			if (uncle_pt != NULL && uncle_pt->c == 1) {
				grand_parent_pt->c = 1;
				parent_pt->c = 0;
				uncle_pt->c = 0;
				pt = grand_parent_pt;
			}
			else {
				// If 'pt' is the right child of its parent, we perform a left rotation
				if (pt == parent_pt->r) {
					leftrotate(parent_pt);
					pt = parent_pt;
					parent_pt = pt->p;
				}
				// After the above, a right rotation is performed
				rightrotate(grand_parent_pt);
				int t = parent_pt->c;
				parent_pt->c = grand_parent_pt->c;
				grand_parent_pt->c = t;
				pt = parent_pt;
			}
		}
		else {
			// Similar fixup as above but with the roles of left and right exchanged
			struct node* uncle_pt = grand_parent_pt->l;
			if ((uncle_pt != NULL) && (uncle_pt->c == 1)) {
				grand_parent_pt->c = 1;
				parent_pt->c = 0;
				uncle_pt->c = 0;
				pt = grand_parent_pt;
			}
			else {
				if (pt == parent_pt->l) {
					rightrotate(parent_pt);
					pt = parent_pt;
					parent_pt = pt->p;
				}
				leftrotate(grand_parent_pt);
				int t = parent_pt->c;
				parent_pt->c = grand_parent_pt->c;
				grand_parent_pt->c = t;
				pt = parent_pt;
			}
		}
	}
}
// Function to print the in-order traversal of the tree
void inorder(struct node* trav) {
	if (trav == NULL)
		return;
	inorder(trav->l);
	printf("%d ", trav->d);
	inorder(trav->r);
}
// Main function where the execution of the program begins
int main() {
	int n = 7; // Number of nodes to be inserted
	int a[7] = { 7, 6, 5, 4, 3, 2, 1 }; // The values to be inserted into the tree
	// Loop to insert nodes into the tree
	for (int i = 0; i < n; i++) {
		// Creating a new node with the value from the array and color it red (1)
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		temp->r = NULL;
		temp->l = NULL;
		temp->p = NULL;
		temp->d = a[i];
		temp->c = 1;
		// Perform BST insertion with the new node
		root = bst(root, temp);
		// Fix any violations after BST insertion
		fixup(root, temp);
		// Ensure the root is always black (0)
		root->c = 0;
	}
	// Print the in-order traversal of the tree to show the final structure
	printf("Inorder Traversal of Created Tree\n");
	inorder(root);
	return 0; // End of program
}