#include <stdio.h>

void printBinary(int num) {
    unsigned int mask = 1 << (sizeof(int) * 8 - 1); // 创建一个掩码，用于检查每一位
    for(int i = 0; i < sizeof(int) * 8; i++) {
        putchar(num & mask ? '1' : '0'); // 检查每一位是否为1
        mask >>= 1; // 将掩码右移一位
    }
    putchar('\n');
}

int main() {
    int num;
    while(scanf("%d", &num) != EOF) {
        if(num<0){
            printBinary(~(num-1)+2147483648);
            printBinary(num-1);
            printBinary(num);
        }else{
            printBinary(num);
            printBinary(num);
            printBinary(num);
        }
        
    }
    return 0;
}