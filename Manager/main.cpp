#include "../Manager/public/UserInterface.h"


int main()
{
	_Initializer::InitializeSortManager();
	_InputCommand::ProgramLoop();
	_Initializer::DeleteSortManager();
}