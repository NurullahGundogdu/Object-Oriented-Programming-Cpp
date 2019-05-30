/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package homework8;
/**
 * @author Nurullah GUNDOGDU
 * since 2019-1-16
 */

class Iterator <E>{
    /**
     * empty array instance used for list element
     */
    private Collection <E> obje;
    /**
     * index of the list
     */
    private int index;
    /**
     * constructur
     */
    Iterator(Collection <E> arr, int ind){
        obje = arr;
        this.index = ind;
    }
    /**
     * hasNext method Returns true if the iteration has more elements.
     * @return true if the iteration has more elements.
     */
    boolean hasNext(){

        return (index < obje.size());
    }
    /**
     * next method Returns the next element in the iteration and advances the iterator.
     * @return e elements of list
     */
    E next(){
        if (!hasNext()) {
            throw new IllegalAccessError("error: no next element");
        }

        E ret = obje.ARRAY(index);
        index++;
        return ret;
    }
    /**
     * remove method remove list first element from list
     */
    void remove(){
        E ret = obje.ARRAY(index);
        obje.remove(ret);
    }

}
