#include <iostream>

using namespace std;


void quickSort(int arr[], int start_pos, int end_pos){
   int pivot = arr[start_pos];
   int l = start_pos;
   int r = end_pos;

   while(l <= r){
      while(arr[l] < pivot) l++;
      while(arr[r] > pivot) r--;

      if(l <= r){
         swap(arr[l], arr[r]);
         l++;
         r--;
      }
   }

   if(start_pos < r) quickSort(arr, start_pos, r);
   if(l < end_pos) quickSort(arr, l, end_pos);
}



int absoluteValue(int value){
   if(value < 0){
      return value * -1;
   }
   return value;
}


int findShortestDistance(int arr1[], int arr2[], int lengthArray1, int lengthArray2){
   int i = 0;
   int j = 0;

   int shortest_distance = absoluteValue(arr1[i] - arr2[j]);

   while(i < lengthArray1 && j < lengthArray2){
      int new_distance = absoluteValue(arr1[i] - arr2[j]);

      if(new_distance < shortest_distance){
         shortest_distance = new_distance;
      }

      if(arr1[i] < arr2[j]){ 
         i++; 
      }else{ 
         j++; 
      }
   }

   return shortest_distance;
}



int main(){

   int array1[] = {1, 2, 3, 5, 7,-1,-8,5,-4,-9};
   int array2[] = {10, 20, 30, 40, 26,6,-12,45,99,100};
   
   int lengthArray1 = sizeof(array1)/sizeof(array1[0]);
   int lengthArray2 = sizeof(array2)/sizeof(array2[0]);

   quickSort(array1,0,lengthArray1-1);
   quickSort(array2,0,lengthArray2-1);

   int shortest_distance = findShortestDistance(array1,array2, lengthArray1, lengthArray2);

   cout << "A menor distancia entre o 1° array e o 2° array é " << shortest_distance;

   return 0;
}