#include "../public/UserInterface.h"
#include "../../Sorts/public/SortBase.h"

#include <vector>
#include <chrono>
#include <fstream>
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
	for (size_t i = 0; i <_ListName.size();++i)
	{
		std::cout << "\t"<< i << ")" << _ListName[i] << std::endl;
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
		return EInput::START;

	case EInput::SORT:
		ShowSorts(_Initializer::FactoryPtr);
		return EInput::SORT;

	case EInput::SAVES:
		return EInput::SAVES;

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
		SetArrayToSort();
		ShowArray();
		SelectSort();
		return;

	case EInput::SAVES:
		SavesLoop(true);
		return;
	}
}

void _InputCommand::SetArrayToSort()
{
	char tempAns;
	while (true)
	{
		std::cout << "Generate new array? (y/n): ";

		std::cin >> tempAns;
		if (tempAns == 'n' || tempAns == 'y')
		{
			if (tempAns == 'n')
			{
				SavesLoop(false);
				return;
			}
			else
			{
				// todo generate array
				return;
			}
		}
		else
		{
			std::cout << "\tWRONG CHAR!";
		}
	}

}

void _InputCommand::ProgramLoop()
{
	/*
	*	goto
	*/
menu:

	_Initializer::ProgramState = EProgram::MENU;
	int result = 0b0;
	std::string command = {""};
	while ((result & 1) != 1)
	{
		std::cin >> command;
		result = InputCommand(command);
	}
	if (result == EInput::EXIT) return;



	/*
	*	goto
	*/
preparing:		

	std::cout << OUT_SLINE;
	_Initializer::ProgramState = EProgram::PREPARING;
	ExecuteCommand(result);
	char tempAns;
	std::cout << "Start? (y/n)" << std::endl;
	std::cin >> tempAns;
	if (tempAns == 'n') goto preparing;

	std::cout << OUT_SLINE;
	_Initializer::ProgramState = EProgram::SORTING;
	SortResult _result;
	_Initializer::SortPtr->SortCycle(_Initializer::ArrayPtr, _result);

	std::cout << OUT_SLINE;
	_Initializer::ProgramState = EProgram::RESULTING;
	ShowArray();
	ShowResultMessage(_result);
}

void _InputCommand::SavesLoop(bool edit)
{
	std::ifstream AReader("SavedArray.txt");
	std::vector<std::string> BufferArray; 
	std::string buffer;

	int CountArray = 0;

	if (AReader.fail())
	{
		std::cout << "\tDIDNT FIND FILE SavedArray.txt!\n";
		return;
	}

	std::cout << OUT_SLINE;
	std::cout << "Your saved arrays:\n";
	while (!AReader.eof())
	{
		AReader >> buffer;
		std::cout << CountArray++ << ") {" << buffer << "}.\n";
		BufferArray.push_back(buffer);
	}
	AReader.close();

	if (edit)
	{
		//todo command add
		//todo command remove
		//todo generate random
	}
	else
	{
		int tempIndex;
		while (true)
		{
			std::cout << "Enter index of array: ";
			std::cin >> tempIndex;
			if (BufferArray.size() > tempIndex)
			{
				_Initializer::ArrayPtr = new SortTarget(BufferArray[tempIndex]);
				break;
			}
			else
			{
				std::cout << "\tWRONG INDEX!";
			}
		}
	}

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

