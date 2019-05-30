/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GTU;

import java.awt.*;

/**
 * @author Nurullah GUNDOGDU
 * since 2019-1-16
 */

public abstract class polygon implements shape{

    class Point2D{

        Point2D(double x_value, double y_value){
            x=x_value;
            y=y_value;
        }
        void setx(double a){x=a;}
        void sety(double a){y=a;}
        double getx() {return x;}
        double gety() {return y;}

        private double x;
        private double y;

    }
    /**
     * parameters for polygon
     */
    private int sizes;
    private double pol_area;
    private double pol_perimeter;
    private String name;

    /**
     * polygon setters and getters
     */
    public void setname(String a){name=a;}
    public String getname(){
        return name;
    }
    void setsize(int a){sizes=a;}
    int getsize(){return sizes;}
    public void setArea(double a){pol_area=a;}
    public double getArea() {return pol_area;}
    public void setPerimeter(double a){pol_perimeter=a;}
    public double getPerimeter() {return pol_perimeter;}

    /**   draw circle
     * @param g Graphics object
     */
    public abstract void draw(Graphics g);
    public abstract void increment();
    public abstract void decremenet();

    /**
     * compare shape with respect to their areas.
     * @param other object of shape
     */
    @Override
    public int compareTo(shape other){
        return Integer.compare((int)this.Area(),(int)other.Area());

    }

    /**
     * @return area of polygon
     */
    @Override
    public double Area(){

        return pol_area;
    }
    /**
     * @return perimeter of polygon
     */
    @Override
    public double Perimeter(){

        return pol_perimeter;
    }



}
