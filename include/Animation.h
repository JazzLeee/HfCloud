#ifndef _ANIMATION_H
#define _ANIMATION_H

#include "stdinc.h"
#include "Graphics.h"
#include "Bitmap.h"
#include "Sprite.h"
#include "Module.h"
HFCLOUD_BEGIN

class Animation{
public:
    int frames;                 /**< total frames. */
    int current_frame;          /**< current frame. */
    Sprite *sprite;             /**< current sprite to show. */

    Animation();
    Animation(int fm);

    std::function<void(void)> update_frame;
    void update();              /**< update Animation. */
};

HFCLOUD_END
#endif
