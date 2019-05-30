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

public class Homework8 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        link_list_int();
        link_list_string();
        array_list_int();
        array_list_string();
        hash_set_int();
        hash_set_string();

    }

    /**
     * link_list_int method is to test the linklist for int
     */
    private static void link_list_int(){
        System.out.println("**************************************");
        System.out.println("**********LinkedList integer**********");
        System.out.println("**************************************");
        linkList<Integer> linkLstTest = new linkList<>();
        try {
            System.out.println("Elements add to linkLstTest");
            linkLstTest.add(1);
            linkLstTest.add(1);
            linkLstTest.add(3);
            linkLstTest.add(4);
            linkLstTest.add(5);
        } catch (Exception ex) {
            System.out.println("TEST ERROR");
            throw ex;
        }

        Iterator iter=linkLstTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of linkLstTest : " + linkLstTest.size());

        System.out.println("Elements add to linkLstTest2");
        linkList<Integer> linkLstTest2 = new linkList<>();
        linkLstTest2.add(34);
        linkLstTest2.add(6);
        linkLstTest2.add(7);
        linkLstTest2.add(8);

        Iterator iter2=linkLstTest2.iterator();
        while(iter2.hasNext())
            System.out.print(iter2.next()+" ");

        System.out.println();
        System.out.println("Size of linkLstTest2 : " + linkLstTest2.size());

        System.out.println("linkLstTest2 elements add to linkLstTest");
        linkLstTest.addAll(linkLstTest2);

        iter=linkLstTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of linkLstTest : " + linkLstTest.size());


        System.out.println("Remove element '3' from linkLstTest");
        linkLstTest.remove(3);
        iter=linkLstTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of linkLstTest : " + linkLstTest.size());


        System.out.println("Remove linkLstTest2 elements from linkLstTest");
        linkLstTest.removeAll(linkLstTest2);

        iter=linkLstTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of linkLstTest : " + linkLstTest.size());

        System.out.println("Clear linkLstTest2");
        linkLstTest2.clear();
        System.out.println("Size of linkLstTest2 : " + linkLstTest2.size());

        System.out.println("Elements add to linkLstTest3");
        linkList<Integer> linkLstTest3 = new linkList<>();
        linkLstTest3.add(11);
        linkLstTest3.add(16);
        linkLstTest3.add(17);
        linkLstTest3.add(18);
        linkLstTest3.add(20);
        linkLstTest3.add(55);
        linkLstTest3.add(889);

        Iterator iter3=linkLstTest3.iterator();
        while(iter3.hasNext())
            System.out.print(iter3.next()+" ");

        System.out.println();
        System.out.println("Size of linkLstTest3 : " + linkLstTest3.size());

        System.out.println("Elements add to linkLstTest4");
        linkList<Integer> linkLstTest4 = new linkList<>();
        linkLstTest4.add(11);
        linkLstTest4.add(16);

        Iterator iter4=linkLstTest4.iterator();
        while(iter4.hasNext())
            System.out.print(iter4.next()+" ");

        System.out.println();
        System.out.println("Size of linkLstTest4 : " + linkLstTest4.size());

        System.out.print("Contains function for element '18' in linkLstTest3 = ");
        if(linkLstTest3.contains(18))
            System.out.println("true");
        else
            System.out.println("false");

        System.out.print("Contains function for element '0' in linkLstTest3 = ");
        if(linkLstTest3.contains(0))
            System.out.println("true");
        else
            System.out.println("false");

        System.out.print("ContainsAll function for linkLstTest4 elements in linkLstTest3 = ");
        if(linkLstTest3.containsAll(linkLstTest4))
            System.out.println("true");
        else
            System.out.println("false");

        System.out.println("RetainAll function for linkLstTest3 between linkLstTest4");
        System.out.println("linkLstTest3 elements : ");
        linkLstTest3.retainAll(linkLstTest4);
        iter3=linkLstTest3.iterator();
        while(iter3.hasNext())
            System.out.print(iter3.next()+" ");

        System.out.println();
        System.out.println("Size of linkLstTest3 : " + linkLstTest3.size());

        System.out.print("linkLstTest3 is empty = ");
        if(linkLstTest3.isEmpty())
            System.out.println("true");
        else
            System.out.println("false");

        System.out.println("Add element linkLstTest3 using offer function.");
        linkLstTest3.offer(45);
        linkLstTest3.offer(71);

        iter3=linkLstTest3.iterator();
        while(iter3.hasNext())
            System.out.print(iter3.next()+" ");
        System.out.println();

        System.out.println("First element of linkLstTest3 (using element function) : "+ linkLstTest3.element());

        System.out.println("First element of linkLstTest3 (using poll function) : "+ linkLstTest3.poll());

        System.out.println("After poll function first element of linkLstTest3 remove from list.");
        iter3=linkLstTest3.iterator();
        while(iter3.hasNext())
            System.out.print(iter3.next()+" ");
        System.out.println();

        iter3=linkLstTest3.iterator();
        iter3.remove();

    }

    /**
     * link_list_string method is to test the linklist for string
     */
    private static void link_list_string(){
        System.out.println("**************************************");
        System.out.println("**********LinkedList String***********");
        System.out.println("**************************************");
        linkList<String> linkLstTest = new linkList<>();

        try {
            System.out.println("Elements add to linkLstTest");
            linkLstTest.add("e");
            linkLstTest.add("m");
            linkLstTest.add("r");
            linkLstTest.add("e");
            linkLstTest.add("a");
        } catch (Exception ex) {
            System.out.println("TEST ERROR");
            throw ex;
        }

        Iterator iter=linkLstTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of linkLstTest : " + linkLstTest.size());

        System.out.println("Elements add to linkLstTest2");
        linkList<String> linkLstTest2 = new linkList<>();
        linkLstTest2.add("ooo");
        linkLstTest2.add("t");
        linkLstTest2.add("k");
        linkLstTest2.add("l");

        Iterator iter2=linkLstTest2.iterator();
        while(iter2.hasNext())
            System.out.print(iter2.next()+" ");

        System.out.println();
        System.out.println("Size of linkLstTest2 : " + linkLstTest2.size());

        System.out.println("linkLstTest2 elements add to linkLstTest");
        linkLstTest.addAll(linkLstTest2);

        iter=linkLstTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of linkLstTest : " + linkLstTest.size());


        System.out.println("Remove element 'r' from linkLstTest");
        linkLstTest.remove("r");
        iter=linkLstTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of linkLstTest : " + linkLstTest.size());


        System.out.println("Remove linkLstTest2 elements from linkLstTest");
        linkLstTest.removeAll(linkLstTest2);

        iter=linkLstTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of linkLstTest : " + linkLstTest.size());

        System.out.println("Clear linkLstTest2");
        linkLstTest2.clear();
        System.out.println("Size of linkLstTest2 : " + linkLstTest2.size());

        System.out.println("Elements add to linkLstTest3");
        linkList<String> linkLstTest3 = new linkList<>();
        linkLstTest3.add("h");
        linkLstTest3.add("x");
        linkLstTest3.add("e");
        linkLstTest3.add("s");

        Iterator iter3=linkLstTest3.iterator();
        while(iter3.hasNext())
            System.out.print(iter3.next()+" ");

        System.out.println();
        System.out.println("Size of linkLstTest3 : " + linkLstTest3.size());

        System.out.println("Elements add to linkLstTest4");
        linkList<String> linkLstTest4 = new linkList<>();
        linkLstTest4.add("h");
        linkLstTest4.add("x");

        Iterator iter4=linkLstTest4.iterator();
        while(iter4.hasNext())
            System.out.print(iter4.next()+" ");

        System.out.println();
        System.out.println("Size of linkLstTest4 : " + linkLstTest4.size());

        System.out.print("Contains function for element 'z' in linkLstTest3 = ");
        if(linkLstTest3.contains("z"))
            System.out.println("true");
        else
            System.out.println("false");

        System.out.print("Contains function for element 'x' in linkLstTest3 = ");
        if(linkLstTest3.contains("x"))
            System.out.println("true");
        else
            System.out.println("false");

        System.out.print("ContainsAll function for linkLstTest4 elements in linkLstTest3 = ");
        if(linkLstTest3.containsAll(linkLstTest4))
            System.out.println("true");
        else
            System.out.println("false");

        System.out.println("RetainAll function for linkLstTest3 between linkLstTest4");
        linkLstTest3.retainAll(linkLstTest4);
        iter3=linkLstTest3.iterator();
        while(iter3.hasNext())
            System.out.print(iter3.next()+" ");

        System.out.println();
        System.out.println("Size of linkLstTest3 : " + linkLstTest3.size());

        System.out.print("linkLstTest3 is empty = ");
        if(linkLstTest3.isEmpty())
            System.out.println("true");
        else
            System.out.println("false");
        System.out.println("Add element linkLstTest3 using offer function.");
        linkLstTest3.offer("GTU");
        linkLstTest3.offer("BM");

        iter3=linkLstTest3.iterator();
        while(iter3.hasNext())
            System.out.print(iter3.next()+" ");
        System.out.println();

        System.out.println("First element of linkLstTest3 (using element function) : "+ linkLstTest3.element());

        System.out.println("First element of linkLstTest3 (using poll function) : "+ linkLstTest3.poll());

        System.out.println("After poll function first element of linkLstTest3 remove from list.");
        iter3=linkLstTest3.iterator();
        while(iter3.hasNext())
            System.out.print(iter3.next()+" ");
        System.out.println();

        iter3=linkLstTest3.iterator();
        iter3.remove();
    }
    /**
     * array_list_int method is to test the linklist for int
     */
    private static void array_list_int(){
        System.out.println("**************************************");
        System.out.println("**********ArrayList integer***********");
        System.out.println("**************************************");
        arrayList<Integer> arrayLstTest = new arrayList<>();
        try {
            System.out.println("Elements add to arrayLstTest");
            arrayLstTest.add(14);
            arrayLstTest.add(14);
            arrayLstTest.add(33);
            arrayLstTest.add(4956);
            arrayLstTest.add(543);
        } catch (Exception ex) {
            System.out.println("TEST ERROR");
            throw ex;
        }

        Iterator iter=arrayLstTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of arrayLstTest : " + arrayLstTest.size());

        System.out.println("Elements add to arrayLstTest2");
        arrayList<Integer> arrayLstTest2 = new arrayList<>();
        arrayLstTest2.add(114);
        arrayLstTest2.add(67);
        arrayLstTest2.add(789);
        arrayLstTest2.add(811);

        Iterator iter2=arrayLstTest2.iterator();
        while(iter2.hasNext())
            System.out.print(iter2.next()+" ");

        System.out.println();
        System.out.println("Size of arrayLstTest2 : " + arrayLstTest2.size());

        System.out.println("arrayLstTest2 elements add to arrayLstTest");
        arrayLstTest.addAll(arrayLstTest2);

        iter=arrayLstTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of arrayLstTest : " + arrayLstTest.size());


        System.out.println("Remove element '33' from arrayLstTest");
        arrayLstTest.remove(33);
        iter=arrayLstTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of arrayLstTest : " + arrayLstTest.size());


        System.out.println("Remove arrayLstTest2 elements from arrayLstTest");
        arrayLstTest.removeAll(arrayLstTest2);

        iter=arrayLstTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of arrayLstTest : " + arrayLstTest.size());

        System.out.println("Clear arrayLstTest2");
        arrayLstTest2.clear();
        System.out.println("Size of arrayLstTest2 : " + arrayLstTest2.size());

        System.out.println("Elements add to arrayLstTest3");
        arrayList<Integer> arrayLstTest3 = new arrayList<>();
        arrayLstTest3.add(11);
        arrayLstTest3.add(16);
        arrayLstTest3.add(17);
        arrayLstTest3.add(18);
        arrayLstTest3.add(200);
        arrayLstTest3.add(55);
        arrayLstTest3.add(889);

        Iterator iter3=arrayLstTest3.iterator();
        while(iter3.hasNext())
            System.out.print(iter3.next()+" ");

        System.out.println();
        System.out.println("Size of arrayLstTest3 : " + arrayLstTest3.size());

        System.out.println("Elements add to arrayLstTest4");
        arrayList<Integer> arrayLstTest4 = new arrayList<>();
        arrayLstTest4.add(11);
        arrayLstTest4.add(16);

        Iterator iter4=arrayLstTest4.iterator();
        while(iter4.hasNext())
            System.out.print(iter4.next()+" ");

        System.out.println();
        System.out.println("Size of arrayLstTest4 : " + arrayLstTest4.size());

        System.out.print("Contains function for element '18' in arrayLstTest3 = ");
        if(arrayLstTest3.contains(18))
            System.out.println("true");
        else
            System.out.println("false");

        System.out.print("Contains function for element '1000' in arrayLstTest3 = ");
        if(arrayLstTest3.contains(1000))
            System.out.println("true");
        else
            System.out.println("false");

        System.out.print("ContainsAll function for arrayLstTest4 elements in arrayLstTest3 = ");
        if(arrayLstTest3.containsAll(arrayLstTest4))
            System.out.println("true");
        else
            System.out.println("false");


        System.out.println("RetainAll function for arrayLstTest3 between arrayLstTest4");
        arrayLstTest3.retainAll(arrayLstTest4);

        System.out.print("arrayLstTest3 elements : ");
        iter3=arrayLstTest3.iterator();
        while(iter3.hasNext())
            System.out.print(iter3.next()+" ");

        System.out.println();
        System.out.println("Size of arrayLstTest3 : " + arrayLstTest3.size());

        System.out.print("arrayLstTest3 is empty = ");
        if(arrayLstTest3.isEmpty())
            System.out.println("true");
        else
            System.out.println("false");

        iter3=arrayLstTest3.iterator();
        iter3.remove();
    }

    /**
     * array_list_string method is to test the linklist for string
     */
    private static void array_list_string(){
        System.out.println("**************************************");
        System.out.println("**********ArrayList String************");
        System.out.println("**************************************");

        arrayList<String> arrayLstTest = new arrayList<>();

        try {
            System.out.println("Elements add to arrayLstTest");
            arrayLstTest.add("murat");
            arrayLstTest.add("emre");
            arrayLstTest.add("nurullah");
            arrayLstTest.add("samet");
            arrayLstTest.add("fali");
        } catch (Exception ex) {
            System.out.println("TEST ERROR");
            throw ex;
        }

        Iterator iter=arrayLstTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of arrayLstTest : " + arrayLstTest.size());

        System.out.println("Elements add to arrayLstTest2");
        arrayList<String> arrayLstTest2 = new arrayList<>();
        arrayLstTest2.add("izmir");
        arrayLstTest2.add("denizli");
        arrayLstTest2.add("edirne");
        arrayLstTest2.add("ankara");

        Iterator iter2=arrayLstTest2.iterator();
        while(iter2.hasNext())
            System.out.print(iter2.next()+" ");

        System.out.println();
        System.out.println("Size of arrayLstTest2 : " + arrayLstTest2.size());

        System.out.println("arrayLstTest2 elements add to arrayLstTest");
        arrayLstTest.addAll(arrayLstTest2);

        iter=arrayLstTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of arrayLstTest : " + arrayLstTest.size());


        System.out.println("Remove element 'murat' from arrayLstTest");
        arrayLstTest.remove("murat");
        iter=arrayLstTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of arrayLstTest : " + arrayLstTest.size());


        System.out.println("Remove arrayLstTest2 elements from arrayLstTest");
        arrayLstTest.removeAll(arrayLstTest2);

        iter=arrayLstTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of arrayLstTest : " + arrayLstTest.size());

        System.out.println("Clear arrayLstTest2");
        arrayLstTest2.clear();
        System.out.println("Size of arrayLstTest2 : " + arrayLstTest2.size());

        System.out.println("Elements add to arrayLstTest3");
        arrayList<String> arrayLstTest3 = new arrayList<>();
        arrayLstTest3.add("i");
        arrayLstTest3.add("p");
        arrayLstTest3.add("e");
        arrayLstTest3.add("k");

        Iterator iter3=arrayLstTest3.iterator();
        while(iter3.hasNext())
            System.out.print(iter3.next()+" ");

        System.out.println();
        System.out.println("Size of arrayLstTest3 : " + arrayLstTest3.size());

        System.out.println("Elements add to arrayLstTest4");
        arrayList<String> arrayLstTest4 = new arrayList<>();
        arrayLstTest4.add("p");
        arrayLstTest4.add("k");

        Iterator iter4=arrayLstTest4.iterator();
        while(iter4.hasNext())
            System.out.print(iter4.next()+" ");

        System.out.println();
        System.out.println("Size of arrayLstTest4 : " + arrayLstTest4.size());

        System.out.print("Contains function for element 'k' in arrayLstTest3 = ");
        if(arrayLstTest3.contains("k"))
            System.out.println("true");
        else
            System.out.println("false");

        System.out.print("Contains function for element 'x' in arrayLstTest3 = ");
        if(arrayLstTest3.contains("x"))
            System.out.println("true");
        else
            System.out.println("false");

        System.out.print("ContainsAll function for arrayLstTest4 elements in arrayLstTest3 = ");
        if(arrayLstTest3.containsAll(arrayLstTest4))
            System.out.println("true");
        else
            System.out.println("false");

        System.out.println("RetainAll function for arrayLstTest3 between arrayLstTest4");
        arrayLstTest3.retainAll(arrayLstTest4);

        System.out.print("arrayLstTest3 elements : ");
        iter3=arrayLstTest3.iterator();
        while(iter3.hasNext())
            System.out.print(iter3.next()+" ");

        System.out.println();
        System.out.println("Size of arrayLstTest3 : " + arrayLstTest3.size());

        System.out.print("arrayLstTest3 is empty = ");
        if(arrayLstTest3.isEmpty())
            System.out.println("true");
        else
            System.out.println("false");

        iter3=arrayLstTest3.iterator();
        iter3.remove();

    }
    /**
     * hash_set_int method is to test the linklist for int
     */
    private static void hash_set_int(){
        System.out.println("**************************************");
        System.out.println("***********HashSet integer************");
        System.out.println("**************************************");

        hashset<Integer> setTest = new hashset<>();
        try {
            System.out.println("Elements add to setTest");
            setTest.add(11);
            setTest.add(11);
            setTest.add(33);
            setTest.add(44);
            setTest.add(55);
        } catch (Exception ex) {
            System.out.println("TEST ERROR");
            throw ex;
        }

        Iterator iter=setTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of setTest : " + setTest.size());

        System.out.println("Elements add to setTest2");
        hashset<Integer> setTest2 = new hashset<>();
        setTest2.add(666);
        setTest2.add(777);
        setTest2.add(888);
        setTest2.add(999);

        Iterator iter2=setTest2.iterator();
        while(iter2.hasNext())
            System.out.print(iter2.next()+" ");

        System.out.println();
        System.out.println("Size of setTest2 : " + setTest2.size());

        System.out.println("setTest2 elements add to setTest");
        setTest.addAll(setTest2);

        iter=setTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of setTest : " + setTest.size());


        System.out.println("Remove element '33' from setTest");
        setTest.remove(33);
        iter=setTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of setTest : " + setTest.size());


        System.out.println("Remove setTest2 elements from setTest");
        setTest.removeAll(setTest2);

        iter=setTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of setTest : " + setTest.size());

        System.out.println("Clear setTest2");
        setTest2.clear();
        System.out.println("Size of setTest2 : " + setTest2.size());

        System.out.println("Elements add to setTest3");
        hashset<Integer> setTest3 = new hashset<>();
        setTest3.add(11);
        setTest3.add(16);
        setTest3.add(17);
        setTest3.add(18);
        setTest3.add(55);
        setTest3.add(200);
        setTest3.add(889);

        Iterator iter3=setTest3.iterator();
        while(iter3.hasNext())
            System.out.print(iter3.next()+" ");

        System.out.println();
        System.out.println("Size of setTest3 : " + setTest3.size());

        System.out.println("Elements add to setTest4");
        hashset<Integer> setTest4 = new hashset<>();
        setTest4.add(11);
        setTest4.add(16);

        Iterator iter4=setTest4.iterator();
        while(iter4.hasNext())
            System.out.print(iter4.next()+" ");

        System.out.println();
        System.out.println("Size of setTest4 : " + setTest4.size());

        System.out.print("Contains function for element '18' in setTest3 = ");
        if(setTest3.contains(18))
            System.out.println("true");
        else
            System.out.println("false");

        System.out.print("Contains function for element '45642' in setTest3 = ");
        if(setTest3.contains(45642))
            System.out.println("true");
        else
            System.out.println("false");

        System.out.print("ContainsAll function for setTest4 elements in setTest3 = ");
        if(setTest3.containsAll(setTest4))
            System.out.println("true");
        else
            System.out.println("false");


        System.out.println("RetainAll function for setTest3 between setTest4");
        setTest3.retainAll(setTest4);

        System.out.print("setTest3 elements : ");
        iter3=setTest3.iterator();
        while(iter3.hasNext())
            System.out.print(iter3.next()+" ");

        System.out.println();
        System.out.println("Size of setTest3 : " + setTest3.size());

        System.out.print("setTest3 is empty = ");
        if(setTest3.isEmpty())
            System.out.println("true");
        else
            System.out.println("false");

        iter3=setTest3.iterator();
        iter3.remove();
    }

    /**
     * hash_set_string method is to test the linklist for string
     */
    private static void hash_set_string(){
        System.out.println("**************************************");
        System.out.println("***********HashSet String*************");
        System.out.println("**************************************");

        hashset<String> setTest = new hashset<>();

        try {
            System.out.println("Elements add to setTest");
            setTest.add("e");
            setTest.add("m");
            setTest.add("r");
            setTest.add("e");
            setTest.add("u");
        } catch (Exception ex) {
            System.out.println("TEST ERROR");
            throw ex;
        }
        Iterator iter=setTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of setTest : " + setTest.size());

        System.out.println("Elements add to setTest2");
        hashset<String> setTest2 = new hashset<>();
        setTest2.add("s");
        setTest2.add("t");
        setTest2.add("v");
        setTest2.add("z");

        Iterator iter2=setTest2.iterator();
        while(iter2.hasNext())
            System.out.print(iter2.next()+" ");

        System.out.println();
        System.out.println("Size of setTest2 : " + setTest2.size());

        System.out.println("setTest2 elements add to setTest");
        setTest.addAll(setTest2);

        iter=setTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of setTest : " + setTest.size());


        System.out.println("Remove element 'e' from setTest");
        setTest.remove("e");
        iter=setTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of setTest : " + setTest.size());


        System.out.println("Remove setTest2 elements from setTest");
        setTest.removeAll(setTest2);

        iter=setTest.iterator();
        while(iter.hasNext())
            System.out.print(iter.next()+" ");

        System.out.println();
        System.out.println("Size of setTest : " + setTest.size());

        System.out.println("Clear setTest2");
        setTest2.clear();
        System.out.println("Size of setTest2 : " + setTest2.size());

        System.out.println("Elements add to setTest3");
        hashset<String> setTest3 = new hashset<>();

        setTest3.add("e");
        setTest3.add("i");
        setTest3.add("h");
        setTest3.add("x");


        Iterator iter3=setTest3.iterator();
        while(iter3.hasNext())
            System.out.print(iter3.next()+" ");

        System.out.println();
        System.out.println("Size of setTest3 : " + setTest3.size());

        System.out.println("Elements add to setTest4");
        hashset<String> setTest4 = new hashset<>();
        setTest4.add("h");
        setTest4.add("x");

        Iterator iter4=setTest4.iterator();
        while(iter4.hasNext())
            System.out.print(iter4.next()+" ");

        System.out.println();
        System.out.println("Size of setTest4 : " + setTest4.size());

        System.out.print("Contains function for element 'z' in setTest3 = ");
        if(setTest3.contains("z"))
            System.out.println("true");
        else
            System.out.println("false");

        System.out.print("Contains function for element 'x' in setTest3 = ");
        if(setTest3.contains("x"))
            System.out.println("true");
        else
            System.out.println("false");

        System.out.print("ContainsAll function for setTest4 elements in setTest3 = ");
        if(setTest3.containsAll(setTest4))
            System.out.println("true");
        else
            System.out.println("false");

        System.out.println("RetainAll function for setTest3 between setTest4");
        setTest3.retainAll(setTest4);

        System.out.print("setTest3 elements : ");
        iter3=setTest3.iterator();
        while(iter3.hasNext())
            System.out.print(iter3.next()+" ");

        System.out.println();
        System.out.println("Size of setTest3 : " + setTest3.size());

        System.out.print("setTest3 is empty = ");
        if(setTest3.isEmpty())
            System.out.println("true");
        else
            System.out.println("false");

        iter3=setTest3.iterator();
        iter3.remove();
    }
}
