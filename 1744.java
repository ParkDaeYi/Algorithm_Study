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
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n =Integer.parseInt(st.nextToken());
		int[] arr=new int[n];
		for(int i=0;i<n;++i) {
			st=new StringTokenizer(br.readLine());
			arr[i]=Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);
		int l=0,r=n-1,sum=0;
		for(;l<r;l+=2) {
			if(arr[l]<0 && arr[l+1]<=0) sum+=arr[l]*arr[l+1];
			else break;
		}
		for(;r>0;r-=2) {
			if(arr[r]>1 && arr[r-1]>1) sum+=arr[r]*arr[r-1];
			else break;
		}
		for(;l<=r;++l) sum+=arr[l];
		System.out.println(sum);
	}
}