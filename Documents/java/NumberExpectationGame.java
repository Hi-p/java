import java.util.Scanner;
import java.util.Random;

class Player {
    String name;
    int num;

    Player(String name) {
        this.name = name;
    }
}

public class NumberExpectationGame {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random rand = new Random();
        
        // 선수 이름 입력
        System.out.print("게임에 참여할 선수들 이름 >> ");
        String playernames = scanner.nextLine();

        // 이름을 공백 기준으로 나눠서 배열로 저장
        String [] names = playernames.split(" ");
        int player = names.length; // 참가자 수 = 배열의 길이
        Player [] players = new Player[player];

        for (int i = 0; i < player; i++)
            players[i] = new Player(names[i]);

        // 각 선수의 좋아하는 숫자 입력
        for (int i = 0; i < player; i++) {
            while (true) {
                System.out.print("[" + players[i].name + "] 정수 선택(1~10) >> ");
                String input = scanner.nextLine();
                try {
                    int n = Integer.parseInt(input);
                    if (n < 1 || n > 10) {
                        System.out.println("1~10 사이의 정수를 입력하세요.");
                        continue;
                    }
                    players[i].num = n;
                    break;
                } 
                catch (NumberFormatException e) {
                    System.out.println("숫자를 입력하세요.");
                }
            }
        }

        System.out.print("Enter키 입력 >> ");
        scanner.nextLine();

        // 현재 게임 선수 수
        int currentCount = player;

        while (true) {
            // 정수 15개 생성
            int [] random = new int[15];
            for (int i = 0; i < 15; i++) {
                random[i] = rand.nextInt(10) + 1;
                System.out.print(random[i] + " ");
            }
            System.out.println();

            // 각 선수가 맞춘 개수 계산
            int [] correct = new int[currentCount];
            for (int i = 0; i < currentCount; i++) {
                int count = 0;
                for (int j = 0; j < 15; j++) {
                    if (random[j] == players[i].num) 
                        count++;
                }
                correct[i] = count;
                System.out.println("[" + players[i].name + "] 맞춘 개수: " + count);
            }

            // 최소값 찾기
            int min = correct[0];
            for (int i = 1; i < currentCount; i++) {
                if (correct[i] < min)
                    min = correct[i];
            }

            // 패자 수 세기
            int loser = 0;
            for (int i = 0; i < currentCount; i++) {
                if (correct[i] == min) 
                    loser++;
            }

            // 패자 이름 출력
            System.out.print("현재 패자들 : ");
            for (int i = 0; i < currentCount; i++) {
                if (correct[i] == min)
                    System.out.print(players[i].name + " ");
            }
            
            // 패자가 1명이라면 종료
            if (loser == 1) {
                for (int i = 0; i < currentCount; i++) {
                    if (correct[i] == min)
                        System.out.println("\n최종 패자는 " + players[i].name + "입니다.");
                }
                break;
            }

            // 다음 게임용 새 배열 만들기
            Player [] nextPlayers = new Player[loser];
            int idx = 0;
            for (int i = 0; i < currentCount; i++) {
                if (correct[i] == min) {
                    nextPlayers[idx] = players[i];
                    idx++;
                }
            }
            
            players = nextPlayers;
            currentCount = loser;

            System.out.print("\nEnter키 입력 >> ");
            scanner.nextLine();
        }

        scanner.close();
    }
}
