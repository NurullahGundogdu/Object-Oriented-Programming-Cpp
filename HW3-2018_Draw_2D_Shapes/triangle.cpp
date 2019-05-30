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

}

double triangle::total_Area(){
    return area;
}
double triangle::total_Perimeter(){
    return perimeter;

}
double triangle::Area(){

    return areaOfShape;
}

double triangle::Perimeter(){

    return perimeterOfShape;
}
bool triangle::operator !=(const triangle& tria){
    if(((getlength()*(getlength()/2*sqrt(3)))/2) != ((tria.getlength()*(tria.getlength()/2*sqrt(3)))/2))
        return true;
    else
        return false;
}

bool triangle::operator ==(const triangle& tria){

    return !(*this != tria);
}

bool triangle::operator <(const triangle& tria){
    if(((getlength()*(getlength()/2*sqrt(3)))/2) < ((tria.getlength()*(tria.getlength()/2*sqrt(3)))/2))
        return true;
    else
        return false;
}

bool triangle::operator >(const triangle& tria){

    if(((getlength()*(getlength()/2*sqrt(3)))/2) > ((tria.getlength()*(tria.getlength()/2*sqrt(3)))/2))
        return true;
    else
        return false;
}

const triangle triangle::operator +(double number)const{
    double triangleValue=getlength()+number;

    if(triangleValue<=0)
        return triangle(1);

    return triangle(triangleValue);
}
const triangle triangle::operator -(double number)const{

    double triangleValue=getlength()-number;
    if(triangleValue<=0)
        return triangle(1);

    return triangle(triangleValue);
}
triangle triangle::operator ++(){

    setlength(getlength()+1);

    return triangle(getlength());
}
triangle triangle::operator ++(int){

    double temp=getlength();
    setlength(getlength()+1);

    return triangle(temp);
}

triangle triangle::operator --(){

    setlength(getlength()-1);

    return triangle(getlength());
}

triangle triangle::operator --(int){

    double temp=getlength();
    setlength(getlength()-1);

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
