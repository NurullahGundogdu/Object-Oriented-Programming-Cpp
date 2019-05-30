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

public class arrayList<E> implements List<E>  {
    /**
     * empty array instance used for list element
     */
    private Object[] base;
    /**
     * The size of the arrayList (the number of elements it contains).
     */
    private int size;

    /**
     * iterator method create Iterator class type object
     * @return object
     */
    @Override
    public Iterator<E> iterator(){

        return new Iterator<>(this, 0);
    }

    /**
     * add method adds an element to list
     * @param e element for list
     */
    @Override
    public void add(E e){
        if(size==0) {
            base = new Object[1];
            base[0]=e;
        }else{
            int i;
            Object temp[];  // declare array variable
            temp = new Object[size + 1];
            for(i=0; i<size; i++)
                temp[i]=base[i];
            temp[i]=e;
            base=temp;
        }
        size++;

    }

    /**
     * addAll method adds a list elements to list
     * @param c object for addAll method
     */
    @Override
    public void addAll(Collection<E> c){
        Iterator<E> iter=c.iterator();
        while(iter.hasNext())
            this.add(iter.next());

    }
    /**
     * clear method for delete list elements
     */
    @Override
    public void clear(){
        Object temp[];  // declare array variable
        temp = new Object[1];
        this.base=temp;
        this.size=0;
    }
    /**
     * contains method checks if the element is in the list
     * @param e element for the checking
     * @return true if this collection contains the specified element
     */
    @Override
    public boolean contains(E e){
        for(int i = 0; i < size; i++){
            if(base[i] == e)        //if elements in list return true
                return true;
        }
        return false;
    }
    /**
     * containsAll method checks if the list elements is in the list
     * @param c object for containsAll method
     * @return true if this collection contains all of the elements in the specified collection.
     */
    @Override
    public boolean containsAll(Collection<E> c){
        if(size ==0 || c.size()==0)
            return false;
        Iterator<E> iter=c.iterator();
        while(iter.hasNext()){
            if (!(this.contains(iter.next()))) {           //if list in list return true
                return false;
            }
        }

        return true;
    }
    /**
     * isEmpty method checks if the list empty
     * @return true if this list empty
     */
    @Override
    public boolean isEmpty(){

        //if list is empty return true
        return size() == 0;
    }
    /**
     * remove method  Removes a single instance of the specified element from this
     * collection, if it is present
     * @param e element for remove
     */
    @Override
    public void remove(E e) {
        int k=0;
        if(this.contains(e)){
            Object temp[];  // declare array variable
            temp = new Object[size-1];
            for(int i = 0; i <size; i++){
                if(base[i] != e){           //if elements in list remove the elements from list
                    temp[k] = base[i];
                    k++;
                }
            }
            size--;
            base=temp;
        }
    }
    /**
     * removeAll method  Removes all of this collection's elements that are also contained
     * in the specified collection
     * @param c object for remove
     */
    @Override
    public void removeAll(Collection<E> c){

        Iterator<E> iter=c.iterator();
        while(iter.hasNext()) {
            E num= iter.next();
            if (this.contains(num)) {
                this.remove(num);

            }
        }
    }
    /**
     * retainAll method  Retains only the elements in this collection that are contained in
     * the specified collection
     * @param c object for retain
     */
    @Override
    public void retainAll(Collection<E> c){

        int num=0;
        for(int i = 0; i < this.size; i++){
            Iterator<E> iter=c.iterator();
            while(iter.hasNext()) {
                if (base[i] ==iter.next()) {       //Retains only the elements in this collection that are contained in the specified collection
                    num = 1;
                }
            }
            if(num==0){                             //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!buna bak!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                this.remove((E) base[i]);
                i--;
            }
            num=0;
        }
    }
    /**
     * size method Returns the number of elements in this collection.
     * @return size of the list
     */
    @Override
    public int size(){

        return size;
    }
    /**
     * ARRAY method Returns list element
     * @param i index of array
     * @return e elements of list
     */
    @Override
    public E ARRAY(int i){

        return (E) base[i];
    }

}
