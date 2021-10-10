#include <Terrain/Terrain.h>

Terrain::Terrain(int gridX, int gridZ, int seed)
{
    xSize = gridX;
    zSize = gridZ;
    perlinNoise.SetSeed(seed);
    perlinNoise.SetFrequency(0.5f);
    perlinNoise.SetFractalOctaves(3);
    perlinNoise.SetFractalLacunarity(5.f);
    perlinNoise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
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
    int currVert = 0;
    int currTriangle = 0;

    for(int z = 0; z < zSize; z++)
    {
        for (int x = 0; x < xSize; x++)
        {
            indicies[currTriangle + 0] = currVert + 0;
            indicies[currTriangle + 1] = currVert + xSize + 1;
            indicies[currTriangle + 2] = currVert + 1;
            indicies[currTriangle + 3] = currVert + 1;
            indicies[currTriangle + 4] = currVert + xSize + 1;
            indicies[currTriangle + 5] = currVert + xSize + 2;
            currVert++;
            currTriangle += 6;
        }
        currVert++;
    }
    return indicies;
}

