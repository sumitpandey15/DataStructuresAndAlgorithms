/* Category -  Data Structure
   Sub-category -  Array/2D Array
   
   By - Sumit Pandey
   When - May 24, 2017
   What - Prints numbers of a 2D array in spiral order
   
   E.g. -

   Input -
   15 8 7 12 18
   8 10 23 6 22
   4 21 45 7 27
   90 1 34 76 11
   2 8 89 23 41

   Output - 15 8 7 12 18 22 27 11 41 23 89 8 2 90 4 8 10 23 6 7 76 34 1 21 45
*/

#include <iostream>
using namespace std;

namespace{
    enum Dimention{
      row = 5,
      col = 5
    };
    
}

//Input - an rowxcol 2D array
void printSpiral(int arr[row][col], int row, int col){
   int k = 0; //Start row index
   int l = row; //End row index
   int m = 0; //Start col index
   int n = col;   //End col index
    
   while( (k<l) && (m < n) ){
       for (int i = m; i < n; i++)
        std::cout <<arr[k][i] <<" ";
    
       k++;
       
       for (int i = k; i < l; i++)
        std::cout <<arr[i][n-1] <<" ";
        
       n--;
       
       if (k<l){
        for (int i = n-1; i >= m; i--)
            std::cout <<arr[l-1][i] <<" ";           
       }
       l--;
       
       if (m<n){
        for (int i = l-1; i >= k; i--)
            std::cout <<arr[i][m] <<" ";           
       }
       m++;
    
   }
    
}


//Input - an rowxcol 2D array
//Recursive version
void printSpiralRecursive(int arr[row][col], int rowStart, int rowEnd, int colStart, int colEnd){

   if (rowEnd < 0 || colEnd < 0)
        return;

   int k = rowStart; //Start row index
   int l = rowEnd; //End row index
   int m = colStart; //Start col index
   int n = colEnd;   //End col index
    
   for (int i = m; i < n; i++)
    std::cout <<arr[k][i] <<" ";

   k++;
   for (int i = k; i < l; i++)
    std::cout <<arr[i][n-1] <<" ";
    
    n--;    

   if (k<l){
    for (int i = n-1; i >= m; i--)
        std::cout <<arr[l-1][i] <<" ";           
   }
   l--;
   if (m<n){
    for (int i = l-1; i >= k; i--)
        std::cout <<arr[i][m] <<" ";           
   }
   m++;
   printSpiralRecursive(arr, rowStart+1,rowEnd-1, colStart+1, colEnd-1);

}


int main() {

int arr[row][col] = {    {15, 58, 7, 12, 18},
                         {8, 10, 53, 6, 22},
                         {4, 21, 45, 70, 27},
                         {90, 1, 34, 76, 11},
                         {2, 80, 89, 23, 41}
    };
 
    printSpiral(arr, row, col);
    cout <<std::endl;
    printSpiralRecursive(arr, 0, row, 0, col);
	return 0;
}
