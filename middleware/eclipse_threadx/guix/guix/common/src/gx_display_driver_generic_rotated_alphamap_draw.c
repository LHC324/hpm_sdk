/***************************************************************************
 * Copyright (c) 2024 Microsoft Corporation 
 * 
 * This program and the accompanying materials are made available under the
 * terms of the MIT License which is available at
 * https://opensource.org/licenses/MIT.
 * 
 * SPDX-License-Identifier: MIT
 **************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** GUIX Component                                                        */
/**                                                                       */
/**   Display Management (Display)                                        */
/**                                                                       */
/**************************************************************************/

#define GX_SOURCE_CODE


/* Include necessary system files.  */

#include "gx_api.h"
#include "gx_system.h"
#include "gx_display.h"

#if defined GX_BRUSH_ALPHA_SUPPORT

/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _gx_display_driver_generic_rotated_alphamap_raw_alpha_draw          */
/*                                                        PORTABLE C      */
/*                                                           6.1.3        */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Kenneth Maxwell, Microsoft Corporation                              */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    Internal helper function that handles writing  with brush alpha     */
/*    of uncompressed alpha map file.                                     */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    context                               Drawing context               */
/*    xpos                                  x-coord of top-left draw point*/
/*    ypos                                  y-coord of top-left draw point*/
/*    pixelmap                              Pointer to GX_PIXELMAP struct */
/*    alpha                                 alpha value from 0 to 255     */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    [gx_display_driver_pixel_blend]       Basic display driver pixel    */
/*                                            blend function              */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    _gx_display_driver_generic_alphamap_draw                            */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  12-31-2020     Kenneth Maxwell          Initial Version 6.1.3         */
/*                                                                        */
/**************************************************************************/
static VOID  _gx_display_driver_generic_rotated_alphamap_raw_alpha_draw(GX_DRAW_CONTEXT *context, INT xpos, INT ypos, GX_PIXELMAP *pmp, GX_UBYTE alpha)
{
INT                xval;
INT                yval;
GX_UBYTE          *getrowalpha;
GX_CONST GX_UBYTE *getalpha;
GX_UBYTE           combined_alpha;
GX_COLOR           fill_color;
GX_RECTANGLE      *clip;
GX_RECTANGLE       rotated_clip;
VOID               (*blend_func)(GX_DRAW_CONTEXT *context, INT x, INT y, GX_COLOR fcolor, GX_UBYTE alpha);

    /* Pick up clip rectangle.  */
    clip = context -> gx_draw_context_clip;

    GX_SET_BLEND_FUNCTION(blend_func, context -> gx_draw_context_display -> gx_display_color_format)

    /* Pick up context fill color.  */
    fill_color = context -> gx_draw_context_brush.gx_brush_fill_color;

    GX_SWAP_VALS(xpos, ypos);

    if (context -> gx_draw_context_display -> gx_display_rotation_angle == GX_SCREEN_ROTATION_CW)
    {
        ypos = context -> gx_draw_context_canvas -> gx_canvas_x_resolution - ypos - pmp -> gx_pixelmap_width;
        rotated_clip.gx_rectangle_left = clip -> gx_rectangle_top;
        rotated_clip.gx_rectangle_right = clip -> gx_rectangle_bottom;
        rotated_clip.gx_rectangle_top = (GX_VALUE)(context -> gx_draw_context_canvas -> gx_canvas_x_resolution - clip -> gx_rectangle_right - 1);
        rotated_clip.gx_rectangle_bottom = (GX_VALUE)(context -> gx_draw_context_canvas -> gx_canvas_x_resolution - clip -> gx_rectangle_left - 1);
    }
    else
    {
        xpos = context -> gx_draw_context_canvas -> gx_canvas_y_resolution - xpos - pmp -> gx_pixelmap_height;
        rotated_clip.gx_rectangle_left = (GX_VALUE)(context -> gx_draw_context_canvas -> gx_canvas_y_resolution - clip -> gx_rectangle_bottom - 1);
        rotated_clip.gx_rectangle_right = (GX_VALUE)(context -> gx_draw_context_canvas -> gx_canvas_y_resolution - clip -> gx_rectangle_top - 1);
        rotated_clip.gx_rectangle_top = clip -> gx_rectangle_left;
        rotated_clip.gx_rectangle_bottom = clip -> gx_rectangle_right;
    }

    getrowalpha = (UCHAR *)(pmp -> gx_pixelmap_data);
    getrowalpha += (pmp -> gx_pixelmap_height) * (rotated_clip.gx_rectangle_top - ypos);
    getrowalpha += (rotated_clip.gx_rectangle_left - xpos);

    for (yval = rotated_clip.gx_rectangle_top; yval <= rotated_clip.gx_rectangle_bottom; yval++)
    {
        getalpha = getrowalpha;

        for (xval = rotated_clip.gx_rectangle_left; xval <= rotated_clip.gx_rectangle_right; xval++)
        {
            combined_alpha = (GX_UBYTE)((*getalpha++) * alpha / 255);
            blend_func(context, xval, yval, fill_color, combined_alpha);
        }

        getrowalpha += pmp -> gx_pixelmap_height;
    }
}

/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _gx_display_driver_generic_rotated_alphamap_compressed_alpha_draw   */
/*                                                        PORTABLE C      */
/*                                                           6.1.3        */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Kenneth Maxwell, Microsoft Corporation                              */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    Internal helper function that handles writing with brush alpha      */
/*    of compressed alpha map file.                                       */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    context                               Drawing context               */
/*    xpos                                  x-coord of top-left draw point*/
/*    ypos                                  y-coord of top-left draw point*/
/*    pixelmap                              Pointer to GX_PIXELMAP struct */
/*    alpha                                 alpha value from 0 to 255     */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    [gx_display_driver_pixel_blend]       Basic display driver pixel    */
/*                                            blend function              */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    _gx_display_driver_generic_alphamap_draw                            */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  12-31-2020     Kenneth Maxwell          Initial Version 6.1.3         */
/*                                                                        */
/**************************************************************************/
static VOID  _gx_display_driver_generic_rotated_alphamap_compressed_alpha_draw(GX_DRAW_CONTEXT *context, INT xpos, INT ypos, GX_PIXELMAP *pmp, GX_UBYTE alpha)
{
INT                yval;
INT                xval;
GX_CONST GX_UBYTE *get;
GX_UBYTE           count;
GX_UBYTE           falpha;
GX_COLOR           fill_color;
GX_RECTANGLE      *clip;
GX_RECTANGLE       rotated_clip;
GX_UBYTE           combined_alpha;
VOID               (*blend_func)(GX_DRAW_CONTEXT *context, INT x, INT y, GX_COLOR fcolor, GX_UBYTE alpha);

    /* Pick up clip rectangle. */
    clip = context -> gx_draw_context_clip;

    GX_SET_BLEND_FUNCTION(blend_func, context -> gx_draw_context_display -> gx_display_color_format)

    /* Pick up context fill color.  */
    fill_color = context -> gx_draw_context_brush.gx_brush_fill_color;

    get = (GX_CONST GX_UBYTE *)pmp -> gx_pixelmap_data;

    GX_SWAP_VALS(xpos, ypos);

    if (context -> gx_draw_context_display -> gx_display_rotation_angle == GX_SCREEN_ROTATION_CW)
    {
        ypos = context -> gx_draw_context_canvas -> gx_canvas_x_resolution - ypos - pmp -> gx_pixelmap_width;
        rotated_clip.gx_rectangle_left = clip -> gx_rectangle_top;
        rotated_clip.gx_rectangle_right = clip -> gx_rectangle_bottom;
        rotated_clip.gx_rectangle_top = (GX_VALUE)(context -> gx_draw_context_canvas -> gx_canvas_x_resolution - clip -> gx_rectangle_right - 1);
        rotated_clip.gx_rectangle_bottom = (GX_VALUE)(context -> gx_draw_context_canvas -> gx_canvas_x_resolution - clip -> gx_rectangle_left - 1);
    }
    else
    {
        xpos = context -> gx_draw_context_canvas -> gx_canvas_y_resolution - xpos - pmp -> gx_pixelmap_height;
        rotated_clip.gx_rectangle_left = (GX_VALUE)(context -> gx_draw_context_canvas -> gx_canvas_y_resolution - clip -> gx_rectangle_bottom - 1);
        rotated_clip.gx_rectangle_right = (GX_VALUE)(context -> gx_draw_context_canvas -> gx_canvas_y_resolution - clip -> gx_rectangle_top - 1);
        rotated_clip.gx_rectangle_top = clip -> gx_rectangle_left;
        rotated_clip.gx_rectangle_bottom = clip -> gx_rectangle_right;
    }

    /* compressed with no alpha is a two-byte count and two-byte pixel value */

    /* first, skip to the starting row */
    for (yval = ypos; yval < rotated_clip.gx_rectangle_top; yval++)
    {
        xval = 0;
        while (xval < pmp -> gx_pixelmap_height)
        {
            count = *get++;

            if (count & 0x80)
            {
                count = (GX_UBYTE)((count & 0x7f) + 1);
                get++;      /* skip repeated pixel value */
            }
            else
            {
                count++;
                get += count;   /* skip raw pixel values */
            }
            xval += count;
        }
    }

    /* now we are on the first visible row, copy pixels until we get
       to the enf of the last visible row
     */

    while (yval <= rotated_clip.gx_rectangle_bottom)
    {
        xval = xpos;

        while (xval < xpos + pmp -> gx_pixelmap_height)
        {
            count = *get++;

            if (count & 0x80)
            {
                /* repeated value */
                count = (GX_UBYTE)((count & 0x7f) + 1);
                falpha = *get++;

                while (count--)
                {
                    if (xval >= rotated_clip.gx_rectangle_left &&
                        xval <= rotated_clip.gx_rectangle_right)
                    {
                        combined_alpha = (GX_UBYTE)(falpha * alpha / 255);
                        blend_func(context, xval, yval, fill_color, combined_alpha);
                    }
                    xval++;
                }
            }
            else
            {
                /* string of non-repeated values */
                count++;
                while (count--)
                {
                    if (xval >= rotated_clip.gx_rectangle_left &&
                        xval <= rotated_clip.gx_rectangle_right)
                    {
                        combined_alpha = (GX_UBYTE)((*get) * alpha / 255);
                        blend_func(context, xval, yval, fill_color, combined_alpha);
                    }
                    get++;
                    xval++;
                }
            }
        }
        yval++;
    }
}
#endif /* GX_BRUSH_ALPHA_SUPPORT*/

/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _gx_display_driver_generic_rotated_alphamap_raw_draw                */
/*                                                        PORTABLE C      */
/*                                                           6.1.3        */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Kenneth Maxwell, Microsoft Corporation                              */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    Internal helper function that handles writing of uncompressed       */
/*    alpha map file.                                                     */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    context                               Drawing context               */
/*    xpos                                  x-coord of top-left draw point*/
/*    ypos                                  y-coord of top-left draw point*/
/*    pixelmap                              Pointer to GX_PIXELMAP struct */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    [gx_display_driver_pixel_blend]       Basic display driver pixel    */
/*                                            blend function              */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    _gx_display_driver_generic_alphamap_draw                            */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  12-31-2020     Kenneth Maxwell          Initial Version 6.1.3         */
/*                                                                        */
/**************************************************************************/
static VOID  _gx_display_driver_generic_rotated_alphamap_raw_draw(GX_DRAW_CONTEXT *context, INT xpos, INT ypos, GX_PIXELMAP *pmp)
{
INT                xval;
INT                yval;
GX_UBYTE          *getrowalpha;
GX_CONST GX_UBYTE *getalpha;
GX_COLOR           fill_color;
GX_RECTANGLE      *clip;
GX_RECTANGLE       rotated_clip;
VOID               (*blend_func)(GX_DRAW_CONTEXT *context, INT x, INT y, GX_COLOR fcolor, GX_UBYTE alpha);

    /* Pick up clip rectangle.  */
    clip = context -> gx_draw_context_clip;

    GX_SET_BLEND_FUNCTION(blend_func, context -> gx_draw_context_display -> gx_display_color_format)

    /* Pick up context fill color.  */
    fill_color = context -> gx_draw_context_brush.gx_brush_fill_color;

    GX_SWAP_VALS(xpos, ypos);

    if (context -> gx_draw_context_display -> gx_display_rotation_angle == GX_SCREEN_ROTATION_CW)
    {
        ypos = context -> gx_draw_context_canvas -> gx_canvas_x_resolution - ypos - pmp -> gx_pixelmap_width;
        rotated_clip.gx_rectangle_left = clip -> gx_rectangle_top;
        rotated_clip.gx_rectangle_right = clip -> gx_rectangle_bottom;
        rotated_clip.gx_rectangle_top = (GX_VALUE)(context -> gx_draw_context_canvas -> gx_canvas_x_resolution - clip -> gx_rectangle_right - 1);
        rotated_clip.gx_rectangle_bottom = (GX_VALUE)(context -> gx_draw_context_canvas -> gx_canvas_x_resolution - clip -> gx_rectangle_left - 1);
    }
    else
    {
        xpos = context -> gx_draw_context_canvas -> gx_canvas_y_resolution - xpos - pmp -> gx_pixelmap_height;
        rotated_clip.gx_rectangle_left = (GX_VALUE)(context -> gx_draw_context_canvas -> gx_canvas_y_resolution - clip -> gx_rectangle_bottom - 1);
        rotated_clip.gx_rectangle_right = (GX_VALUE)(context -> gx_draw_context_canvas -> gx_canvas_y_resolution - clip -> gx_rectangle_top - 1);
        rotated_clip.gx_rectangle_top = clip -> gx_rectangle_left;
        rotated_clip.gx_rectangle_bottom = clip -> gx_rectangle_right;
    }

    getrowalpha = (UCHAR *)(pmp -> gx_pixelmap_data);
    getrowalpha += (pmp -> gx_pixelmap_height) * (rotated_clip.gx_rectangle_top - ypos);
    getrowalpha += (rotated_clip.gx_rectangle_left - xpos);

    for (yval = rotated_clip.gx_rectangle_top; yval <= rotated_clip.gx_rectangle_bottom; yval++)
    {
        getalpha = getrowalpha;

        for (xval = rotated_clip.gx_rectangle_left; xval <= rotated_clip.gx_rectangle_right; xval++)
        {
            blend_func(context, xval, yval, fill_color, *getalpha++);
        }

        getrowalpha += pmp -> gx_pixelmap_height;
    }
}

/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _gx_display_driver_generic_rotated_alphamap_compressed_draw         */
/*                                                        PORTABLE C      */
/*                                                           6.1.3        */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Kenneth Maxwell, Microsoft Corporation                              */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    Internal helper function that handles writing of compressed         */
/*    alpha map file.                                                     */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    context                               Drawing context               */
/*    xpos                                  x-coord of top-left draw point*/
/*    ypos                                  y-coord of top-left draw point*/
/*    pixelmap                              Pointer to GX_PIXELMAP struct */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    [gx_display_driver_pixel_blend]       Basic display driver pixel    */
/*                                            blend function              */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    _gx_display_driver_generic_alphamap_draw                            */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  12-31-2020     Kenneth Maxwell          Initial Version 6.1.3         */
/*                                                                        */
/**************************************************************************/
static VOID  _gx_display_driver_generic_rotated_alphamap_compressed_draw(GX_DRAW_CONTEXT *context, INT xpos, INT ypos, GX_PIXELMAP *pmp)
{
INT                yval;
INT                xval;
GX_CONST GX_UBYTE *get;
GX_UBYTE           count;
GX_UBYTE           pixel;
GX_COLOR           fill_color;
GX_RECTANGLE      *clip;
GX_RECTANGLE       rotated_clip;
VOID               (*blend_func)(GX_DRAW_CONTEXT *context, INT x, INT y, GX_COLOR fcolor, GX_UBYTE alpha);

    /* Pick up clip rectangle.  */
    clip = context->gx_draw_context_clip;

    GX_SET_BLEND_FUNCTION(blend_func, context -> gx_draw_context_display -> gx_display_color_format)

    /* Pick up context fill color.  */
    fill_color = context -> gx_draw_context_brush.gx_brush_fill_color;

    get = (GX_CONST GX_UBYTE *)pmp -> gx_pixelmap_data;

    GX_SWAP_VALS(xpos, ypos);

    if (context -> gx_draw_context_display -> gx_display_rotation_angle == GX_SCREEN_ROTATION_CW)
    {
        ypos = context -> gx_draw_context_canvas -> gx_canvas_x_resolution - ypos - pmp -> gx_pixelmap_width;
        rotated_clip.gx_rectangle_left = clip -> gx_rectangle_top;
        rotated_clip.gx_rectangle_right = clip -> gx_rectangle_bottom;
        rotated_clip.gx_rectangle_top = (GX_VALUE)(context -> gx_draw_context_canvas -> gx_canvas_x_resolution - clip -> gx_rectangle_right - 1);
        rotated_clip.gx_rectangle_bottom = (GX_VALUE)(context -> gx_draw_context_canvas -> gx_canvas_x_resolution - clip -> gx_rectangle_left - 1);
    }
    else
    {
        xpos = context -> gx_draw_context_canvas -> gx_canvas_y_resolution - xpos - pmp -> gx_pixelmap_height;
        rotated_clip.gx_rectangle_left = (GX_VALUE)(context -> gx_draw_context_canvas -> gx_canvas_y_resolution - clip -> gx_rectangle_bottom - 1);
        rotated_clip.gx_rectangle_right = (GX_VALUE)(context -> gx_draw_context_canvas -> gx_canvas_y_resolution - clip -> gx_rectangle_top - 1);
        rotated_clip.gx_rectangle_top = clip -> gx_rectangle_left;
        rotated_clip.gx_rectangle_bottom = clip -> gx_rectangle_right;
    }

    /* compressed with no alpha is a two-byte count and two-byte pixel value */

    /* first, skip to the starting row */
    for (yval = ypos; yval < rotated_clip.gx_rectangle_top; yval++)
    {
        xval = 0;
        while (xval < pmp -> gx_pixelmap_height)
        {
            count = *get++;

            if (count & 0x80)
            {
                count = (GX_UBYTE)((count & 0x7f) + 1);
                get++;      /* skip repeated pixel value */
            }
            else
            {
                count++;
                get += count;   /* skip raw pixel values */
            }
            xval += count;
        }
    }

    /* now we are on the first visible row, copy pixels until we get
       to the enf of the last visible row
     */

    while (yval <= rotated_clip.gx_rectangle_bottom)
    {
        xval = xpos;

        while (xval < xpos + pmp -> gx_pixelmap_height)
        {
            count = *get++;

            if (count & 0x80)
            {
                /* repeated value */
                count = (GX_UBYTE)((count & 0x7f) + 1);
                pixel = *get++;

                while (count--)
                {
                    if (xval >= rotated_clip.gx_rectangle_left &&
                        xval <= rotated_clip.gx_rectangle_right)
                    {
                        blend_func(context, xval, yval, fill_color, pixel);
                    }
                    xval++;
                }
            }
            else
            {
                /* string of non-repeated values */
                count++;
                while (count--)
                {
                    if (xval >= rotated_clip.gx_rectangle_left &&
                        xval <= rotated_clip.gx_rectangle_right)
                    {
                        blend_func(context, xval, yval, fill_color, *get);
                    }
                    get++;
                    xval++;
                }
            }
        }
        yval++;
    }
}

/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _gx_display_driver_generic_rotated_alphamap_draw    PORTABLE C      */
/*                                                           6.1.3        */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Kenneth Maxwell, Microsoft Corporation                              */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function blends the context fill color with the canvas         */
/*      background.                                                       */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    context                               Drawing context               */
/*    xpos                                  x-coord of top-left draw point*/
/*    ypos                                  y-coord of top-left draw point*/
/*    pmp                                   Pointer to GX_PIXELMAP struct */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    status                                Completion status             */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    _gx_display_driver_generic_rotated_alphamap_compressed_alpha_draw   */
/*                                          Real display driver alphamap  */
/*                                            draw function               */
/*    _gx_display_driver_generic_rotated_alphamap_raw_alpha_draw          */
/*                                          Real display driver alphamap  */
/*                                            draw function               */
/*    _gx_display_driver_generic_rotated_alphamap_compressed_draw         */
/*                                          Real display driver alphamap  */
/*                                            draw function               */
/*    _gx_display_driver_generic_rotated_alphamap_raw_draw                */
/*                                          Real display driver alphamap  */
/*                                            draw function               */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Application Code                                                    */
/*    GUIX default draw funtions                                          */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  12-31-2020     Kenneth Maxwell          Initial Version 6.1.3         */
/*                                                                        */
/**************************************************************************/
VOID  _gx_display_driver_generic_rotated_alphamap_draw(GX_DRAW_CONTEXT *context, INT xpos, INT ypos, GX_PIXELMAP *pmp)
{
#if defined GX_BRUSH_ALPHA_SUPPORT
GX_UBYTE alpha;

    alpha = context -> gx_draw_context_brush.gx_brush_alpha;
    if (alpha == 0)
    {
        /* Nothing to drawn. Just return. */
        return;
    }

    if (alpha != 0xff)
    {
        if (pmp -> gx_pixelmap_flags & GX_PIXELMAP_COMPRESSED)
        {
            _gx_display_driver_generic_rotated_alphamap_compressed_alpha_draw(context, xpos, ypos, pmp, alpha);
        }
        else
        {
            _gx_display_driver_generic_rotated_alphamap_raw_alpha_draw(context, xpos, ypos, pmp, alpha);
        }
        return;
    }
#endif

    if (pmp -> gx_pixelmap_flags & GX_PIXELMAP_COMPRESSED)
    {
        _gx_display_driver_generic_rotated_alphamap_compressed_draw(context, xpos, ypos, pmp);
    }
    else
    {
        _gx_display_driver_generic_rotated_alphamap_raw_draw(context, xpos, ypos, pmp);
    }
}

