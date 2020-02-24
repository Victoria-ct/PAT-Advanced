#include<cstdio>
#include<cmath>
#include<cstring>
int main(){
	int a,b,sum;
	scanf("%d %d",&a,&b);
	sum = a + b;
	int i = 0;  //判断正负
	if (sum < 0){
		sum *= -1;
		i = 1;
	}
	int j = 0,c;
	int re[11] = {0};
	if(sum == 0)
	   j = 1;
	while(sum != 0){
		c = sum % 10;
		re[j] = c;
		j++;
		sum = sum / 10;
	}
	if(i == 1)
		printf("-");
	while(j > 0){
		printf("%d",re[j-1]);
		if(j % 3 == 1 && j > 1){		
			printf(",");             //第7位，第4位后分别加一个‘，’
		}
		j--;
	}
	return 0;
}