#pragma once
#include <string>
#include "UIObject.h"

class TextUI
{

private:
	static const std::string WELCOME_MSG;
	static const std::string HELP_MSG;
	static const std::string UNSCHEDULED_DATE_BAR;
	static std::string QUALIFIER_DATE_BAR;
	static std::string DEFAULT_DATE_BAR;
	static std:: string NO_SCHEDULE;

    static struct tm convertToLocalTime(const time_t &taskDate); 
	static bool isUnscheduled(const time_t &taskDate);
	static std::string getWkDayName(const time_t &taskDate);
	static std::string getMonthName(const time_t &taskDate);
    static std::string getTimeName(const time_t &taskDate);
	static std::string getQualifierName(const time_t &taskDate);
	static void printDateBar(const time_t &taskDate);
	static void printTasks(TaskList::TList tasks);
	static void printPrevious(Task task);

public:
	static void printWelcomeMsg();
	static void printHelp();

	static std::string getInput();
	static void showOutput(UIObject uiObj);

	TextUI(void);
	~TextUI(void);
};

