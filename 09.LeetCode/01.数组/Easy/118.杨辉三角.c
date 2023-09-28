/*************************************************************************
	> File Name: 118.杨辉三角.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Sep 2023 11:05:36 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int base = numRows;
 //   returnColumnSizes = (int **)malloc(sizeof(int*));
    *returnColumnSizes = (int *)malloc(sizeof(int) * base);
    int **ans = (int **)malloc(sizeof(int *) * (base + 5));

    //生成杨辉三角
    for (int i = 0; i < numRows; i++) {
        ans[i] = (int *)malloc(sizeof(int) * (i + 1));
        ans[i][0] = 1; ans[i][i] = 1;
        for (int j = 1; j < i; j++) {
          //  printf("%d %d\n", ans[i - 1][j - 1], ans[i - 1][j]);
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        //    printf("%d\n", ans[i][j]);
        }
        (*returnColumnSizes)[(*returnSize)++] = i + 1; 
  //      printf("len = %d\n", *returnSize);
    }
    return ans;
}

int main() {
    int *row, col; 
    int **ans = generate(5, &col, &row);
    for (int i = 0; i < col; i++) {
   //     printf("%d\n", row[i]);
        for (int k = col - 1; k > i; k--) {
            printf(" ");
        }
        for (int j = 0; j < row[i]; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
