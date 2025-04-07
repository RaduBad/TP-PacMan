#include <stdlib.h>
#include <time.h>
#include "include/raylib.h"
#define MAZE_WIDTH 28
#define MAZE_HEIGHT 31
typedef enum Direction{
        STOP,
        UP,
        DOWN,
        LEFT,
        RIGHT
}Direction;
typedef struct{
    int row;
    int col;
}Vector2Int;
char maze[MAZE_HEIGHT][MAZE_WIDTH];
float SPEED = 2.0f;
const char initialmaze[MAZE_HEIGHT][MAZE_WIDTH] = {
    "############################",
    "#............##............#",
    "#.####.#####.##.#####.####.#",
    "#O####.#####.##.#####.####O#",
    "#.####.#####.##.#####.####.#",
    "#..........................#",
    "#.####.##.########.##.####.#",
    "#.####.##.########.##.####.#",
    "#......##....##....##......#",
    "######.##### ## #####.######",
    "     #.##### ## #####.#     ",
    "     #.##          ##.#     ",
    "     #.## ###__### ##.#     ",
    "######.## #      # ##.######",
    "      .   #      #   .      ",
    "######.## #      # ##.######",
    "     #.## ######## ##.#     ",
    "     #.##          ##.#     ",
    "     #.## ######## ##.#     ",
    "######.## ######## ##.######",
    "#............##............#",
    "#.####.#####.##.#####.####.#",
    "#.####.#####.##.#####.####.#",
    "#...##................##...#",
    "###.##.##.########.##.##.###",
    "###.##.##.########.##.##.###",
    "#......##....##....##......#",
    "#.##########.##.##########.#",
    "#.##########.##.##########.#",
    "#O.......................O.#",
    "############################"
};

void drawMaze(char maze[MAZE_HEIGHT][MAZE_WIDTH]) {
    for (int y = 0; y < MAZE_HEIGHT; y++)
    {
        for (int x = 0; x < MAZE_WIDTH; x++)
        {
            if (maze[y][x] == '#')
            {   
                Rectangle rec = {x*20, y*20, 20, 20};
                DrawRectangleRec(rec, BLACK);
                DrawRectangleLinesEx(rec, 5, DARKBLUE);
            }
            else if (maze[y][x] == '.')
            {
                DrawCircle(x*20+10, y*20+10, 2, YELLOW);
            }
            else if (maze[y][x] == 'O')
            {
                DrawCircle(x*20+10, y*20+10, 6, RED);
            }
            if (maze[y][x] == '_')
            {   
                Rectangle rec = {x*20, y*20, 20, 20};
                DrawRectangleRec(rec, BLACK);
                DrawRectangleLinesEx(rec, 5, WHITE);
            }
        }
    }
}

int main(void)
{
    // Initialization
    float error_term = 0;  
    char Char='#';
    int score=0;
    int pos_x=MAZE_WIDTH*20/2;
    int pos_y=(MAZE_HEIGHT*23/2)-MAZE_HEIGHT/4+1;
    int ok=0;
    srand(time(NULL));
    InitWindow(MAZE_WIDTH * 20, MAZE_HEIGHT * 23, "PAC-MAN");
    SetTargetFPS(60);    
   //labir
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            maze[i][j] = initialmaze[i][j];
        }
    }           
   
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        
        // Draw
        
        BeginDrawing();
        ClearBackground(BLACK);
        if(ok==0)
        {
           
            ClearBackground(BLACK);
            DrawText("PAC MAN", 50, 80, 100, GOLD); 
            DrawText("PAC MAN", 60, 80, 100, YELLOW); 
            DrawText("PRESS   ENTER    TO START",50,500,30,YELLOW);
        }
        if(IsKeyPressed(KEY_ENTER) || ok==1){
            ok=1;
            ClearBackground(BLACK);
            drawMaze(maze);
            DrawCircle(pos_x,pos_y,8 ,YELLOW);
           if(IsKeyDown(KEY_RIGHT) && ((maze[(int)(pos_y - error_term+8)/ 20][(int)(pos_x + 20-8)/ 20] != Char) && (maze[(int)(pos_y + error_term-8)/ 20][(int)(pos_x + 20-8)/ 20] != Char))
           && ((maze[(int)(pos_y - error_term-8)/ 20][(int)(pos_x + 20-8)/ 20] != '_') && (maze[(int)(pos_y + error_term-8)/ 20][(int)(pos_x + 20-8)/ 20] != '_')))
           {
            pos_x+=2;

           }
           if(IsKeyDown(KEY_LEFT) && ((maze[(int)(pos_y - error_term+8)/ 20][(int)(pos_x - 20+8)/ 20] != Char) && (maze[(int)(pos_y + error_term-8)/ 20][(int)(pos_x - 20+8)/ 20] != Char))
           && ((maze[(int)(pos_y - error_term+8)/ 20][(int)(pos_x - 20+8)/ 20] != '_') && (maze[(int)(pos_y + error_term-8)/ 20][(int)(pos_x - 20+8)/ 20] != '_')))
           {
            pos_x-=2;

           }
           if(IsKeyDown(KEY_UP) && ((maze[(int)(pos_y - 20+8)/ 20][(int)(pos_x + error_term-8)/ 20] != Char) && (maze[(int)(pos_y - 20+8)/ 20][(int)(pos_x - error_term+8)/ 20] != Char))
           && ((maze[(int)(pos_y - 20+8)/ 20][(int)(pos_x + error_term-8)/ 20] != '_') && (maze[(int)(pos_y - 20+8)/ 20][(int)(pos_x - error_term+8)/ 20] != '_')))
           {
            pos_y-=2;

           }
           if(IsKeyDown(KEY_DOWN) && ((maze[(int)(pos_y + 20-8)/ 20][(int)(pos_x + error_term-8)/ 20] != Char) && (maze[(int)(pos_y + 20-8)/ 20][(int)(pos_x - error_term+8)/ 20] != Char))
           && ((maze[(int)(pos_y + 20-8)/ 20][(int)(pos_x + error_term-8)/ 20] != '_') && (maze[(int)(pos_y + 20-8)/ 20][(int)(pos_x - error_term+8)/ 20] != '_')))
           {
            pos_y+=2;

           }
           if (maze[(int)pos_y / 20][(int)pos_x / 20] == '.') {
            score += 10;
            maze[(int)pos_y / 20][(int)pos_x / 20] = ' ';
           }
           if (maze[(int)pos_y / 20][(int)pos_x / 20] == 'O') {
            score += 50;
            maze[(int)pos_y / 20][(int)pos_x / 20] = ' ';}
           DrawText(TextFormat("Score: %i", score), 10, (MAZE_HEIGHT*23) - 60, 20, LIGHTGRAY);

           }
          
       
            
           
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}