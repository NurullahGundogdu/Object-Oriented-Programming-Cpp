/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GTU;

import java.awt.*;
/**
 @author Nurullah GUNDOGDU
  * since 2019-1-16
 */

public class rectengal implements shape {

    /**
     *  rectengal coordinates
     */
    private double x_coordinate;
    private double y_coordinate;
    private double width;
    private double height;
    private String name;
    /**
     *  create rectengal
     * @param Width Height
     */
    public rectengal(double Width, double Height){
        height=Height;
        width=Width;
        x_coordinate=0;
        y_coordinate=0;
    }

    /**
     *  coordinates setter and getters
     */
    public double getwidth(){return width;}
    public double getheight(){return height;}
    void setx_coordinate(double a){x_coordinate=a;}
    void sety_coordinate(double a){y_coordinate=a;}
    double getx_coordinate(){return x_coordinate;}
    double gety_coordinate(){return y_coordinate;}



    /**
     * @return name of rectengal
     */
    @Override
    public String getname(){

        return name;
    }
    /**
     * @param  a for rectangal name
     */
    public void setname(String a){
        name=a;
    }
    /**   draw rectengal
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
     * @return area of rectengal
     */
    @Override
    public double Area(){

        return height*width;
    }
    /**
     * @return perimeter of rectengal
     */
    @Override
    public double Perimeter(){

        return 2*(height + width);
    }
    /**
     * increment rectengal coordinate
     */
    @Override
    public void increment(){
        x_coordinate+=1.0;
        y_coordinate+=1.0;

    }/**
     * decrement rectengal coordinate
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
