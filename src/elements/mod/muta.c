#include <powder.h>

int update_MUTA(UPDATE_FUNC_ARGS)
{
	int r, rx, ry;
	for(rx=-2; rx<3; rx++)
		for(ry=-2; ry<3; ry++)
		{
			if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
					continue;
				//change_particle(PT_FROM,PT_TO,r,Reversable?,Chance in 100)
				change_particle(PT_GUNP,PT_DUST,r,0,15);
				change_particle(PT_DYST,PT_DUST,r,0,15);
				change_particle(PT_WATR,PT_DSTW,r,0,5);
				change_particle(PT_PLEX,PT_GOO,r,0,15);
				change_particle(PT_NITR,PT_DESL,r,0,10);
				change_particle(PT_PLNT,PT_WOOD,r,0,15);
				change_particle(PT_DESL,PT_GAS,r,0,5);
				change_particle(PT_COAL,PT_WOOD,r,0,20);
				change_particle(PT_BHOL,PT_WHOL,r,1,50);
				change_particle(PT_SMKE,PT_DUST,r,0,15);
				change_particle(PT_BTRY,PT_METL,r,0,15);
				change_particle(PT_PTCT,PT_NTCT,r,1,100);
				change_particle(PT_PSCN,PT_NSCN,r,1,100);
				change_particle(PT_NBLE,PT_O2,r,1,15);
				change_particle(PT_WTRV,PT_SLTW,r,0,15);
				change_particle(PT_BRMT,PT_BMTL,r,0,15);
				change_particle(PT_BGLA,PT_GLAS,r,0,15);
				change_particle(PT_PLSM,PT_URAN,r,0,15);
				change_particle(PT_ACID,PT_DSTW,r,1,15);
                change_particle(PT_NP2, PT_DESL,r,0,25);
				change_particle(PT_STKM,PT_BAGL,r,0,5);

				if((r&0xFF)==PT_YEST)
				{
				if(15>(rand()%100000)&&isplayer==0)
					parts[r>>8].type = PT_STKM;
				else 
					parts[r>>8].type = PT_DYST;
				}
			}
		}
}
