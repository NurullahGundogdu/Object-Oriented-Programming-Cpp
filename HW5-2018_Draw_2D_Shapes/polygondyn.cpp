#include "polygondyn.h"

#include "polygon.h"
#include "circle.h"
#include "rectengal.h"
#include "triangle.h"
#include "shape.h"
#define PI 3.14
#include <cmath>

namespace SHAPES{

    polygonDyn::polygonDyn():polygon(){
        setsize(0);
        points=new Point2D[getsize()];
        setwidth(0);
        setheight(0);
        settype("");
        setArea(0);
        setPerimeter(0);
    }

    polygonDyn::~polygonDyn(){
        delete [] points;
    }
    polygonDyn::polygonDyn(rectengal rec){
                                                    //conversion rectengal to polygon constructur
        setsize(4);

        points=new Point2D[getsize()];
                                                //conversion rectengal to polygon constructur
        Point2D p(rec.getx_coordinate(),rec.gety_coordinate());
        points[0]= p;

        Point2D p_1(rec.getx_coordinate()+rec.getwidth(),rec.gety_coordinate());
        points[1]= p_1;

        Point2D p_2(rec.getx_coordinate()+rec.getwidth(),rec.gety_coordinate()+rec.getheight());
        points[2]=p_2;

        Point2D p_3(rec.getx_coordinate(),rec.gety_coordinate()+rec.getheight());
        points[3]=p_3;
    }
    polygonDyn::polygonDyn(circle circ){

        setsize(100);

        points=new Point2D[getsize()];
                                            //conversion circle to polygon constructur
        for(int i=1; i<=100; i++){
            if(circ.gettype()=="bigshape"){
                Point2D p(circ.getx_coordinate()+(circ.getradius()+circ.getradius()*sin(((2*PI)/100)*i)),circ.gety_coordinate()+(circ.getradius()+circ.getradius()*cos(((2*PI)/100)*i)));
                points[i-1]=p;
            }else{
                Point2D p(circ.getx_coordinate()+(circ.getradius()*sin(((2*PI)/100)*i)),circ.gety_coordinate()+(circ.getradius()*cos(((2*PI)/100)*i)));
                points[i-1]=p;
            }
        }
    }
    polygonDyn::polygonDyn(triangle tria){
                                        //conversion triangle to polygon constructur
        setsize(3);

        points=new Point2D[getsize()];
                                        //conversion triangle to polygon constructur
        Point2D p(tria.getx_coordinate(),tria.gety_coordinate());
        points[0]=p;

        Point2D p_1(tria.getx_coordinate_2(),tria.gety_coordinate_2());
        points[1]=p_1;

        Point2D p_2(tria.getx_coordinate_3(),tria.gety_coordinate_3());
        points[2]=p_2;

    }
    polygonDyn::polygonDyn( vector <polygon::Point2D> &point){

        setsize(point.size());
        points=new Point2D[getsize()];

        for(int i=0; i<getsize(); i++)          //conversion point2d vector to polygon constructur
            points[i]=point[i];

        settype("smallshape");
    }
    polygonDyn::polygonDyn(polygon::Point2D po){

        setsize(1);
        points=new Point2D[getsize()];          //conversion one point to polygon constructur
        points[0]=po;
    }

    double polygonDyn::Area(){
        return getArea();

    }
    double polygonDyn::Perimeter(){
        return getPerimeter();
    }
    ostream& operator <<(ostream & output, const polygonDyn &poly){

        if(poly.gettype()=="bigshape"){
            output << "<svg width=\""<<poly.getwidth()<<"\" height=\""<<poly.getheight()<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;

            output << "<polygon points=\"";                 //in this operator overload function print to file svg code

            for(int j=0; j<poly.getsize(); j++){
                output <<poly.points[j].getx()<<" ";            //if it is container
                output <<poly.points[j].gety()<<" ";
            }

            output<<"\" fill=\"red\" />"<<endl;

        }else if(poly.gettype()=="smallshape"){

            output << "<polygon points=\"";

            for(int j=0; j<poly.getsize(); j++){
                output <<poly.points[j].getx()<<" ";
                output <<poly.points[j].gety()<<" ";            //if it is inner

            }

            output<<"\" fill=\"green\"  stroke=\"black\" />"<<endl;
        }
        return  output;
    }
    bool operator !=(const polygonDyn& A,const polygonDyn& B){
        return !(A==B);
    }
    bool operator ==(const polygonDyn& A,const polygonDyn& B){

        if(A.getsize()!=B.getsize())
            return false;           //control two polygon if they  equal

        for(int i=0; i<A.getsize(); i++)
            if((A.getvec()[i].getx()!=B.getvec()[i].getx()) || (A.getvec()[i].gety()!=B.getvec()[i].gety()))
                return false;

        return true;
    }
    const polygonDyn operator +(const polygonDyn &A,const polygonDyn& B){
        int i;
        polygonDyn poly;
        poly.setsize(A.getsize()+B.getsize());
                                                        //add two polygon and assign different polygon
        for(i=0; i<A.getsize(); i++)
            poly.getvec()[i]=A.getvec()[i];

        for(int j=i-1, k=0; i<A.getsize()+B.getsize(); i++, k++)
            poly.getvec()[j]=B.getvec()[k];

        return poly;
    }
    polygonDyn& polygonDyn::operator =(const polygonDyn &rightside){
        if(getsize()!=rightside.getsize()){
            delete [] points;
            points=new Point2D[rightside.getsize()];
        }
                    //assign polygon to polygon
        setsize(rightside.getsize());
        setwidth(rightside.getwidth());
        setheight(rightside.getheight());
        settype(rightside.gettype());

        for(int i=0; i<getsize(); i++)
            points[i]=rightside.points[i];

        return *this;

    }
}
