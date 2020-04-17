package ch5;

public class StringGet {
	public static void main(String[] args){
		String str="This is a string";
		//String tmp=str.replace('i','I');
		//tmp=str.concat(tmp);
		//System.out.println(str);
		//System.out.println(tmp);
		String[] tps=str.split("i");
		if (tps!=null)
		{
			str=tps[0];
			for (int i=1;i<tps.length;i++){
				str+="I"+tps[i];
			}
		}
		System.out.println(str);
	}
}
