#include "Intellisense.h"

#include <gba_base.h>
#include <gba_input.h>
#include <gba_video.h>

int main()
{
	SetMode(BG2_ON | MODE_3);

	int t = 0;
	while(1){
		for(int x = 0; x < SCREEN_WIDTH; ++x){
			for(int y = 0; y < SCREEN_HEIGHT; ++y){
				MODE3_FB[y][x] = ((((x&y)+t) & 0x1F) << 10)|
				((((x&y)+t*3)&0x1F)<<5) | ((((x&y)+t * 5)&0x1F)<<0);
			}
		}
		++t;
	}
	return 0;
}
