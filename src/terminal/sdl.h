/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/*****************************************************************************
 * File name:     src/terminal/sdl.h                                         *
 * Created:       2003-09-15 by Hampa Hug <hampa@hampa.ch>                   *
 * Last modified: 2003-09-15 by Hampa Hug <hampa@hampa.ch>                   *
 * Copyright:     (C) 2003 by Hampa Hug <hampa@hampa.ch>                     *
 *****************************************************************************/

/*****************************************************************************
 * This program is free software. You can redistribute it and / or modify it *
 * under the terms of the GNU General Public License version 2 as  published *
 * by the Free Software Foundation.                                          *
 *                                                                           *
 * This program is distributed in the hope  that  it  will  be  useful,  but *
 * WITHOUT  ANY   WARRANTY,   without   even   the   implied   warranty   of *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General *
 * Public License for more details.                                          *
 *****************************************************************************/

/* $Id: sdl.h,v 1.1 2003/09/15 07:53:49 hampa Exp $ */


#ifndef PCE_TERMINAL_SDL_H
#define PCE_TERMINAL_SDL_H 1


#include <stdio.h>

#include <terminal/terminal.h>
#include <libini/libini.h>

#include <SDL/SDL.h>


typedef struct {
  terminal_t    trm;

  SDL_Surface   *scr;

  unsigned      mode;
  unsigned      pxl_w;
  unsigned      pxl_h;
  unsigned      scr_w;
  unsigned      scr_h;

  unsigned      font_w;
  unsigned      font_h;
  unsigned char *font;

  unsigned      crs_x;
  unsigned      crs_y;
  unsigned      crs_y1;
  unsigned      crs_y2;

  unsigned      upd_x1;
  unsigned      upd_y1;
  unsigned      upd_x2;
  unsigned      upd_y2;

  unsigned char fgidx;
  unsigned char bgidx;

  Uint32        fg;
  Uint32        bg;

  char          grab;
  char          upd;
  unsigned      upd_freq;

  unsigned char colmap[256][3];
} sdl_t;


terminal_t *sdl_new (ini_sct_t *ini);
void sdl_del (sdl_t *sdl);

void sdl_set_size (sdl_t *sdl, unsigned m, unsigned w, unsigned h);
void sdl_set_map (sdl_t *sdl, unsigned i, unsigned r, unsigned g, unsigned b);
void sdl_set_col (sdl_t *sdl, unsigned fg, unsigned bg);
void sdl_set_crs (sdl_t *sdl, unsigned y1, unsigned y2);
void sdl_set_pos (sdl_t *sdl, unsigned x, unsigned y);
void sdl_set_chr (sdl_t *sdl, unsigned x, unsigned y, unsigned char c);
void sdl_set_pxl (sdl_t *sdl, unsigned x, unsigned y, unsigned w, unsigned h);
void sdl_check (sdl_t *sdl);


#endif
