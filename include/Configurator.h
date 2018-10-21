#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include <boost/property_tree/ptree.hpp>

class Configurator {
    public:
        Configurator();
        ~Configurator();
        void setWindowX(int x);
        int getWindowX();
        void setWindowY(int y);
        int getWindowY();
        boost::property_tree::ptree getDefault();
        enum Element {
            WindowX = 0,
            WindowY = 1
        };

    private:
        boost::property_tree::ptree pt;
        std::string getPropertyName(Element const& elem);
        template<typename T>
        void set(Element const& elem, T const& value);
        template<typename T>
        T get(Element const& elem);
        void save();
};

#endif