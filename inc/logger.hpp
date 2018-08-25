#pragma once

/* Local libraries: */
#include "platform.hpp"

/* Standard libraries: */
#include <exception>
#include <string>

/* Component Object Model: */
#ifdef CYNTH_OS_WINDOWS
#include <objbase.h>
#endif

namespace Cynth {

    class Logger {
    public:
        /* Errors: */
        static void errHRESULT(HRESULT hr);
        static void errPlatform();
        static void errPlatform(std::string message);
        #ifdef CYNTH_API_WASAPI
        static void errWASAPI(std::string message);
        #endif
        static void errCynth(std::string message);

        /* Platform independent log: */
        static void log(std::string message);
        static void log(int message);
        static void log(float message);
    };

    /*/ Custom exception: /*/
    class Exception: public std::exception {
    protected:
        std::string message;
        std::string source;

    public:
        Exception(std::string message, std::string source = "Unknown");
        Exception(int message, std::string source = "Unknown");

        /* Accessors: */
        std::string getMessage() noexcept;
        std::string getSource() noexcept;
        virtual std::string what() noexcept;
        virtual void log() noexcept;
    };

    /*/ Platform exception: /*/
    class PlatformException: public Exception {
    public:
        PlatformException(std::string message = "Platform not suppored.");
    };

    #ifdef CYNTH_OS_WINDOWS
    /*/ COM exception: /*/
    class COMException: public Exception {
    public:
        COMException(HRESULT message);
    };
    #endif

    #ifdef CYNTH_API_WASAPI
    /*/ WASAPI exception: /*/
    class WASAPIException: public Exception {
    public:
        WASAPIException(std::string message);
    };
    #endif

    /*/ Cynth exception: /*/
    class CynthException: public Exception {
    public:
        CynthException(std::string message);
    };

}