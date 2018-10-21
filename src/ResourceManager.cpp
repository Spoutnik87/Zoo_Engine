#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "ResourceManager.h"
#include "Game.h"

using namespace std;

namespace fs = boost::filesystem;

ResourceManager::ResourceManager() {
    Game::instance()->getLogger()->info("Chargement du gestionnaire de ressources.");
    fs::path path = "resources";
    // Check if folders exists and create folders
    if (!fs::exists(path)) {
        Game::instance()->getLogger()->info("Le dossier des ressources n'existe pas. Le dossier est en cours de création...");
        fs::create_directory(path);
        fs::create_directory(path.string() + "/models");
        fs::create_directory(path.string() + "/audio");
        fs::create_directory(path.string() + "/worlds");
        saveTextFile(path.string() + "/config.json", "{}");
        Game::instance()->getLogger()->info("Le dossier des ressources a été créé.");
    }
}

ResourceManager::~ResourceManager() {}

void ResourceManager::saveTextFile(string const& path, string const& content) {
    ofstream fs;
    fs.open(path);
    fs << content;
    fs.close();
}

void ResourceManager::saveJsonFile(string const& path, boost::property_tree::ptree const& pt) {
    boost::property_tree::json_parser::write_json(path, pt);
}

void ResourceManager::saveBinaryFile(string const& path) {}

string ResourceManager::loadTextFile(string const& path) {
    std::ifstream file(path);
    string content = "";
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            content += line;
        }
        file.close();
    }
    return content;
}

boost::property_tree::ptree ResourceManager::loadJsonFile(string const& path) {
    boost::property_tree::ptree pt;
    boost::property_tree::read_json(path, pt);
    return pt;

}
void ResourceManager::saveConfig(boost::property_tree::ptree const& pt) {
    saveJsonFile("resources/config.json", pt);
}

boost::property_tree::ptree ResourceManager::loadConfig() {
    return loadJsonFile("resources/config.json");
}