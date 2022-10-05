#include<iostream>
using namespace std;

void merge(int numbers[], int i, int j, int k){
            int mergdSize = k - i + 1;
            int mergePos = 0;
            int leftPos = 0;
            int rightPos = 0;
            int mergedNumbers[mergdSize];

            leftPos = i;
            rightPos = j + 1;

            while(leftPos <= j && rightPos <= k){
                if(numbers[leftPos] <= numbers[rightPos]){
                mergedNumbers[mergePos] = numbers[leftPos];
                ++leftPos;
                }
                else{
                mergedNumbers[mergePos] = numbers[rightPos];
                ++rightPos;
                }
                ++mergePos;
            }

            while(leftPos <= j){
                mergedNumbers[mergePos] = numbers[leftPos];
                ++leftPos;
                ++rightPos;
            }

            while(rightPos <= k){
                mergedNumbers[mergePos] = numbers[rightPos];
                ++rightPos;
                ++mergePos;
            }

            for(mergePos = 0; mergePos < mergdSize; ++mergePos){
                numbers[i + mergePos] = mergedNumbers[mergePos];
            }
        }

        void mergeSort(int numbers[], int i, int k){
            int j = 0;

            if(i < k){
                j = (i + k) / 2;

                mergeSort(numbers, i, j);
                mergeSort(numbers, j + 1, k);

                merge(numbers, i, j, k);
            }
        }


int main(){
    int array[] = {3, 66, 8, 0, 1, 3, 4, 6};
    int size = 8;

    mergeSort(array, 0, 7);

    for(int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }


    return 0;
}