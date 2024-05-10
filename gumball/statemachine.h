#pragma once

#include <iostream>
#include <vector>

template<typename StateType, typename EventType>
class StateMachine
{
public:
    class Transition
    {
    public:
        Transition(const StateType& from, const StateType& to, const EventType& event);

        auto checkOriginState(const StateType& state) const -> bool;
        auto checkEvent(const EventType& event) const -> bool;
        auto doTransition() const -> const StateType&;

    private:
        StateType from_;
        StateType to_;
        EventType event_;
    };

    auto handleEvent(const EventType& event) -> void;
    auto findTransition(const EventType& event) const -> const Transition*;
    auto addTransition(const StateType& from, const StateType& to, const EventType& event) -> void;

protected:
    auto setInitialState(const StateType& state) -> void;

private:
    std::vector<Transition> transition_map_;
    StateType current_state_;
};

template<typename StateType, typename EventType>
auto StateMachine<StateType, EventType>::handleEvent(const EventType& event) -> void
{
    if(const auto transition = findTransition(event); transition)
    {
        const auto old_state = current_state_;
        current_state_ = transition->doTransition();
        std::cout << "----------------------------------------------->\n";
        std::cout << "Invoking transition:\nFrom: " << stateToString(old_state) << "\nTo: " << stateToString(current_state_) << "\nEvent: " << eventToString(event) << std::endl;
        std::cout << "<-----------------------------------------------\n\n";
    }
    else
    {
        std::cout << "Error, cant handle event: " << eventToString(event) << std::endl;
    }
}

template<typename StateType, typename EventType>
auto StateMachine<StateType, EventType>::findTransition(const EventType& event) const -> const Transition*
{
    const auto it = std::find_if(std::begin(transition_map_),
                                 std::end(transition_map_),
                                 [this, event](const auto &transition) {
                                     return transition.checkOriginState(current_state_)
                                            && transition.checkEvent(event);
                                 });
    return it != std::end(transition_map_) ? &(*it) : nullptr;
}

template<typename StateType, typename EventType>
auto StateMachine<StateType, EventType>::addTransition(const StateType& from, const StateType& to, const EventType& event) -> void
{
    transition_map_.push_back({from, to, event});
}

template<typename StateType, typename EventType>
auto StateMachine<StateType, EventType>::setInitialState(const StateType& state) -> void
{
    current_state_ = state;
}

///////////////////////////////// TRANSITION

template<typename StateType, typename EventType>
StateMachine<StateType, EventType>::Transition::Transition(const StateType& from, const StateType& to, const EventType& event)
    : from_{from}
    , to_{to}
    , event_{event}
{
}

template<typename StateType, typename EventType>
auto StateMachine<StateType, EventType>::Transition::checkOriginState(const StateType& state) const -> bool
{
    return from_ == state;
}

template<typename StateType, typename EventType>
auto StateMachine<StateType, EventType>::Transition::checkEvent(const EventType& event) const -> bool
{
    return event_ == event;
}

template<typename StateType, typename EventType>
auto StateMachine<StateType, EventType>::Transition::doTransition() const -> const StateType&
{
    return to_;
}
