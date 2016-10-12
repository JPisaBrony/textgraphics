#include <SDL/SDL.h>
#include <curses.h>

PDCEX SDL_Surface *pdc_screen;
int width, height, input_char, quit = 0;
MEVENT event;

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

    //pdc_screen = SDL_SetVideoMode(640, 480, 0, SDL_SWSURFACE | SDL_ANYFORMAT);

    // init PDCurses with proper settings
    initscr();
    start_color();
    scrollok(stdscr, TRUE);
    init_pair(1, COLOR_WHITE + 8, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);

    addstr("Basic PDCurses Window\n");

    // main loop
    while(!quit) {
        input_char = getch();
        switch(input_char) {
            case KEY_MOUSE:
                if(nc_getmouse(&event) == OK) {
                    quit = 1;
                }
                break;
        }

        addstr("Basic PDCurses Window\n");
    }

    // cleanup
    endwin();
    SDL_Quit();
    return 0;
}
