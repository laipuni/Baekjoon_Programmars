import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String doc = reader.readLine();
		String findStr = reader.readLine();
		int docSize = doc.length();
		int findStrSize = findStr.length();
		doc = doc.replace(findStr, "");
		System.out.println((docSize - doc.length()) / findStrSize);
	}

}