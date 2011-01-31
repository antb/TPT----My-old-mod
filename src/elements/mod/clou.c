#include <powder.h>

int update_CLOU(UPDATE_FUNC_ARGS)
{
// ---MOVEMENT---
    int setX = 0;
    int setY = 0;
    int r,rx,ry;
    for(rx=-10;x<11;rx++)
        for(ry=-10;x<11;ry++)
            if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
    				continue;
                if((r&0xFF)==PT_CLOU)
                {
                    setY+=ry;
                    setX+=rx;
                }
            }

// ---PRODUCTION---
    for(rx=-1;rx<2;rx++)
        for(ry=-1;ry<2;ry++)
			if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
    				continue;  
                
                if(10 > (rand()/(RAND_MAX/3000)))
                {
                    if(parts[i].temp <= 273.15f && pv[y/CELL][x/CELL] < -12.0f)
                        create_part(i,x,y,PT_FOG);
                    else if(parts[i].temp <= 273.15f)
                        create_part(-1,x+rand()%5-2,y+rand()%3, PT_SNOW);
                    else if(parts[i].temp >= 80+273.15f)
                    {
                        if(10 < rand()/(RAND_MAX/1000))
                            create_part(-1,x+rand()%5-2,y+rand()%3, PT_WATR);
                        else
                            create_part(-1,x+rand()%5-2,y+rand()%3, PT_THDR);
                    }
                    else
                        create_part(-1,x+rand()%5-2,y+rand()%3, PT_WATR);
                }

            }

    if(10 > (rand()/(RAND_MAX/90)))
    {
        if(setX==0)
            parts[i].x+=(rand()%3)-1;
        if(setY==0)
            parts[i].y+=(rand()%3)-1;
    }
    parts[i].x+=setX;
    parts[i].y+=setY;
}

