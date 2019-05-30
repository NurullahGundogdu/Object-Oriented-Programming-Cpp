#include "triangle.h"
#include <fstream>
#include <cmath>
#include <iostream>

namespace SHAPES{

    double triangle::area=0;
    double triangle::perimeter=0;

    triangle::triangle():shape(),type(""),length(0.0),x_coordinate(0.0),y_coordinate(0.0),x_coordinate_2(0.0),y_coordinate_2(0.0),x_coordinate_3(0.0),y_coordinate_3(0.0){
    }			//default constructur throws 0 and spaces into all variables

    triangle::triangle(double Length){				//this constructur takes length and creates a triangle member
        setlength(Length);
        area+=(getlength()*(getlength()/2*sqrt(3)))/2;
        perimeter+=3*getlength();
    }

    double triangle::Area(){
        shape_Area=(length*(length/2*sqrt(3)))/2;
        return shape_Area;
    }
    double triangle::Perimeter(){
        shape_Perimeter=3*length;
        return shape_Perimeter;
    }

    double triangle::total_Area(){
        return area;                //satic area function
    }
    double triangle::total_Perimeter(){
        return perimeter;           //satic perimeter function

    }

    bool triangle::operator !=(triangle& tria){
        return shape::operator!=(tria);
    }

    bool triangle::operator ==(triangle& tria){

        return shape::operator==(tria);            //control two triangle is equal
    }

    bool triangle::operator <(triangle& tria){
        return shape::operator<(tria);
    }

    bool triangle::operator >(triangle& tria){

        return shape::operator>(tria);
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
    triangle& triangle::operator ++(){

        x_coordinate++;
        y_coordinate++;
        x_coordinate_2++;
        y_coordinate_2++;
        x_coordinate_3++;
        y_coordinate_3++;
                                //add 1 to triangle sizes
        return *this;
    }
    triangle& triangle::operator ++(int){

        triangle::operator++();

        return *this;
    }

    triangle& triangle::operator --(){

        x_coordinate--;
        y_coordinate--;
        x_coordinate_2--;
        y_coordinate_2--;
        x_coordinate_3--;
        y_coordinate_3--;
                        //substruct 1 to triangle sizes
        return *this;
    }

    triangle& triangle::operator --(int){

        triangle::operator--();         //substruct 1 to triangle sizes

        return *this;
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
}
