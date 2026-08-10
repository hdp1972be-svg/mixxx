/*
 * Preflight probe for the Qt 6.10.x / Ubuntu 20.04 build.
 *
 * Ubuntu Focal's EGL/X11 headers may expose a preprocessor macro named Bool.
 * Qt's QShaderDescription::VariableType enum also contains an enumerator named
 * Bool. If the macro is visible at the point where that enum is parsed, the
 * Qt build explodes with errors such as:
 *
 *   expected identifier before 'int'
 *
 * This deliberately reproduces the relevant preprocessor situation without
 * building Qt. The probe is meant to fail fast, before the expensive Qt build.
 */

#include <EGL/egl.h>

#ifdef Bool
#error "EGL/X11 headers define Bool as a preprocessor macro; this conflicts with Qt QShaderDescription::Bool"
#endif

/* Keep this close to the Qt construct we care about. */
enum VariableType {
    Unknown,
    Int,
    Bool,
    Bool2,
};

int main(void) {
    return Bool == 2 ? 0 : 1;
}
