import java.io.*; 
public class Main {	
    public static void main(String[] args) throws Exception{		
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            String inputStr = br.readLine();
            if(inputStr.equals("#"))
                break;			
            inputStr = inputStr.toLowerCase();
            int ans=0;
            for(int i=0;i<inputStr.length();i++) {	
                char t=inputStr.charAt(i);
                if(t=='a' || t=='e' || t=='i' || t=='o' || t=='u')ans++;			
            }			
            System.out.println(ans);
        }	
    }
}