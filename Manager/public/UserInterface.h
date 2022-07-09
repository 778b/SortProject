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
*/
enum EInput : std::int8_t
{
	INCORR	= 0b1000010,
	EXIT	= 0b0000001,
	HELP	= 0b0000010,
	START	= 0b0000101,
	SORT	= 0b0001010,
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
													std::pair<std::string, int>("sorts",			EInput::SORT),
	};

	void ShowStartUpMessage();
	void ShowResultMessage(SortResult& result);

	void ShowCommands();
	void ShowSorts(SortFactory* factory);

	EInput InputCommand(std::string word);
	void ExecuteCommand(int index);

	void ProgramLoop();

	void SelectSort();
	void ShowArray();
};

