#include <SDL2/SDL.h>
#include <stdio.h>

//screen window constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char* args[])
{
  //The window we will render to
  SDL_Window* window = NULL;

  //the surface contained by the window
  SDL_Surface* screenSurface = NULL;

  //Initialize SDL
  if (SDL_Init( SDL_INIT_VIDEO ) < 0)
  {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  }
  else {
    //Create Window
    window = SDL_CreateWindow( "Hello World!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if (window == NULL)
    {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
      //Get window surface
      screenSurface = SDL_GetWindowSurface( window );

      //fill surface with some color
      SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF2F, 0xFF3, 0xFF ) );

      //Update changes
      SDL_UpdateWindowSurface( window );

      //wait 4 seconds
      SDL_Delay( 4000 );
    }
  }

  //Destroy window
  SDL_DestroyWindow( window );

  //quit sdl subsystems
  SDL_Quit();

  return 0;
}
