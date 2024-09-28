import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;

class Result {

    public static String res = "";

    public static boolean Solve(List<Integer> a, int total, String cur, int i, boolean save[][]) {
        total = total % 101;

        if (i == a.size()) {
            if (total % 101 == 0) {
                res = cur;
                return true;
            }
            return false;
        }

        if (save[i][total + 101]) return false;
        save[i][total + 101] = true;

        if (Solve(a, total + a.get(i) % 101, cur + "+" + a.get(i), i + 1, save))
            return true;
        if (Solve(a, total - a.get(i) % 101, cur + "-" + a.get(i), i + 1, save))
            return true;
        if (Solve(a, total * a.get(i) % 101, cur + "*" + a.get(i), i + 1, save))
            return true;

        return false;
    }

    public static String arithmeticExpressions(List<Integer> arr) {

        boolean[][] save = new boolean[arr.size()][2 * 101];

        Solve(arr, arr.get(0), "" + arr.get(0), 1, save);

        return res;
    }
}

public class Arithmetic_Expressions {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                .map(Integer::parseInt)
                .collect(toList());

        String result = Result.arithmeticExpressions(arr);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
