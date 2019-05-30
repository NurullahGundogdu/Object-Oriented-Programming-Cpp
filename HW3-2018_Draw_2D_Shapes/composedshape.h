#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H
#include "circle.h"
#include "rectengal.h"
#include "triangle.h"
#include <vector>
#include <fstream>
#include <string>

class composedshape{

    public:
    enum class shapes{
            rectangle,
            circle,
            triangle
    };

    class ShapeElem{
        public:
            ShapeElem();
            ShapeElem(rectengal *rec,shapes b);
            ShapeElem(circle *circ,shapes b);
            ShapeElem(triangle *tria,shapes b);

            double Elem_perimeter();
            double Elem_area();
            friend ostream& operator <<(ostream & output, const ShapeElem &elem);
            inline void setarea(double a){area=a;}
            inline void setperimeter(double a){perimeter=a;}
        private:
            void *shape_objects;
            shapes typename_of_shapes;
            double perimeter;
            double area;
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
                        //optimalFit function put small shapes member in to vector
        vector<ShapeElem> recrec(double width,double height,double smallwidth,double smallheight);
        vector<ShapeElem> rectria(double width,double height,double length);
        vector<ShapeElem> reccirc(double width,double height,double radius);
        vector<ShapeElem> circrect(double radius, double width, double height);     //These functions helper functions for optimalFit
        vector<ShapeElem> circcirc(double radius,double smallradius);                  //this function return a vector to optimalFit
        vector<ShapeElem> circtri(double radius, double length);
        vector<ShapeElem> trirect(double length, double width, double height);
        vector<ShapeElem> tricirc(double length, double radius);
        vector<ShapeElem> tritri(double length, double smallength);

        inline string getName1() const {return name1;}
        inline void setName1(string name){name1=name;}      //set and get function for variables
        inline string getName2() const {return name2;}
        inline void setName2(string name){name2=name;}

        vector<ShapeElem> innerShape;
        composedshape operator +=(const rectengal &rec);
        const ShapeElem &operator [](int i)const{
            return innerShape[i];
        }
        friend ostream& operator <<(ostream & output, const composedshape &shapes);

        rectengal fakeRec;          //helper shape members
        circle fakeCirc;
        triangle fakeTria;
    private:
        string name1;               //these variables for members type
        string name2;
};

#endif // COMPOSEDSHAPE_H
