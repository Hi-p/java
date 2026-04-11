import java.util.Scanner;
import java.util.Random;

public class john {

    //패딩의 안쪽 영역에 지뢰를 무작위로 배치
    public static void a (int[][] board, int k, int n, int m) {
        Random random = new Random();
        int d = 0; // 처음 지뢰 개수 0

        while (d < k) {
            int r = random.nextInt(n) + 1; // 1~n
            int c = random.nextInt(m) + 1; // 1~m

            if (board[r][c] != -1) {
                board[r][c] = -1;
                d++;
            }
        }
    }

    // 패딩 보드를 이용하여 각 칸 주위의 지뢰 개수를 계산
    public static void b (int[][] board, int n, int m) {
        for (int i = 1; i <= n; i++) { // 1부터 n까지
            for (int j = 1; j <= m; j++) { //1부터 m까지만 안쪽 영역 계산
                if (board[i][j] == -1) // 지뢰면 계산 안 함
                    continue;
                
                int Count = 0;
                // 주변 8칸 확인
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        
                        // 패딩 덕분에 board[i+dr][j+dc]는 항상 유효한 인덱스임
                        if (board[i + dr][j + dc] == -1) {
                            Count++;
                        }
                    }
                }
                board[i][j] = Count; //주변 지뢰 개수 해당 칸에 저장
            }
        }
    }

    // 실제 게임 영역만 출력
    public static void c (int[][] board, int n, int m) {
        // 1부터 n까지, 1부터 m까지의 영역만 출력
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                System.out.printf("%3d ", board[i][j]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("2차원 배열의 크기(n행 m열) : ");
        int n = scanner.nextInt(); // 행 입력
        int m = scanner.nextInt(); // 열 입력

        System.out.print("지뢰의 개수는 : ");
        int k = scanner.nextInt(); // 지뢰 개수 입력


        int[][] board = new int[n + 2][m + 2]; // (n+2) x (m+2) 크기의 '패딩 보드' 생성 = 0

        
        a (board, k, n, m); // 패딩을 제외한 안쪽 영역에 지뢰 배치

        b (board, n, m); // 주변 지뢰 개수 계산

        c (board, n, m); // 실제 게임 영역 출력

        scanner.close();
    }
}

