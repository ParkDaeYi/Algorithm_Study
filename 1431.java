import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.Stack;
import java.util.HashSet;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String[] str = new String[n];
		for(int i=0;i<n;++i) str[i]=br.readLine();
		Arrays.sort(str, new Comparator<String>() {
			@Override
			public int compare(String s1, String s2) {
				int ret = s1.length() - s2.length();
				if(ret == 0) {
					int m1=0,m2=0;
					for(int i=0;i<s1.length();++i) {
						char c1 = s1.charAt(i);
						char c2 = s2.charAt(i);
						if('0'<=c1&&c1<='9') m1+=c1-'0';
						if('0'<=c2&&c2<='9') m2+=c2-'0';
					}
					if(m1 == m2) return s1.compareTo(s2);
					return m1-m2;
				}
				return ret;
			}
		});
		for(int i=0;i<n;++i) System.out.println(str[i]);
	}
}

//public class Main {
//	public static void main(String[] args) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		String str = br.readLine();
//		int n = Integer.parseInt(str);
//		ArrayList<Node>[] al = new ArrayList[51];
//		for(int i=1;i<51;++i) al[i]=new ArrayList<>();
//		while(n-- != 0) {
//			str = br.readLine();
//			int sum=0, len=str.length();
//			for(int i=0;i<len;++i) {
//				char c =str.charAt(i);
//				if('0'<=c&&c<='9') sum+=c-'0';
//			}
//			al[len].add(new Node(sum,str));
//		}
//		for(int i=1;i<51;++i) {
//			if(al[i].size()==0) continue;
//			Collections.sort(al[i]);
//			for(Node e: al[i]) System.out.println(e.str);
//		}
//	}
//	
//	static class Node implements Comparable<Node>{
//		public String str;
//		public int sum;
//		Node(int sum, String str){
//			this.sum=sum;
//			this.str=str;
//		}
//		@Override
//		public int compareTo(Node node) {
//			if(this.sum==node.sum) return this.str.compareTo(node.str);
//			return this.sum - node.sum;
//		}
//	}
//}