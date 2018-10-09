#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include "Game.h"
#include "Logger.h"
#include "Configurator.h"

int main() {
    Configurator config = Configurator();

    Game game = Game();
    sf::RenderWindow window(sf::VideoMode(
        std::stoi(config.get(CONFIG_RESOLUTION_X)),
        std::stoi(config.get(CONFIG_RESOLUTION_Y))), "ZooEngine");
    
    float t = 0.0;
    float dt = 0.01;
    float currentTime = sf::Time().asSeconds();   
    float accumulator = 0.0;

    // Boucle de jeu à temps fixe + interpolation.
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        game.getLogger()->info("a");
        Command* command = game.getInputHandler()->handleInput();

        float newTime = sf::Time().asSeconds();
        float frameTime = newTime - currentTime;
        if (frameTime > 0.25) {
            frameTime = 0.25;
        }
        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= dt)
        {
            //previousState = currentState;
            //integrate(currentState, t, dt);
            t += dt;
            accumulator -= dt;
        }

        const double alpha = accumulator / dt;

        //State state = currentState * alpha + previousState * ( 1.0 - alpha );

        //render(state);

        window.clear();
        window.display();
    }
    return 0;
}


/*
Boucle de jeu experimental. WIP.

    float t = 0.0;
    float dt = 0.01;
    float currentTime = sf::Time().asSeconds();   
    float accumulator = 0.0;
    //State previous
    //State current

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        game.getLogger()->info("a");
        Command* command = game.getInputHandler()->handleInput();

        float newTime = sf::Time().asSeconds();
        float frameTime = newTime - currentTime;
        if (frameTime > 0.25) {
            frameTime = 0.25;
        }
        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= dt)
        {
            //previousState = currentState;
            //integrate(currentState, t, dt);
            t += dt;
            accumulator -= dt;
        }

        const double alpha = accumulator / dt;

        //State state = currentState * alpha + previousState * ( 1.0 - alpha );

        //render(state);



        window.clear();
        window.display();
    }

*/

    /*


     using clock = std::chrono::high_resolution_clock;
    std::chrono::nanoseconds lag(0ns);
    auto time_start = clock::now();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        game.getLogger()->info("a");
        Command* command = game.getInputHandler()->handleInput();

        auto delta_time = clock::now() - time_start;
        time_start = clock::now();
        lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);

        while(lag >= timestep) {
            lag -= timestep;

            //previous_state = current_state;
            //update(&current_state); // update at a fixed rate each time
        }

            // calculate how close or far we are from the next timestep
            auto alpha = (float) lag.count() / timestep.count();
            //auto interpolated_state = interpolate(current_state, previous_state, alpha);

        //render(interpolated_state);

        window.clear();
        window.display();
    }*/
