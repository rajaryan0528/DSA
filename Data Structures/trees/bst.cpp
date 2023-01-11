/*
Write a program to implement Binary Search Tree which supports the following operations:
(i) Insert an element x
(ii) Delete an element x
(iii)  Search for an element x in the BST  and change its value to y and then place the node with
       value y at its appropriate position in the BST
(iv) Display the elements of the BST in preorder, inorder, and postorder traversal (iterative,recursive)
(v) Display the elements of the BST in level-by-level traversal
(vi) Display the height of the BST
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node
{
public:
       int data;
       node *right;
       node *left;
       node(int d)
       {
              this->data = d;
              this->left = NULL;
              this->right = NULL;
       }
};


void levelOrderTraversal(node* root)
{
       queue<node*> q;
       q.push(root);
       q.push(NULL);  //separator

       while(!q.empty()){
              node* temp =q.front();
              q.pop();
              if(temp==NULL){
                     cout<<endl;
                     if(!q.empty())
                        q.push(NULL);
              }
              else{
                     cout<<temp->data<<" ";
                     if(temp->left){
                            q.push(temp->left);
                     }
                     if (temp->right)
                     {
                            q.push(temp->right );
                     }
              }
       }
}
node *insertData(node *&root, int d)
{
       // base case
       if (root == NULL)
       {
              root = new node(d);
              return root;
       }

       if (d > root->data)
       {
              // right subtree
              root->right = insertData(root->right, d);
       }

       else
       {
              // left subtree
              root->left = insertData(root->left, d);
       }
       return root;
}

void getData(node *&root)
{
       int data;
       cin >> data;
       while (data != -1)
       {
              insertData(root, data);
              cin >> data;
       }
}

void inorder(node* root){
       //base case
       if(root==NULL)
          return;

       // L Root R   
       inorder(root->left);
       cout<<root->data<<" ";
       inorder(root->right);
}
void postorder(node* root){
       // base case
       if (root == NULL)
          return;
       // L R Root
       postorder(root->left);
       postorder(root->right);
       cout << root->data << " ";
}
void preorder(node* root){
       // base case
       if (root == NULL)
          return;
       //Root L R
       cout << root->data << " ";
       preorder(root->left);
       preorder(root->right);
}
void iterativeInorder(node *root)
{
       stack<node *>s;
       node *curr = root;

       while (curr != NULL || s.empty() == false)
       {
          /* Reach the left most Node of the curr Node */
          while (curr != NULL)
          {
              /* place pointer to a tree node on the stack before traversing the node's left subtree */
                     s.push(curr);
                     curr = curr->left;
          }

          /* Current must be NULL at this point */
          curr = s.top();
          s.pop();
          cout << curr->data << " ";

          /* we have visited the node and its left subtree.  Now, it's right subtree's turn */
          curr = curr->right;
       }
}

void iterativePostorder(node *root)
{
       if (root == NULL)
          return;
       stack<node*> s1, s2;

       // push root to first stack
       s1.push(root);
       node *node;

       // Run while first stack is not empty
       while (!s1.empty())
       {
          // Pop an item from s1 and push it to s2
          node = s1.top();
          s1.pop();
          s2.push(node);

          // Push left and right children
          // of removed item to s1
          if (node->left)
                     s1.push(node->left);
          if (node->right)
                     s1.push(node->right);
       }

       // Print all elements of second stack
       while (!s2.empty())
       {
          node = s2.top();
          s2.pop();
          cout << node->data << " ";
       }
}
void iterativePreorder(node *root)
{
       if (root == NULL)
          return;
       stack<node*> nodeStack;
       nodeStack.push(root);

       /* Pop all items one by one. Do following for every popped item
          a) print it
          b) push its right child
          c) push its left child
       Note that right child is pushed first so that left is processed first */
       while (nodeStack.empty() == false)
       {
          // Pop the top item from stack and print it
          node *node = nodeStack.top();
          cout<<node->data<<" ";
          nodeStack.pop();

          // Push right and left children of the popped node to stack
          if (node->right)
                     nodeStack.push(node->right);
          if (node->left)
                     nodeStack.push(node->left);
       }
}
node *minValue(node *root)
{
       node *temp = root;
       while (temp != NULL)
       {
          temp = temp->left;
       }
       return temp;
}

node* deletion(node* root,int val)
{
   
    if(root==NULL)
      return root;
    if(root->data==val)
    {
       //0 child
       if(root->left==NULL && root->right==NULL)
       {
              delete root;
              return NULL;
       }
       //1 child
       if (root->left != NULL && root->right == NULL)
       {
              node *temp=root->left;
              delete root;
              return temp;
       }
       if (root->left == NULL && root->right != NULL)
       {
              node *temp = root->right;
              delete root;
              return temp;
       }
       //2 children
       if (root->left != NULL && root->right != NULL)
       {
              int min=minValue(root->right)->data;  //inorder successor
              root->data=min;
              root->right=deletion(root->right,min);
              return root;
       
       }
    }
    else if(root->data>val){
       root->left=deletion(root->left,val);
       return root;
    }
    else{
       root->right =deletion(root->right,val);
       return root;
    } 
}


bool search(node *&root, int x)
{
       // base case
       if (root == NULL)
          return false;

       if(root->data==x)
            return true;

       if (root->data>x)
       {
          //  might be in left subtree
            return search(root->left, x);
       }

       else
       {
          //  might be in right subtree
            return search(root->right, x);
       }
}

bool searchIterative(node *&root, int x)
{
       node* temp=root;
       while(temp !=NULL){
            if (root->data == x)
                     return true;
            if (root->data > x)
                     temp=temp->left;
            else
                     temp = temp->right;
       }
       return false;
}
int main()
{
       node *root = NULL;
       getData(root);
       inorder(root);
       cout << endl;
       // iterativeInorder(root);
       // cout << endl;
       // preorder(root);
       // cout<<endl;
       // iterativePreorder(root);
       // postorder(root);
       // cout << endl;
       // iterativePostorder(root);
       //cout<<search(root,10);
       deletion(root,12);
       //levelOrderTraversal(root);
}