#pragma once

extern int ___excno;
extern bool ___handled;

struct ___Rt {
    constexpr void operator<<(int value) {
        ___excno = value;
    };
};

extern ___Rt ___rt;
void ___defaultExceptionHandler(const char *, int);

#define throw if (___handled == false) ___defaultExceptionHandler(__FILE__, __LINE__); ___rt <<
#define try ; ___excno = 0; ___handled = true; if (1)
#define catch(x) ; ___handled = false; if (___excno == x)
#define catchall ; ___handled = false; if (1)
#define finally ; ___handled = false; if (1)
#define except ; ___handled = false; if (___excno) ___defaultExceptionHandler();
#define struct extern "C" struct
