#include "file.h"

void write_schedule_into_file(std::ofstream &file, std::vector<std::string> &vector_classes) {
    for (int i = 0; i < vector_classes.size(); i++) {
        file << vector_classes[i] << std::endl;
    }
}
