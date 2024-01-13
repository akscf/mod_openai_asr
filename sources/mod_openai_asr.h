/**
 * (C)2024 aks
 * https://github.com/akscf/
 **/
#ifndef MOD_GOOGLE_ASR_H
#define MOD_GOOGLE_ASR_H

#include <switch.h>
#include <switch_stun.h>
#include <switch_curl.h>
#include <switch_json.h>
#include <stdint.h>
#include <string.h>

#ifndef true
#define true SWITCH_TRUE
#endif
#ifndef false
#define false SWITCH_FALSE
#endif

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define VERSION             "1.0-v1_http"

#define QUEUE_SIZE          96
#define VAD_STORE_FRAMES    64
#define VAD_RECOVERY_FRAMES 15
#define DEF_CHUNK_SZ_SEC    15

typedef struct {
    switch_mutex_t          *mutex;
    uint32_t                active_threads;
    uint32_t                chunk_size_sec;
    uint32_t                vad_silence_ms;
    uint32_t                vad_voice_ms;
    uint32_t                vad_threshold;
    uint32_t                request_timeout;    // seconds
    uint32_t                connect_timeout;    // seconds
    uint8_t                 fl_vad_debug;
    uint8_t                 fl_vad_enabled;
    uint8_t                 fl_shutdown;
    uint8_t                 fl_log_http_errors;
    const char              *api_key;
    const char              *api_url;
    const char              *user_agent;
    const char              *proxy;
    const char              *proxy_credentials;
    const char              *opt_encoding;
    const char              *opt_model;
} globals_t;

typedef struct {
    switch_memory_pool_t    *pool;
    switch_vad_t            *vad;
    switch_buffer_t         *vad_buffer;
    switch_mutex_t          *mutex;
    switch_queue_t          *q_audio;
    switch_queue_t          *q_text;
    switch_buffer_t         *curl_recv_buffer_ref;
    switch_vad_state_t      vad_state;
    int32_t                 transcript_results;
    uint32_t                vad_buffer_size;
    uint32_t                vad_stored_frames;
    uint32_t                chunk_buffer_size;
    uint32_t                deps;
    uint32_t                samplerate;
    uint32_t                channels;
    uint32_t                frame_len;
    uint32_t                ptime;
    uint8_t                 fl_pause;
    uint8_t                 fl_vad_first_cycle;
    uint8_t                 fl_destroyed;
    uint8_t                 fl_abort;
    const char              *opt_model;
} asr_ctx_t;

typedef struct {
    uint32_t                len;
    switch_byte_t           *data;
} xdata_buffer_t;

/* utils.c */
void thread_finished();
void thread_launch(switch_memory_pool_t *pool, switch_thread_start_t fun, void *data);

switch_status_t xdata_buffer_push(switch_queue_t *queue, switch_byte_t *data, uint32_t data_len);
switch_status_t xdata_buffer_alloc(xdata_buffer_t **out, switch_byte_t *data, uint32_t data_len);
void xdata_buffer_free(xdata_buffer_t **buf);
void xdata_buffer_queue_clean(switch_queue_t *queue);

char *audio_file_write(switch_byte_t *buf, uint32_t buf_len, uint32_t channels, uint32_t samplerate, const char *file_ext);

/* curl.c */
switch_status_t curl_perform(switch_buffer_t *recv_buffer, char *model_name, char *chunk_file, char *ext_opts);

#endif
