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
import java.util.Vector;

public class polygonVect extends polygon{
    /**
     *  empty vector for Point2D objects
     */
    private Vector <Point2D> points;
    /**
     *  size for vector size
     */
    private int Size;
    /**   convert rectengal to polygon
     * @param rec rectengal object
     */
    public polygonVect(rectengal rec){

        points = new Vector<>();
        Point2D p=new Point2D(rec.getx_coordinate(),rec.gety_coordinate());
        points.add(p);


        Point2D p_1=new Point2D(rec.getx_coordinate()+rec.getwidth(),rec.gety_coordinate());
        points.add(p_1);

        Point2D p_2=new Point2D(rec.getx_coordinate()+rec.getwidth(),rec.gety_coordinate()+rec.getheight());
        points.add(p_2);

        Point2D p_3=new Point2D(rec.getx_coordinate(),rec.gety_coordinate()+rec.getheight());
        points.add(p_3);
        Size=4;
    }
    /**   convert circle to polygon
     * @param circ circle object
     */
    public polygonVect(circle circ){

        points = new Vector<>();

        for(int i=1; i<=100; i++){
            if(circ.getname().equals("C")){
                Point2D p=new Point2D(circ.getx_coordinate()+(circ.getradius()+circ.getradius()*Math.sin(((2*Math.PI)/100)*i)),circ.gety_coordinate()+(circ.getradius()+circ.getradius()*Math.cos(((2*Math.PI)/100)*i)));
                points.add(p);
            }else{
                Point2D p=new Point2D(circ.getx_coordinate()+(circ.getradius()*Math.sin(((2*Math.PI)/100)*i)),circ.gety_coordinate()+(circ.getradius()*Math.cos(((2*Math.PI)/100)*i)));
                points.add(p);
            }
        }
        Size=100;
    }
    /**   convert triangle to polygon
     * @param tria triangle object
     */
    public polygonVect(triangle tria){

        points = new Vector<>();
        Point2D p=new Point2D(tria.getx_coordinate(),tria.gety_coordinate());
        points.add(p);

        Point2D p_1=new Point2D(tria.getx_coordinate_2(),tria.gety_coordinate_2());
        points.add(p_1);

        Point2D p_2=new Point2D(tria.getx_coordinate_3(),tria.gety_coordinate_3());
        points.add(p_2);
        Size=3;
    }
    /**   add object to vector
     * @param po Point2D object
     */
    public polygonVect(Point2D po){
        points = new Vector<>();
        points.add(po);
    }

    /**   increase coordinate
     */
    @Override
    public void increment(){
        for(int i=0; i<Size; i++){
            points.get(i).setx( points.get(i).getx()+1);
            points.get(i).sety( points.get(i).gety()+1);
        }
    }
    /**   decrease coordinate
     */
    @Override
    public void decremenet(){
        for(int i=0; i<Size; i++){
            points.get(i).setx( points.get(i).getx()-1);
            points.get(i).sety( points.get(i).gety()-1);
        }
    }
    /**   return points vector
     * @return points
     */
    Vector<Point2D> getvec() {return points;}
    /**   return size of vector
     *  @return size
     */
    public int size() {return Size;}
    /**   draw polygon
     * @param g Graphics object
     */
    @Override
    public void draw(Graphics g){


        Polygon p = new Polygon();

        for (Point2D point : points) {
            p.addPoint((int)point.getx(),(int) point.gety());
            p.addPoint((int)point.getx(), (int)point.gety());
            p.addPoint((int)point.getx(),(int) point.gety());
            p.addPoint((int)point.getx(),(int) point.gety());
        }

        if(this.getname().equals("P")) {
            g.setColor(Color.RED);
        }else
            g.setColor(Color.GREEN);

    }

}
