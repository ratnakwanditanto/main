//@author A0086626W

#include "CommandInterface.h"

CommandInterface::CommandInterface(void) {
}


CommandInterface::~CommandInterface(void) {
}

UIObject CommandInterface::undo() {
    UIObject noUndo;
    noUndo.setHeaderText("No more actions to undo.");
    return noUndo;
}