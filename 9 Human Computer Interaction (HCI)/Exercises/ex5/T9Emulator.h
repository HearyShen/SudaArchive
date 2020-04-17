/*****************************************************************
 T9Emulator.h		[declaration of class T9Emulator]
	An T9 keyboard emulator program with mod switching ability.
		1427405017
		Jiayun Shen
		2016-12-10
******************************************************************/
#ifndef T9EMULATOR_H
#define T9EMULATOR_H

// Include all necessary headers.
#include <iostream>
#include <guisan.hpp>
#include <guisan/sdl.hpp>
#include <guisan/sdl/sdltruetypefont.hpp>
#include "SDL.h"

class T9Emulator : public gcn::Container, public gcn::ActionListener
{
public:
	T9Emulator();
	~T9Emulator();
	void action(const gcn::ActionEvent & actionEvent);

protected:
	/*
	* Common stuff we need
	*/
	bool running = true;

	gcn::SDLTrueTypeFont* ttf_font;

	/* my guisan widgets below */
	gcn::TextBox* textBox;
	gcn::ScrollArea* textBoxScrollArea;  // Scroll area for the text box
	gcn::Button* button1;
	gcn::Button* button2;
	gcn::Button* button3;
	gcn::Button* button4;
	gcn::Button* button5;
	gcn::Button* button6;
	gcn::Button* button7;
	gcn::Button* button8;
	gcn::Button* button9;
	gcn::Button* button_extend;
	gcn::Button* button0;
	gcn::Button* button_del;

	/*
	* btn*_caption provide the button caption for mod[status].
	* with the support of std::string,
	* ButtonActionListener is able to fit btn*_caption dynamically.
	*/
	std::string btn1_caption[4] = { "1*#", "1*#", "1", "," };
	std::string btn2_caption[4] = { "2 abc", "2 ABC", "2", "." };
	std::string btn3_caption[4] = { "3 def", "3 DEF", "3", "?" };
	std::string btn4_caption[4] = { "4 ghi", "4 GHI", "4", "!" };
	std::string btn5_caption[4] = { "5 jkl", "5 JKL", "5", "+" };
	std::string btn6_caption[4] = { "6 mno", "6 MNO", "6", "-" };
	std::string btn7_caption[4] = { "7 pqrs", "7 PQRS", "7", "_" };
	std::string btn8_caption[4] = { "8 tuv", "8 TUV", "8", "/" };
	std::string btn9_caption[4] = { "9 wxyz", "9 WXYZ", "9", "'" };
	std::string btn_extend_caption[4] = { "en", "EN", "123", ",.?!" };
	std::string btn0_caption[4] = { "0 spc", "0 spc", "0", "=" };

	/*
	* btn*_text provide the input source.
	* with the support of std::string,
	* ButtonActionListener is able to fit btn*_text dynamically.
	*/
	std::string btn1_text[4] = { "1*#", "1*#", "1", "," };
	std::string btn2_text[4] = { "abc", "ABC", "2", "." };
	std::string btn3_text[4] = { "def", "DEF", "3", "?" };
	std::string btn4_text[4] = { "ghi", "GHI", "4", "!" };
	std::string btn5_text[4] = { "jkl", "JKL", "5", "+" };
	std::string btn6_text[4] = { "mno", "MNO", "6", "-" };
	std::string btn7_text[4] = { "pqrs", "PQRS", "7", "_" };
	std::string btn8_text[4] = { "tuv", "TUV", "8", "/" };
	std::string btn9_text[4] = { "wxyz", "WXYZ", "9", "'" };
	std::string btn_extend_text[4] = { "en", "EN", "123", ",.?!" };
	std::string btn0_text[4] = { " ", " ", "0", "=" };

	clock_t clk_old;	// clk_0 (ms)->button
	int press_count;
	void* btn_old;
	std::string str_done;
	int status;
};


#endif