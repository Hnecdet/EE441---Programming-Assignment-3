
#include "matrix.hpp"
#include <iostream>

using namespace std;
class BST_Node
{
 public :
 BST_Node* left;
 BST_Node* right;
 // Determinant of key matrix is value
 Matrix key;
 long value;
 BST_Node(Matrix key, long value){
  {
      this->key = key;
      this->value = value;
      left = nullptr;
      right = nullptr;
  }
 }
};
bool key_exists(BST_Node* root, Matrix A)
{
    if (root == nullptr) return false;
    if (root->key == A) return true;
    if (A < root->key) return key_exists(root->left, A);
    return key_exists(root->right, A);
}
long search(BST_Node* root, Matrix A)
{
    if (root == nullptr) return -1;
    if (root->key == A) return root->value;
    if (A < root->key) return search(root->left, A);
    else return search(root->right, A);
}
void insert(BST_Node*& root, Matrix A,long detA)
{
    if (root == nullptr)
    {
        root = new BST_Node(A,detA);
        root->key = A;
        root->value = detA;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }

    if (root->key == A)
    {
        root->value = detA;
        return;
    }

    if (A < root->key)
    {
        insert(root->left, A, detA);
    }
    else
    {
        insert(root->right, A,detA);
    }

}
void cofactor(Matrix &A, Matrix &B, int p,int q, int n){
   int i = 0, j = 0;
   for (int row = 0; row < n; row++){
      for (int column = 0; column < n; column++){
         if (row != p && column != q){
            B.SetMatrix(i,j++,A.GetMatrix(row,column));
            if (j == n - 1){
                  j = 0;
                  i++;
            }
         }
      }
   }
}
int calculateDeterminant(Matrix &A, int dimension){
   int Det = 0;
   if (dimension == 1)
      return A.GetMatrix(0,0);
   Matrix cofactorMat(dimension);
   int sign = 1;
   for (int firstRow = 0; firstRow < dimension; firstRow++){
      cofactor(A, cofactorMat, 0, firstRow, dimension);
      Det += sign * A.GetMatrix(0,firstRow) * calculateDeterminant(cofactorMat, dimension - 1);
      sign = -sign;
   }
   return Det;
}

long determinant(BST_Node*& root, Matrix& A)
{
    if(!key_exists(root,A))
        if (root == nullptr)
        {
            root = new BST_Node(A, determinant(root,A));
            root->key = A;
            root->value = calculateDeterminant(A,A.size());
            root->left = nullptr;
            root->right = nullptr;
            return root->value;
        }
        else
        {
            insert(root,A,calculateDeterminant(A,A.size()));
            return root->value;
        }

    else if (key_exists(root,A)){
    {
        long S = search(root,A);
        return S;

}}
}
