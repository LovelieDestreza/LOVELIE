#include <iostream>

using namespace std;

 int myArray[30];
 int numElem = 0;
 int maxElem = 20;

 void bubbleSort(){
    int i, j;
    bool swapped;
    for(int i =0; i < numElem - 1; i++){
        swapped = false;
        for(j = 0; j < numElem - i -1; j++){
            if(myArray[j] > myArray[j+1]){
                swap(myArray[j], myArray[j+1]);
                swapped = true;
            }
        }

        if(swapped == false){
            break;
        }
    }
}

 void traverseArray() {
     cout << "showing elements in my array \n";
       for(int i = 0; i< maxElem; i++){
         cout<< to_string(myArray[i]) + " | ";
     }
     cout << "\n";
 }
 
 string insertAtTheEnd(int num){
     if(numElem != maxElem){
         myArray[numElem] =num;
         numElem++;
         return "An element is successfully inserted at the end! \n";
     }
     
     return "The array is full. Please remove elements before inserting new one. \n";
 }
 
 string insertAtTheBeginning(int num){
     if(numElem != maxElem){
         for(int i= numElem; i >= 0; i--){
             myArray[i+1] = myArray[i];
             
         }
         
         myArray[0] = num;
         numElem++;
         return  "An element is successfully inserted at the beginning! \n";
     }
     
     return "The array is full. Please remove elements before inserting new one. \n";
     
 }
 
 string insertAtTheGivenPosition(int num, int ElementAfter){
     if(numElem != maxElem){
         int position;
         for(int i = 0; i <= maxElem; i++){
             if(myArray [i] == ElementAfter){
             position = i;
             break;
         }
     }
     
     for(int i = numElem; i>+position; i--){
         myArray[i+1] = myArray[i];
     }
     myArray[position +1]= num;
     numElem++;
     return "An element is successfully inserted at the specified location! \n";
     
     }
     
     
     return "The array is full. Please remove elements before inserting new one. \n";
}

string insertAtSortedArray(int num){
    if(numElem != maxElem){
        bubbleSort();
        int position;
    for(int i = 0; i < numElem; i++){
        if(num < myArray[i]){
            position = i;
            break;
        }
    }

    for(int i = numElem; i>=position; i--){
        myArray[i+1] = myArray[i];
    }

    myArray[position] = num;
    numElem++;
    return "An element is succesfully inserted at a sorted array! \n";
    }

    return "The Array is full. Please remove elements before inserting new one. \n";
}
 
 string deleteFromTheEnd(){
    if(numElem != 0){
        numElem--;
        return "An element has been deleted from the end!";
    }
    return "The array is underflow! Delete is not possible";
}

string deleteFromTheBeginning(){
    if(numElem != 0){
        for(int i = 0; i<= numElem; i++ ){
        myArray[i] = myArray[i+1];
        }
        numElem--;
        return "An element has been deleted from the beginning!";
    }
    return "The array is underflow! Delete is not possible";
}

string deleteFromGivenElement(int element){
    if(numElem != 0){
        int index;
        for(int i = 0; i <= numElem; i++){
            if(myArray[i] == element){
                index = i;
                break;
            }
        }

        for(int i = index; i <= numElem; i++){
            myArray[i] = myArray[i+1];
        }
        numElem--;
        return to_string(element) + "has been deleted!";

    }
    return "The array is underflow! Deleted is not possible";
    
}

int binarySearch(int num, int lowest, int highest){
    while(lowest <= highest){
        int middle = lowest + (highest - lowest) /2;

        if(myArray[middle] ==num){
            lowest = middle + 1;
        }else{
            highest = middle - 1;
        }
    }
    return -1;
}

int main(){
    
   cout << insertAtTheBeginning(3);
    traverseArray();
   cout << insertAtTheEnd(7);
    traverseArray();
   cout << insertAtTheEnd(9);
    traverseArray();
   cout << insertAtTheBeginning(20);
    traverseArray();
   cout << insertAtTheGivenPosition(37, 7);
    traverseArray();
   cout << insertAtTheBeginning(256);
    traverseArray();
   cout << insertAtTheGivenPosition(128, 9);
    traverseArray();
   cout << insertAtTheBeginning(19);
    traverseArray();
    
   cout << insertAtSortedArray(3);
    traverseArray();
   cout << insertAtSortedArray(30);
    traverseArray();
   cout << insertAtSortedArray(38);
    traverseArray();
   cout << insertAtSortedArray(19);
    traverseArray();

   cout << deleteFromTheBeginning();
   traverseArray();
   cout << deleteFromTheBeginning();
    traverseArray();
   cout << deleteFromTheEnd();
    traverseArray();
   cout << deleteFromTheEnd();
    traverseArray();
   cout << deleteFromGivenElement(20);
    traverseArray();
   cout << deleteFromGivenElement(38);

    traverseArray();

    cout << binarySearch (30, 3, numElem);

    return 0;
}
