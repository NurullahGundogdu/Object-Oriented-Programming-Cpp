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

public interface queue<E> extends Collection <E> {
    Iterator<E> iterator();
    void add(E e);
    void addAll(Collection<E> c);
    void clear();                 //pure functions
    boolean contains(E e);
    boolean containsAll(Collection<E> c);
    boolean isEmpty();
    void remove(E e);
    void removeAll(Collection<E> c);
    void retainAll(Collection<E> c);
    int size();
    E ARRAY(int i);
    void Add(E e);
    E element();
    void offer(E e);
    E poll();


}
