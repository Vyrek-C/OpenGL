#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/range.hpp>
#include <glm/gtc/random.inl>
#include <Noise/FastNoiseLite.h>


class Terrain
{

public:
    Terrain(int gridX, int gridZ, int seed);
    std::vector<unsigned int> GenerateTerrain(std::vector<glm::vec3> &verticies);

private:
    int xSize, zSize;
    int triangleIndex = 0;
    int vert = 0;
    std::vector<unsigned int> indicies;
    FastNoiseLite perlinNoise;
    void AddTriangle(int a, int b, int c);
};
