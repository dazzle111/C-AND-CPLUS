
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10

#define MAX 0    //求最大值
#define MIN 1    //求最小值

int find(int *num, int begin,int end, int opt){       //opt参数设置求最大最小值
    int i, temp1, temp2;   
    if(begin  == end)
        return num[begin];
    else{
        i = begin+(end-begin)/2;
        temp1 = find(num,begin,i,opt);
        temp2 = find(num,i+1,end,opt);
        if(opt == MAX)
            return temp1 > temp2 ? temp1 : temp2;
        return temp1 > temp2 ? temp2 : temp1;
    }
}

int main(){
    int num[N]={0};
    int i,j,k,max,min;

    for(i=0 ; i < N;i++)
        num[i] = rand() ;        //随机生成数字大小在20以内的数组
    for(i=0;i
        printf("%d ",num[i]);

    max = find(num,0,N-1,MAX);
    min = find(num,0,N-1,MIN);
    printf("max:%d min:%d\n",max,min);
    return 0;
}
