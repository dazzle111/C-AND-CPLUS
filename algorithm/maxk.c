/// \file maxk.c
/*
  ------------------------------------
  Create date : 2014-12-03 19:28
  Modified date: 2014-12-09 21:23
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <stdio.h>
char 	num[10];
int 	len, k;

//计算start到end位数的数
int get_arr_val(int start, int end)
{
	int result = 0;
	int i = 0;

	for (i = start; i <= end; i++){
		result = result * 10 + num[i] - '0';	
	}
	return result;
}


int get_max_val(int start, int k)
{
	int sum = 0, i = 0, msum = 0;

	//如果k=1，那么值就为它自己
	if (k == 1) {
		return get_arr_val(start, len - 1);
	}
	//k不等于1，那么就需要再分,
	for (i = 0; i <= len - start - k; i++){
		sum = get_arr_val(start, start+i);
		sum *= get_max_val(start + i + 1, k - 1);
		//如果新得到的sum大于原有的，则替换
		if (sum > msum){
			msum = sum;
		}
	}
	return msum;
}

int main(int argc, char *argv[])
{
	printf("please input n, k(n >= k):\n");
	scanf("%d%d", &len, &k);
	printf("please input I(i的位数要等于n):\n");
	scanf("%s", num);
	printf("%d\n", get_max_val(0, k));

	return 0;
}

