#include "pch.h"
#include "Board.h"
#include "Player.h"

Board board;
Player player;

int main(int argc, char* argv[])
{
    ::srand(static_cast<unsigned>(time(nullptr)));
    board.Init(25, &player);
    player.Init(&board);
    
    uint64 lastTick = 0;
    while (true)
    {
        const uint64 currentTick = GetTickCount64();
        const uint64 deltaTick = currentTick - lastTick;
        lastTick = currentTick;

        // 입력
        
        // 로직
        player.Update(deltaTick);

        // 렌더링
        board.Render();
    }
}
