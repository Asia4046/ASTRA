#pragma once
#include "defines.h"
// Disable assertions by commenting out the below line.
#define ASASSERTIONS_ENABLED
#ifdef ASASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif
ASAPI void report_assertion_failure(const char *expression, const char *message, const char *file, i32 line);
#define ASASSERT(expr)                                               \
    {                                                                \
        if (expr)                                                    \
        {                                                            \
        }                                                            \
        else                                                         \
        {                                                            \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }
#define ASASSERT_MSG(expr, message)                                       \
    {                                                                     \
        if (expr)                                                         \
        {                                                                 \
        }                                                                 \
        else                                                              \
        {                                                                 \
            report_assertion_failure(#expr, message, __FILE__, __LINE__); \
            debugBreak();                                                 \
        }                                                                 \
    }
#ifdef _DEBUG
#define ASASSERT_DEBUG(expr)                                         \
    {                                                                \
        if (expr)                                                    \
        {                                                            \
        }                                                            \
        else                                                         \
        {                                                            \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }
#else
#define ASASSERT_DEBUG(expr) // Does nothing at all
#endif
#else
#define ASASSERT(expr)              // Does nothing at all
#define ASASSERT_MSG(expr, message) // Does nothing at all
#define ASASSERT_DEBUG(expr)        // Does nothing at all
#endif