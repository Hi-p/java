import java.util.Scanner;

class Player {
    String name;

    public Player(String name) { 
        this.name = name;
    }

    public String loser() { 
        return name;
    }

    // 사용자로부터 단어 입력받는 메소드
    public String getWordFromUser(Scanner scanner) {
        System.out.print(name + ">> ");
        return scanner.next();
    }
}

class WordGameApp {
    Player [] member; // 참가자를 저장하는 배열
    String firstword = "아버지";
    Scanner scanner = new Scanner(System.in);

    public void run() {
        System.out.println("끝말잇기 게임을 시작합니다...");
        System.out.print("게임에 참가하는 인원은 몇 명입니까? >> ");
        int players = scanner.nextInt(); // 참가자 수 입력

        member = new Player[players]; // Player 객체 생성 -> member[]에 저장

        for (int i = 0; i < players; i++) {
            System.out.print("참가자의 이름을 입력하세요 >> ");
            String name = scanner.next();
            member[i] = new Player(name);
        }

        System.out.println("시작하는 단어는 " + firstword + "입니다.");
        String word = firstword;
        int next = 0; // 차례를 나타내는 변수

        while (true) {
            Player nowplayer = member[next % member.length]; // 현재 차례인 플레이어 구하기
            String word2 = nowplayer.getWordFromUser(scanner); // 단어 입력받기

            if (!checkSuccess(word, word2)) {
                System.out.println(nowplayer.loser() + "이 졌습니다.");
                break;
            }

            else
            word = word2; // 단어 갱신
            next++;
        }
    }

    // 끝말잇기 성공 여부 체크
    public boolean checkSuccess(String Word, String word2) {
        int lastIndex = Word.length() - 1; // 마지막 문자에 대한 인덱스
        char lastChar = Word.charAt(lastIndex); // 마지막 문자
        char firstChar = word2.charAt(0); // 첫 번째 문자
        return lastChar == firstChar;
    }
}

public class Main {
    public static void main(String[] args) {
        WordGameApp game = new WordGameApp(); 
        game.run();
    }
}