#ifndef DEFINE_H
#define DEFINE_H

#ifdef WIN32
#define PATH_SEP "\\"
#else
#define PATH_SEP "/"
#endif

#define ANTB_VERSION 6 //AntB Edit -- Bwahahahaaah!
#define SAVE_VERSION 45
#define MINOR_VERSION 13 //Start at 10 to prevent "New Version" update
#define IDENT_VERSION "G" //Change this if you're not Simon! It should be a single letter.
#define BETA

#define SERVER "powdertoy.co.uk"

#undef PLOSS

#define THUMB_CACHE_SIZE 256

#define IMGCONNS 3
#define TIMEOUT 100
#define HTTP_TIMEOUT 10

#define MENUSIZE 40
#define BARSIZE 17
#define XRES	612
#define YRES	384
#define NPART XRES*YRES

#define MAX_DISTANCE sqrt(pow(XRES, 2)+pow(YRES, 2))

#define MAXSIGNS 16
#define TAG_MAX 256

#define ZSIZE_D	16
#define ZFACTOR_D	8
extern unsigned char ZFACTOR;
extern unsigned char ZSIZE;

#define CELL    4
#define ISTP    (CELL/2)
#define CFDS	(4.0f/CELL)

#define TSTEPP 0.3f
#define TSTEPV 0.4f
#define VADV 0.3f
#define VLOSS 0.999f
#define PLOSS 0.9999f

#define GRID_X 5
#define GRID_Y 4
#define GRID_P 3
#define GRID_S 6
#define GRID_Z 3

#define STAMP_X 4
#define STAMP_Y 4
#define STAMP_MAX 120

#define NGOL 13

#define CIRCLE_BRUSH 0
#define SQUARE_BRUSH 1
#define BRUSH_NUM 2

#ifdef PIX16
typedef unsigned short pixel;
#else
typedef unsigned int pixel;
#endif

#define SURF_RANGE     10
#define NORMAL_MIN_EST 3
#define NORMAL_INTERP  20
#define NORMAL_FRAC    16

#define REFRACT        0x80000000

/* heavy flint glass, for awesome refraction/dispersion
   this way you can make roof prisms easily */
#define GLASS_IOR      1.9
#define GLASS_DISP     0.07

typedef unsigned char uint8;

extern int amd;

extern int FPSB;

int NUM_PARTS;
int GRAV;
int GRAV_R;
int GRAV_G;
int GRAV_B;
int GRAV_R2;
int GRAV_G2;
int GRAV_B2;

extern int legacy_enable;

extern int sys_pause;
extern int framerender;

extern int mousex, mousey;
extern int death;

struct sign
{
    int x,y,ju;
    char text[256];
};
typedef struct sign sign;

struct stamp
{
    char name[11];
    pixel *thumb;
    int thumb_w, thumb_h, dodelete;
};
typedef struct stamp stamp;

int MSIGN;
int CGOL;
int ISGOL;
int ISLOVE;
int ISLOLZ;
int ISGRAV;
int ISWIRE;
int GSPEED;
int love[XRES/9][YRES/9];
int lolz[XRES/9][YRES/9];
int gol[XRES][YRES];
int gol2[XRES][YRES][NGOL];
int SEC;
int SEC2;
int REPLACE_MODE;
int CURRENT_BRUSH;
int GRID_MODE;
int VINE_MODE;
int DEBUG_MODE;
int GENERATION;
int isplayer2;
int playerspawn;
int player2spawn;
int death2;
int ISSPAWN1;
int ISSPAWN2;
extern sign signs[MAXSIGNS];
extern stamp stamps[STAMP_MAX];
extern int stamp_count;
extern int itc;
extern char itc_msg[64];

extern int do_open;
extern int sys_pause;
extern int legacy_enable; //Used to disable new features such as heat, will be set by commandline or save.
extern int death, death2, framerender;

extern unsigned char last_major, last_minor, update_flag;

extern char http_proxy_string[256];

//Functions in main.c
void thumb_cache_inval(char *id);
void thumb_cache_add(char *id, void *thumb, int size);
int thumb_cache_find(char *id, void **thumb, int *size);
void *build_thumb(int *size, int bzip2);
void *build_save(int *size, int x0, int y0, int w, int h);
int parse_save(void *save, int size, int replace, int x0, int y0);
void del_stamp(int d);
void sdl_seticon(void);
#endif
