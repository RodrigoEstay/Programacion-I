#include <stdio.h>
#include <stdlib.h>

long long mcm(long long n1, long long n2);

int main(){
	long long n1, n2, m;
	printf("Ingrese dos numeros:\n");
	scanf("%lld%lld", &n1, &n2);
	m=mcm(n1, n2);
	if(m){
		printf("El minimo comun multiplo es: %lld\n", m);
	}
	else{
		printf("No presentan minimo comun multiplo.\n");
	}
}

long long mcm(long long n1, long long n2){
	if(n1==0 || n2==0){
		return 0;
	}
	long long temp, i;
	if(n2>n1){
		temp=n1;
		n1=n2;
		n2=temp;
	}
	i=n1;
	while(i%n1!=0 || i%n2!=0){
		++i;
	}
	return i;
}