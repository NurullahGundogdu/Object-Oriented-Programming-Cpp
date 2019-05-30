#ifndef POLYGON_H
#define POLYGON_H
#include "circle.h"
#include "rectengal.h"
#include "triangle.h"

namespace namepolygon{

    class Polygon
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

            Polygon();          //default constructur
            ~Polygon();             //destructur
            Polygon(const Polygon &p);          //copy constructur

            Polygon(rectengal rec);
            Polygon(circle circ);       //shape to polygon constructur
            Polygon(triangle tria);
            Polygon(Point2D po);        //point to polygon constructur
            Polygon( vector <Point2D> point);       //vector to polygon constructur

            friend const Polygon operator +(const Polygon &A,const Polygon &B);
            Point2D& operator [](int index);            //operator overloading
            friend ostream& operator <<(ostream & output, const Polygon &poly);
            Polygon& operator =(const Polygon &rightside);
            friend bool operator !=(const Polygon& A,const Polygon& B);
            friend bool operator ==(const Polygon& A,const Polygon& B);

            inline void setsize(const int a){sizes=a;}            //set and get function for variables
            inline int getsize() const {return sizes;}
            inline void setwidth(const double a){width=a;}            //set and get function for variables
            inline double getwidth() const {return width;}
            inline void setheight(const double a){height=a;}            //set and get function for variables
            inline double getheight() const {return height;}
            inline string gettype() const {return type;}
            inline void settype(string name){type=name;}

        private:
            Point2D *points;
            int sizes;          //necesseray variable
            int width;
            int height;
            string type;

    };

}
#endif // POLYGON_H
