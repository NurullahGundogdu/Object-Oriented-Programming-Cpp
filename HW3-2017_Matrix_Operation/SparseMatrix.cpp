#include "SparseMatrix.h"
#include <fstream>
#include <iostream>
#include<string.h>
#include <stdlib.h>

SparseMatrix::SparseMatrix()
{

}

SparseMatrix::SparseMatrix(string matrixFilename){

    int i=0;
    char *c, *we;

    string line;
    setFilename(matrixFilename);
    ifstream file;
    file.open(getFilename());                   //okunacak dosya acilir

    if(!file.is_open()){
        cout<<"Error opening file"<<endl;
        return;                                 //dosya acilip acilmama kotrolu yapilir
    }

    while(getline(file,line)){
        i++;
    }
    file.close();                                   //size ayirmak icin dosya bir kere okunur
    index.resize(i);
    data.resize(i);

    file.open(getFilename());

    if(!file.is_open()){
        cout<<"Error opening file"<<endl;               //dosyadan matris okunur
        return;
    }

    for(int j = 0; j < i; j++){
        int count=2;
        double num;

        file>>num;
        row.push_back(num);
        getline(file,line);

        we = (char*) malloc (line.length());
        sprintf(we, "%s",line.c_str());             //satir stir okuma yapilir ve satir parcalanir

        c = strtok (we,": ");

        while(c!=NULL){

            if(count%2==0){
                index[j].push_back(atoi(c));
                count++;
            }else{
                count++;
                data[j].push_back(atof(c));
            }
            c = strtok (NULL, ": ");
        }
    }
    file.close();
}
SparseMatrix::SparseMatrix(vector<vector<double> > & v, vector<vector<int> > & v1, vector<int> &v2){

    data.resize(v2.size());
    index.resize(v2.size());

    for(int j=0; j<v2.size(); j++){                         //constructur yeni obje olusturur
        row.push_back(v2[j]);
        for(int i=0; i < v[j].size(); i++){
            data[j].push_back(v[j][i]);
            index[j].push_back(v1[j][i]);
        }
    }
}


const SparseMatrix SparseMatrix::operator+(const SparseMatrix& matris1){

    int theSize,a=0,b=0,sum, e = 0 ,r = 0,x=0,y=0,k;
    vector<vector<double> > tempData;
    vector<vector<int> > tempIndex;
    vector<int> temprow;
    int count = 0,count1=0;
    int sumrow = row.size()+matris1.row.size();

    if(row.size() > matris1.row.size())
        theSize = row.size();
    else                                                    //size ayirmak icin size hesaplanir
        theSize = matris1.row.size();

    for(int i = 0; i < theSize; i++)
        if(row[i]==matris1.row[i])
            count1++;
    sumrow-=count1;
    tempData.resize(sumrow);
    tempIndex.resize(sumrow);                   //size ayirilir

    for(int j=0; j<sumrow; j++){
        if(row[r]==matris1.row[e]){
            temprow.push_back(row[r]);
            sum = data[r].size() + matris1.data[e].size();

            if(data[r].size() > matris1.data[e].size())
                theSize = data[j].size();
            else
                theSize = matris1.data[e].size();
                                                            //rowlarýn esitligine ve indexlerin esitligine gore toplama islemi yapilir
            for(int i = 0; i < theSize; i++)
                if(index[r][i]==matris1.index[r][i])
                    count++;

            sum -= count;

            for(int i = 0; i < sum; i++){
                if(index[x][a]==matris1.index[y][b]){
                    if(data[x][a]+matris1.data[y][b]==0){
                        a++;
                        b++;
                        k=0;
                        continue;                                   //sonuc yeni matrise atanir
                    }

                    tempIndex[j].push_back(index[x][a]);
                    tempData[j].push_back(data[x][a]+matris1.data[y][b]);
                    a++;
                    b++;
                    k=0;
                }else
                    if(index[x][a]>matris1.index[y][b]){
                        tempIndex[j].push_back(matris1.index[y][b]);
                        tempData[j].push_back(matris1.data[y][b]);
                        b++;
                        k=1;
                    }else{
                        tempIndex[j].push_back(index[x][a]);
                        tempData[j].push_back(data[x][a]);
                        a++;
                        k=2;
                    }
            }
            if(k==0){
                x++;
                y++;
            }else if(k==1){
                y++;
            }else
                x++;
            r++;
            e++;
        }else
            if(row[r]>matris1.row[e]){
                temprow.push_back(matris1.row[e]);
                for(int i=0; i<matris1.index[e].size(); i++){
                    tempIndex[j].push_back(matris1.index[e][i]);
                    tempData[j].push_back(matris1.data[e][i]);
                }
                e++;
            }else{
                temprow.push_back(row[r]);
                for(int i=0; i<index[r].size(); i++){
                    tempIndex[j].push_back(index[r][i]);
                    tempData[j].push_back(data[r][i]);
                }
                r++;
            }
            count=0;
            a=0;
            b=0;
    }

    return SparseMatrix(tempData , tempIndex, temprow);
}
const SparseMatrix SparseMatrix::operator-(const SparseMatrix& matris1){

    int theSize,a=0,b=0,sum, e = 0 ,r = 0,x=0,y=0,k;
    vector<vector<double> > tempData;
    vector<vector<int> > tempIndex;
    vector<int> temprow;
    int count = 0,count1=0;
    int sumrow = row.size()+matris1.row.size();

    if(row.size() > matris1.row.size())
        theSize = row.size();
    else
        theSize = matris1.row.size();

    for(int i = 0; i < theSize; i++)                //size ayirmak icin size hesaplanir
        if(row[i]==matris1.row[i])
            count1++;
    sumrow-=count1;
    tempData.resize(sumrow);
    tempIndex.resize(sumrow);                       //size ayirilir

    for(int j=0; j<sumrow; j++){
        if(row[r]==matris1.row[e]){
            temprow.push_back(row[r]);
            sum = data[r].size() + matris1.data[e].size();

            if(data[r].size() > matris1.data[e].size())
                theSize = data[j].size();
            else
                theSize = matris1.data[e].size();

            for(int i = 0; i < theSize; i++)
                if(index[r][i]==matris1.index[r][i])                    //rowlarýn esitligine ve indexlerin esitligine gore toplama islemi yapilir
                    count++;

            sum -= count;

            for(int i = 0; i < sum; i++){
                if(index[x][a]==matris1.index[y][b]){
                    if(data[x][a]-matris1.data[y][b]==0){
                        a++;
                        b++;
                        k=0;
                        continue;
                    }

                    tempIndex[j].push_back(index[x][a]);
                    tempData[j].push_back(data[x][a]-matris1.data[y][b]);
                    a++;
                    b++;
                    k=0;
                }else                                                   //sonuc yeni matrise atanir
                    if(index[x][a]>matris1.index[y][b]){
                        tempIndex[j].push_back(matris1.index[y][b]);
                        tempData[j].push_back(0-matris1.data[y][b]);
                        b++;
                        k=1;
                    }else{
                        tempIndex[j].push_back(index[x][a]);
                        tempData[j].push_back(data[x][a]);
                        a++;
                        k=2;
                    }
            }
            if(k==0){
                x++;
                y++;
            }else if(k==1){
                y++;
            }else
                x++;
            r++;
            e++;
        }else
            if(row[r]>matris1.row[e]){
                temprow.push_back(matris1.row[e]);
                for(int i=0; i<matris1.index[e].size(); i++){
                    tempIndex[j].push_back(matris1.index[e][i]);
                    tempData[j].push_back(0-matris1.data[e][i]);
                }
                e++;
            }else{
                temprow.push_back(row[r]);
                for(int i=0; i<index[r].size(); i++){
                    tempIndex[j].push_back(index[r][i]);
                    tempData[j].push_back(data[r][i]);
                }
                r++;
            }
            count=0;
            a=0;
            b=0;
    }

    return SparseMatrix(tempData , tempIndex, temprow);
}
const SparseMatrix SparseMatrix::operator-(){

    vector<vector<double> >tempData;
    tempData.resize(row.size());

    for (int i = 0; i < row.size(); i++){
        tempData[i].resize(data[i].size());
        for (int j = 0; j < data[i].size(); j++)
            tempData[i][j] = data[i][j];
    }
                                                            //matrisin datalari 0 dan cikarilir ve geri matrise atanir
    for(int j = row.size() - 1; j >= 0 ; j--)
        for(int i = 0; i < tempData[j].size(); i++)
            data[j].pop_back();

    data.resize(row.size());

    for(int j=0; j<row.size(); j++)
        for(int i=0; i<tempData[j].size(); i++)
            data[j].push_back(0-tempData[j][i]);

    return SparseMatrix(data,index,row);
}
const SparseMatrix SparseMatrix::operator=(const SparseMatrix& matris1){

    for(int i = 0; i < row.size(); i++){
        data[i].clear();
        index[i].clear();
    }
    data.clear();
    index.clear();
    row.clear();

    row.resize(matris1.row.size());

    for(int i = 0; i < row.size(); i++)
        row[i]=matris1.row[i];

    data.resize(matris1.row.size());                            //gelen matris sonucu yeni matrise atnir
    index.resize(matris1.row.size());

    for (int i = 0; i < row.size(); i++){
        data[i].resize(matris1.data[i].size());
        index[i].resize(matris1.data[i].size());
    }

    for(int i=0; i<matris1.row.size(); i++)
        for(int j=0; j<matris1.index[i].size(); j++){
            data[i][j] = matris1.data[i][j];
            index[i][j] = matris1.index[i][j];
        }

     return *this;
}

const SparseMatrix SparseMatrix::operator*(const SparseMatrix& matris1){

    return SparseMatrix(data,index,row);                        //carpma islemini yapamadýgýmdan ayni matrisi atadim
}
SparseMatrix SparseMatrix::transpose(){

    return SparseMatrix(data,index,row);                    //transpoýse islemini yapamadýgýmdan ayni matrisi atadim

}
ostream& operator<<(ostream & output, const SparseMatrix &matris1){

     for(int y=0; y<matris1.row.size(); y++){
        output<<matris1.row[y]<<" ";
        for(int z=0; z<matris1.index[y].size(); z++){                         //matris dosyaya yazdirilir
            output<<matris1.index[y][z]<<":"<<matris1.data[y][z]<<" ";
        }
        output<<endl;
    }
    return output;
}
