#include "libavutil/application.h"
#include "libavcodec/avcodec.h"
#include "libavformat/url.h"
#include "libavutil/fifo.h"
#include "libavformat/avformat.h"

int av_application_open(AVApplicationContext **ph, void *opaque) {
    int ret = av_application_alloc(ph, opaque);
    if (ret)
        return ret;

    return 0;
}

void av_application_closep(AVApplicationContext **ph) {
    if (!ph || !*ph)
        return;

    av_application_close(*ph);
    *ph = NULL;
}

void av_application_close(AVApplicationContext *h) {
    av_free(h);
}

void av_codec_set_lowres(AVCodecContext *avctx, int val) {

}

void av_codec_set_pkt_timebase(AVCodecContext *avctx, AVRational val) {

}

int ffurl_close(URLContext *h) {
    return 0;
}

int64_t ffurl_seek(URLContext *h, int64_t pos, int whence) {
    int64_t ret;

    if (!h->prot->url_seek)
        return AVERROR(ENOSYS);
    ret = h->prot->url_seek(h, pos, whence & ~AVSEEK_FORCE);
    return ret;
}

int64_t ffurl_size(URLContext *h) {
    int64_t pos, size;

    size = ffurl_seek(h, 0, AVSEEK_SIZE);
    if (size < 0) {
        pos = ffurl_seek(h, 0, SEEK_CUR);
        if ((size = ffurl_seek(h, -1, SEEK_END)) < 0)
            return size;
        size++;
        ffurl_seek(h, pos, SEEK_SET);
    }
    return size;
}

int av_packet_split_side_data(AVPacket *pkt) {
    return 0;
}

uintptr_t av_dict_strtoptr(char *value) {
    return 0;
}

AVFifo *av_fifo_alloc2(size_t elems, size_t elem_size,
                       unsigned int flags) {
    return NULL;
}

int av_codec_get_max_lowres(const AVCodec *codec) {
    return 0;
}

struct SwrContext *swr_alloc_set_opts(struct SwrContext *s,
                                      int64_t out_ch_layout, enum AVSampleFormat out_sample_fmt,
                                      int out_sample_rate,
                                      int64_t in_ch_layout, enum AVSampleFormat in_sample_fmt,
                                      int in_sample_rate,
                                      int log_offset, void *log_ctx) {
//    if(!s) s= swr_alloc();
//    if(!s) return NULL;
//
//    s->log_level_offset= log_offset;
//    s->log_ctx= log_ctx;
//
//    if (av_opt_set_int(s, "ocl", out_ch_layout,   0) < 0)
//        goto fail;
//
//    if (av_opt_set_int(s, "osf", out_sample_fmt,  0) < 0)
//        goto fail;
//
//    if (av_opt_set_int(s, "osr", out_sample_rate, 0) < 0)
//        goto fail;
//
//    if (av_opt_set_int(s, "icl", in_ch_layout,    0) < 0)
//        goto fail;
//
//    if (av_opt_set_int(s, "isf", in_sample_fmt,   0) < 0)
//        goto fail;
//
//    if (av_opt_set_int(s, "isr", in_sample_rate,  0) < 0)
//        goto fail;
//
//    if (av_opt_set_int(s, "tsf", AV_SAMPLE_FMT_NONE,   0) < 0)
//        goto fail;
//
//    if (av_opt_set_int(s, "ich", av_get_channel_layout_nb_channels(s-> user_in_ch_layout), 0) < 0)
//        goto fail;
//
//    if (av_opt_set_int(s, "och", av_get_channel_layout_nb_channels(s->user_out_ch_layout), 0) < 0)
//        goto fail;
//
//    av_opt_set_int(s, "uch", 0, 0);
//    return s;
//    fail:
//    av_log(s, AV_LOG_ERROR, "Failed to set option\n");
//    swr_free(&s);
    return NULL;
}

int avcodec_encode_video2(AVCodecContext *avctx, AVPacket *avpkt,
                          const AVFrame *frame, int *got_packet_ptr) {
    return 0;
}

int64_t av_get_default_channel_layout(int nb_channels) {
    return 0;
}

/**
 * Return the number of channels in the channel layout.
 */
int av_get_channel_layout_nb_channels(uint64_t channel_layout) {
    return 0;
}

int av_application_alloc(AVApplicationContext **ph, void *opaque) {
    return 0;
}

int64_t av_frame_get_pkt_pos(const AVFrame *frame) {
    return 0;
}

attribute_deprecated
int avcodec_decode_video2(AVCodecContext *avctx, AVFrame *picture,
                          int *got_picture_ptr,
                          const AVPacket *avpkt) {
    return 0;
}

void av_fifo_drain(AVFifoBuffer *f, int size) {

}

int ffurl_read(URLContext *h, unsigned char *buf, int size) {
    return 0;
}

/**
 * Free an AVFifoBuffer and reset pointer to NULL.
 * @param f AVFifoBuffer to free
 */
void av_fifo_freep(AVFifoBuffer **f) {

}

/**
 * Initialize an AVFifoBuffer.
 * @param size of FIFO
 * @return AVFifoBuffer or NULL in case of memory allocation failure
 */
AVFifoBuffer *av_fifo_alloc(unsigned int size) {
    return NULL;
}

/**
 * Reset the AVFifoBuffer to the state right after av_fifo_alloc, in particular it is emptied.
 * @param f AVFifoBuffer to reset
 */
void av_fifo_reset(AVFifoBuffer *f) {

}

/**
 * Return the amount of space in bytes in the AVFifoBuffer, that is the
 * amount of data you can write into it.
 * @param f AVFifoBuffer to write into
 * @return size
 */
int av_fifo_space(const AVFifoBuffer *f) {
    return 0;
}

/**
 * Return the amount of data in bytes in the AVFifoBuffer, that is the
 * amount of data you can read from it.
 * @param f AVFifoBuffer to read from
 * @return size
 */
int av_fifo_size(const AVFifoBuffer *f) {
    return 0;
}

/**
 * Feed data at specific position from an AVFifoBuffer to a user-supplied callback.
 * Similar as av_fifo_gereric_read but without discarding data.
 * @param f AVFifoBuffer to read from
 * @param offset offset from current read position
 * @param buf_size number of bytes to read
 * @param func generic read function
 * @param dest data destination
 */
int av_fifo_generic_peek_at(AVFifoBuffer *f, void *dest, int offset, int buf_size,
                            void (*func)(void *, void *, int)) {
    return 0;
}

int ffurl_write(URLContext *h, const unsigned char *buf, int size) {
    return 0;
}

int ffurl_closep(URLContext **h) {
    return 0;
}

void av_application_on_async_read_speed(AVApplicationContext *h, AVAppAsyncReadSpeed *speed) {

}

void av_application_on_async_statistic(AVApplicationContext *h, AVAppAsyncStatistic *statistic) {

}

/**
 * Check if the user has requested to interrupt a blocking function
 * associated with cb.
 */
int ff_check_interrupt(AVIOInterruptCB *cb) {
    return 0;
}

int av_application_on_io_control(AVApplicationContext *h, int event_type, AVAppIOControl *control) {
    return 0;
}

int ff_alloc_extradata(AVCodecParameters *par, int size) {
    int ret;

    if (size < 0 || size >= INT32_MAX - AV_INPUT_BUFFER_PADDING_SIZE) {
        par->extradata = NULL;
        par->extradata_size = 0;
        return AVERROR(EINVAL);
    }
    par->extradata = av_malloc(size + AV_INPUT_BUFFER_PADDING_SIZE);
    if (par->extradata) {
        memset(par->extradata + size, 0, AV_INPUT_BUFFER_PADDING_SIZE);
        par->extradata_size = size;
        ret = 0;
    } else {
        par->extradata_size = 0;
        ret = AVERROR(ENOMEM);
    }
    return ret;
}

AVInputFormat *av_iformat_next(const AVInputFormat *f) {
    return NULL;
}

/**
 * If f is NULL, returns the first registered output format,
 * if f is non-NULL, returns the next registered output format after f
 * or NULL if f is the last one.
 */
attribute_deprecated
AVOutputFormat *av_oformat_next(const AVOutputFormat *f) {
    return NULL;
}

int ffurl_open_whitelist(URLContext **puc, const char *filename, int flags,
                         const AVIOInterruptCB *int_cb, AVDictionary **options,
                         const char *whitelist, const char *blacklist,
                         URLContext *parent) {
    return 0;
}

int av_fifo_generic_write(AVFifoBuffer *f, void *src, int size, int (*func)(void *, void *, int)) {
    return 0;
}

void av_register_input_format(AVInputFormat *iformat) {

}

void av_register_all() {

}

AVRational av_codec_get_pkt_timebase(const AVCodecContext *avctx) {
    AVRational s;
    return s;
}

void avcodec_register_all(){

}

//int av_lockmgr_register(int (*cb)(void **mutex, enum AVLockOp op)){
//    return 0;
//}

int av_lockmgr_register(int (*cb)(void **mutex, enum AVLockOp op))
{
//    if (lockmgr_cb) {
//        // There is no good way to rollback a failure to destroy the
//        // mutex, so we ignore failures.
//        lockmgr_cb(&codec_mutex,    AV_LOCK_DESTROY);
//        lockmgr_cb(&avformat_mutex, AV_LOCK_DESTROY);
//        lockmgr_cb     = NULL;
//        codec_mutex    = NULL;
//        avformat_mutex = NULL;
//    }
//
//    if (cb) {
//        void *new_codec_mutex    = NULL;
//        void *new_avformat_mutex = NULL;
//        int err;
//        if (err = cb(&new_codec_mutex, AV_LOCK_CREATE)) {
//            return err > 0 ? AVERROR_UNKNOWN : err;
//        }
//        if (err = cb(&new_avformat_mutex, AV_LOCK_CREATE)) {
//            // Ignore failures to destroy the newly created mutex.
//            cb(&new_codec_mutex, AV_LOCK_DESTROY);
//            return err > 0 ? AVERROR_UNKNOWN : err;
//        }
//        lockmgr_cb     = cb;
//        codec_mutex    = new_codec_mutex;
//        avformat_mutex = new_avformat_mutex;
//    }

    return 0;
}