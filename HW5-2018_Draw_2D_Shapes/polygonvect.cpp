#include "polygonvect.h"
#include "polygon.h"
#include "circle.h"
#include "rectengal.h"
#include "triangle.h"
#include "shape.h"
#define PI 3.14
#include <cmath>

namespace SHAPES{

    polygonVect::polygonVect():polygon(){
        setsize(0);
        points=vector<Point2D>();
        setwidth(0);
        setheight(0);
        settype("");
        setArea(0);
        setPerimeter(0);
    }
    polygonVect::polygonVect(rectengal rec){
                                                    //conversion rectengal to polygon constructur
        Point2D p(rec.getx_coordinate(),rec.gety_coordinate());
        points.push_back(p);

        Point2D p_1(rec.getx_coordinate()+rec.getwidth(),rec.gety_coordinate());
        points.push_back(p_1);

        Point2D p_2(rec.getx_coordinate()+rec.getwidth(),rec.gety_coordinate()+rec.getheight());
        points.push_back(p_2);

        Point2D p_3(rec.getx_coordinate(),rec.gety_coordinate()+rec.getheight());
        points.push_back(p_3);
    }
    polygonVect::polygonVect(circle circ){
                                            //conversion circle to polygon constructur
        for(int i=1; i<=100; i++){
            if(circ.gettype()=="bigshape"){
                Point2D p(circ.getx_coordinate()+(circ.getradius()+circ.getradius()*sin(((2*PI)/100)*i)),circ.gety_coordinate()+(circ.getradius()+circ.getradius()*cos(((2*PI)/100)*i)));
                points.push_back(p);
            }else{
                Point2D p(circ.getx_coordinate()+(circ.getradius()*sin(((2*PI)/100)*i)),circ.gety_coordinate()+(circ.getradius()*cos(((2*PI)/100)*i)));
                points.push_back(p);
            }
        }
    }      //shape to polygon constructur
    polygonVect::polygonVect(triangle tria){
                                        //conversion triangle to polygon constructur
        Point2D p(tria.getx_coordinate(),tria.gety_coordinate());
        points.push_back(p);

        Point2D p_1(tria.getx_coordinate_2(),tria.gety_coordinate_2());
        points.push_back(p_1);

        Point2D p_2(tria.getx_coordinate_3(),tria.gety_coordinate_3());
        points.push_back(p_2);

    }
    polygonVect::polygonVect(Point2D po){
          //conversion one point to polygon constructur
        points.push_back(po);
    }

    double polygonVect::Area(){
        return getArea();
    }
    double polygonVect::Perimeter(){
        return getPerimeter();
    }
    ostream& operator <<(ostream & output, const polygonVect &poly){

        if(poly.gettype()=="bigshape"){
            output << "<svg width=\""<<poly.getwidth()<<"\" height=\""<<poly.getheight()<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;

            output << "<polygon points=\"";                 //in this operator overload function print to file svg code

            for(unsigned int j=0; j<poly.points.size(); j++){
                output <<poly.points[j].getx()<<" ";            //if it is container
                output <<poly.points[j].gety()<<" ";
            }

            output<<"\" fill=\"red\" />"<<endl;

        }else if(poly.gettype()=="smallshape"){

            output << "<polygon points=\"";

            for(unsigned int j=0; j<poly.points.size(); j++){
                output <<poly.points[j].getx()<<" ";
                output <<poly.points[j].gety()<<" ";            //if it is inner
            }
            output<<"\" fill=\"green\"  stroke=\"black\" />"<<endl;
        }
        return  output;
    }
    bool operator !=(const polygonVect& A,const polygonVect& B){

        return !(A==B);
    }
    bool operator ==(const polygonVect& A,const polygonVect& B){
        if(A.getvec().size()!=B.getvec().size())
            return false;           //control two polygon if they  equal

        for(int i=0; i<A.getsize(); i++)
            if((A.getvec()[i].getx()!=B.getvec()[i].getx()) || (A.getvec()[i].gety()!=B.getvec()[i].gety()))
                return false;

        return true;
    }
    const polygonVect operator +(const polygonVect &A,const polygonVect& B){
        unsigned int i;
        polygonVect poly;
                                                        //add two polygon and assign different polygon
        for(i=0; i<A.getvec().size(); i++)
            poly.getvec()[i]=A.getvec()[i];

        for(unsigned int j=i-1, k=0; i<A.getvec().size()+B.getvec().size(); i++, k++)
            poly.getvec()[j]=B.getvec()[k];

        return poly;
    }

}
