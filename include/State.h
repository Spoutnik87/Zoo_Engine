#ifndef ZOOENGINE_STATE_H
#define ZOOENGINE_STATE_H


class State {
    public:
        enum StateId {
            MAIN_MENU = 0,
            GAME = 1
        };

        State(StateId stateId);
        ~State();
        StateId getId() const;
        virtual void setup() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;

    private:
        StateId stateId;
};


#endif
