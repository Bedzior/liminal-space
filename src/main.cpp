#include "Intellisense.h"

#include <gba_input.h>
#include <gba_base.h>
#include <gba_video.h>

int main()
{
	//set GBA rendering context to MODE 3 Bitmap Rendering
	SetMode(BG2_ON | MODE_3);

	int t = 0;
	while(1){
		int x,y;
		for(x = 0; x < SCREEN_WIDTH; ++x){
			for( y = 0; y < SCREEN_HEIGHT; ++y){
				((unsigned short*)0x06000000)[x+y*SCREEN_WIDTH] = ((((x&y)+t) & 0x1F) << 10)|
				((((x&y)+t*3)&0x1F)<<5) | ((((x&y)+t * 5)&0x1F)<<0);
			}
		}
		++t;
	}
	return 0;
}
