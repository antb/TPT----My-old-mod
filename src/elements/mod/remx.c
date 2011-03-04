#include <element.h>

int update_REMX(UPDATE_FUNC_ARGS)
{
    int r,rx,ry;
    for(rx=-10;rx<11;rx++)
        for(ry=-10;ry<11;ry++)
			if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
					continue;
				if(parts[r>>8].type==PT_VIRU && parts[r>>8].life2 == 10)
                {
					parts[r>>8].life2=9;
                    kill_part(i);
                }
			}
    return 0;
}
