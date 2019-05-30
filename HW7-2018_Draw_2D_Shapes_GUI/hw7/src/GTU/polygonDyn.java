/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GTU;


import java.awt.*;
import java.util.Vector;
/**
 * @author Nurullah GUNDOGDU
 * since 2019-1-16
 */
public class polygonDyn extends polygon{
    /**
     *  empty array for Point2D objects
     */
    private Point2D [] points;

    /**   convert rectengal to polygon
     * @param rec rectengal object
     */
    public polygonDyn(rectengal rec){
        setsize(4);

        points=new Point2D[getsize()];

        Point2D p=new Point2D(rec.getx_coordinate(),rec.gety_coordinate());
        points[0]= p;

        Point2D p_1=new Point2D(rec.getx_coordinate()+rec.getwidth(),rec.gety_coordinate());
        points[1]= p_1;

        Point2D p_2=new Point2D(rec.getx_coordinate()+rec.getwidth(),rec.gety_coordinate()+rec.getheight());
        points[2]=p_2;

        Point2D p_3=new Point2D(rec.getx_coordinate(),rec.gety_coordinate()+rec.getheight());
        points[3]=p_3;
    }
    /**   convert circle to polygon
     * @param circ circle object
     */
    public polygonDyn(circle circ){
        setsize(100);

        points=new Point2D[getsize()];

        for(int i=1; i<=100; i++){
            if(circ.getname().equals("C")){
                Point2D p=new Point2D(circ.getx_coordinate()+(circ.getradius()+circ.getradius()*Math.sin(((2*Math.PI)/100)*i)),circ.gety_coordinate()+(circ.getradius()+circ.getradius()*Math.cos(((2*Math.PI)/100)*i)));
                points[i-1]=p;
            }else{
                Point2D p=new Point2D(circ.getx_coordinate()+(circ.getradius()*Math.sin(((2*Math.PI)/100)*i)),circ.gety_coordinate()+(circ.getradius()*Math.cos(((2*Math.PI)/100)*i)));
                points[i-1]=p;
            }
        }
    }
    /**   convert triangle to polygon
     * @param tria triangle object
     */
    public polygonDyn(triangle tria){
        setsize(3);

        points=new Point2D[getsize()];

        Point2D p=new Point2D(tria.getx_coordinate(),tria.gety_coordinate());
        points[0]=p;

        Point2D p_1=new Point2D(tria.getx_coordinate_2(),tria.gety_coordinate_2());
        points[1]=p_1;

        Point2D p_2=new Point2D(tria.getx_coordinate_3(),tria.gety_coordinate_3());
        points[2]=p_2;
    }
    /**   add object to vector
     * @param po Point2D object
     */
    public polygonDyn(Point2D po){

        setsize(1);
        points=new Point2D[getsize()];
        points[0]=po;
    }        //point to polygon uctur
    /**
     * convert vector to array
     * @param point
     */
    public polygonDyn( Vector <Point2D> point){
        setsize(point.size());
        points=new Point2D[getsize()];

        for(int i=0; i<getsize(); i++)
            points[i]= point.get(i);

    }
    /**   draw circle
     * @param g Graphics object
     */
    @Override
    public void draw(Graphics g){
        Polygon p = new Polygon();
        p.addPoint(5, 5); p.addPoint(250, 5); p.addPoint(250, 250); p.addPoint(5, 250);
        Polygon pInner = new Polygon();
        pInner.addPoint(10, 10); pInner.addPoint(55,155); pInner.addPoint(155, 55);

    }
    /**   decrease coordinate
     */
    @Override
    public void increment(){
        for(int i=0; i<10; i++){
            points[i].setx( points[i].getx()+1);
            points[i].sety( points[i].gety()+1);
        }
    }
    /**   decrease coordinate
     */
    @Override
    public void decremenet(){
        for(int i=0; i<10; i++){
            points[i].setx( points[i].getx()-1);
            points[i].sety( points[i].gety()-1);
        }
    }

}
