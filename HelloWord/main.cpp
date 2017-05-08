#include <stdio.h>

int main() {
    //    printf("Hello, World!\n");
    //循环
    //    for (int i = 0; i < 100; ++i) {
    //        // if  条件判断
    //        if (i % 2 == 0) {
    //            printf("The number id %d\n", i);
    //        }
    //    }

    //九九乘法表
    for (int j = 1; j < 10; ++j) {
        for (int i = 1; i <= j; ++i) {
            printf("%d*%d=%2d \t", i, j, j * i);
            //printf("i*j" "= %d", j * i);
        }
        printf("\n");
    }


    return 0;
}