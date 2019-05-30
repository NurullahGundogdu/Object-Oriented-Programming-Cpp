#include <iostream>
#include "circle.h"
#include "rectangal.h"
#include "triangle.h"
#include "ComposedShape.h"

using namespace std;

int main(){

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
        composedshape comp(rec,recsmall,file);
    }else if(shape=='R' && smallshape=='C'){
        rectengal rec(Width,Height);
        circle circsmall(Smallradius);
        composedshape comp(rec,circsmall,file);
    }else if(shape=='R' && smallshape=='T'){
        rectengal rec(Width,Height);
        triangle triasmall(Smalllength);
        composedshape comp(rec,triasmall,file);
    }else if(shape=='C' && smallshape=='R'){
        circle circ(Radius);
        rectengal recsmall(Smallwidth,Smallheight);
        composedshape comp(circ,recsmall,file);
    }else if(shape=='C' && smallshape=='C'){
        circle circ(Radius), circsmall(Smallradius);
        composedshape comp(circ,circsmall,file);
    }else if(shape=='C' && smallshape=='T'){
        circle circ(Radius);
        triangle triasmall(Smalllength);
        composedshape comp(circ,triasmall,file);
    }else if(shape=='T' && smallshape=='R'){
        triangle tria(Length);
        rectengal recsmall(Smallwidth,Smallheight);
        composedshape comp(tria,recsmall,file);
    }else if(shape=='T' && smallshape=='C'){
        triangle tria(Length);
        circle circsmall(Smallradius);
        composedshape comp(tria,circsmall,file);
    }else if(shape=='T' && smallshape=='T'){
        triangle tria(Length), triasmall(Smalllength);
        composedshape comp(tria,triasmall,file);
    }

    file.close();
    return 0;
}
