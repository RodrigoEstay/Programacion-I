#include <stdio.h>
#include <stdlib.h>

int main (){
	int n;
	scanf("%d", &n);
	if(1<=n && n<=4)
		printf("few\n");
	if(5<=n && n<=9)
		printf("several\n");
	if(10<=n && n<=19)
		printf("pack\n");
	if(20<=n && n<=49)
		printf("lots\n");
	if(50<=n && n<=99)
		printf("horde\n");
	if(100<=n && n<=249)
		printf("throng\n");
	if(250<=n && n<=499)
		printf("swarm\n");
	if(500<=n && n<=999)
		printf("zounds\n");
	if(1000<=n)
		printf("legion\n");
	return 0;
}