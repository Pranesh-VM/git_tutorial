#include<stdio.h>
#define max 10
int top=-1;
int stack[max];
int factorial(int);
int main(){
    int x,result;
    printf("enter a number:");
    scanf("%d",&x);
    result=factorial(x);
    printf("\n factorial of %d is %d",x,result);
}
int factorial(int n){
    int fact=1,length=0,flag=0;
    while(n>0){
            if(top==max-1){
                flag=1;
            }
            else{
                top++;
                stack[top]=n;
                length++;

            }
            n--;
    }
    if(!flag){
        for(int i=0;i<length;i++){
            printf("%d,",stack[i]);
            fact=fact*stack[i];
        }
    }
    else{
        printf("the stack is overflow");
        return 0;
    }
    return fact;
}
