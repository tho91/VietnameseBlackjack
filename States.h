

#ifndef SFML_PROJECT_STATES_H
#define SFML_PROJECT_STATES_H
#include "State.h"

class States
{
private:
    bool states[LAST];

public:
    bool isEnabled(State state);
    void enabledState(State state);
    void disableState(State state);
};

#endif //SFML_PROJECT_STATES_H
