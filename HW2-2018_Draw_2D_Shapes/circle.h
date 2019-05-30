#ifndef CIRCLE_H
#define CIRCLE_H
#include<vector>
#include<fstream>

using namespace std;

class circle{

    public:
        circle();
        circle(double Radius);

        void draw(ofstream &file);


        inline void setradius(const double a){this->radius=a;}
        inline double getradius() const {return radius;}

        inline void setx_coordinate(const double a){x_coordinate=a;}
        inline void sety_coordinate(const double a){y_coordinate=a;}
        inline double getx_coordinate() const {return x_coordinate;}
        inline double gety_coordinate() const {return y_coordinate;}
        inline string gettype() const {return type;}
        inline void settype(string name){type=name;}
    private:
        string type;
        double radius;
        double x_coordinate;
        double y_coordinate;
};


#endif // CIRCLE_H
