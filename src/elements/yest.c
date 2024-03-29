#include <element.h>

int update_YEST(UPDATE_FUNC_ARGS) {
	int r, rx, ry;
	for (rx=-2; rx<3; rx++)
		for (ry=-2; ry<3; ry++)
			if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if ((r>>8)>=NPART || !r)
					continue;
				if ((r&0xFF)==PT_DYST && 1>(rand()%30) && !legacy_enable)
				{
					part_change_type(i,x,y,PT_DYST);
				}
/* AntB Edit */ if((r&0xFF)==PT_BGLA)
                {
                    parts[i].type = PT_BAGL;
                    parts[r>>8].type = PT_BAGL;
                }

			}
	if (parts[i].temp>303&&parts[i].temp<317) {
		create_part(-1, x+rand()%3-1, y+rand()%3-1, PT_YEST);
	}
	return 0;
}
