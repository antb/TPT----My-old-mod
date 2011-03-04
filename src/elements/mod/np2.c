#include <element.h>

int update_NP2(UPDATE_FUNC_ARGS)
{
    int r,rx,ry;
    if(parts[i].life<=1)
    {
        kill_part(i);
        create_part(-1, x, y, PT_FIRE);
    }
    for(rx=-2; rx<3; rx++)
        for(ry=-2; ry<3; ry++)
            if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
            {
                r = pmap[y+ry][x+rx];
                if(parts[i].tmp == 1 && !r)
                {
                    parts[i].life--;
                    create_part(-1, x+rand()%3-1, y+rand()%3-1, PT_FIRE);
                }
                if((r>>8)>=NPART || !r)
                    continue;
                if(((r&0xFF)==PT_LAVA && parts[r>>8].ctype==PT_THRM) || ((r&0xFF)==PT_NP2 && parts[r>>8].tmp==1) && !parts[i].tmp)
                {
                    parts[i].tmp = 1;
                    if((r&0xFF)==PT_LAVA)
                        kill_part(r>>8);
                }
            }
    return 0;
}
