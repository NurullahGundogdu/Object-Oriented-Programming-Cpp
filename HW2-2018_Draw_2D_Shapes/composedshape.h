#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H
#include "circle.h"
#include "rectangal.h"
#include "triangle.h"
#include<vector>
#include <fstream>

class composedshape{
    public:
        composedshape();
        composedshape(rectengal rec, rectengal recsmall,ofstream &file);
        composedshape(rectengal rec, circle circ,ofstream &file);
        composedshape(rectengal rec, triangle tria,ofstream &file);
        composedshape(circle circ, rectengal rec,ofstream &file);
        composedshape(circle circ, circle circsmall,ofstream &file);
        composedshape(circle circ, triangle tria,ofstream &file);
        composedshape(triangle tria, rectengal rec,ofstream &file);
        composedshape(triangle tria, circle circ,ofstream &file);
        composedshape(triangle tria, triangle triasmall,ofstream &file);

        void draw(ofstream &file);
        void optimalFit(const char a,const char b,const double length1,const double length2,const double smallength1,const double smallength2);

        vector<rectengal> recrec(double width,double height,double smallwidth,double smallheight);
        vector<triangle> rectria(double width,double height,double length);
        vector<circle> reccirc(double width,double height,double radius);
        vector<rectengal> circrect(double radius, double width, double height);
        vector<circle> circcirc(double radius,double smallradius);
        vector<triangle> circtri(double radius, double length);
        vector<rectengal> trirect(double length, double width, double height);
        vector<circle> tricirc(double length, double radius);
        vector<triangle> tritri(double length, double smallength);

        vector<rectengal> getrectVector(){return rectVector;}
        vector<rectengal> rectVector;
        vector<circle> getcircVector(){return circVector;}
        vector<circle> circVector;
        vector<triangle> gettriaVector(){return triaVector;}
        vector<triangle> triaVector;


        inline string getName1() const {return name1;}
        inline void setName1(string name){name1=name;}
        inline string getName2() const {return name2;}
        inline void setName2(string name){name2=name;}

        rectengal fakeRec;
        circle fakeCirc;
        triangle fakeTria;
    private:
        string name1;
        string name2;

};

#endif // COMPOSEDSHAPE_H
