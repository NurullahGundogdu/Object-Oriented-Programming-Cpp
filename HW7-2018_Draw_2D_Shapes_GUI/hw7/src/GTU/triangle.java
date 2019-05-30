/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GTU;
/**
 * @author Nurullah GUNDOGDU
 * since 2019-1-16
 */

import java.awt.*;

public class triangle implements shape{


    /**
     *  length for triangle
     */
    private double length;
    /**
     *  triangle coordinates
     */
    private double x_coordinate;
    private double y_coordinate;
    private double x_coordinate_2;
    private double y_coordinate_2;
    private double x_coordinate_3;
    private double y_coordinate_3;

    /**
     *  triangle type name
     */
    private String name;


    /**
     *  create triangle
     * @param Length for triangle
     */
    public triangle(double Length){
        length=Length;

        x_coordinate=0;
        y_coordinate=0;
        x_coordinate_2=0;
        y_coordinate_2=0;
        x_coordinate_3=0;
        y_coordinate_3=0;

    }

    /**
     *  coordinates setter and getters
     */
    public double getlength() {return length;}
    public  void setx_coordinate(double a){x_coordinate=a;}
    public void sety_coordinate(double a){y_coordinate=a;}
    public double getx_coordinate() {return x_coordinate;}
    public  double gety_coordinate() {return y_coordinate;}        //set and get function for variables
    public void setx_coordinate_2(double a){x_coordinate_2=a;}
    public void sety_coordinate_2(double a){y_coordinate_2=a;}
    public  double getx_coordinate_2() {return x_coordinate_2;}
    public  double gety_coordinate_2() {return y_coordinate_2;}
    public void setx_coordinate_3(double a){x_coordinate_3=a;}
    public void sety_coordinate_3(double a){y_coordinate_3=a;}
    public double getx_coordinate_3() {return x_coordinate_3;}
    public double gety_coordinate_3() {return y_coordinate_3;}
    public void setname(String a){ name=a; }

    /**   draw triangle
     * @param g Graphics object
     */
    @Override
    public void draw(Graphics g){
        Polygon p = new Polygon();

        p.addPoint((int)x_coordinate, (int)y_coordinate);
        p.addPoint((int)x_coordinate_2, (int)y_coordinate_2);
        p.addPoint((int)x_coordinate_3, (int)y_coordinate_3);

        if(this.getname().equals("P")) {
            g.setColor(Color.RED);
        }else
            g.setColor(Color.GREEN);
        g.fillPolygon(p);
    }
    /**
     * @return name of triangle
     */
    @Override
    public String getname(){
        return name;
    }
    /**
     * @return area of triangle
     */
    @Override
    public double Area(){
        return (length*(length/2*Math.sqrt(3)))/2;

    }
    /**
     * @return perimeter of triangle
     */
    @Override
    public double Perimeter(){
        return 3*length;
    }
    /**
     * increment triangle coordinate
     */
    @Override
    public void increment(){
        x_coordinate+=1;
        y_coordinate+=1;
        x_coordinate_2+=1;
        y_coordinate_2+=1;
        x_coordinate_3+=1;
        y_coordinate_3+=1;
    }
    /**
     * decrement triangle coordinate
     */
    @Override
    public void decremenet(){
        x_coordinate-=1;
        y_coordinate-=1;
        x_coordinate_2-=1;
        y_coordinate_2-=1;
        x_coordinate_3-=1;
        y_coordinate_3-=1;
    }

    /**
     * compare shape with respect to their areas.
     * @param other object of shape
     */
    @Override
    public int compareTo(shape other){
        return Integer.compare((int)this.Area(),(int)other.Area());

    }
}
