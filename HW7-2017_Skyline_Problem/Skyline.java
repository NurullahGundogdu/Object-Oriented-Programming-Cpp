package nurullah;
import java.io.*;
import java.util.Vector;

public class Skyline {
    private Vector <Integer> left = new Vector<>();
    private Vector <Integer> right = new Vector<>();
    private Vector <Integer> flagg = new Vector<>();
    private Vector <Integer> width = new Vector<>();
    private Vector <Integer> heights = new Vector<>();
    private Vector <Integer> position = new Vector<>();

    public Skyline(){
        readToFile();
    }

    private void readToFile(){
        String line;
        int i=0,num=0,num2=0;


        try{
            BufferedReader br = new BufferedReader(new FileReader("data.txt"));
            while ((line = br.readLine()) != null) {
                String[] parts = ( line).split(" ");

                width.add(Integer.parseInt(parts[0]));
                heights.add(Integer.parseInt(parts[1]));
                position.add(Integer.parseInt(parts[2]));

               // System.out.println(width.get(i) + "," + heights.get(i) + "," + position.get(i));
                i++;
            }
        } catch (Exception e) {
            System.out.println("File error");
            e.printStackTrace();
        }

        for(i=0; i<width.size(); i++){
            if(num<heights.get(i))
                num=heights.get(i);
            if(num2<width.get(i)+position.get(i))
                num2=width.get(i)+position.get(i);
        }
        putt(num+1,num2+1);
    }

    private void putt(int num, int num2){

        int [][] points = new int[num][num2];
        int i,j,k,temp, ab,ac,ae=0;

        for(i=0; i<num; i++)
            for(j=0; j<num2; j++)
                points[i][j]=0;

        for(k=0; k<width.size(); k++)
            for(j = num-1; j >num- heights.get(k)-1; j--)
                for (i=position.get(k); i<width.get(k)+position.get(k); i++)
                    points[j][i]=1;

        for(i=0; i < num2; i++){
            for (j=0; j<num; j++){
                ab=0;
                ac=0;
                if(points[j][i]==1){
                    if(i==0){
                        if(points[j-1][i]==0 && points[j][i+1]==1) {
                            left.add(0);            //en bas oldugu kısım yanı doluysa
                            right.add(0);
                            left.add(0);
                            right.add(num-j);
                            flagg.add(0);
                            flagg.add(0);
                        }else if(points[j-1][i]==0 && points[j][i+1]==0) {
                            left.add(0);
                            right.add(0);
                            left.add(0);
                            right.add(num-j);       //en bas taraf aynı bos ise
                            left.add(i+1);
                            right.add(num-j);
                            flagg.add(0);
                            flagg.add(0);
                            flagg.add(0);
                            ae=1;
                            if(points[num-1][i+1]==0){
                                left.add(i+1);
                                right.add(0);
                                flagg.add(0);       //sonuna kadar sıfır ise

                            }else
                                for(k=j; k<num; k++)
                                    if(points[k][i+1]==1){
                                        left.add(i+1);          //sonunda sayı var ise
                                        right.add(num-k);
                                        flagg.add(0);
                                        break;
                                    }
                        }
                    }else {
                        if(points[j - 1][i] == 0 && points[j][i - 1] == 0 && points[j][i + 1] == 0){
                            if(points[num-1][i-1]==0){
                                left.add(i);
                                right.add(0);
                                flagg.add(0);
                                ab=1;
                            }
                            left.add(i);
                            right.add(num - j);
                            left.add(i+1);
                            right.add(num-j);
                            flagg.add(0);
                            flagg.add(0);
                            if(points[num-1][i+1]==0){
                                left.add(i+1);
                                right.add(0);
                                flagg.add(0);
                                ac=1;
                            }
                            ae=1;
                        }else if (points[j - 1][i] == 0 && points[j][i - 1] == 0) {
                            left.add(i);                    //ust bolum sol bos ise
                            right.add(num - j);
                            flagg.add(0);
                        } else if (points[j - 1][i] == 0 && points[j][i + 1] == 0) {
                            left.add(i + 1);            //ust bolum sag bos ise
                            right.add(num - j);
                            flagg.add(0);
                        } else if (points[j - 1][i] == 1 && points[j][i + 1] == 1 && points[j - 1][i + 1] == 0) {
                            left.add(i + 1);
                            right.add(num - j);
                            flagg.add(0);
                        } else if (points[j - 1][i] == 1 && points[j][i - 1] == 1 && points[j - 1][i - 1] == 0) {
                            left.add(i);
                            right.add(num - j);
                            flagg.add(1);
                        }
                        if (j == num - 1) {
                            if (points[j - 1][i - 1] == 0 && points[j][i - 1] == 0 && ab == 0) {
                                if(ae==1)
                                    ae=0;
                                else{
                                    left.add(i);
                                    right.add(0);
                                    flagg.add(1);
                                }
                            }else if (points[j - 1][i + 1] == 0 && points[j][i + 1] == 0 && ac== 0) {
                                left.add(i + 1);
                                right.add(0);
                                flagg.add(0);
                            }
                        }
                    }
                }
            }
        }
        for(i=0; i<left.size(); i++)
            if(flagg.get(i)==1){
                temp=right.get(i-1);
                right.set(i-1,right.get(i));
                right.set(i,temp);
            }

        for(i=0; i<left.size(); i++) {
            System.out.print("(" + left.get(i) + "," + right.get(i) + ")");
            if(i!=left.size()-1)
                System.out.print(", ");
        }
    }
}
