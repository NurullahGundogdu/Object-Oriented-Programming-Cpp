#include "triangle.h"
#include <fstream>
#include <cmath>
#include <iostream>

double triangle::area=0;
double triangle::perimeter=0;

triangle::triangle():type(""),length(0.0),x_coordinate(0.0),y_coordinate(0.0),x_coordinate_2(0.0),y_coordinate_2(0.0),x_coordinate_3(0.0),y_coordinate_3(0.0){
}			//default constructur throws 0 and spaces into all variables

triangle::triangle(double Length){				//this constructur takes length and creates a triangle member
    setlength(Length);
    area+=(getlength()*(getlength()/2*sqrt(3)))/2;
    perimeter+=3*getlength();
}

double triangle::total_Area(){
    return area;                //satic area function
}
double triangle::total_Perimeter(){
    return perimeter;           //satic perimeter function

}

bool triangle::operator !=(const triangle& tria){
    if(((getlength()*(getlength()/2*sqrt(3)))/2) != ((tria.getlength()*(tria.getlength()/2*sqrt(3)))/2))
        return true;        //control two triangle is not equal
    else
        return false;
}

bool triangle::operator ==(const triangle& tria){

    return !(*this != tria);            //control two triangle is equal
}

bool triangle::operator <(const triangle& tria){
    if(((getlength()*(getlength()/2*sqrt(3)))/2) < ((tria.getlength()*(tria.getlength()/2*sqrt(3)))/2))
        return true;
    else                //control  triangle smaller than other
        return false;
}

bool triangle::operator >(const triangle& tria){

    if(((getlength()*(getlength()/2*sqrt(3)))/2) > ((tria.getlength()*(tria.getlength()/2*sqrt(3)))/2))
        return true;
    else                    //control  circle bigger than other
        return false;
}

const triangle triangle::operator +(double number)const{
    double triangleValue=getlength()+number;

    if(triangleValue<=0)            //add double value to triangle
        return triangle(1);

    return triangle(triangleValue);
}
const triangle triangle::operator -(double number)const{

    double triangleValue=getlength()-number;
    if(triangleValue<=0)                //subsruction double value to triangle
        return triangle(1);

    return triangle(triangleValue);
}
triangle triangle::operator ++(){

    setlength(getlength()+1);
                            //add 1 to triangle sizes
    return triangle(getlength());
}
triangle triangle::operator ++(int){

    double temp=getlength();
    setlength(getlength()+1);   //add 1 to triangle sizes

    return triangle(temp);
}

triangle triangle::operator --(){

    setlength(getlength()-1);
                    //substruct 1 to triangle sizes
    return triangle(getlength());
}

triangle triangle::operator --(int){

    double temp=getlength();
    setlength(getlength()-1);           //substruct 1 to triangle sizes

    return triangle(temp);
}
ostream& operator <<(ostream & output, const triangle &tria){

    								//if shape is big
    if(tria.gettype()=="bigshape"){		//function write svg codes to file and draw main shape
        output << "<svg width=\""<<tria.getlength()<<"\" height=\""<<((tria.getlength()/2)*sqrt(3))<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
        output << "<polygon points=\""<<tria.getlength()/2<<",0 0,"<<((tria.getlength()/2)*sqrt(3))<<","<<tria.getlength()<<","<<(tria.getlength()/2)*sqrt(3)<<"\" fill=\"red\"/>"<<endl;

    }else if(tria.gettype()=="smallshape"){			//if shape is small function draw a small shape(triangle)
        output << "<polygon points=\""<<tria.getx_coordinate()<<" "<<tria.gety_coordinate()<<" "<<tria.getx_coordinate_2()<<" "<<tria.gety_coordinate_2()<<" "<<tria.getx_coordinate_3()<<" "<<tria.gety_coordinate_3()<<"\" fill=\"green\"  stroke=\"black\" />"<<endl;

    }
    return output;
}
