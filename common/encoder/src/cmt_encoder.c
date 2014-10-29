#include <mem.h>
#include <stdio.h>

#include <ogg/ogg.h>
#include <oggz/oggz.h>
#include <vorbis/vorbis.h>

#include "cmt_encoder_private.h"

bool cmt_encoder_init(CMT_Encoder *encoder)
{
    if (encoder->format == CMT_Encoder_Format_Ogg) {
        return false; // todo
    } else if (encoder->format == CMT_Encoder_Format_WebM) {
        return false; // todo
    } else {
        return false; // invalid
    }

    // @todo validate more input info
    encoder->internals = (CMT_Encoder_Internals *)malloc(sizeof(CMT_Encoder_Internals));
    
    return true;
}

bool cmt_encoder_start()
{
    return false; // todo
}

bool cmt_encoder_add_audio(CMT_Encoder *encoder, CMT_Audio_Buffer *buffer, double timestamp)
{
    return false; // todo
}

bool cmt_encoder_add_video(CMT_Encoder *encoder, CMT_Video_Buffer *buffer, double timestamp)
{
    return false; // todo
}

bool cmt_encoder_end()
{
    return false; // todo
}

bool cmt_encoder_free(CMT_Encoder *encoder)
{
    if (encoder->internals) {
        free(encoder->internals);
        encoder->internals = NULL;
    }
    return true;
}
