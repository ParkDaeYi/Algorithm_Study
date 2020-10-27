import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.Queue;

public class Main {

	static int N;
	static ArrayList<Node>[] g;
	static boolean[] visit;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		g = new ArrayList[N+1];
		visit = new boolean[N+1];
		for(int i=1;i<=N;++i) g[i]=new ArrayList<>();
		for(int i=1;i<N;++i) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			g[u].add(new Node(v,w));
			g[v].add(new Node(u,w));
		}
		Node a = bfs(1);
		Node b = bfs(a.f);
		System.out.println(a.s<b.s?b.s:a.s);
	}
	
	static Node bfs(int src) {
		Arrays.fill(visit, false);
		visit[src]=true;
		Queue<Node> q = new LinkedList<>();
		q.offer(new Node(src,0));
		Node ret = new Node(src, 0);
		while(!q.isEmpty()) {
			int cur = q.peek().f,cost=q.peek().s;
			q.remove();
			if(ret.s<cost) ret=new Node(cur,cost);
			for(Node nxt:g[cur]) {
				if(visit[nxt.f]) continue;
				visit[nxt.f]=true;
				q.offer(new Node(nxt.f,cost+nxt.s));
			}
		}
		return ret;
	}
	
	static class Node{
		public int f, s;
		public Node(int f,int s) {
			this.f=f;
			this.s=s;
		}
	}
}