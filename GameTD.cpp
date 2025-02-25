#include "Input.h"
#include "Tour.h"
#include "Ennemie.h"
#include "test.h"
#include <thread>


int main(){
	GUI* gui = new GUI();
	std::thread t1(&Input::input, gui);
	//test.checkKey();
	
				//METTRE LE JEU ICI

	FIN = true;
	t1.join();
return 0;
}
