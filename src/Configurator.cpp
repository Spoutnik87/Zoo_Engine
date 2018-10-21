#include "Configurator.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "Game.h"

Configurator::Configurator() {
    boost::property_tree::ptree config = Game::instance()->getResourceManager()->loadConfig();
    if (config.empty()) {
        Game::instance()->getLogger()->info("Chargement de la configuration par défaut.");
        pt = getDefault();
    }
    else {
        Game::instance()->getLogger()->info("Chargement du fichier de configuration.");
        pt = config;
    }
    save();
}

Configurator::~Configurator() {}


void Configurator::setWindowX(int x) {
    set(Element::WindowX, x);
}

int Configurator::getWindowX() {
    return get<int>(Element::WindowX);
}

void Configurator::setWindowY(int y) {
    set(Element::WindowY, y);
}

int Configurator::getWindowY() {
    return get<int>(Element::WindowY);
}

template<typename T>
void Configurator::set(Element const& elem, T const& value) {
    pt.put(getPropertyName(elem), value);
    save();
}

template<typename T>
T Configurator::get(Element const& elem) {
    string key = getPropertyName(elem);
    try {
        return pt.get<T>(key);
    } catch (boost::property_tree::ptree_bad_path error) {
        return getDefault().get<T>(key);
    }
}

void Configurator::save() {
    Game::instance()->getResourceManager()->saveConfig(pt);
}

boost::property_tree::ptree Configurator::getDefault() {
    boost::property_tree::ptree config;
    config.put(getPropertyName(Element::WindowX), 1280);
    config.put(getPropertyName(Element::WindowY), 720);
    return config;
}

string Configurator::getPropertyName(Element const& elem) {
    string name;
    switch(elem) {
        case WindowX:
            name = "window.x";
            break;
        case WindowY:
            name = "window.y";
            break;
    }
    return name;
}