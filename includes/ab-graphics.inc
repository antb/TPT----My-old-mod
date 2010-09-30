/* AntB's Fork - Glow effects > graphics.c */
else if (t==PT_LEAD)
{
    if(cmode == 3||cmode==4 || cmode==6)
    {
        vid[ny*(XRES+BARSIZE)+nx] = ptypes[t].pcolors;
        cg = 1;
        cb = 1;
        cr = 1;
        x = nx/CELL;
        y = ny/CELL;
        cg += fire_g[y][x];
        if(cg > 255) cg = 255;
        fire_g[y][x] = cg;
        cb += fire_b[y][x];
        if(cb > 255) cb = 255;
        fire_b[y][x] = cb;
        cr += fire_r[y][x];
        if(cr > 255) cr = 255;
        fire_r[y][x] = cr;
    }
    else
    {
        cr = 0x20;
        cg = 0x1E;
        cb = 0x1E;
        blendpixel(vid, nx, ny, cr, cg, cb, 192);
        blendpixel(vid, nx+1, ny, cr, cg, cb, 96);
        blendpixel(vid, nx-1, ny, cr, cg, cb, 96);
        blendpixel(vid, nx, ny+1, cr, cg, cb, 96);
        blendpixel(vid, nx, ny-1, cr, cg, cb, 96);
        blendpixel(vid, nx+1, ny-1, cr, cg, cb, 32);
        blendpixel(vid, nx-1, ny+1, cr, cg, cb, 32);
        blendpixel(vid, nx+1, ny+1, cr, cg, cb, 32);
        blendpixel(vid, nx-1, ny-1, cr, cg, cb, 32);
    }
}
else if(t==PT_MUPT)
{
    if(cmode == 3||cmode==4 || cmode==6)
    {
        vid[ny*(XRES+BARSIZE)+nx] = ptypes[t].pcolors;
        cg = 0;
        cb = 0;
        cr = 6;
        x = nx/CELL;
        y = ny/CELL;
        cg += fire_g[y][x];
        if(cg > 255) cg = 255;
        fire_g[y][x] = cg;
        cb += fire_b[y][x];
        if(cb > 255) cb = 255;
        fire_b[y][x] = cb;
        cr += fire_r[y][x];
        if(cr > 255) cr = 255;
        fire_r[y][x] = cr;
    }
    else
    {
        cr = 0x80;
        cg = 0x00;
        cb = 0x00;
        blendpixel(vid, nx, ny, cr, cg, cb, 192);
        blendpixel(vid, nx+1, ny, cr, cg, cb, 96);
        blendpixel(vid, nx-1, ny, cr, cg, cb, 96);
        blendpixel(vid, nx, ny+1, cr, cg, cb, 96);
        blendpixel(vid, nx, ny-1, cr, cg, cb, 96);
        blendpixel(vid, nx+1, ny-1, cr, cg, cb, 32);
        blendpixel(vid, nx-1, ny+1, cr, cg, cb, 32);
        blendpixel(vid, nx+1, ny+1, cr, cg, cb, 32);
        blendpixel(vid, nx-1, ny-1, cr, cg, cb, 32);
    }
}
else if(t==PT_MUNE)
{          
    cr = 0xF7;
    cg = 0x8D;
    cb = 0xEE;
    blendpixel(vid, nx, ny, cr, cg, cb, 192);
    blendpixel(vid, nx+1, ny, cr, cg, cb, 96);
    blendpixel(vid, nx-1, ny, cr, cg, cb, 96);
    blendpixel(vid, nx, ny+1, cr, cg, cb, 96);
    blendpixel(vid, nx, ny-1, cr, cg, cb, 96);
    blendpixel(vid, nx+1, ny-1, cr, cg, cb, 32);
    blendpixel(vid, nx-1, ny+1, cr, cg, cb, 32);
    blendpixel(vid, nx+1, ny+1, cr, cg, cb, 32);
    blendpixel(vid, nx-1, ny-1, cr, cg, cb, 32);
} 

//Neons
else if(t==PT_RNEO)
{
    cr=0x19*parts[i].life;
    cg=0x00;
    cb=0x00;

    blendpixel(vid, nx, ny, cr, cg, cb, 192);
    blendpixel(vid, nx-1, ny, cr, cg, cb, 192);
    blendpixel(vid, nx+1, ny, cr, cg, cb, 192);
    blendpixel(vid, nx, ny-1, cr, cg, cb, 192);
    blendpixel(vid, nx, ny+1, cr, cg, cb, 192);
    blendpixel(vid, nx-1, ny-1, cr, cg, cb, 96);
    blendpixel(vid, nx+1, ny-1, cr, cg, cb, 96);
    blendpixel(vid, nx-1, ny+1, cr, cg, cb, 96);
    blendpixel(vid, nx+1, ny+1, cr, cg, cb, 96);
    blendpixel(vid, nx-2, ny, cr, cg, cb, 96);
    blendpixel(vid, nx, ny-2, cr, cg, cb, 96);
    blendpixel(vid, nx+2, ny, cr, cg, cb, 96);
    blendpixel(vid, nx, ny+2, cr, cg, cb, 96);
    blendpixel(vid, nx-2, ny-2, cr, cg, cb, 32);
    blendpixel(vid, nx+2, ny-2, cr, cg, cb, 32);
    blendpixel(vid, nx-2, ny+2, cr, cg, cb, 32);
    blendpixel(vid, nx+2, ny+2, cr, cg, cb, 32);
    blendpixel(vid, nx-3, ny, cr, cg, cb, 32);
    blendpixel(vid, nx, ny-3, cr, cg, cb, 32);
    blendpixel(vid, nx+3, ny, cr, cg, cb, 32);
    blendpixel(vid, nx, ny+3, cr, cg, cb, 32);
}

else if(t==PT_GNEO)
{
    cr=0x00;
    cg=0x19*parts[i].life;
    cb=0x00;

    blendpixel(vid, nx, ny, cr, cg, cb, 192);
    blendpixel(vid, nx-1, ny, cr, cg, cb, 192);
    blendpixel(vid, nx+1, ny, cr, cg, cb, 192);
    blendpixel(vid, nx, ny-1, cr, cg, cb, 192);
    blendpixel(vid, nx, ny+1, cr, cg, cb, 192);
    blendpixel(vid, nx-1, ny-1, cr, cg, cb, 96);
    blendpixel(vid, nx+1, ny-1, cr, cg, cb, 96);
    blendpixel(vid, nx-1, ny+1, cr, cg, cb, 96);
    blendpixel(vid, nx+1, ny+1, cr, cg, cb, 96);
    blendpixel(vid, nx-2, ny, cr, cg, cb, 96);
    blendpixel(vid, nx, ny-2, cr, cg, cb, 96);
    blendpixel(vid, nx+2, ny, cr, cg, cb, 96);
    blendpixel(vid, nx, ny+2, cr, cg, cb, 96);
    blendpixel(vid, nx-2, ny-2, cr, cg, cb, 32);
    blendpixel(vid, nx+2, ny-2, cr, cg, cb, 32);
    blendpixel(vid, nx-2, ny+2, cr, cg, cb, 32);
    blendpixel(vid, nx+2, ny+2, cr, cg, cb, 32);
    blendpixel(vid, nx-3, ny, cr, cg, cb, 32);
    blendpixel(vid, nx, ny-3, cr, cg, cb, 32);
    blendpixel(vid, nx+3, ny, cr, cg, cb, 32);
    blendpixel(vid, nx, ny+3, cr, cg, cb, 32);
}

else if(t==PT_BNEO)
{
    cr=0x00;
    cg=0x00;
    cb=0x19*parts[i].life;

    blendpixel(vid, nx, ny, cr, cg, cb, 192);
    blendpixel(vid, nx-1, ny, cr, cg, cb, 192);
    blendpixel(vid, nx+1, ny, cr, cg, cb, 192);
    blendpixel(vid, nx, ny-1, cr, cg, cb, 192);
    blendpixel(vid, nx, ny+1, cr, cg, cb, 192);
    blendpixel(vid, nx-1, ny-1, cr, cg, cb, 96);
    blendpixel(vid, nx+1, ny-1, cr, cg, cb, 96);
    blendpixel(vid, nx-1, ny+1, cr, cg, cb, 96);
    blendpixel(vid, nx+1, ny+1, cr, cg, cb, 96);
    blendpixel(vid, nx-2, ny, cr, cg, cb, 96);
    blendpixel(vid, nx, ny-2, cr, cg, cb, 96);
    blendpixel(vid, nx+2, ny, cr, cg, cb, 96);
    blendpixel(vid, nx, ny+2, cr, cg, cb, 96);
    blendpixel(vid, nx-2, ny-2, cr, cg, cb, 32);
    blendpixel(vid, nx+2, ny-2, cr, cg, cb, 32);
    blendpixel(vid, nx-2, ny+2, cr, cg, cb, 32);
    blendpixel(vid, nx+2, ny+2, cr, cg, cb, 32);
    blendpixel(vid, nx-3, ny, cr, cg, cb, 32);
    blendpixel(vid, nx, ny-3, cr, cg, cb, 32);
    blendpixel(vid, nx+3, ny, cr, cg, cb, 32);
    blendpixel(vid, nx, ny+3, cr, cg, cb, 32);
}

else if(t==PT_CNEO)
{
    cr=0x00;
    cg=0x19*parts[i].life;
    cb=0x19*parts[i].life;

    blendpixel(vid, nx, ny, cr, cg, cb, 192);
    blendpixel(vid, nx-1, ny, cr, cg, cb, 192);
    blendpixel(vid, nx+1, ny, cr, cg, cb, 192);
    blendpixel(vid, nx, ny-1, cr, cg, cb, 192);
    blendpixel(vid, nx, ny+1, cr, cg, cb, 192);
    blendpixel(vid, nx-1, ny-1, cr, cg, cb, 96);
    blendpixel(vid, nx+1, ny-1, cr, cg, cb, 96);
    blendpixel(vid, nx-1, ny+1, cr, cg, cb, 96);
    blendpixel(vid, nx+1, ny+1, cr, cg, cb, 96);
    blendpixel(vid, nx-2, ny, cr, cg, cb, 96);
    blendpixel(vid, nx, ny-2, cr, cg, cb, 96);
    blendpixel(vid, nx+2, ny, cr, cg, cb, 96);
    blendpixel(vid, nx, ny+2, cr, cg, cb, 96);
    blendpixel(vid, nx-2, ny-2, cr, cg, cb, 32);
    blendpixel(vid, nx+2, ny-2, cr, cg, cb, 32);
    blendpixel(vid, nx-2, ny+2, cr, cg, cb, 32);
    blendpixel(vid, nx+2, ny+2, cr, cg, cb, 32);
    blendpixel(vid, nx-3, ny, cr, cg, cb, 32);
    blendpixel(vid, nx, ny-3, cr, cg, cb, 32);
    blendpixel(vid, nx+3, ny, cr, cg, cb, 32);
    blendpixel(vid, nx, ny+3, cr, cg, cb, 32);
}

else if(t==PT_YNEO)
{ 
    cr=0x19*parts[i].life;
    cg=0x19*parts[i].life;
    cb=0x00;

    blendpixel(vid, nx, ny, cr, cg, cb, 192);
    blendpixel(vid, nx-1, ny, cr, cg, cb, 192);
    blendpixel(vid, nx+1, ny, cr, cg, cb, 192);
    blendpixel(vid, nx, ny-1, cr, cg, cb, 192);
    blendpixel(vid, nx, ny+1, cr, cg, cb, 192);
    blendpixel(vid, nx-1, ny-1, cr, cg, cb, 96);
    blendpixel(vid, nx+1, ny-1, cr, cg, cb, 96);
    blendpixel(vid, nx-1, ny+1, cr, cg, cb, 96);
    blendpixel(vid, nx+1, ny+1, cr, cg, cb, 96);
    blendpixel(vid, nx-2, ny, cr, cg, cb, 96);
    blendpixel(vid, nx, ny-2, cr, cg, cb, 96);
    blendpixel(vid, nx+2, ny, cr, cg, cb, 96);
    blendpixel(vid, nx, ny+2, cr, cg, cb, 96);
    blendpixel(vid, nx-2, ny-2, cr, cg, cb, 32);
    blendpixel(vid, nx+2, ny-2, cr, cg, cb, 32);
    blendpixel(vid, nx-2, ny+2, cr, cg, cb, 32);
    blendpixel(vid, nx+2, ny+2, cr, cg, cb, 32);
    blendpixel(vid, nx-3, ny, cr, cg, cb, 32);
    blendpixel(vid, nx, ny-3, cr, cg, cb, 32);
    blendpixel(vid, nx+3, ny, cr, cg, cb, 32);
    blendpixel(vid, nx, ny+3, cr, cg, cb, 32);
}

else if(t==PT_MNEO)
{
    cr=0x19*parts[i].life;
    cg=0x00;
    cb=0x19*parts[i].life;

    blendpixel(vid, nx, ny, cr, cg, cb, 192);
    blendpixel(vid, nx-1, ny, cr, cg, cb, 192);
    blendpixel(vid, nx+1, ny, cr, cg, cb, 192);
    blendpixel(vid, nx, ny-1, cr, cg, cb, 192);
    blendpixel(vid, nx, ny+1, cr, cg, cb, 192);
    blendpixel(vid, nx-1, ny-1, cr, cg, cb, 96);
    blendpixel(vid, nx+1, ny-1, cr, cg, cb, 96);
    blendpixel(vid, nx-1, ny+1, cr, cg, cb, 96);
    blendpixel(vid, nx+1, ny+1, cr, cg, cb, 96);
    blendpixel(vid, nx-2, ny, cr, cg, cb, 96);
    blendpixel(vid, nx, ny-2, cr, cg, cb, 96);
    blendpixel(vid, nx+2, ny, cr, cg, cb, 96);
    blendpixel(vid, nx, ny+2, cr, cg, cb, 96);
    blendpixel(vid, nx-2, ny-2, cr, cg, cb, 32);
    blendpixel(vid, nx+2, ny-2, cr, cg, cb, 32);
    blendpixel(vid, nx-2, ny+2, cr, cg, cb, 32);
    blendpixel(vid, nx+2, ny+2, cr, cg, cb, 32);
    blendpixel(vid, nx-3, ny, cr, cg, cb, 32);
    blendpixel(vid, nx, ny-3, cr, cg, cb, 32);
    blendpixel(vid, nx+3, ny, cr, cg, cb, 32);
    blendpixel(vid, nx, ny+3, cr, cg, cb, 32);
}
