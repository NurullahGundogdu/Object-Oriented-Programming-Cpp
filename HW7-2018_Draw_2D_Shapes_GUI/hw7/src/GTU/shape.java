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
import java.awt.Graphics;
public interface shape extends Comparable{
    double Area();
    double Perimeter();
    void increment();
    void decremenet();
    void draw(Graphics g);
    String getname();
    int compareTo(shape other);

}
