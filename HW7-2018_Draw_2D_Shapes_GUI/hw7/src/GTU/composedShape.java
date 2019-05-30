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
public class composedShape implements shape{

    /**
     * parameters of composedshape
     */
    private String name; //polygon icin gerekli name
    private String name1;               //these variables for members type
    private String name2;
    private int size;

    /**
     *  empty array for shape objects
     */
    private shape [] shapes;

    /**
     * add sto array
     * @param s add to array
     */
    private void fill(shape s){
        if(size==0){
            shapes = new shape[1];
            shapes[0]=s;
            size++;
        }else{
            shape [] t;
            t= new shape[size+1];
            System.arraycopy(shapes, 0, t, 0, size);
                t[size]=s;
                shapes=t;
                size++;
        }
    }

    /**
     * @return  shapes array
     */
    public shape[] getarr(){
        return shapes;
    }
    /**
     * fill container with inner
     * @param rec,recsmall fill shape
     */
    public composedShape(rectengal rec, rectengal recsmall) {

        rec.setx_coordinate(0);
        rec.sety_coordinate(0);

        rec.setname("R");

        size=0;
        fill(rec);

        name1="R";
        name2="R";

        optimalFit('R','R',rec.getwidth(),rec.getheight(),recsmall.getwidth(),recsmall.getheight());        //small shapes member assing to vector
    }
    /**
     * fill container with inner
     * @param rec,circ fill shape
     */
    public composedShape(rectengal rec, circle circ){
        rec.setx_coordinate(0);
        rec.sety_coordinate(0);

        rec.setname("R");
        size=0;
        fill(rec);

        name1="R";
        name2="C";

        optimalFit('R','C',rec.getwidth(),rec.getheight(),circ.getradius(),circ.getradius());       //small shapes member assing to vector
    }
    /**
     * fill container with inner
     * @param rec,tria fill shape
     */
    public composedShape(rectengal rec, triangle tria){

        rec.setx_coordinate(0);
        rec.sety_coordinate(0);

        rec.setname("R");
        size=0;
        fill(rec);

        name1="R";
        name2="T";

        optimalFit('R','T',rec.getwidth(),rec.getheight(),tria.getlength(),tria.getlength());      //small shapes member assing to vector
    }
    /**
     * fill container with inner
     * @param circ,rec fill shape
     */
    public composedShape(circle circ, rectengal rec){

        circ.setx_coordinate(0);
        circ.sety_coordinate(0);

        size=0;
        circ.setname("C");
        fill(circ);

        name1="C";
        name2="R";

        optimalFit('C','R',circ.getradius(),circ.getradius(),rec.getwidth(),rec.getheight());      //small shapes member assing to vector
    }
    /**
     * fill container with inner
     * @param circ,circsmall fill shape
     */
    public composedShape(circle circ, circle circsmall){
        circ.setx_coordinate(0);
        circ.sety_coordinate(0);

        size=0;
        circ.setname("C");
        fill(circ);

        name1="C";
        name2="C";

        optimalFit('C','C',circ.getradius(),circ.getradius(),circsmall.getradius(),circsmall.getradius());      //small shapes member assing to vector
    }
    /**
     * fill container with inner
     * @param circ,tria fill shape
     */
    public composedShape(circle circ, triangle tria){
        circ.setx_coordinate(0);
        circ.sety_coordinate(0);

        size=0;
        circ.setname("C");
        fill(circ);

        name1="C";
        name2="T";

        optimalFit('C','T',circ.getradius(),circ.getradius(),tria.getlength(),tria.getlength());      //small shapes member assing to vector

    }
    /**
     * fill container with inner
     * @param tria,rec fill shape
     */
    public composedShape(triangle tria, rectengal rec){
        tria.setx_coordinate(tria.getlength()/2);
        tria.sety_coordinate(0);
        tria.setx_coordinate_2(0);
        tria.sety_coordinate_2((tria.getlength()/2)*Math.sqrt(3));
        tria.setx_coordinate_3(tria.getlength());
        tria.sety_coordinate_3((tria.getlength()/2)*Math.sqrt(3));

        size=0;
        tria.setname("T");
        fill(tria);

        name1="T";
        name2="R";

        optimalFit('T','R',tria.getlength(),tria.getlength(),rec.getwidth(),rec.getheight());      //small shapes member assing to vector

    }
    /**
     * fill container with inner
     * @param tria,circ fill shape
     */
    public composedShape(triangle tria, circle circ){
        tria.setx_coordinate(tria.getlength()/2);
        tria.sety_coordinate(0);
        tria.setx_coordinate_2(0);
        tria.sety_coordinate_2((tria.getlength()/2)*Math.sqrt(3));
        tria.setx_coordinate_3(tria.getlength());
        tria.sety_coordinate_3((tria.getlength()/2)*Math.sqrt(3));

        size=0;
        tria.setname("T");
        fill(tria);

        name1="T";
        name2="C";

        optimalFit('T','C',tria.getlength(),tria.getlength(),circ.getradius(),circ.getradius());
    }
    /**
     * fill container with inner
     * @param tria,triasmall fill shape
     */
    public composedShape(triangle tria, triangle triasmall){
        tria.setx_coordinate(tria.getlength()/2);
        tria.sety_coordinate(0);
        tria.setx_coordinate_2(0);
        tria.sety_coordinate_2((tria.getlength()/2)*Math.sqrt(3));
        tria.setx_coordinate_3(tria.getlength());
        tria.sety_coordinate_3((tria.getlength()/2)*Math.sqrt(3));

        size=0;
        tria.setname("T");
        fill(tria);

        name1="T";
        name2="T";

        optimalFit('T','T',tria.getlength(),tria.getlength(),triasmall.getlength(),triasmall.getlength());
    }
    /**
     * fill shapes array
     * @param name,name2,length1,length2,smallength1,smallength2 for fill shapesa array
     */
    private void optimalFit(char name,char name2,double length1,double length2,double smallength1,double smallength2){
        if(name=='R' && name2=='R'){
            recrec(length1,length2,smallength1,smallength2);
        }else if(name=='R' && name2=='C'){
            reccirc(length1,length2,smallength1);
        }else if(name=='R' && name2=='T'){
            rectria(length1,length2,smallength1);
        }else if(name=='C' && name2=='R'){
            circrect(length1,smallength1,smallength2);
        }else if(name=='C' && name2=='C'){
            circcirc(length1,smallength1);
        }else if(name=='C' && name2=='T'){
            circtri(length1,smallength1);
        }else if(name=='T' && name2=='R'){
            trirect(length1,smallength1,smallength2);
        }else if(name=='T' && name2=='C'){
            tricirc(length1,smallength1);
        }else if(name=='T' && name2=='T'){
            tritri(length1,smallength1);
        }
    }
    /**
     * fill shapes array
     * @param width,height,smallwidth,smallheight for fill shapesa array
     */
    private void recrec(double width,double height,double smallwidth,double smallheight){
        double i,j;

        for(i=0; i<width; i=i+smallwidth)
            for(j=0; j<height; j=j+smallheight){
                if(j+smallheight<=height && i+smallwidth<=width){
                    rectengal ptr=new rectengal(smallwidth,smallheight);
                    ptr.setx_coordinate(i);
                    ptr.sety_coordinate(j);
                    ptr.setname("r");
                    fill(ptr);
                }
            }

    }
    /**
     * fill shapes array
     * @param width,height,length for fill shapesa array
     */
    private void rectria(double width,double height,double length){
        double i,j,p2x,p3x,p3y;

        for(j=0; j<height; j+=(length/2)*Math.sqrt(3))
            for(i=0; i<width; i+=length){
                p3x=i+length;
                p3y=j+length/2*Math.sqrt(3);
                if(p3x<width && p3y<height){
                    triangle temp=new triangle(length);
                    temp.setx_coordinate(i);
                    temp.sety_coordinate(j+length/2*Math.sqrt(3));
                    temp.setx_coordinate_2(i+length/2);
                    temp.sety_coordinate_2(j);
                    temp.setx_coordinate_3(i+length);
                    temp.sety_coordinate_3(j+length/2*Math.sqrt(3));
                    temp.setname("t");
                    fill(temp);

                }
            }
        for(j=0; j<height; j+=(length/2)*Math.sqrt(3))
            for(i=0; i<width; i+=length){
                p2x=i+length/2+length;
                p3y=j+length/2*Math.sqrt(3);
                if(p2x<width && p3y<height){
                    triangle temp=new triangle(length);
                    temp.setx_coordinate(i+length/2);
                    temp.sety_coordinate(j);
                    temp.setx_coordinate_2(i+length/2+length);
                    temp.sety_coordinate_2(j);
                    temp.setx_coordinate_3(i+length);
                    temp.sety_coordinate_3(j+length/2*Math.sqrt(3));
                    temp.setname("t");
                    fill(temp);
                }
            }
    }
    /**
     * fill shapes array
     * @param width,height,radius for fill shapesa array
     */
    private void reccirc(double width,double height,double radius){
        int a,b=0,e=0,num3=0;
        double  i,j;

        double num1=width/(2*radius);
        double num2=height/(2*radius);

        for(i=radius; i<height; i+=(a*radius*Math.sqrt(3))){
            for(j=radius; j<width; j+=2*radius){
                if(e%2==1)
                    if(b%2==1)
                        j+=radius;
                if(j+radius<=width && i+radius<=height)
                    num3++;
                j-=radius;
            }
            b++;
            e++;
            a=1;
        }
        b=e=0;
        if(num1*num2>num3){
            for(i=radius; i<height; i=i+2*radius){
                for(j=radius; j<width; j=j+2*radius)
                    if(j+radius<=width && i+radius<=height){
                        circle temp=new circle(radius);
                        temp.setx_coordinate(i);
                        temp.sety_coordinate(j);
                        temp.setname("c");
                        fill(temp);
                    }
            }
        }else
            for(i=radius; i<height; i+=(a*radius*Math.sqrt(3))){
                for(j=radius; j<width; j+=2*radius){
                    if(e%2==1)
                        if(b%2==1)
                            j+=radius;
                    if(j+radius<=width && i+radius<=height){
                        circle temp=new circle(radius);
                        temp.setx_coordinate(j);
                        temp.sety_coordinate(i);
                        temp.setname("c");
                        fill(temp);
                    }
                    if(b%2==1)
                        j-=radius;
                }
                b++;
                e++;
                a=1;
            }
    }/**
     * fill shapes array
     * @param radius,width,height for fill shapesa array
     */
    private void circrect(double radius, double width, double height){
        double i,j;
        int a=0;
        double point1,point2,point3,point4;

        for(i=0; i<2*radius; i++){
            for(j=0; j<2*radius; j++){
                point1=Math.sqrt(Math.pow((radius-(j)),2)+Math.pow((radius-i),2));
                point2=Math.sqrt(Math.pow((radius-(j+width)),2)+Math.pow((radius-(i+height)),2));
                point3=Math.sqrt(Math.pow((radius-(j)),2)+Math.pow((radius-(i+height)),2));
                point4=Math.sqrt(Math.pow((radius-(j+width)),2)+Math.pow((radius-i),2));
                if(point1<=radius && point2<=radius && point3<=radius && point4<=radius){
                    rectengal temp=new rectengal(width,height);
                    temp.setx_coordinate(j);
                    temp.sety_coordinate(i);
                    temp.setname("r");
                    fill(temp);

                    j+=width;
                    a=1;
                }
            }
            if(a==1){
                a=0;
                i+=height;
            }
        }
    }
    /**
     * fill shapes array
     * @param radius,smallradius for fill shapesa array
     */
    private void circcirc(double radius,double smallradius){
        double i,j;
        int temp3=0,temp2=0;

        for(j=0; j<=radius/smallradius; j++){
            for(i=smallradius; i<2*radius; i+=2*smallradius){
                if(i+smallradius<=2*radius){
                    circle temp=new circle(smallradius);
                    temp.setx_coordinate(i);
                    temp.sety_coordinate(radius);
                    temp.setname("c");
                    fill(temp);

                }
            }
        }
        for(j=radius-(smallradius*Math.sqrt(3)); j>=0; j-=smallradius*Math.sqrt(3)){
            for(i=2*smallradius+temp3*smallradius; i<2*radius; i+=2*smallradius){
                if(Math.sqrt(Math.pow((radius-(i)),2)+Math.pow((radius-j),2))+smallradius<=radius){
                    circle temp=new circle(smallradius);
                    temp.setx_coordinate(i);
                    temp.sety_coordinate(j);
                    temp.setname("c");
                    fill(temp);

                }
            }
            if(temp2%2==0)
                temp3=1;
            else
                temp3=0;
            temp2++;
        }
        temp3=temp2=0;
        for(j=radius+(smallradius*Math.sqrt(3)); j<=2*radius; j+=smallradius*Math.sqrt(3)){
            for(i=2*smallradius+temp3*smallradius; i<2*radius; i+=2*smallradius){
                if(Math.sqrt(Math.pow((radius-(i)),2)+Math.pow((radius-j),2))+smallradius<=radius){
                    circle temp=new circle(smallradius);
                    temp.setx_coordinate(i);
                    temp.sety_coordinate(j);
                    temp.setname("c");
                    fill(temp);
                }
            }
            if(temp2%2==0)
                temp3=1;
            else
                temp3=0;
            temp2++;
        }
    }
    /**
     * fill shapes array
     * @param radius,length for fill shapesa array
     */
    private void circtri(double radius, double length){
        double p1x,p1y,p2x,p2y,p3x,p3y;
        double i,j;
        int temp2=0;

        for(j=radius; j>0; j-=length/2*Math.sqrt(3)){
            for(i=0; i<2*radius; i+=length){
                p1x=i;
                p1y=j;
                p2x=i+length;
                p2y=j;
                p3x=i+length/2;
                p3y=j-length/2*Math.sqrt(3);
                if((Math.sqrt(Math.pow((radius-(p1x)),2)+Math.pow((radius-p1y),2))<=radius) && (Math.sqrt(Math.pow((radius-(p2x)),2)+Math.pow((radius-p2y),2))<=radius) && (Math.sqrt(Math.pow((radius-(p3x)),2)+Math.pow((radius-p3y),2))<=radius)){
                    triangle temp=new triangle(length);
                    temp.setx_coordinate(p1x);
                    temp.sety_coordinate(p1y);
                    temp.setx_coordinate_2(p2x);
                    temp.sety_coordinate_2(p2y);
                    temp.setx_coordinate_3(p3x);
                    temp.sety_coordinate_3(p3y);
                    temp.setname("t");
                    fill(temp);


                    triangle temp3=new triangle(length);
                    temp3.setx_coordinate(p1x);
                    temp3.sety_coordinate(p1y+temp2*length/2*Math.sqrt(3));
                    temp3.setx_coordinate_2(p2x);
                    temp3.sety_coordinate_2(p2y+temp2*length/2*Math.sqrt(3));
                    temp3.setx_coordinate_3(p3x);
                    temp3.sety_coordinate_3(p3y+2*(length/2*Math.sqrt(3))+(temp2*length/2*Math.sqrt(3)));
                    temp3.setname("t");
                    fill(temp3);


                }
            }
            temp2+=2;
        }temp2=0;
        for(j=radius; j>0; j-=length/2*Math.sqrt(3)){
            for(i=length; i<2*radius; i+=length){
                p1x=i;
                p1y=j;
                p2x=i-length/2;
                p2y=j-length/2*Math.sqrt(3);
                p3x=i+length/2;
                p3y=j-length/2*Math.sqrt(3);
                if((Math.sqrt(Math.pow((radius-(p1x)),2)+Math.pow((radius-p1y),2))<=radius) && (Math.sqrt(Math.pow((radius-(p2x)),2)+Math.pow((radius-p2y),2))<=radius) && (Math.sqrt(Math.pow((radius-(p3x)),2)+Math.pow((radius-p3y),2))<=radius)){
                    triangle temp=new triangle(length);
                    temp.setx_coordinate(p1x);
                    temp.sety_coordinate(p1y);
                    temp.setx_coordinate_2(p2x);
                    temp.sety_coordinate_2(p2y);
                    temp.setx_coordinate_3(p3x);
                    temp.sety_coordinate_3(p3y);
                    temp.setname("t");
                    fill(temp);


                    triangle temp3=new triangle(length);
                    temp3.setx_coordinate(p1x);
                    temp3.sety_coordinate(p1y+temp2*length/2*Math.sqrt(3));
                    temp3.setx_coordinate_2(p2x);
                    temp3.sety_coordinate_2(p2y+2*(length/2*Math.sqrt(3))+temp2*length/2*Math.sqrt(3));
                    temp3.setx_coordinate_3(p3x);
                    temp3.sety_coordinate_3(p3y+2*(length/2*Math.sqrt(3))+(temp2*length/2*Math.sqrt(3)));
                    temp3.setname("t");
                    fill(temp3);

                }
            }
            temp2+=2;
        }
    }
    /**
     * fill shapes array
     * @param length,width,height for fill shapesa array
     */
    private void trirect(double length, double width, double height){
        double i,j;
        int a=1;
        double b;

        b=(height/Math.sqrt(3))+1;

        for(j=((length/2)*Math.sqrt(3)-height); j>=0; j-=height){
            for(i=b; i<=length-a*(height/Math.sqrt(3)); i+=width){
                if(i+width<=length-a*(height/Math.sqrt(3))){
                    rectengal temp=new rectengal(width,height);
                    temp.setx_coordinate(i);
                    temp.sety_coordinate(j);
                    temp.setname("r");
                    fill(temp);

                }
            }
            a++;
            b=height*a/Math.sqrt(3)+1;
        }
    }
    /**
     * fill shapes array
     * @param length,radius for fill shapesa array
     */
    private void tricirc(double length, double radius){
        double i,j;
        double num=2*(length*Math.sqrt(3)/2)/(3*radius);
        double x=length/2, y=2*radius;

        for(j=0; j<num; ++j){
            for(i=0; i<j+1; ++i){
                if(y+radius<=length*Math.sqrt(3)/2){
                    circle temp=new circle(radius);
                    temp.setx_coordinate(x);
                    temp.sety_coordinate(y);
                    temp.setname("c");
                    fill(temp);

                }
                x+=(radius*2);
            }
            x=length/2;
            x-=((j+1)*radius);
            y+=(radius*Math.sqrt(3));
        }
    }
    /**
     * fill shapes array
     * @param length,smallength for fill shapesa array
     */
    private void tritri(double length, double smallength){
        double p3x,p3y,temp2=0;
        double  i,j;

        for(j=length/2*Math.sqrt(3); j>=0; j-=(smallength/2)*Math.sqrt(3)){
            for(i=temp2; i<length-temp2; i+=smallength){
                p3x=i+smallength;
                p3y=j;
                if(p3x<=length-temp2 && p3y>0){
                    triangle temp=new triangle(smallength);
                    temp.setx_coordinate(i);
                    temp.sety_coordinate(j);
                    temp.setx_coordinate_2(i+smallength/2);
                    temp.sety_coordinate_2(j-smallength/2*Math.sqrt(3));
                    temp.setx_coordinate_3(i+smallength);
                    temp.sety_coordinate_3(j);
                    temp.setname("t");
                    fill(temp);

                }
            }
            temp2+=smallength/2;
        }
        temp2=smallength/2;
        for(j=length/2*Math.sqrt(3); j>=0; j-=(smallength/2)*Math.sqrt(3)){
            for(i=temp2; i<length-temp2; i+=smallength){
                p3x=i+smallength;
                p3y=j-smallength/2*Math.sqrt(3);
                if(p3x<=length-temp2 && p3y>0){
                    triangle temp=new triangle(smallength);
                    temp.setx_coordinate(i+smallength/2);
                    temp.sety_coordinate(j);
                    temp.setx_coordinate_2(i);
                    temp.sety_coordinate_2(j-smallength/2*Math.sqrt(3));
                    temp.setx_coordinate_3(i+smallength);
                    temp.sety_coordinate_3(j-smallength/2*Math.sqrt(3));
                    temp.setname("t");
                    fill(temp);

                }
            }
            temp2+=smallength/2;
        }

    }

    /**   draw Shape
     * @param g Graphics object
     */
    @Override
    public void draw(Graphics g){
        Polygon p = new Polygon();

        p.addPoint(225, 300);

        if(this.getname().equals("P")) {
            g.setColor(Color.RED);
        }else
            g.setColor(Color.GREEN);
        g.fillPolygon(p);
    }
    /**
     * compare shape with respect to their areas.
     * @param other object of shape
     */
    @Override
    public int compareTo(shape other){
        return Integer.compare((int)this.Area(),(int)other.Area());

    }
    /**
     * @return name of Shape
     */
    @Override
    public String getname(){
        return name;
    }

    /**
     * @return Area of shape
     */
    @Override
    public double Area(){
        return shapes[0].Area();
    }
    /**
     * @return perimeter of shape
     */
    @Override
    public double Perimeter(){
        return shapes[0].Perimeter();
    }
    /**   decrease coordinate
     */
    @Override
    public void increment(){
        for(int i=0; i<size; i++){
            shapes[i].increment();
        }
    }
    /**   decrease coordinate
     */
    @Override
    public void decremenet(){
        for(int i=0; i<size; i++){
            shapes[i].decremenet();
        }
    }
}
