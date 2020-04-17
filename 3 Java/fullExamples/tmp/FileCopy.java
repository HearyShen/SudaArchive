package tmp;
import java.io.*;

public class FileCopy {
	public static boolean doCopy(File source,File dest){
		boolean sucess=false;
		try {
			BufferedInputStream fsrc=new BufferedInputStream(new FileInputStream(source));
			BufferedOutputStream fdest=new BufferedOutputStream(new FileOutputStream(dest));
			int data;
			while ((data=fsrc.read())!=-1)
				fdest.write(data);
			fsrc.close();
			fdest.close();
			sucess=true;
		} catch (FileNotFoundException e) {
			System.err.println(e.getMessage());
			sucess=false;
		}catch(IOException e){
			System.err.println(e.getMessage());
			sucess=false;
		}
		return sucess;
	}
	
	public static void main(String[] args){
		String fileSrc,fileDest;
		fileSrc="g:\\×ÔÖ÷Á·Ï°£¨ËÎ£©.doc";
		fileDest="g:\\tmp.doc";
		File fdSrc=new File(fileSrc);
		File fdDest=new File(fileDest);
		doCopy(fdSrc,fdDest);
	}
}
