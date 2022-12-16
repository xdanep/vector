#if !defined(HEADER_LIBRARY)
#define HEADER_LIBRARY

typedef enum
{
    OFF = 0,
    ON
} MUSIC;
typedef enum
{
    ENGLISH = 0,
    SPANISH
} LANGUAGE;
typedef enum
{
    BLACK = 0,
    RED = 1,
    GREEN = 2,
    YELLOW = 3,
    BLUE = 4,
    WHITE = 7
} COLOR;

typedef struct
{
    MUSIC mstate;
    LANGUAGE lstate;
} OPTION;

typedef struct
{
    COLOR cstate;
    char name[21];
} PLAYER;

typedef struct version
{
    char version[20];
    char help[20];
    char namever[10];
    char verver[20];
    char coderver[20];
    char builver[70];
    char copyver[70];
    char licever[90];
    char typever[70];
    char garaver[70];
} VERSION;

extern PLAYER P;
extern OPTION O;
extern VERSION V;
extern char dir[100];
extern char dir2[100];
extern char ini_music[100];
extern char g_music[100];

#endif // HEADER_LIBRARY