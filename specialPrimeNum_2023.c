#include <stdio.h>
#include <math.h>
/*
신기한 소수: 소수인데 1,2,...N자릿수가 모두 소수
N이 주어졌을 때, N자리 신기한 소수를 모두 찾아보자.

input: N (=[1,8])
output: N 자릿수의 신기한 소수
*/
void create_num(int,int);
int is_prime(int);

/* main method
*/
int main(){
    int N;
    scanf("%d",&N);

    // since the Nth digit num should also be prime num,
    // run the method with prime nums only
    int prime_num[]={2,3,5,7};

    for(int loc=0;loc<4;loc++){
        create_num(prime_num[loc],N);
    }

    return 0;
}

/* method that sets number for each digit
    does recursive call only if
        the created number is prime number
    @param num - number that has been created
    @param digit - loc of digit where method is deciding
*/
void create_num(int num, int digit){
    // base case, when the num is completed
    if(digit==1) printf("%d\n", num);

    int temp;
    for(int i=0;i<10;i++){
        temp=num*10+i;
        if(is_prime(temp)==1){
            create_num(temp,digit-1);
        }
    }
}

/* method that decides if the param is prime number
    @param num - number to discover
*/
int is_prime(int num){
    int sqrt_num=sqrt(num);
    for(int i=2;i<=sqrt_num;i++){
        if(num%i==0) return 0;
    }
    return 1;
}