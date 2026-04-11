import java.util.Random;
import java.util.Scanner;

// 추상 클래스
abstract class Player {
    protected String [] bet = {"묵", "찌", "빠"};
    protected String name; // 선수 이름
    protected String lastBet = null; // 선수가 최근에 낸 값

    protected Player(String name) {  // 생성자
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public String getBet() {
        return lastBet;
    }

    // 선수가 낸 것으로 묵,찌,빠 중 1개를 결정하여 리턴
    abstract public String next(); // 추상메소드
}

// Human 클래스
class Human extends Player {
    Scanner scanner;

    public Human(String name, Scanner scanner) { //생성자
        super(name);
        this.scanner = scanner;
    }

    @Override
    public String next() {
        while (true) {
            System.out.print(name + " >> ");
            String input = scanner.next();
            if (input.equals("묵") || input.equals("찌") || input.equals("빠")) {
                lastBet = input;
                return lastBet;
            }
            System.out.println("묵, 찌, 빠 중에서 다시 입력하세요.");
        }
    }
}

// Computer 클래스
class Computer extends Player {
    Random rand = new Random();

    public Computer(String name) { // 생성자
        super(name);
    }

    @Override
    public String next() {
        lastBet = bet[rand.nextInt(3)]; // 0 이상 3 미만 정수 하나 랜덤 생성
        System.out.println(name + " >> 결정하였습니다.");
        return lastBet;
    }
}

// Game 클래스
class Game {
    Player [] players = new Player[2];
    Player owner; // 현재 오너
    Scanner scanner = new Scanner(System.in);

    public void createPlayers() { // 선수 생성 메소드
        System.out.println("묵찌빠 게임을 시작합니다.");
        System.out.print("선수이름 입력 >> ");
        String player = scanner.next();
        players[0] = new Human(player, scanner);

        System.out.print("컴퓨터이름 입력 >> ");
        String computerName = scanner.next();
        players[1] = new Computer(computerName);

        owner = players[0]; // 사람 먼저 오너
        System.out.println("2명의 선수를 생성 완료하였습니다.\n");
    }

    public void run() {
        createPlayers(); // 플레이어 생성 및 초기화

        while (true) {
            String human = players[0].next();
            String computer = players[1].next();

            System.out.println(players[0].getName() + " : " + human + ", " +
                               players[1].getName() + " : " + computer);

            int result = check(human, computer);

            if (result == 0) { // 오너 승리
                System.out.println(owner.getName() + " 이겼습니다.");
                System.out.println("게임을 종료합니다.");
                break;
            }
            else if (result == 1) { // 사람 승
                owner = players[0];
                System.out.println("오너가 " + owner.getName() + "로 변경되었습니다.\n");
            }
            else { // 컴퓨터 승
                owner = players[1];
                System.out.println("오너가 " + owner.getName() + "로 변경되었습니다.\n");
            }
        }
    }

    // 가위바위보 판정
    int check(String human, String computer) {
        if (human.equals(computer)) 
            return 0;

        if ((human.equals("묵") && computer.equals("찌")) || (human.equals("찌") && computer.equals("빠")) || (human.equals("빠") && computer.equals("묵")))
            return 1;
        
        return -1;
    }
}

// MGPApp 클래스
public class MGPApp {
    public static void main(String[] args) {
        new Game().run();
    }
}
