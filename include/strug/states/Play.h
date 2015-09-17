#pragma once

#include <glade/GladeObject.h>
#include <glade/State.h>
#include <glade/debug/log.h>
#include <strug/Level.h>
#include <strug/generator/WorldGenerator.h>

class Context;
class Block;
class StrugController;
class Player;

class Play: public State
{
  friend class MazeController;
  
  private:
    static const float BASE_RUNNING_SPEED;

    float runningSpeed;
    float blockWidth, blockHeight;
    float screenScaleX, screenScaleY;
    Vector2i cameraMan;
    StrugController *controller;
    Player *player;
    WorldGenerator generator;
    AreaMap areaMap;
    
    int
      prevPlayerBlockCoordX,
      prevPlayerBlockCoordY,
      prevPlayerAreaCoordX,
      prevPlayerAreaCoordY;

  public:
    Play();
    ~Play();
    
    virtual void init(Context &context);
    virtual void shutdown(Context &context);
    virtual void applyRules(Context &context);
    
    private:
      float blockToWorldCoordX(int blockX)
      {
        return blockX * blockWidth - screenScaleX + blockWidth / 2;
      }
      
      float blockToWorldCoordY(int blockY)
      {
        return blockY * blockHeight - screenScaleY + blockHeight / 2;
      }

      int getBlockCoordX(Block &object);
      int getBlockCoordY(Block &object);
      int areaCoordFromBlockCoord(int blockCoord);
      void applyStartingRulesForBlock(Block &block, int block_x, int block_y);
      void addArea(Context &context, int area_x, int area_y, WorldGenerator::AreaType type);
      void addMoreAreas(Context &context, int area_x, int area_y);
};
