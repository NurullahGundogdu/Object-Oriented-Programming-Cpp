#include "composedshape.h"
#include "circle.h"
#include "rectengal.h"
#include "triangle.h"
#include "polygon.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#define PI 3.14

using namespace namepolygon;

composedshape::composedshape():name1(""),name2(""),area(0),perimeter(0){     //default constructur
}

composedshape::composedshape(rectengal rec, rectengal recsmall){

    fakeRec.setwidth(rec.getwidth());           //received big shape member assigned to member in constructur
    fakeRec.setheight(rec.getheight());         //this construction for rectengal in rectengal
    fakeRec.settype("bigshape");

    setarea(rec.getwidth()*rec.getheight());            //calculate container area and perimeter
    setperimeter(2*(rec.getwidth()+rec.getheight()));
    setS_area(recsmall.getwidth()*recsmall.getheight());            //calculate container area and perimeter
    setS_perimeter(2*(recsmall.getwidth()+recsmall.getheight()));

    setName1("R");              //assign shapes type
    setName2("R");

    optimalFit('R','R',rec.getwidth(),rec.getheight(),recsmall.getwidth(),recsmall.getheight());        //small shapes member assing to vector

}

composedshape::composedshape(rectengal rec, circle circ){

    fakeRec.setwidth(rec.getwidth());              //received big shape member assigned to member in constructur
    fakeRec.setheight(rec.getheight());         //this construction for circle in rectengal
    fakeRec.settype("bigshape");

    setarea(rec.getwidth()*rec.getheight());                //calculate container area and perimeter
    setperimeter(2*(rec.getwidth()+rec.getheight()));
    setS_area(PI*circ.getradius()*circ.getradius());            //calculate container area and perimeter
    setS_perimeter(circ.getradius()*2*PI);

    setName1("R");          //assign shapes type
    setName2("C");

    optimalFit('R','C',rec.getwidth(),rec.getheight(),circ.getradius(),circ.getradius());       //small shapes member assing to vector

}

composedshape::composedshape(rectengal rec, triangle tria){

    fakeRec.setwidth(rec.getwidth());       //received big shape member assigned to member in constructur
    fakeRec.setheight(rec.getheight());     //this construction for triangle in rectengal
    fakeRec.settype("bigshape");

    setarea(rec.getwidth()*rec.getheight());
    setperimeter(2*(rec.getwidth()+rec.getheight()));           //calculate container area and perimeter
    setS_area((tria.getlength()*(tria.getlength()/2*sqrt(3)))/2);           //calculate container area and perimeter
    setS_perimeter(3*tria.getlength());

    setName1("R");          //assign shapes type
    setName2("T");

    optimalFit('R','T',rec.getwidth(),rec.getheight(),tria.getlength(),tria.getlength());      //small shapes member assing to vector

}

composedshape::composedshape(circle circ, rectengal rec){

    fakeCirc.setradius(circ.getradius());   //received big shape member assigned to member in constructur
    fakeCirc.settype("bigshape");           //this construction for rectengal in circle

    setarea(PI*circ.getradius()*circ.getradius());
    setperimeter(circ.getradius()*2*PI);            //calculate container area and perimeter
    setS_area(rec.getwidth()*rec.getheight());            //calculate container area and perimeter
    setS_perimeter(2*(rec.getwidth()+rec.getheight()));

    setName1("C");
    setName2("R");          //assign shapes type

    optimalFit('C','R',circ.getradius(),circ.getradius(),rec.getwidth(),rec.getheight());      //small shapes member assing to vector

}

composedshape::composedshape(circle circ, circle circsmall){

    fakeCirc.setradius(circ.getradius());       //this construction for circle in circle
    fakeCirc.settype("bigshape");               //received big shape member assigned to member in constructur

    setarea(PI*circ.getradius()*circ.getradius());
    setperimeter(circ.getradius()*2*PI);            //calculate container area and perimeter
    setS_area(PI*circsmall.getradius()*circsmall.getradius());            //calculate container area and perimeter
    setS_perimeter(circsmall.getradius()*2*PI);

    setName1("C");                    //assign shapes type
    setName2("C");

    optimalFit('C','C',circ.getradius(),circ.getradius(),circsmall.getradius(),circsmall.getradius());      //small shapes member assing to vector

}

composedshape::composedshape(circle circ, triangle tria){

    fakeCirc.setradius(circ.getradius());       //received big shape member assigned to member in constructur
    fakeCirc.settype("bigshape");           //this construction for triangle in circle

    setarea(PI*circ.getradius()*circ.getradius());
    setperimeter(circ.getradius()*2*PI);            //calculate container area and perimeter
    setS_area((tria.getlength()*(tria.getlength()/2*sqrt(3)))/2);            //calculate container area and perimeter
    setS_perimeter(3*tria.getlength());

    setName1("C");                    //assign shapes type
    setName2("T");

    optimalFit('C','T',circ.getradius(),circ.getradius(),tria.getlength(),tria.getlength());      //small shapes member assing to vector

}

composedshape::composedshape(triangle tria, rectengal rec){

    fakeTria.setlength(tria.getlength());   //received big shape member assigned to member in constructur
    fakeTria.settype("bigshape");           //this construction for rectengal in triangle

    setarea((tria.getlength()*(tria.getlength()/2*sqrt(3)))/2);
    setperimeter(3*tria.getlength());               //calculate container area and perimeter
    setS_area(rec.getwidth()*rec.getheight());            //calculate container area and perimeter
    setS_perimeter(2*(rec.getwidth()+rec.getheight()));

    setName1("T");
    setName2("R");                    //assign shapes type

    optimalFit('T','R',tria.getlength(),tria.getlength(),rec.getwidth(),rec.getheight());      //small shapes member assing to vector

}

composedshape::composedshape(triangle tria, circle circ){

    fakeTria.setlength(tria.getlength());   //received big shape member assigned to member in constructur
    fakeTria.settype("bigshape");           //this construction for circle in triangle

    setarea((tria.getlength()*(tria.getlength()/2*sqrt(3)))/2);
    setperimeter(3*tria.getlength());               //calculate container area and perimeter
    setS_area(PI*circ.getradius()*circ.getradius());            //calculate container area and perimeter
    setS_perimeter(circ.getradius()*2*PI);

    setName1("T");                    //assign shapes type
    setName2("C");

    optimalFit('T','C',tria.getlength(),tria.getlength(),circ.getradius(),circ.getradius());      //small shapes member assing to vector

}

composedshape::composedshape(triangle tria, triangle triasmall){

    fakeTria.setlength(tria.getlength());   //received big shape member assigned to member in constructur
    fakeTria.settype("bigshape");           //this construction for triangle in triangle

    setarea((tria.getlength()*(tria.getlength()/2*sqrt(3)))/2);
    setperimeter(3*tria.getlength());               //calculate container area and perimeter
    setS_area((triasmall.getlength()*(triasmall.getlength()/2*sqrt(3)))/2);            //calculate container area and perimeter
    setS_perimeter(3*triasmall.getlength());

    setName1("T");
    setName2("T");                        //assign shapes type

    optimalFit('T','T',tria.getlength(),tria.getlength(),triasmall.getlength(),triasmall.getlength());      //small shapes member assing to vector
}

ostream& operator <<(ostream & output, const composedshape &shapes){

    int shapenum=-1;

    int emptyArea=0,totalperimeter=0,totalarea=0;



    for(unsigned int i=0; i<shapes.poly.size(); i++){
        output<<shapes.poly[i];
        shapenum++;
    }

    output<<"</svg>";

    totalperimeter=shapes.getperimeter()+(shapenum*shapes.getS_perimeter());
    totalarea=shapes.getarea()+(shapenum*shapes.getS_area());
    emptyArea=shapes.getarea()-(shapenum*shapes.getS_area());


    cout<<"I can fit at most "<<shapenum<<" small shapes into the main container. The empty area (red) in container is "<<emptyArea<<"."<<endl;
    cout<<"Total area of shapes "<<totalarea<<", total perimeter of shapes "<<totalperimeter<<"."<<endl;


    return output;
}

composedshape& composedshape::operator +=(const Polygon pol){
    poly.push_back(pol);
    return *this;
}

void composedshape::optimalFit(char name,char name2,double length1,double length2,double smallength1,double smallength2){

    if(name=='R' && name2=='R'){
        recrec(length1,length2,smallength1,smallength2);
    }else if(name=='R' && name2=='C'){
        reccirc(length1,length2,smallength1);
    }else if(name=='R' && name2=='T'){
        rectria(length1,length2,smallength1);
    }else if(name=='C' && name2=='R'){                              //helper functions are called according to conditions
        circrect(length1,smallength1,smallength2);
    }else if(name=='C' && name2=='C'){
        circcirc(length1,smallength1);                   //small shape members assign to vector
    }else if(name=='C' && name2=='T'){
        circtri(length1,smallength1);
    }else if(name=='T' && name2=='R'){
        trirect(length1,smallength1,smallength2);
    }else if(name=='T' && name2=='C'){
        tricirc(length1,smallength1);
    }else if(name=='T' && name2=='T'){
        tritri(length1,smallength1);
    }
}

void composedshape::recrec(double width,double height,double smallwidth,double smallheight){

    double i,j;

    auto a=width/smallwidth;
    auto b=height/smallheight;
    auto c=width/smallheight;
    auto d=height/smallwidth;


    fakeRec.setx_coordinate(0);
    fakeRec.sety_coordinate(0);
    Polygon poly(fakeRec);          //container shape coordinate asiggn
    poly.settype(fakeRec.gettype());
    poly.setheight(fakeRec.getheight());
    poly.setwidth(fakeRec.getwidth());
    *this+=poly;                      //conversion container shape to polygon  and add to polygon vector

    if((a*b)>=(c*d)){
        for(i=0; i<width; i=i+smallwidth)
            for(j=0; j<height; j=j+smallheight){         //if more is drawn in the horizontal drawing this loop work
                if(j+smallheight<=height && i+smallwidth<=width){
                    rectengal ptr=rectengal(smallwidth,smallheight);
                    ptr.setx_coordinate(i);           //coordinate assign to members variable
                    ptr.sety_coordinate(j);   //small shapes member asign to vector
                    ptr.settype("smallshape");
                    Polygon poly1(ptr);
                    poly1.settype(ptr.gettype());   //conversion inner shape to polygon  and add to polygon vector
                    *this+=poly1;
                }
            }
    }else{
        for(i=0; i<width; i=i+smallheight)
            for(j=0; j<height; j=j+smallwidth){         //if more is drawn in the vertical drawing this loop work
                if(i+smallheight<=width && j+smallwidth<=height){
                    rectengal ptr=rectengal(smallwidth,smallheight);
                    ptr.setx_coordinate(i);        //coordinate assign to members variable
                    ptr.sety_coordinate(j);
                    ptr.settype("smallshape");
                    Polygon poly1(ptr);             //conversion inner shape to polygon  and add to polygon vector
                    poly1.settype(ptr.gettype());
                    *this+=poly1;
                }
            }
    }
}

void composedshape::rectria(double width,double height,double length){

    double i,j,p2x=0,p3x=0,p3y=0;

    fakeRec.setx_coordinate(0);
    fakeRec.sety_coordinate(0);
    Polygon poly(fakeRec);          //container shape coordinate asiggn
    poly.settype(fakeRec.gettype());
    poly.setheight(fakeRec.getheight());
    poly.setwidth(fakeRec.getwidth());
    *this+=poly;        //conversion container shape to polygon  and add to polygon vector

     for(j=0; j<height; j+=(length/2)*sqrt(3))
        for(i=0; i<width; i+=length){
            p3x=i+length;               //in here loops draw triangles 0-width and calculate x and y coordinate
            p3y=j+length/2*sqrt(3);
            if(p3x<width && p3y<height){
                triangle temp=triangle(length);
                temp.setx_coordinate(i);
                temp.sety_coordinate(j+length/2*sqrt(3));
                temp.setx_coordinate_2(i+length/2);         //coordinate assign to members variable
                temp.sety_coordinate_2(j);
                temp.setx_coordinate_3(i+length);
                temp.sety_coordinate_3(j+length/2*sqrt(3));
                temp.settype("smallshape");              //small shapes member asign to vector
                Polygon poly1(temp);
                poly1.settype(temp.gettype());          //conversion inner shape to polygon  and add to polygon vector
                *this+=poly1;
            }
        }
    for(j=0; j<height; j+=(length/2)*sqrt(3))
        for(i=0; i<width; i+=length){
            p2x=i+length/2+length;       //in here loops draw rotate triangles 0-width and calculate x and y coordinate
            p3y=j+length/2*sqrt(3);
            if(p2x<width && p3y<height){
                triangle temp=triangle(length);
                temp.setx_coordinate(i+length/2);
                temp.sety_coordinate(j);            //coordinate assign to members variable
                temp.setx_coordinate_2(i+length/2+length);
                temp.sety_coordinate_2(j);
                temp.setx_coordinate_3(i+length);
                temp.sety_coordinate_3(j+length/2*sqrt(3));
                temp.settype("smallshape");              //small shapes member asign to vector
                Polygon poly1(temp);
                poly1.settype(temp.gettype());          //conversion inner shape to polygon  and add to polygon vector
                *this+=poly1;

            }
        }
}

void composedshape::reccirc(double width,double height,double radius){

    int a=0,b=0,e=0, num1,num2,num3=0;
    double  i,j;

    num1=width/(2*radius);
    num2=height/(2*radius);

    fakeRec.setx_coordinate(0);
    fakeRec.sety_coordinate(0);     //container shape coordinate asiggn
    Polygon poly(fakeRec);
    poly.settype(fakeRec.gettype());
    poly.setheight(fakeRec.getheight());
    poly.setwidth(fakeRec.getwidth());
    *this+=poly;            //conversion container shape to polygon  and add to polygon vector

    for(i=radius; i<height; i+=(a*radius*sqrt(3))){
            for(j=radius; j<width; j+=2*radius){
                if(e%2==1)
                    if(b%2==1)
                        j+=radius;       //here calculate how many circles fits into the rectangle
                if(j+radius<=width && i+radius<=height)
                    num3++;
                    j-=radius;
            }
            b++;
            e++;
            a=1;
        }
        b=e=a=0;
    if(num1*num2>num3){
        for(i=radius; i<height; i=i+2*radius){
            for(j=radius; j<width; j=j+2*radius)
                if(j+radius<=width && i+radius<=height){        //this sequence is written if the sequence fits more
                    circle temp=circle(radius);
                    temp.setx_coordinate(i);
                    temp.sety_coordinate(j);        //coordinate assign to members variable
                    temp.settype("smallshape");
                    Polygon poly1(temp);
                    poly1.settype(temp.gettype());          //conversion inner shape to polygon  and add to polygon vector
                    *this+=poly1;
                }
        }
    }else
        for(i=radius; i<height; i+=(a*radius*sqrt(3))){
            for(j=radius; j<width; j+=2*radius){
                if(e%2==1)              //This loop is printed with more shapes if it fills
                    if(b%2==1)
                        j+=radius;
                if(j+radius<=width && i+radius<=height){
                    circle temp=circle(radius);
                    temp.setx_coordinate(j);        //coordinate assign to members variable
                    temp.sety_coordinate(i);
                    temp.settype("smallshape");
                    Polygon poly1(temp);
                    poly1.settype(temp.gettype());      //conversion inner shape to polygon  and add to polygon vector
                    *this+=poly1;
                }
                if(b%2==1)
                    j-=radius;
            }
            b++;
            e++;
            a=1;
        }
}

void composedshape::circrect(double radius, double width, double height){

    double i,j;
    int a=0;
    double point1,point2,point3,point4;

    fakeCirc.setx_coordinate(0);
    fakeCirc.sety_coordinate(0);            //container shape coordinate asiggn
    Polygon poly(fakeCirc);
    poly.settype(fakeCirc.gettype());           //conversion container shape to polygon  and add to polygon vector
    poly.setheight(fakeCirc.getradius()*2);
    poly.setwidth(fakeCirc.getradius()*2);
    *this+=poly;


    for(i=0; i<2*radius; i++){
        for(j=0; j<2*radius; j++){
            point1=sqrt(pow((radius-(j)),2)+pow((radius-i),2));
            point2=sqrt(pow((radius-(j+width)),2)+pow((radius-(i+height)),2));      //in here check each point of the rectangle is inside the circle
            point3=sqrt(pow((radius-(j)),2)+pow((radius-(i+height)),2));            //if they are rectangel draw and Width is added to j
            point4=sqrt(pow((radius-(j+width)),2)+pow((radius-i),2));
            if(point1<=radius && point2<=radius && point3<=radius && point4<=radius){
                rectengal temp=rectengal(width,height);
                temp.setx_coordinate(j);        //coordinate assign to members variable
                temp.sety_coordinate(i);
                temp.settype("smallshape");
                Polygon poly1(temp);
                poly1.settype(temp.gettype());
                *this+=poly1;       //conversion inner shape to polygon  and add to polygon vector
                j+=width;
                a=1;
            }
        }
        if(a==1){           //if rectangel draw heigt is added to i
            a=0;
            i+=height;
        }
    }
}

void composedshape::circcirc(double radius,double smallradius){

    double i,j;
    int temp3=0,temp2=0;

    fakeCirc.setx_coordinate(0);
    fakeCirc.sety_coordinate(0);
    Polygon poly(fakeCirc);             //container shape coordinate asiggn
    poly.settype(fakeCirc.gettype());
    poly.setheight(fakeCirc.getradius()*2);
    poly.setwidth(fakeCirc.getradius()*2);
    *this+=poly;                //conversion container shape to polygon  and add to polygon vector

    for(j=0; j<=radius/smallradius; j++){
        for(i=smallradius; i<2*radius; i+=2*smallradius){       // in here draw cirles center of big circle
            if(i+smallradius<=2*radius){
                circle temp=circle(smallradius);
                temp.setx_coordinate(i);        //coordinate assign to members variable
                temp.sety_coordinate(radius);
                temp.settype("smallshape");
                Polygon poly1(temp);
                poly1.settype(temp.gettype());      //conversion inner shape to polygon  and add to polygon vector
                *this+=poly1;
           }
        }
    }
    for(j=radius-(smallradius*sqrt(3)); j>=0; j-=smallradius*sqrt(3)){
        for(i=2*smallradius+temp3*smallradius; i<2*radius; i+=2*smallradius){           //in here small circle draw center to start of big circle
            if(sqrt(pow((radius-(i)),2)+pow((radius-j),2))+smallradius<=radius){
                circle temp=circle(smallradius);
                temp.setx_coordinate(i);
                temp.sety_coordinate(j);    //coordinate assign to members variable
                temp.settype("smallshape");
                Polygon poly1(temp);
                poly1.settype(temp.gettype());          //conversion inner shape to polygon  and add to polygon vector
                *this+=poly1;
           }
        }
        if(temp2%2==0)
            temp3=1;
        else                //if small circle center + radius of small circle smaller than big circle function draw small circle
            temp3=0;
        temp2++;
    }
    temp3=temp2=0;
    for(j=radius+(smallradius*sqrt(3)); j<=2*radius; j+=smallradius*sqrt(3)){
        for(i=2*smallradius+temp3*smallradius; i<2*radius; i+=2*smallradius){
            if(sqrt(pow((radius-(i)),2)+pow((radius-j),2))+smallradius<=radius){            //in here small circle draw center to endpoint of big circle
                circle temp=circle(smallradius);
                temp.setx_coordinate(i);
                temp.sety_coordinate(j);        //coordinate assign to members variable
                temp.settype("smallshape");
                Polygon poly1(temp);
                poly1.settype(temp.gettype());      //conversion inner shape to polygon  and add to polygon vector
                *this+=poly1;
           }
        }
        if(temp2%2==0)
            temp3=1;
        else
            temp3=0;
        temp2++;
    }
}

void composedshape::circtri(double radius, double length){

    double p1x=0,p1y=0,p2x=0,p2y=0,p3x=0,p3y=0;
    double i,j;
    int temp2=0;

    fakeCirc.setx_coordinate(0);        //container shape coordinate asiggn
    fakeCirc.sety_coordinate(0);
    Polygon poly(fakeCirc);
    poly.settype(fakeCirc.gettype());
    poly.setheight(fakeCirc.getradius()*2);
    poly.setwidth(fakeCirc.getradius()*2);
    *this+=poly;            //conversion container shape to polygon  and add to polygon vector

    for(j=radius; j>0; j-=length/2*sqrt(3)){
        for(i=0; i<2*radius; i+=length){
            p1x=i;
            p1y=j;
            p2x=i+length;       //here triangels coordinate calculate and if the coordinate is in circle function draw triangels
            p2y=j;
            p3x=i+length/2;
            p3y=j-length/2*sqrt(3);
            if((sqrt(pow((radius-(p1x)),2)+pow((radius-p1y),2))<=radius) && (sqrt(pow((radius-(p2x)),2)+pow((radius-p2y),2))<=radius) && (sqrt(pow((radius-(p3x)),2)+pow((radius-p3y),2))<=radius)){
                triangle temp=triangle(length);
                temp.setx_coordinate(p1x);
                temp.sety_coordinate(p1y);
                temp.setx_coordinate_2(p2x);
                temp.sety_coordinate_2(p2y);        //coordinate assign to members variable
                temp.setx_coordinate_3(p3x);        //it draws center to start point
                temp.sety_coordinate_3(p3y);
                temp.settype("smallshape");
                Polygon poly1(temp);
                poly1.settype(temp.gettype());      //conversion inner shape to polygon  and add to polygon vector
                *this+=poly1;

                triangle temp3=triangle(length);
                temp3.setx_coordinate(p1x);
                temp3.sety_coordinate(p1y+temp2*length/2*sqrt(3));
                temp3.setx_coordinate_2(p2x);           //coordinate assign to members variable
                temp3.sety_coordinate_2(p2y+temp2*length/2*sqrt(3));
                temp3.setx_coordinate_3(p3x);
                temp3.sety_coordinate_3(p3y+2*(length/2*sqrt(3))+(temp2*length/2*sqrt(3)));
                temp3.settype("smallshape");
                Polygon poly3(temp3);
                poly3.settype(temp3.gettype());
                *this+=poly3;           //conversion inner shape to polygon  and add to polygon vector
            }
        }
        temp2+=2;
    }temp2=0;
    for(j=radius; j>0; j-=length/2*sqrt(3)){
        for(i=length; i<2*radius; i+=length){
            p1x=i;
            p1y=j;
            p2x=i-length/2;                 //here rotate triangels coordinate calculate and if the coordinate is in circle function draw triangels
            p2y=j-length/2*sqrt(3);         //it draws center to endpoint point
            p3x=i+length/2;
            p3y=j-length/2*sqrt(3);
            if((sqrt(pow((radius-(p1x)),2)+pow((radius-p1y),2))<=radius) && (sqrt(pow((radius-(p2x)),2)+pow((radius-p2y),2))<=radius) && (sqrt(pow((radius-(p3x)),2)+pow((radius-p3y),2))<=radius)){
                triangle temp=triangle(length);
                temp.setx_coordinate(p1x);
                temp.sety_coordinate(p1y);
                temp.setx_coordinate_2(p2x);
                temp.sety_coordinate_2(p2y);        //coordinate assign to members variable
                temp.setx_coordinate_3(p3x);
                temp.sety_coordinate_3(p3y);
                temp.settype("smallshape");
                Polygon poly1(temp);
                poly1.settype(temp.gettype());          //conversion inner shape to polygon  and add to polygon vector
                *this+=poly1;

                triangle temp3=triangle(length);
                temp3.setx_coordinate(p1x);
                temp3.sety_coordinate(p1y+temp2*length/2*sqrt(3));
                temp3.setx_coordinate_2(p2x);           //coordinate assign to members variable
                temp3.sety_coordinate_2(p2y+2*(length/2*sqrt(3))+temp2*length/2*sqrt(3));
                temp3.setx_coordinate_3(p3x);
                temp3.sety_coordinate_3(p3y+2*(length/2*sqrt(3))+(temp2*length/2*sqrt(3)));
                temp3.settype("smallshape");
                Polygon poly3(temp3);
                poly3.settype(temp3.gettype());
                *this+=poly3;       //conversion inner shape to polygon  and add to polygon vector
            }
        }
        temp2+=2;
    }
}

void composedshape::trirect(double length, double width, double height){

    double i,j;
    int a=1;
    double b;

    b=(height/sqrt(3))+1;

    fakeTria.setx_coordinate(fakeTria.getlength()/2);
    fakeTria.sety_coordinate(0);
    fakeTria.setx_coordinate_2(0);      //container shape coordinate asiggn
    fakeTria.sety_coordinate_2((fakeTria.getlength()/2)*sqrt(3));
    fakeTria.setx_coordinate_3(fakeTria.getlength());
    fakeTria.sety_coordinate_3((fakeTria.getlength()/2)*sqrt(3));
    Polygon poly(fakeTria);
    poly.settype(fakeTria.gettype());
    poly.setheight(((fakeTria.getlength()/2)*sqrt(3)));         //conversion container shape to polygon  and add to polygon vector
    poly.setwidth(fakeTria.getlength());
    *this+=poly;

    for(j=((length/2)*sqrt(3)-height); j>=0; j-=height){
            for(i=b; i<=length-a*(height/sqrt(3)); i+=width){           //in here rectangels distance between triangel length with corner points of rectengal
                if(i+width<=length-a*(height/sqrt(3))){
                    rectengal temp=rectengal(width,height);
                    temp.setx_coordinate(i);        //coordinate assign to members variable
                    temp.sety_coordinate(j);
                    temp.settype("smallshape");
                    Polygon poly1(temp);
                    poly1.settype(temp.gettype());          //conversion inner shape to polygon  and add to polygon vector
                    *this+=poly1;
                }
            }
            a++;
            b=height*a/sqrt(3)+1;
        }
}

void composedshape::tricirc(double length, double radius){

    double i,j;
    int num=2*(length*sqrt(3)/2)/(3*radius);
    double x=length/2, y=2*radius;


    fakeTria.setx_coordinate(fakeTria.getlength()/2);
    fakeTria.sety_coordinate(0);
    fakeTria.setx_coordinate_2(0);
    fakeTria.sety_coordinate_2((fakeTria.getlength()/2)*sqrt(3));
    fakeTria.setx_coordinate_3(fakeTria.getlength());
    fakeTria.sety_coordinate_3((fakeTria.getlength()/2)*sqrt(3));
    Polygon poly(fakeTria);
    poly.settype(fakeTria.gettype());
    poly.setheight(((fakeTria.getlength()/2)*sqrt(3)));
    poly.setwidth(fakeTria.getlength());
    *this+=poly;            //conversion container shape to polygon  and add to polygon vector

    for(j=0; j<num; ++j){
        for(i=0; i<j+1; ++i){
            if(y+radius<=length*sqrt(3)/2){     //circle center point calculate and check the distance from triangles length
                circle temp=circle(radius);
                temp.setx_coordinate(x);            //coordinate assign to members variable
                temp.sety_coordinate(y);
                temp.settype("smallshape");
                Polygon poly1(temp);
                poly1.settype(temp.gettype());      //conversion inner shape to polygon  and add to polygon vector
                *this+=poly1;
            }
            x+=(radius*2);
        }
        x=length/2;         //x and y increase after first draw
        x-=((j+1)*radius);
        y+=(radius*sqrt(3));
    }
}

void composedshape::tritri(double length, double smallength){

    decltype(length) p3x=0,p3y=0,temp2=0;
    decltype(length) i,j;

    fakeTria.setx_coordinate(fakeTria.getlength()/2);
    fakeTria.sety_coordinate(0);
    fakeTria.setx_coordinate_2(0);          //container shape coordinate asiggn
    fakeTria.sety_coordinate_2((fakeTria.getlength()/2)*sqrt(3));
    fakeTria.setx_coordinate_3(fakeTria.getlength());
    fakeTria.sety_coordinate_3((fakeTria.getlength()/2)*sqrt(3));
    Polygon poly(fakeTria);
    poly.settype(fakeTria.gettype());
    poly.setheight(((fakeTria.getlength()/2)*sqrt(3)));
    poly.setwidth(fakeTria.getlength());
    *this+=poly;            //conversion container shape to polygon  and add to polygon vector

    for(j=length/2*sqrt(3); j>=0; j-=(smallength/2)*sqrt(3)){
        for(i=temp2; i<length-temp2; i+=smallength){
            p3x=i+smallength;
            p3y=j;                  //calculate small triangle coordinate and draw start point to end point in big triangel
            if(p3x<=length-temp2 && p3y>0){
                triangle temp=triangle(length);
                temp.setx_coordinate(i);
                temp.sety_coordinate(j);            //coordinate assign to members variable
                temp.setx_coordinate_2(i+smallength/2);
                temp.sety_coordinate_2(j-smallength/2*sqrt(3));
                temp.setx_coordinate_3(i+smallength);
                temp.sety_coordinate_3(j);
                temp.settype("smallshape");
                Polygon poly1(temp);
                poly1.settype(temp.gettype());          //conversion inner shape to polygon  and add to polygon vector
                *this+=poly1;
            }
        }
        temp2+=smallength/2;
    }
    temp2=smallength/2;
    for(j=length/2*sqrt(3); j>=0; j-=(smallength/2)*sqrt(3)){
        for(i=temp2; i<length-temp2; i+=smallength){
            p3x=i+smallength;
            p3y=j-smallength/2*sqrt(3);
            if(p3x<=length-temp2 && p3y>0){
                triangle temp=triangle(length);              //calculate rotate small triangle coordinate and draw start point to end point in big triangel
                temp.setx_coordinate(i+smallength/2);
                temp.sety_coordinate(j);                //coordinate assign to members variable
                temp.setx_coordinate_2(i);
                temp.sety_coordinate_2(j-smallength/2*sqrt(3));
                temp.setx_coordinate_3(i+smallength);
                temp.sety_coordinate_3(j-smallength/2*sqrt(3));
                temp.settype("smallshape");
                Polygon poly1(temp);
                poly1.settype(temp.gettype());      //conversion inner shape to polygon  and add to polygon vector
                *this+=poly1;
            }
        }
        temp2+=smallength/2;
    }
}
