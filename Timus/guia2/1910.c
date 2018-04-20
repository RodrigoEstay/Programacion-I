#include <stdlib.h>
#include <stdio.h>

/* Programa hecho sin ayuda. */

int main (){
	int n, i, maxMagic=0, maxSection; // "maxMagic" es 0 para que no tome basura en la linea 11.
	scanf("%d", &n);
	int magic[n];

	/* A medida que escaneamos datos, vamos trabajando con ellos, "maxSection=2" se debe que en
	el caso de que solo se ingresan 3 secciones, entonces la seccion del medio sera el 2. Luego
	se escanean datos y se suman para asignar como maxima magia la de los primeros 3 datos, una
	vez superados los 3 datos revisamos si la magia de las ultimas 3 secciones superan la magia
	maxima almacenada, en el caso de que si lo supere, lo asignamos como nueva magia maxima y la
	nueva seccion maxima sera la del medio de los 3, pero ya que los arreglos parten del 0, se
	le suma 1, lo cual queda solo en "i". */

	for(i=0, maxSection=2;i<n;++i){
		scanf("%d", &magic[i]);
		if(i<3){
			maxMagic+=magic[i];
			continue;
		}
		if(maxMagic<magic[i]+magic[i-1]+magic[i-2]){
			maxMagic=magic[i]+magic[i-1]+magic[i-2];
			maxSection=i;
		}
	}
	printf("%d %d\n", maxMagic, maxSection);
	return 0;
}