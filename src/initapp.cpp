#include "initapp.h"
#include <filesystem>
#include <fstream>

void init_app() {
  if (!std::filesystem::exists(DATA_DIR)) {
    std::filesystem::create_directories(DATA_DIR);
  }

  if (!std::filesystem::exists(TARGET_DIR_PATH)) {
    std::ofstream outfile(TARGET_DIR_PATH);
    outfile << "select/target/dir";
    outfile.close();
  }
}
