#include <Terrain/Terrain.h>

Terrain::Terrain(int gridX, int gridZ, int seed)
{
    xSize = gridX;
    zSize = gridZ;
    indicies.resize((xSize-1)*(zSize-1)*6);
    perlinNoise.SetSeed(seed);
    perlinNoise.SetFrequency(0.05f);
    perlinNoise.SetFractalOctaves(5);
    perlinNoise.SetFractalLacunarity(2.f);
    perlinNoise.SetFractalGain(0.5f);
    perlinNoise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
}


std::vector<unsigned int> Terrain::GenerateTerrain(std::vector<glm::vec3> &verticies)
{
    for(int i = 0, z = 0; z <= zSize; z++)
    {
        for (int x = 0; x <= xSize; x++)
        {
            verticies.push_back(glm::vec3(x, perlinNoise.GetNoise((float)x, (float)z), z));

            if(x < xSize -1 && z < zSize -1)
            {
                // I really don't know what this does
                AddTriangle(i, i + xSize + 1, i + 1);
                AddTriangle(i + 1, i + xSize + 1, i + xSize + 2);
            }
            i++;
        }
    }
    return indicies;
}

void Terrain::AddTriangle(int a, int b, int c)
{
    indicies[triangleIndex] = a;
    indicies[triangleIndex + 1] = b;
    indicies[triangleIndex + 2] = c;
    triangleIndex += 3;
}

