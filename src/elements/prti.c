#include <element.h>

int update_PRTI(UPDATE_FUNC_ARGS) {
	int r, nnx, rx, ry, fe = 0;
	int count =0;
	parts[i].tmp = (int)((parts[i].temp-73.15f)/100+1);
	if (parts[i].tmp>=CHANNELS) parts[i].tmp = CHANNELS-1;
	else if (parts[i].tmp<0) parts[i].tmp = 0;
	for (rx=-1; rx<2; rx++)
		for (ry=-1; ry<2; ry++)
			if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				count ++;
				if (!r)
					fe = 1;
				if ((r>>8)>=NPART || !r)
					continue;
				if ((r&0xFF)==PT_SPRK || ((r&0xFF)!=PT_PRTI && (r&0xFF)!=PT_PRTO && (ptypes[r&0xFF].falldown!= 0 || ptypes[r&0xFF].state == ST_GAS)))
					for ( nnx=0; nnx<80; nnx++)
						if (!portal[parts[i].tmp][count-1][nnx])
						{
							portal[parts[i].tmp][count-1][nnx] = parts[r>>8].type;
							portaltemp[parts[i].tmp][count-1][nnx] = parts[r>>8].temp;
							portalctype[parts[i].tmp][count-1][nnx] = parts[r>>8].ctype;
							if ((r&0xFF)==PT_SPRK)
								part_change_type(r>>8,x+rx,y+ry,parts[r>>8].ctype);
							else
								kill_part(r>>8);
							break;
						}
			}
	
	
	if(fe){
		if(!parts[i].life) parts[i].life = rand();
		if(!parts[i].ctype) parts[i].life = rand();
		int orbd[4] = {0, 0, 0, 0};	//Orbital distances
		int orbl[4] = {0, 0, 0, 0};	//Orbital locations
		orbitalparts_get(parts[i].life, parts[i].ctype, orbd, orbl);
		for(r = 0; r < 4; r++){
			if(orbd[r]>1){
				orbd[r] -= 12;
				if(orbd[r]<1){
					orbd[r] = (rand()%128)+128;
					orbl[r] = rand()%255;
				} else {
					orbl[r] += 2;
					orbl[r] = orbl[r]%255;
				}
			} else {
				orbd[r] = (rand()%128)+128;
				orbl[r] = rand()%255;
			}
		}
		orbitalparts_set(&parts[i].life, &parts[i].ctype, orbd, orbl);
	} else {
		parts[i].life = 0;
		parts[i].ctype = 0;
	}
	return 0;
}
