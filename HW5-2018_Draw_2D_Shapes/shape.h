#ifndef SHAPE_H
#define SHAPE_H

#include <vector>

namespace SHAPES{

    class shape
    {
        public:

            shape();

            virtual double Area()=0;
            virtual double Perimeter()=0;

            virtual shape& operator ++()=0;
            virtual shape& operator ++(int)=0;
            virtual shape& operator --()=0;
            virtual shape& operator --(int)=0;
            virtual bool operator !=(shape& SHAPE);
            virtual bool operator ==(shape& SHAPE);
            virtual bool operator <(shape& SHAPE);          //operator overloading for necessary operation
            virtual bool operator >(shape& SHAPE);

            inline void setarea(const double a){shape_Area=a;}
            inline void setperimeter(const double a){shape_Perimeter=a;}
            inline void setname(const char a){name=a;}
            inline char getname() const {return name;}

        protected:
            double shape_Area;
            double shape_Perimeter;
            char name;


    };

}
#endif // SHAPE_H
