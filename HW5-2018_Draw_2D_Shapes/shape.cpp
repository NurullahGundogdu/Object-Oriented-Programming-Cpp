#include "shape.h"
#include <iostream>

namespace SHAPES{
    using namespace std;

    shape::shape():shape_Area(0.0),shape_Perimeter(0.0)
    {

    }

    bool shape::operator !=(shape& SHAPE){
        if(Area()!= SHAPE.Area())
            return true;
        else
            return false;
    }
    bool shape::operator ==(shape& SHAPE){
        if(Area()== SHAPE.Area())
            return true;
        else
            return false;
    }
    bool shape::operator <(shape& SHAPE){

        if(Area() < SHAPE.Area())
            return true;
        else
            return false;
    }
    bool shape::operator >(shape& SHAPE){

        if(Area() > SHAPE.Area())
            return true;
        else
            return false;
    }
}
