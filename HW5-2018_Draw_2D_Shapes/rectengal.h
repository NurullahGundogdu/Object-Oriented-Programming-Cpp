#ifndef RECTENGAL_H
#define RECTENGAL_H

#include "shape.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

namespace SHAPES{

    class rectengal:public shape
    {
        public:
                                //this class contains properties of a rectangular shape
            rectengal();                //default constructur
            rectengal(double Width, double Height);         //this constructur creates a rectangle member

            static double total_Area();             //static funnction for area and perimeter
            static double total_Perimeter();
            double Area() override;
            double Perimeter() override;

            friend ostream& operator <<(ostream & output, const rectengal &rec);
            const rectengal operator +(double number)const;
            const rectengal operator -(double number)const;
            bool operator !=(rectengal& rec);
            bool operator ==(rectengal& rec);         //operator overloading for necessary operation
            bool operator <(rectengal& rec);
            bool operator >(rectengal& rec);
            rectengal& operator ++() override;
            rectengal& operator ++(int) override;
            rectengal& operator --() override;
            rectengal& operator --(int) override;

            inline void setwidth(const double a){width=a;}
            inline void setheight(const double a){height=a;}
            inline double getwidth() const {return width;}
            inline double getheight()const {return height;}
            inline void setx_coordinate(const double a){x_coordinate=a;}
            inline void sety_coordinate(const double a){y_coordinate=a;}
            inline double getx_coordinate() const {return x_coordinate;}        //set and get function for variables
            inline double gety_coordinate() const {return y_coordinate;}
            inline string gettype() const {return type;}
            inline void settype(string name){type=name;}
            inline static void setperimeter(double a){perimeter =a;}
            inline static void setarea(double a){area =a;}

        private:
            string type;                    //this variable for the underdstand shape big or small
            double x_coordinate;            //these variables for the starting points of the rectangle
            double y_coordinate;
            double width;               //this variables for rectengal sizes
            double height;
            static double perimeter;
            static double area;
    };

}

#endif // RECTENGAL_H
