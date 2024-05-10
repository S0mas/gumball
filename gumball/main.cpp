#include "vendingmachine.h"

int main()
{
    VendingMachine::VendingMachine m;
    m.handleEvent(VendingMachine::Events::COIN_INSERTED);
    m.handleEvent(VendingMachine::Events::PRODUCT_PRESSED);
    m.handleEvent(VendingMachine::Events::VENDING_COMPLETE);

    return 0;
}
