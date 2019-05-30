#include "rectengal.h"
#include <fstream>
#include <cmath>
#include <iostream>
namespace SHAPES{
    double rectengal::area=0;
    double rectengal::perimeter=0;

    rectengal::rectengal():shape(),type(""),x_coordinate(0.0),y_coordinate(0.0),width(0.0),height(0.0){
    }              //default constructur throws 0 and spaces into all variables

    rectengal::rectengal(double Width, double Height){
        setheight(Height);                  //this constructur takes heigt and width and creates a rectangle member
        setwidth(Width);
        area+=(getheight()*getwidth());
        perimeter+=2*(getheight()+getwidth());
    }
    double rectengal::Area(){

         shape_Area=width*height;
             return shape_Area;
    }
    double rectengal::Perimeter(){

        shape_Perimeter=2*(height+width);
        return shape_Perimeter;
    }
    double rectengal::total_Area(){
        return area;            //satic area function

    }

    double rectengal::total_Perimeter(){
        return perimeter;       //satic perimeter function

    }
    bool rectengal::operator !=(rectengal& rec){
        return shape::operator!=(rec);
    }

    bool rectengal::operator ==(rectengal& rec){

        return shape::operator==(rec);         //control two rectengal is equal
    }

    bool rectengal::operator <(rectengal& rec){
        return shape::operator<(rec);
    }

    bool rectengal::operator >(rectengal& rec){

        return shape::operator>(rec);
    }


    const rectengal rectengal::operator +(double number)const{
        double rectengal_Width_Value, rectengal_Height_Value;

        rectengal_Height_Value=getheight()+number;
        rectengal_Width_Value=getwidth()+number;

        if(rectengal_Width_Value<=0 && rectengal_Height_Value<=0)
            return rectengal(1,1);              //add double value to rectengal
        if(rectengal_Width_Value<=0)
            return rectengal(1,rectengal_Height_Value);
        if(rectengal_Height_Value<=0)
            return rectengal(rectengal_Width_Value,1);

        return rectengal(rectengal_Width_Value,rectengal_Height_Value);

    }
    const rectengal rectengal::operator -(double number)const{
        double rectengal_Width_Value, rectengal_Height_Value;

        rectengal_Height_Value=getheight()-number;
        rectengal_Width_Value=getwidth()-number;

        if(rectengal_Width_Value<=0 && rectengal_Height_Value<=0)           //subsruction double value to rectengal
            return rectengal(1,1);
        if(rectengal_Width_Value<=0)
            return rectengal(1,rectengal_Height_Value);
        if(rectengal_Height_Value<=0)
            return rectengal(rectengal_Width_Value,1);

        return rectengal(rectengal_Width_Value,rectengal_Height_Value);
    }


    rectengal& rectengal::operator ++(){

        x_coordinate++;
        y_coordinate++;

        return *this;
    }

    rectengal& rectengal::operator ++(int){

        rectengal::operator++();//add 1 to rectengal sizes

        return *this;
    }

    rectengal& rectengal::operator --(){

        x_coordinate--;
        y_coordinate--;          //substruct 1 to rectengal sizes

        return *this;
    }

    rectengal& rectengal::operator --(int){

        rectengal::operator--();


        return *this;
    }

    ostream& operator <<(ostream & output, const rectengal &rec){
        if(rec.gettype()=="bigshape"){                  //if shape is big
            output << "<svg version=\"1.1\""<<endl;       //function write svg codes to file and draw main shape
            output << "baseProfile=\"full\""<<endl;
            output << "width=\""<<rec.getwidth()<<"\" height=\""<<rec.getheight()<<"\""<<endl;
            output << "xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
            output << "<rect width=\"100%\" height=\"100%\" fill=\"red\" />"<<endl;
        }else if(rec.gettype()=="smallshape"){          //if shape is small function draw a small shape (rectengal)
            output << "<rect x=\""<<rec.getx_coordinate()<<"\" y=\""<<rec.gety_coordinate()<<"\" width=\""<<rec.getwidth()<<"\" height=\""<<rec.getheight()<<"\" fill=\"green\" stroke=\"black\"/>"<<endl;
        }
        return output;
    }
}
