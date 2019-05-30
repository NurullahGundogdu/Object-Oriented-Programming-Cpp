#include <iostream>
#include "shape.h"
#include "triangle.h"
#include "rectengal.h"
#include "circle.h"
#include "composedshape.h"
#include "polygon.h"
#include "polygondyn.h"
#include "polygonvect.h"
#include <cmath>
#include <vector>

using namespace std;
using namespace SHAPES;

void printAll(vector <shape*> SHAPE, string filename);
void printPoly(vector <shape*> SHAPE, string filename);
vector <shape*> convertAll(vector <shape*> SHAPE);
void sortShapes(vector <shape*> SHAPE);
ostream& operator <<(ostream & output, const shape *SHAPE);



int main()
{
    string filename[9];

    filename[0]="result0.svg";
    filename[1]="result1.svg";          //svg filename
    filename[2]="result2.svg";
    filename[3]="result3.svg";
    filename[4]="result4.svg";
    filename[5]="result5.svg";
    filename[6]="result6.svg";          //svg filename
    filename[7]="result7.svg";
    filename[8]="result8.svg";


    rectengal rec1(350,350);
    rectengal rec2(23,23);
    circle circ1(350);
    circle circ2(50);
    triangle tria1(350);
    triangle tria2(50);


    composedshape c_1(rec1,rec2);
    composedshape c_2(rec1,circ2);
    composedshape c_3(rec1,tria2);
    composedshape c_4(circ1,rec2);
    composedshape c_5(circ1,circ2);
    composedshape c_6(circ1,tria2);
    composedshape c_7(tria1,rec2);
    composedshape c_8(tria1,circ2);
    composedshape c_9(tria1,tria2);



    printAll(c_1.getvec(),filename[0]);
    printAll(c_2.getvec(),filename[1]);
    printAll(c_3.getvec(),filename[2]);
    printAll(c_4.getvec(),filename[3]);
    printAll(c_5.getvec(),filename[4]);

    vector<shape*> p;
    p=convertAll(c_6.getvec());
    printPoly(p,filename[5]);
    p=convertAll(c_7.getvec());
    printPoly(p,filename[6]);
    p=convertAll(c_8.getvec());
    printPoly(p,filename[7]);
    p=convertAll(c_9.getvec());
    printPoly(p,filename[8]);


    return 0;
}


void printAll(vector <shape*> SHAPE,string filename){

    double totalarea=0,emptyArea=0,totalperimeter=0;
    int shapenum=0;
    ofstream file;
    file.open(filename);

    for(unsigned int i=0; i<SHAPE.size(); i++){
        file<<SHAPE[i];
        totalarea+=SHAPE[i]->Area();
        totalperimeter+=SHAPE[i]->Perimeter();
        shapenum++;
    }

    file<<"</svg>";

    file.close();

    emptyArea=SHAPE[0]->Area()-(totalarea-SHAPE[0]->Area());

    cout<<"I can fit at most "<<(shapenum-1)<<" small shapes into the main container. The empty area (red) in container is "<<emptyArea<<"."<<endl;
    cout<<"Total area of shapes "<<totalarea<<", total perimeter of shapes "<<totalperimeter<<"."<<endl;
}
void printPoly(vector <shape*> SHAPE,string filename){

    double totalarea=0,emptyArea=0,totalperimeter=0;
    int shapenum=0;

    ofstream file;
    file.open(filename);

    for(unsigned int i=0; i<SHAPE.size(); i++){

        file<<SHAPE[i];
        totalarea+=SHAPE[i]->Area();
        totalperimeter+=SHAPE[i]->Perimeter();
        shapenum++;
    }

    file<<"</svg>";
    file.close();

    emptyArea=SHAPE[0]->Area()-(totalarea-SHAPE[0]->Area());

    cout<<"I can fit at most "<<(shapenum-1)<<" small polygons into the main container. The empty area (red) in container is "<<emptyArea<<"."<<endl;
    cout<<"Total area of polygons "<<totalarea<<", total perimeter of polygons "<<totalperimeter<<"."<<endl;

}
vector <shape*> convertAll(vector <shape*> SHAPE){

    vector <shape*> shapes;

    for(unsigned int i=0; i<SHAPE.size(); i++){
        if(SHAPE[i]->getname()=='R'){
            rectengal *x =(rectengal*) SHAPE[i];
            rectengal y=*x;
            polygonVect *pol=new polygonVect(y);
            if(i==0){
                pol->setheight(y.getheight());
                pol->setwidth(y.getwidth());
            }
            pol->settype(y.gettype());
            pol->setname('P');
            pol->setArea(y.Area());
            pol->setPerimeter(y.Perimeter());
            shapes.push_back(pol);
        }else if(SHAPE[i]->getname()=='C'){
            circle *x =(circle*) SHAPE[i];
            circle y=*x;
            polygonVect *pol=new polygonVect(y);
            if(i==0){
                pol->setheight(y.getradius()*2);
                pol->setwidth(y.getradius()*2);
            }
            pol->settype(y.gettype());
            pol->setname('P');
            pol->setArea(y.Area());
            pol->setPerimeter(y.Perimeter());
            shapes.push_back(pol);
        }else if(SHAPE[i]->getname()=='T'){
            triangle *x =(triangle*) SHAPE[i];
            triangle y=*x;
            polygonVect *pol=new polygonVect(y);
            if(i==0){
                pol->setheight(((y.getlength()/2)*sqrt(3)));
                pol->setwidth(y.getlength());

            }

            pol->settype(x->gettype());
            pol->setname('P');
            pol->setArea(y.Area());
            pol->setPerimeter(y.Perimeter());
            shapes.push_back(pol);
        }

    }


    return shapes;
}
void sortShapes(vector <shape*> SHAPE){
    for(unsigned int i=0; i<SHAPE.size(); i++)
        for(unsigned int j=0; j<SHAPE.size(); j++)
            if(SHAPE[j]<SHAPE[j+1]){
                shape *s;
                s=SHAPE[j];
                SHAPE[j]=SHAPE[j+1];
                SHAPE[j+1]=s;
            }
}

ostream& operator <<(ostream & output, const shape *SHAPE){

    if(SHAPE->getname()=='R'){
        rectengal *x =(rectengal*) SHAPE;
        output<<*x;
    }else if(SHAPE->getname()=='C'){
        circle *x =(circle*) SHAPE;
        output<<*x;
    }else if(SHAPE->getname()=='T'){
        triangle *x =(triangle*) SHAPE;
        output<<*x;
    }else if(SHAPE->getname()=='P'){
        polygonVect *pol=(polygonVect*)SHAPE;
        output<<*pol;
    }

    return output;
}
