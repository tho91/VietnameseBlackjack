#include "States.h"

bool States::isEnabled(State state)
{
    return states[state];
}

void States::enabledState(State state)
{
    states[state] = true;
}

void States::disableState(State state)
{
    states[state] = false;
}