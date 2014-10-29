#include <mem.h>
#include <stdio.h>

#include <ogg/ogg.h>
#include <oggz/oggz.h>
#include <vorbis/vorbis.h>

#include "cmt_encoder.h"

typedef struct CMT_Encoder_Internals {
    // Ogg output stream state
    OGGZ *oggz;
    
    // Vorbis encoder state
    vorbis_info *vorbisInfo;
    vorbis_dsp_state *vorbisDspState;
    vorbis_comment *vorbisComment;
    vorbis_block *vorbisBlock;
    
    // @todo theora state
    
    // @todo vpx state
} CMT_Encoder_Internals;

