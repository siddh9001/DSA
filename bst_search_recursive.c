void insert(node *root, int data)
{
    node * temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left=temp->right = NULL
    if(root == NULL)

}
node* insert(node*root,int data)//recusive
{
if(root==NULL){
   node*temp=(node*)malloc(sizeof(node));
   temp->data=data;
   temp->left=temp->right=NULL;
   root=temp;return root;
}
else if(root->data > data)root->left=insert(root->left,data); 
else root->right=insert(root->right,data);
  return root;
}