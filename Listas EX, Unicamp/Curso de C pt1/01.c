#include <stdio.h>

int special_num(int num){
	int div_int = num/100, rest_div = num%100;
	int sum = div_int + rest_div, pow = sum * sum;

	//printf("%d + %d = %d ; %d² = %d\n", div_int, rest_div, sum, sum, pow);
	if(num == pow){
		printf("%d + %d = %d ; %d² = %d\n", div_int, rest_div, sum, sum, pow);
		return 1;
	}
	return 0;

}

int main(){
	for(int i=1000; i<= 9999; i++){
		if(special_num(i)) printf("%d eh um numero especial\n\n", i);
		//else printf("%d n eh um numero especial\n", i);
	}

	// int num; scanf("%d", &num);
	// if(special_num(num)) printf("%d eh um numero especial\n", num);
	// else printf("%d n eh um numero especial\n", num);



	return 0;
}