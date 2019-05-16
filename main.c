#include <stdbool.h>
#include <SDL2/SDL.h>
#include <emscripten.h>

#define WINDOW_WIDTH    640
#define WINDOW_HEIGHT   480

const unsigned int size = 50;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

SDL_Point velocity = {0, 0};
SDL_Rect square = {size, size, size, size};

bool init() {
     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
    if (window == NULL | renderer == NULL) {
        return false;
    } 

    return true;
}

void process_event(SDL_Event *event) {
    SDL_Keycode key = event->key.keysym.sym;
    
    if (event->key.type == SDL_KEYDOWN) {
        if (key == SDLK_LEFT || key == SDLK_RIGHT) {
            velocity.x = key == SDLK_LEFT ? -1 : 1;
        }
        if (key == SDLK_UP || key == SDLK_DOWN) {
            velocity.y = key == SDLK_UP ? -1 : 1;
        }
    }
    if (event->key.type == SDL_KEYUP) {
        velocity.x = 0;
        velocity.y = 0;
    }
}

void process_input() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        process_event(&event);
    }
}

void update() {
    square.x += velocity.x;
    square.y += velocity.y;
}

void draw() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255 );
    SDL_RenderFillRect(renderer, &square );
}

void main_loop() {
    process_input();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    update();
    draw();    

    SDL_RenderPresent(renderer);
}

void destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main() {
    init();

    square.x = (WINDOW_WIDTH - size) / 2;
    square.y = (WINDOW_HEIGHT - size) / 2;

    emscripten_set_main_loop(main_loop, -1, 1);

    destroy();
    return EXIT_SUCCESS;
}