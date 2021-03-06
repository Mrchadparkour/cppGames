#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;
//Window to render to
SDL_Window* gWindow = NULL;

//surface contained by window
SDL_Surface* gScreenSurface = NULL;

//image we will load and show on screen
SDL_Surface* gHelloWorld = NULL;

bool init()
{
  bool success = true;

  if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
  {
    printf("SDL couldn't initialize SDL error%s\n", SDL_GetError());
    success = false;
  }
  else
  {
    gWindow = SDL_CreateWindow( "This is Lena Gray!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if (gWindow == NULL) {
      printf("Window couldn't be created! SDL_Error : %s\n", SDL_GetError() );
      success = false;
    }
    else
    {
      gScreenSurface = SDL_GetWindowSurface( gWindow );
    }
  }
  return success;
}

bool loadMedia()
{
  bool success = true;

  gHelloWorld = SDL_LoadBMP("./lena_gray.bmp");
  if ( gHelloWorld == NULL )
  {
    printf("Unable to load image %s! SDL Error: %s\n", "imageWindow/lena_gray.bmp", SDL_GetError());
    success = false;
  }

  return success;

}

void close()
{
  SDL_FreeSurface( gHelloWorld );
  gHelloWorld = NULL;

  SDL_Quit();
}

int main(int argc, char* args[])
{
  if (!init())
  {
    printf("Failed to initialize!\n");
  }
  else
  {
    if (!loadMedia()) {
      printf("Failed to load Media! \n");
    }
    else
    {
      SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
      SDL_UpdateWindowSurface( gWindow );
      SDL_Delay( 4000 );
    }
  }

  close();

  return 0;
}
