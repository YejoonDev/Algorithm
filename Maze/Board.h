#pragma once
#include "ConsoleHelper.h"
#include "types.h"

class Player;

enum { BOARD_MAX_SIZE = 100 };

enum class TileType
{
    NONE = 0,
    EMPTY,
    WALL,
};

class Board
{
public:
    Board();
    ~Board();

    void Init(int32 size, Player* player);
    void Render();

    void GenerateMap();

    TileType GetTileType(Pos pos);
    ConsoleColor GetTileColor(Pos pos);
    int32 GetSize() { return _size; }

    Pos GetEnterPos() { return Pos{ 1, 1 }; }
    Pos GetExitPos() { return Pos{ _size - 2, _size - 2 }; }

    
private:
    TileType _tiles[BOARD_MAX_SIZE][BOARD_MAX_SIZE] = {};
    int32 _size = 0;
    Player* _player = nullptr;
};
