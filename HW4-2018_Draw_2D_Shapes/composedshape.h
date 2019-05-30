#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H
#include "circle.h"
#include "rectengal.h"
#include "triangle.h"
#include "polygon.h"
#include <vector>
#include <fstream>
#include <string>

using namespace namepolygon;

class composedshape{

    public:
    enum class shapes{
            rectangle,
            circle,
            triangle
    };
        composedshape();            //default constructur
        composedshape(rectengal rec, rectengal recsmall);
        composedshape(rectengal rec, circle circ);
        composedshape(rectengal rec, triangle tria);
        composedshape(circle circ, rectengal rec);       //this constructur for every different condition
        composedshape(circle circ, circle circsmall);
        composedshape(circle circ, triangle tria);
        composedshape(triangle tria, rectengal rec);
        composedshape(triangle tria, circle circ);
        composedshape(triangle tria, triangle triasmall);

        void optimalFit(const char a,const char b,const double length1,const double length2,const double smallength1,const double smallength2);
                        //optimalFit function put small shapes member in to vector of polygon
        void recrec(double width,double height,double smallwidth,double smallheight);
        void rectria(double width,double height,double length);
        void reccirc(double width,double height,double radius);
        void circrect(double radius, double width, double height);     //These functions helper functions for optimalFit
        void circcirc(double radius,double smallradius);                  //this function return a vector to optimalFit
        void circtri(double radius, double length);
        void trirect(double length, double width, double height);
        void tricirc(double length, double radius);
        void tritri(double length, double smallength);

        inline string getName1() const {return name1;}
        inline void setName1(string name){name1=name;}      //set and get function for variables
        inline string getName2() const {return name2;}
        inline void setName2(string name){name2=name;}
        inline void setperimeter(int a){perimeter =a;}
        inline void setarea(int a){area =a;}
        inline int getarea() const {return area;}
        inline int getperimeter() const {return perimeter;}
        inline void setS_perimeter(int a){S_perimeter =a;}
        inline void setS_area(int a){S_area =a;}
        inline int getS_area() const {return S_area;}
        inline int getS_perimeter() const {return S_perimeter;}

        composedshape& operator +=(const Polygon poly);     //add polygon to vector operator
        friend ostream& operator <<(ostream & output, const composedshape &shapes);             //print to svg file operator

        rectengal fakeRec;          //helper shape members
        circle fakeCirc;
        triangle fakeTria;

        vector<Polygon> poly;       //polygon vector


    private:
        string name1;               //these variables for members type
        string name2;
        int area;
        int perimeter;
        int S_area;
        int S_perimeter;

};

#endif // COMPOSEDSHAPE_H
