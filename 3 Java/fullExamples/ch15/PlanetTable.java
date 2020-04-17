package ch15;
import javax.swing.*;
import java.awt.*;

public class PlanetTable extends JFrame{
	private static final long serialVersionUID = 1L;

	private Object[][] cells={
			{"Mercury",2440.0,0,false,Color.YELLOW},
			{"Venus",6052.0,0,false,Color.YELLOW},
			{"Earth",6378.0,1,false,Color.BLUE},
			{"Mars",3397.0,2,false,Color.RED},
			{"Jupiter",71492,16,true,Color.ORANGE},
			{"Saturn",60268.3,18,true,Color.BLUE}
	};
	
	private String[] colNames={"Planet","Radius","Moons",
			"Gaseous","Color"};
	
	public PlanetTable(){
		setTitle("PlanetTable");
		setSize(600,200);
		final JTable table=new JTable(cells,colNames);
		this.getContentPane().add(new JScrollPane(table),BorderLayout.CENTER);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
	}
	
	public static void main(String[] args){
		new PlanetTable();
	}
}
