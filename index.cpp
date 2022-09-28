#include<iostream>
#include<windows.h>
#include<array>
using namespace std;

class Program{
    public:
    int numberOfElements, key;
    int elements[0];
        void main(){
            cout<<"\n\t\t*****************************************************************************"<<endl;
            cout<<"\n\t\t\t\t\tSEARCHING AND SORTING ALGORITHMS"<<endl;
            cout<<"\n\t\t*****************************************************************************"<<endl;
            cout<<"\n";
        }

        void welcomeMessage(){
            cout<<"The Algorithms available in this Program are:"<<endl;
            cout<<"Searching Algorithms"<<endl;
            cout<<"1. Linear Search"<<endl;
            cout<<"2. Binary Search"<<endl<<endl; Sleep(3000);
            cout<<"Sorting Algorithms"<<endl;
            cout<<"1. Selection Sort"<<endl;
            cout<<"2. Insertion Sort"<<endl;
            cout<<"3. Nearly Sorted"<<endl;
            cout<<"4. Shell Sort"<<endl;
            cout<<"5. Quick Sort"<<endl;
            cout<<"6. Merge Sort"<<endl;
            cout<<"7. Radix Sort"<<endl<<endl; Sleep(10000);
            cout<<"Do you want to proceed with Sorting or Searching Algorithm?"<<endl;
            cout<<"Enter 0 for Sorting or 1 for Searching Algorithm."<<endl;
        }
        
        void takeInput(){
            cout<<"Enter the number of elements in the Array to be processed >>>>>> ";
            cin>>numberOfElements;
            for(int i=0; i<numberOfElements; i++){
                cout<<"Element at index "<<i<<" "; cin>>elements[i];
            }
            cout<<endl;
        }

        void displayInput(){
            cout<<"\nElements to be taken as inputs: [ ";
            for(int i=0; i<numberOfElements; i++){
                cout<<elements[i]<<" ";
            }cout<<"]"<<endl;
        }
};

class Algorithms : public Program{
    public:

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
                for(int j = i + 1; j < numberOfElements; ++j){
                    if(elements[j] < elements[indexSmallest]){
                        indexSmallest = j;
                    }
                }
                temp = elements[i];
                elements[i] = elements[indexSmallest];
                elements[indexSmallest] = temp;
            }cout<<endl;
            cout<<"\nSORTED [ ";
            for(int i=0; i < numberOfElements; i++){
                cout<<elements[i]<<" ";
            }cout<<"]";
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
            cout<<"\nSORTED [ ";
            for(int i=0; i < numberOfElements; i++){
                cout<<elements[i]<<" ";
            }cout<<"]";
        }

        //Nearly sorted
        void nearlySorted(){
            takeInput();
            cout<<"UNSORTED";
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
            cout<<"\nSORTED [ ";
            for(int i=0; i < numberOfElements; i++){
                cout<<elements[i]<<" ";
            }cout<<"]";
        }

        //Quick sort
        // int lowIndex, highIndex;
        int partition(int elements[], int lowIndex, int highIndex){
            // takeInput();
            // cout<<"UNSORTED";
            // displayInput();
            int temp;
            // cout<<"Select a low index for partition ";cin>>lowIndex;
            // cout<<"Select a high index for partition ";cin>>highIndex;
            int midpoint = lowIndex + (highIndex - lowIndex) / 2;
            int pivot = elements[midpoint];
            bool done = false;
            while(!done){
                while(elements[lowIndex] < pivot){
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

            // cout<<"\nSORTED [ ";
            // for(int i=0; i < numberOfElements; i++){
            //     cout<<elements[i]<<" ";
            // }cout<<"]";
        }

};

// class AlgorithmSelector : public Algorithm{
//     public:
//         do{
//             while(){

//             }

//         }while()
// };

int main(){
    Algorithms m;
    // m.project();
    // m.welcomeMessage();
    // m.partition();
    int elements[8] = {10, 2, 78, 4, 45, 32, 7, 11};
    m.quickSort(elements, 0, 8-1);
    cout<<"\nSORTED [ ";
    for(int i=0; i < 8; i++){
        cout<<elements[i]<<" ";
    }cout<<"]";

    return 0;
};
