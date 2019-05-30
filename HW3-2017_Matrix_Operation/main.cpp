#include <iostream>
#include <string>
#include "SparseVector.h"
#include "SparseMatrix.h"
#include <fstream>
void testMatrix();
void testVector();

using namespace std;

int main(){

    ofstream outfile;
    outfile.open("output.txt", ios::out | ios::trunc );

    SparseVector a1("input2.txt");
    SparseVector a2("input3.txt");
    SparseVector a;

    a=a1+a2;
    outfile<<endl<<a<<endl;
    a=a1-a2;
    outfile<<endl<<a<<endl;
    a=-a1;
    outfile<<endl<<a<<endl;
    outfile<<endl<<dot(a1,a2)<<endl;


    SparseMatrix a3("input.txt");
    SparseMatrix a4("input1.txt");
    SparseMatrix b;

    b=a3+a4;
    outfile<<endl<<b<<endl;
    b=a3-a4;
    outfile<<endl<<b<<endl;
    b=a3*a4;
    outfile<<endl<<b<<endl;
    b=-a3;
    outfile<<endl<<b<<endl;
    outfile<<endl<<a3.transpose()<<endl;
    return 0;
}



void testVector(){





}

void testMatrix(){
    ofstream outfile;
    outfile.open("output.txt", ios::out | ios::trunc );


}
