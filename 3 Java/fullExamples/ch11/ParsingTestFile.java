package ch11;
import java.io.*;

public class ParsingTestFile {
	public static void main(String[] args){
		FileReader frs=null;
		FileWriter fws=null;
		StreamTokenizer in=null;
		PrintWriter out=null;
		
		String sname;
		double midterm1,midterm2,finalScore,total;
		
		try{
			frs=new FileReader("in.dat");
			fws=new FileWriter("g:\\out.dat");
			in=new StreamTokenizer(frs);
			out=new PrintWriter(fws);
			in.nextToken();
			while (in.ttype!=StreamTokenizer.TT_EOF){
				if (in.ttype==StreamTokenizer.TT_WORD)
					sname=in.sval;
				else
				{
					System.out.println("Bad formate!");
					return;
				}
				if (in.nextToken()==StreamTokenizer.TT_NUMBER)
					midterm1=in.nval;
				else
				{
					System.out.println("Bad formate!");
					return;
				}
				if (in.nextToken()==StreamTokenizer.TT_NUMBER)
					midterm2=in.nval;
				else
				{
					System.out.println("Bad formate!");
					return;
				}
				if (in.nextToken()==StreamTokenizer.TT_NUMBER)
					finalScore=in.nval;
				else
				{
					System.out.println("Bad formate!");
					return;
				}
				total=midterm1*0.3+midterm2*0.3+finalScore*0.4;
				out.println(sname+" "+total);
				
				in.nextToken();	//»ñµÃ»»ÐÐ·ûºÅ
			}
		}catch(IOException e){
			System.err.println(e.getMessage());
		}
		finally{
			try{
				if (frs!=null)
					frs.close();
				if (fws!=null)
					fws.close();
			}catch(IOException e){
				System.err.println(e.getMessage());
			}
		}
	}
}
