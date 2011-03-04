#include <element.h>

int update_EMIT(UPDATE_FUNC_ARGS)
{
    int r,rx,ry;
	for(rx=-1; rx<2; rx++)
		for(ry=-1; ry<2; ry++)
			if(x+rx>=0 && y+ry>0 &&
			   x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
					continue;
                if((r&0xFF)==PT_SPRK)
                    create_part(-1,x+rand()%3-1,y+rand()%3-1, PT_PHOT);
            }
    return 0;
}
