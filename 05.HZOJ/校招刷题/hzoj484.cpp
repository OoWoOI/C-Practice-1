/*************************************************************************
	> File Name: hzoj484.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Dec 2023 08:29:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int score[30];
char chr;

int main() {
    while ((cin >> chr)) {
        if (chr < 'A' || chr > 'Z') continue;
        score[chr - 'A']++;
    }
    int max_height = 0;
    for (int i = 0; i < 26; i++) max_height = max(max_height, score[i]);
    
    int last[max_height  + 5] = {0};

    //控制行数
    for (int i = 0; i < max_height; i++) {
        
        //处理每一行最后出现的为止
        for (int j = 0; j < 26; j++) {
            if (score[j]  >= max_height - i) {
                last[max_height - i] = j;
            }
        }
    }
    
    for (int i = 0; i < max_height; i++) {
        
        for (int j = 0; j < 26; j++) {
            if (j != 0) printf(" ");
            if (score[j] >= max_height - i) {
                printf("*");
                if (last[max_height - i] == j) break;
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }


    for (int i = 0; i < 26; i++) {
       if (i != 0) printf(" ");
        putchar('A' + i);
    }
    
    cout << endl;

    return 0;
}
