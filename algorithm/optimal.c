/// \file optimal.c
/*
  ------------------------------------
  Create date : 2014-12-03 19:26
  Modified date: 2014-12-09 21:24
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/

#include <stdio.h>


int main(int argc, char *argv[])
{
	int 	num = 0;
	int 	i = 2;
	int 	sum = 0;
	int 	separate = 0;
	long 	result = 1;
	int 	j = 0;

	printf("input num:");
	scanf("%d", &num);
	if(num <=4){
		printf("%d",num);
		return 0;
	}

	//把数num分成若干个互不相等的自然数的和，因数各数
	//越多，乘积越大。为了使因数个数尽可能地多，所以从i=2
	//开始分，直到和大于等于num
	while (1){
		sum += i;
		printf("sum = %d\n", sum);
		if (sum >= num){
			separate = sum - num;	//separate为差值
			break;
		}
		i++;

	}

	printf("i = %d, separate = %d\n", i, separate);
	
	//若和比num大，则因数各数至少减少1个，那个因数为sum-num的差
	for (j = 2; j < separate; j++){
		result = result * j;		
	}

	for (j = separate + 1; j <= i; j++){
		result = result * j;
	}

	printf("result = %ld\n", result);
	return 0;
}

