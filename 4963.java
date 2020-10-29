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
	static int w,h;
	static int[][] map=new int[51][51];
	static int[] dy= {1,0,-1,0,1,1,-1,-1};
	static int[] dx= {0,1,0,-1,1,-1,1,-1};
	static boolean[][] visit=new boolean[51][51];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			w = Integer.parseInt(st.nextToken());
			h = Integer.parseInt(st.nextToken());
			if(w==0&&h==0) break;
			for(int i=0;i<h;++i) {
				Arrays.fill(visit[i], false);
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<w;++j) {
					map[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			int cnt=0;
			for(int i=0;i<h;++i) for(int j=0;j<w;++j) {
				if(map[i][j] == 0 || visit[i][j]) continue;
				bfs(i,j);
				++cnt;
			}
			System.out.println(cnt);
		}
	}
	
	public static void bfs(int y,int x) {
		visit[y][x]=true;
		Queue<Node> q=new LinkedList<>();
		q.offer(new Node(y,x));
		while(!q.isEmpty()) {
			int cy=q.peek().y,cx=q.peek().x;
			q.remove();
			for(int i=0;i<8;++i) {
				int ny=cy+dy[i],nx=cx+dx[i];
				if(ny<0||nx<0||ny>=h||nx>=w) continue;
				if(map[ny][nx]==0||visit[ny][nx]) continue;
				visit[ny][nx]=true;
				q.offer(new Node(ny,nx));
			}
		}
	}
	
	public static class Node{
		int y,x;
		Node(int y,int x){
			this.y=y;
			this.x=x;
		}
	}
}