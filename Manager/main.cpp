#include "../Manager/public/UserInterface.h"

/*	ROADMAP
* 
*		
*	Use chrono for timer managment				- complete
*	Read/Write arrays from files
*	Create new arrays with random 
*	predicates
*	class for command for multi commands			
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
*/



int main()
{
	_Initializer::InitializeSortManager();
	_InputCommand::ProgramLoop();
	_Initializer::DeleteSortManager();
}