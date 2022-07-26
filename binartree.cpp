#include <iostream>
using namespace std;
struct Node{
	int data;
   Node* left;
   Node* right;
};

Node* CreateNewNode(Node* root,int data)
{
	Node* new_node=new Node();
   new_node->data=data;
   new_node->left=NULL;
   new_node->right=NULL;

   if(root==NULL)

   	root=new_node;

   else if(data <= root->data)

   	root->left=CreateNewNode(root->left,data);

   else

   	root->right=CreateNewNode(root->right,data);

   return root;

}

int FindMin(Node* root)
{
	if(root==NULL)
   return -1;

   else if(root->left==NULL)
   	return root->data;

   return FindMin(root->left);
}

int FindMax(Node* root)
{
	if(root==NULL)
   return -1;

   else if(root->right==NULL)
   	return root->data;

   return FindMax(root->right);
}

void showBinarytree(Node* root)
{

}
int main()
{
	
	Node *root=NULL;
   int n;
   char ch='y';
   while(ch!='n')
   {
   	cout<<"Enter the value to insert into the binary tree:\n";
      cin>>n;
      root=CreateNewNode(root,n);
      cout<<"Do you want to continue (y/n):\n";
      cin>>ch;
   }
   cout<<"\n the binary tree is:\n";
   showBinarytree(root);

   cout<<"\n The maximum element in the binary tree is : "<<FindMax(root);
   cout<<"\n The minimum element in the binary tree is : "<<FindMin(root);

  return 0;
}