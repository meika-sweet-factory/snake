#include <SDL2/SDL.h>
#include <time.h>
#include <stdbool.h>
#include "../Headers/memory.h"
#include "../Headers/interface.h"
#include "../Headers/player.h"
#include "../Headers/draw.h"

void            this_game(t_game *g, SDL_Rect rect, SDL_Renderer * render);

_Bool               sdl_engine(t_game * g)
{
    SDL_Rect        rect;
    SDL_Window *    window;
    SDL_Renderer *  render;

    window = 0;
    render = 0;
    render = init_sdl(g, window, render);
    rect.w = 10;
    rect.h = 10;
    render = draw_walls(g, rect, render);
//  Ici la boucle;
    event_loop(g, rect, render);
    free_sdl(window, render);
    return SUCCESS;
}

void            this_game(t_game * g, SDL_Rect rect, SDL_Renderer * render)
{
    bool        run;
    SDL_Event   e;

    run = true;
    g->player->stat.speed = 1000;
    while (run) {
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) run = false;
            else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_UP) g->player->direction = 0;
                else if (e.key.keysym.sym == SDLK_DOWN) g->player->direction = 1;
                else if (e.key.keysym.sym == SDLK_RIGHT) g->player->direction = 2;
                else if (e.key.keysym.sym == SDLK_LEFT) g->player->direction = 3;
            }
        }
        move_forward(g->player);
        SDL_RenderClear(render);
        render = draw_walls(g, rect, render);
        render = draw_snake(g->player, render, rect);
        SDL_Delay(g->player->stat.speed);
    }
}

