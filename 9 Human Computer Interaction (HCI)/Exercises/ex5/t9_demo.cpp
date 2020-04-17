/*****************************************************************
 T9_demo.cpp	[main program]
	An T9 keyboard emulator program with mod switching ability.
		1427405017
		Jiayun Shen
		2016-12-10
******************************************************************/
#include <iostream>
#include <guisan.hpp>
#include <guisan/sdl.hpp>
#include <guisan/sdl/sdltruetypefont.hpp>
#include "SDL.h"
#include "T9Emulator.h" 

using namespace gcn;

/*
* Common stuff we need
*/
bool running = true;

/*
* SDL Stuff we need
*/
SDL_Window* sdlWindow;
SDL_Surface* sdlScreen;
SDL_Event event;

/*
* Guichan SDL stuff we need
*/
gcn::SDLInput* input;             // Input driver
gcn::SDLGraphics* graphics;       // Graphics driver
gcn::SDLImageLoader* imageLoader; // For loading images

/*
* Guichan stuff we need
*/
Container* top;		// ptr to T9Emulator instance
gcn::Gui* gui;      // A Gui object - binds it all together

//T9Emulator* t9emulator;

/**
* Initializes the application
*/
void
init()
{
	/*
	* Here we initialize SDL as we would do with any SDL application.
	*/
	SDL_Init(SDL_INIT_VIDEO);
	sdlWindow = SDL_CreateWindow("T9 keyboard",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 300, 500, 0);

	sdlScreen = SDL_GetWindowSurface(sdlWindow);

	// We want to enable key repeat
	//SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);

	/*
	* Now it's time for Guichan SDL stuff
	*/
	imageLoader = new gcn::SDLImageLoader();
	// The ImageLoader in use is static and must be set to be
	// able to load images
	gcn::Image::setImageLoader(imageLoader);
	graphics = new gcn::SDLGraphics();
	// Set the target for the graphics object to be the screen.
	// In other words, we will draw to the screen.
	// Note, any surface will do, it doesn't have to be the screen.
	graphics->setTarget(sdlScreen);
	input = new gcn::SDLInput();

	/*
	* Last but not least it's time to initialize and create the gui
	* with Guichan stuff.
	*/
	//top = new gcn::Container();
	top = new T9Emulator();				// ********* T9Emulator instance created here!!! ********
	// Set the dimension of the top container to match the screen.
	top->setDimension(gcn::Rectangle(0, 0, 300, 500));
	gui = new gcn::Gui();
	// Set gui to use the SDLGraphics object.
	gui->setGraphics(graphics);
	// Set gui to use the SDLInput object
	gui->setInput(input);
	// Set the top container
	gui->setTop(top);

	//top->add(t9emulator);
}

/**
* Halts the application
*/
void
halt()
{
	/*
	* Destroy Guichan SDL stuff
	*/
	//delete t9emulator;
	delete top;
	delete input;
	delete graphics;
	delete imageLoader;

	/*
	* Destroy SDL stuff
	*/
	SDL_Quit();
}

/**
* Checks input. On escape halt the application.
*/
void
checkInput()
{
	/*
	* Poll SDL events
	*/
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_ESCAPE)
				running = false;

			if (event.key.keysym.sym == SDLK_f) {
				if (event.key.keysym.mod & KMOD_CTRL) {
					// TODO: Toggle full screen
				}
			}
		}
		else if (event.type == SDL_QUIT) {
			running = false;
		}

		/*
		* Now that we are done polling and using SDL events we pass
		* the leftovers to the SDLInput object to later be handled by
		* the Gui.
		*/
		input->pushInput(event);
	}
}

/**
* Runs the application
*/
void
run()
{
	while (running) {
		// Poll input
		checkInput();
		// Let the gui perform it's logic (like handle input)
		gui->logic();
		// Draw the gui
		gui->draw();
		// Update the screen
		SDL_UpdateWindowSurface(sdlWindow);
	}
}

int
main(int argc, char **argv)
{

	try {
		init();
		run();
		halt();
	}
	/*
	* Catch all Guichan exceptions
	*/
	catch (gcn::Exception e) {
		std::cerr << e.getMessage() << std::endl;
		return 1;
	}
	/*
	* Catch all Std exceptions
	*/
	catch (std::exception e) {
		std::cerr << "Std exception: " << e.what() << std::endl;
		return 1;
	}
	/*
	* Catch all Unknown exceptions
	*/
	catch (...) {
		std::cerr << "Unknown exception" << std::endl;
		return 1;
	}

	return 0;
}