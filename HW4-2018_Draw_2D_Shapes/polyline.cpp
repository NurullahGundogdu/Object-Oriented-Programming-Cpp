#include "polyline.h"
#include "circle.h"
#include "rectengal.h"
#include "triangle.h"
#include <vector>
#include <iostream>
#define PI 3.14
#include <cmath>

Polyline::Polyline():sizes(0),width(0.0),height(0.0),type(""){
}           //default constructur

Polyline::~Polyline(){  //destructur
    delete [] points;

}
Polyline::Polyline(const Polyline &p):sizes(p.getsize()),width(p.getwidth()),height(p.getheight()),type(p.gettype()){//copy constructur

    points=new Point2D[sizes];          //copy constructur

    for(int i=0; i<sizes; i++)
        points[i]=p.points[i];

}

Polyline::Polyline(rectengal rec){

    sizes=4;

    points=new Point2D[4];
                                            //conversion rectengal to Polyline constructur
    Point2D p(rec.getx_coordinate(),rec.gety_coordinate());
    points[0]= p;

    Point2D p_1(rec.getx_coordinate()+rec.getwidth(),rec.gety_coordinate());
    points[1]= p_1;

    Point2D p_2(rec.getx_coordinate()+rec.getwidth(),rec.gety_coordinate()+rec.getheight());
    points[2]=p_2;

    Point2D p_3(rec.getx_coordinate(),rec.gety_coordinate()+rec.getheight());
    points[3]=p_3;


}
Polyline::Polyline(circle circ){

    sizes=100;

    points=new Point2D[sizes];
                                        //conversion circle to Polyline constructur
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

Polyline::Polyline(triangle tria){

    sizes=3;

    points=new Point2D[sizes];
                                    //conversion triangle to Polyline constructur
    Point2D p(tria.getx_coordinate(),tria.gety_coordinate());
    points[0]=p;

    Point2D p_1(tria.getx_coordinate_2(),tria.gety_coordinate_2());
    points[1]=p_1;

    Point2D p_2(tria.getx_coordinate_3(),tria.gety_coordinate_3());
    points[2]=p_2;

}


Polyline::Polyline( vector <Polyline::Point2D> point):width(0.0),height(0.0){

    sizes=point.size();
    points=new Point2D[sizes];

    for(int i=0; i<sizes; i++)          //conversion point2d vector to Polyline constructur
        points[i]=point[i];

    type="smallshape";
}

Polyline::Polyline(Point2D po):width(0.0),height(0.0),type(""){

    sizes=1;
    points=new Point2D[sizes];          //conversion one point to Polyline constructur
    points[0]=po;

}

Polyline::Point2D::Point2D():x(0),y(0){
}           //default constructur for point2d

Polyline::Point2D::Point2D(double x, double y){
    setx(x);
    sety(y);                //point save
}

ostream& operator <<(ostream & output, const Polyline &poly){

    if(poly.gettype()=="bigshape"){
        output << "<svg width=\""<<poly.getwidth()<<"\" height=\""<<poly.getheight()<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;

        output << "<Polyline points=\"";                 //in this operator overload function print to file svg code

        for(int j=0; j<poly.sizes; j++){
            output <<poly.points[j].getx()<<" ";            //if it is container
            output <<poly.points[j].gety()<<" ";
        }

        output<<"\" fill=\"red\" />"<<endl;

    }else if(poly.gettype()=="smallshape"){

        output << "<Polyline points=\"";

        for(int j=0; j<poly.sizes; j++){
            output <<poly.points[j].getx()<<" ";
            output <<poly.points[j].gety()<<" ";            //if it is inner

        }

        output<<"\" fill=\"green\"  stroke=\"black\" />"<<endl;
    }else{
        output <<"<svg height=\"200\" width=\"500\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
        output <<"<polyline points=\"20,20 40,25 60,40 80,120 120,140 200,180\""<<endl;             //example polynom
        output <<"style=\"fill:none;stroke:black;stroke-width:3\" />"<<endl;
        output <<"</svg>"<<endl;


    }
    return  output;
}

const Polyline operator +(const Polyline &A,const Polyline &B){

    int i;
    Polyline poly;
    poly.sizes=A.sizes+B.sizes;
                                                    //add two Polyline and assign different Polyline
    poly.points=new Polyline::Point2D[poly.sizes];

    for(i=0; i<A.sizes; i++)
        poly.points[i]=A.points[i];

    for(int j=i-1, k=0; i<A.sizes+B.sizes; i++, k++)
        poly.points[j]=B.points[k];

    return poly;
}

Polyline& Polyline::operator =(const Polyline &rightside){
    if(sizes!=rightside.sizes){
        delete []points;
        points=new Point2D[rightside.sizes];
    }
                //assign Polyline to Polyline
    sizes=rightside.sizes;
    width=rightside.getwidth();
    height=rightside.getheight();
    type=rightside.gettype();

    for(int i=0; i<sizes; i++)
        points[i]=rightside.points[i];

    return *this;
}

Polyline::Point2D& Polyline::operator [](int index){
    if(index>=sizes)
        index=sizes-1;          //that returns a reference to the point at the given index.
    return points[index];
}

bool operator !=(const Polyline& A,const Polyline& B){

        return !(A==B);         //control two Polyline if they do not equal

}

bool operator ==(const Polyline& A,const Polyline& B){

    if(A.getsize()!=B.getsize())
        return false;           //control two Polyline if they  equal

    for(int i=0; i<A.getsize(); i++)
        if((A.points[0].getx()!=B.points[0].getx()) || (A.points[0].gety()!=B.points[0].gety()))
            return false;

    return true;
}
