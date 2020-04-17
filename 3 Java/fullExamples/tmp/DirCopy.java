package tmp;
import java.io.*;

public class DirCopy {
	public static void doDirCopy(File fSrc,File fDesc,boolean crt){
		if (fSrc.isFile()){
			FileCopy.doCopy(fSrc,fDesc);
			return;
		}
		if (fSrc.isDirectory()){
			if (crt)	//创建文件夹
				fDesc.mkdir();
			File[] fds=fSrc.listFiles();
			if (fds==null||fds.length<=0)
				return;
			for (int i=0;i<fds.length;i++){
				File tmpDst=new File(fDesc,fds[i].getName());
				doDirCopy(fds[i],tmpDst,true);
			}
		}
	}
	
	public static void main(String[] args){
		String fsrc,fdst;
		fsrc="g:\\svm_light";
		fdst="g:\\svm_bk";
		File fdSrc,fdDst;
		fdSrc=new File(fsrc);
		fdDst=new File(fdst);
		if (fdSrc.isDirectory()&&!fdDst.exists())
			fdDst.mkdirs();
		doDirCopy(fdSrc,fdDst,false);
	}
}
