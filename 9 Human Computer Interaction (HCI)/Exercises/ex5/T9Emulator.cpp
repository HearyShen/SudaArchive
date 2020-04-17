/*****************************************************************
 T9Emulator.cpp		[implement of class T9Emulator]
	An T9 keyboard emulator program with mod switching ability.
		1427405017
		Jiayun Shen
		2016-12-10
******************************************************************/
#include "T9Emulator.h"

using namespace gcn;

T9Emulator::T9Emulator()
{
	status = 0;

	Container *top = this;
	if (TTF_Init() == 0)
		ttf_font = new SDLTrueTypeFont("myfont.ttf", 22);
	else {
		std::cout << "Can't Init SDL_TTF library!" << std::endl;
		exit(-1);
	}

	// The global font is static and must be set.
	gcn::Widget::setGlobalFont(ttf_font);

	/*
	* Create all the widgets
	*/
	button1 = new Button(btn1_caption[status]);
	button2 = new Button(btn2_caption[status]);
	button3 = new Button(btn3_caption[status]);

	button4 = new Button(btn4_caption[status]);
	button5 = new Button(btn5_caption[status]);
	button6 = new Button(btn6_caption[status]);

	button7 = new Button(btn7_caption[status]);
	button8 = new Button(btn8_caption[status]);
	button9 = new Button(btn9_caption[status]);

	button_extend = new Button(btn_extend_caption[status]);
	button0 = new Button(btn0_caption[status]);
	button_del = new Button("<=");

	textBox = new gcn::TextBox();
	textBoxScrollArea = new ScrollArea(textBox);
	textBoxScrollArea->setWidth(300);
	textBoxScrollArea->setHeight(180);
	textBoxScrollArea->setBorderSize(1);

	/*
	* Add them to the top container
	*/
	//top->add(textBox, 0, 0);
	top->add(textBoxScrollArea, 0, 0);

	top->add(button1, 0, 180);
	top->add(button2, 100, 180);
	top->add(button3, 200, 180);

	top->add(button4, 0, 260);
	top->add(button5, 100, 260);
	top->add(button6, 200, 260);

	top->add(button7, 0, 340);
	top->add(button8, 100, 340);
	top->add(button9, 200, 340);

	top->add(button_extend, 0, 420);
	top->add(button0, 100, 420);
	top->add(button_del, 200, 420);

	/*
	* Set Size for every widgets
	*/
	textBox->setSize(300, 180);

	button1->setSize(100, 80);
	button2->setSize(100, 80);
	button3->setSize(100, 80);

	button4->setSize(100, 80);
	button5->setSize(100, 80);
	button6->setSize(100, 80);

	button7->setSize(100, 80);
	button8->setSize(100, 80);
	button9->setSize(100, 80);

	button_extend->setSize(100, 80);
	button0->setSize(100, 80);
	button_del->setSize(100, 80);

	// Add the ButtonActionListener to the buttons action listeners
	button1->addActionListener(this);
	button2->addActionListener(this);
	button3->addActionListener(this);
	button4->addActionListener(this);
	button5->addActionListener(this);
	button6->addActionListener(this);
	button7->addActionListener(this);
	button8->addActionListener(this);
	button9->addActionListener(this);
	button_extend->addActionListener(this);
	button0->addActionListener(this);
	button_del->addActionListener(this);
	
}

T9Emulator::~T9Emulator()
{
	/*
	* Destroy Guichan stuff
	*/
	delete ttf_font;

	/*
	* Widgets
	*/
	delete textBox;
	delete textBoxScrollArea;

	delete button1;
	delete button2;
	delete button3;

	delete button4;
	delete button5;
	delete button6;

	delete button7;
	delete button8;
	delete button9;

	delete button_extend;
	delete button0;
	delete button_del;

	/*
	* Destroy SDL stuff
	*/
	TTF_Quit();
}


void T9Emulator::action(const gcn::ActionEvent& actionEvent)
{
	clock_t clk_current = clock();
	void* btn_current = actionEvent.getSource();
	
	/* 
	* initialize for new press 
	*/
	if (press_count == 0 || clk_current - clk_old > 500 || btn_current != btn_old)
	{
		clk_old = clk_current;
		press_count = 0;
		str_done = textBox->getText();
	}
	// the following control logics can dynamically modify themselves to btn*_text[status]

	/* functional buttons : 
	*	extends(switch mod), 
	*	del(delete last character).
	*/
	if (actionEvent.getSource() == button_extend)
	{
		status = (status + 1) % 4;
		std::cout <<"status: "<< status <<"  mod: "<<btn_extend_caption[status]<< std::endl;
		button0->setCaption(btn0_caption[status]);
		button1->setCaption(btn1_caption[status]);
		button2->setCaption(btn2_caption[status]);
		button3->setCaption(btn3_caption[status]);
		button4->setCaption(btn4_caption[status]);
		button5->setCaption(btn5_caption[status]);
		button6->setCaption(btn6_caption[status]);
		button7->setCaption(btn7_caption[status]);
		button8->setCaption(btn8_caption[status]);
		button9->setCaption(btn9_caption[status]);
		button_extend->setCaption(btn_extend_caption[status]);
	}
	else if (actionEvent.getSource() == button_del)
	{
		if (press_count++ < 3)
			textBox->setText(textBox->getText().substr(0, textBox->getText().length() - 1));
		else
			textBox->setText("");
	}


	/*
	* INPUT buttons
	*/
	if (actionEvent.getSource() == button1)
	{
		textBox->setText(str_done + btn1_text[status][press_count++ % btn1_text[status].length()]);
		if (btn1_text[status].length() == 1)
			str_done = textBox->getText();
	}
	else if (actionEvent.getSource() == button2)
	{
		textBox->setText(str_done + btn2_text[status][press_count++ % btn2_text[status].length()]);
		if (btn2_text[status].length() == 1)
			str_done = textBox->getText();
	}
	else if (actionEvent.getSource() == button3)
	{
		textBox->setText(str_done + btn3_text[status][press_count++ % btn3_text[status].length()]);
		if (btn3_text[status].length() == 1)
			str_done = textBox->getText();
	}
	else if (actionEvent.getSource() == button4)
	{
		textBox->setText(str_done + btn4_text[status][press_count++ % btn4_text[status].length()]);
		if (btn4_text[status].length() == 1)
			str_done = textBox->getText();
	}
	else if (actionEvent.getSource() == button5)
	{
		textBox->setText(str_done + btn5_text[status][press_count++ % btn5_text[status].length()]);
		if (btn5_text[status].length() == 1)
			str_done = textBox->getText();
	}
	else if (actionEvent.getSource() == button6)
	{
		textBox->setText(str_done + btn6_text[status][press_count++ % btn6_text[status].length()]);
		if (btn6_text[status].length() == 1)
			str_done = textBox->getText();
	}
	else if (actionEvent.getSource() == button7)
	{
		textBox->setText(str_done + btn7_text[status][press_count++ % btn7_text[status].length()]);
		if (btn7_text[status].length() == 1)
			str_done = textBox->getText();
	}
	else if (actionEvent.getSource() == button8)
	{
		textBox->setText(str_done + btn8_text[status][press_count++ % btn8_text[status].length()]);
		if (btn8_text[status].length() == 1)
			str_done = textBox->getText();
	}
	else if (actionEvent.getSource() == button9)
	{
		textBox->setText(str_done + btn9_text[status][press_count++ % btn9_text[status].length()]);
		if (btn9_text[status].length() == 1)
			str_done = textBox->getText();
	}
	else if (actionEvent.getSource() == button0)
	{
		textBox->setText(str_done + btn0_text[status][press_count++ % btn0_text[status].length()]);
		if (btn0_text[status].length() == 1)
			str_done = textBox->getText();
	}
	clk_old = clk_current;	// update old clock
	btn_old = btn_current;	// update old button ptr
}

