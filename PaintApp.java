import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.io.*;
import javax.imageio.*;
import javax.swing.*;
import javax.swing.event.*;
import java.util.List;
import java.util.ArrayList;

public class PaintApp {

    public static class LineSegment { // 선 정보를 저장하는 클래스
        final List<Point> points;
        final Color color;
        final int strokewidth;
        final String mode;
        final boolean mirrored;

        public LineSegment(List<Point> points, Color color, int strokewidth, String mode, boolean mirrored) {
            this.points = new ArrayList<>(points); // this.points = points; 로 하면 currentline과 alllines가 같은 객체를 참조하게 되어 문제가 발생할 수 있음, currentline 리스트의 내용만 복사하여 새로운 리스트를 생성
            this.color = color;
            this.strokewidth = strokewidth;
            this.mode = mode;
            this.mirrored = mirrored;
        }

        public LineSegment(List<Point> points, Color color, int strokewidth, String mode) {
            this(points, color, strokewidth, mode, false);
        }

        public LineSegment(List<Point> points, Color color, int strokewidth) {
            this(points, color, strokewidth, "DRAW", false);
        }
    }

    public static class PaintPanel extends JPanel implements MouseListener, MouseMotionListener { // main 메서드에서 접근할 수 있도록 static으로 선언, MouseListener와 MouseMotionListener 인터페이스 구현
        List<LineSegment> alllines = new ArrayList<>(); // 선들을 저장할 리스트의 리스트, LineSegment는 하나의 선을 의미
        List<Point> currentline; // 현재 그려지고 있는 선을 저장하는 리스트
        Color currentColor = Color.BLACK; // 현재 선택된 색상, 기본값은 검정색
        int currentStrokeWidth = 2; // 기본 굵기
        String currentmode = "DRAW"; // 기본 모드
        Point sPoint; // 시작점
        Point ePoint; // 끝점
        BufferedImage loadedimage; // 불러온 이미지를 저장할 변수
        boolean mirrormode = false;

        public PaintPanel() {
            setBackground(Color.WHITE);
            addMouseListener(this);
            addMouseMotionListener(this);
        }

        Point getmirrorPoint(Point p) {
            return new Point(this.getWidth() - p.x, p.y);
        }

        @Override
        public void paintComponent(Graphics g) {
            super.paintComponent(g); // 배경을 지우기 위해 부모 클래스의 메서드를 호출, 만약 이 코드가 없으면 이전에 그린 그림이 지워지지 않습니다.

            Graphics2D g2d = (Graphics2D) g; // Graphics 객체를 Graphics2D로 변환하여 더 향상된 그래픽 기능 사용, Graphics를 Graphics2D로
                                             // 다운캐스팅
            g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON); // 안티앨리어싱 설정, 계단현상
                                                                                                      // 완화해주는 기능, 선이
                                                                                                      // 부드럽게 보임

            for (LineSegment line : alllines) { // alllines 리스트에 저장된 모든 선들을 line 변수에 하나씩 가져와서 그린다. , LineSegment = 선 하나를 의미

                g2d.setColor(line.color); // 현재 선택된 색상으로 그리기
                g2d.setStroke(new BasicStroke(line.strokewidth)); // 현재 선택된 굵기로 그리기

                if (loadedimage != null) {
                    g2d.drawImage(loadedimage, 0, 0, this); // 불러온 이미지는 배경으로 사용
                }

                List<Point> points = line.points; // 선을 구성하는 점들의 리스트
                if (line.mode.equals("DRAW")) {
                    for (int i = 0; i < points.size() - 1; i++) { // -1을 하는 이유는 선을 그리기 위해서는 두 점이 필요하다. p1은 i번째 점, p2는
                                                                  // i+1번째 점이므로 마지막 점까지 그리려면 size()-1까지만 반복해야 한다.
                        Point p1 = points.get(i); // 시작 점
                        Point p2 = points.get(i + 1); // 끝 점
                        g2d.drawLine(p1.x, p1.y, p2.x, p2.y); // 두 점 사이에 선을 그림
                    }
                } else { // 도형 복원
                    Point p1 = points.get(0); // 마우스를 누른 시작점
                    Point p2 = points.get(1); // 마우스를 뗀 끝점

                    int x = Math.min(p1.x, p2.x); // 더 작은 값이 시작 좌표
                    int y = Math.min(p1.y, p2.y); // 더 작은 값이 시작 좌표
                    int width = Math.abs(p1.x - p2.x); // 사용자가 오른쪽에서 왼쪽으로 드래그 하더라도 양수가 나오게 함
                    int height = Math.abs(p1.y - p2.y); // 사용자가 아래에서 위로 드래그 하더라도 양수가 나오게 함

                    if (line.mode.equals("LINE")) {
                        g2d.drawLine(p1.x, p1.y, p2.x, p2.y);
                    } else if (line.mode.equals("RECT")) {
                        g2d.drawRect(x, y, width, height);
                    } else if (line.mode.equals("OVAL")) {
                        g2d.drawOval(x, y, width, height);
                    }
                }

                // 점들을 전부 반대편 좌표로 변환
                if (line.mirrored) {
                    List<Point> mirrPoints = new ArrayList<>();
                    for (Point p : line.points) {
                        mirrPoints.add(getmirrorPoint(p));
                    }

                    if (line.mode.equals("DRAW")) {
                        for (int i = 0; i < mirrPoints.size() - 1; i++) {
                            Point p1 = mirrPoints.get(i);
                            Point p2 = mirrPoints.get(i + 1);
                            g2d.drawLine(p1.x, p1.y, p2.x, p2.y);
                        }
                    } else {
                        Point p1 = mirrPoints.get(0);
                        Point p2 = mirrPoints.get(1);

                        int x = Math.min(p1.x, p2.x);
                        int y = Math.min(p1.y, p2.y);
                        int width = Math.abs(p1.x - p2.x);
                        int height = Math.abs(p1.y - p2.y);

                        if (line.mode.equals("LINE")) {
                            g2d.drawLine(p1.x, p1.y, p2.x, p2.y);
                        } else if (line.mode.equals("RECT")) {
                            g2d.drawRect(x, y, width, height);
                        } else if (line.mode.equals("OVAL")) {
                            g2d.drawOval(x, y, width, height);
                        }
                    }
                }
            }

            if (currentmode.equals("DRAW") && currentline != null) { // 현재 그려지고 있는 선이 있다면
                g2d.setColor(currentColor);
                g2d.setStroke(new BasicStroke(currentStrokeWidth));

                for (int i = 0; i < currentline.size() - 1; i++) {
                    Point p1 = currentline.get(i);
                    Point p2 = currentline.get(i + 1);
                    g2d.drawLine(p1.x, p1.y, p2.x, p2.y); // 현재 그리고 있는 선을 덧그림
                }

                if (mirrormode) {
                    List<Point> mirrorPoints = new ArrayList<>();

                    for (Point p : currentline) { // 실시간으로 점들을 반전시켜서 임시 리스트에 담음
                        mirrorPoints.add(getmirrorPoint(p));
                    }

                    for (int i = 0; i < mirrorPoints.size() - 1; i++) {
                        Point p1 = mirrorPoints.get(i);
                        Point p2 = mirrorPoints.get(i + 1);
                        g2d.drawLine(p1.x, p1.y, p2.x, p2.y);
                    }
                }
            }

            // 임시 도형 보여주기
            if (!currentmode.equals("DRAW") && sPoint != null && ePoint != null) {
                g2d.setColor(currentColor);
                g2d.setStroke(new BasicStroke(currentStrokeWidth));

                int x = Math.min(sPoint.x, ePoint.x);
                int y = Math.min(sPoint.y, ePoint.y);
                int width = Math.abs(sPoint.x - ePoint.x);
                int height = Math.abs(sPoint.y - ePoint.y);

                if (currentmode.equals("LINE")) {
                    g2d.drawLine(sPoint.x, sPoint.y, ePoint.x, ePoint.y);
                } else if (currentmode.equals("RECT")) {
                    g2d.drawRect(x, y, width, height);
                } else if (currentmode.equals("OVAL")) {
                    g2d.drawOval(x, y, width, height);
                }

                if (mirrormode) {
                    // 시작점 끝점 각각 반전시킴
                    Point msPoint = getmirrorPoint(sPoint);
                    Point mePoint = getmirrorPoint(ePoint);

                    int mx = Math.min(msPoint.x, mePoint.x);
                    int my = Math.min(msPoint.y, mePoint.y);
                    int mwidth = Math.abs(msPoint.x - mePoint.x);
                    int mheight = Math.abs(msPoint.y - mePoint.y);

                    if (currentmode.equals("LINE")) {
                        g2d.drawLine(msPoint.x, msPoint.y, mePoint.x, mePoint.y);
                    } else if (currentmode.equals("RECT")) {
                        g2d.drawRect(mx, my, mwidth, mheight);
                    } else if (currentmode.equals("OVAL")) {
                        g2d.drawOval(mx, my, mwidth, mheight);
                    }
                }
            }
        }

        public void mousePressed(MouseEvent e) {
            if (currentmode.equals("DRAW")) {
                currentline = new ArrayList<>(); // 새로운 선을 그리기 위해 현재 선 리스트 초기화, 점들을 기록할 새로운 리스트 객체를 만들어서 currentline에 초기화
                currentline.add(e.getPoint());
                sPoint = null;
                ePoint = null;
            } else {
                sPoint = e.getPoint();
                ePoint = sPoint;
                currentline = null;
            }
        }

        public void mouseDragged(MouseEvent e) {
            if (currentmode.equals("DRAW")) {
                if (currentline != null) {
                    currentline.add(e.getPoint());
                }
            } else {
                ePoint = e.getPoint();
            }
            repaint(); // 패널을 다시 그려서 변경 사항을 반영 -> paintComponent 메서드가 호출됨
        }

        public void mouseReleased(MouseEvent e) {
            if (currentmode.equals("DRAW")) {
                if (currentline != null && !currentline.isEmpty()) {
                    LineSegment newline = new LineSegment(currentline, currentColor, currentStrokeWidth, "DRAW",
                            mirrormode); // 현재 그려진 선의 정보를 LineSegment 객체로 생성
                    alllines.add(newline); // 선의 정보를 alllines 리스트에 추가
                }
                currentline = null; // 선 그리기 종료
            } else {
                if (sPoint == null)
                    return;
                List<Point> shapePoints = new ArrayList<>(); // alllines에 추가할 좌표를 담을 리스트 생성
                shapePoints.add(sPoint);
                shapePoints.add(ePoint);

                LineSegment newline = new LineSegment(shapePoints, currentColor, currentStrokeWidth, currentmode,
                        mirrormode);
                alllines.add(newline);
                sPoint = null;
                ePoint = null;
                repaint();
            }
        }

        public void mouseClicked(MouseEvent e) {
        } // 사용하지 않는 메서드들

        public void mouseEntered(MouseEvent e) {
        } // 사용하지 않는 메서드들

        public void mouseExited(MouseEvent e) {
        } // 사용하지 않는 메서드들

        public void mouseMoved(MouseEvent e) {
        } // 사용하지 않는 메서드들
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("그림판 프로그램");
        frame.setSize(1300, 900);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout());
        PaintPanel panel = new PaintPanel(); // JPanel을 상속받은 PaintPanel 객체 생성
        JMenuBar mb = new JMenuBar();
        JMenu filemenu = new JMenu("파일");
        JMenuItem openitem = new JMenuItem("불러오기");
        JMenuItem saveitem = new JMenuItem("저장하기");
        JPanel toolPanel = new JPanel(); // 도구 패널 생성
        toolPanel.setBackground(Color.LIGHT_GRAY);
        JSlider strokeSlider = new JSlider(JSlider.HORIZONTAL, 1, 20, 2); // 최소값 1, 최대값 20, 초기값 2
        strokeSlider.setMajorTickSpacing(5);
        strokeSlider.setMinorTickSpacing(1);
        strokeSlider.setPaintTicks(true);
        strokeSlider.setPaintLabels(true);

        JButton colorchooseButton = new JButton("색상 선택");
        JButton clearallButton = new JButton("전체 지우기");
        JButton red = new JButton("빨강");
        JButton blue = new JButton("파랑");
        JButton black = new JButton("검정");
        JButton eraser = new JButton("지우개");
        JButton draw = new JButton("자유곡선");
        JButton line = new JButton("직선");
        JButton rect = new JButton("사각형");
        JButton oval = new JButton("원");
        JCheckBox mirror = new JCheckBox("대칭 모드");
        mirror.setBackground(Color.LIGHT_GRAY);

        red.addActionListener(e -> { // 람다식으로 ActionListener 구현
            panel.currentColor = Color.RED;
            panel.currentStrokeWidth = strokeSlider.getValue();
        });

        blue.addActionListener(e -> {
            panel.currentColor = Color.BLUE;
            panel.currentStrokeWidth = strokeSlider.getValue();
        });

        black.addActionListener(e -> {
            panel.currentColor = Color.BLACK;
            panel.currentStrokeWidth = strokeSlider.getValue();
        });

        eraser.addActionListener(e -> {
            panel.currentColor = panel.getBackground();
            panel.currentStrokeWidth = strokeSlider.getValue();
        });

        strokeSlider.addChangeListener(e -> {
            panel.currentStrokeWidth = strokeSlider.getValue();
        });

        clearallButton.addActionListener(e -> {
            panel.alllines.clear();
            panel.repaint();
        });

        colorchooseButton.addActionListener(e -> {
            Color selectedColor = JColorChooser.showDialog(frame, "색상 선택", panel.currentColor);
            if (selectedColor != null) {
                panel.currentColor = selectedColor;
                panel.currentStrokeWidth = strokeSlider.getValue();
            }
        });

        draw.addActionListener(e -> {
            panel.currentmode = "DRAW";
            panel.currentline = null; // 마우스를 떼지 않고 도형 모드로 바꿨을 때, currentline에 남은 미완성 선의 좌표가 저장되는 것을 방지
            panel.sPoint = null; // 사용자가 도형을 그리려고 클릭만 하고 드래그 하지 않은 채 모드 변경시, spoint에 남은 좌표가 다음 클릭에 영향을 주는 것을 방지
        });

        line.addActionListener(e -> {
            panel.currentmode = "LINE";
            panel.currentline = null;
            panel.sPoint = null;
        });

        rect.addActionListener(e -> {
            panel.currentmode = "RECT";
            panel.currentline = null;
            panel.sPoint = null;
        });

        oval.addActionListener(e -> {
            panel.currentmode = "OVAL";
            panel.currentline = null;
            panel.sPoint = null;
        });

        saveitem.addActionListener(e -> {
            JFileChooser fileChooser = new JFileChooser();
            fileChooser.setDialogTitle("그림 저장");
            int usersection = fileChooser.showSaveDialog(frame); // 저장용 창을 띄움. usersection은 사용자가 저장을 눌렀는지 취소를 눌렀는지 결과를
                                                                 // 받음, 0 -> 저장, 1 -> 취소, -1 -> 에러 발생

            if (usersection == JFileChooser.APPROVE_OPTION) { // 저장을 눌렀다면
                File filetosave = fileChooser.getSelectedFile(); // 선택한 파일 경로 가져옴
                try {
                    if (!filetosave.getAbsolutePath().endsWith(".png")) {
                        filetosave = new File(filetosave.getAbsolutePath() + ".png"); // 파일명에 png 붙여줌
                    }

                    // JPanel에 그려진 그림은 파일 아님. 그래서 메모리 속에 PaintPanel이 가지고 있는 그림을 복사함
                    BufferedImage image = new BufferedImage(panel.getWidth(), panel.getHeight(),
                            BufferedImage.TYPE_INT_RGB); // RAM 속에 PaintPanel과 똑같은 크기의 빈 이미지 객체를 만듦. 색상 모드는 일반적인 RGB 방식
                                                         // 사용
                    Graphics2D g2 = image.createGraphics(); // image 위에 그릴수 있는 전용 붓 생성
                    panel.paint(g2); // PaintPanel에게 명령 -> 모니터 화면 말고, image 위에 그려라
                    g2.dispose(); // 버리기

                    ImageIO.write(image, "png", filetosave); // image 데이터를 png형식으로 filetosave에 저장
                    JOptionPane.showMessageDialog(frame, "저장되었습니다: " + filetosave.getName());
                } catch (IOException e2) {
                    JOptionPane.showMessageDialog(frame, "저장 중 오류가 발생했습니다!", "에러", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        openitem.addActionListener(e -> {
            JFileChooser fileChooser = new JFileChooser();
            fileChooser.setDialogTitle("그림 불러오기");
            int usersection = fileChooser.showOpenDialog(frame);

            if (usersection == JFileChooser.APPROVE_OPTION) {
                File filetoopen = fileChooser.getSelectedFile();
                try {
                    BufferedImage image = ImageIO.read(filetoopen); // 파일 -> 이미지 변환
                    panel.loadedimage = image;
                    panel.alllines.clear();
                    panel.repaint();
                } catch (IOException e2) {
                    JOptionPane.showMessageDialog(frame, "불러오기 중 오류가 발생했습니다!", "에러", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        mirror.addActionListener(e -> {
            panel.mirrormode = mirror.isSelected();
        });

        filemenu.add(openitem);
        filemenu.add(saveitem);
        mb.add(filemenu);
        frame.setJMenuBar(mb);
        toolPanel.add(new JLabel("굵기: "));
        toolPanel.add(strokeSlider);
        toolPanel.add(colorchooseButton);
        toolPanel.add(clearallButton);
        toolPanel.add(red);
        toolPanel.add(blue);
        toolPanel.add(black);
        toolPanel.add(eraser);
        toolPanel.add(draw);
        toolPanel.add(line);
        toolPanel.add(rect);
        toolPanel.add(oval);
        toolPanel.add(mirror);
        frame.add(toolPanel, BorderLayout.NORTH);
        frame.add(panel, BorderLayout.CENTER);

        frame.setVisible(true);
    }
}