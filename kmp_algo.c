#include <stdio.h>
#include <string.h>
int main()
{
    char t[100005],p[1005];
    scanf("%s%s",t,p);
    int n=strlen(t),m=strlen(p);
    //preproccessing
    int f[m];
    f[0]=0;int i=1,j=0;
    while(i<m)
    {
        if(p[i]==p[j]){f[i]=j+1;i++;j++;}
        else if(j>0)j=f[j-1];
        else {f[i]=0;i++;}
    }
    i=0,j=0;
    int flag=0;
    while(i<n)
    {
        if(t[i]==p[j])
        {
            if(j==m-1){flag=1;break;}
            i++;j++;
        }
        else if(j>0)j=f[j-1];
        else {j=0;i++;}
    }
    if(flag==1)printf("%d",i-m+1);
    else printf("pattern is not matching");
    return 0;
}