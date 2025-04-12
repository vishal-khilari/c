#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* left;
struct Node* right;
};
struct Node* newNode(int data) {
struct Node* node = (struct Node*)malloc
(sizeof(struct Node));
node->data = data;
node->left = NULL;
node->right = NULL;
return node;
}
struct Node* insert(struct Node* node, int data) {
if (node == NULL) {
return newNode(data);
}
if (data < node->data) {
node->left = insert(node->left, data);
} else
if (data > node->data) {
node->right = insert(node->right, data);
}
return node;
}
void inorderTraversal(struct Node* root) {
if (root != NULL) {
inorderTraversal(root->left);
printf("%d ", root->data);
inorderTraversal(root->right);
}
}
void PreorderTraversal(struct Node* root) {
if (root != NULL) {
printf("%d ", root->data);
PreorderTraversal(root->left);
PreorderTraversal(root->right);
}
}
void PostorderTraversal(struct Node* root) {
if (root != NULL) {
PostorderTraversal(root->right);
PostorderTraversal(root->left);
printf("%d ", root->data);
}
}
void displayTree(struct Node* root, int space) {
if (root == NULL)
return;
space += 10;
displayTree(root->right, space);
printf("\n");
for (int i = 10; i < space; i++)
printf(" ");
printf("%d\n", root->data);
displayTree(root->left, space);
}
int main() {
struct Node* root = NULL;
root = insert(root, 50);
root = insert(root, 30);
root = insert(root, 20);
root = insert(root, 40);
root = insert(root, 70);
root = insert(root, 60);
root = insert(root, 80);
root = insert(root, 90);
//root = insert(root, 100);
//root = insert(root, 5);
printf("Inorder traversal: ");
inorderTraversal(root);
printf("\n");
printf("Preorder traversal: ");
PreorderTraversal(root);
printf("\n");
printf("Postorder traversal: ");
PostorderTraversal(root);
printf("\n");
printf("Tree Display:\n");
displayTree(root, 0);
return 0;
}