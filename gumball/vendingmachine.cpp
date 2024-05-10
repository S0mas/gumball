#include "vendingmachine.h"

namespace VendingMachine
{

VendingMachine::VendingMachine()
{
    addTransition(States::IDLE, States::READY, Events::COIN_INSERTED);
    addTransition(States::READY, States::IDLE, Events::COIN_RETURN);
    addTransition(States::READY, States::VENDING, Events::PRODUCT_PRESSED);
    addTransition(States::VENDING, States::IDLE, Events::VENDING_COMPLETE);

    addTransition(States::IDLE, States::FAULT, Events::GENERIC_FAULT);
    addTransition(States::READY, States::FAULT, Events::GENERIC_FAULT);
    addTransition(States::READY, States::FAULT, Events::GENERIC_FAULT);
    addTransition(States::VENDING, States::FAULT, Events::GENERIC_FAULT);

    setInitialState(States::IDLE);
}

}
