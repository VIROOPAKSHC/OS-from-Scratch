#include<stdio.h>

void pay_amount(int dollars, int *twenties, int *tens,
    int *fives, int *ones){
        *twenties = dollars/20;
        dollars %= 20;
        *tens = dollars/10;
        dollars %= 10;
        *fives = dollars/5;
        dollars %= 5;
        *ones = dollars/1;

}

int main(void){
    int total = 2016;
    int tw,te, fi, on;
    pay_amount(total,&tw,&te,&fi,&on);
    printf("%d %d %d %d \n",tw,te,fi,on);
    return 0;
}