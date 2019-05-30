#ifndef SPARSEVECTOR_H
#define SPARSEVECTOR_H
#include<vector>
#include<string>
#include <fstream>

using namespace std;

class SparseVector
{
    public:
        SparseVector();
        SparseVector(string vectorFilename);
        SparseVector(vector<double> v, vector<int> v1);

        const SparseVector operator +(const SparseVector& vec1);
        const SparseVector operator -(const SparseVector& vec1);
        const SparseVector operator -();
        const SparseVector operator =(const SparseVector& vec1);
        friend double dot(SparseVector v1, SparseVector v2);
        friend ostream& operator<<(ostream & output, const SparseVector &vec1);

        inline string getFilename(){return vectorFilename;}
        inline void setFilename(string a){this->vectorFilename = a;}

        string vectorFilename;
        vector<double> data;
        vector<int> index;
};

#endif // SPARSEVECTOR_H
