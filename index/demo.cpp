#include<iostream>
using namespace std;


int demo(){
    int numberOfElements, key;
    cout<<"Enter size: ";
    cin>>numberOfElements;
    int elements[numberOfElements];

    for(int i = 0; i < numberOfElements; i++){
        cout<<"Set index: ";
        cin>>elements[i];
    }
    int mid, low, high = numberOfElements - 1, ret = 0;
    cout<<"Enter key for binary search>>>>"; cin>>key;

    
    while(high>=low){
        mid = (high + low) / 2;

        if(key == elements[mid]){
            return mid;
            break;
        }
        else if(elements[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        return -1;
    }




    if(ret == -1){
        cout<<key<<" not found"<<endl;
    }
    else{
        cout<<key<<" found at index "<<ret<<endl;
    }
    cout<<endl;

    for(int i=0; i< numberOfElements; i++){
        cout<<elements[i]<<" ";
    }
}

int main(){
    demo();

    return 0;
}