#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include<string>
#include<vector>
#include <fstream>

using namespace std;

class SparseMatrix
{
    public:
        SparseMatrix();
        SparseMatrix(string matrixFilename);
        SparseMatrix(vector<vector<double> > &v, vector<vector<int> > &v1, vector<int> &v2);
        const SparseMatrix operator+(const SparseMatrix& vec1);
        const SparseMatrix operator-(const SparseMatrix& vec1);
        const SparseMatrix operator-();
        const SparseMatrix operator=(const SparseMatrix& vec1);
        const SparseMatrix operator*(const SparseMatrix& vec1);
        SparseMatrix transpose();
        friend ostream& operator<<(ostream & output, const SparseMatrix &vec1);

        inline string getFilename(){return matrixFilename;}
        inline void setFilename(string a){this->matrixFilename = a;}

        string matrixFilename;
        vector<vector<double> > data;
        vector<vector<int> > index;
        vector<int> row;

};

#endif // SPARSEMATRIX_H
