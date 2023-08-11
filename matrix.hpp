
#include <iostream>

using namespace std;

class Matrix{
protected:
    int S;
    int **data;
public:
    Matrix() : S(0) {}
    Matrix(int N);
    Matrix (const Matrix &ref);
    ~Matrix();
    int size(){
        return S;
    }
    void SetMatrix(int i, int j, int k);
    int GetMatrix(int i, int j) const;
    friend bool operator==(const Matrix& lhs, const Matrix& rhs){
      if (lhs.S != rhs.S) return false;

      for (int i = 0; i < lhs.S; i++) {
        for (int j = 0; j < lhs.S; j++) {
          if (lhs.GetMatrix(i,j) != rhs.GetMatrix(i,j)) return false;
        }
      }
      return true;
    }
    friend bool operator<(const Matrix& lhs, const Matrix& rhs) {
      if (lhs.S < rhs.S) return true;
      if (lhs.S > rhs.S) return false;

      for (int i = 0; i < lhs.S; i++) {
        for (int j = 0; j < lhs.S; j++) {
          if (lhs.GetMatrix(i,j) < rhs.GetMatrix(i,j)) return true;
          if (lhs.GetMatrix(i,j) > rhs.GetMatrix(i,j)) return false;
        }
      }
      return false;

    }
};
Matrix::Matrix(int N): S(N){
if(N<=20 && 0<=N){
    data=new int*[S];
    for(int i=0;i<S;i++)
        data[i]=new int[S];

    for(int i=0;i<S;i++){
        for(int j=0;j<S;j++){
            if(i==j) data[i][j]=1;
            else data[i][j]=0;
        }
    }
}
}
Matrix::Matrix (const Matrix &ref){
    this->data=new int*[ref.S];
    for(int i=0;i<ref.S;i++)
        this->data[i]=new int[ref.S];

    for(int r=0;r<ref.S;r++){
        for(int c=0;c<ref.S;c++){
            this->data[r][c]=ref.data[r][c];
        }
    }
}

void Matrix::SetMatrix(int i, int j, int k) {
	if (i > S || j > S|| 0 > i|| 0 > j)  //checking the indices are valid.
		cerr << "ERROR";
	else
		data[i][j] = k;
}
int Matrix::GetMatrix(int i, int j)const{
	int a;
	if (i > S || j > S|| 0 > i|| 0 > j) //checking the indices are valid.
		cerr << "ERROR";
	else
		return data[i][j];

}

Matrix::~Matrix(){
        //Free each sub-array (row)
for(int i = 0; i< S; ++i) {
delete[] data[i];
        }
delete[] data;  //Free the array of pointers
}

