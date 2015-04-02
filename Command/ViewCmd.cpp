#define _CRT_SECURE_NO_WARNINGS
#include "ViewCmd.h"
#include "Storage.h"
#include "TaskList.h"
#include <iostream>
#include <sstream>
#include "ViewType.h"
#include "Logger.h"
#include <time.h>

const std::string ViewCmd:: NO_TASK_MESSAGE = "There is no task. Start writing one now!"; 
const std::string ViewCmd:: INVALID_INPUT_MESSAGE = "Invalind input";

ViewCmd::ViewCmd(void) {
}

ViewCmd::~ViewCmd(void) {
}

void ViewCmd:: prepareDetail(std::string detail){
    _detail = detail;
}

time_t ViewCmd:: getDayPosition(int index){
	time_t curTime;
	time_t day;
	struct tm * timeinfo;
	int diff = 0;

	time (&curTime);
	timeinfo = localtime(&curTime);

	if(timeinfo->tm_wday < index){
		diff = index - timeinfo->tm_wday;
		day = curTime + diff*86400;
	}else 
	if(timeinfo->tm_wday > index && index == 0){
		diff = 7 - timeinfo->tm_wday;
		day = curTime + diff*86400;
	}else
	if(timeinfo->tm_wday > index && index != 0){
		diff = 7 - timeinfo->tm_wday + index;
		day = curTime + diff*86400;
	}else{
		day = curTime;
	}

	return day;
}

TaskList::TList ViewCmd:: getSelectedTasks(){
	
	TaskList::TList selectedTasks;
	//get current tasks
    Storage* storage = Storage::getInstance();
    TaskList taskList = storage->getTaskList();
	
	 ViewType = ViewType::determineViewType(_detail);  
	 switch (ViewType) {
        case ViewType::SUNDAY: {
			time_t day = getDayPosition(0);
			selectedTasks = taskList.getDay(day);
			return selectedTasks;
		}
		case ViewType::MONDAY: {
			time_t day = getDayPosition(1);
			selectedTasks = taskList.getDay(day);
			return selectedTasks;
        }
		case ViewType::TUESDAY: {
			time_t day = getDayPosition(2);
			selectedTasks = taskList.getDay(day);
			return selectedTasks;
        }
		case ViewType::WEDNESDAY: {
			time_t day = getDayPosition(3);
			selectedTasks = taskList.getDay(day);
			return selectedTasks;
        }
		case ViewType::THURSDAY: {
			time_t day = getDayPosition(4);
			selectedTasks = taskList.getDay(day);
			return selectedTasks;
        }
		case ViewType::FRIDAY: {
			time_t day = getDayPosition(5);
			selectedTasks = taskList.getDay(day);
			return selectedTasks;
        }
		case ViewType::SATURDAY: {
			time_t day = getDayPosition(6);
			selectedTasks = taskList.getDay(day);
			return selectedTasks;
        }
		case ViewType::ALL: {
			selectedTasks = taskList.getAll();
			return selectedTasks;
        }
		case ViewType::TODAY: {
			selectedTasks = taskList.getToday();
			return selectedTasks;
        }
		case ViewType::TOMORROW: {
			selectedTasks = taskList.getTomorrow();
			return selectedTasks;
        }
		case ViewType::WEEKLY: {
			selectedTasks = taskList.getWeekly();
			return selectedTasks;
        }
		case ViewType::INVALID: {
			return selectedTasks;
        }
		default :{
			return selectedTasks;
		 }
	 }
}


UIObject ViewCmd::execute() {
	std:: string header;
	TaskList::TList selectedTasks;
	selectedTasks = getSelectedTasks();
   
    UIObject viewObj;
	if(!selectedTasks.empty()){
		viewObj.setTaskList(selectedTasks);
	} else
	if(selectedTasks.empty() && ViewType == 11){
		viewObj.setHeaderText(INVALID_INPUT_MESSAGE);
	}else{
		viewObj.setHeaderText(NO_TASK_MESSAGE);
	}
	return viewObj;
}

