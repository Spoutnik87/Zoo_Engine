#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>
#include <boost/property_tree/ptree.hpp>

using namespace std;

class ResourceManager {
    public:
        ResourceManager();
        ~ResourceManager();
        void loadImage(string name);
        void loadAudio(string name);
        void loadWorld(string name);
        boost::property_tree::ptree loadConfig();
        void saveConfig(const boost::property_tree::ptree &pt);

    private:
        string loadTextFile(string const& path);
        boost::property_tree::ptree loadJsonFile(string const& path);
        void saveTextFile(string const& path, string const& content);
        void saveBinaryFile(string const& path);
        void saveJsonFile(string const& path, boost::property_tree::ptree const& pt);
};

#endif
