#include<iostream>
#include<windows.h>
#include<array>
using namespace std;

class Program{
    protected:
    int numberOfElements;
    int key;
    int elements[0];
        void header(){
            cout<<"\n\t\t*****************************************************************************"<<endl;
            cout<<"\n\t\t\t\t\tSEARCHING AND SORTING ALGORITHMS"<<endl;
            cout<<"\n\t\t*****************************************************************************"<<endl;
            cout<<"\n";
        }

        void welcomeMessage(){
            cout<<"\t\t\t\tBelow Are The Type Algorithms Available in This Program"<<endl;
            cout<<"\t\t\t\t1. Searching Algorithms"<<endl;
            cout<<"\t\t\t\t2. Sorting Algorithms"<<endl;
            cout<<endl;
        }
            
           
        void searchingAlgorithm(){
            cout<<"Searching Algorithms"<<endl;
            cout<<"1 Linear Search"<<endl;
            cout<<"2 Binary Search"<<endl;
            cout<<"0. Go Back"<<endl;
        }

        void sortingAlgorithm(){
            cout<<"Sorting Algorithms"<<endl;
            cout<<"1. Selection Sort"<<endl;
            cout<<"2. Insertion Sort"<<endl;
            cout<<"3. Nearly Sorted"<<endl;
            cout<<"4. Shell Sort"<<endl;
            cout<<"5. Quick Sort"<<endl;
            cout<<"6. Merge Sort"<<endl;
            cout<<"7. Radix Sort"<<endl;
            cout<<"0. Back"<<endl;
        }
        
        void takeInput(){
            cout<<"Enter the number of elements in the Array to be processed >>>>>> ";
            cin>>numberOfElements;
            elements[numberOfElements];
            for(int i=0; i<numberOfElements; i++){
                cout<<"Element at index "<<i<<": "; cin>>elements[i];
            }
            cout<<endl;
        }

        void displayInput(){
            cout<<"\nElements to be taken as inputs: [ ";
            for(int i=0; i<numberOfElements; i++){
                cout<<elements[i]<<" ";
            }cout<<"]"<<endl;
        }

        void displayResult(){
            cout<<"\nSORTED: [ ";
            for(int i=0; i<numberOfElements; i++){
                cout<<elements[i]<<" ";
            }cout<<"]"<<endl;
        }
};

class AlgorithmsForInt : protected Program{
    protected:

        // Linear search algorithm
        void linearSearch(){
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
            int mid, low, high = numberOfElements - 1, ret = -1;
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
                }
            }

            if(ret == -1){
                cout<<key<<" not found"<<endl;
            }
            else{
                cout<<key<<" found at index "<<ret<<endl;
            }
            cout<<endl;
            
        }

        //Selection Sort
        void selectionSort(){
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
        }

        //Insertion sort
        void insertionSort(){
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
        }

        //Nearly sorted
        void nearlySorted(){
            // codes goes here

        }

        //Shell sort
        void shellSort(){
            for(int gap = numberOfElements/2; gap > 0; gap /= 2){
            for(int j = gap; j < numberOfElements; j++){
            int temp = elements[j];
            int i = 0;

            for(i = j; (i >= gap) && (elements[i - gap] > temp); i -= gap){
                elements[i] = elements[i - gap];
            }
            elements[i] = temp;
            }
    }
            
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

class Home: protected AlgorithmsForInt{
    public:

    void mainProgramControl(){
        header();
        Sleep(3000);
        welcomeMessage();
        int choice;
        int option, decision;
        string proceed;
        do{
            cout<<"Do you want to proceed with Sorting or Searching Algorithm?"<<endl;
            cout<<"Enter 0 for Sorting or 1 for Searching Algorithm >>>> ";
            cin>>option;
            cout<<endl<<endl;

            // checking user input validity
            while(option != 0 && option != 1){
                cout<<"Please enter a value between 0 and 1: ";
                cin>>option;
            }

            switch(option){
                case 0:
                    do{
                        searchingAlgorithm();
                        cout<<endl;
                        cout<<"Select any of the Searching Algorithms above: ";
                        cin>>choice;
                        cout<<endl;

                        while(choice < 0 || choice > 2){
                            cout<<"Please enter a value between 0 and 2: ";
                            cin>>choice;
                        }
                        switch(choice){
                            
                            case 1:
                                while(proceed != "N"){
                                cout<<"Linear search algorithm"<<endl;
                                takeInput();
                                displayInput();
                                linearSearch();

                                cout<<"Do you want to continue with Linear Search? (Y or N): ";
                                cin>>proceed;
                                cout<<endl;
                                }
                                break;
                                

                            case 2:
                                proceed = "Y";
                                while(proceed == "Y"){
                                cout<<"Binary search algorithm"<<endl;
                                takeInput();
                                displayInput();
                                binarySearch();

                                cout<<"Do you want to continue with Linear Search? (Y or N): ";
                                cin>>proceed;
                                cout<<endl;
                                }
                                break;

                        }
                    }while(choice != 0);
                    break;

                case 1:
                    do{
                        sortingAlgorithm();
                        cout<<endl;
                        cout<<"Select any of the Sorting Algorithm above: ";
                        cin>>choice;
                        cout<<endl;

                        while(choice < 0 || choice > 7){
                            cout<<"Please enter a value between 0 and 7: ";
                            cin>>choice;
                        }

                        switch(choice){
                            case 1:
                                proceed = "Y";
                                while(proceed == "Y"){
                                cout<<"Selection sort algorithm"<<endl;
                                takeInput();
                                displayInput();
                                selectionSort();
                                displayResult();

                                cout<<"Do you want to continue with Linear Search? (Y or N): ";
                                cin>>proceed;
                                cout<<endl;
                                }
                                break;

                            case 2:
                                proceed = "Y";
                                while(proceed == "Y"){
                                cout<<"Insertion sort algorithm"<<endl;
                                takeInput();
                                displayInput();
                                insertionSort();
                                displayResult();

                                cout<<"Do you want to continue with Insertion Sort? (Y or N): ";
                                cin>>proceed;
                                cout<<endl;
                                }
                                break;

                            case 3:
                                proceed = "Y";
                                while(proceed == "Y"){
                                cout<<"Nearly sort algorithm"<<endl;
                                takeInput();
                                displayInput();
                                nearlySorted();
                                displayResult();

                                cout<<"Do you want to continue with Nearly Sort? (Y or N): ";
                                cin>>proceed;
                                cout<<endl;
                                }
                                break;

                            case 4:
                                proceed = "Y";
                                while(proceed == "Y"){
                                cout<<"Shell sort algorithm"<<endl;
                                takeInput();
                                displayInput();
                                shellSort();
                                displayResult();

                                cout<<"Do you want to continue with Shell Sort? (Y or N): ";
                                cin>>proceed;
                                cout<<endl;
                                }
                                break;

                            case 5:
                                proceed = "Y";
                                while(proceed == "Y"){
                                cout<<"Quick sort algorithm"<<endl;
                                int elements[0], lowIndex, highIndex;
                                takeInput();
                                displayInput();
                                cout<<"Set low index: ";
                                cin>>lowIndex;
                                cout<<"Set high index: ";
                                cin>>highIndex;
                                quickSort(elements, lowIndex, highIndex);
                                displayResult();

                                cout<<"Do you want to continue with Quick Sort? (Y or N): ";
                                cin>>proceed;
                                cout<<endl;
                                }
                                break;
                        }

                    }while(choice != 0);
            }


        }while(option == 0 || option == 1);
    }
};

int main(){
     Home home;
     home.mainProgramControl();

    // menu.numberOfElements;
    // cout<<"Enter the number of elements in the Array to be processed >>>>>> ";
    // cin>>menu.numberOfElements;
    // alg.elements[menu.numberOfElements]; 
    // for(int a=0; a<menu.numberOfElements; a++){
    //     cout<<"Element at index "<<a<<": "; 
    //     cin>>menu.elements[a];
    // }

    
    

    return 0;
};
