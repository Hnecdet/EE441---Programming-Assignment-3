#include <iostream>
#include "Matrix.hpp"
using namespace std;
const int TABLE_SIZE = 65536;
void cofactor(Matrix& A, Matrix& B, int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int column = 0; column < n; column++) {
            if (row != p && column != q) {
                B.SetMatrix(i, j++, A.GetMatrix(row, column));
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
int calculateDeterminant(Matrix& A, int dimension) {
    int Det = 0;
    if (dimension == 1)
        return A.GetMatrix(0, 0);
    Matrix cofactorMat(dimension);
    int sign = 1;
    for (int firstRow = 0; firstRow < dimension; firstRow++) {
        cofactor(A, cofactorMat, 0, firstRow, dimension);
        Det += sign * A.GetMatrix(0, firstRow) * calculateDeterminant(cofactorMat, dimension - 1);
        sign = -sign;
    }
    return Det;
}
class HT_Item
{
public:
    Matrix key;
    long value;
    HT_Item(Matrix key, long value) {
        {
            this->key = key;
            this->value = value;
        }
    };
};
class HashTable
{
private:
    HT_Item** table;
public:
    int count = 0;
    HashTable()
    {
        // Initialize the table with NULLs
        table = new HT_Item * [TABLE_SIZE]();
    }

    ~HashTable()
    {
        // Deallocate memory for each item in the table
        for (int i = 0; i < TABLE_SIZE; i++)
            delete table[i];
        delete[] table;
    }
    bool key_exists(Matrix& key)
    {
        int h = key.hash();
        HT_Item* item = table[h];
        // Check if the item at the calculated location has the given key
        if (item && item->key == key)
            return true;
        // Otherwise, search the rest of the table for the key
        for (int i = h + 1; i < TABLE_SIZE; i++)
        {
            item = table[i];
            if (item && item->key == key)
                return true;
        }
        return false;
    }
    void insert(Matrix& key, long value) const
    {
        HT_Item* item = new HT_Item{ key, value };
        int count = 0;
        // Check if the hash table is full
        if (count == TABLE_SIZE)
        {
            std::cerr << "Error: Hash table is full!" << std::endl;
            return;
        }
        int h = key.hash();
        while (table[h] != NULL) {
            h = (h + 1) % TABLE_SIZE;
        }
        // Insert the item at the calculated location
        table[h] = item;
        count++;
    }

    long search(Matrix& key) const
    {
        int h = key.hash();
        int count = 0;
        HT_Item* item = table[h];
        while (item && item->key == key) {
            item = table[h];
            // Return the value if the item is found
            if (item && item->key == key)
                return item->value;
            else { h++; }
            count++;
            // Return -1 if the item is not found
            if (count == TABLE_SIZE) return -1;
        }


    }
};
long determinant(HashTable*& table, Matrix& A)
{
    if (table->key_exists(A) == false)
        if (table == nullptr)
        {
            table = new HashTable();
            table->insert(A, calculateDeterminant(A, A.size()));
            return calculateDeterminant(A, A.size());
        }
        else
        {
            table->insert(A, calculateDeterminant(A, A.size()));
            return calculateDeterminant(A, A.size());
        }

    else if (table->key_exists(A) == true) {
        {
            long S = table->search(A);
            return S;

        }
    }
}


