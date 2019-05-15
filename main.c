#include <stdbool.h>
#include <SDL2/SDL.h>
#include <emscripten.h>

#define WINDOW_WIDTH    640
#define WINDOW_HEIGHT   480

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int counter = 0;

bool initSDL() {
     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
    if (window == NULL | renderer == NULL) {
        return false;
    } 

    return true;
}

void mainLoop() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    SDL_Rect r = {counter % WINDOW_WIDTH - 50, 50, 50, 50};
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255 );
    SDL_RenderFillRect(renderer, &r );

    SDL_RenderPresent(renderer);

    counter++;
}

void destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main() {
    initSDL();

    emscripten_set_main_loop(mainLoop, -1, 1);

    destroy();
    return EXIT_SUCCESS;
}