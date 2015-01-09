/*
   2012-5-21 Google面试第三轮   
   
   给出表达式，求最后的值  +- /* () 
   思路：
       ) 不入栈
       遇到 ),就计算当前 ( ) 内的值，并弹出 (
       num_stack - 存储数字 
       op_stack -- 存储(及+ - * /
       op需要向前看一位 ,如果后面的优先级较高的话，就先入栈；
            否则，就计算前面的数字

   Test Case:
input: 7+8*5*(9-8) 
output:47 
7*8+9
(((7*8+9))) 
7*(9-8)

6*((5-4)+(7-6))

7+8*(9-5)

7+8*9
(((7+8*9))) 

(7+8*2)*2

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double operate(double ,double,char);
double num_stack[1000];
int ns = 0 ;
char op_stack[1000];
int ops = 0;
bool isNumber(char c ){
    if( c >= '0' && c<='9') return true;
    return false;
}
bool isOp(char c){
    if( c == '+' || c == '-' || c=='*' || c=='/' ) return true;
    return false;
}
void calcTop2(){
    char op = op_stack[--ops];
    double t1 = num_stack[ns-1];
    double t2 = num_stack[ns-2];
    ns = ns-2;

    double t3 = operate(t1,t2,op);
    num_stack[ns++] = t3; 
}
//  a - new op ; b - old op
bool isReadyToCalc(char a,char b){
    switch(b){
        case '(':
            return false;
            break;
        case '+':
        case '-':
            return (a=='-' || a=='+');
            break;
        case '*':
        case '/':
            return true;

    }
}
double operate(double t1,double t2,char op){
    if(op == '+') return t1+t2;
    if(op == '-') return t2- t1;
    if(op == '*') return t1*t2;
    if(op == '/') return t2/t1;
}
char* condense(char *exp){
    int i = 0 , j = 0 ; 
    while(exp[i] != 0 ){
        while(exp[i] != 0 && exp[i] == ' ') i++ ;
        printf("%c" , exp[i]) ;
        if(exp[i] != 0 ) exp[j++]=exp[i++];
    }
    exp[j] = 0 ;
    return exp;
}
double calc(char *exp){
    int j = 0 ; 
    condense(exp);
    int len = strlen(exp);

    printf("len = %d\n",len);
    int i = 0; 
    while(i<len){
        if(isNumber(exp[i])){
            int tmp = exp[i] - '0' ; 
            i++;
            while(i<len && isNumber(exp[i])) {
                tmp = 10*tmp + (exp[i] - '0');
                i++;
            }
            num_stack[ns++] = tmp;
            if( i>= len) break;
        }
        if(isOp(exp[i])){
            if(ops == 0 ||! isReadyToCalc(exp[i],op_stack[ops-1])) {
                op_stack[ops++] = exp[i];
            }else{
                printf("calc op = %c\n",exp[i]);
                calcTop2(); 
                op_stack[ops++] = exp[i];
            }
        }else if(exp[i] == '('){
            op_stack[ops++] = '(';
        }else if(exp[i] == ')'){
            //开始计算这个()内的值
            while(op_stack[ops-1] != '('){
                calcTop2();
            }
            ops--; //pop ( 
        }else{
        }
        i++;
    }
    while(ops>0){
        char  op = op_stack[ops-1];
        if( op == '(' ) { ops--;continue;}
        calcTop2();
    }   
    printf("num_stack lenght = %d\n",ns);
    return num_stack[0];
}
int main(){
    char exp[1000] = "";
    while(true){
        ns = 0 ;
        ops = 0; 
        gets(exp);
        printf("\t%.2lf\n",calc(exp));
    }
    return 0;
}
