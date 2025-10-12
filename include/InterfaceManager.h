#ifndef INTERFACE_MANAGER_H
#define INTERFACE_MANAGER_H

enum InterfaceType {
    MAIN_MENU,
    VEHICLE_MENU,
    EXIT,
};

class InterfaceManager {
private:
    InterfaceType currentInterface;

public:
    InterfaceManager();

    void setInterface(InterfaceType newInterface);
    InterfaceType getCurrentInterface();
};

#endif
