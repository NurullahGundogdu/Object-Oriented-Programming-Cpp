/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GTU;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
/**
 * @author Nurullah GUNDOGDU
 * since 2019-1-16
 */
public class newShapes{

    /**
     * GUI parameters
     */
    protected JFrame frame;
    private JComboBox<String> contShape;
    private JComboBox<String> innShape;
    private JComboBox<String> contwith;
    private JComboBox<String> contheight;
    private JComboBox<String> innerheight;
    private JComboBox<String> innerwith;
    private JPanel panel;

    /**
     * GUI constructur
     */
    newShapes(){

        createWindow();
        comboBoxName();

        comboBox();

        clearButton();

        drawButton();
    }
    /**
     * create main Window
     */
    private void createWindow(){
        frame = new JFrame();
        frame.setBounds(200, 20, 600, 800);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(null);

        panel = new JPanel();
        panel.setBackground(Color.WHITE);
        panel.setBounds(10, 11, 550, 500);
        frame.getContentPane().add(panel); // panel reference copied

    }
    /**
     * create comboboxname
     */
    private void comboBoxName(){
        JLabel contShape = new JLabel("Container shape");
        contShape.setHorizontalAlignment(SwingConstants.CENTER);
        contShape.setBounds(10, 522, 99, 14);
        frame.getContentPane().add(contShape);

        JLabel innShape = new JLabel("Inner shape");
        innShape.setHorizontalAlignment(SwingConstants.CENTER);
        innShape.setBounds(210, 522, 100, 14);
        frame.getContentPane().add(innShape);

        JLabel WIDTH = new JLabel("Width/Radius/Length");
        WIDTH.setHorizontalAlignment(SwingConstants.CENTER);
        WIDTH.setBounds(10, 576, 118, 14);
        frame.getContentPane().add(WIDTH);

        JLabel HEIGHT = new JLabel("Height (JUST BIG RECTANGLE)");
        HEIGHT.setHorizontalAlignment(SwingConstants.CENTER);
        HEIGHT.setBounds(10, 616, 170, 14);
        frame.getContentPane().add(HEIGHT);

        JLabel smallWIDTH = new JLabel("Width/Radius/Length");
        smallWIDTH.setHorizontalAlignment(SwingConstants.CENTER);
        smallWIDTH.setBounds(210, 576, 118, 14);
        frame.getContentPane().add(smallWIDTH);

        JLabel smallHEIGHT = new JLabel("Height (JUST SMALL RECTANGLE)");
        smallHEIGHT.setHorizontalAlignment(SwingConstants.CENTER);
        smallHEIGHT.setBounds(210, 616, 200, 14);
        frame.getContentPane().add(smallHEIGHT);

    }
    /**
     * create combobox
     */
    private void comboBox(){

        contShape = new JComboBox<>();
        contShape.setSelectedIndex(-1);
        contShape.setMaximumRowCount(3);
        contShape.setBounds(10, 543, 100, 20);
        contShape.addItem("Rectangle");
        contShape.addItem("Triangle");
        contShape.addItem("Circle");
        frame.getContentPane().add(contShape);

        innShape = new JComboBox<>();
        innShape.setSelectedIndex(-1);
        innShape.setMaximumRowCount(3);
        innShape.setBounds(210, 543, 100, 20);
        innShape.addItem("Rectangle");
        innShape.addItem("Triangle");
        innShape.addItem("Circle");
        frame.getContentPane().add(innShape);

        contwith = new JComboBox<>();
        contwith.setSelectedIndex(-1);
        contwith.setMaximumRowCount(10);
        contwith.addItem("300");
        contwith.addItem("391");
        contwith.addItem("343");
        contwith.addItem("378");
        contwith.addItem("450");
        contwith.addItem("455");
        contwith.addItem("460");
        contwith.addItem("463");
        contwith.addItem("470");
        contwith.addItem("472");

        contwith.setBounds(10, 590, 100, 20);

        frame.getContentPane().add(contwith);

        contheight = new JComboBox<>();
        contheight.setSelectedIndex(-1);
        contheight.setMaximumRowCount(10);
        contheight.addItem("300");
        contheight.addItem("391");
        contheight.addItem("343");
        contheight.addItem("378");
        contheight.addItem("450");
        contheight.addItem("455");
        contheight.addItem("460");
        contheight.addItem("463");
        contheight.addItem("470");
        contheight.addItem("472");
        contheight.setBounds(10, 630, 100, 20);

        frame.getContentPane().add(contheight);

        innerwith = new JComboBox<>();
        innerwith.setSelectedIndex(-1);
        innerwith.setMaximumRowCount(10);
        innerwith.addItem("30");
        innerwith.addItem("39");
        innerwith.addItem("44");
        innerwith.addItem("45");
        innerwith.addItem("49");
        innerwith.addItem("51");
        innerwith.addItem("57");
        innerwith.addItem("63");
        innerwith.addItem("70");
        innerwith.addItem("72");
        innerwith.setBounds(210, 590, 100, 20);

        frame.getContentPane().add(innerwith);

        // Combo box for selecting inner shape
        innerheight = new JComboBox<>();
        innerheight.setSelectedIndex(-1);
        innerheight.setMaximumRowCount(10);
        innerheight.addItem("30");
        innerheight.addItem("39");
        innerheight.addItem("44");
        innerheight.addItem("45");
        innerheight.addItem("49");
        innerheight.addItem("51");
        innerheight.addItem("57");
        innerheight.addItem("63");
        innerheight.addItem("70");
        innerheight.addItem("72");
        innerheight.setBounds(210, 630, 100, 20);

        frame.getContentPane().add(innerheight);

    }
    /**
     * user selection
     */
    private double index(Object a) {
        Object b=0,b1=1,b2=2,b3=3,b4=4,b5=5,b6=6,b7=7,b8=8,b9=9;
        if(a == b) {
            return 300;
        }else if(a==b1) {
            return 391;
        }else if(a==b2) {
            return 343;
        }else if(a==b3) {
            return 378;
        }else if(a==b4) {
            return 450;
        }else if(a==b5) {
            return 455;
        }else if(a==b6) {
            return 460;
        }else if(a==b7) {
            return 463;
        }else if(a==b8) {
            return 470;
        }else if(a==b9) {
            return 472;
        }

        return 0;
     }

    /**
     * user selection 2
     */
    private double index2(Object a){
        Object b=0,b1=1,b2=2,b3=3,b4=4,b5=5,b6=6,b7=7,b8=8,b9=9;
        if(a==b) {
            return 30;
        }else if(a==b1) {
            return 39;
        }else if(a==b2) {
            return 44;
        }else if(a==b3) {
            return 45;
        }else if(a==b4) {
            return 49;
        }else if(a==b5) {
            return 51;
        }else if(a==b6) {
            return 57;
        }else if(a==b7) {
            return 63;
        }else if(a==b8) {
            return 70;
        }else if(a==b9) {
            return 72;
        }
        return 0;
    }
    private shape[] fun(Object a, Object b){
        double num1,num2,num3,num4;
        shape arr[];
        arr=new shape[0];
        if(a=="Rectangle" && b=="Rectangle") {
            num1=index(contheight.getSelectedIndex());
            num2=index(contwith.getSelectedIndex());
            num3=index2(innerheight.getSelectedIndex());
            num4=index2(innerwith.getSelectedIndex());
            rectengal rec=new rectengal(num2,num1);
            rectengal recsmall=new rectengal(num4,num3);
            composedShape comp=new composedShape(rec,recsmall);
            arr= MAIN.convertAll(comp.getarr());
            MAIN.drawAll(arr,panel);
            return arr;
        }else if(a=="Rectangle" && b=="Circle") {
            num1=index(contheight.getSelectedIndex());
            num2=index(contwith.getSelectedIndex());
            num3=index2(innerheight.getSelectedIndex());

            rectengal rec=new rectengal(num2,num1);
            circle circ=new circle(num3);
            composedShape comp=new composedShape(rec,circ);
            arr=MAIN.convertAll(comp.getarr());

            return arr;
        }else if(a=="Rectangle" && b=="Triangle") {
            num1=index(contheight.getSelectedIndex());
            num2=index(contwith.getSelectedIndex());
            num3=index2(innerheight.getSelectedIndex());

            rectengal rec=new rectengal(num2,num1);
            triangle tri=new triangle(num3);
            composedShape comp=new composedShape(rec,tri);
            arr=MAIN.convertAll(comp.getarr());
            return arr;
        }else if(a=="Circle" && b=="Rectangle") {
            num1=index(contheight.getSelectedIndex());
            num3=index2(innerheight.getSelectedIndex());
            num4=index2(innerwith.getSelectedIndex());
            circle circ=new circle(num1/2);
            rectengal rec=new rectengal(num4,num3);

            composedShape comp=new composedShape(circ,rec);
            arr=MAIN.convertAll(comp.getarr());
            return arr;
        }else if(a=="Circle" && b=="Circle") {

            num1=index(contheight.getSelectedIndex());
            num3=index2(innerheight.getSelectedIndex());

            circle circ=new circle(num1/2);
            circle circsmall=new circle(num3);
            composedShape comp=new composedShape(circ,circsmall);

            arr=MAIN.convertAll(comp.getarr());
            return arr;
        }else if(a=="Circle" && b=="Triangle") {

            num1=index(contheight.getSelectedIndex());
            num3=index2(innerheight.getSelectedIndex());
            circle circ=new circle(num1/2);
            triangle tri=new triangle(num3);
            composedShape comp=new composedShape(circ,tri);

            arr=MAIN.convertAll(comp.getarr());
            return arr;
        }else if(a=="Triangle" && b=="Rectangle") {

            num1=index(contheight.getSelectedIndex());
            num2=index2(innerwith.getSelectedIndex());
            num3=index2(innerheight.getSelectedIndex());

            rectengal rec=new rectengal(num2,num3);
            triangle tri=new triangle(num1);
            composedShape comp=new composedShape(tri,rec);

            arr=MAIN.convertAll(comp.getarr());
            return arr;
        }else if(a=="Triangle" && b=="Circle") {

            num1=index(contheight.getSelectedIndex());

            num3=index2(innerheight.getSelectedIndex());

            circle circ=new circle(num3);
            triangle tri=new triangle(num1);
            composedShape comp=new composedShape(tri,circ);


            arr=MAIN.convertAll(comp.getarr());
            return arr;
        }else if(a=="Triangle" && b=="Triangle") {

            num1=index(contheight.getSelectedIndex());
            num3=index2(innerheight.getSelectedIndex());
            triangle trism=new triangle(num3);
            triangle tri=new triangle(num1);
            composedShape comp=new composedShape(tri,trism);

            arr=MAIN.convertAll(comp.getarr());
            return arr;
        }
        return arr;
    }


    /**
     * create draw button
     */
    private void drawButton(){
        
        JButton draw = new JButton("Draw");
        draw.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent arg0) {
                double num=0;
                        double num2 = 0;
                int i=0;

                shape [] arr=fun(contShape.getSelectedItem(),innShape.getSelectedItem());
                int [] array;
                int [] array2;
                Graphics g = panel.getGraphics();
                for (shape anArr : arr) {

                    polygonVect pol = (polygonVect) anArr;
                    array = new int[pol.size()];
                    array2 = new int[pol.size()];
                    for (int j = 0; j < pol.size(); j++) {
                        array[j] = (int) pol.getvec().get(j).getx();
                        array2[j] = (int) pol.getvec().get(j).gety();
                    }
                    if (pol.getname().equals("P")) {
                        g.setColor(Color.RED);
                    } else {
                        g.setColor(Color.GREEN);
                    }
                    num+=arr[i].Perimeter();
                    num2+=arr[i].Area();
                    i++;
                    g.drawPolygon(array, array2, pol.size());
                }
                JOptionPane.showMessageDialog(null,"Container Perimeter / Area  :  " + arr[0].Perimeter()+" / "+arr[0].Area()+"\n"+
                                                "Inner Perimeter / Area  :  " + arr[1].Perimeter()+" / "+arr[0].Area()+"\n" +"Total Perimeter / Area  :  "+
                                                num+" / "+num2, "Information About Shapes", JOptionPane.INFORMATION_MESSAGE);
                panel.paintComponents(g);
            }
        });


        draw.setBounds(475, 543, 75, 23);
        frame.getContentPane().add(draw); // button reference copied
    }
    /**
     * create clear button
     */
    private void clearButton(){

        JButton clear = new JButton("Clear");
        clear.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                Graphics g = panel.getGraphics(); // get brush
                g.setColor(Color.WHITE); // from now on, use white color
                g.fillRect(0, 0, panel.getWidth(), panel.getHeight());
                panel.paintComponents(g);
            }
        });

        clear.setBounds(475, 600, 75, 23);
        frame.getContentPane().add(clear);

    }

}
