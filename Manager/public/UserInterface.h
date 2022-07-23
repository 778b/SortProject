#pragma once

#include "Output.h"
#include "SortFactory.h"
#include "SortResult.h"
#include "SortTarget.h"
#include "ctime"
#include <string>
#include <map>


/*
*	Last bit for execution command(exit from InputLoop())
*	enum & 1 = exit from loop
*/
enum EInput : std::int8_t
{
	EXIT	= 0b0000001,
	HELP	= 0b0000010,
	//		= 0b0000011,
	//		= 0b0000100,
	START	= 0b0000101,
	//		= 0b0000110,
	//		= 0b0000111,
	//		= 0b0001000,
	SAVES	= 0b0001001,
	SORT	= 0b0001010,
	INCORR	= 0b1000010,
};

enum class EProgram
{
	MENU		= 0,
	PREPARING	= 1,
	SORTING		= 2,
	RESULTING	= 3 
};

/*	
*	Cant initialize other factory
*	Like singltone but better for this task
*/
namespace _Initializer
{
	void InitializeSortManager();
	void DeleteSortManager();

	static SortFactory* FactoryPtr;
	static SortBase* SortPtr;
	static SortTarget* ArrayPtr;

	static EProgram ProgramState;

}

namespace _InputCommand
{
	static std::map<std::string, int> Commands = { std::pair<std::string, int>("exit",				EInput::EXIT),
													std::pair<std::string, int>("help",				EInput::HELP),
													std::pair<std::string, int>("start",			EInput::START),
													std::pair<std::string, int>("sortlist",			EInput::SORT),
													std::pair<std::string, int>("savelist",			EInput::SAVES),
	};

	void ShowStartUpMessage();
	void ShowResultMessage(SortResult& result);

	void ShowCommands();
	void ShowSorts(SortFactory* factory);

	EInput InputCommand(std::string word);
	void ExecuteCommand(int index);
	void SetArrayToSort();

	void ProgramLoop();
	void SavesLoop(bool edit);

	void SelectSort();
	void ShowArray();
};

