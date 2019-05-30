#include "circle.h"
#include <iostream>
#include <fstream>
#include <cmath>

circle::circle():radius(0.0){}
circle::circle(double Radius){

    setradius(Radius);
}
void circle::draw(ofstream &file){

     if(gettype()=="bigshape"){
        file << "<svg width=\""<<getradius()*2<<"\" height=\""<<getradius()*2<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
        file << "<circle cx=\""<<getradius()<<"\" cy=\""<<getradius()<<"\" r=\""<<getradius()<<"\" fill=\"red\"/>"<<endl;
    }else if(gettype()=="smallshape"){
        file<<"<circle cx=\""<<getx_coordinate()<<"\" cy=\""<<gety_coordinate()<<"\" r=\""<<getradius()<<"\" fill=\"green\"  />";

    }
}
