#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include <string>
#include <unordered_map>

class Configurator
{
public:
    Configurator();
    Configurator(std::string const& file);
    ~Configurator();

    enum ConfigTypes
    {
        RESOLUTION_X,
        RESOLUTION_Y
    };

    static ConfigTypes types;

    void set(std::string const& key, std::string const& value);
    std::string get(std::string const& key);
    void save();

private:
    std::string file;
    std::unordered_map<ConfigTypes, std::string> config;
};

#endif