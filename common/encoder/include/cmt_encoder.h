#pragma once

#include <mem.h>
#include <stdio.h>

#ifdef __cpluspus
extern "C" {
#endif

typedef struct CMT_Encoder_Internals CMT_Encoder_Internals;

typedef enum {
    CMT_Encoder_Format_Ogg,
    CMT_Encoder_Format_WebM
} CMT_Encoder_Format;

typedef struct {
    int sampleRate;
    int channels;
    int bitrate;
} CMT_Audio_Info;
    
typedef struct {
    CMT_Audio_Info *info;
    float **pcm;
} CMT_Audio_Buffer;

typedef struct {
    int frameWidth;
    int frameHeight;
    int picWidth;
    int picHeight;
    int picLeft;
    int picTop;
    int rate_numerator;
    int rate_denominator;
    int bitrate;
} CMT_Video_Info;

typedef struct {
    CMT_Video_Info *info;
    unsigned char *y;
    unsigned char *u;
    unsigned char *v;
    int yStride;
    int uStride;
    int vStride;
} CMT_Video_Buffer;

typedef struct {
    CMT_Encoder_Internals *internals;

    FILE *outputFile;
    CMT_Encoder_Format format;
    CMT_Audio_Info *audioInfo;
    CMT_Video_Info *videoInfo;
} CMT_Encoder;

extern bool cmt_encoder_init(CMT_Encoder *encoder);
extern bool cmt_encoder_start();
extern bool cmt_encoder_add_audio(CMT_Encoder *encoder, CMT_Audio_Buffer *buffer, double timestamp);
extern bool cmt_encoder_add_video(CMT_Encoder *encoder, CMT_Video_Buffer *buffer, double timestamp);
extern bool cmt_encoder_end();
extern bool cmt_encoder_free(CMT_Encoder *encoder);


#ifdef __cplusplus
}
#endif
