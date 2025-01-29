#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

#if ASRELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

typedef enum log_level {

    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO =3, 
    LOG_LEVEL_DEBUG = 4, 
    LOG_LEVEL_TRACE = 5,

} log_level;

b8 initialize_logging();
void shutdown_logging();

ASAPI void log_output(log_level level, const char* message, ...);

#define ASFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);

#ifndef ASERROR
#define ASERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
#define ASWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else 
#define ASWARN(message, ...);
#endif

#if LOG_INFO_ENABLED == 1
#define ASINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else 
#define ASINFO(message, ...);
#endif

#if LOG_DEBUG_ENABLED == 1
#define ASDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else 
#define ASDEBUG(message, ...);
#endif

#if LOG_TRACE_ENABLED == 1
#define ASTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else 
#define ASTRACE(message, ...);
#endif
