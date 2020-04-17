/*
 * 实验二
 * Fan
 * 1427405017
 * 沈家赟
 * 2016/3/17
 */

public class Fan {
	private int speed;
	private boolean on;
	private float radius;
	private String color;
	
	public Fan()
	{
		speed = 2;
		on = false;
		radius = 2;
		color = "white";
	}
	public Fan(int new_speed, boolean new_on, float new_radius, String new_color)
	{
		setSpeed(new_speed);
		setOn(new_on);
		setRadius(new_radius);
		setColor(new_color);
	}
	public int getSpeed()
	{
		return speed;
	}
	public boolean setSpeed(int new_speed)
	{
		if(new_speed == 1 || new_speed == 2 || new_speed == 3)	// 1\2\3 分别表示 慢\中\快
		{
			speed = new_speed;
			return true;
		}
		else
		{
			System.out.println("Error:new speed is not valid!");
			return false;
		}
	}
	public boolean getOn()
	{
		return on;
	}
	public void setOn(boolean new_on)
	{
		on = new_on;
	}
	public float getRadius()
	{
		return radius;
	}
	public boolean setRadius(float new_radius)
	{
		if(new_radius > 0)
		{
			radius = new_radius;
			return true;
		}
		else
		{
			System.out.println("Error:new radius is not valid!");
			return false;
		}
	}
	public String getColor()
	{
		return color;
	}
	public void setColor(String new_color)
	{
		color = new_color;
	}
	public String toString()
	{
		String info;
		
		switch(speed)
		{
		case 1: info = "speed:" + "slow" + '\t';break;
		case 2: info = "speed:" + "medium" + '\t';break;
		case 3: info = "speed:" + "fast" + '\t';break;
		default:info = "speed:" + "Error" + '\t';break;
		}
		info += on?"status:on ":"status:off ";
		info += "radiud:" + radius + " ";
		info += "color:" + color + " ";
		
		return info;
	}
	
	public static void main(String[] args) {
		Fan fan_a = new Fan();
		String info = fan_a.toString();
		System.out.println(info);
	}

}
