#include "raylib.h"
#include "ecb_utils.h"
#include "ray_radium.h"

global_variable Vector2 Values[4];

typedef plex
{
  r32 X;
  r32 Y;
  u32 Height;
  u32 Width;


} entity;

global_variable entity Player;
global_variable entity Bullet[10];
global_variable u32 BulletIndex = 0;

file_scope void
CreateBullet()
{
  if(BulletIndex < 10)
  {
    Bullet[BulletIndex].X = Player.X;
    Bullet[BulletIndex].Y = Player.Y - Player.Height;
    Bullet[BulletIndex].Width = 5;
    Bullet[BulletIndex++].Height = 5;
  }
}

file_scope void
RenderBullets()
{
  for(u32 Iter = 0; Iter < BulletIndex; Iter++)
  {
    DrawRectangle(Bullet[Iter].X, Bullet[Iter].Y,
                  Bullet[Iter].Width, Bullet[Iter].Height, WHITE);
    Bullet[Iter].Y -= 0.03;

    if(Bullet[Iter].Y < 10)
    {
      BulletIndex--;
    }
  }
}

file_scope void
DrawPlayer(entity* Player)
{
  Vector2 Top = {};
  Top.x = Player->X;
  Top.y = Player->Y - Player->Height;

  Vector2 BottomLeft = {};
  BottomLeft.x = Player->X - (Player->Width / 2);
  BottomLeft.y = Player->Y;

  Vector2 BottomRight = {};
  BottomRight.x = Player->X + (Player->Width / 2);
  BottomRight.y = Player->Y;


  DrawTriangle(Top, BottomLeft, BottomRight, BLUE);
}


s32
main()
{
  InitWindow(WND_WIDTH, WND_HEIGHT, "Hello Window");

  Player.X = WND_WIDTH / 2;
  Player.Y = 580;
  Player.Width = 40;
  Player.Height = 30;

  Values[0].x = 100.0f;
  Values[0].y = 100.0f;

  Values[1].x = 150.0f;
  Values[1].y = 600.0f;

  Values[2].x = 200.0f;
  Values[2].y = 300.0f;

  Values[3].x = 600.0f;
  Values[3].y = 500.0f;




  char* Buffer;
  while(!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);

    //DrawLineEx((Vector2){100.0f, 500.0f}, (Vector2){600.0f, 500.0f}, 3.0f, WHITE);
    //DrawLineEx((Vector2){100.0f, 100.0f}, (Vector2){100.0f, 500.0f}, 3.0f, WHITE);


    //DrawSplineBezierCubic(Values, 4, 2.0f, WHITE);

    DrawPlayer(&Player);
    if(IsKeyDown(KEY_A))
    {
      Player.X -= 0.07;
    }
    if(IsKeyDown(KEY_D))
    {
      Player.X += 0.07;
    }
    if(IsKeyReleased(KEY_SPACE))
    {
      CreateBullet();
    }

    RenderBullets();



    EndDrawing();
  }

  CloseWindow();

  return 0;
}
