/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// Abishai Mathai, EECS 348 Lab5 Question 1
#include <stdio.h>
#include <stdlib.h>

//takes in pointers as arguments so we can access them outside fucntion scope
void salesStatistics(float *arrayFloats,int size,float *maxArr, float *minArr,float *average,
int *maxIndex, int *minIndex){
    // cumulative sum for finding average
    float cumSum=0;
    // finding max, min, and cumulative sum
    for(int i=0; i<size;i++){
        //check so we dont go out of bounds
        if (i+1==size){
        // do nothing
        }
        else{
            cumSum+=arrayFloats[i];
            if (arrayFloats[i+1]>*maxArr){
                *maxArr=arrayFloats[i+1];
                *maxIndex=i+1;
            }
            if (arrayFloats[i+1]<*minArr){
                *minArr=arrayFloats[i+1];
                *minIndex=i+1;
            }
        }
    }
    *average=cumSum/size;
}

void sixMonthAverage(float *arrayFloats, int size, int windowSize, float *slideAverage){
    float sum=0;
    for(int i=0; i<windowSize; i++){
        sum+=arrayFloats[i];
    }
    //initialise the first sum
    slideAverage[0]=sum/windowSize;
    // subtract the first element and add the last element in the sliding window
    for(int i=1; i<size-windowSize+1; i++){
        sum=sum-arrayFloats[i-1]+arrayFloats[i+windowSize-1];
        slideAverage[i]=sum/windowSize;
    }

}

void bubbleSortDescending(float *arrayFloats,char *monthNames[], int size){
    for(int j=0; j<size-1; j++){
        for(int i=0; i<size-1-j; i++){
            if (arrayFloats[i]<arrayFloats[i+1]){
                float temp1=arrayFloats[i];
                char *temp2=monthNames[i];
                arrayFloats[i]=arrayFloats[i+1];
                monthNames[i]=monthNames[i+1];
                arrayFloats[i+1]=temp1;
                monthNames[i+1]=temp2;
            }
    }
    }
}

int main()
{
    // want to get input from user on 12 months
    int numberOfElements=12;
    
    // type cast malloc to float pointer
    float *arr=(float *)malloc(numberOfElements*sizeof(float));
    
    // This array contains garbage values, want to intialise the data
    for(int i=0;i<numberOfElements;i++){
        printf("Enter your data per month: ");
        scanf(" %f",&arr[i]);
    }

    //copy the array
    float *copyArr=(float *)malloc(numberOfElements*sizeof(float));
    for (int i=0;i<numberOfElements;i++){
        copyArr[i]=arr[i];
    }
     
    char *months[12]={"January","February","March","April","May","June","July","August","September","October",
        "November","December"};
   
   // string pointer for months
   /*
    char *months[3]={"January","February","March"};*/
    printf("Monthly Sales Report for 2024\n");
    printf("Month\t Sales\n");
    for(int i=0; i<numberOfElements;i++){
        printf("%s\t%f\n",months[i],arr[i]);
    }

    // intialise max,min and indices variables
    float maxArr=arr[0];
    int maxArrIndex=0;
    float minArr=arr[0];
    int minArrIndex=0;
    float average=0;
    int windowSize=6;
    float movingAverage[7];
    
    printf("\n");
    // call and print 
    salesStatistics(arr,numberOfElements,&maxArr,&minArr,&average,&maxArrIndex,&minArrIndex);
    printf("Sales summary report:\n");
    printf("Maximum sales:%f %s\n",maxArr,months[maxArrIndex]);
    printf("Minimum sales:%f %s\n",minArr,months[minArrIndex]);
    printf("Average sales:%f\n",average);

    printf("\n");

    sixMonthAverage(arr,numberOfElements,windowSize,movingAverage);
    printf("Six month Moving Average Report\n");
    printf("January to June: %f\n",movingAverage[0]);
    printf("February to July: %f\n",movingAverage[1]);
    printf("March to August: %f\n",movingAverage[2]);
    printf("April to September: %f\n",movingAverage[3]);
    printf("May to October: %f\n",movingAverage[4]);
    printf("June to November: %f\n",movingAverage[5]);
    printf("July to December: %f\n",movingAverage[6]);
    free(arr);
    printf("\n");
    bubbleSortDescending(copyArr, months, numberOfElements);
    printf("Sales report (highest to lowest):\n");
    printf("Month\tSales\n");
    for(int i=0; i<numberOfElements; i++){
        printf("%s\t%f\n",months[i],copyArr[i]);
    }
    free(copyArr);
    }
    
