/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// Abishai Mathai, EECS 348 Lab5 Question 2

#include <stdio.h>
#include <stdlib.h>

# define SIZE 5
//printing array in readable format
void printarr(int ** arr){
    for(int row=0; row<SIZE; row++){
        for(int col=0; col<SIZE; col++){
            printf("%d\t",arr[row][col]);
        }
        printf("\n");
        }
}
void add(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE], int **addResult){
    for(int row=0; row<SIZE; row++){
        for(int col=0; col<SIZE; col++){
            addResult[row][col]=arr1[row][col]+arr2[row][col];
        }
    }

}

void transpose(int arr1[SIZE][SIZE], int **transResult){
     for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            // Transpose the element
            transResult[col][row] = arr1[row][col];
        }
    }

}

void multiply(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE], int **multiResult){
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            for (int k = 0; k < SIZE; k++) { 
                multiResult[row][col] += arr1[row][k] * arr2[k][col]; 
            }}
}
}
int main() {
int m1[SIZE][SIZE] = {
{1, 2, 3, 4, 5},
{6, 7, 8, 9, 10},
{11, 12, 13, 14, 15},
{16, 17, 18, 19, 20},
{21, 22, 23, 24, 25}
};
int m2[SIZE][SIZE] = {
{25, 24, 23, 22, 21},
{20, 19, 18, 17, 16},
{15, 14, 13, 12, 11},
{10, 9, 8, 7, 6},
{5, 4, 3, 2, 1}
};

int numRowsm1 = sizeof(m1) / sizeof(m1[0]);
int numColsm1 = sizeof(m1[0]) / sizeof(m1[0][0]);

int numRowsm2 = sizeof(m2) / sizeof(m2[0]);
int numColsm2 = sizeof(m2[0]) / sizeof(m2[0][0]);

int **resultarr=(int **)malloc(SIZE*sizeof(int));
for(int i=0; i<SIZE;i++){
    resultarr[i]=(int *)malloc(SIZE*sizeof(int));
}

if ((numRowsm1==numRowsm2) & (numColsm1==numColsm2)){
    add(m1,m2,resultarr);
    printf("The result of addition is:\n");
    printarr(resultarr);
}
else{
    printf("The matrices dont have matching orders");
}
transpose(m1,resultarr);
printf("The result of transpose is:\n");
printarr(resultarr);

if (numColsm1==numRowsm2){
    for(int row=0; row<SIZE; row++){
        for(int col=0; col<SIZE; col++){
            resultarr[row][col]=0;
        }}
    multiply(m1,m2,resultarr);
    printf("The result of multiplication is:\n");
    printarr(resultarr);
}

}
