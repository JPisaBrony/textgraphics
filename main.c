#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <curses.h>

PDCEX SDL_Surface *pdc_screen;
int width, height, input_char, quit = 0;
MEVENT event;
char **image_buffer;
int num_lines = 0;

void read_ascii(char *filename) {
    char ch, *line;
    int i = 0, line_length = 0, line_end_flag = 0;

    // open the file in read mode to handle end of lines
    FILE *fp = fopen(filename, "r");

    // check DAT pointer
    if(fp == NULL) {
        printf("Error opening file");
        exit(1);
    }

    // read entire file
    while(ch != EOF) {
        ch = fgetc(fp);
        // check if it is the end of the line
        if(ch == '\n') {
            // increment number of lines
            num_lines++;
            // stop incrementing the length of the line
            line_end_flag = 1;
        }
        if(line_end_flag == 0)
            // increment number of lines
            line_length++;
    }
    // get back to the beginning of the file
    fseek(fp, 0, SEEK_SET);

    // allocate DAT memory
    image_buffer = malloc(sizeof(char*) * num_lines);
    line = malloc(sizeof(char) * line_length + 1);

    // re read the whole file but this time line by line
    while(fgets(line, line_length + 1, fp)) {
        // check if the line is a new line character
        if(*line != '\n') {
            // allocate the proper memory
            image_buffer[i] = malloc(line_length + 1);
            // copy the memory into the image buffer
            strncpy(image_buffer[i], line, line_length);
            i++;
        }
    }

    // cleanup
    fclose(fp);
    free(line);
}

void print_file() {
    int i;
    // iterate through each line in the string buffer
    for(i = 0; i < num_lines; i++) {
        // check if it is the end of the image frame
        if(*image_buffer[i] == 'E') {
            // refresh the image
            refresh();
            delay_output(30);
        } else {
            // add the line to the screen from the image buffer
            printw(image_buffer[i]);
            // add new line character to get to the next line
            printw("\n");
        }
    }
}

int main(int argc, char* args[])
{
    // make SDL not write stdout.txt and stderr.txt to the filesystem
    freopen("CON", "w", stdout);
    freopen("CON", "w", stderr);

    // read the file
    read_ascii("all.txt");
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

    //addstr("Basic PDCurses Window\n");

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

        // print out the image from the image buffer
        print_file();
    }

    // cleanup
    endwin();
    SDL_Quit();
    free(image_buffer);
    return 0;
}
