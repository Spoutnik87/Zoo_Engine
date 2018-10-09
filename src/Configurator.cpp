#include "Configurator.h"
#include <iostream>
#include <fstream>

#define DEFAULT_CONFIG "//config file ZooEngine \n\
\n\
resolution_x=1280\n\
resolution_y=720\n\
"

Configurator::Configurator()
{
    this->file = "config.cfg";

    std::fstream fs;
    std::string buffer;

    //test config file exists
    fs.open(this->file, std::fstream::in);
    fs >> buffer;
    fs.close();

    if(buffer == ""){
        fs.open(this->file, std::fstream::out);
        fs << DEFAULT_CONFIG;
        fs.close();
    }

    //load config file
    fs.open(this->file, std::fstream::in);
    
    size_t separator;
    std::string key;
    std::string value;

    while(!fs.eof())
    {
        std::getline(fs, buffer);

        if(buffer == "" || (buffer[0] == '/' && buffer[1] == '/')){
            continue;
        }

        separator = buffer.find("=");
        key = buffer.substr(0, separator);
        value = buffer.substr(separator+1, buffer.length() - separator);

        this->config[key] = value;
    }

    fs.close();
}

Configurator::Configurator(std::string const& file)
{
    this->file = file;
}

Configurator::~Configurator()
{
    
}

void Configurator::set(std::string const& key, std::string const& value)
{
    this->config[key] = value;
}

std::string Configurator::get(std::string const& key)
{
    return this->config[key];
}

void Configurator::save()
{

}