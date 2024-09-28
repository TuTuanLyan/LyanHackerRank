import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {
    
    private static List<Integer> res = new ArrayList<>();
    /*
     * Complete the 'kFactorization' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts following parameters:
     *  1. INTEGER n
     *  2. INTEGER_ARRAY A
     */

    public static List<Integer> kFactorization(int n, List<Integer> A) {
        Collections.sort(A);
        
        find(n, A);
        Collections.reverse(res);
        return res;
    }
    
    private static void find(int total, List<Integer> a){
        if(total == 1){
            res.add(1);
            return;
        }
        
        if(a.size() == 0){
            res.clear();
            res.add(-1);
            return;
        }
        
        int x = a.get(a.size() - 1);
        
        if(total % x == 0){
            res.add(total);
            total/=x;
        }
        else{
            a.remove(a.size() - 1);
        }
        
        find(total, a);
    }

}

public class kFactorization {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int k = Integer.parseInt(firstMultipleInput[1]);

        List<Integer> A = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        List<Integer> result = Result.kFactorization(n, A);

        bufferedWriter.write(
            result.stream()
                .map(Object::toString)
                .collect(joining(" "))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
