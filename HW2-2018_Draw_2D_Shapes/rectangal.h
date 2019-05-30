#ifndef RECTANGAL_H
#define RECTANGAL_H
#include<vector>
#include <fstream>

using namespace std;

class rectengal{

    public:

        rectengal();
        rectengal(double Width, double Height);

        void draw(ofstream &file);

        inline void setwidth(const double a){width=a;}
        inline void setheight(const double a){height=a;}
        inline double getwidth() const {return width;}
        inline double getheight()const {return height;}
        inline void setx_coordinate(const double a){x_coordinate=a;}
        inline void sety_coordinate(const double a){y_coordinate=a;}
        inline double getx_coordinate() const {return x_coordinate;}
        inline double gety_coordinate() const {return y_coordinate;}
        inline string gettype() const {return type;}
        inline void settype(string name){type=name;}

    private:
        string type;
        double x_coordinate;
        double y_coordinate;
        double width;
        double height;

};

#endif // RECTANGAL_H
