/*
 * msvc_rtc_handler.c - Suppress MSVC runtime check popup dialogs in CI
 *
 * When compiled with /RTCu (uninitialized variable detection), MSVC shows
 * a modal dialog on violations. This file installs a custom handler that
 * prints the error to stderr and exits, allowing CI to detect the failure
 * without hanging on a popup.
 *
 * Link this file into all targets when building Debug on MSVC.
 */

#ifdef _MSC_VER

#include <stdio.h>
#include <stdlib.h>
#include <rtcapi.h>
#include <crtdbg.h>
#include <windows.h>

/* Custom RTC error handler: print to stderr and abort */
static int __cdecl rtc_error_handler(int errorType, const wchar_t *filename,
                                     int linenumber, const wchar_t *moduleName,
                                     const wchar_t *format, ...) {
  fwprintf(stderr, L"\n=== MSVC Runtime Check Failure ===\n");
  if (filename)
    fwprintf(stderr, L"File: %s\nLine: %d\n", filename, linenumber);
  if (moduleName)
    fwprintf(stderr, L"Module: %s\n", moduleName);
  if (format) {
    va_list args;
    va_start(args, format);
    vfwprintf(stderr, format, args);
    va_end(args);
    fwprintf(stderr, L"\n");
  }
  fwprintf(stderr, L"==================================\n");
  fflush(stderr);
  _exit(1);
  return 0; /* unreachable */
}

/* Initialization: suppress all debug popups and install RTC handler */
#pragma section(".CRT$XIB", long, read)
static void __cdecl init_rtc_handler(void);
__declspec(allocate(".CRT$XIB")) static void (__cdecl *p_init)(void) = init_rtc_handler;

/* Exported symbol so linker can be forced to include this object */
int init_rtc_handler_force = 0;

static void __cdecl init_rtc_handler(void) {
  /* Suppress Windows Error Reporting dialog */
  SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOOPENFILEERRORBOX);

  /* Redirect CRT debug reports to stderr instead of popup */
  _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
  _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
  _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
  _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
  _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
  _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);

  /* Install custom RTC error handler */
  _RTC_SetErrorFuncW(rtc_error_handler);
}

#endif /* _MSC_VER */
