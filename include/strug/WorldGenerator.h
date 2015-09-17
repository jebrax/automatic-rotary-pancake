#pragma once

#include <strug/Level.h>

class WorldGenerator
{
  private:
    long seed;
    
  public:
    WorldGenerator(const long seed_param = 0);
    void setSeed(const long seed_param = 0);
    void fillArea(Area *area, AreaMap &map, int area_x, int area_y);
};
