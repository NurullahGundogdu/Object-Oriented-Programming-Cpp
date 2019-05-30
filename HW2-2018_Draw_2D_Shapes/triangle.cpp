#include "triangle.h"
#include <fstream>
#include <cmath>
#include <iostream>

triangle::triangle():length(0.0){}
triangle::triangle(double Length){
    setlength(Length);

}

void triangle::draw(ofstream &file){

    if(gettype()=="bigshape"){
        file << "<svg width=\""<<getlength()<<"\" height=\""<<((getlength()/2)*sqrt(3))<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
        file << "<polygon points=\""<<getlength()/2<<",0 0,"<<((getlength()/2)*sqrt(3))<<","<<getlength()<<","<<(getlength()/2)*sqrt(3)<<"\" fill=\"red\"/>"<<endl;
    }else if(gettype()=="smallshape"){
        file << "<polygon points=\""<<getx_coordinate()<<" "<<gety_coordinate()<<" "<<getx_coordinate_2()<<" "<<gety_coordinate_2()<<" "<<getx_coordinate_3()<<" "<<gety_coordinate_3()<<"\" fill=\"green\"  stroke=\"black\" />"<<endl;

    }

}

