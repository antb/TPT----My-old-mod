#include <element.h>

int update_VIRU(UPDATE_FUNC_ARGS)
{
    int r,rx,ry;
	for(rx=-1;rx<2;rx++)
		for(ry=-1;ry<2;ry++)
			if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
					continue;
				if((!parts[r>>8].life2) &&
                    (r&0xFF)!= PT_CLNE && (r&0xFF)!= PT_BCLN && (r&0xFF)!= PT_PCLN &&
                    (r&0xFF)!= PT_DMND && (r&0xFF)!= PT_VOID &&
                    (r&0xFF)!= PT_BHOL && (r&0xFF)!= PT_WHOL &&
                    (r&0xFF)!= PT_PIPE && (r&0xFF)!= PT_PRTI && (r&0xFF)!= PT_PRTO &&
                    (r&0xFF)!= PT_STKM && (r&0xFF)!= PT_STKM2 &&
                    (r&0xFF)!= PT_REMX && (r&0xFF)!= PT_VIRU
                  )
				{
                    parts[r>>8].ctype2=parts[r>>8].ctype;
					parts[r>>8].ctype=parts[r>>8].type;
					parts[r>>8].type=PT_VIRU;
                    parts[r>>8].life2=10;
				}

                if(parts[r>>8].type == PT_VIRU && parts[i].life2 == 9)
                    parts[r>>8].life2 = 9;

                if(parts[i].life2 == 1)
                {
                    parts[i].type   = parts[i].ctype;
                    parts[i].ctype  = parts[i].ctype2;
                    parts[i].ctype2 = PT_NONE;
                    parts[i].life2  = 120;
                }
			}
    return 0;
}
