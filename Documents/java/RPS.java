import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class RPS extends JFrame implements ActionListener {
    JTextField information, output;
    JButton 가위;
    JButton 바위;
    JButton 보;
    Random random = new Random();

    public RPS() {
        setTitle("가위, 바위, 보");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // 안내문
        information = new JTextField("아래의 버튼 중에서 하나를 클릭하시오!");
        information.setEditable(false); // 수정 불가
        add(information, BorderLayout.NORTH);

        // 버튼 생성
        가위 = new JButton("가위");
        바위 = new JButton("바위");
        보 = new JButton("보");
  
        가위.addActionListener(this);
        바위.addActionListener(this);
        보.addActionListener(this);

        
        JPanel panel = new JPanel(new BorderLayout());
        panel.add(가위, BorderLayout.WEST);
        panel.add(바위, BorderLayout.CENTER);
        panel.add(보, BorderLayout.EAST);
        add(panel, BorderLayout.CENTER);

        // 결과창
        output = new JTextField("결과가 여기에 표시됩니다.");
        output.setEditable(false);
        add(output, BorderLayout.SOUTH);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        int user = -1; // 사용자 선택

        // 누른 버튼의 인덱스 찾기
        if (e.getSource() == 가위) 
            user = 0;
        else if (e.getSource() == 바위) 
            user = 1;
        else if (e.getSource() == 보) 
            user = 2;

        int computer = random.nextInt(3);

        if (user == 0) { // 가위
            if(computer == 0) {
                output.setText("사용자: 가위, 컴퓨터: 가위. 비김!");
            } else if (computer == 1) {
                output.setText("사용자: 가위, 컴퓨터: 바위. 컴퓨터 승!");
            } else {
                output.setText("사용자: 가위, 컴퓨터: 보. 사용자 승!");
            }
        }
        else if (user == 1) { // 바위
            if(computer == 0) {
                output.setText("사용자: 바위, 컴퓨터: 가위. 사용자 승!");
            } else if (computer == 1) {
                output.setText("사용자: 바위, 컴퓨터: 바위. 비김!");
            } else {
                output.setText("사용자: 바위, 컴퓨터: 보. 컴퓨터 승!");
            }
        }
        else {
            if(computer == 0) { // 보
                output.setText("사용자: 보, 컴퓨터: 가위. 컴퓨터 승!");
            } else if (computer == 1) {
                output.setText("사용자: 보, 컴퓨터: 바위. 사용자 승!");
            } else {
                output.setText("사용자: 보, 컴퓨터: 보. 비김!");
            }
        }
    }
    public static void main(String[] args) {
        new RPS();
    }
}
