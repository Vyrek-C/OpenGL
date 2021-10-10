#include <Terrain/Terrain.h>

Terrain::Terrain(int gridX, int gridZ, int seed)
{
    xSize = gridX;
    zSize = gridZ;
    perlinNoise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    perlinNoise.SetSeed(seed);
}


std::vector<unsigned int> Terrain::GenerateTerrain(std::vector<glm::vec3> &verticies)
{

    for(int i = 0, z = 0; z <= zSize; z++)
    {
        for (int x = 0; x <= xSize; x++)
        {
            verticies.push_back(glm::vec3(x, perlinNoise.GetNoise((float)x, (float)z), z));
            i++;
        }
    }
    std::vector<unsigned int> indicies(xSize*zSize*6);
    int vert = 0;
    int tris = 0;

    for(int z = 0; z < zSize; z++)
    {
        for (int x = 0; x < xSize; x++)
        {
            indicies[tris + 0] = vert + 0;
            indicies[tris + 1] = vert + xSize + 1;
            indicies[tris + 2] = vert + 1;
            indicies[tris + 3] = vert + 1;
            indicies[tris + 4] = vert + xSize + 1;
            indicies[tris + 5] = vert + xSize + 2;
            vert++;
            tris += 6;
        }
        vert++;
    }
    return indicies;
}

