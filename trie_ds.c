#include <stdio.h>
#include <stdlib.h>
struct node{
    int c;
    int end;
    struct node*p[26];
};
typedef struct node trienode;

trienode*create()
{
    trienode*nn=(trienode*)malloc(sizeof(trienode));
    nn->c=0;nn->end=0;
    for(int i=0;i<26;i++)nn->p[i]=NULL;
    return nn;
}
trienode*add(trienode*root,char a[])
{
    trienode*t=root;
    for(int i=0;a[i];i++)
    {
        if(t->p[a[i]-97]==NULL)t->p[a[i]-97]=create();
        t=t->p[a[i]-97];
        t->c++;
    }
    t->end=1;
    return root;
}
int main()
{
    int n; scanf("%d",&n);
    char a[5],b[100];
    trienode *root=create();
    while(n--)
    {
        scanf("%s%s",a,b);
        if(a[0]=='a')
        {
            root=add(root,b);
        }
        else{
            trienode*temp=root;
            int f=0;
            for(int j=0;b[j];j++)
            {
                temp=temp->p[b[j]-97];
                if(temp==NULL){f=1;break;}
            }
            if(f==0)printf("%d\n",temp->c);
            else printf("0\n");
        }
    }
    return 0;
}