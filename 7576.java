import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.Queue;

public class Main {

	static int[] dy= {1,0,-1,0};
	static int[] dx= {0,1,0,-1};
	static int[][] map;
	static int ans=0, N, M;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		Queue<tomato> q = new LinkedList<>();
		for(int i=0;i<N;++i) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<M;++j) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] == 1) q.offer(new tomato(i,j));
			}
		}
		while(!q.isEmpty()) {
			int y = q.peek().y, x = q.peek().x;
			q.remove();
			for(int i=0;i<4;++i) {
				int ny=y+dy[i],nx=x+dx[i];
				if(ny<0||nx<0||ny>=N||nx>=M) continue;
				if(map[ny][nx] == 0) {
					q.offer(new tomato(ny,nx));
					map[ny][nx] = map[y][x] + 1;
				}
			}
		}
		print();
	}
	
	static void print() {
		for(int i=0;i<N;++i) {
			for(int j=0;j<M;++j) {
				if(map[i][j]==0) {
					System.out.println(-1);
					return;
				}
				else if(ans<map[i][j]) ans=map[i][j];
			}
		}
		System.out.println(ans-1);
	}
	
	static class tomato{
		public int y,x;
		public tomato(int y,int x) {
			this.y=y;
			this.x=x;
		}
	}
}