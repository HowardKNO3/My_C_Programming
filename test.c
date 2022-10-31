#include <stdio.h>

int gcd(int a,int b){
    int min = a*b,max;
    while(a!=0 && b!=0){
        if(a>b)
            a = a % b;
        else 
            b= b % a;
    }
    if (a == 0)
        max = b;
    else   
        max = a;
    min = min/max;
    return min;
    
}

int main(){
    int a[4000],i=0;
    while((scanf("%d",&a[i])) != EOF)
        i++;
    int k=i,ans=1;
    for(i=0;i<k;i++)
        ans = gcd(ans,a[i]);
    printf("%d",ans);
    return 0;
}
