#include<stdio.h>
#include<string.h>
#define N 101  //101
#define K (N * N)  //10001
#define LENGTH 10
#define C 10
char tower[N][N][N][LENGTH] = {}, table[K][C][LENGTH] = {};
int hi[K][C] = {}, hj[K][C] = {}, hk[K][C] = {};
void init(){
    for(int i=0; i<K; i++)
        for(int j=0; j<C; j++)
            table[i][j][0] = '\0';
}
int f(char *str, int k){
    int ans=(str[0]-'a'+1);
    int i=1;
    while(str[i]!='\0'){
        ans = (ans*29+(str[i]-'0'+1))%k;
        i++;
    }
    return ans;
}
// int f(char *c, int k)
// {
//     return (77 * (c[0] - 'a') + 2022) % k;
// }
int search(int v, char *target){
    for(int i=0; i<C; i++){
        if(strcmp(table[v][i],target)==0)
        {
            // printf("found %s in %d\n", target, i);
            return i;
        }
    }
    return -1;
}
void hash(int ni, int nj, int nk, int n, int k){
    char str_now[LENGTH];
    strcpy(str_now,tower[ni][nj][nk]);
    int v = f(str_now,k);
    int find = search(v,str_now);
    if(find<0){
        int insertc = 0;
        while(table[v][insertc][0]!='\0')
            insertc++;
        //insert
        strcpy(table[v][insertc],str_now);
        hi[v][insertc] = ni;
        hj[v][insertc] = nj;
        hk[v][insertc] = nk;
        // printf("insert %s in %d, %d\n", str_now, v, insertc);
    }
    else{
        printf("%s ", str_now);
        //remove
        table[v][find][0] = '\0';
        if(ni+1<n)
            hash(ni+1,nj,nk,n,k);
        int ii = hi[v][find], jj = hj[v][find], kk = hk[v][find];
        if(ii+1<n)
            hash(ii+1,jj,kk,n,k);
    }
    return;
}
int main(){
    int a, b;
    int n,k;
    scanf("%d%d%d", &n, &a, &b);
    init();
    k = n*n;
    //input tower
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
            for(int m=0; m<=i; m++)
                scanf("%s", tower[i][j][m]);
    //insert the tops one by one
    for(int i=0; i<n; i++){
        hash(i,i,i,n,k);
        for(int j=0; j<i; j++){
            hash(i,j,i,n,k);
            hash(i,i,j,n,k);
        }
    }
}