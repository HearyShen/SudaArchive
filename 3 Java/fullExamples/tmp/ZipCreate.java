package tmp;

import java.io.*;
import java.util.zip.*;

public class ZipCreate {
	private static void zipFile(ZipOutputStream o, File fd,String pName) throws IOException {
		String strName;
		if (pName==null)
			strName=fd.getName();
		else
			strName=pName+"\\"+fd.getName();
		if (fd.isDirectory()){			
			File[] lst=fd.listFiles();
			if (lst!=null)
				for (int i=0;i<lst.length;i++)
					zipFile(o,lst[i],strName);
			return;
		}
		ZipEntry entry = new ZipEntry(strName);
		o.putNextEntry(entry);
		FileInputStream fin = new FileInputStream(fd);
		BufferedInputStream bin = new BufferedInputStream(fin);
		int c = bin.read();
		while (c != -1) {
			o.write(c);
			c = bin.read();
		}
		bin.close();
		fin.close();
		o.closeEntry();
	}

	public static void creatZip(String n, File fd) throws IOException {
		ZipOutputStream zout = new ZipOutputStream(new FileOutputStream(n));
		zipFile(zout, fd,null);
		zout.close();
	}

	public static void main(String[] args) throws IOException {
		String zipFile = "g:\\test.zip";
		String srcFile = "G:\\B19306_01\\win.102\\b14320";
		File fd = new File(srcFile);
		creatZip(zipFile, fd);
	}
}
