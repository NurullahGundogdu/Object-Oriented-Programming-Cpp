#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include <fstream>
#include <string>
#include "shape.h"

using namespace std;

namespace SHAPES{

    class triangle:public shape
    {
        public:
            triangle();             //default constructur
            triangle(double Length);        //this constructur creates a triangle member

            static double total_Area();
            static double total_Perimeter();
            double Area() override;
            double Perimeter() override;

            friend ostream& operator <<(ostream & output, const triangle &tria);
            const triangle operator +(double number)const;
            const triangle operator -(double number)const;
            bool operator !=(triangle& tria);
            bool operator ==(triangle& tria);
            bool operator <(triangle& tria);          //operator overloading for necessary operation
            bool operator >(triangle& tria);
            triangle& operator ++() override;
            triangle& operator ++(int) override;
            triangle& operator --() override;
            triangle& operator --(int) override;

            inline void setlength(const double a){length=a;}
            inline double getlength() const {return length;}

            inline void setx_coordinate(const double a){x_coordinate=a;}
            inline void sety_coordinate(const double a){y_coordinate=a;}
            inline double getx_coordinate() const {return x_coordinate;}
            inline double gety_coordinate() const {return y_coordinate;}        //set and get function for variables
            inline void setx_coordinate_2(const double a){x_coordinate_2=a;}
            inline void sety_coordinate_2(const double a){y_coordinate_2=a;}
            inline double getx_coordinate_2() const {return x_coordinate_2;}
            inline double gety_coordinate_2() const {return y_coordinate_2;}
            inline void setx_coordinate_3(const double a){x_coordinate_3=a;}
            inline void sety_coordinate_3(const double a){y_coordinate_3=a;}
            inline double getx_coordinate_3() const {return x_coordinate_3;}
            inline double gety_coordinate_3() const {return y_coordinate_3;}

            inline string gettype() const {return type;}
            inline void settype(string name){type=name;}
            inline static void setperimeter(double a){perimeter =a;}
            inline static void setarea(double a){area =a;}


        private:
            string type;                 //this variable for the underdstand shape big or small
            double length;              //this variables for triangle sizes
            double x_coordinate;
            double y_coordinate;
            double x_coordinate_2;
            double y_coordinate_2;      //these variables for the starting points of the triangle
            double x_coordinate_3;
            double y_coordinate_3;
            static double perimeter;
            static double area;

    };
}
#endif // TRIANGLE_H
