#include "circle.h"
#include <iostream>
#include <fstream>
#include <cmath>
#define PI 3.14


double circle::area=0;
double circle::perimeter=0;

circle::circle() : type(""),radius(0.0),x_coordinate(0.0),y_coordinate(0.0){		//default constructur throws 0 and spaces into all variables
}

circle::circle(double Radius){
    setradius(Radius);					//this constructur takes radius and creates a circle member
    perimeter+=2*PI*getradius();
    area+=PI*getradius()*getradius();
}

double circle::total_Area(){

    return area;            //satic area function
}

double circle::total_Perimeter(){

    return perimeter;           //satic perimeter function
}

bool circle::operator !=(const circle& circ){

    if((PI*getradius()*getradius())!= (circ.getradius()*circ.getradius()*PI))
        return true;
    else                    //control two circle is not equal
        return false;
}

bool circle::operator ==(const circle& circ){

    return !(*this != circ);            //control two circle is equal
}

bool circle::operator <(const circle& circ){

    if((PI*getradius()*getradius()) < (circ.getradius()*circ.getradius()*PI))
        return true;
    else                //control  circle smaller than other
        return false;
}

bool circle::operator >(const circle& circ){

    if((PI*getradius()*getradius()) > (circ.getradius()*circ.getradius()*PI))
        return true;
    else                //control  circle bigger than other
        return false;
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
circle circle::operator ++(){

    setradius(getradius()+1);
                                //add 1 to circle sizes
    return circle(getradius());
}

circle circle::operator ++(int){

    double temp=getradius();

    setradius(getradius()+1);           //add 1 to circle sizes

    return circle(temp);
}

circle circle::operator --(){

    setradius(getradius()-1);
                        //substruct 1 to circle sizes
    return circle(getradius());
}
circle circle::operator --(int){

    double temp=getradius();            //substruct 1 to circle sizes

    setradius(getradius()-1);

    return circle(temp);
}

ostream& operator <<(ostream & output, const circle &circ){
    if(circ.gettype()=="bigshape"){				//function write svg codes to file and draw main shape
        output << "<svg width=\""<<circ.getradius()*2<<"\" height=\""<<circ.getradius()*2<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
        output << "<circle cx=\""<<circ.getradius()<<"\" cy=\""<<circ.getradius()<<"\" r=\""<<circ.getradius()<<"\" fill=\"red\"/>"<<endl;

    }else if(circ.gettype()=="smallshape"){			//if shape is small function draw a small shape(circle)
        output<<"<circle cx=\""<<circ.getx_coordinate()<<"\" cy=\""<<circ.gety_coordinate()<<"\" r=\""<<circ.getradius()<<"\" fill=\"green\"  />";
    }
    return output;
}
