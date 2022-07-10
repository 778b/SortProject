#include "../public/UserInterface.h"
#include "../../Sorts/public/SortBase.h"

#include <chrono>
#include <iostream>

void _Initializer::InitializeSortManager()
{
	FactoryPtr = new SortFactory();
	FactoryPtr->RegisterAllSort();
	_InputCommand::ShowStartUpMessage();
	return;
}

void _Initializer::DeleteSortManager()
{
	delete FactoryPtr;
	delete ArrayPtr;
}

void _InputCommand::ShowStartUpMessage()
{
	std::cout << OUT_SLINE;
	std::cout << "SORT_MANAGER v 1.0.0: \v \n";
	std::cout << OUT_SLINE;
	std::cout << "TYPE help TO GET COMMAND LIST.\n";
	
}

void _InputCommand::ShowResultMessage(SortResult& result)
{
	std::chrono::duration<double> ExecutionTime = result.EndTime - result.StartTime;
	std::cout << OUT_SLINE;
	std::cout << "TIME TO SORT: " << ExecutionTime.count() << "'s\n";
	std::cout << "COUNT OF MOVES: " << result.Moves << " swaps\n";
}

void _InputCommand::ShowCommands()
{
	std::cout << "COMMAND LIST:\n";
	for (auto command : Commands)
	{
		std::cout << "\t\t" << command.first << std::endl;
	}
	std::cout << "END COMMAND LIST.\n";
}

void _InputCommand::ShowSorts(SortFactory* factory)
{
	std::vector<std::string> _ListName;
	factory->GetNamesAllSorts(_ListName);
	std::cout << "SORT LIST:\n";
	for (auto& tempsort : _ListName)
	{
		std::cout << "\t\t" << tempsort << std::endl;
	}
	std::cout << "END SORT LIST:\n";
}

EInput _InputCommand::InputCommand(std::string word)
{
	auto tempcommand = Commands.find(word);
	if (tempcommand == Commands.end())
	{
		WRONG_COMMAND(word);
		return EInput::INCORR;
	}

	switch (tempcommand->second)
	{
	case EInput::EXIT:
		return EInput::EXIT;

	case EInput::HELP:
		ShowCommands();
		return EInput::HELP;

	case EInput::START:
		std::cout << "START" << std::endl;
		return EInput::START;

	case EInput::SORT:
		ShowSorts(_Initializer::FactoryPtr);
		return EInput::SORT;

	default:
		return EInput::INCORR;
	}
}

void _InputCommand::ExecuteCommand(int index)
{
	switch (index)
	{
	case EInput::EXIT:
		return;

	case EInput::START:

		return;
	}
}

void _InputCommand::ProgramLoop()
{
	_Initializer::ProgramState = EProgram::MENU;
	int result = 0b0;
	std::string command = {""};
	while ((result & 1) != 1)
	{
		std::cin >> command;
		result = InputCommand(command);
	}
	if (result == EInput::EXIT) return;

	std::cout << OUT_SLINE;
	_Initializer::ProgramState = EProgram::PREPARING;
	ExecuteCommand(result);
	_Initializer::ArrayPtr = new SortTarget(12, true);
	ShowArray();
	SelectSort();
	int tempAns;
	std::cout << "PRESS ANY KEY TO START:)" << std::endl;
	std::cin >> tempAns;

	std::cout << OUT_SLINE;
	_Initializer::ProgramState = EProgram::SORTING;
	SortResult _result;
	_Initializer::SortPtr->SortCycle(_Initializer::ArrayPtr, _result);

	std::cout << OUT_SLINE;
	_Initializer::ProgramState = EProgram::RESULTING;
	ShowArray();
	ShowResultMessage(_result);
}

void _InputCommand::SelectSort()
{
	int index;
	ShowSorts(_Initializer::FactoryPtr);
	while (true)
	{
		std::cout << "SELECT SORT: ";
		std::cin >> index;
		if (index < _Initializer::FactoryPtr->GetSortCount())
		{
			_Initializer::SortPtr = _Initializer::FactoryPtr->GetSort(index);
			break;
		}
		else
		{
			std::cout << "WRONG INDEX, TRY AGAIN.";
		}
	}
	std::cout << "SELECTED SORT: " << _Initializer::SortPtr->SortName << std::endl;
}

void _InputCommand::ShowArray()
{
	std::cout << "Array: { " << _Initializer::ArrayPtr->GetArray() <<" }\n";
}

