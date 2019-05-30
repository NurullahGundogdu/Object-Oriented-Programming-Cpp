#include "polygon.h"
#include "circle.h"
#include "rectengal.h"
#include "triangle.h"
#include "shape.h"
#include <vector>
#include <iostream>
#define PI 3.14
#include <cmath>

namespace SHAPES{

    polygon::polygon():sizes(0),width(0.0),height(0.0),type(""),pol_area(0),pol_perimeter(0){
    }           //default constructur

    polygon::Point2D::Point2D():x(0),y(0){
    }           //default constructur for point2d

    polygon::Point2D::Point2D(double x, double y){
        setx(x);
        sety(y);                //point save
    }

    ostream& operator <<(ostream & output, const polygon &poly){

        if(poly.gettype()=="bigshape"){
            output << "<svg width=\""<<poly.getwidth()<<"\" height=\""<<poly.getheight()<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;

            output << "<polygon points=\"";                 //in this operator overload function print to file svg code

            output<<"\" fill=\"red\" />"<<endl;

        }else if(poly.gettype()=="smallshape"){

            output << "<polygon points=\"";

            output<<"\" fill=\"green\"  stroke=\"black\" />"<<endl;
        }
        return  output;
    }

    const polygon& operator +(const polygon &A,const polygon &B){

        int i;
        polygon *poly;
                                                        //add two polygon and assign different polygon
        for(i=0; i<A.sizes; i++)
            poly->setArea(A.getArea());

        for(int j=i-1, k=0; j<A.sizes+B.sizes; j++, k++)
            poly->setPerimeter(B.getPerimeter());

        return *poly;
    }


    bool operator !=(const polygon& A,const polygon& B){

            return !(A==B);         //control two polygon if they do not equal

    }

    bool operator ==(const polygon& A,const polygon& B){

        if(A.getsize()!=B.getsize())
            return false;           //control two polygon if they  equal

        for(int i=0; i<A.getsize(); i++)
            if((A.getArea()!=B.getArea()) || (A.getPerimeter()!=B.getPerimeter()))
                return false;

        return true;
    }
    polygon& polygon::operator ++(){
        return *this;
    }
    polygon& polygon::operator ++(int){
        return *this;
    }
    polygon& polygon::operator --(){
        return *this;
    }
    polygon& polygon::operator --(int){
        return *this;
    }

}
