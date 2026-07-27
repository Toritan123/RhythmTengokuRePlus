#include "engines/toss_boys.h"
#include "src/audio.h"

asm(".include \"include/gba.inc\""); // Temporary

// For readability.
#define gTossBoys ((struct TossBoysEngineData *)gCurrentEngineData)


/* TOSS BOYS */


// Play Ball Dispenser SFX, panned towards the boy who starts the toss.
void toss_boys_play_ball_sfx(u32 param) {
    struct SoundPlayer *soundPlayer = play_sound(&s_f_toss_ball_seqData);
    s8 panning;

    switch (param) {
        case 0:
            panning = 60;
            break;
        case 1:
            panning = 29;
            break;
        default:
            panning = -60;
            break;
    }

    set_soundplayer_panning(soundPlayer, panning);
}


#include "asm/engines/toss_boys/asm_0803e824.s"

#include "asm/engines/toss_boys/asm_0803e884.s"

#include "asm/engines/toss_boys/asm_0803e8b4.s"

#include "asm/engines/toss_boys/asm_0803e908.s"

#include "asm/engines/toss_boys/asm_0803e960.s"

#include "asm/engines/toss_boys/asm_0803e990.s"

#include "asm/engines/toss_boys/asm_0803e9b0.s"

#include "asm/engines/toss_boys/asm_0803ea08.s"

#include "asm/engines/toss_boys/asm_0803ea1c.s"

#include "asm/engines/toss_boys/asm_0803ea2c.s"

#include "asm/engines/toss_boys/asm_0803ea6c.s"

#include "asm/engines/toss_boys/asm_0803ea98.s"

#include "asm/engines/toss_boys/asm_0803ee14.s"

#include "asm/engines/toss_boys/asm_0803ee18.s"

#include "asm/engines/toss_boys/asm_0803ee58.s"

#include "asm/engines/toss_boys/asm_0803eea0.s"

#include "asm/engines/toss_boys/asm_0803ef64.s"

#include "asm/engines/toss_boys/asm_0803f038.s"

#include "asm/engines/toss_boys/asm_0803f0b8.s"

#include "asm/engines/toss_boys/asm_0803f12c.s"

#include "asm/engines/toss_boys/asm_0803f144.s"

#include "asm/engines/toss_boys/asm_0803f1b8.s"

#include "asm/engines/toss_boys/asm_0803f1bc.s"

#include "asm/engines/toss_boys/asm_0803f1f4.s"

#include "asm/engines/toss_boys/asm_0803f390.s"

#include "asm/engines/toss_boys/asm_0803f3b0.s"

#include "asm/engines/toss_boys/asm_0803f400.s"

#include "asm/engines/toss_boys/asm_0803f4ec.s"

#include "asm/engines/toss_boys/asm_0803f578.s"

#include "asm/engines/toss_boys/asm_0803f598.s"

#include "asm/engines/toss_boys/asm_0803f59c.s"

#include "asm/engines/toss_boys/asm_0803f7b4.s"

#include "asm/engines/toss_boys/asm_0803f7c0.s"

#include "asm/engines/toss_boys/asm_0803f7cc.s"

#include "asm/engines/toss_boys/asm_0803f9a0.s"

#include "asm/engines/toss_boys/asm_0803fa64.s"

#include "asm/engines/toss_boys/asm_0803fb00.s"

#include "asm/engines/toss_boys/asm_0803fb14.s"

#include "asm/engines/toss_boys/asm_0803fb68.s"

#include "asm/engines/toss_boys/asm_0803fbd8.s"

#include "asm/engines/toss_boys/asm_0803fc8c.s"

#include "asm/engines/toss_boys/asm_0803fc90.s"
