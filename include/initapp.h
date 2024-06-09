#ifndef INITAPP_H
#define INITAPP_H

#include "working_dir.h"

#define DATA_DIR WDIR "data"
#define TARGET_DIR_PATH DATA_DIR "/targetdir.txt"
#define DEFAULT_WRAPPING_DIR "qtcopy-files-stash"

void init_app();

#endif // INITAPP_H
