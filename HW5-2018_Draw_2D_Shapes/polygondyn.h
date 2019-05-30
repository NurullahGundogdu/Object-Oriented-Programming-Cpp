#ifndef POLYGONDYN_H
#define POLYGONDYN_H

#include "polygon.h"
#include "polygon.h"
#include "circle.h"
#include "rectengal.h"
#include "triangle.h"
#include "shape.h"

    namespace SHAPES{

    class polygonDyn:public polygon
    {
        public:
            polygonDyn();
            ~polygonDyn();
            polygonDyn(const polygonDyn &p);

            polygonDyn(rectengal rec);
            polygonDyn(circle circ);       //shape to polygon constructur
            polygonDyn(triangle tria);
            polygonDyn(Point2D po);        //point to polygon constructur
            polygonDyn( vector <Point2D> &point);

            double Area();
            double Perimeter();
            polygonDyn& operator =(const polygonDyn &rightside);
            friend ostream& operator <<(ostream & output, const polygonDyn &poly);
            bool operator !=(const polygonDyn& A);
            bool operator ==(const polygonDyn& A);
            friend const polygonDyn operator +(const polygonDyn &A,const polygonDyn& B);
            inline Point2D* getvec() const {return points;}

        private:
            Point2D *points;
    };
}
#endif // POLYGONDYN_H
