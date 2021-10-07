#include <iostream>
#include <vector>
#include "matrix.hpp"

// Implement the functions here
// Remember to use auto and ranged for-loops when they can be used!

// Function reads input from user to n x n matrix,
// one number at a time.
Matrix ReadMatrix(int n){
    int input;
    std::vector<std::vector<int>> matrix(n,std::vector<int>(n));
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++){
            std::cin >> input;
            matrix[i][j] = input;
        }
    }    
    return matrix;
}

// Function rotates n x n matrix 90 degrees clockwise
// and stores it to a new matrix that it returns
Matrix Rotate90Deg(const Matrix & matrix){
    int n = matrix.size();
    std::vector<std::vector<int>> temp(n,std::vector<int>(n));

    for (int i=0; i < n; i++) {
        for (int j=0; j<n; j++){
            temp[i][j] = matrix[i][j];
        }
    }    

    for (int i=0; i< n/2; ++i) {
        for (int j=i; j< n-1-i; ++j){
            int tmp = temp[i][j];
            temp[i][j] = temp[n-1-j][i];
            temp[n-1-j][i] = temp[n-1-i][n-1-j];
            temp[n-1-i][n-1-j] = temp[j][n-1-i];
            temp[j][n-1-i] = tmp;
        }
    }
    
    return temp;
}

/* Function prints n x n matrix to standard output:
 * e.g. when n = 3 and the matrix' rows are all 1,2,3:
Printing out a 3 x 3 matrix:\n
1 2 3 \n
1 2 3 \n
1 2 3 \n
 */
void Print(const Matrix & matrix){
    int n = matrix.size();
    std::cout << "Printing out a " << n << " x " << n << " matrix:" << std::endl;
    for (auto n : matrix) {
        for (auto l : n){
            std::cout << l << " ";
        }        
        std::cout << std::endl;
    }
}

