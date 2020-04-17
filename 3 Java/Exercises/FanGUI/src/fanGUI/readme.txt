readme.text
实验四
1427405017
沈家赟
2016/5/27
*******************************************************************************
设计风扇类及风扇界面，能让用户调节风速、定时。
*******************************************************************************

注意：
1、文件清单：
	本程序包含4份java代码：
	1）风扇框架 FanFrame.java
	2）风扇控制面板 FanControlPanel.java
	3）风扇定时面板 FanTimerPanel.java
	4）风扇图形面板 FanGraphicPanel.java
	
其中，各Class还包含内部类，如继承的ActionListener；
  风扇图形面板FanGraphicPanel提供API: public void set_repaint_period(int new_period) 
    通过调整刷新率来实现风扇转速快慢，相比于调整角度控制转速，不易引起视觉卡顿感；
  风扇控制面板FanControlPanel、风扇定时面板FanTimerPanel通过传递引用形参来实现对风扇图形面板FanGraphicPanel的控制；

2、程序主函数 位于 风扇框架 FanFrame.java 文件中