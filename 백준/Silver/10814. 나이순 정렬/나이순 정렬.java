import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer;
        StringBuilder builder = new StringBuilder();
        int count = Integer.parseInt(reader.readLine());

        List<Member> members = new ArrayList<>();
        for (int i = 0; i < count; i++) {
            tokenizer = new StringTokenizer(reader.readLine()," ");
            int age = Integer.parseInt(tokenizer.nextToken());
            String name = tokenizer.nextToken();
            members.add(new Member(age,name));
        }

        members.sort(new Comparator<Member>() {
            @Override
            public int compare(final Member o1, final Member o2) {
                return o1.age - o2.age;
            }
        });


        members.forEach(member -> builder.append(member.toString()).append("\n"));
        System.out.print(builder.toString());
    }

     static class Member{
        private int age;
        private String name;

        public Member(final int age, final String name) {
            this.age = age;
            this.name = name;
        }

        public int getAge() {
            return age;
        }

        public String getName() {
            return name;
        }

         @Override
         public String toString() {
             return age + " " + name;
         }
     }

}
