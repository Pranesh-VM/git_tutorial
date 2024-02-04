#include<stdio.h>
#include<string.h>
#include<malloc.h>
char stack[50];
int top=-1;
void push(char);
char pop();
void palindrome_bracket_main(char);
void Ispalindrome(char *,int);
void Isbraketcrct(char *,int);
int main(){
    printf("---------------MENU------------------\n");
    printf("1.Bracket Matching\n");
    printf("2.Palindrome Checker\n");
    printf("3.Infix TO PostFix\n");
    printf("4.Polynomial Addition\n");
    int choice;
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:{
            palindrome_bracket_main('b');
            break;
        }
        case 2:{
            palindrome_bracket_main('p');
            break;
        }
        printf("github changing");
        printf("git cloneing");
    }
}
void palindrome_bracket_main(char choice){
    char str[50];
    printf("enter a string:");
    scanf("%s",str);
    int len=strlen(str);
    if(choice=='b'){
        Isbraketcrct(&str[0],len);
    }
    if(choice=='p'){
        Ispalindrome(&str[0],len);
    }
}
void Isbraketcrct(char *str,int len){
    int i,flag=1;
    char temp;
    for(int i=0;i<len;i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='[' ){
            push(str[i]);
        }
        if(str[i]=='}' || str[i]==']' || str[i]==')'){
            if(top==-1){
                flag=0;
            }
            else{
                temp=pop();
                if(str[i]==')' && (temp=='{' || temp=='['))
                    flag=0;
                if(str[i]=='}' && (temp=='(' || temp=='['))
                    flag=0;
                if(str[i]==']' && (temp=='(' || temp=='{'))
                    flag=0;
            }
        }
    }
    if(top>=0){
        flag=0;
    }
    if(flag==1){
        printf("valid expression");
    }
    else{
        printf("Invalid expression");
    }
}
void Ispalindrome(char *str,int len){
        int i,j;
        int mid=len/2;
        int flag=0;
        for(i=0;i<mid;i++){
                push(str[i]);
        }
        for(j=mid+1;j<len;j++){
                if(pop()!=str[j]){
                        flag=1;
                }
        }
        if(!flag){
                printf("It is a palindrome");
        }
        else{
               printf("It is not a palindrome");
        }
}
void push(char c){
        stack[++top]=c;
}
char pop(){
        char temp=stack[top];
        top--;
        return temp;
}