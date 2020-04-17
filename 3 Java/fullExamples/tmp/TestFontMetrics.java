package tmp;

/*编写程序，以红色、ScanSerif、粗体＋斜体、20磅的规格居中显式相关信息。*/
import java.awt.*;
import javax.swing.*;
class MessagePanel extends JPanel{
	private String message="Welcom to Java GUI";	
	private int xCoordinate=20;
	private int yCoordinate=20;	
	private boolean centered;	
	public MessagePanel(String mess){
		message=mess;
	}	
	public void setCentered(boolean cen){
		this.centered=cen;
	}	
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		if (this.centered){
			FontMetrics fm=g.getFontMetrics();
			int w=fm.stringWidth(message);
			int h=fm.getAscent();
			this.xCoordinate=(this.getSize().width-w)/2;
			this.yCoordinate=(this.getSize().height-h)/2;
		}
		g.drawString(message,xCoordinate,yCoordinate);
	}
}
public class TestFontMetrics extends JFrame{
	public TestFontMetrics(){
		MessagePanel msgP=new MessagePanel("Welcom to Java GUI");
		msgP.setForeground(Color.RED);
		msgP.setFont(new Font("SansSerif",Font.BOLD+Font.ITALIC,20));
		msgP.setCentered(true);
		this.getContentPane().add(msgP);
		this.setSize(300,200);
		this.setTitle("Test FontMetrics");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}	
	public static void main(String[] args){
		new TestFontMetrics();
	}
}
