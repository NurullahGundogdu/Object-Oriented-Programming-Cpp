#include <iostream>
#include "rectangal.h"
#include <fstream>
#include <cmath>

rectengal::rectengal(){
}
rectengal::rectengal(double Width, double Height){
    setheight(Height);
    setwidth(Width);

}

void rectengal::draw(ofstream &file){

    if(gettype()=="bigshape"){
        file << "<svg version=\"1.1\""<<endl;
        file << "baseProfile=\"full\""<<endl;
        file << "width=\""<<getwidth()<<"\" height=\""<<getheight()<<"\""<<endl;
        file << "xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
        file << "<rect width=\"100%\" height=\"100%\" fill=\"red\" />"<<endl;           //tamamlandı
    }else if(gettype()=="smallshape"){
            file << "<rect x=\""<<getx_coordinate()<<"\" y=\""<<gety_coordinate()<<"\" width=\""<<getwidth()<<"\" height=\""<<getheight()<<"\" fill=\"green\" stroke=\"black\"/>"<<endl;
    }
}



