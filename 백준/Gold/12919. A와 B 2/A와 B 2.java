import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String s = reader.readLine();
        String t = reader.readLine();

        System.out.print(dfs(s,t) ? 1 : 0);
    }

    public static boolean dfs(String s, String t) {
        if (s.length() == t.length()) {
            if (s.equals(t)) {
                return true;
            }
            return false;
        }
        if (t.charAt(0) == 'B') {
            String substring = t.substring(1);
            StringBuilder sb = new StringBuilder(substring);
            String string = sb.reverse().toString();
            if(dfs(s, string)) return true;
        }

        if (t.charAt(t.length() - 1) == 'A') {
            if(dfs(s, t.substring(0, t.length() - 1))) return true;
        }

        return false;
    }

}
