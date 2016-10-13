#define NO_STDIO_REDIRECT
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <curses.h>

PDCEX SDL_Surface *pdc_screen;
int width, height, input_char, quit = 0;
MEVENT event;
char **image_buffer;
int num_lines = 0;

void update() {
    refresh();
    delay_output(50);
}

void draw_pony() {
    addstr("                                                                                                    \n");
    addstr("                                                                                                    \n");
    addstr("                                                                                                    \n");
    addstr("                                                               .,,,,,.        ..          .,,,.     \n");
    addstr("                                                             .,lxxxdl'  ..   .......... .,lxdl'     \n");
    addstr("                                                             .ldOOOdl' ..........,cc;.,;lxxxc..     \n");
    addstr("                                                           .,lxxxkOdl;...........',,'.cxxxl;'..     \n");
    addstr("                                                           .ldOxoxOkx:................,:ld:.''..    \n");
    addstr("                                                           .ldOdldOOOxo,................';:c;'...   \n");
    addstr("                                                           .ldOkxkOOOOO:..................',;c;'..  \n");
    addstr("                                                           .;oOOOOOl........................;llc,.. \n");
    addstr("                                                           .':dxOOOdlll,......   ,ooooool:. .....   \n");
    addstr("                                                            .,ldOOOl...ckl,. ;kkkc..lOOOdl.         \n");
    addstr("                                                            .,ldOOOdlllOMO:. .,;,.  ;OOOdl'         \n");
    addstr("                                                            .,ldOOOOOOOXMO:.   ,k,  ;OOOdl'         \n");
    addstr("                          ...........                       ..,cdxOOOOO0KKKo'. .,.  ;OOOdl:,.       \n");
    addstr("                      ......,:::::,......                   ..';ldOOOOOl.oKKKOkkk,  ;OOOkxdl'       \n");
    addstr("                  ......,:::clooolc:::,....                ...';lxOOOOOdldO0KKKKKxllodxOOOxl.       \n");
    addstr("               .......,:llloc;;;;;;;;;;:,...              ..'..,ldOOOOOOOOOOOOOOOOOOkxdodd;.        \n");
    addstr("             .......,:clc;;;'.........';;::;;,,,,,,.      ..'..;ldOOOOOOOxoddddddddddd;...          \n");
    addstr("           .......,:coc;'...............';:ldxdodxxl,,,,,...''';ldOOOOOOOdl,..........              \n");
    addstr("         .........;oc;,''.........     ...,ldxkkkxxxxoldxl;::::oxkOOOOOOOdl.                        \n");
    addstr("       ........,::co:''.......            'llodxkkkxddxkOkxoldxkOOOOOOOOOdl.                        \n");
    addstr("      .........;lool:'......              .ldxdodxxxxddxOOOdldOOOOOOOOOOOdl.                        \n");
    addstr("     ........,:cloc;'.....                .ldOxlloooddxkOxddxkOOOOOOOOOOOdl'                        \n");
    addstr("    .........;llol:'....                  .ldOkkdlldxddoddxkOOOOOOOOOOOxd;.                         \n");
    addstr("   ..........;oc;;,'....                  'lkNOdxkkxdOKOxkOOOOOOOOOOOOOdl.                          \n");
    addstr("  .........,:co:''......                  'ldxxxkOOkxOKkdxOOOOOOOOOOOxd;.                           \n");
    addstr(" ..........;oll:''....                  .,:llldOOOOOOOOdldOOOOOOOxddd;.                             \n");
    addstr("  .........;ooo:''....                .,cdddoldOOOOOOxdolooodxOOOdl,.                               \n");
    addstr("    .......;ooo:''....              .,cdddddoldOOOOOOxl,...,ldOOOkxl,.                              \n");
    addstr("      .....;ooo:''....            .,cddddddodxkOOOOxd;.    .ldOOOOOdl'                              \n");
    addstr("      .....;loo:''....          .,cdddddoolldOOOOOOdl'      .;dxOOOkxl,.                            \n");
    addstr("        ...;ooo:''....        .,cdddddddol,.;dxOOOOdl.       .ldOOOOOdl'                            \n");
    addstr("          ..':l:'''...      .;codddddddo;.  'ldOOOOkxl,.   .,lxkOOOxdol'                            \n");
    addstr("             .';cc;'..      'loddddddo;.    'ldOOOOOOdl. .,lxkOOOOOdlll'                            \n");
    addstr("               .''''..       .;oddddol'     .ldOOOOOOkxl,lxkOOOOOOOdlll'                            \n");
    addstr("                   ...         .;ooo;.      .ldOOOOOOOOdldOOOOOOOxdooooc,.                          \n");
    addstr("                     .           ...        .ldOOOOOOOOdldOOOOOxdddddddol'                          \n");
    addstr("                                            .ldOOOOOOOOkxdddoddddddddddol'                          \n");
    addstr("                                             .;dxOOOOOOxool,...;oooooooll'                          \n");
    addstr("                                              .loddoodo;...     .........                           \n");
    addstr("                                              .lllllcll.                                            \n");
    update();
    addstr("                                                                                                    \n");
    addstr("                                                                                                    \n");
    addstr("                                                               .,,,,,.                    .,,,.     \n");
    addstr("                                                             .,lxxxdl.        ..        .,lxdl.     \n");
    addstr("                                                             'ldOOOdl:,...   .........',lxxx:.      \n");
    addstr("                                                           .,lxxxkOdl;...........,::::oxxxl;.       \n");
    addstr("                                                           'ldOxoxOkx:...........',,,,lxxd:....     \n");
    addstr("                                                           .ldOdldOOOc................';co:'''..    \n");
    addstr("                                                           .ldOkxkOOOxo,................',;c;'...   \n");
    addstr("                                                           .,oOOOOOl......................',;c;'..  \n");
    addstr("                                                           .':oxOOOdlll,....................;llc,.. \n");
    addstr("                                                           .';ldOOOl.........lOOO:  ,oool:. .....   \n");
    addstr("                                                            .,ldOOOdllldkl,. .,,,.  ;OOOdl.         \n");
    addstr("                                                            .,ldOOOOOOOXMO:.   ,k,  ;OOOdl.         \n");
    addstr("                          ...........                       ..;cdxOOOOO0KKKo'. .,.  ;OOOdl:,.       \n");
    addstr("                      ......,:::::,......                   ..';ldOOOOOl'oKKKOkkk,  ;OOOkxdl.       \n");
    addstr("                  ......,:::coooooc:::,....                 ..';ldOOOOOdldO0KKKKKxlcodxOOOdl'       \n");
    addstr("               .......,:clllc;;;;;;;;;;:,...               ...';ldOOOOOOOOOOOOOOOOOOkxdddd;.        \n");
    addstr("             .......,:coc;;;,.........';::,..             ..'..,ldOOOOOOOxdddddddooodd;...          \n");
    addstr("           .......,:coc;'...............';;:;;;,,,,.      ..'..;ldOOOOOOOdl,..........              \n");
    addstr("         .........;oc;,'..........     ...,loxdodxxl,,,,,...''';ldOOOOOOOdl'                        \n");
    addstr("       ........,::cl:''.......            'ldxkkkxxxxoldxl;::::oxkOOOOOOOdl.                        \n");
    addstr("      .........;llol:'......              .llodxkkkxddxkOkxoldxkOOOOOOOOOdl.                        \n");
    addstr("     ........,:cloc;'.....                .ldxdodxxxxddxOOOdldOOOOOOOOOOOdl.                        \n");
    addstr("    .........;llll:'....                  'ldOxlloooddxkOxddxkOOOOOOOOOOOdl'                        \n");
    addstr("   ..........;oc;,,'....                  'ldOkkdlldxddoddxkOOOOOOOOOOOxd;.                         \n");
    addstr("  .........,:lo:''......                  .lkNOdxkkxdOKOxkOOOOOOOOOOOOOdl'                          \n");
    addstr(" ..........;ooo:''....                     .:xxkkOOkxOKkdxOOOOOOOOOxdod;.                           \n");
    addstr("  .........;ooo:''....                    .,:ldOOOOOOxddxkOOOxoxOOOdl,.                             \n");
    addstr("    .......;ooo:''....                  .,cdoldOOOOOOdloddoodoldOOOkxl,.                            \n");
    addstr("      .....;ooo:''....                .,:llodxkOOOOxd;.....,llldOOOOOkxl,.                          \n");
    addstr("      .....;ooo:''....              .,cdoldxkOOOxdd;.      'lodododxOOOdl.                          \n");
    addstr("        ...;olo:''....            .,cdddoldOOOOOdll.     .,cddddooldOOOdl.                          \n");
    addstr("          ..';o:''''..          .,coddddoldOOOOOdll.     'lodddoodxkOOOdl.                          \n");
    addstr("             .';cc;'..          .lodddddoldOOOOOdll.     'loddolldOOOOOdl.                          \n");
    addstr("               .''''..          .lodddddoldOOOOOdll.     'lodoldxkOOOOOdl.                          \n");
    addstr("                   ...          .loddddolldOOOOOdll'   .,cdddoldOOOOOxd;.                           \n");
    addstr("                     .           .;ooo;.,ldOOOOOkxkl,. 'lodddoldOOOOOdl.                            \n");
    addstr("                                   ...  .ldOOOOOOOOdl. 'lodddolxOOOxd;.                             \n");
    addstr("                                        .ldOOOOOOOOdl. 'llodddodddd;.                               \n");
    addstr("                                        .ldOOOOOOOOdl.  .,llooollll'                                \n");
    addstr("                                         .;odooddddol.    .........                                 \n");
    addstr("                                          .llclllllll'                                              \n");
    update();
    addstr("                                                                                                    \n");
    addstr("                                                               .,,,,,.                    .,,,.     \n");
    addstr("                                                             .,lxxxdl.        ..        .,lxdl.     \n");
    addstr("                                                             'ldOOOdl:,...   .........',lxxx:.      \n");
    addstr("                                                           .,lxxxkOdl;...........,::::oxxxl;.       \n");
    addstr("                                                           .ldOxoxOkx:...........',,,,lxxd:....     \n");
    addstr("                                                           .ldOdldOOOc................';co:'.'..    \n");
    addstr("                                                           .ldOkxkOOOxo,................',;c;'...   \n");
    addstr("                                                           .,oOOOOOl..'...................',;c;'..  \n");
    addstr("                                                           .':dxOOOdlll,....................;lcc,.. \n");
    addstr("                                                           .';ldOOOl.........lOOO:  ,oool:. .....   \n");
    addstr("                                                            .,ldOOOdllldkl,. .,,,.  ;OOOdl'         \n");
    addstr("                            .........                       .,ldOOOOOOOXMO:.   ,k,  ;OOOdl'         \n");
    addstr("                        .................                   ..;cdxOOOOO0KKKo'. .,.  ;OOOdl:,.       \n");
    addstr("                    ........,:::::::,......                 ..';ldOOOOOl'oKKKOkkk,  ;OOOkxdl.       \n");
    addstr("                  ........,:coooooooc:,.....                ..';ldOOOOOdldO0KKKKKxllodxOOOdl.       \n");
    addstr("               .........,:clc;;;;;;;;;;:,...               ...';ldOOOOOOOOOOOOOOOOOOkxdddd;.        \n");
    addstr("               .......,:coc;,''.......';;:,..             ..'..,ldOOOOOOOxdddooddddddd;...          \n");
    addstr("             .......,:clc;'.............,;;:;;;,,,,.      ..'..;ldOOOOOOOdl,..........              \n");
    addstr("           .........;lc;,'........     ...,ldxdodxxl,,,,,...''';ldOOOOOOOdl.                        \n");
    addstr("         .........,:cl:'.......           'loxkkkxxxxdldxl;::::oxkOOOOOOOdl.                        \n");
    addstr("        ..........;ooo:'......            .llodxkkkxddxkOkxdldxkOOOOOOOOOdl.                        \n");
    addstr("       ........,::coc;'.....              .ldxdodxxxxddxOOOdldOOOOOOOOOOOdl.                        \n");
    addstr("      .........;oolo:'....              .,lxkOkxdoooodxkOxddxkOOOOOOOOOOOdl.                        \n");
    addstr("     ..........;olc;,'....              .ldOOOkdolllloddodxkOOOOOOOOOOOxd;.                         \n");
    addstr("    .........,:col:''.....              .ldOOOkkdoodkxxxxkOOOOOOOOOOOOOdl.                          \n");
    addstr("   ..........;ollo:'....                .ldOKNOdxkkxdONKOOOOOOOOOOOOOxd;.                           \n");
    addstr("    .........;ollo:'....                 .;dkKOxkOOkkkxkOOOOOxdxOOOxdol'                            \n");
    addstr("      .......;llll:'....                  .ldOOOOOOxdoloddoodoldOOOkxxxl,,,.                        \n");
    addstr("        .....',:ollc;....               .,:ldOOOxoool,...,looodddxOOOOOkxdl.                        \n");
    addstr("          .....;ollo:'....            .,lxxxkOxdoll,.    'lodddolodddxOOOdl.                        \n");
    addstr("            ...;lllo:'....            .lxOOOOOdl,..    .,cdddddol,.,lodxOdl.                        \n");
    addstr("              ..'':o:'''..            'ldOOOxdol'    .,cddddddo;.  .ldxkOdl.                        \n");
    addstr("                ..,llc;'..          .,:ldOOOdl,.     'lodddddol' .,lxkOOOdl.                        \n");
    addstr("                  .':o:'..          'ldxkOOOdl.    .,cdddddddol:,lxkOOOOOdl.                        \n");
    addstr("                    .'''..          .ldOOOOOdl.    'lodddddddollldOOOOOOOdl.                        \n");
    addstr("                       ...          .ldOOOOOdl.    'lodddddddol,.;oxOOOOOdl'                        \n");
    addstr("                         .          .ldOOOOOdl.    'lodddddddol' .ldOOOxd;.                         \n");
    addstr("                                  .,lxkOOOOOdl.    'lodddddddol'  .;oxOdl.                          \n");
    addstr("                                  .ldOOOOOOOdl.    'lodddddddol'   .lod;.                           \n");
    addstr("                                  .ldOOOOOOOdl.     .;oooooooll'    ...                             \n");
    addstr("                                  .lodoodoodol.       .........                                     \n");
    addstr("                                  .lllllllllll.                                                     \n");
    update();
    addstr("                                                               'lllll.                    'lll'     \n");
    addstr("                                                             .,lxxxdl.        ..        .,lxdl'     \n");
    addstr("                                                             .ldOOOdl:,...   .........',lxxx:.      \n");
    addstr("                                                           .,lxxxkOdl;...........,::::oxxxl;.       \n");
    addstr("                                                           'ldOxoxOkx:...........',,,,lxxd:....     \n");
    addstr("                                                           'ldOdldOOOc................';co:..'..    \n");
    addstr("                                                           'ldOkxkOOOxo,................',;c;'...   \n");
    addstr("                                                           .,oOOOOOl......................',;c;'..  \n");
    addstr("                                                           .':dxOOOdlll,....................;ol:,.. \n");
    addstr("                                                           .';ldOOOl.........lOOO:  ,oool:. .....   \n");
    addstr("                                                            .,ldOOOdllldkl,. .,,,.  ;OOOdl.         \n");
    addstr("                          ...........                       .,ldOOOOOOOXMO:.   ,k,  ;OOOdl.         \n");
    addstr("                      ......,:::::,....                     ..,cdxOOOOO0KKKo'. .,.  ;OOOdl:,.       \n");
    addstr("                  ........,:clooolc:::,..                   ..';ldOOOOOl'oKKKOkkk,  ;OOOkxdl.       \n");
    addstr("                ........,:coolc;;;;;;;;:,..                 ..';ldOOOOOdldO0KKKKKxllodxOOOdl.       \n");
    addstr("               .......,:coc;;;'.......';::,..              ...';ldOOOOOOOOOOOOOOOOOOkxddod;.        \n");
    addstr("              ......,:clc;'.............';::'.            ..'..,ldOOOOOOOxddddoddddodd;...          \n");
    addstr("             .......;lll:'................,lc;;,,,,.      ..'..;ldOOOOOOOdl,..........              \n");
    addstr("            ........;l:;,'..........     .,loxdodxxl,,,,,...''';ldOOOOOOOdl.                        \n");
    addstr("           .......,:lo:''.......          'loxkkkxxxxdldxl;::::oxkOOOOOOOdl.                        \n");
    addstr("          ........;lll:'......            'llodxkkkxddxkOkxdloxkOOOOOOOOOdl.                        \n");
    addstr("         ......,::loc;'.....              .lkKkodxxxxddxOOOdldOOOOOOOOOOOdl.                        \n");
    addstr("        .......;oooo:'....              .,lxOKklloooddxkOxodxkOOOOOOOOOOOdl.                        \n");
    addstr("        .......;lllo:'....              .ldOkdoolllkKkddddxkOOOOOOOOOOOxd;.                         \n");
    addstr("        .......;lllo:'....              .lxOkkdldkkOKOxxxkOOOOOOOOOOOOOdl.                          \n");
    addstr("    .  ........;oooo:'....              .lkNOdxkxddONOdxOOOOOOOOOOOOOxo;.                           \n");
    addstr("   ............;oooo:'....              .lxKOkkOkkkxxxxkOOOOOxdxOxdddol:,,,.                        \n");
    addstr("    .   .......;oooo:'....              .ldOOOOOxddolodddddddoldOkxxxxxxxol.                        \n");
    addstr("          .....;ooll:'....            .,:ldOOOxdooooool,.,lodoldOOOOOOOOOkxl,.                      \n");
    addstr("            ...;ollo:'....          .,:ldxkOxdooooooo;.  'loddodooddoddxOOOdl.                      \n");
    addstr("              .;looo:'....        .,lxxxkOxddoddoll;.  .,cdddddol,.,ldxkOOOdl.                      \n");
    addstr("               .'':olc;...        .ldOOOOOdlodddoll'   .lodddddol' .ldOOOOOdl.                      \n");
    addstr("                  ..:o:'..        'ldOOOxdooddddoll' .,cdddddddol:,lxkOOOOOdl.                      \n");
    addstr("                    .';c,..     .,lxkOOOdlodddddoll' 'loddddddo;.,ldOOOOOOOdl.                      \n");
    addstr("                      .'''..    'ldOOOxdolodddddoll:;coddddddol' 'ldOOOOOOOdl'                      \n");
    addstr("                         ...  .,lxkOOOdlllodddddollodddddddddol'  .;dxOOOxd;.                       \n");
    addstr("                           .  .ldOOOOOdl,.;ooooollloddddddddo;.    'ldOxo;.                         \n");
    addstr("                              .ldOOOOOdl.  ........;oddddddol'      .;o;.                           \n");
    addstr("                            .,lxkOOOOOkxl,.         .;ooooo;.         .                             \n");
    addstr("                            'ldOOOOOOOOOdl.           .....                                         \n");
    addstr("                            'lodxOOOOOOOdl'                                                         \n");
    addstr("                             .,loddddddd;.                                                          \n");
    addstr("                              .lllllllll.                                                           \n");
    update();
    addstr("                                                               'lllll.       .........    .lll'     \n");
    addstr("                                                             .,lxxxdl.  ..   .......... .,lxdl.     \n");
    addstr("                                                             .ldOOOdl' ..........;cc;',;lxxxc..     \n");
    addstr("                                                           .,lxxxkOdl,...........',,'.cxxxl;'..     \n");
    addstr("                                                           .ldOxoxOkx:................,:ld:..'..    \n");
    addstr("                                                           .ldOdldOOOxo,................';:c;'...   \n");
    addstr("                                                           .ldOkxkOOOOO:..................',;c;'..  \n");
    addstr("                                                           .;oOOOOOl........................;llc,.. \n");
    addstr("                                                           .':dxOOOdlll,......   ,odooool:. .....   \n");
    addstr("                                                            .,ldOOOl.''ckl,. ;kkkc.'lOOOdl.         \n");
    addstr("                          ...........                       .,ldOOOdlllOMO:. .,,,.  ;OOOdl.         \n");
    addstr("                      ......,:::::,....                     .,ldOOOOOOOXMO:.   ,k,  ;OOOdl.         \n");
    addstr("                  ........,:collloc:::,..                   ..;cdxOOOOO0KKKo'. .,.  ;OOOdl:,.       \n");
    addstr("                ........,:clloc;;;;;;;;:,..                 ..';ldOOOOOl'oKKKOkkk,  ;OOOkxdl.       \n");
    addstr("               .......,:coc;;;,.......';::,..              ...';ldOOOOOdldO0KKKKKxllodxOOOdl.       \n");
    addstr("              ......,:clc;'.............';;:'.            ..'..,ldOOOOOOOOOOOOOOOOOOkxddod;.        \n");
    addstr("             .......;oll:'................,lc;;,,,,.      ..'..;ldOOOOOOOxddddoddddodd;...          \n");
    addstr("            ........;oc;,'..........     .,ldxdodxxl,,,,,...''';ldOOOOOOOdl,..........              \n");
    addstr("           .......,:ll:'........          'ldxkkkxxxxdldxl;::::oxkOOOOOOOdl.                        \n");
    addstr("          ........;loo:'......            'llodxkkkxodxkOkxdldxkOOOOOOOOOdl.                        \n");
    addstr("         ......,::clc;'.....            .,lxOKkodxxxxddxOOOdldOOOOOOOOOOOdl.                        \n");
    addstr("        .......;oooo:'....              'ldO0KklloooodxkOxodxkOOOOOOOOOOOdl.                        \n");
    addstr("        .......;oooo:'....            .,lxkOxdoolllkKkodddxkOOOOOOOOOOOxd;.                         \n");
    addstr("        .......;oooo:'....            .ldOOOxodkkkxOKOxxxkOOOOOOOOOOOOOdl.                          \n");
    addstr("       ........;oooo:'....            .lkNOdxkxdONNKOOOOOOOOOOOOOOOOOxd;.                           \n");
    addstr("    ...........;oooo:'....            .lxKOkkOkxOKKkoxOOOOOOOOOOOOOxd;.                             \n");
    addstr("   ...  .......;oooo:'....            .ldOOOOOOOxddolodddddodddxOxdol:,,,.                          \n");
    addstr("    .     .....;oooo:'....          .,:ldOOOOOxddodoool,.....,ldOkxxxxxxxl,.                        \n");
    addstr("            ...;oooo:'....        .,lxxxkOxdooooddddo;.    .,:loddoxOOOOOdl'                        \n");
    addstr("              .;oool:'....      .,lxkOOOxd;.,loddddol'   .,cdddooolodddxOkxl,.                      \n");
    addstr("               .'';olc;...      'ldOOOxd;.  'loddddol'   'lodddddol,.,ldOOOdl.                      \n");
    addstr("                  .':l:'..    .,lxkOOOdl. .;codddddol' .;codddddo;.',lxkOOOdl.                      \n");
    addstr("                    .';c,..   'ldOOOxo;.  'loddddddol:,cdddddddol:,lxkOOOOOdl.                      \n");
    addstr("                      .'''...,lxkOOOdl.   'loddddddolodddddddddollldOOOOOOOdl.                      \n");
    addstr("                         ...,ldOOOOOdl.   'loddddddoloddddddddo;.,ldOOOOOOOdl'                      \n");
    addstr("                          .;lxkOOOOOdl.    .;oooooolloddddddo;.   .;dxOOOxd;.                       \n");
    addstr("                          .ldOOOOOxd;.       ........;odddo;.      'ldOOOdl.                        \n");
    addstr("                        .,lxkOOOOOdl.                 .;o;.         .;odd;.                         \n");
    addstr("                        .ldOOOOOOOdl.                   .             ...                           \n");
    addstr("                         .;dddddddol.                                                               \n");
    addstr("                           .,llldxxxdlll:,.                                                         \n");
    addstr("                             .,loddddddd;.                                                          \n");
    addstr("                              .lllllllll.                                                           \n");
    update();
    addstr("                                                                             .........              \n");
    addstr("                                                               .,,,,,.       .'........   .,,,.     \n");
    addstr("                                                             .,lxxxdl'  ..  ...,c:cc,'..';lxdl'     \n");
    addstr("                                                             'ldOOOdl' ........',:oolc::oxxxl,.     \n");
    addstr("                                                           .,lxxxkOdl,...........',,,,lxxxl;,...    \n");
    addstr("                                                           .ldOxoxOkx:................,:ldl:;'...   \n");
    addstr("                                                           .ldOdldOOOxo,................,;clcc;'..  \n");
    addstr("                                                           .ldOkxkOOOOO:..................',:ol:,.. \n");
    addstr("                                                           .;oOOOOOl.............................   \n");
    addstr("                                                           .':oxOOOdlll,......   ,ooooool:.         \n");
    addstr("                            .........                       .,ldOOOl...ckl,. ;kkkc.'lOOOdl.         \n");
    addstr("                        .................                   .,ldOOOdlllOMO:. .,,,.  ;OOOxl.         \n");
    addstr("                    ........,:::::::,......                 .,ldOOOOOOOXMO:.   ,k,  ;OOOdl'         \n");
    addstr("                  ........,:llloolooc:,.....                ..;coxOOOOO0KKKo'. .,.  ;OOOdl:,.       \n");
    addstr("               .........,:clc;;;;;;;;;::,...                ..';ldOOOOOl'oKKKOkkk,  ;OOOkxdl.       \n");
    addstr("              ........,:clc;,''.......';;:,..              ...';ldOOOOOdldO0KKKKKxllodxOOOdl.       \n");
    addstr("             .......,:coc;'.............,;::'.            ..'..,ldOOOOOOOOOOOOOOOOOOkxdddd;.        \n");
    addstr("           .........;oc;,'........     ...,lc;;,,,,,,,,.  ..'..;ldOOOOOOOxdddooddddddd;...          \n");
    addstr("         .........,:ll:'.......           'ldxdodxxolll:,;;::::cldOOOOOOOdl,..........              \n");
    addstr("        ..........;loo:'......            'loxkkkxxxxdldxoloxxxxxkOOOOOOOdl.                        \n");
    addstr("       ........,::clc;,.....            .,lxdodxkkkxddxkOkxddxOOOOOOOOOOOdl.                        \n");
    addstr("      .........;ollo:'....            .,lxkOkxdodxxxxddxOOOdldOOOOOOOOOOOdl.                        \n");
    addstr("     ..........;ooc;,'....            .ldOOOkdolloooddxkOxodxkOOOOOOOOOxd;.                         \n");
    addstr("    .........,:clo:''.....            .ldOOOxodkxxxxxdodddxkOOOOOOOOOOOdl.                          \n");
    addstr("   ..........;lloo:'....              .lkN0dxxxdONNKOkxxxkOOOOOOOOOOOxd;.                           \n");
    addstr("    .........;looo:'....              .lxKOxkOkkOKKkoxOOOOOOOOOOOOOxd;.                             \n");
    addstr("      .......;llll:'....              'ldOOOOOxddddolodddddodddxOxdol'                              \n");
    addstr("        .....',:llcc;'...         .,,,:ldOOOxdoododoool,.....,ldOkxxxl,,,.                          \n");
    addstr("          .....;loll:'....        .ldxxxkOxoolodddddoll'   .,:ldOOOOOkxxxl,.                        \n");
    addstr("            ...;llll:'....      .,lxkOOOxd;.,loddddol,.    'looddodddxOOOdl.                        \n");
    addstr("              ..'';l:'''..    .,lxkOOOxo;.  'loddddol'   .,cddddoolllodxOkxl,.                      \n");
    addstr("                ..,olc;'..    'ldOOOxd;.    'loddddol'   'lodddddol,.,ldOOOdl.                      \n");
    addstr("                  .':o:'..  .,lxkOOOdl.     .loddddol:,,,cddddddo;.  .ldOOOdl.                      \n");
    addstr("                    .'''...,lxkOOOOOdl.     'loddddolodddddddddol' .,lxkOOOkxl,.                    \n");
    addstr("                       .';lxkOOOOOxd;.      'loddddoloddddddddo;.  .ldOOOOOOOdl.                    \n");
    addstr("                        'ldOOOOOOOdl.        .;oooollodddddddol'   'ldOOOOOOOdl'                    \n");
    addstr("                        .ldOOOOOOOdl.          ....,loddddooo;.     .;dxOOOxd;.                     \n");
    addstr("                        .ldOOOOOxd;.                .;ooo;...        'ldOOOdl.                      \n");
    addstr("                        .lodddddol.                   ...             .;oddol.                      \n");
    addstr("                         .,lllllll:,.                                   .....                       \n");
    addstr("                           .,llldxxxdlll:,.                                                         \n");
    addstr("                             .,loddddddd;.                                                          \n");
    addstr("                              .lllllllll.                                                           \n");
    update();
    addstr("                                                                             .........              \n");
    addstr("                                                                             .........              \n");
    addstr("                                                               .,,,,,.       .'........   .,,,.     \n");
    addstr("                                                             .,lxxxdl'  ..  ...,:c::;'..';lxdl.     \n");
    addstr("                                                             'ldOOOdl' ........',:lolc::oxxxl,.     \n");
    addstr("                                                           .,lxxxkOdl;...........',,,,lxxxl;,...    \n");
    addstr("                                                           'ldOxoxOkx:................,:ldlc;'...   \n");
    addstr("                                                           .ldOdldOOOxo,................';cllc;'..  \n");
    addstr("                                                           .ldOkxkOOOOO:..................',:lcc,.. \n");
    addstr("                                                           .,oOOOOOl..'..........................   \n");
    addstr("                                                           .':dxOOOdlll,......   ,ooooool:.         \n");
    addstr("                            .........                       .,ldOOOl...ckl,. ;kkkc.'lOOOdl.         \n");
    addstr("                        .................                   .,ldOOOdlllOMO:. .,,,.  ;OOOdl.         \n");
    addstr("                    ........,:::::::,......                 .,ldOOOOOOOXMO:.   ,k,  ;OOOdl.         \n");
    addstr("                  ........,:cllllollc:,.....                ..;cdxOOOOO0KKKo'. .,.  ;OOOdl:,.       \n");
    addstr("               .........,:coc;;;;;;;;;::,...                ..';ldOOOOOl'oKKKOkkk,  ;OOOkxdl.       \n");
    addstr("              ........,:cl:;,''.......';::,..              ...';ldOOOOOdldO0KKKKKxlcodxOOOdl'       \n");
    addstr("             .......,:cl:;,.............';::'.            ..'..,ldOOOOOOOOOOOOOOOOOOkxdddd;.        \n");
    addstr("           .........;lc;,'........     ...,lc;;,,,,,,,,.  ..'..;ldOOOOOOOxdddddddooodd;...          \n");
    addstr("         .........,:cl:''......           'loxdddxxdlll:,;;::::cldOOOOOOOdl,..........              \n");
    addstr("        ..........;loo:'......            .ldxkkkxxxxdldxoldxxxxxkOOOOOOOdl'                        \n");
    addstr("       ........,::coc;'.....            .,lxdodxkkkxddxkOkxddxOOOOOOOOOOOdl.                        \n");
    addstr("      .........;lllo:'....            .,lxkOkxdodxxxxddxOOOdldOOOOOOOOOOOdl.                        \n");
    addstr("     ..........;olc;,'....            .ldOOOkdolloooodxkOxddxkOOOOOOOOOxd;.                         \n");
    addstr("    .........,:col:'......            .ldOOOxldkxxxxxdddddxkOOOOOOOOOOOdl.                          \n");
    addstr("   ..........;oooo:'....              .lkN0dxkxdONNOodxxxkOOOOOOOOOOOxd;.                           \n");
    addstr("    .........;oooo:'....              .lxKOkkOkkkxxxxkOOOOOOOOOOOOOxd;.                             \n");
    addstr("      .......;oooo:'....            .,:ldOOOOOxdolloddodddoddodxOxd;.                               \n");
    addstr("        .....',:ollc,'...         .,lxxxkOOOxdooooddoolll,.,llldOkxl,.                              \n");
    addstr("          .....;ollo:'....      .,lxkOOOxdddolodddddo;...  'llldOOOdl.                              \n");
    addstr("            ...;llol:'....    .,lxkOOOxd;...,loddddol'     'lodooxOkxl,.                            \n");
    addstr("              ..'':l:''...  .,lxkOOOOOdl'   'loddddol'   .,cdddoldOOOdl.                            \n");
    addstr("                ..,olc;'...,lxkOOOOOxd;.    'loddddol'   'lodddoldOOOkxl,.                          \n");
    addstr("                  .':o:',;lxkOOOOOOOdl.     'loddddol:,,,cdddddolodxOOOdl'                          \n");
    addstr("                    .',:oxkOOOOOOOxd;.      'loddddddolodddddddollldOOOkxl,.                        \n");
    addstr("                      'ldOOOOOOOxd;.        'lodddddooddddddddo;...;dxOOOkxl,.                      \n");
    addstr("                      'ldOOOOOOOdl'          .;oooollodddddddol'   .ldOOOOOkxl,.                    \n");
    addstr("                       .;dxOOOxd;.             ....,loddddddo;.     .;dxOOOOOkxl,.                  \n");
    addstr("                         .;ddd;.                    .;ooooo;.        .ldOOOOOOOdl.                  \n");
    addstr("                           ...                        .....           .;dxOOOOOdl.                  \n");
    addstr("                                                                       'loddddo;.                   \n");
    addstr("                              .,,,,,,,,,.                               .......                     \n");
    addstr("                              'lllllllll.                                                           \n");
    update();
    addstr("                                                                             .........              \n");
    addstr("                                                                             .........              \n");
    addstr("                                                               .,,,,,.       .'........   .,,,.     \n");
    addstr("                                                               .lllll.       .........    'lll.     \n");
    addstr("                                                             .,lxxxdl'  ..   .......... .,lxol'     \n");
    addstr("                                                             .ldOOOdl' ..........,cc;.,;lxxxc..     \n");
    addstr("                                                           .,lxxxkOdl;...........',,'.cxxxl;'..     \n");
    addstr("                                                           .ldOxoxOkx:................,:ld:.''..    \n");
    addstr("                                                           .ldOdldOOOxo,................';:c;'...   \n");
    addstr("                                                           .;oOkxkOOOOO:..................',;c;'..  \n");
    addstr("                                                           .':dxOOOl........................;llc,.. \n");
    addstr("                                                            .,ldOOOdlll,......   ,ooooool:. .....   \n");
    addstr("                                                            .,ldOOOl...ckl,. ;kkkc..lOOOdl.         \n");
    addstr("                                                            .,ldOOOdlllOMO:. .,;,.  ;OOOdl'         \n");
    addstr("                          ...........                       ..;cdxOOOOOXMO:.   ,k,  ;OOOdl'         \n");
    addstr("                      ......,:::::,......                   ..';ldOOOOO0KKKo'. .,.  ;OOOdl:,.       \n");
    addstr("                  ......,:::coooooc:::,....                ...';ldOOOOOl.oKKKOkkk,  ;OOOkxdl'       \n");
    addstr("               .......,:clllc;;;;;;;;;;:,...              ..'..,ldOOOOOdldO0KKKKKxllodxOOOxl.       \n");
    addstr("             .......,:coc;;;,.........';::,..             ..'..;ldOOOOOOOOOOOOOOOOOOkxdodd;.        \n");
    addstr("           .......,:coc;'...............';;:;;;,,,,,,,,.  ..''';ldOOOOOOOxoddddddddddd;...          \n");
    addstr("         .........;oc;,'..........     ...,ldxdodxxdlll:,;;::::clxOOOOOOOdl,..........              \n");
    addstr("       ........,::cl:''.......          .;:ldxkkkxxxxoldxdloxxxxxkOOOOOOOdl.                        \n");
    addstr("      .........;llol:'......            .loxdodxkkkxddxkOkxddxOOOOOOOOOOOdl.                        \n");
    addstr("     ........,:cloc;'.....            .,lxkOkxdodxxxxddxOOOdldOOOOOOOOOOOdl.                        \n");
    addstr("    .........;llll:'....              'ldOOOxdolooooddxkOxddxkOOOOOOOOOxd;.                         \n");
    addstr("   ..........;oc;,,'....              .ldOOOxodxxxxxxdddddxkOOOOOOOOOOOdl.                          \n");
    addstr("  .........,:lo:''......              .lkNOdxkxdONNOddxxxkOOOOOOOOOOOxd;.                           \n");
    addstr(" ..........;ooo:''....                .lxKOkkOdldxkxxkOOOOOOOOOOOxddo;.                             \n");
    addstr("  .........;ooo:''....            .,,,:ldOOOxdooolloodddddoododxOdl,.                               \n");
    addstr("    .......;ooo:''....          .,lxxxxxddddoloddooolll,...,llldOdl.                                \n");
    addstr("      .....;ooo:''....        .,lxkOOOxd;...,loddddol,.    'llldOkxl,.                              \n");
    addstr("      .....;ooo:''....      .,lxkOOOxd;.    'loddddddc,.   'llldOOOdl.                              \n");
    addstr("        ...;olo:''....    .,lxkOOOOOdl.     .loddddddol:,,,cdoldOOOdl.                              \n");
    addstr("          ..';o:''''..  .,lxkOOOOOxd;.      'loddddddolllodddoldOOOkxl,.                            \n");
    addstr("             .';cc;'...,lxkOOOOOOOdl.       'loddddddoloddddddoodxOOOdl.                            \n");
    addstr("               .''''..,ldOOOOOOOxd;.         .;odddddoloddddddolldOOOkxl,.                          \n");
    addstr("                   ...,ldOOOOOxd;.            'llooddoloddddolllldOOOOOdl.                          \n");
    addstr("                     ...;odddd;.               ....;olllooo;...,lxOOOOOkxl,.                        \n");
    addstr("                         .....                      .......     .;dxOOOOOdl'                        \n");
    addstr("                                                                 'ldOOOOOkxl,.                      \n");
    addstr("                                                                 .ldOOOOOOOdl.                      \n");
    addstr("                                                                  .;odoodddol.                      \n");
    addstr("                                                                   .llcllllll'                      \n");
    update();
    addstr("                                                                             .........              \n");
    addstr("                                                                             .........              \n");
    addstr("                                                               .,,,,,.       .'........   .,,,.     \n");
    addstr("                                                               .lllll.       .........    'lll.     \n");
    addstr("                                                             .,lxxxdl'  ..   .......... .,lxol'     \n");
    addstr("                                                             .ldOOOdl' ..........,cc;.,;lxxxc..     \n");
    addstr("                                                           .,lxxxkOdl;...........',,'.cxxxl;'..     \n");
    addstr("                                                           .ldOxoxOkx:................,:ld:.''..    \n");
    addstr("                                                           .ldOdldOOOxo,................';:c;'...   \n");
    addstr("                                                           .ldOkxkOOOOO:..................',;c;'..  \n");
    addstr("                                                           .;oOOOOOl........................;llc,.. \n");
    addstr("                                                           .':dxOOOdlll,......   ,ooooool:. .....   \n");
    addstr("                                                            .,ldOOOl...ckl,. ;kkkc..lOOOdl.         \n");
    addstr("                                                            .,ldOOOdlllOMO:. .,;,.  ;OOOdl'         \n");
    addstr("                                                            .,ldOOOOOOOXMO:.   ,k,  ;OOOdl'         \n");
    addstr("                          ...........                       ..,cdxOOOOO0KKKo'. .,.  ;OOOdl:,.       \n");
    addstr("                      ......,:::::,......                   ..';ldOOOOOl.oKKKOkkk,  ;OOOkxdl'       \n");
    addstr("                  ......,:::clooolc:::,....                ...';lxOOOOOdldO0KKKKKxllodxOOOxl.       \n");
    addstr("               .......,:llloc;;;;;;;;;;:,...              ..'..,ldOOOOOOOOOOOOOOOOOOkxdodd;.        \n");
    addstr("             .......,:clc;;;'.........';;::;;,,,,,,.      ..'..;ldOOOOOOOxoddddddddddd;...          \n");
    addstr("           .......,:coc;'...............';:ldxdodxxl,,,,,...''';ldOOOOOOOdl,..........              \n");
    addstr("         .........;oc;,''.........     ...,ldxkkkxxxxoldxl;::::oxkOOOOOOOdl.                        \n");
    addstr("       ........,::co:''.......            'llodxkkkxddxkOkxoldxkOOOOOOOOOdl.                        \n");
    addstr("      .........;lool:'......            .,lxOKkodxxxxddxOOOdldOOOOOOOOOOOdl.                        \n");
    addstr("     ........,:cloc;'.....            .,lxkO0KklloooodxkOxddxkOOOOOOOOOOOdl'                        \n");
    addstr("    .........;llol:'....              .ldOOOkdoolllkKkddddxkOOOOOOOOOOOxd;.                         \n");
    addstr("   ..........;oc;;,'....              .ldOOOxldkkkxOKOxxxkOOOOOOOOOOOOOdl.                          \n");
    addstr("  .........,:co:''......              .lkNOdxkxd0NNOdxOOOOOOOOOOOOOOOxd;.                           \n");
    addstr(" ..........;oll:''....                .lxKOxkOkkkxkxxkOOOOOOOOOOOOOxo;.                             \n");
    addstr("  .........;ooo:''....            .,,,:ldOOOxdddollooddddooodxOOOxool'                              \n");
    addstr("    .......;ooo:''....          .,lxxxxxdddd;...,llooodol,.,ldOOOdlodc,.                            \n");
    addstr("      .....;ooo:''....        .,lxkOOOxdol,.  .,cddddddol' .ldOOOdlodol'                            \n");
    addstr("      .....;loo:''....      .,lxkOOOOOdl,.    'loddddddol' .ldOOOdlodol'                            \n");
    addstr("        ...;ooo:''....    .,lxkOOOOOxd;.      'loddddddol' .ldOOOkxdoll'                            \n");
    addstr("          ..':l:'''...  .,lxkOOOOOOOdl'        .;ooddddol:,:ldOOOOOdlll'                            \n");
    addstr("             .';cc;'..  .ldOOOOOOOxd;.          'llodddddollldOOOOOdl,.                             \n");
    addstr("               .''''..  'ldOOOOOxd;.            'llodddddollldOOOOOdl'                              \n");
    addstr("                   ...  'lxOOOOOdl.             'llodddddollldOOOOOkxl,.                            \n");
    addstr("                     .   .;ddddd;.              'llodddddollldOOOOOOOdl'                            \n");
    addstr("                           .....                .llodddoolllldOOOOOOOdl:,.                          \n");
    addstr("                                                 ..;ooo;.....;dxOOOOOkxdl.                          \n");
    addstr("                                                    ...      .loddddodool.                          \n");
    addstr("                                                             'lllllllllll.                          \n");
    update();
    addstr("                                                                             .........              \n");
    addstr("                                                                             .........              \n");
    addstr("                                                               .,,,,,.                    .,,,.     \n");
    addstr("                                                             .,lxxxdl.        ..        .,lxdl.     \n");
    addstr("                                                             'ldOOOdl:,...   .........',lxxx:.      \n");
    addstr("                                                           .,lxxxkOdl;...........,::::oxxxl;.       \n");
    addstr("                                                           'ldOxoxOkx:...........',,,,lxxd:....     \n");
    addstr("                                                           .ldOdldOOOc................';co:'''..    \n");
    addstr("                                                           .ldOkxkOOOxo,................',;c;'...   \n");
    addstr("                                                           .,oOOOOOl......................',;c;'..  \n");
    addstr("                                                           .':oxOOOdlll,....................;llc,.. \n");
    addstr("                                                           .';ldOOOl.........lOOO:  ,oool:. .....   \n");
    addstr("                                                            .,ldOOOdllldkl,. .,,,.  ;OOOdl.         \n");
    addstr("                                                            .,ldOOOOOOOXMO:.   ,k,  ;OOOdl.         \n");
    addstr("                          ...........                       ..;cdxOOOOO0KKKo'. .,.  ;OOOdl:,.       \n");
    addstr("                      ......,:::::,......                   ..';ldOOOOOl'oKKKOkkk,  ;OOOkxdl.       \n");
    addstr("                  ......,:::coooooc:::,....                 ..';ldOOOOOdldO0KKKKKxlcodxOOOdl'       \n");
    addstr("               .......,:clllc;;;;;;;;;;:,...               ...';ldOOOOOOOOOOOOOOOOOOkxdddd;.        \n");
    addstr("             .......,:coc;;;,.........';::,..             ..'..,ldOOOOOOOxdddddddooodd;...          \n");
    addstr("           .......,:coc;'...............';;:;;;,,,,.      ..'..;ldOOOOOOOdl,..........              \n");
    addstr("         .........;oc;,'..........     ...,loxdodxxl,,,,,...''';ldOOOOOOOdl'                        \n");
    addstr("       ........,::cl:''.......            'ldxkkkxxxxoldxl;::::oxkOOOOOOOdl.                        \n");
    addstr("      .........;llol:'......            .,lxdodxkkkxddxkOkxoldxkOOOOOOOOOdl.                        \n");
    addstr("     ........,:cloc;'.....              .ldO0KkodxxxxddxOOOdldOOOOOOOOOOOdl.                        \n");
    addstr("    .........;llll:'....              .,lxkO0KklloooodxkOxddxkOOOOOOOOOOOdl'                        \n");
    addstr("   ..........;oc;,,'....              .ldOOOkdoolllkKkddddxkOOOOOOOOOOOxd;.                         \n");
    addstr("  .........,:lo:''......              .ldOOOxldkkkxOKOxxxkOOOOOOOOOOOOOdl.                          \n");
    addstr(" ..........;ooo:''....                .lkNOdxkxd0NNOdxOOOOOOOOOOOOOOOxd;.                           \n");
    addstr("  .........;ooo:''....              .,:ldxxkkOxldxxxxkOOOOOOOxdxOxdddol:,.                          \n");
    addstr("    .......;ooo:''....              'ldxxxkOxd;.,llooddoddddodxkOdlooodol:;.                        \n");
    addstr("      .....;ooo:''....            .,lxkOOOxo;.',cooodol,...,ldOOOdlodddddol'                        \n");
    addstr("      .....;ooo:''....          .,lxkOOOxd;..,cddddddol'   'ldOOOdlodddddol'                        \n");
    addstr("        ...;olo:''....        .,lxkOOOOOdl' 'loddddddol' .,lxkOOOdlodddddol'                        \n");
    addstr("          ..';o:''''..      .,lxkOOOOOxd;.  'loddddddol' .ldOOOOOdloddddo;.                         \n");
    addstr("             .';cc;'..    .,lxkOOOOOOOdl.   'loddddddol' .ldOOOOOdlodddol'                          \n");
    addstr("               .''''..    'ldOOOOOOOxd;.    'loddddddol:,lxkOOOOOdlodddol'                          \n");
    addstr("                   ...    'ldOOOOOOOdl'     'loddddddollldOOOOOOOdloddo;.                           \n");
    addstr("                     .     .;dxOOOxd;.      'loddddddollldOOOOOOOdllo;.                             \n");
    addstr("                            .loddd;.        'loddddddollldOOOOOOOdl,.                               \n");
    addstr("                             .....          'loddddddollldOOOOOOOdl.                                \n");
    addstr("                                             .;oooooolllldOOOOOOOkxl,.                              \n");
    addstr("                                               ........,loddddddddo;.                               \n");
    addstr("                                                       'lllllllllll.                                \n");
    update();
    addstr("                                                                             .... ...               \n");
    addstr("                                                               .,,,,,.                    .,,,.     \n");
    addstr("                                                             .,lxxxdl.        ..        .,lxdl.     \n");
    addstr("                                                             'ldOOOdl:,...   .........',lxxx:.      \n");
    addstr("                                                           .,lxxxkOdl;...........,::::oxxxl;.       \n");
    addstr("                                                           .ldOxoxOkx:...........',,,,lxxd:....     \n");
    addstr("                                                           .ldOdldOOOc................';co:'.'..    \n");
    addstr("                                                           .ldOkxkOOOxo,................',;c;'...   \n");
    addstr("                                                           .,oOOOOOl..'...................',;c;'..  \n");
    addstr("                                                           .':dxOOOdlll,....................;lcc,.. \n");
    addstr("                                                           .';ldOOOl.........lOOO:  ,oool:. .....   \n");
    addstr("                                                            .,ldOOOdllldkl,. .,,,.  ;OOOdl'         \n");
    addstr("                            .........                       .,ldOOOOOOOXMO:.   ,k,  ;OOOdl'         \n");
    addstr("                        .................                   ..;cdxOOOOO0KKKo'. .,.  ;OOOdl:,.       \n");
    addstr("                    ........,:::::::,......                 ..';ldOOOOOl'oKKKOkkk,  ;OOOkxdl.       \n");
    addstr("                  ........,:coooooooc:,.....                ..';ldOOOOOdldO0KKKKKxllodxOOOdl.       \n");
    addstr("               .........,:clc;;;;;;;;;;:,...               ...';ldOOOOOOOOOOOOOOOOOOkxdddd;.        \n");
    addstr("               .......,:coc;,''.......';;:,..             ..'..,ldOOOOOOOxdddooddddddd;...          \n");
    addstr("             .......,:clc;'.............,;;:;;;,,,,.      ..'..;ldOOOOOOOdl,..........              \n");
    addstr("           .........;lc;,'........     ...,ldxdodxxl,,,,,...''';ldOOOOOOOdl.                        \n");
    addstr("         .........,:cl:'.......           'loxkkkxxxxdldxl;::::oxkOOOOOOOdl.                        \n");
    addstr("        ..........;ooo:'......            'llodxkkkxddxkOkxdldxkOOOOOOOOOdl.                        \n");
    addstr("       ........,::coc;'.....            .,lxOKkodxxxxddxOOOdldOOOOOOOOOOOdl.                        \n");
    addstr("      .........;oolo:'....              .ldO0KklloooodxkOxddxkOOOOOOOOOOOdl.                        \n");
    addstr("     ..........;olc;,'....              .ldOkdoolllkKkdoodxkOOOOOOOOOOOxd;.                         \n");
    addstr("    .........,:col:''.....              .ldOkxdodkkOKOxxxkOOOOOOOOOOOOOdl'                          \n");
    addstr("   ..........;ollo:'....                .lkN0dxkxddONOdxOOOOOOOOOOOOOxo;.                           \n");
    addstr("    .........;ollo:'....                .lxKOkkOkkkkxxxkOOOOOOOOOxoddolc:;,.                        \n");
    addstr("      .......;llll:'....              .,:ldOOOOOxdoolooddoddoodxOdlodooddddc,.                      \n");
    addstr("        .....',:ollc;....           .,lxxxkOOOxodooodol,...,loxkOdlloooddddol'                      \n");
    addstr("          .....;ollo:'....          'ldOOOOOxdooddddo;.  .,lxkOxd;...,lodddol'                      \n");
    addstr("            ...;lllo:'....        .,lxkOOOxoooddooo;.  .,lxkOOOdl. .,coddddol'                      \n");
    addstr("              ..'':o:'''..        .ldOOOOOdlodddoll'   'ldOOOxd;..,cdddddddol'                      \n");
    addstr("                ..,llc;'..      .,lxkOOOxoodddddoll' .,lxkOOOdl. 'lodddddddol'                      \n");
    addstr("                  .':o:'..    .,lxkOOOOOdlodddddoll' 'ldOOOOOdl. 'lodddddoo;.                       \n");
    addstr("                    .'''..    'ldOOOOOOOdlodddddoll:,lxkOOOOOdl. 'lodddddol'                        \n");
    addstr("                       ...    'ldOOOOOxdolodddddolllldOOOOOxd;.   .;odddoll'                        \n");
    addstr("                         .     .;oxOOOdlllodddddolldxkOOOOOdl.     'lloll,.                         \n");
    addstr("                                'looddolodddddddolldOOOOOOOdl.      .....                           \n");
    addstr("                                 .....,lodddddddolldOOOOOOOdl.                                      \n");
    addstr("                                       .;ooooooollldOOOOOOOdl.                                      \n");
    addstr("                                         ..........;odoodddol.                                      \n");
    addstr("                                                   .llcllllll'                                      \n");
    update();
    addstr("                                                               'lllll.                    'lll'     \n");
    addstr("                                                             .,lxxxdl.        ..        .,lxdl'     \n");
    addstr("                                                             .ldOOOdl:,...   .........',lxxx:.      \n");
    addstr("                                                           .,lxxxkOdl;...........,::::oxxxl;.       \n");
    addstr("                                                           'ldOxoxOkx:...........',,,,lxxd:....     \n");
    addstr("                                                           'ldOdldOOOc................';co:..'..    \n");
    addstr("                                                           'ldOkxkOOOxo,................',;c;'...   \n");
    addstr("                                                           .,oOOOOOl......................',;c;'..  \n");
    addstr("                                                           .':dxOOOdlll,....................;ol:,.. \n");
    addstr("                                                           .';ldOOOl.........lOOO:  ,oool:. .....   \n");
    addstr("                                                            .,ldOOOdllldkl,. .,,,.  ;OOOdl.         \n");
    addstr("                          ...........                       .,ldOOOOOOOXMO:.   ,k,  ;OOOdl.         \n");
    addstr("                      ......,:::::,....                     ..,cdxOOOOO0KKKo'. .,.  ;OOOdl:,.       \n");
    addstr("                  ........,:clooolc:::,..                   ..';ldOOOOOl'oKKKOkkk,  ;OOOkxdl.       \n");
    addstr("                ........,:coolc;;;;;;;;:,..                 ..';ldOOOOOdldO0KKKKKxllodxOOOdl.       \n");
    addstr("               .......,:coc;;;'.......';::,..              ...';ldOOOOOOOOOOOOOOOOOOkxddod;.        \n");
    addstr("              ......,:clc;'.............';::'.            ..'..,ldOOOOOOOxddddoddddodd;...          \n");
    addstr("             .......;lll:'................,lc;;,,,,.      ..'..;ldOOOOOOOdl,..........              \n");
    addstr("            ........;l:;,'..........     .,loxdodxxl,,,,,...''';ldOOOOOOOdl.                        \n");
    addstr("           .......,:lo:''.......          'loxkkkxxxxdldxl;::::oxkOOOOOOOdl.                        \n");
    addstr("          ........;lll:'......            'llodxkkkxddxkOkxdloxkOOOOOOOOOdl.                        \n");
    addstr("         ......,::loc;'.....            .,lxxxdodxxxxddxOOOdldOOOOOOOOOOOdl.                        \n");
    addstr("        .......;oooo:'....              .ldOOOxlooloddxkOxodxkOOOOOOOOOOOdl.                        \n");
    addstr("        .......;lllo:'....              .ldOOOkkdlldxdddddxkOOOOOOOOOOOxd;.                         \n");
    addstr("        .......;lllo:'....              .lxOKNOdxxkxdOKOxkOOOOOOOOOOOOOdl.                          \n");
    addstr("    .  ........;oooo:'....               .;dkKOkkOOkxOKkdxOOOOOOOOOOOxool:,.                        \n");
    addstr("   ............;oooo:'....                'ldOOOOOOOOxddxkOOOOOOOxddooooddoc;.                      \n");
    addstr("    .   .......;oooo:'....              .,:ldOOOOOOxdolodddddxOOOdlllodddddol'                      \n");
    addstr("          .....;ooll:'....              .ldxkOOOxddol,.....,ldOOOxl,.;oodddol'                      \n");
    addstr("            ...;ollo:'....            .,lxkOOOxdoll,.    .,lxkOxd;.  'lodddol'                      \n");
    addstr("              .;looo:'....            .ldOOOxdol,..      .ldOOOdl' .,cdddddol'                      \n");
    addstr("               .'':olc;...            .ldOOOdl,.       .,lxkOOOdl. 'lodddddol'                      \n");
    addstr("                  ..:o:'..            'ldOOOdl.        .ldOOOOOdl. 'lodddddol'                      \n");
    addstr("                    .';c,..         .,lxkOOOdl.      .,lxkOOOOOdl. 'lodddddol'                      \n");
    addstr("                      .'''..        .ldOOOOOdl.    .,lxkOOOOOxd;.  'loddddo;.                       \n");
    addstr("                         ...      .,:ldOOOOOdl.    'ldOOOOOOOdl.    .;ooo;.                         \n");
    addstr("                           .      'llldOOOOOdl. .,,lxkOOOOOxd;.       ...                           \n");
    addstr("                                  'looooxOxo;.  'lldOOOOOOOdl'                                      \n");
    addstr("                                  .loddoodol'   .lldOOOOOxd;.                                       \n");
    addstr("                                  'loddddool'    ..;dodddol.                                        \n");
    addstr("                                  'lloooooll'       .......                                         \n");
    addstr("                                   .........       .,,,,,,,,,.                                      \n");
    addstr("                                                   'lllllllll.                                      \n");
    update();
    addstr("                                                               'lllll.       .........    .lll'     \n");
    addstr("                                                             .,lxxxdl.  ..   .......... .,lxdl.     \n");
    addstr("                                                             .ldOOOdl' ..........;cc;',;lxxxc..     \n");
    addstr("                                                           .,lxxxkOdl,...........',,'.cxxxl;'..     \n");
    addstr("                                                           .ldOxoxOkx:................,:ld:..'..    \n");
    addstr("                                                           .ldOdldOOOxo,................';:c;'...   \n");
    addstr("                                                           .ldOkxkOOOOO:..................',;c;'..  \n");
    addstr("                                                           .;oOOOOOl........................;llc,.. \n");
    addstr("                                                           .':dxOOOdlll,......   ,odooool:. .....   \n");
    addstr("                                                            .,ldOOOl.''ckl,. ;kkkc.'lOOOdl.         \n");
    addstr("                          ...........                       .,ldOOOdlllOMO:. .,,,.  ;OOOdl.         \n");
    addstr("                      ......,:::::,....                     .,ldOOOOOOOXMO:.   ,k,  ;OOOdl.         \n");
    addstr("                  ........,:collloc:::,..                   ..;cdxOOOOO0KKKo'. .,.  ;OOOdl:,.       \n");
    addstr("                ........,:clloc;;;;;;;;:,..                 ..';ldOOOOOl'oKKKOkkk,  ;OOOkxdl.       \n");
    addstr("               .......,:coc;;;,.......';::,..              ...';ldOOOOOdldO0KKKKKxllodxOOOdl.       \n");
    addstr("              ......,:clc;'.............';;:'.            ..'..,ldOOOOOOOOOOOOOOOOOOkxddod;.        \n");
    addstr("             .......;oll:'................,lc;;,,,,.      ..'..;ldOOOOOOOxddddoddddodd;...          \n");
    addstr("            ........;oc;,'..........     .,ldxdodxxl,,,,,...''';ldOOOOOOOdl,..........              \n");
    addstr("           .......,:ll:'........          'ldxkkkxxxxdldxl;::::oxkOOOOOOOdl.                        \n");
    addstr("          ........;loo:'......            'llodxkkkxodxkOkxdldxkOOOOOOOOOdl.                        \n");
    addstr("         ......,::clc;'.....              'loxdodxxxxdoxOOOdldOOOOOOOOOOOdl.                        \n");
    addstr("        .......;oooo:'....                .ldOxlloooodxkOxodxkOOOOOOOOOOOdl.                        \n");
    addstr("        .......;oooo:'....                .ldOkxdlldxdddddxkOOOOOOOOOOOxd;.                         \n");
    addstr("        .......;oooo:'....                .lkN0dxkkxdOKOxkOOOOOOOOOOOOOdl.                          \n");
    addstr("       ........;oooo:'....                .lxKOkkOOkxOKkdxOOOOOOOOOOOxd;.                           \n");
    addstr("    ...........;oooo:'....                'lodxOOOOOOxddxkOOOOOOOOOxdol:;,,.                        \n");
    addstr("   ...  .......;oooo:'....              .,:ldxkOOOOOOdlodddddxOOOxdoloodddoc;.                      \n");
    addstr("    .     .....;oooo:'....              .ldxkOOOxdddd;.....,ldOOOdlllloddddol'                      \n");
    addstr("            ...;oooo:'....            .,:ldOOOxooll,.      'ldOOOdl,.,lodddol'                      \n");
    addstr("              .;oool:'....            'llldOOOdl,..      .,lxkOxd;.  'lodddol'                      \n");
    addstr("               .'';olc;...          .,cdoldOOOdl.        .ldOOOdl' .,cdddddol'                      \n");
    addstr("                  .':l:'..        .,coddoldOOOdl.        .ldOOOdl. 'lodddddol'                      \n");
    addstr("                    .';c,..       'lodoodxkOOOdl.      .,lxkOOOdl. 'lodddddol'                      \n");
    addstr("                      .'''..    .,cdddoldOOOOOdl.    .,lxkOOOOOdl. 'lodddddol'                      \n");
    addstr("                         ...    'lodddoldOOOOOdl.  .,lxkOOOOOOOdl. 'lodddoo;.                       \n");
    addstr("                              .,cdddddolodxOOOdl:,,lxkOOOOOOOxd;.   .;oooll'                        \n");
    addstr("                              'lodddddol,.;oddolllldOOOOOOOxo;.       .....                         \n");
    addstr("                              'lodddddol'  ........;dxOOOxd;.                                       \n");
    addstr("                               .;oooooll'           .;doo;.                                         \n");
    addstr("                                 .,looddl:;,.      .,:lll:,.                                        \n");
    addstr("                                  'lloooooll'       .......                                         \n");
    addstr("                                   .........       .,,,,,,,,,.                                      \n");
    addstr("                                                   'lllllllll.                                      \n");
    update();
    addstr("                                                                             .........              \n");
    addstr("                                                               .,,,,,.       .'........   .,,,.     \n");
    addstr("                                                             .,lxxxdl'  ..  ...,c:cc,'..';lxdl'     \n");
    addstr("                                                             'ldOOOdl' ........',:oolc::oxxxl,.     \n");
    addstr("                                                           .,lxxxkOdl,...........',,,,lxxxl;,...    \n");
    addstr("                                                           .ldOxoxOkx:................,:ldl:;'...   \n");
    addstr("                                                           .ldOdldOOOxo,................,;clcc;'..  \n");
    addstr("                                                           .ldOkxkOOOOO:..................',:ol:,.. \n");
    addstr("                                                           .;oOOOOOl.............................   \n");
    addstr("                                                           .':oxOOOdlll,......   ,ooooool:.         \n");
    addstr("                            .........                       .,ldOOOl...ckl,. ;kkkc.'lOOOdl.         \n");
    addstr("                        .................                   .,ldOOOdlllOMO:. .,,,.  ;OOOxl.         \n");
    addstr("                    ........,:::::::,......                 .,ldOOOOOOOXMO:.   ,k,  ;OOOdl'         \n");
    addstr("                  ........,:llloolooc:,.....                ..;coxOOOOO0KKKo'. .,.  ;OOOdl:,.       \n");
    addstr("               .........,:clc;;;;;;;;;::,...                ..';ldOOOOOl'oKKKOkkk,  ;OOOkxdl.       \n");
    addstr("              ........,:clc;,''.......';;:,..              ...';ldOOOOOdldO0KKKKKxllodxOOOdl.       \n");
    addstr("             .......,:coc;'.............,;::'.            ..'..,ldOOOOOOOOOOOOOOOOOOkxdddd;.        \n");
    addstr("           .........;oc;,'........     ...,lc;;,,,,,,,,.  ..'..;ldOOOOOOOxdddooddddddd;...          \n");
    addstr("         .........,:ll:'.......           'ldxdodxxolll:,;;::::cldOOOOOOOdl,..........              \n");
    addstr("        ..........;loo:'......            'loxkkkxxxxdldxoloxxxxxkOOOOOOOdl.                        \n");
    addstr("       ........,::clc;,.....              .llodxkkkxddxkOkxddxOOOOOOOOOOOdl.                        \n");
    addstr("      .........;ollo:'....                'loxdodxxxxddxOOOdldOOOOOOOOOOOdl.                        \n");
    addstr("     ..........;ooc;,'....                'ldOkxdoooddxkOxodxkOOOOOOOOOxd;.                         \n");
    addstr("    .........,:clo:''.....                .lkNOdxxxdloddddxkOOOOOOOOOOOdl.                          \n");
    addstr("   ..........;lloo:'....                  'lxKOxkOOkkxxdldOOOOOOOOOOOxd;.                           \n");
    addstr("    .........;looo:'....                   .;dxOOOOOOOOdldOOOOOOOOOxd;.                             \n");
    addstr("      .......;llll:'....                .,,,lxkOOOOOOxdolodxOOOOOxdol:,,,;,.                        \n");
    addstr("        .....',:llcc;'...               .ldxkOOOxdddd;...,ldOOOxdooodddddol:,.                      \n");
    addstr("          .....;loll:'....            .,:ldOOOxd;....    .ldOOOdlloooodddddol'                      \n");
    addstr("            ...;llll:'....          .,cdoldOOOdl.        .ldOOOdl,...;oddddol'                      \n");
    addstr("              ..'';l:'''..          'lodoldOOOkxl,,.     'ldOOOdl.   'lloddddc,.                    \n");
    addstr("                ..,olc;'..        .,cdddoldOOOOOdll.     .ldOOOdl.   'looddddol'                    \n");
    addstr("                  .':o:'..      .,coddddoldOOOOOdll.   .,:ldOOOdl.   'lodddddol'                    \n");
    addstr("                    .'''..      'loddddolldOOOOOdll. .,:ldxkOOOdl.   'lodddddol'                    \n");
    addstr("                       ...    .,cdddddollldOOOOOdll:,lxxxkOOOOOdl.   'lodddddol'                    \n");
    addstr("                         .    'lodddddollldOOOOOdlllldOOOOOOOxd;.    'lodddddol'                    \n");
    addstr("                              'loddddo;...;dddod;..,ldOOOOOxd;.       .;odddo;.                     \n");
    addstr("                              'lloooll'    .....   'ldOOOxool'          .;oll'                      \n");
    addstr("                               .......             .loood;...             ...                       \n");
    addstr("                                  .,;:::::;,.      .lllll:,.                                        \n");
    addstr("                                  'lloooooll'       .......                                         \n");
    addstr("                                   .........       .,,,,,,,,,.                                      \n");
    addstr("                                                   'lllllllll.                                      \n");
    update();
    addstr("                                                                             .........              \n");
    addstr("                                                                             .........              \n");
    addstr("                                                               .,,,,,.       .'........   .,,,.     \n");
    addstr("                                                             .,lxxxdl'  ..  ...,:c::;'..';lxdl.     \n");
    addstr("                                                             'ldOOOdl' ........',:lolc::oxxxl,.     \n");
    addstr("                                                           .,lxxxkOdl;...........',,,,lxxxl;,...    \n");
    addstr("                                                           'ldOxoxOkx:................,:ldlc;'...   \n");
    addstr("                                                           .ldOdldOOOxo,................';cllc;'..  \n");
    addstr("                                                           .ldOkxkOOOOO:..................',:lcc,.. \n");
    addstr("                                                           .,oOOOOOl..'..........................   \n");
    addstr("                                                           .':dxOOOdlll,......   ,ooooool:.         \n");
    addstr("                            .........                       .,ldOOOl...ckl,. ;kkkc.'lOOOdl.         \n");
    addstr("                        .................                   .,ldOOOdlllOMO:. .,,,.  ;OOOdl.         \n");
    addstr("                    ........,:::::::,......                 .,ldOOOOOOOXMO:.   ,k,  ;OOOdl.         \n");
    addstr("                  ........,:cllllollc:,.....                ..;cdxOOOOO0KKKo'. .,.  ;OOOdl:,.       \n");
    addstr("               .........,:coc;;;;;;;;;::,...                ..';ldOOOOOl'oKKKOkkk,  ;OOOkxdl.       \n");
    addstr("              ........,:cl:;,''.......';::,..              ...';ldOOOOOdldO0KKKKKxlcodxOOOdl'       \n");
    addstr("             .......,:cl:;,.............';::'.            ..'..,ldOOOOOOOOOOOOOOOOOOkxdddd;.        \n");
    addstr("           .........;lc;,'........     ...,lc;;,,,,,,,,.  ..'..;ldOOOOOOOxdddddddooodd;...          \n");
    addstr("         .........,:cl:''......           'loxdddxxdlll:,;;::::cldOOOOOOOdl,..........              \n");
    addstr("        ..........;loo:'......            .ldxkkkxxxxdldxoldxxxxxkOOOOOOOdl'                        \n");
    addstr("       ........,::coc;'.....              .llodxkkkxddxkOkxddxOOOOOOOOOOOdl.                        \n");
    addstr("      .........;lllo:'....                'ldxdodxxxxddxOOOdldOOOOOOOOOOOdl.                        \n");
    addstr("     ..........;olc;,'....                .ldOkxdoooodxkOxddxkOOOOOOOOOxd;.                         \n");
    addstr("    .........,:col:'......                .lkNOdxxxdlodoodxkOOOOOOOOOOOdl.                          \n");
    addstr("   ..........;oooo:'....                  .lxKOxkOOkxxxoldOOOOOOOOOOOxd;.                           \n");
    addstr("    .........;oooo:'....                   .;dxOOOOOOxddxkOOOOOOOOOxd;.                             \n");
    addstr("      .......;oooo:'....                .,,,:ldOOOOOOdlododddxOOOxdol'                              \n");
    addstr("        .....',:ollc,'...             .,:ldxxxkOxdddo;.....,ldOOOdlodc,.                            \n");
    addstr("          .....;ollo:'....          .,cdoldOOOxd;....    .,lxkOOOdlodol'                            \n");
    addstr("            ...;llol:'....        .,coddoldOOOdl.        .ldOOOxdoloddoc,.                          \n");
    addstr("              ..'':l:''...        'lodddoldOOOkxl,,.     'ldOOOdlllodddddc,.                        \n");
    addstr("                ..,olc;'..      .,cdddddoldOOOOOdll.     .ldOOOxlllodddddol'                        \n");
    addstr("                  .':o:'..    .,cddddddolldOOOOOdll.     .ldOOOdl,.;ooddddoc,.                      \n");
    addstr("                    .'''..  .,coddddddollldOOOOOdll. .,,,lxkOOOdl. 'loddddddoc,.                    \n");
    addstr("                       ...  'lodddddoo;.,ldOOOOOdll:,:ldxkOOOOOdl.  .;ooddddddoc,.                  \n");
    addstr("                         .   .;oddddol' 'ldOOOOOdlllldxkOOOOOxd;.    'lodddddddddc,,.               \n");
    addstr("                              'llooo;.   .;ddddoolllldOOOOOOOdl.      .;ooddddddolll'               \n");
    addstr("                               .....       ........,ldOOOOOxd;.        'lodddddol,..                \n");
    addstr("                                                   .loddddd;.           .;ooooo;.                   \n");
    addstr("                                  .,,,,,,,,,.       .......               .....                     \n");
    addstr("                                   .........       .,,,,,,,,,.                                      \n");
    addstr("                                                   'lllllllll.                                      \n");
    update();
    addstr("                                                                             .........              \n");
    addstr("                                                                             .........              \n");
    addstr("                                                               .,,,,,.       .'........   .,,,.     \n");
    addstr("                                                               .lllll.       .........    'lll.     \n");
    addstr("                                                             .,lxxxdl'  ..   .......... .,lxol'     \n");
    addstr("                                                             .ldOOOdl' ..........,cc;.,;lxxxc..     \n");
    addstr("                                                           .,lxxxkOdl;...........',,'.cxxxl;'..     \n");
    addstr("                                                           .ldOxoxOkx:................,:ld:.''..    \n");
    addstr("                                                           .ldOdldOOOxo,................';:c;'...   \n");
    addstr("                                                           .ldOkxkOOOOO:..................',;c;'..  \n");
    addstr("                                                           .;oOOOOOl........................;llc,.. \n");
    addstr("                                                           .':dxOOOdlll,......   ,ooooool:. .....   \n");
    addstr("                                                            .,ldOOOl...ckl,. ;kkkc..lOOOdl.         \n");
    addstr("                                                            .,ldOOOdlllOMO:. .,;,.  ;OOOdl'         \n");
    addstr("                          ...........                       .,ldOOOOOOOXMO:.   ,k,  ;OOOdl'         \n");
    addstr("                      ......,:::::,......                   ..,cdxOOOOO0KKKo'. .,.  ;OOOdl:,.       \n");
    addstr("                  ......,:::coooooc:::,....                 ..';ldOOOOOl.oKKKOkkk,  ;OOOkxdl'       \n");
    addstr("               .......,:clllc;;;;;;;;;;:,...               ...';lxOOOOOdldO0KKKKKxllodxOOOxl.       \n");
    addstr("             .......,:coc;;;,.........';::,..             ..'..,ldOOOOOOOOOOOOOOOOOOkxdodd;.        \n");
    addstr("           .......,:coc;'...............';;:;;;,,,,.      ..'..;ldOOOOOOOxoddddddddddd;...          \n");
    addstr("         .........;oc;,'..........     ...,loxdodxxl,,,,,...''';ldOOOOOOOdl,..........              \n");
    addstr("       ........,::cl:''.......            'ldxkkkxxxxoldxl;::::oxkOOOOOOOdl.                        \n");
    addstr("      .........;llol:'......              .llodxkkkxddxkOkxoldxkOOOOOOOOOdl.                        \n");
    addstr("     ........,:cloc;'.....                .ldxdodxxxxddxOOOdldOOOOOOOOOOOdl.                        \n");
    addstr("    .........;llll:'....                  'ldOxlooooddxkOxddxkOOOOOOOOOOOdl'                        \n");
    addstr("   ..........;oc;,,'....                  'ldOkkdlldxdodddxkOOOOOOOOOOOxd;.                         \n");
    addstr("  .........,:lo:''......                  .lkNOdxkkxdOKxldOOOOOOOOOOOOOdl.                          \n");
    addstr(" ..........;ooo:''....                     .:xxkkOOkkOKxldOOOOOOOOOOOxd;.                           \n");
    addstr("  .........;ooo:''....                    .,lxkOOOOOOxddxkOxdxOOOxddd;.                             \n");
    addstr("    .......;ooo:''....                .,,,lxkOOOxddddolodddoldOOOdlll'                              \n");
    addstr("      .....;ooo:''....              .,cdoldOOOOOdll,.......,ldOOOdlodc,.                            \n");
    addstr("      .....;ooo:''....            .,cdddoldOOOOOdll'       'ldOOOdlodol'                            \n");
    addstr("        ...;olo:''....          .,cdddddolodxOOOdll.       'lxOOOdlodol'                            \n");
    addstr("          ..';o:''''..        .,cddddddo;.,ldOOOdll.     .,lxkOOOdlodddc,.                          \n");
    addstr("             .';cc;'..      .;coddddddol' .ldOOOkxxl,. .,lxkOOOOOdlodddol'                          \n");
    addstr("               .''''..      'lodddddoo;.  .ldOOOOOOdl:,lxkOOOOOxdolodddddc,.                        \n");
    addstr("                   ...      'loddddo;.    .ldOOOOOOdldxkOOOOOOOdlllodddddol'                        \n");
    addstr("                     .       .;ooo;.      .ldOOOOOOdldOOOOOOOxd;.,lodddddddc,.                      \n");
    addstr("                               ...         .;doodddoldOOOOOxd;.  'lodddddddol'                      \n");
    addstr("                                             ........;ddddd;.     .;oodddddddc,.                    \n");
    addstr("                                                      .....         .;ooooooo;.                     \n");
    addstr("                                                   .,,,,,,,,,.        .......                       \n");
    addstr("                                                   'lllllllll.                                      \n");
    update();
}

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
        }
        // add the line to the screen from the image buffer
        printw(image_buffer[i]);
        // add new line character to get to the next line
        printw("\n");
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
