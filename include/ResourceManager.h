#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>

using namespace std;

class ResourceManager {
    public:
        ResourceManager();
        void loadImage(string name);
        void loadAudio(string name);
        void loadWorld(string name);

    private:
        void loadFile(string path);
        void saveFile(string path);
};

#endif
