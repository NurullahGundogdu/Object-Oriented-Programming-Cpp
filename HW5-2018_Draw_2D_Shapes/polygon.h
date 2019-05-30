#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include "circle.h"
#include "rectengal.h"
#include "triangle.h"

using namespace std;

namespace SHAPES{

    class polygon:public shape
    {
        public:
            class Point2D{
                public:
                    Point2D();          //default constructur
                    Point2D(double x, double y);
                    inline void setx(const double a){x=a;}
                    inline void sety(const double a){y=a;}            //set and get function for variables
                    inline double getx() const {return x;}
                    inline double gety() const {return y;}
                private:
                    double x;
                    double y;       // x and y coordinate

            };

            polygon();          //default constructur

            virtual double Area()=0;
            virtual double Perimeter()=0;
            virtual polygon& operator ++();
            virtual polygon& operator ++(int);
            virtual polygon& operator --();
            virtual polygon& operator --(int);

            friend ostream& operator <<(ostream & output, const polygon &poly);
            friend bool operator !=(const polygon& A,const polygon& B);
            friend bool operator ==(const polygon& A,const polygon& B);
            friend const polygon& operator +(const polygon &A,const polygon &B);

            inline void setsize(const int a){sizes=a;}            //set and get function for variables
            inline int getsize() const {return sizes;}
            inline void setwidth(const double a){width=a;}            //set and get function for variables
            inline double getwidth() const {return width;}
            inline void setheight(const double a){height=a;}            //set and get function for variables
            inline double getheight() const {return height;}
            inline string gettype() const {return type;}
            inline void settype(string name){type=name;}
            inline void setArea(const double a){pol_area=a;}            //set and get function for variables
            inline double getArea() const {return pol_area;}
            inline void setPerimeter(const double a){pol_perimeter=a;}            //set and get function for variables
            inline double getPerimeter() const {return pol_perimeter;}

        private:
            int sizes;          //necesseray variable
            int width;
            int height;
            string type;
            double pol_area;
            double pol_perimeter;


    };
}

#endif // POLYGON_H
