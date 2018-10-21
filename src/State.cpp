#include "State.h"

State::State(State::StateId stateId) {
    this->stateId = stateId;
}

State::~State() {}

State::StateId State::getId() const {
    return this->stateId;
}