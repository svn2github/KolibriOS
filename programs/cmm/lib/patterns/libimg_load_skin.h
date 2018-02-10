#ifndef INCLUDE_LIBIMG_LOAD_SKIN_H
#define INCLUDE_LIBIMG_LOAD_SKIN_H

#ifndef INCLUDE_LIBIMG_H
#include "../lib/obj/libimg.h"
#endif

:struct libimg_image {
	dword image, w, h, imgsrc;
} skin;

:void Libimg_LoadImage(dword struct_pointer, file_path)
{
	dword image_pointer;
	image_pointer = load_image(file_path);
	if (!image_pointer) notify("'Error: Image not loaded' -E");
	ESDWORD[struct_pointer] = image_pointer;
	ESDWORD[struct_pointer+4] = DSWORD[image_pointer+4];
	ESDWORD[struct_pointer+8] = DSWORD[image_pointer+8];
	ESDWORD[struct_pointer+12] = ESDWORD[image_pointer+24];
}

:void Libimg_FillTransparent(dword struct_pointer, w, h, new_transparent_color)
{
	dword i, max_i, image_data;
	image_data = ESDWORD[struct_pointer + 24];
	max_i =  w * h * 4 + image_data;
	for (i = image_data; i < max_i; i += 4)	if (DSDWORD[i]==0) DSDWORD[i] = new_transparent_color;
}

:void Libimg_ReplaceColor(dword struct_pointer, w, h, old_color, new_color)
{
	dword i, max_i, image_data;
	image_data = ESDWORD[struct_pointer + 24];
	max_i =  w * h * 4 + image_data;
	for (i = image_data; i < max_i; i += 4)	if (DSDWORD[i]==old_color) DSDWORD[i] = new_color;
}

#endif