#include <SDL/SDL.h>
#include <curses.h>

PDCEX SDL_Surface *pdc_screen;
int width, height;

int main(int argc, char* args[])
{
    // initialize SDL and quit if it failed
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
        exit(1);

    // setup window and make it full screen
    SDL_VideoInfo *info;
    info = SDL_GetVideoInfo();
    width = info->current_w;
    height = info->current_h;
    pdc_screen = SDL_SetVideoMode(width, height, 0, SDL_SWSURFACE | SDL_ANYFORMAT | SDL_FULLSCREEN);

    // init PDCurses
    initscr();
    start_color();
    scrollok(stdscr, TRUE);
    init_pair(1, COLOR_WHITE + 8, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));

    // basic text on screen
    addstr("Basic PDCurses Window");

    // wait for input
    getch();
    endwin();

    // cleanup and quit
    SDL_Quit();
    return 0;
}
