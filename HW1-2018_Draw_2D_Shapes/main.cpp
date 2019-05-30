#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
enum class shapes{
            rectangle,
            circle,
            triangle
        };

void drawrectrect(double width, double height, double smallwidth, double smallheight);
void drawrectcirc(double width, double height, double radius);
void drawrecttri(double width, double height, double length);

void drawcircrect(double radius, double width, double height);
void drawcirccirc(double radius,double smallradius);
void drawcirctri(double radius, double length);

void drawtrirect(double length, double width, double height);
void drawtricirc(double length, double radius);
void drawtritri(double length, double smallength);

int main(){

    char shape,smallshape;
    double width, height,radius,length,smallwidth,smallheight,smallradius,smalllength;
    shapes a,b;



    cout<<"Please enter the main container shape (R, C, T)"<<endl;
    cin >>shape;

    if(shape=='R'){
        cout<<"Please enter the width"<<endl;
        cin>>width;
        cout<<"Please enter the height"<<endl;
        cin>>height;
        a=shapes::rectangle;
    }else if(shape=='C'){
        cout<<"Please enter the radius"<<endl;
        cin>>radius;
        a=shapes::circle;
    }else if(shape=='T'){
        cout<<"Please enter the side length"<<endl;
        cin>>length;
        a=shapes::triangle;
    }

    cout<<"Please enter the small shape (R, C, T)"<<endl;
    cin >>smallshape;

    if(smallshape=='R'){
        cout<<"Please enter the width"<<endl;
        cin>>smallwidth;
        cout<<"Please enter the height"<<endl;
        cin>>smallheight;
        b=shapes::rectangle;
    }else if(smallshape=='C'){
        cout<<"Please enter the radius"<<endl;
        cin>>smallradius;
        b=shapes::circle;
    }else if(smallshape=='T'){
        cout<<"Please enter the side length"<<endl;
        cin>>smalllength;
        b=shapes::triangle;
    }
    if(a==shapes::circle && b==shapes::circle)
        drawcirccirc(radius, smallradius);
    else if(a==shapes::circle && b==shapes::rectangle)
        drawcircrect(radius, smallwidth, smallheight);
    else if(a==shapes::circle && b==shapes::triangle)
        drawcirctri(radius, smalllength);
    else if(a==shapes::rectangle && b==shapes::rectangle)
        drawrectrect(width, height, smallwidth, smallheight);
    else if(a==shapes::rectangle && b==shapes::circle)
        drawrectcirc(width, height, smallradius);
    else if(a==shapes::rectangle && b==shapes::triangle)
        drawrecttri(width, height,smalllength);
    else if(a==shapes::triangle && b==shapes::triangle)
        drawtritri(length,smalllength);
    else if(a==shapes::triangle && b==shapes::rectangle)
        drawtrirect(length, smallwidth, smallheight);
    else if(a==shapes::triangle && b==shapes::circle)
        drawtricirc(length, smallradius);

}


void drawrectrect(double width, double height, double smallwidth, double smallheight){

    int i,j,a,b,c,d,shapenum=0;
    double areanum1,areanum2,emptyarea;
    ofstream file;
    file.open("result.svg");

    file << "<svg version=\"1.1\""<<endl;
    file << "baseProfile=\"full\""<<endl;
    file << "width=\""<<width<<"\" height=\""<<height<<"\""<<endl;
    file << "xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
    file << "<rect width=\"100%\" height=\"100%\" fill=\"red\" />"<<endl;           //tamamlandý

    a=width/smallwidth;
    b=height/smallheight;
    c=width/smallheight;
    d=height/smallwidth;

    if((a*b)>=(c*d)){
        for(i=0; i<width; i=i+smallwidth)
            for(j=0; j<height; j=j+smallheight){
                if(j+smallheight<=height && i+smallwidth<=width){
                    file << "<rect x=\""<<i<<"\" y=\""<<j<<"\" width=\""<<smallwidth<<"\" height=\""<<smallheight<<"\" fill=\"green\" stroke=\"black\"/>"<<endl;
                    shapenum++;
                }
            }
    }else{
        for(i=0; i<width; i=i+smallheight)
            for(j=0; j<height; j=j+smallwidth){
                file << "<rect x=\""<<i<<"\" y=\""<<j<<"\" width=\""<<smallheight<<"\" height=\""<<smallwidth<<"\" fill=\"green\" stroke=\"black\"/>"<<endl;
                shapenum++;
            }
    }

    file <<"</svg>";
    areanum1=height*width;
    areanum2=smallheight*smallwidth*shapenum;
    emptyarea=areanum1-areanum2;
    cout<<"I can fit at most "<<shapenum<<" small shapes into the main container. The empty area (red) in container is "<<emptyarea<<"."<<endl;
    file.close();

}
void drawrectcirc(double width, double height, double radius){

    int i,j, a=0,b=0,e=0, num1,num2,num3=0,shapenum=0;
    double areanum1,areanum2,emptyarea,pi=3.14;
    ofstream file;
    file.open("result.svg");
    file << "<svg version=\"1.1\""<<endl;
    file << "baseProfile=\"full\""<<endl;
    file << "width=\""<<width<<"\" height=\""<<height<<"\""<<endl;
    file << "xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
    file << "<rect width=\"100%\" height=\"100%\" fill=\"red\" />"<<endl;

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
                    file<<"<circle cx=\""<<i<<"\" cy=\""<<j<<"\" r=\""<<radius<<"\" fill=\"green\" stroke=\"black\" />";
                    shapenum++;
                }
    }else
        for(i=radius; i<height; i+=(a*radius*sqrt(3))){
            for(j=radius; j<width; j+=2*radius){
                if(e%2==1)
                    if(b%2==1)
                        j+=radius;
                if(j+radius<=width && i+radius<=height){
                    file<<"<circle cx=\""<<j<<"\" cy=\""<<i<<"\" r=\""<<radius<<"\" fill=\"green\" stroke=\"black\" />";
                    shapenum++;
                }
                if(b%2==1)
                    j-=radius;
            }
            b++;
            e++;
            a=1;
        }
    file <<"</svg>";
    areanum1=height*width;
    areanum2=(pi*radius*radius)*shapenum;
    emptyarea=areanum1-areanum2;
    cout<<"I can fit at most "<<shapenum<<" small shapes into the main container. The empty area (red) in container is "<<emptyarea<<"."<<endl;
    file.close();
}
void drawrecttri(double width, double height, double length){
    int i,j,shapenum=0;
    double p1x=0,p1y=0,p2x=0,p2y=0,p3x=0,p3y=0,areanum1,areanum2,emptyarea;
    ofstream file;
    file.open("result.svg");
    file << "<svg version=\"1.1\""<<endl;
    file << "baseProfile=\"full\""<<endl;
    file << "width=\""<<width<<"\" height=\""<<height<<"\""<<endl;
    file << "xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
    file << "<rect width=\"100%\" height=\"100%\" fill=\"red\" />"<<endl;


         for(j=0; j<height; j+=(length/2)*sqrt(3))
            for(i=0; i<width; i+=length){
                p1x=i;
                p1y=j+length/2*sqrt(3);
                p2x=i+length/2;
                p2y=j;
                p3x=i+length;
                p3y=j+length/2*sqrt(3);
                if(p3x<width && p3y<height){
                    file << "<polygon points=\""<<p1x<<" "<<p1y<<" "<<p2x<<" "<<p2y<<" "<<p3x<<" "<<p3y<<"\" fill=\"green\" stroke=\"black\" />"<<endl;
                    shapenum++;
                }
            }
        for(j=0; j<height; j+=(length/2)*sqrt(3))
            for(i=0; i<width; i+=length){
                p1x=i+length/2;
                p1y=j;
                p2x=i+length/2+length;
                p2y=j;
                p3x=i+length;
                p3y=j+length/2*sqrt(3);
                if(p2x<width && p3y<height){
                    file << "<polygon points=\""<<p1x<<" "<<p1y<<" "<<p2x<<" "<<p2y<<" "<<p3x<<" "<<p3y<<"\" fill=\"green\" stroke=\"black\" />"<<endl;
                    shapenum++;
                }
            }

    file <<"</svg>";
    areanum1=height*width;
    areanum2=((length*(length/2*sqrt(3)))/2)*shapenum;
    emptyarea=areanum1-areanum2;
    cout<<"I can fit at most "<<shapenum<<" small shapes into the main container. The empty area (red) in container is "<<emptyarea<<"."<<endl;
    file.close();
}

void drawcircrect(double radius, double width, double height){

    double i,j,areanum1,areanum2,emptyarea,pi=3.14;
    int shapenum=0,a=0;
    double point1,point2,point3,point4;

    ofstream file;
    file.open("result.svg");
    file << "<svg width=\""<<radius*2<<"\" height=\""<<radius*2<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
    file << "<circle cx=\""<<radius<<"\" cy=\""<<radius<<"\" r=\""<<radius<<"\" fill=\"red\"/>"<<endl;
    for(i=0; i<2*radius; i++){
        for(j=0; j<2*radius; j++){
            point1=sqrt(pow((radius-(j)),2)+pow((radius-i),2));
            point2=sqrt(pow((radius-(j+width)),2)+pow((radius-(i+height)),2));
            point3=sqrt(pow((radius-(j)),2)+pow((radius-(i+height)),2));
            point4=sqrt(pow((radius-(j+width)),2)+pow((radius-i),2));
            if(point1<=radius && point2<=radius && point3<=radius && point4<=radius){
                file << "<rect x=\""<<j<<"\" y=\""<<i<<"\" width=\""<<width<<"\" height=\""<<height<<"\" fill=\"green\" stroke=\"black\"/>"<<endl;
                shapenum++;
                j+=width;
                a=1;
            }
        }
        if(a==1){
            a=0;
            i+=height;
        }
    }

    file <<"</svg>";
    areanum1=(pi*radius*radius);
    areanum2=height*width*shapenum;
    emptyarea=areanum1-areanum2;
    cout<<"I can fit at most "<<shapenum<<" small shapes into the main container. The empty area (red) in container is "<<emptyarea<<"."<<endl;
    file.close();
}
void drawcirccirc(double radius,double smallradius){

    double i,j,areanum1,areanum2,emptyarea,pi=3.14;
    int shapenum=0,temp=0,temp2=0;
    ofstream file;
    file.open("result.svg");
    file << "<svg width=\""<<radius*2<<"\" height=\""<<radius*2<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
    file << "<circle cx=\""<<radius<<"\" cy=\""<<radius<<"\" r=\""<<radius<<"\" fill=\"red\"/>"<<endl;

    for(j=0; j<=radius/smallradius; j++){
        for(i=smallradius; i<2*radius; i+=2*smallradius){
            if(i+smallradius<=2*radius){
                file<<"<circle cx=\""<<i<<"\" cy=\""<<radius<<"\" r=\""<<smallradius<<"\" fill=\"green\"  />";
                shapenum++;
           }
        }
    }
    for(j=radius-(smallradius*sqrt(3)); j>=0; j-=smallradius*sqrt(3)){
        for(i=2*smallradius+temp*smallradius; i<2*radius; i+=2*smallradius){
            if(sqrt(pow((radius-(i)),2)+pow((radius-j),2))+smallradius<=radius){
                file<<"<circle cx=\""<<i<<"\" cy=\""<<j<<"\" r=\""<<smallradius<<"\" fill=\"green\"  />";
                shapenum++;
           }
        }
        if(temp2%2==0)
            temp=1;
        else
            temp=0;
        temp2++;
    }
    temp=temp2=0;
    for(j=radius+(smallradius*sqrt(3)); j<=2*radius; j+=smallradius*sqrt(3)){
        for(i=2*smallradius+temp*smallradius; i<2*radius; i+=2*smallradius){
            if(sqrt(pow((radius-(i)),2)+pow((radius-j),2))+smallradius<=radius){
                file<<"<circle cx=\""<<i<<"\" cy=\""<<j<<"\" r=\""<<smallradius<<"\" fill=\"green\"  />";
                shapenum++;
           }
        }
        if(temp2%2==0)
            temp=1;
        else
            temp=0;
        temp2++;
    }

    file <<"</svg>";
    areanum1=(pi*radius*radius);
    areanum2=(pi*smallradius*smallradius)*shapenum;
    emptyarea=areanum1-areanum2;
    cout<<"I can fit at most "<<shapenum<<" small shapes into the main container. The empty area (red) in container is "<<emptyarea<<"."<<endl;
    file.close();
}
void drawcirctri(double radius, double length){

    double areanum1,areanum2,emptyarea,pi=3.14,p1x=0,p1y=0,p2x=0,p2y=0,p3x=0,p3y=0;
    int shapenum=0,temp=0;
    double i,j;
    ofstream file;
    file.open("result.svg");
    file << "<svg width=\""<<radius*2<<"\" height=\""<<radius*2<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
    file << "<circle cx=\""<<radius<<"\" cy=\""<<radius<<"\" r=\""<<radius<<"\" fill=\"red\"/>"<<endl;
    for(j=radius; j>0; j-=length/2*sqrt(3)){
        for(i=0; i<2*radius; i+=length){
            p1x=i;
            p1y=j;
            p2x=i+length;
            p2y=j;
            p3x=i+length/2;
            p3y=j-length/2*sqrt(3);
            if((sqrt(pow((radius-(p1x)),2)+pow((radius-p1y),2))<=radius) && (sqrt(pow((radius-(p2x)),2)+pow((radius-p2y),2))<=radius) && (sqrt(pow((radius-(p3x)),2)+pow((radius-p3y),2))<=radius)){
                file << "<polygon points=\""<<p1x<<" "<<p1y<<" "<<p2x<<" "<<p2y<<" "<<p3x<<" "<<p3y<<"\" fill=\"green\" stroke=\"black\" />"<<endl;
                file << "<polygon points=\""<<p1x<<" "<<p1y+temp*length/2*sqrt(3)<<" "<<p2x<<" "<<p2y+temp*length/2*sqrt(3)<<" "<<p3x<<" "<<p3y+2*(length/2*sqrt(3))+(temp*length/2*sqrt(3))<<"\" fill=\"green\" stroke=\"black\" />"<<endl;
                shapenum+=2;
            }
        }
        temp+=2;
    }temp=0;
    for(j=radius; j>0; j-=length/2*sqrt(3)){
        for(i=length; i<2*radius; i+=length){
            p1x=i;
            p1y=j;
            p2x=i-length/2;
            p2y=j-length/2*sqrt(3);
            p3x=i+length/2;
            p3y=j-length/2*sqrt(3);
            if((sqrt(pow((radius-(p1x)),2)+pow((radius-p1y),2))<=radius) && (sqrt(pow((radius-(p2x)),2)+pow((radius-p2y),2))<=radius) && (sqrt(pow((radius-(p3x)),2)+pow((radius-p3y),2))<=radius)){
                file << "<polygon points=\""<<p1x<<" "<<p1y<<" "<<p2x<<" "<<p2y<<" "<<p3x<<" "<<p3y<<"\" fill=\"green\" stroke=\"black\" />"<<endl;
                file << "<polygon points=\""<<p1x<<" "<<p1y+temp*length/2*sqrt(3)<<" "<<p2x<<" "<<p2y+2*(length/2*sqrt(3))+temp*length/2*sqrt(3)<<" "<<p3x<<" "<<p3y+2*(length/2*sqrt(3))+(temp*length/2*sqrt(3))<<"\" fill=\"green\" stroke=\"black\" />"<<endl;
                shapenum+=2;
            }
        }
        temp+=2;
    }
    file <<"</svg>";
    areanum1=(pi*radius*radius);
    areanum2=((length*(length/2*sqrt(3)))/2)*shapenum;
    emptyarea=areanum1-areanum2;
    cout<<"I can fit at most "<<shapenum<<" small shapes into the main container. The empty area (red) in container is "<<emptyarea<<"."<<endl;
    file.close();
}

void drawtrirect(double length, double width, double height){

    double i,j;
    int shapenum=0,a=1;
    double areanum1,areanum2,emptyarea,b;

    ofstream file;
    file.open("result.svg");
    file << "<svg width=\""<<length<<"\" height=\""<<((length/2)*sqrt(3))<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
    file << "<polygon points=\""<<length/2<<",0 0,"<<((length/2)*sqrt(3))<<","<<length<<","<<(length/2)*sqrt(3)<<"\" fill=\"red\"/>"<<endl;

    b=(height/sqrt(3))+1;
    for(j=((length/2)*sqrt(3)-height); j>=0; j-=height){
            for(i=b; i<=length-a*(height/sqrt(3)); i+=width){
                if(i+width<=length-a*(height/sqrt(3))){
                    file << "<rect x=\""<<i<<"\" y=\""<<j<<"\" width=\""<<width<<"\" height=\""<<height<<"\" fill=\"green\" stroke=\"black\"/>"<<endl;
                    shapenum++;
                }

            }
            a++;
            b=height*a/sqrt(3)+1;
        }

    file <<"</svg>";
    areanum1=((length*(length/2*sqrt(3)))/2)*shapenum;
    areanum2=width*height*shapenum;
    emptyarea=areanum1-areanum2;
    cout<<"I can fit at most "<<shapenum<<" small shapes into the main container. The empty area (red) in container is "<<emptyarea<<"."<<endl;
    file.close();
}
void drawtricirc(double length, double radius){

    int i,j,shapenum=0;
    double areanum1,areanum2,emptyarea,pi=3.14;
    int num=2*(length*sqrt(3)/2)/(3*radius);
    double x=length/2, y=2*radius;

    ofstream file;
    file.open("result.svg");
    file << "<svg width=\""<<length<<"\" height=\""<<((length/2)*sqrt(3))<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
    file << "<polygon points=\""<<length/2<<",0 0,"<<((length/2)*sqrt(3))<<","<<length<<","<<(length/2)*sqrt(3)<<"\" fill=\"red\"/>"<<endl;

    for(j=0; j<num; ++j){
        for(i=0; i<j+1; ++i){
            if(y+radius<=length*sqrt(3)/2){
                file<<"<circle cx=\""<<x<<"\" cy=\""<<y<<"\" r=\""<<radius<<"\" fill=\"green\" stroke=\"black\" />";
                shapenum++;
            }
            x+=(radius*2);
        }
        x=length/2;
        x-=((j+1)*radius);
        y+=(radius*sqrt(3));
        }

    file <<"</svg>";
    areanum1=(length*(length/2*sqrt(3)))/2;
    areanum2=(pi*radius*radius)*shapenum;
    emptyarea=areanum1-areanum2;
    cout<<"I can fit at most "<<shapenum<<" small shapes into the main container. The empty area (red) in container is "<<emptyarea<<"."<<endl;
    file.close();
}
void drawtritri(double length, double smallength){

    double p1x=0,p1y=0,p2x=0,p2y=0,p3x=0,p3y=0,temp=0,areanum1,areanum2,emptyarea;
    double i,j;
    int shapenum=0;

    ofstream file;
    file.open("result.svg");
    file << "<svg width=\""<<length<<"\" height=\""<<((length/2)*sqrt(3))<<"\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
    file << "<polygon points=\""<<length/2<<",0 0,"<<((length/2)*sqrt(3))<<","<<length<<","<<(length/2)*sqrt(3)<<"\" fill=\"red\"/>"<<endl;

    for(j=length/2*sqrt(3); j>=0; j-=(smallength/2)*sqrt(3)){
        for(i=temp; i<length-temp; i+=smallength){
            p1x=i;
            p1y=j;
            p2x=i+smallength/2;
            p2y=j-smallength/2*sqrt(3);
            p3x=i+smallength;
            p3y=j;
            if(p3x<=length-temp && p3y>0){
                file << "<polygon points=\""<<p1x<<" "<<p1y<<" "<<p2x<<" "<<p2y<<" "<<p3x<<" "<<p3y<<"\" fill=\"green\"  />"<<endl;
                shapenum++;
            }
        }
        temp+=smallength/2;
    }
    temp=smallength/2;
    for(j=length/2*sqrt(3); j>=0; j-=(smallength/2)*sqrt(3)){
        for(i=temp; i<length-temp; i+=smallength){
            p1x=i+smallength/2;
            p1y=j;
            p2x=i;
            p2y=j-smallength/2*sqrt(3);
            p3x=i+smallength;
            p3y=j-smallength/2*sqrt(3);
            if(p3x<=length-temp && p3y>0){
                file << "<polygon points=\""<<p1x<<" "<<p1y<<" "<<p2x<<" "<<p2y<<" "<<p3x<<" "<<p3y<<"\" fill=\"green\"  />"<<endl;
                shapenum++;
            }
        }
        temp+=smallength/2;
    }

    file <<"</svg>";
    areanum1=((length*(length/2*sqrt(3)))/2);
    areanum2=((smallength*(smallength/2*sqrt(3)))/2)*shapenum;
    emptyarea=areanum1-areanum2;
    cout<<"I can fit at most "<<shapenum<<" small shapes into the main container. The empty area (red) in container is "<<emptyarea<<"."<<endl;
    file.close();
}
