#include<iostream>
using namespace std;


int partition(int elements[], int lowIndex, int highIndex){
    int v, i, j, temp;
    v = elements[lowIndex];
    i = lowIndex;
    j = highIndex + 1;

    do{
        do{
            i++;
        }while(elements[i] < v && i <= highIndex);

        do{
            j--;
        }while(v < elements[j]);
        if(i < j){
            temp = elements[i];
            elements[i] = elements[j];
            elements[j] = temp;
        }
    }while(i < j);

    elements[i] = elements[j];
    elements[j] = v;

    return j;
}

void quickSort(int elements[], int lowIndex, int highIndex){
    int j;
    if(lowIndex<highIndex){
        j = partition(elements, lowIndex, highIndex);
        quickSort(elements, lowIndex, highIndex - 1);
        quickSort(elements, lowIndex + 1, highIndex);
    }
}

int main(){
    int array[] = {3, 66, 8, 0, 1, 3, 4, 6};
    int size = 8;

    quickSort(array, 0, 7);

    for(int i = 0; i < size; i++){
        cout<<array[i]<<" "<<endl;
    }


    return 0;
}