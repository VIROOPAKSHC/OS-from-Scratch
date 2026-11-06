	Running a .c file:
1. Preprocessing: Obeys the `#` directives
2. Compiling: Converts to *object code*, but not ready to be run yet.
3. Linking: Linker combines the *object code* and any addnl needed code.

Simple cmd: `gcc file.c -o file && ./file`
**Macros:** `#define <CONST-NAME> <const-value>`
Ex: `#define INCHES_PER_LB 166`
> To define a float, use f as a suffix to the number (decimal). If not, it is interpreted as a double.

Arrays cannot be a return type in C language. Pass them by reference and do the manipulation and get the output from one of the arguments.

int arr[10];

arr       // pointer to first element: int *
&arr      // pointer to the entire array: int (\*)[10]

> C receives pointers to the first elements of the array, not the copy of the array. Hence, there is no pass-by-reference like in C++. But simply a pointer passing. This is called **decayed pointer** of an array.

```c
#include<stdio.h>
void reverse(int* arr, int* rev){
 int i=0;
 int j=9;
 for(i=0;i<10;i++){
  rev[j] = arr[i];
  j--;
 }
}

int main(){
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
```

`static` - retains the storage location of a variable throughout the program.
> different from `const`, and does not mean it should have the same value throughout the program.

external variables - are both static and File scoped.

