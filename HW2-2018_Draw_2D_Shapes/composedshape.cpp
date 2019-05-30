#include "composedshape.h"
#include "circle.h"
#include "rectangal.h"
#include "triangle.h"
#include<vector>
#include <iostream>
#include <fstream>
#include <cmath>

composedshape::composedshape(){
}
composedshape::composedshape(rectengal rec, rectengal recsmall,ofstream &file){

    fakeRec.setwidth(rec.getwidth());
    fakeRec.setheight(rec.getheight());
    fakeRec.settype("bigshape");
    setName1("R");
    setName2("R");
    optimalFit('R','R',rec.getwidth(),rec.getheight(),recsmall.getwidth(),recsmall.getheight());

    draw(file);

}
composedshape::composedshape(rectengal rec, circle circ,ofstream &file){
    fakeRec.setwidth(rec.getwidth());
    fakeRec.setheight(rec.getheight());
    fakeRec.settype("bigshape");
    setName1("R");
    setName2("C");
    optimalFit('R','C',rec.getwidth(),rec.getheight(),circ.getradius(),circ.getradius());
    draw(file);
}
composedshape::composedshape(rectengal rec, triangle tria,ofstream &file){
    fakeRec.setwidth(rec.getwidth());
    fakeRec.setheight(rec.getheight());
    fakeRec.settype("bigshape");
    setName1("R");
    setName2("T");
    optimalFit('R','T',rec.getwidth(),rec.getheight(),tria.getlength(),tria.getlength());
    draw(file);
}
composedshape::composedshape(circle circ, rectengal rec,ofstream &file){
    fakeCirc.setradius(circ.getradius());
    fakeCirc.settype("bigshape");
    setName1("C");
    setName2("R");
    optimalFit('C','R',circ.getradius(),circ.getradius(),rec.getwidth(),rec.getheight());
    draw(file);
}
composedshape::composedshape(circle circ, circle circsmall,ofstream &file){
    fakeCirc.setradius(circ.getradius());
    fakeCirc.settype("bigshape");
    setName1("C");
    setName2("C");
    optimalFit('C','C',circ.getradius(),circ.getradius(),circsmall.getradius(),circsmall.getradius());
    draw(file);
}
composedshape::composedshape(circle circ, triangle tria,ofstream &file){
    fakeCirc.setradius(circ.getradius());
    fakeCirc.settype("bigshape");
    setName1("C");
    setName2("T");
    optimalFit('C','T',circ.getradius(),circ.getradius(),tria.getlength(),tria.getlength());
    draw(file);
}
composedshape::composedshape(triangle tria, rectengal rec,ofstream &file){
    fakeTria.setlength(tria.getlength());
    fakeTria.settype("bigshape");
    setName1("T");
    setName2("R");
    optimalFit('T','R',tria.getlength(),tria.getlength(),rec.getwidth(),rec.getheight());
    draw(file);
}
composedshape::composedshape(triangle tria, circle circ,ofstream &file){
    fakeTria.setlength(tria.getlength());
    fakeTria.settype("bigshape");
    setName1("T");
    setName2("C");
    optimalFit('T','C',tria.getlength(),tria.getlength(),circ.getradius(),circ.getradius());
    draw(file);
}
composedshape::composedshape(triangle tria, triangle triasmall,ofstream &file){
    fakeTria.setlength(tria.getlength());
    fakeTria.settype("bigshape");
    setName1("T");
    setName2("T");
    optimalFit('T','T',tria.getlength(),tria.getlength(),triasmall.getlength(),triasmall.getlength());
    draw(file);
}

void composedshape::optimalFit(char name,char name2,double length1,double length2,double smallength1,double smallength2){

    if(name=='R' && name2=='R'){
        rectVector=recrec(length1,length2,smallength1,smallength2);
    }else if(name=='R' && name2=='C'){
        circVector=reccirc(length1,length2,smallength1);
    }else if(name=='R' && name2=='T'){
        triaVector=rectria(length1,length2,smallength1);
    }else if(name=='C' && name2=='R'){
        rectVector=circrect(length1,smallength1,smallength2);
    }else if(name=='C' && name2=='C'){
        circVector=circcirc(length1,smallength1);
    }else if(name=='C' && name2=='T'){
        triaVector=circtri(length1,smallength1);
    }else if(name=='T' && name2=='R'){
        rectVector=trirect(length1,smallength1,smallength2);
    }else if(name=='T' && name2=='C'){
        circVector=tricirc(length1,smallength1);
    }else if(name=='T' && name2=='T'){
        triaVector=tritri(length1,smallength1);
    }
}

vector<rectengal> composedshape::recrec(double width,double height,double smallwidth,double smallheight){

    double i,j;
    vector<rectengal> vec;

    auto a=width/smallwidth;
    auto b=height/smallheight;
    auto c=width/smallheight;
    auto d=height/smallwidth;

    if((a*b)>=(c*d)){
        for(i=0; i<width; i=i+smallwidth)
            for(j=0; j<height; j=j+smallheight){
                if(j+smallheight<=height && i+smallwidth<=width){
                    rectengal temp=rectengal(smallwidth,smallheight);
                    temp.setx_coordinate(i);
                    temp.sety_coordinate(j);
                    temp.settype("smallshape");
                    vec.push_back(temp);
                }
            }
    }else{
        for(i=0; i<width; i=i+smallheight)
            for(j=0; j<height; j=j+smallwidth){
                if(i+smallheight<=width && j+smallwidth<=height){
                    rectengal temp=rectengal(smallwidth,smallheight);
                    temp.setx_coordinate(i);
                    temp.sety_coordinate(j);
                    temp.settype("smallshape");
                    vec.push_back(temp);
                }
            }
    }
    return vec;
}
vector<triangle> composedshape::rectria(double width,double height,double length){

    vector<triangle> vec;

    double i,j,p2x=0,p3x=0,p3y=0;

     for(j=0; j<height; j+=(length/2)*sqrt(3))
        for(i=0; i<width; i+=length){
            p3x=i+length;
            p3y=j+length/2*sqrt(3);
            if(p3x<width && p3y<height){
                triangle temp=triangle(length);
                temp.setx_coordinate(i);
                temp.sety_coordinate(j+length/2*sqrt(3));
                temp.setx_coordinate_2(i+length/2);
                temp.sety_coordinate_2(j);
                temp.setx_coordinate_3(i+length);
                temp.sety_coordinate_3(j+length/2*sqrt(3));
                temp.settype("smallshape");
                vec.push_back(temp);
            }
        }
    for(j=0; j<height; j+=(length/2)*sqrt(3))
        for(i=0; i<width; i+=length){
            p2x=i+length/2+length;
            p3y=j+length/2*sqrt(3);
            if(p2x<width && p3y<height){
                triangle temp=triangle(length);
                temp.setx_coordinate(i+length/2);
                temp.sety_coordinate(j);
                temp.setx_coordinate_2(i+length/2+length);
                temp.sety_coordinate_2(j);
                temp.setx_coordinate_3(i+length);
                temp.sety_coordinate_3(j+length/2*sqrt(3));
                temp.settype("smallshape");
                vec.push_back(temp);
            }
        }

    return vec;
}
vector<circle> composedshape::reccirc(double width,double height,double radius){

    vector<circle> vec;
    int a=0,b=0,e=0, num1,num2,num3=0;
    double  i,j;

    num1=width/(2*radius);
    num2=height/(2*radius);

    for(i=radius; i<height; i+=(a*radius*sqrt(3))){
            for(j=radius; j<width; j+=2*radius){
                if(e%2==1)
                    if(b%2==1)
                        j+=radius;
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
        for(i=radius; i<height; i=i+2*radius)
            for(j=radius; j<width; j=j+2*radius)
                if(j+radius<=width && i+radius<=height){
                    circle temp=circle(radius);
                    temp.setx_coordinate(i);
                    temp.sety_coordinate(j);
                    temp.settype("smallshape");
                    vec.push_back(temp);
                }
    }else
        for(i=radius; i<height; i+=(a*radius*sqrt(3))){
            for(j=radius; j<width; j+=2*radius){
                if(e%2==1)
                    if(b%2==1)
                        j+=radius;
                if(j+radius<=width && i+radius<=height){
                    circle temp=circle(radius);
                    temp.setx_coordinate(i);
                    temp.sety_coordinate(j);
                    temp.settype("smallshape");
                    vec.push_back(temp);
                }
                if(b%2==1)
                    j-=radius;
            }
            b++;
            e++;
            a=1;
        }
    return vec;
}
vector<rectengal> composedshape::circrect(double radius, double width, double height){

    vector<rectengal> vec;
    double i,j;
    int a=0;
    double point1,point2,point3,point4;

    for(i=0; i<2*radius; i++){
        for(j=0; j<2*radius; j++){
            point1=sqrt(pow((radius-(j)),2)+pow((radius-i),2));
            point2=sqrt(pow((radius-(j+width)),2)+pow((radius-(i+height)),2));
            point3=sqrt(pow((radius-(j)),2)+pow((radius-(i+height)),2));
            point4=sqrt(pow((radius-(j+width)),2)+pow((radius-i),2));
            if(point1<=radius && point2<=radius && point3<=radius && point4<=radius){
                rectengal temp=rectengal(width,height);
                temp.setx_coordinate(j);
                temp.sety_coordinate(i);
                temp.settype("smallshape");
                vec.push_back(temp);
                j+=width;
                a=1;
            }
        }
        if(a==1){
            a=0;
            i+=height;
        }
    }
    return vec;
}
vector<circle> composedshape::circcirc(double radius,double smallradius){

    vector<circle> vec;
    double i,j;
    int temp3=0,temp2=0;

    for(j=0; j<=radius/smallradius; j++){
        for(i=smallradius; i<2*radius; i+=2*smallradius){
            if(i+smallradius<=2*radius){
                circle temp=circle(smallradius);
                temp.setx_coordinate(i);
                temp.sety_coordinate(radius);
                temp.settype("smallshape");
                vec.push_back(temp);
           }
        }
    }
    for(j=radius-(smallradius*sqrt(3)); j>=0; j-=smallradius*sqrt(3)){
        for(i=2*smallradius+temp3*smallradius; i<2*radius; i+=2*smallradius){
            if(sqrt(pow((radius-(i)),2)+pow((radius-j),2))+smallradius<=radius){
                circle temp=circle(smallradius);
                temp.setx_coordinate(i);
                temp.sety_coordinate(j);
                temp.settype("smallshape");
                vec.push_back(temp);
           }
        }
        if(temp2%2==0)
            temp3=1;
        else
            temp3=0;
        temp2++;
    }
    temp3=temp2=0;
    for(j=radius+(smallradius*sqrt(3)); j<=2*radius; j+=smallradius*sqrt(3)){
        for(i=2*smallradius+temp3*smallradius; i<2*radius; i+=2*smallradius){
            if(sqrt(pow((radius-(i)),2)+pow((radius-j),2))+smallradius<=radius){
                circle temp=circle(smallradius);
                temp.setx_coordinate(i);
                temp.sety_coordinate(j);
                temp.settype("smallshape");
                vec.push_back(temp);
           }
        }
        if(temp2%2==0)
            temp3=1;
        else
            temp3=0;
        temp2++;
    }
    return vec;
}
vector<triangle> composedshape::circtri(double radius, double length){
    vector<triangle> vec;

    double p1x=0,p1y=0,p2x=0,p2y=0,p3x=0,p3y=0;
    double i,j;
    int temp2=0;
    for(j=radius; j>0; j-=length/2*sqrt(3)){
        for(i=0; i<2*radius; i+=length){
            p1x=i;
            p1y=j;
            p2x=i+length;
            p2y=j;
            p3x=i+length/2;
            p3y=j-length/2*sqrt(3);
            if((sqrt(pow((radius-(p1x)),2)+pow((radius-p1y),2))<=radius) && (sqrt(pow((radius-(p2x)),2)+pow((radius-p2y),2))<=radius) && (sqrt(pow((radius-(p3x)),2)+pow((radius-p3y),2))<=radius)){
                triangle temp=triangle(length);
                temp.setx_coordinate(p1x);
                temp.sety_coordinate(p1y);
                temp.setx_coordinate_2(p2x);
                temp.sety_coordinate_2(p2y);
                temp.setx_coordinate_3(p3x);
                temp.sety_coordinate_3(p3y);
                temp.settype("smallshape");
                vec.push_back(temp);
                triangle temp3=triangle(length);
                temp3.setx_coordinate(p1x);
                temp3.sety_coordinate(p1y+temp2*length/2*sqrt(3));
                temp3.setx_coordinate_2(p2x);
                temp3.sety_coordinate_2(p2y+temp2*length/2*sqrt(3));
                temp3.setx_coordinate_3(p3x);
                temp3.sety_coordinate_3(p3y+2*(length/2*sqrt(3))+(temp2*length/2*sqrt(3)));
                temp3.settype("smallshape");
                vec.push_back(temp3);
            }
        }
        temp2+=2;
    }temp2=0;
    for(j=radius; j>0; j-=length/2*sqrt(3)){
        for(i=length; i<2*radius; i+=length){
            p1x=i;
            p1y=j;
            p2x=i-length/2;
            p2y=j-length/2*sqrt(3);
            p3x=i+length/2;
            p3y=j-length/2*sqrt(3);
            if((sqrt(pow((radius-(p1x)),2)+pow((radius-p1y),2))<=radius) && (sqrt(pow((radius-(p2x)),2)+pow((radius-p2y),2))<=radius) && (sqrt(pow((radius-(p3x)),2)+pow((radius-p3y),2))<=radius)){
                triangle temp=triangle(length);
                temp.setx_coordinate(p1x);
                temp.sety_coordinate(p1y);
                temp.setx_coordinate_2(p2x);
                temp.sety_coordinate_2(p2y);
                temp.setx_coordinate_3(p3x);
                temp.sety_coordinate_3(p3y);
                temp.settype("smallshape");
                vec.push_back(temp);
                triangle temp3=triangle(length);
                temp3.setx_coordinate(p1x);
                temp3.sety_coordinate(p1y+temp2*length/2*sqrt(3));
                temp3.setx_coordinate_2(p2x);
                temp3.sety_coordinate_2(p2y+2*(length/2*sqrt(3))+temp2*length/2*sqrt(3));
                temp3.setx_coordinate_3(p3x);
                temp3.sety_coordinate_3(p3y+2*(length/2*sqrt(3))+(temp2*length/2*sqrt(3)));
                temp3.settype("smallshape");
                vec.push_back(temp3);
            }
        }
        temp2+=2;
    }
    return vec;
}
vector<rectengal> composedshape::trirect(double length, double width, double height){

    vector<rectengal> vec;
    double i,j;
    int a=1;
    double b;

    b=(height/sqrt(3))+1;
    for(j=((length/2)*sqrt(3)-height); j>=0; j-=height){
            for(i=b; i<=length-a*(height/sqrt(3)); i+=width){
                if(i+width<=length-a*(height/sqrt(3))){
                    rectengal temp=rectengal(width,height);
                    temp.setx_coordinate(i);
                    temp.sety_coordinate(j);
                    temp.settype("smallshape");
                    vec.push_back(temp);
                }
            }
            a++;
            b=height*a/sqrt(3)+1;
        }
    return vec;
}
vector<circle> composedshape::tricirc(double length, double radius){
    vector<circle> vec;
    double i,j;
    int num=2*(length*sqrt(3)/2)/(3*radius);
    double x=length/2, y=2*radius;


    for(j=0; j<num; ++j){
        for(i=0; i<j+1; ++i){
            if(y+radius<=length*sqrt(3)/2){
                circle temp=circle(radius);
                temp.setx_coordinate(x);
                temp.sety_coordinate(y);
                temp.settype("smallshape");
                vec.push_back(temp);
                //file<<"<circle cx=\""<<x<<"\" cy=\""<<y<<"\" r=\""<<radius<<"\" fill=\"green\" stroke=\"black\" />";
            }
            x+=(radius*2);
        }
        x=length/2;
        x-=((j+1)*radius);
        y+=(radius*sqrt(3));
    }

    return vec;
}
vector<triangle> composedshape::tritri(double length, double smallength){

    vector<triangle> vec;
    decltype(length) p3x=0,p3y=0,temp2=0;
    double i,j;

    for(j=length/2*sqrt(3); j>=0; j-=(smallength/2)*sqrt(3)){
        for(i=temp2; i<length-temp2; i+=smallength){
            p3x=i+smallength;
            p3y=j;
            if(p3x<=length-temp2 && p3y>0){
                triangle temp=triangle(length);
                temp.setx_coordinate(i);
                temp.sety_coordinate(j);
                temp.setx_coordinate_2(i+smallength/2);
                temp.sety_coordinate_2(j-smallength/2*sqrt(3));
                temp.setx_coordinate_3(i+smallength);
                temp.sety_coordinate_3(j);
                temp.settype("smallshape");
                vec.push_back(temp);
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
                triangle temp=triangle(length);
                temp.setx_coordinate(i+smallength/2);
                temp.sety_coordinate(j);
                temp.setx_coordinate_2(i);
                temp.sety_coordinate_2(j-smallength/2*sqrt(3));
                temp.setx_coordinate_3(i+smallength);
                temp.sety_coordinate_3(j-smallength/2*sqrt(3));
                temp.settype("smallshape");
                vec.push_back(temp);
            }
        }
        temp2+=smallength/2;
    }
    return vec;
}

void composedshape::draw(ofstream &file){

    int shapenum=0;
    double areanum1,areanum2,emptyarea,pi=3.14;

    if(name1=="R"){
        fakeRec.draw(file);
        areanum1=(fakeRec.getheight()*fakeRec.getwidth());
    }else if(name1=="C"){
        fakeCirc.draw(file);
        areanum1=(pi*fakeCirc.getradius()*fakeCirc.getradius());
    }else if(name1=="T"){
        fakeTria.draw(file);
        areanum1=((fakeTria.getlength()*(fakeTria.getlength()/2*sqrt(3)))/2);
    }

    if(name2=="R"){
        for(int i=0; i<getrectVector().size(); i++){
            rectVector[i].draw(file);
            shapenum++;
        }
        areanum2=((getrectVector())[0].getheight()*(getrectVector())[0].getwidth())*shapenum;
    }else if(name2=="C"){
        for(int i=0; i<getcircVector().size(); i++){
            circVector[i].draw(file);
            shapenum++;
        }
        areanum2=(pi*(getcircVector())[0].getradius()*(getcircVector())[0].getradius())*shapenum;
    }else if(name2=="T"){
        for(int i=0; i<gettriaVector().size(); i++){
            triaVector[i].draw(file);
            shapenum++;
        }
        if(name1=="C"){
            shapenum*=2;
        }
        areanum2=(((gettriaVector())[0].getlength()*((gettriaVector())[0].getlength()/2*sqrt(3)))/2);
    }
    emptyarea=areanum1-areanum2;
    cout<<"I can fit at most "<<shapenum<<" small shapes into the main container. The empty area (red) in container is "<<emptyarea<<"."<<endl;
    file <<"</svg>";
}
