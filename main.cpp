#include <iostream>
#include "hash.hpp"
using namespace std;
int main() {
    Matrix A(11);

    A.SetMatrix(7,2,11);
    A.SetMatrix(7,6,24);
    A.SetMatrix(7,7,3);
    A.SetMatrix(7,8,8);
    A.SetMatrix(7,9,12);
    A.SetMatrix(8,6,14);
    A.SetMatrix(8,7,16);
    A.SetMatrix(8,8,20);
    A.SetMatrix(8,9,6);
    A.SetMatrix(9,6,2);
    A.SetMatrix(9,7,2);
    A.SetMatrix(9,8,16);
    A.SetMatrix(9,9,20);
    A.SetMatrix(6,6,17);
    A.SetMatrix(6,7,9);
    A.SetMatrix(6,9,19);
    A.SetMatrix(6,10,20);
    for (int i=0;i  <11;i++){
        for (int j=0;j  <11;j++){
            cout << A.GetMatrix(i,j)<<" ";
        }
        cout << endl;
    }
    HashTable* ht = new HashTable();  // Create a pointer to a HashTable object
    ht->insert(A, calculateDeterminant(A, A.size()));
    long s = determinant(*&ht,A);
    cout << endl << s;



}
