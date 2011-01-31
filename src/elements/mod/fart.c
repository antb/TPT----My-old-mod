#include <powder.h>

int update_FART(UPDATE_FUNC_ARGS)
{
    int r,rx,ry;
    for(rx=-2; rx<3; rx++)
        for(ry=-2; ry<3; ry++)
            if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
            {
                if(parts[i].tmp<10 && !parts[i].life)
                    parts[i].life=rand()/(RAND_MAX/50)+20;

                r = pmap[y+ry][x+rx];
                if((r>>8)>=NPART)
                    continue;
                if((r&0xFF)==PT_FIRE)
                {
                    pv[y/CELL][x/CELL]=(parts[i].tmp*2);
                    parts[i].type=PT_FIRE;
                    parts[i].life=rand()/(RAND_MAX/25)+20;
                    parts[i].tmp=0;
                    parts[i].temp=700.0f;
                    continue;
                }

                if(!r && parts[i].tmp >= 10)
                {
                    int tempX = x+rand()%3-1;
                    int tempY = y+rand()%3-1;                    
                    if(create_part(-1, tempX, tempY, PT_FART))
                    {
                        r = pmap[tempY][tempX];
                        parts[r>>8].tmp=parts[i].tmp*0.9;
                        parts[i].tmp*=0.9;
                        rx=3;
                        ry=3;
                    }
                }
            }
}
