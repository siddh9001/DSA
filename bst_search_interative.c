node* insert(node*root,int data)//non-recusive
{
   node*temp=(node*)malloc(sizeof(node));
   temp->data=data;
   temp->left=temp->right=NULL;
   if(root==NULL)root=temp;
   else{
   node *temp1=root;
   while(1){
     if(temp1->data > data){
        if(temp1->left==NULL)
        {
          temp1->left=temp;
          break;
        }
       else temp1=temp1->left;
     }
     else {
       if(temp1->right==NULL){
        temp1->right=temp;
        break;
       }
       else temp1=temp1->right;
    }
  }
  return root;
}