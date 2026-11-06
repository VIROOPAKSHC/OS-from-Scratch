
// Written by: Viroopaksh Chekuri

/*Fun*/

#include<stdio.h>
#define FRACTION 4.0f/3.0f
#define PI 3.14f
int func(int x){
return 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6;
}

int func2(int x){
 int d1=(x%10);
 x=x/10;
 int d2=(x%10);
 x=x/10;
 int d3=(x%10);
 if(d3==0){
  return d1*10+d2;
 }
 else{

  return d1*100+d2*10+d3;
 }

}

void reverse(int* arr, int* rev){
 int i=0;
 int j=9;
 for(i=0;i<10;i++){
  rev[j] = arr[i];
  j--;
 }
}

int main(){
// float R=10;
//printf("Volume = %f\n cubic meters", FRACTION*PI*R*R*R);
//int x;
//printf("Enter x:\n");
//scanf("%d",&x);
// printf("f(x) = %3.2f\n",(float)func(x));
//printf("Reversed number : %d\n",func2(x));
 int arr[10];
 int i=0;
 printf("Enter 10 numbers : ");
 for(i=0;i<10;i++){
  scanf("%d", &arr[i]);
 }
 int rev_arr[10];
 reverse(arr, rev_arr);
 printf("Reversed : ");
 for(i=0;i<10;i++){
 printf("%d ",rev_arr[i]);
 }
 printf("\n");

 return 0;
}
