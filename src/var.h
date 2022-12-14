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

extern PLAYER P;
extern OPTION O;
extern char dir[100];
extern char dir2[100];
extern char ini_music[100];
extern char g_music[100];

#endif // HEADER_LIBRARY