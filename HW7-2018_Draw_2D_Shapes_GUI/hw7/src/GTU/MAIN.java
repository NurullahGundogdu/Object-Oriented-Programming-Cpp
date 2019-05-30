/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package GTU;


import java.awt.EventQueue;
import java.awt.Graphics;
import javax.swing.JPanel;

/**
 * @author Nurullah GUNDOGDU
 * since 2019-1-16
 */
public class MAIN {

    /**
     * create newShapes object
     */
    public static void main(String [] args){

        EventQueue.invokeLater(() -> {
            try {
                newShapes window = new newShapes();
                window.frame.setVisible(true);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });

    }
    /**
     * draw shapes
     * @param arr,j for drawing shapes
     */
    public static void drawAll(shape arr[], JPanel j){
        Graphics g = j.getGraphics();
        Graphics e= j.getGraphics();
        for (shape anArr : arr) {
            anArr.draw(g);
        }
        j.paintComponents(e);

    }
    /**
     * convert to polygon shapes
     * @param arr for converting shapes
     */
    public static shape[] convertAll(shape[] arr){
        shape [] temp;
        temp=new shape[arr.length];

        for(int i=0; i<arr.length; i++ ) {

            switch (arr[i].getname()) {
                case "R":
                case "r": {
                    rectengal rec = (rectengal) arr[i];

                    polygonVect pol = new polygonVect(rec);
                    if (arr[i].getname().equals("R"))
                        pol.setname("P");              //rectengal convert to polygon
                    else {
                        pol.setname("p");
                    }

                    pol.setArea(rec.Area());
                    pol.setPerimeter(rec.Perimeter());
                    temp[i] = pol;

                    break;
                }
                case "C":
                case "c": {
                    circle circ = (circle) arr[i];
                    polygonVect pol = new polygonVect(circ);
                    if (arr[i].getname().equals("C"))
                        pol.setname("P");
                    else
                        pol.setname("p");


                    pol.setArea(circ.Area());
                    pol.setPerimeter(circ.Perimeter());
                    temp[i] = pol;

                    break;
                }
                case "T":
                case "t": {
                    triangle tria = (triangle) arr[i];

                    polygonVect pol = new polygonVect(tria);                     //triangle convert to polygon
                    if (arr[i].getname().equals("T"))
                        pol.setname("P");
                    else
                        pol.setname("p");

                    pol.setArea(tria.Area());
                    pol.setPerimeter(tria.Perimeter());
                    temp[i] = pol;

                    break;
                }
            }
        }
        return temp;
    }
    /**
     * sort shapes
     * @param SHAPE for sorting shapes
     */
    public static void sortShapes(shape [] SHAPE){
        for(int i=0; i<SHAPE.length; i++)
             for(int j=0; j<SHAPE.length; j++)
                if(SHAPE[j].Area()<SHAPE[j+1].Area()){
                    shape s;
                    s=SHAPE[j];                 //sorts shapes according to their areas.
                    SHAPE[j]=SHAPE[j+1];
                    SHAPE[j+1]=s;
        }
    }

}
