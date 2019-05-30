#ifndef POLYGONVECT_H
#define POLYGONVECT_H

#include "polygon.h"
#include "polygon.h"
#include "circle.h"
#include "rectengal.h"
#include "triangle.h"
#include "shape.h"

namespace SHAPES{

class polygonVect:public polygon
{
    public:
        polygonVect();
        polygonVect(rectengal rec);
        polygonVect(circle circ);       //shape to polygon constructur
        polygonVect(triangle tria);
        polygonVect(Point2D po);        //point to polygon constructur

        double Area();
        double Perimeter();
        friend ostream& operator <<(ostream & output, const polygonVect &poly);
        bool operator !=(const polygonVect& A);
        bool operator ==(const polygonVect& A);
        friend const polygonVect operator +(const polygonVect &A,const polygonVect& B);
        inline vector<Point2D> getvec() const {return points;}

    private:
        vector<Point2D> points;

};
}
#endif // POLYGONVECT_H
