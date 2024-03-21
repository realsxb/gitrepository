#include<Windows.h>
#include<stdio.h>
int aaa=1;
int main(){
	MessageBoxW(0,NULL,NULL,MB_OK);
	aaa=0x778899;
	asm("movl $0x778899,%0":"=m"(aaa));
	printf("你好");
	return 0;
}