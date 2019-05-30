#include "composedshape.h"
#include "circle.h"
#include "rectengal.h"
#include "triangle.h"
#include "polygon.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#define pI 3.14

namespace SHAPES{

    composedshape::composedshape():shape(),name1(""),name2(""){     //default constructur
        shapes=vector<shape*>();
    }
    composedshape::~composedshape(){
        if(!shapes.empty())
            delete &shapes;
    }

    composedshape::composedshape(rectengal rec, rectengal recsmall){

        rec.setx_coordinate(0);
        rec.sety_coordinate(0);
        rec.settype("bigshape");
        rec.setname('R');
        *this+=(&rec);

        setName1("R");              //assign shapes type
        setName2("R");

        optimalFit('R','R',rec.getwidth(),rec.getheight(),recsmall.getwidth(),recsmall.getheight());        //small shapes member assing to vector

    }

    composedshape::composedshape(rectengal rec, circle circ){

        rec.setx_coordinate(0);
        rec.sety_coordinate(0);
        rec.settype("bigshape");
        rec.setname('R');
        *this+=(&rec);

        setName1("R");          //assign shapes type
        setName2("C");

        optimalFit('R','C',rec.getwidth(),rec.getheight(),circ.getradius(),circ.getradius());       //small shapes member assing to vector

    }

    composedshape::composedshape(rectengal rec, triangle tria){

        rec.setx_coordinate(0);
        rec.sety_coordinate(0);
        rec.settype("bigshape");
        rec.setname('R');
        *this+=(&rec);

        setName1("R");          //assign shapes type
        setName2("T");

        optimalFit('R','T',rec.getwidth(),rec.getheight(),tria.getlength(),tria.getlength());      //small shapes member assing to vector

    }

    composedshape::composedshape(circle circ, rectengal rec){

        circ.setx_coordinate(0);
        circ.sety_coordinate(0);
        circ.settype("bigshape");
        circ.setname('C');
        *this+=(&circ);

        setName1("C");
        setName2("R");          //assign shapes type

        optimalFit('C','R',circ.getradius(),circ.getradius(),rec.getwidth(),rec.getheight());      //small shapes member assing to vector

    }

    composedshape::composedshape(circle circ, circle circsmall){

        circ.setx_coordinate(0);
        circ.sety_coordinate(0);
        circ.settype("bigshape");
        circ.setname('C');
        *this+=(&circ);

        setName1("C");                    //assign shapes type
        setName2("C");

        optimalFit('C','C',circ.getradius(),circ.getradius(),circsmall.getradius(),circsmall.getradius());      //small shapes member assing to vector

    }

    composedshape::composedshape(circle circ, triangle tria){

        circ.setx_coordinate(0);
        circ.sety_coordinate(0);
        circ.settype("bigshape");
        circ.setname('C');
        *this+=(&circ);

        setName1("C");                    //assign shapes type
        setName2("T");

        optimalFit('C','T',circ.getradius(),circ.getradius(),tria.getlength(),tria.getlength());      //small shapes member assing to vector

    }

    composedshape::composedshape(triangle tria, rectengal rec){

        tria.setx_coordinate(tria.getlength()/2);
        tria.sety_coordinate(0);
        tria.setx_coordinate_2(0);
        tria.sety_coordinate_2((tria.getlength()/2)*sqrt(3));
        tria.setx_coordinate_3(tria.getlength());
        tria.sety_coordinate_3((tria.getlength()/2)*sqrt(3));
        tria.settype("bigshape");
        tria.setname('T');
        *this+=(&tria);

        setName1("T");
        setName2("R");                    //assign shapes type

        optimalFit('T','R',tria.getlength(),tria.getlength(),rec.getwidth(),rec.getheight());      //small shapes member assing to vector

    }

    composedshape::composedshape(triangle tria, circle circ){

        tria.setx_coordinate(tria.getlength()/2);
        tria.sety_coordinate(0);
        tria.setx_coordinate_2(0);
        tria.sety_coordinate_2((tria.getlength()/2)*sqrt(3));
        tria.setx_coordinate_3(tria.getlength());
        tria.sety_coordinate_3((tria.getlength()/2)*sqrt(3));
        tria.settype("bigshape");
        tria.setname('T');
        *this+=(&tria);

        setName1("T");                    //assign shapes type
        setName2("C");

        optimalFit('T','C',tria.getlength(),tria.getlength(),circ.getradius(),circ.getradius());      //small shapes member assing to vector

    }

    composedshape::composedshape(triangle tria, triangle triasmall){

        tria.setx_coordinate(tria.getlength()/2);
        tria.sety_coordinate(0);
        tria.setx_coordinate_2(0);
        tria.sety_coordinate_2((tria.getlength()/2)*sqrt(3));
        tria.setx_coordinate_2(tria.getlength());
        tria.sety_coordinate_3((tria.getlength()/2)*sqrt(3));
        tria.settype("bigshape");
        tria.setname('T');

        *this+=(&tria);

        setName1("T");
        setName2("T");                        //assign shapes type

        optimalFit('T','T',tria.getlength(),tria.getlength(),triasmall.getlength(),triasmall.getlength());      //small shapes member assing to vector
    }

    ostream& operator <<(ostream & output, const composedshape &shapes){

        int shapenum=-1;

        int emptyArea=0,totalperimeter=0,totalarea=0;

        output<<"</svg>";

        cout<<"I can fit at most "<<shapenum<<" small shapes into the main container. The empty area (red) in container is "<<emptyArea<<"."<<endl;
        cout<<"Total area of shapes "<<totalarea<<", total perimeter of shapes "<<totalperimeter<<"."<<endl;

        return output;
    }

    const shape* composedshape::operator [](int i)const{
                return shapes[i];
    }

    composedshape& composedshape::operator +=(shape *Shape){
        shapes.push_back(Shape);
        return *this;
    }

    double composedshape::Area(){
        shape_Area=0;
        return shape_Area;
    }
    double composedshape::Perimeter(){
        shape_Perimeter=0;
        return shape_Perimeter;
    }
    composedshape& composedshape::operator ++(){
        return *this;
    }
    composedshape& composedshape::operator ++(int){
        return *this;
    }

    composedshape& composedshape::operator --(){
        return *this;
    }
    composedshape& composedshape::operator --(int){
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

        if((a*b)>=(c*d)){
            for(i=0; i<width; i=i+smallwidth)
                for(j=0; j<height; j=j+smallheight){         //if more is drawn in the horizontal drawing this loop work
                    if(j+smallheight<=height && i+smallwidth<=width){
                        rectengal *ptr=new rectengal(smallwidth,smallheight);
                        ptr->setx_coordinate(i);           //coordinate assign to members variable
                        ptr->sety_coordinate(j);   //small shapes member asign to vector
                        ptr->settype("smallshape");
                        ptr->setname('R');
                        shape *Shape;
                        Shape=ptr;
                        *this+=(Shape);
                       // delete ptr;
                    }
                }
        }else{
            for(i=0; i<width; i=i+smallheight)
                for(j=0; j<height; j=j+smallwidth){         //if more is drawn in the vertical drawing this loop work
                    if(i+smallheight<=width && j+smallwidth<=height){
                        rectengal *ptr=new rectengal(smallwidth,smallheight);
                        ptr->setx_coordinate(i);        //coordinate assign to members variable
                        ptr->sety_coordinate(j);
                        ptr->settype("smallshape");
                        ptr->setname('R');
                        shape *Shape;
                        Shape=ptr;
                        *this+=(Shape);
                        //delete ptr;
                    }
                }
        }
    }

    void composedshape::rectria(double width,double height,double length){

        double i,j,p2x=0,p3x=0,p3y=0;

        for(j=0; j<height; j+=(length/2)*sqrt(3))
            for(i=0; i<width; i+=length){
                p3x=i+length;               //in here loops draw triangles 0-width and calculate x and y coordinate
                p3y=j+length/2*sqrt(3);
                if(p3x<width && p3y<height){
                    triangle *temp=new triangle(length);
                    temp->setx_coordinate(i);
                    temp->sety_coordinate(j+length/2*sqrt(3));
                    temp->setx_coordinate_2(i+length/2);         //coordinate assign to members variable
                    temp->sety_coordinate_2(j);
                    temp->setx_coordinate_3(i+length);
                    temp->sety_coordinate_3(j+length/2*sqrt(3));
                    temp->settype("smallshape");              //small shapes member asign to vector
                    temp->setname('T');
                    shape *Shape;
                    Shape=temp;
                    *this+=(Shape);
                   // delete temp;
                }
            }
        for(j=0; j<height; j+=(length/2)*sqrt(3))
            for(i=0; i<width; i+=length){
                p2x=i+length/2+length;       //in here loops draw rotate triangles 0-width and calculate x and y coordinate
                p3y=j+length/2*sqrt(3);
                if(p2x<width && p3y<height){
                    triangle *temp=new triangle(length);
                    temp->setx_coordinate(i+length/2);
                    temp->sety_coordinate(j);            //coordinate assign to members variable
                    temp->setx_coordinate_2(i+length/2+length);
                    temp->sety_coordinate_2(j);
                    temp->setx_coordinate_3(i+length);
                    temp->sety_coordinate_3(j+length/2*sqrt(3));
                    temp->settype("smallshape");              //small shapes member asign to vector
                    temp->setname('T');
                    shape *Shape;
                    Shape=temp;
                    *this+=(Shape);
                    //delete temp;

                }
            }
    }

    void composedshape::reccirc(double width,double height,double radius){

        int a=0,b=0,e=0, num1,num2,num3=0;
        double  i,j;

        num1=width/(2*radius);
        num2=height/(2*radius);

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
                        circle *temp=new circle(radius);
                        temp->setx_coordinate(i);
                        temp->sety_coordinate(j);        //coordinate assign to members variable
                        temp->settype("smallshape");
                        temp->setname('C');
                        shape *Shape;
                        Shape=temp;
                        *this+=(Shape);
                        //delete temp;
                    }
            }
        }else
            for(i=radius; i<height; i+=(a*radius*sqrt(3))){
                for(j=radius; j<width; j+=2*radius){
                    if(e%2==1)              //This loop is printed with more shapes if it fills
                        if(b%2==1)
                            j+=radius;
                    if(j+radius<=width && i+radius<=height){
                        circle *temp=new circle(radius);
                        temp->setx_coordinate(j);        //coordinate assign to members variable
                        temp->sety_coordinate(i);
                        temp->settype("smallshape");
                        temp->setname('C');
                        shape *Shape;
                        Shape=temp;
                        *this+=(Shape);
                        //delete temp;
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

        for(i=0; i<2*radius; i++){
            for(j=0; j<2*radius; j++){
                point1=sqrt(pow((radius-(j)),2)+pow((radius-i),2));
                point2=sqrt(pow((radius-(j+width)),2)+pow((radius-(i+height)),2));      //in here check each point of the rectangle is inside the circle
                point3=sqrt(pow((radius-(j)),2)+pow((radius-(i+height)),2));            //if they are rectangel draw and Width is added to j
                point4=sqrt(pow((radius-(j+width)),2)+pow((radius-i),2));
                if(point1<=radius && point2<=radius && point3<=radius && point4<=radius){
                    rectengal *temp=new rectengal(width,height);
                    temp->setx_coordinate(j);        //coordinate assign to members variable
                    temp->sety_coordinate(i);
                    temp->settype("smallshape");
                    temp->setname('R');
                    shape *Shape;
                    Shape=temp;
                    *this+=(Shape);
                   // delete temp;
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

        for(j=0; j<=radius/smallradius; j++){
            for(i=smallradius; i<2*radius; i+=2*smallradius){       // in here draw cirles center of big circle
                if(i+smallradius<=2*radius){
                    circle *temp=new circle(smallradius);
                    temp->setx_coordinate(i);        //coordinate assign to members variable
                    temp->sety_coordinate(radius);
                    temp->settype("smallshape");
                    temp->setname('C');
                    shape *Shape;
                    Shape=temp;
                    *this+=(Shape);
                    //delete temp;
               }
            }
        }
        for(j=radius-(smallradius*sqrt(3)); j>=0; j-=smallradius*sqrt(3)){
            for(i=2*smallradius+temp3*smallradius; i<2*radius; i+=2*smallradius){           //in here small circle draw center to start of big circle
                if(sqrt(pow((radius-(i)),2)+pow((radius-j),2))+smallradius<=radius){
                    circle *temp=new circle(smallradius);
                    temp->setx_coordinate(i);
                    temp->sety_coordinate(j);    //coordinate assign to members variable
                    temp->settype("smallshape");
                    temp->setname('C');
                    shape *Shape;
                    Shape=temp;
                    *this+=(Shape);
                    //delete temp;
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
                    circle *temp=new circle(smallradius);
                    temp->setx_coordinate(i);
                    temp->sety_coordinate(j);        //coordinate assign to members variable
                    temp->settype("smallshape");
                    temp->setname('C');
                    shape *Shape;
                    Shape=temp;
                    *this+=(Shape);
                   // delete temp;
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

        for(j=radius; j>0; j-=length/2*sqrt(3)){
            for(i=0; i<2*radius; i+=length){
                p1x=i;
                p1y=j;
                p2x=i+length;       //here triangels coordinate calculate and if the coordinate is in circle function draw triangels
                p2y=j;
                p3x=i+length/2;
                p3y=j-length/2*sqrt(3);
                if((sqrt(pow((radius-(p1x)),2)+pow((radius-p1y),2))<=radius) && (sqrt(pow((radius-(p2x)),2)+pow((radius-p2y),2))<=radius) && (sqrt(pow((radius-(p3x)),2)+pow((radius-p3y),2))<=radius)){
                    triangle *temp=new triangle(length);
                    temp->setx_coordinate(p1x);
                    temp->sety_coordinate(p1y);
                    temp->setx_coordinate_2(p2x);
                    temp->sety_coordinate_2(p2y);        //coordinate assign to members variable
                    temp->setx_coordinate_3(p3x);        //it draws center to start point
                    temp->sety_coordinate_3(p3y);
                    temp->settype("smallshape");
                    temp->setname('T');
                    shape *Shape;
                    Shape=temp;
                    *this+=(Shape);
                    //delete temp;

                    triangle *temp3=new triangle(length);
                    temp3->setx_coordinate(p1x);
                    temp3->sety_coordinate(p1y+temp2*length/2*sqrt(3));
                    temp3->setx_coordinate_2(p2x);           //coordinate assign to members variable
                    temp3->sety_coordinate_2(p2y+temp2*length/2*sqrt(3));
                    temp3->setx_coordinate_3(p3x);
                    temp3->sety_coordinate_3(p3y+2*(length/2*sqrt(3))+(temp2*length/2*sqrt(3)));
                    temp3->settype("smallshape");
                    temp3->setname('T');
                    shape *Shape2;
                    Shape2=temp3;
                    *this+=(Shape2);
                    //delete temp3;

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
                    triangle *temp=new triangle(length);
                    temp->setx_coordinate(p1x);
                    temp->sety_coordinate(p1y);
                    temp->setx_coordinate_2(p2x);
                    temp->sety_coordinate_2(p2y);        //coordinate assign to members variable
                    temp->setx_coordinate_3(p3x);
                    temp->sety_coordinate_3(p3y);
                    temp->settype("smallshape");
                    temp->setname('T');
                    shape *Shape;
                    Shape=temp;
                    *this+=(Shape);
                   // delete temp;

                    triangle *temp3=new triangle(length);
                    temp3->setx_coordinate(p1x);
                    temp3->sety_coordinate(p1y+temp2*length/2*sqrt(3));
                    temp3->setx_coordinate_2(p2x);           //coordinate assign to members variable
                    temp3->sety_coordinate_2(p2y+2*(length/2*sqrt(3))+temp2*length/2*sqrt(3));
                    temp3->setx_coordinate_3(p3x);
                    temp3->sety_coordinate_3(p3y+2*(length/2*sqrt(3))+(temp2*length/2*sqrt(3)));
                    temp3->settype("smallshape");
                    temp3->setname('T');
                    shape *Shape2;
                    Shape2=temp3;
                    *this+=(Shape2);
                   // delete temp3;
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

        for(j=((length/2)*sqrt(3)-height); j>=0; j-=height){
                for(i=b; i<=length-a*(height/sqrt(3)); i+=width){           //in here rectangels distance between triangel length with corner points of rectengal
                    if(i+width<=length-a*(height/sqrt(3))){
                        rectengal *temp=new rectengal(width,height);
                        temp->setx_coordinate(i);        //coordinate assign to members variable
                        temp->sety_coordinate(j);
                        temp->settype("smallshape");
                        temp->setname('R');
                        shape *Shape;
                        Shape=temp;
                        *this+=(Shape);
                        //delete temp;
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

        for(j=0; j<num; ++j){
            for(i=0; i<j+1; ++i){
                if(y+radius<=length*sqrt(3)/2){     //circle center point calculate and check the distance from triangles length
                    circle *temp=new circle(radius);
                    temp->setx_coordinate(x);            //coordinate assign to members variable
                    temp->sety_coordinate(y);
                    temp->settype("smallshape");
                    temp->setname('C');
                    shape *Shape;
                    Shape=temp;
                    *this+=(Shape);
                   // delete temp;
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

        for(j=length/2*sqrt(3); j>=0; j-=(smallength/2)*sqrt(3)){
            for(i=temp2; i<length-temp2; i+=smallength){
                p3x=i+smallength;
                p3y=j;                  //calculate small triangle coordinate and draw start point to end point in big triangel
                if(p3x<=length-temp2 && p3y>0){
                    triangle *temp=new triangle(length);
                    temp->setx_coordinate(i);
                    temp->sety_coordinate(j);            //coordinate assign to members variable
                    temp->setx_coordinate_2(i+smallength/2);
                    temp->sety_coordinate_2(j-smallength/2*sqrt(3));
                    temp->setx_coordinate_3(i+smallength);
                    temp->sety_coordinate_3(j);
                    temp->settype("smallshape");
                    temp->setname('T');
                    shape *Shape;
                    Shape=temp;
                    *this+=(Shape);
                    //delete temp;
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
                    triangle *temp=new triangle(length);              //calculate rotate small triangle coordinate and draw start point to end point in big triangel
                    temp->setx_coordinate(i+smallength/2);
                    temp->sety_coordinate(j);                //coordinate assign to members variable
                    temp->setx_coordinate_2(i);
                    temp->sety_coordinate_2(j-smallength/2*sqrt(3));
                    temp->setx_coordinate_3(i+smallength);
                    temp->sety_coordinate_3(j-smallength/2*sqrt(3));
                    temp->settype("smallshape");
                    temp->setname('T');
                    shape *Shape;
                    Shape=temp;
                    *this+=(Shape);
                    //delete temp;
                }
            }
            temp2+=smallength/2;
        }
    }
}
