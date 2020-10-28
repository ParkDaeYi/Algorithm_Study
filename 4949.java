import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.Stack;
import java.util.HashSet;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while(true) {
			String str = br.readLine();
			int n = str.length();
			if(n==1) break;
			Stack<Character> st = new Stack<>();
			boolean flag = false;
			for(int i=0;i<n;++i) {
				char c=str.charAt(i);
				flag = true;
				if(c=='('||c=='[') st.push(c);
				else if(c==')'||c==']') {
					if(st.isEmpty()) break;
					else if(c==')'&&st.peek()!='(') break;
					else if(c==']'&&st.peek()!='[') break;
					else st.pop();
				}
				flag = false;
			}
			if(!st.isEmpty()) flag=true;
			System.out.println(flag?"no":"yes");
		}
	}
}