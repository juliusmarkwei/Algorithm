#include<iostream>
using namespace std;


class AlgorithmsForString : protected Program{
    protected:

        // Linear search algorithm
        void linearSearch(){
            takeInput();
            displayInput();
            cout<<"Enter key for linear search>>>>";
            cin>>key;
            for(int i=0; i<numberOfElements; i++){
                if(elements[i]==key){
                    cout<<"Found "<<key<<" at index "<<i<<endl;
                    break;
                }
            }cout<<key<<" was not found"<<endl;
        }

        // Bianry search algorithm
        void binarySearch(){
            takeInput();
            displayInput();
            int mid, low, high = numberOfElements - 1, ret = 0;
            cout<<"Enter key for binary search>>>>"; cin>>key;
            while(high>=low){
                mid = (high + low) / 2;
                if(elements[mid] < key){
                    low = mid + 1;
                }
                else if(elements[mid] > key){
                    high = mid - 1;
                }
                else{
                    ret = mid;
                    break;
                }
                ret = -1;
            }
            if(ret == -1){
                cout<<key<<" not found"<<endl;
            }
            else{
                cout<<key<<" found at index "<<ret<<endl;
            }
        }

        //Selection Sort
        void selectionSort(){
            takeInput();
            cout<<"UNSORTED";
            displayInput();
            int temp = 0, indexSmallest = 0;
            for(int i=0; i<numberOfElements - 1; ++i){
                indexSmallest =i;
                for(int j = i + 1; j < numberOfElements; ++j){
                    if(elements[j] < elements[indexSmallest]){
                        indexSmallest = j;
                    }
                }
                temp = elements[i];
                elements[i] = elements[indexSmallest];
                elements[indexSmallest] = temp;
            }cout<<endl;
            displayResult();
        }

        //Insertion sort
        void insertionSort(){
            takeInput();
            cout<<"UNSORTED";
            displayInput();
            int temp = 0, j, i;
            for(i = 1; i < numberOfElements; ++i){
                j = i;
                while(j > 0 && elements[j] < elements[j-1]){
                    temp = elements[j];
                    elements[j] = elements[j-1];
                    elements[j-1] = temp;
                    --j;
                }
            }
            displayResult();
        }

        //Nearly sorted
        void nearlySorted(){
            takeInput();
            
            displayInput();

        }

        //Shell sort
        void shellSort(){
            takeInput();
            cout<<"UNSORTED";
            displayInput();
            int startIndex, gap;
            int i = 0, j = 0, temp = 0;
            cout<<"Select gap: "; cin>>gap;
            cout<<"Input start index: "; cin>>startIndex;
            for(i = startIndex + gap; i < numberOfElements; i = i + gap){
                j = i;
                while(j - gap >= startIndex && elements[j] < elements[j - gap]){
                    temp = elements[j];
                    elements[j] = elements[j - gap];
                    elements[j - gap] = temp;
                    j = j - gap;
                }
            }
            displayInput();
        }

        //Quick sort
        int partition(int elements[], int lowIndex, int highIndex){
            int temp;
            
            int midpoint = lowIndex + (highIndex - lowIndex) / 2;
            int pivot = elements[midpoint];  // 4 is pivot 
            bool done = false;
            while(!done){
                while(elements[lowIndex] < pivot){  // array = [10, 2, 78, 4, 45, 32, 7, 11]
                    lowIndex += 1;
                }
                while(pivot < elements[highIndex]){
                    highIndex -= 1;
                }
                if(lowIndex >= highIndex){
                    done = true;
                }
                else{
                    temp = elements[lowIndex];
                    elements[lowIndex] = elements[highIndex];
                    elements[highIndex] = temp;

                    lowIndex += 1;
                    highIndex -= 1;
                }
            }

            return highIndex;

        }

        void quickSort(int elements[], int lowIndex, int highIndex){
            if(lowIndex >= highIndex){
                return;
            }
            int lowEndIndex = partition(elements, lowIndex, highIndex);

            quickSort(elements, lowIndex, lowEndIndex);
            quickSort(elements, lowEndIndex - 1, highIndex);

            displayResult();
        }

        // Merge Sort
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

        
        // Radix sort
        int getMax(int elements[], int elementSize){
            int max = elements[0];
            for(int i = 0; i < elementSize; i++){
                if(elements[i] > max){
                    max = elements[i];
                }
            }
            return max;
        }

        void countSort(int elements[], int elementSize, int exp){
            int output[elementSize];
            int i, count[10] = {0};

            // Store count of occurrences of count []
            for(i=0; i<elementSize; i++){
                count[(elements[i] / exp) % 10];
            }

            // Change count[i] so that count[i] now contains actual
            // position of this digit in output[]
            for(i = 0; i < 10; i++){
                count[i] += count[i - 1];
            }

            // Build the output array
            for(i = elementSize -1; i >= 0; i--){
                output[count[(elements[i] / exp) % 10] -1] = elements[i];
                count[(elements[i] / exp) % 10]--;
            }

            // Copy the output array into elements[], so that
            // elements[] now contains sorted numbers according to
            // current digits.
            for(i = 0; i < elementSize; i++){
                elements[i] = output[i];
            }
        }

        void radixSort(int elements[], int elementSize){
            // Find the maximum number to know number of digits
            int m = getMax(elements, elementSize);

            // Do counting sort for every digit. Note that instead of
            // passing digit number, exp is passed. exp is 10^i
            // where i is the current digit number
            for(int exp = 1; m / exp > 0; exp *= 10){
                countSort(elements, elementSize, exp);
            }

            // display results to user
            displayResult();
            
        }

};

int main(){


    return 0;
}