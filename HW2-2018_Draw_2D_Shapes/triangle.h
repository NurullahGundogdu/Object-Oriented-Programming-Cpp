#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<vector>
#include <fstream>

using namespace std;

class triangle{
    public:
        triangle();
        triangle(double Length);

        void draw(ofstream &file);

        inline void setlength(const double a){this->length=a;}
        inline double getlength() const {return length;}
        inline void setx_coordinate(const double a){x_coordinate=a;}
        inline void sety_coordinate(const double a){y_coordinate=a;}
        inline double getx_coordinate() const {return x_coordinate;}
        inline double gety_coordinate() const {return y_coordinate;}
        inline void setx_coordinate_2(const double a){x_coordinate_2=a;}
        inline void sety_coordinate_2(const double a){y_coordinate_2=a;}
        inline double getx_coordinate_2() const {return x_coordinate_2;}
        inline double gety_coordinate_2() const {return y_coordinate_2;}
        inline void setx_coordinate_3(const double a){x_coordinate_3=a;}
        inline void sety_coordinate_3(const double a){y_coordinate_3=a;}
        inline double getx_coordinate_3() const {return x_coordinate_3;}
        inline double gety_coordinate_3() const {return y_coordinate_3;}
        inline string gettype() const {return type;}
        inline void settype(string name){type=name;}

    private:
        string type;
        double length;
        double x_coordinate;
        double y_coordinate;
        double x_coordinate_2;
        double y_coordinate_2;
        double x_coordinate_3;
        double y_coordinate_3;

};

#endif // TRIANGLE_H
