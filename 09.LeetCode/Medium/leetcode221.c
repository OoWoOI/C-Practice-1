/*************************************************************************
	> File Name: leetcode221.c
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Sep 2023 10:16:18 PM CST
 ************************************************************************/


//暴力解法（超时）

//暴力解法：递归
int getMaxLen(char **matrix, int row, int col, int rowSize, int *colSize) {
    if (row == rowSize || col == colSize[row] || matrix[row][col] == '0') return 0;
    int right = getMaxLen(matrix, row, col + 1, rowSize, colSize) + 1;
    int down = getMaxLen(matrix, row + 1, col, rowSize, colSize) + 1;

    int len = 0;
    int flag = 0;
    int n = fmin(down, right);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i + row][j + col] == '1') continue;
            len = fmin(i, j);
            flag = 1;
            break;
        }
        if (flag) break;
    }
    if (len == 0) len = n;
    return len;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    //从两个方向探索，右、下取长度最短 
    int ans = 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == '0') continue;
            ans = fmax(ans, getMaxLen(matrix, i, j, matrixSize, matrixColSize));
        }
    }
    ans = (int)pow(ans, 2);
    return ans;
}



#define min(a, b, c) ({\
    a = fmin(b, a); a = fmin(c, a);\
})

//动态规划
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int ans = 0;
    if (matrix == NULL || matrixSize == 0 || matrixColSize[0] == 0) return ans;
    //dp数组:
    //状态专业方程：dp[i][j] = mid(dp[i - 1][j], dp[i][j - 1], dp[i- 1][j-1]) + 1;
    //代表着dp[i][j]以当前位置为右下角的最大正方形的面积
    int **dp = (int **)malloc(sizeof(int*) * (matrixSize));
    for (int i = 0; i < matrixSize; i++) {
        dp[i] = (int *)malloc(sizeof(int) * matrixColSize[i]);
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = fmin(fmin(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    ans = fmax(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
        }
    }
    free(dp);
    return ans * ans;
}


