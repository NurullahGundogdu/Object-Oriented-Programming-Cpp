#include <iostream>
#include "circle.h"
#include "rectengal.h"
#include "triangle.h"
#include "ComposedShape.h"

using namespace std;

int main(){

    string filename[9];

    filename[0]="result0.svg";
    filename[1]="result1.svg";
    filename[2]="result2.svg";
    filename[3]="result3.svg";
    filename[4]="result4.svg";
    filename[5]="result5.svg";
    filename[6]="result6.svg";
    filename[7]="result7.svg";
    filename[8]="result8.svg";

    rectengal r[4];
    triangle t[4];
    circle c[4];
    composedshape cs[9];

    rectengal r1(500,500);
    rectengal r2=r1-450;
    rectengal r3=r2+10;
    rectengal r4=r3-19;

    r[0]=r1;
    r[1]=r2;
    r[2]=r3;
    r[3]=r4;

    triangle t1(760);
    triangle t2=t1-618;
    triangle t3=t2-100;
    triangle t4=t3+18;

    t[0]=t1;
    t[1]=t2;
    t[2]=t3;
    t[3]=t4;

    circle c1(500);
    circle c2=c1-450;
    circle c3=c2-30;
    circle c4=c3+18;

    c[0]=c1;
    c[1]=c2;
    c[2]=c3;
    c[3]=c4;

    composedshape csrr1(r[0],r[1]);
    composedshape csrc2(r[0],c[1]);
    composedshape csrt3(r[0],t[1]);
    composedshape cscr1(c[0],r[2]);
    composedshape cscc2(c[0],c[2]);
    composedshape csct3(c[0],t[2]);
    composedshape cstr1(t[0],r[3]);
    composedshape cstc2(t[0],c[3]);
    composedshape cstt3(t[0],t[3]);

    cs[0]=csrr1;
    cs[1]=csrc2;
    cs[2]=csrt3;
    cs[3]=cscr1;
    cs[4]=cscc2;
    cs[5]=csct3;
    cs[6]=cstr1;
    cs[7]=cstc2;
    cs[8]=cstt3;

    for(int i=0; i<9; i++){
        ofstream file;
        file.open(filename[i]);
        file<<cs[i];
        file.close();
    }
    return 0;
/*

    char shape,smallshape;
    double Width, Height,Radius,Length,Smallwidth,Smallheight,Smallradius,Smalllength;

    while(1){
        cout<<"Please enter the main container shape (R, C, T)"<<endl;
        cin >>shape;                                                //this loop for the get the correct information from user
        if(shape=='R' || shape=='C' || shape=='T'){
            break;
        }
    }
    while(1){
        if(shape=='R'){
            cout<<"Please enter the width"<<endl;
            cin>>Width;
            cout<<"Please enter the height"<<endl;
            cin>>Height;
            if(Width>0 && Height>0){
                break;
            }                                           //this loop for the get the correct information from user
        }else if(shape=='C'){
            cout<<"Please enter the radius"<<endl;
            cin>>Radius;
            if(Radius>0){
                break;
            }
        }else if(shape=='T'){
            cout<<"Please enter the side length"<<endl;
            cin>>Length;
            if(Length>0){
                break;
            }
        }
    }
    while(1){
        cout<<"Please enter the small shape (R, C, T)"<<endl;
        cin >>smallshape;                                       //this loop for the get the correct information from user
        if(smallshape=='R' || smallshape=='C' || smallshape=='T'){
            break;
        }
    }
    while(1){
        if(smallshape=='R'){
            cout<<"Please enter the width"<<endl;
            cin>>Smallwidth;
            cout<<"Please enter the height"<<endl;
            cin>>Smallheight;
            if(Smallwidth>0 && Smallheight>0){
                break;
            }
        }else if(smallshape=='C'){
            cout<<"Please enter the radius"<<endl;
            cin>>Smallradius;
            if(Smallradius>0){                  //this loop for the get the correct information from user
                break;
            }
        }else if(smallshape=='T'){
            cout<<"Please enter the side length"<<endl;
            cin>>Smalllength;
            if(Smalllength>0){
                break;
            }
        }
    }

    ofstream file;
    file.open("result.svg");

    if(shape=='R' && smallshape=='R'){
        rectengal rec(Width,Height),recsmall(Smallwidth,Smallheight);
        composedshape comp(rec,recsmall);
        file<<comp;
    }else if(shape=='R' && smallshape=='C'){
        rectengal rec(Width,Height);
        circle circsmall(Smallradius);
        composedshape comp(rec,circsmall);
        file<<comp;
    }else if(shape=='R' && smallshape=='T'){
        rectengal rec(Width,Height);
        triangle triasmall(Smalllength);
        composedshape comp(rec,triasmall);
        file<<comp;
    }else if(shape=='C' && smallshape=='R'){
        circle circ(Radius);
        rectengal recsmall(Smallwidth,Smallheight);
        composedshape comp(circ,recsmall);
        file<<comp;
    }else if(shape=='C' && smallshape=='C'){
        circle circ(Radius), circsmall(Smallradius);
        composedshape comp(circ,circsmall);
        file<<comp;
    }else if(shape=='C' && smallshape=='T'){
        circle circ(Radius);
        triangle triasmall(Smalllength);
        composedshape comp(circ,triasmall);
        file<<comp;
    }else if(shape=='T' && smallshape=='R'){
        triangle tria(Length);
        rectengal recsmall(Smallwidth,Smallheight);
        composedshape comp(tria,recsmall);
        file<<comp;
    }else if(shape=='T' && smallshape=='C'){
        triangle tria(Length);
        circle circsmall(Smallradius);
        composedshape comp(tria,circsmall);
        file<<comp;
    }else if(shape=='T' && smallshape=='T'){
        triangle tria(Length), triasmall(Smalllength);
        composedshape comp(tria,triasmall);
        file<<comp;
    }

    file.close();
    */


}
