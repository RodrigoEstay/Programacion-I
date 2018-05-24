#include <stdio.h>
#include <stdlib.h>

long long mcd(long long n1, long long n2);

int main(){
	long long n1, n2, m;
	printf("Ingrese dos numeros:\n");
	scanf("%lld%lld", &n1, &n2);
	m=mcd(n1, n2);
	if(m){
		printf("El minimo comun divisor es: %lld\n", m);
	}
	else{
		printf("No existe minimo comun divisor\n");
	}
	return 0;
}

long long mcd(long long n1, long long n2){
	long long temp, i;
	if(n1>n2){
		temp=n2;
		n2=n1;
		n1=temp;
	}
	i=n1;
	while(1){
		if(i==0){
			break;
		}
		if(n1%i==0 && n2%i==0){
			break;
		}
		--i;
	}
	return i;
}