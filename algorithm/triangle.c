/// \file triangle.c
/*
  ------------------------------------
  Create date : 2014-12-03 19:17
  Modified date: 2014-12-03 19:20
  Author : liaoshengxin
  Email : 654504711@qq.com
  ------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <fcntl.h>


#define MAX_NUM 100

int 	TriArray[MAX_NUM + 10][MAX_NUM + 10];
int 	N;
int 	aMaxSum[MAX_NUM + 10][MAX_NUM + 10];

int main(int argc, char *argv[])
{
	int 	i, j; 
	//初始化生成一个数组
	srand((unsigned int)(time(NULL)));
	//产生1～100行
	N = 1+ rand() % (10 -1);
	for (i = 1; i <= N; i++){
		for (j = 1; j <=i; j++){
		//所有的数都在0～99
		TriArray[i][j] = rand() % 99;
		}
	}
/*	fd = open ("input.txt", O_WRONLY | O_CREAT | O_TRUNC, 0766) ;

	for (i = 1; i <= N; i++){
		for (j = 1; j <= i; j++){
			write(fd, &TriArray[i][j], sizeof(TriArray[i][j]));
		}
		write(fd, ch, sizeof(ch));
	}
*/
	printf("数组：\n");
	for (i = 1; i <= N; i++){
		for (j = 1; j <= i; j++){
			printf("%d ", TriArray[i][j]);
		}
		printf("\n");
	}

	for (j = 1; j <= N; j++){
		aMaxSum[N][j] = TriArray[N][j];
	}

	for (i = N; i > 1; i--){
		for (j = 1; j < i; j++){
			if (aMaxSum[i][j] > aMaxSum[i][j + 1]){
				aMaxSum[i - 1][j] = aMaxSum[i][j] + TriArray[i - 1][j];
			}else {
				aMaxSum[i - 1][j] = aMaxSum[i][j+1] + TriArray[i - 1][j];
			}

		}
	}
	printf("结果：");
	printf("%d\n", aMaxSum[1][1]);
	return 0;
}

