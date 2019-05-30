#include "circle.h"
#include <iostream>
#include <fstream>
#include <cmath>
#define PI 3.14

namespace SHAPES{

    double circle::area=0;
    double circle::perimeter=0;

    circle::circle() :shape(),radius(0.0),x_coordinate(0.0),y_coordinate(0.0){		//default constructur throws 0 and spaces into all variables
    }

    circle::circle(double Radius){
        setradius(Radius);					//this constructur takes radius and creates a circle member
        perimeter+=2*PI*getradius();
        area+=PI*getradius()*getradius();
    }

     double circle::Area(){

         shape_Area=PI*radius*radius;
         return shape_Area;
     }
    double circle::Perimeter(){
        shape_Perimeter=2*PI*radius;
        return shape_Perimeter;
    }
   double circle::total_Area(){

        return area;            //satic area function
    }

    double circle::total_Perimeter(){

        return perimeter;           //satic perimeter function
    }

    bool circle::operator !=(circle& circ){

        return shape::operator!=(circ);
    }

    bool circle::operator ==(circle& circ){

       return shape::operator==(circ);           //control two circle is equal
    }

    bool circle::operator <(circle& circ){

        return shape::operator<(circ);
    }

    bool circle::operator >(circle& circ){

       return shape::operator>(circ);
    }

    const circle circle::operator +(double number)const{

        double radiusValue=getradius()+number;

        if(radiusValue<=0)
            return circle(1);           //add double value to circle

        return circle(radiusValue);
    }

    const circle circle::operator -(double number)const{

        double radiusValue=getradius()-number;

        if(radiusValue<=0)              //subsruction double value to circle
            return circle(1);

        return circle(radiusValue);
    }
    circle& circle::operator ++(){

        x_coordinate++;
        y_coordinate++;
                                    //add 1 to circle sizes
        return *this;
    }

    circle& circle::operator ++(int){

        circle::operator++();
           //add 1 to circle sizes

        return *this;
    }

    circle& circle::operator --(){

        x_coordinate++;
        y_coordinate++;
                            //substruct 1 to circle sizes
        return *this;
    }
    circle& circle::operator --(int){

        circle::operator--();

        return *this;
    }

    ostream& operator <<(ostream & output, const circle &circ){

        if(circ.gettype()=="bigshape"){				//function write svg codes to file and draw main shape
            output << "<svg width=\""<<circ.getradius()*2<<"\" height=\""<<circ.getradius()*2<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
            output << "<circle cx=\""<<circ.getradius()<<"\" cy=\""<<circ.getradius()<<"\" r=\""<<circ.getradius()<<"\" fill=\"red\"/>"<<endl;

        }else if(circ.gettype()=="smallshape"){			//if shape is small function draw a small shape(circle)
            output<<"<circle cx=\""<<circ.getx_coordinate()<<"\" cy=\""<<circ.gety_coordinate()<<"\" r=\""<<circ.getradius()<<"\" fill=\"green\"  />"<<endl;
        }
        return output;
    }
}
