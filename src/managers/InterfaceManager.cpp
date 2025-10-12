#include "../../include/InterfaceManager.h"

InterfaceManager::InterfaceManager() {
    currentInterface = MAIN_MENU;
}

void InterfaceManager::setInterface(InterfaceType newInterface) {
    currentInterface = newInterface;
}

InterfaceType InterfaceManager::getCurrentInterface() {
    return currentInterface;
}
