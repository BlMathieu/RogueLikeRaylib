#include <raylib.h>
#include <vector>
class AbstractData {
    private:
    char* url;
    protected:
    Texture2D texture;
    float tileSize;
    std::vector<Rectangle> tiles;
    std::vector<std::vector<int>> map;
    
    public:
    AbstractData(char* url, float tileSize);
    void loadTexture();
    void draw();
    void drawDebugTiles();
};