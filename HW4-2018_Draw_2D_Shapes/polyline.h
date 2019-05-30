#ifndef POLYLINE_H
#define POLYLINE_H
#include "circle.h"
#include "rectengal.h"
#include "triangle.h"

class Polyline
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

        Polyline();          //default constructur
        ~Polyline();             //destructur
        Polyline(const Polyline &p);          //copy constructur

        Polyline(rectengal rec);
        Polyline(circle circ);       //shape to Polyline constructur
        Polyline(triangle tria);
        Polyline(Point2D po);        //point to Polyline constructur
        Polyline( vector <Point2D> point);       //vector to Polyline constructur

        friend const Polyline operator +(const Polyline &A,const Polyline &B);
        Point2D& operator [](int index);            //operator overloading
        friend ostream& operator <<(ostream & output, const Polyline &poly);
        Polyline& operator =(const Polyline &rightside);
        friend bool operator !=(const Polyline& A,const Polyline& B);
        friend bool operator ==(const Polyline& A,const Polyline& B);

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

#endif // POLYLINE_H
