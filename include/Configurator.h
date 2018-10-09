#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include <string>
#include <unordered_map>

//All config
#define CONFIG_RESOLUTION_X "resolution_x"
#define CONFIG_RESOLUTION_Y "resolution_y"

class Configurator
{
public:
    Configurator();
    Configurator(std::string const& file);
    ~Configurator();

    void set(std::string const& key, std::string const& value);
    std::string get(std::string const& key);
    void save();

private:
    std::string file;
    std::unordered_map<std::string, std::string> config;
};

#endif