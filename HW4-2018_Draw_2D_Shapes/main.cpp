#include <iostream>
#include "circle.h"
#include "rectengal.h"
#include "triangle.h"
#include "ComposedShape.h"
#include "polyline.h"
#include "polygon.h"

using namespace std;

namespace{

    Polygon pol_3,pol_4;
    Polyline poly_3,poly_4;
}


int main(){

    string filename[9];

    filename[0]="result0.svg";
    filename[1]="result1.svg";          //svg filename
    filename[2]="result2.svg";
    filename[3]="result3.svg";
    filename[4]="result4.svg";


    composedshape cs[5];

    rectengal r1(500,500);      //rectengal shape
    rectengal r2=r1-469;

    triangle t1(760);       //triangle shape
    triangle t2=t1-618;

    circle c1(500);             //circle shape
    circle c2=c1-450;

    composedshape csrc(r1,r2);
    composedshape csct(c1,t2);
    composedshape cstr(t1,r2);          //composed object
    composedshape cscr(c1,r2);
    composedshape cstc(t1,c2);
    composedshape csrt(r1,t2);


    cs[0]=csrc;
    cs[1]=csct;
    cs[2]=cstr;
    cs[3]=cscr;
    cs[4]=cstc;

    for(int i=0; i<5; i++){
        ofstream file;
        file.open(filename[i]);         //print file
        file<<cs[i];
        file.close();
    }


    Polygon pol_1(r1);
    Polygon pol_12(r1);         //polygon class operator overloading
    Polygon pol_2(c1);


    pol_3=pol_1+pol_2;      //addition two polygon and assign other polygon

    pol_4=pol_3;        //assign poligon to other poligon

    if(pol_1==pol_12){
        /*
           optinal  operation
            */
    }

    if(pol_2!=pol_3){
      /*
       optinal  operation
        */
    }

    Polyline poly_1(r1);
    Polyline poly_12(r1);
    Polyline poly_2(c1);        //polyline class operator overloading


    poly_3=poly_1+poly_2;      //addition two polygon and assign other polygon

    poly_4=poly_3;        //assign poligon to other poligon

    if(poly_1==poly_12){
        /*
           optinal  operation
            */
    }

    if(poly_2!=poly_3){
      /*
       optinal  operation
        */
    }
    ofstream file;
    file.open("result_polyline.svg");         //print example polynom
    file<<poly_4;
    file.close();

    return 0;
}
