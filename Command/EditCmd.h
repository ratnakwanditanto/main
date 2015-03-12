#pragma once
#include "commandinterface.h"
class EditCmd : public CommandInterface {
public:
    EditCmd(void);
    ~EditCmd(void);
    void prepareTask(Task task);
    UIObject execute();

private:
    Task _task;
};