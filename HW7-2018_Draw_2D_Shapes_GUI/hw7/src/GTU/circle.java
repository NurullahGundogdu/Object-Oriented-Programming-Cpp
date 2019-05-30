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

public class circle implements shape{


    /**
     *  circle coordinates
     */
    private double radius;
    private double x_coordinate;
    private double y_coordinate;
    private String name;
    /**
     *  create circle
     * @param Radius for circle
     */
    public circle(double Radius){
        radius=Radius;

        x_coordinate=0;
        y_coordinate=0;
    }

    /**   draw circle
     * @param g Graphics object
     */
    public void draw(Graphics g){
        Polygon p = new Polygon();

        p.addPoint((int)x_coordinate, (int)y_coordinate);

        if(this.getname().equals("P")) {
            g.setColor(Color.RED);
        }else
            g.setColor(Color.GREEN);
        g.fillPolygon(p);
    }

    /**
     * @param  a for circle name
     */
    public void setname(String a){
        name=a;
    }

    /**
     *  coordinates setter and getters
     * @param a for radius
     */
    public void setradius(double a){radius=a;}
    public double getradius() {return radius;}
    public void setx_coordinate(double a){x_coordinate=a;}
    public void sety_coordinate(double a){y_coordinate=a;}
    public double getx_coordinate() {return x_coordinate;}
    public double gety_coordinate() {return y_coordinate;}


    /**
     * @return name of circle
     */
    @Override
    public String getname(){
        return name;
    }
    /**
     * @return area of circle
     */
    @Override
    public double Area(){

        return Math.PI*radius*radius;
    }
    /**
     * @return perimeter of circle
     */
    @Override
    public double Perimeter(){
        return 2*Math.PI*radius;
    }
    /**
     * increment circle coordinate
     */
    @Override
    public void increment(){
        x_coordinate+=1.0;
        y_coordinate+=1.0;
    }
    /**
     * decremenet circle coordinate
     */
    @Override
    public void decremenet(){
        x_coordinate-=1.0;
        y_coordinate-=1.0;
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
