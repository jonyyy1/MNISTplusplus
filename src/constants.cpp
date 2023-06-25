#include "constants.h"
#include <iostream>
#include <filesystem>

std::filesystem::path find_project_root() {
    auto current_path = std::filesystem::current_path();
    auto project_directory = std::filesystem::path("MNISTplusplus");
    while (current_path != current_path.root_path()) {
        if (std::filesystem::exists(current_path / "MNISTplusplus")) {
            return std::filesystem::path(current_path / project_directory);
        }
        current_path = current_path.parent_path();
    }
    throw std::runtime_error("Project root not found.");
}
