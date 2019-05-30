#include "SparseVector.h"
#include <fstream>
#include <iostream>

using namespace std;

SparseVector::SparseVector()
{

}

SparseVector::SparseVector(string vectorFilename){

    int a;
    double b;
    char c;

    setFilename(vectorFilename);
    ifstream file;
    file.open(getFilename());               //okunucak dosya acilir

    if(!file.is_open()){
        cout<<"Error opening file"<<endl;    //dosya acilip acilmama kotrolu yapilir
        return;
    }
    while(!file.eof()){
        file>>a>>c>>b;                      //dosyadan vektor okunur
        data.push_back(b);
        index.push_back(a);
    }
    file.close();
}
ostream& operator<<(ostream & output, const SparseVector &vec1){

    for(int i=0; i<vec1.index.size(); i++)
        output<<vec1.index[i]<<":"<<vec1.data[i]<<" ";          //vektor output dosyasýna yazadirilir
    output<<endl;

    return output;
}
SparseVector::SparseVector(vector<double> v,vector<int> v1){

    for(int i=0; i<v.size(); i++){
        data.push_back(v[i]);                                   //constructor yeni obje olusturur
        index.push_back(v1[i]);
    }

}

const SparseVector SparseVector::operator +(const SparseVector& vec1){

    int theSize, a=0, b=0, count = 0;
    int sum = data.size() + vec1.data.size();

    vector<double> tempData;
    vector<int> tempIndex;

    if(data.size() > vec1.data.size())
        theSize = data.size();
    else
        theSize = vec1.data.size();
                                                                //yeni vektor icin size hesaplanir
    for(int i = 0; i < theSize; i++)
        if(index[i]==vec1.index[i])
            count++;
    sum -= count;

    for(int i = 0; i < sum; i++)
        if(index[a]==vec1.index[b]){
            if(data[a]+vec1.data[b]==0){
                a++;
                b++;
                continue;                                   //indexlerin esitlik durumuna gore toplama ilemi yapilir ve yeni vektore atanir
            }
            tempIndex.push_back(index[a]);
            tempData.push_back(data[a]+vec1.data[b]);
            a++;
            b++;
        }else
            if(index[a]>vec1.index[b]){
                tempIndex.push_back(vec1.index[b]);

                tempData.push_back(vec1.data[b]);
                 b++;
            }else{
                tempIndex.push_back(index[a]);

                tempData.push_back(data[a]);
                a++;
            }
    return SparseVector(tempData , tempIndex );
}
const SparseVector SparseVector::operator -(const SparseVector& vec1){
    int theSize, a=0, b=0, count = 0;
    int sum = data.size() + vec1.data.size();

    vector<double> tempData;
    vector<int> tempIndex;

    if(data.size() > vec1.data.size())
        theSize = data.size();
    else
        theSize = vec1.data.size();             //yeni vektor icin size hesaplanir

    for(int i = 0; i < theSize; i++)
        if(index[i]==vec1.index[i])
            count++;
    sum -= count;

    for(int i = 0; i < sum; i++)
        if(index[a]==vec1.index[b]){        //indexlerin esitlik durumuna gore cýkaarma ilemi yapilir ve yeni vektore atanir
            if(data[a]-vec1.data[b]==0){
                a++;
                b++;
                continue;
            }
            tempIndex.push_back(index[a]);
            tempData.push_back(data[a]-vec1.data[b]);
            a++;
            b++;
        }else
            if(index[a]>vec1.index[b]){
                tempIndex.push_back(vec1.index[b]);
                tempData.push_back((0-vec1.data[b]));
                b++;
            }else{
                tempIndex.push_back(index[a]);
                tempData.push_back(data[a]);
                a++;
            }
    return SparseVector(tempData , tempIndex );
}

const SparseVector SparseVector::operator -(){
    vector<double> tempData;

    for(int i = 0; i < data.size(); i++){
        tempData.push_back(data[i]);
    }
    for(int i = 0; i < tempData.size(); i++){               //vektorun data degerleri 0 dn cikarilir ve kendisine atanýr
        data.pop_back();
    }
    for(int i=0; i<tempData.size(); i++)
        data.push_back(0-tempData[i]);

    return SparseVector(data ,index);
}
const SparseVector SparseVector::operator =(const SparseVector& vec1){

    for(int i=0; i<vec1.data.size(); i++){                          //gelen vektorun atama islemi yapilir
        data.push_back(vec1.data[i]);
        index.push_back(vec1.index[i]);
    }
    return *this;
}
double dot(SparseVector v1, SparseVector v2){

    int a=0, b=0, theSize;
    double sumDot=0;

    if(v1.data.size() > v2.data.size())
        theSize = v1.data.size();
    else
        theSize = v2.data.size();                               //vektorlerin ayni indekslerindeki datalari birbiriyle carpilir ve toplanir

    for(int i=0; i<theSize; i++){
        if(v1.index[a]==v2.index[b]){
            sumDot+=v1.data[i]*v2.data[b];
            a++;
            b++;
        }else
            if(v1.index[a]>v2.index[b])
                b++;
            else
                a++;
    }
    return sumDot;
}
