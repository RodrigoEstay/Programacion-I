#include <stdlib.h>
#include <stdio.h>

/* Es tan simple como ver el signo al restarle a 240 minutos los minutos que
le tomara hacer los problemas restantes, si da negativo no alcanza, si da
positivo si alcanza. */

int main (){
	int f, queda;
	scanf("%d", &f);
	queda=4*60-((12-f)*45);
	if(queda>=0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}