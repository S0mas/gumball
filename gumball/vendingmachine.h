#pragma once

#include "statemachine.h"

namespace VendingMachine
{

enum class States
{
    IDLE,
    READY,
    VENDING,
    FAULT
};

enum class Events
{
    COIN_INSERTED,
    COIN_RETURN,
    VENDING_COMPLETE,
    PRODUCT_PRESSED,
    GENERIC_FAULT
};

inline std::string stateToString(States state)
{
    switch(state)
    {
    case States::IDLE:
        return "IDLE";
    case States::READY:
        return "READY";
    case States::VENDING:
        return "VENDING";
    case States::FAULT:
        return "FAULT";
    }
    return "UNKNOWN";
}

inline std::string eventToString(Events event)
{
    switch(event)
    {
    case Events::COIN_INSERTED:
        return "COIN_INSERTED";
    case Events::COIN_RETURN:
        return "COIN_RETURN";
    case Events::VENDING_COMPLETE:
        return "VENDING_COMPLETE";
    case Events::PRODUCT_PRESSED:
        return "PRODUCT_PRESSED";
    case Events::GENERIC_FAULT:
        return "GENERIC_FAULT";
    }
    return "UNKNOWN";
}

class VendingMachine final : public StateMachine<States, Events>
{
public:
    VendingMachine();
};

}
