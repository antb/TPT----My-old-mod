#include <element.h>

int update_GOO(UPDATE_FUNC_ARGS) {
	if (!parts[i].life && pv[y/CELL][x/CELL]>1.0f)
		parts[i].life = rand()%80+300;
	if (parts[i].life)
	{
		float advection = 0.1f;
		parts[i].vx += advection*vx[y/CELL][x/CELL];
		parts[i].vy += advection*vy[y/CELL][x/CELL];
	}
//AntB Edit
    int rx,ry,r;
    for(rx=-2;rx<3;rx++)
        for(ry=-2;ry<3;ry++)
			if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
					continue;
                if((r&0xFF)==PT_DESL)
                {
                    create_part(i,x,y,PT_NP2);
                    create_part(r>>8,x+rx,y+ry,PT_NP2);
                }
            }
	return 0;
}
