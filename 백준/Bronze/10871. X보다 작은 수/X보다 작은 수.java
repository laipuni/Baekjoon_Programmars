import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.StringJoiner;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine(), " ");

        int length = Integer.parseInt(tokenizer.nextToken());
        int bound = Integer.parseInt(tokenizer.nextToken());

        List<String> result = Arrays.stream(reader.readLine().split(" "))
                .filter(number -> bound > Integer.parseInt(number))
                .collect(Collectors.toList());

        StringJoiner joiner = new StringJoiner(" ");

        result.forEach(joiner::add);

        System.out.println(joiner.toString());
    }

}
