#include<stdio.h>
#include<stdlib.h>
#define MAXN 20
int q[MAXN];
int count=0;
void dispasolution(int n){
	printf(" %d:", count++);
	for(int i=1;i<=n;i++)
	printf("(%d,%d) ", i,q[i]);
	printf("\n");
}
bool place(int i) //Test whether the queen can be placed in the (i,j) position
{
	int j=1;
	if(i==1) return true; //The first queen can always be placed
	
	while (j<i){ //  k=1~i-1 is the row where the queen has been placed

		if((q[j]==q[i]) || (abs(q[j]-q[i])==abs(j-i)))
		return false;
		j++;
	} 
	return true;
}
void Queens(int n){ //Place the queen of 1~i
	int i=1;
	q[i]=0;
	while (i>=1){
		q[i]++;
		while (q[i]<=n && !place(i))
		q[i]++;
		if(q[i]<=n){
			if(i==n)
			dispasolution(n); //All queen placement ends
			else{
				i++;
				q[i]=0;
			}
		}
		else i--;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d:\n",n);
	Queens(n);
}
