/* AntB's Fork - Element Properties > powder.h */

{"MUTP",  PIXPACK(0x800000),  0.0f,   0.00f * CFDS, 1.00f,  1.00f, -0.99f,  0.00f, 0.00f,  0.000000f * CFDS, 0,  0,    0,  0,  0,  1, SC_CUSTOM,    R_TEMP+0.0f     +273.15f,   251,  "Nuclear - Mutagenic Photons - Mutates elements"},  
{"BAGL",  PIXPACK(0xA6543E),  0.0f,   0.00f * CFDS, 0.00f,  0.00f,  0.00f,  0.00f, 0.00f,  0.000000f * CFDS, 0,  1,    0,  0,  0,  0, SC_CUSTOM,    R_TEMP+0.0f     +273.15f,   70,   "Solid - Bagel!"},   
{"MUNE",  PIXPACK(0xF78DEE),  0.0f,   0.00f * CFDS, 1.00f,  1.00f, -0.99f,  0.00f, 0.25f,  0.002000f * CFDS, 0,  0,    0,  0,  0,  1, SC_CUSTOM,    R_TEMP+4.0f     +273.15f,   60,   "Nuclear - Mutagenic Neutrons - Mutates elements"},
{"RBRI",  PIXPACK(0x990F20),  0.0f,   0.00f * CFDS, 0.90f,  0.00f,  0.00f,  0.00f, 0.00f,  0.000000f * CFDS, 0,  0,    0,  1,  1,  1, SC_CUSTOM,    R_TEMP+0.0f     +273.15f,   150,  "Solid - Red Brick - Solid Construction material, insulates wires."},  
{"EMIT",  PIXPACK(0x303030),  0.0f,   0.00f * CFDS, 0.90f,  0.00f,  0.00f,  0.00f, 0.00f,  0.000000f * CFDS, 0,  0,    0,  1,  1,  1, SC_CUSTOM,    R_TEMP+0.0f     +273.15f,   251,  "Electrics - Emitter releases photons when sparked."},
{"LH2",   PIXPACK(0x5070EF),  0.6f,   0.01f * CFDS, 0.98f,  0.95f,  0.00f,  0.10f, 0.05f,  0.000000f * CFDS, 2,  0,    0,  0,  0,  1, SC_CUSTOM,    0.0f,                       70,   "Liquid - Liquid Hydrogen. Absolute 0, Highy Explosive when mixed with LOX"},  
{"H2",    PIXPACK(0x5070FF),  2.0f,   0.00f * CFDS, 0.99f,  0.30f, -0.10f,  0.00f, 3.00f,  0.000000f * CFDS, 0,  1000, 0,  0,  0,  1, SC_CUSTOM,    R_TEMP+0.0f     +273.15f,   70,   "Gas - Combines with O2 to make WATR/DSTL"},    
{"H202",  PIXPACK(0x6585EF),  0.6f,   0.01f * CFDS, 0.98f,  0.95f,  0.00f,  0.10f, 0.00f,  0.000000f * CFDS, 2,  9999, 0,  0,  0,  0, SC_CUSTOM,    R_TEMP-283.15f  +273.15f,   70,   "Liquid - Rocket fuel."},
{"SUWR",  PIXPACK(0x8080A0),  0.0f,   0.00f * CFDS, 0.90f,  0.00f,  0.00f,  0.00f, 0.00f,  0.000000f * CFDS, 0,  0,    0,  1,  1,  1, SC_CUSTOM,    R_TEMP+0.0f     +273.15f,   251,  "Electrics - Single use wire, dissolves when sparked."},
{"RADI",  PIXPACK(0x505020),  0.0f,   0.00f * CFDS, 0.90f,  0.00f,  0.00f,  0.00f, 0.00f,  0.000000f * CFDS, 0,  0,    0,  0,  0,  1, SC_CUSTOM,    R_TEMP+30.0f    +273.15f,   251,  "Nuclear - Solid Radioactive substance. Decays into Radon Gas."},
{"RADO",  PIXPACK(0x50FF20),  1.0f,   0.01f * CFDS, 0.99f,  0.30f, -0.10f,  0.00f, 0.75f,  0.001000f * CFDS, 0,  0,    0,  0,  1,  0, SC_CUSTOM,    R_TEMP+2.0f     +273.15f,   106,  "Nuclear - Radioactive Gas: Releases the occasional Neutron"},
{"GROW",  PIXPACK(0x008000),  2.0f,   0.02f * CFDS, 0.96f,  0.80f,  0.00f,  1.00f, 0.50f,  0.000000f * CFDS, 1,  0,    0,  0,  30, 1, SC_CUSTOM,    R_TEMP+0.0f     +273.15f,   70,   "Powder - Growth particles, expands whatever element it hits"},
{"LEAD",  PIXPACK(0x201E1E),  0.0f,   0.00f * CFDS, 0.90f,  0.00f,  0.00f,  0.00f, 0.00f,  0.000000f * CFDS, 0,  0,    0,  1,  1,  1, SC_CUSTOM,    R_TEMP+0.0f     +273.15f,   255,  "Electrics - Absorbs neutrons and heats up; doubles as a resistor."},
//Neons
{"R",	  PIXPACK(0xFF0000),  0.0f,	  0.00f * CFDS,	0.00f,	0.00f,	0.50f,	0.00f, 0.00f,  0.000000f * CFDS, 0,	0,	   0,  0,  1,  1, SC_NEON,	    R_TEMP+0.0f	    +273.15f,	106,	"Red Neon - Conductive - Glows when charged with PSCN, Discharge with NSCN"},
{"G",	  PIXPACK(0x00FF00),  0.0f,	  0.00f * CFDS,	0.00f,	0.00f,	0.50f,	0.00f, 0.00f,  0.000000f * CFDS, 0,	0,	   0,  0,  1,  1, SC_NEON,	    R_TEMP+0.0f	    +273.15f,	106,	"Green Neon - Conductive - Glows when charged with PSCN, Discharge with NSCN"},
{"B",	  PIXPACK(0x0000FF),  0.0f,	  0.00f * CFDS,	0.00f,	0.00f,	0.50f,	0.00f, 0.00f,  0.000000f * CFDS, 0,	0,	   0,  0,  1,  1, SC_NEON,	    R_TEMP+0.0f	    +273.15f,	106,	"Blue Neon - Conductive - Glows when charged with PSCN, Discharge with NSCN"},
{"C",	  PIXPACK(0x00FFFF),  0.0f,	  0.00f * CFDS,	0.00f,	0.00f,	0.50f,	0.00f, 0.00f,  0.000000f * CFDS, 0,	0,	   0,  0,  1,  1, SC_NEON,	    R_TEMP+0.0f	    +273.15f,	106,	"Cyan Neon - Conductive - Glows when charged with PSCN, Discharge with NSCN"},
{"M",     PIXPACK(0xFF00FF),  0.0f,	  0.00f * CFDS,	0.00f,	0.00f,	0.50f,	0.00f, 0.00f,  0.000000f * CFDS, 0,	0,	   0,  0,  1,  1, SC_NEON,      R_TEMP+0.0f	    +273.15f,	106,	"Magenta Neon - Conductive - Glows when charged with PSCN, Discharge with NSCN"},
{"Y",	  PIXPACK(0xFFFF00),  0.0f,	  0.00f * CFDS,	0.00f,	0.00f,	0.50f,	0.00f, 0.00f,  0.000000f * CFDS, 0,	0,     0,  0,  1,  1, SC_NEON,	    R_TEMP+0.0f	    +273.15f,	106,	"Yellow Neon - Conductive - Glows when charged with PSCN, Discharge with NSCN"},
//End Neons
s//Name		Colour			Advec	Airdrag			Airloss	Loss	Collid	Grav	Diffus	Hotair			Fal Burn  Exp Mel Hrd  M	Section		H       				Ins(real world, by triclops200) Description

