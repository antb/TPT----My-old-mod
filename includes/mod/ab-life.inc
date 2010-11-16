/* AntB's TPT Fork - Life values > powder.c */

if(t==PT_RADI)
    parts[i].life = 1000;


if(t==PT_MUPT)
{
    float a = (rand()%8) * 0.78540f;
    parts[i].life = 680;
    parts[i].vx = 3.0f*cosf(a);
    parts[i].vy = 3.0f*sinf(a);
}

