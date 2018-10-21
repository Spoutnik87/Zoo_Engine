#ifndef ZOOENGINE_CONTEXT_H
#define ZOOENGINE_CONTEXT_H

#include <SFML/Graphics.hpp>

class Context {
    public:
        Context();
        ~Context();
        void open();
        void clear();
        void close();
        void display();
        bool isOpen();
        void processEvents();
        void setBackgroundColor(sf::Color const& color);

    private:
        sf::RenderWindow *window;
};


#endif