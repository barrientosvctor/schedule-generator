#include "vector.h"
#include <fstream>

inline void print_schedule(std::vector<std::string> &vector_classes)
{
    for (std::string item : vector_classes)
    {
        std::cout << item << std::endl;
    }
}

inline const std::string assignFileName(std::string const name) {
    return name.empty() ? "schedule" : name;
}

inline void write_schedule_into_file(std::ofstream &file, std::vector<std::string> &vector_classes) {
    for (std::size_t i = 0; i < vector_classes.size(); i++) {
        file << vector_classes[i] << std::endl;
    }
}

int main()
{
    int weeks, classes, totalClasses;

    std::cout << "Schedule Generator." << std::endl;
    std::cout << "How many weeks do you want your schedule to have?: ";
    std::cin >> weeks;
    std::cout << "How many classes will the schedule have per day of the week?: ";
    std::cin >> classes;

    totalClasses = classes * weeks * CLASS_DAYS;

    std::vector<std::string> arrClasses(totalClasses);

    std::string input;
    std::cin.ignore(); // Clear the newline character left by previous input

    for (int i = 0; i < totalClasses; i++)
    {
        std::cout << "Type a class for " << WEEK_DAYS[(i % 5)] << ": "; // TODO: Preserve same day of week when there's more than 1 class per day.
        std::getline(std::cin, input);

        arrClasses[i] = input;
    }

    std::string filename;

    std::cout << "I will save a text file in the current directory where this executable is located." << std::endl;
    std::cout << "Please enter a name for the file: ";

    std::getline(std::cin, filename);

    const std::string FILE_EXTENSION = ".txt";
    const std::string FILE = assignFileName(filename) + FILE_EXTENSION;

    put_week_days_to_vector(arrClasses, classes);

    if (weeks > 1)
        put_separators_per_week_to_vector(arrClasses, classes);

    std::ofstream stream(FILE);

    // checks if stream was created correctly
    if (!stream)
        print_schedule(arrClasses);
    else
    {
        if (!stream.is_open())
            std::cout << "Unable to open the file." << std::endl;

        write_schedule_into_file(stream, arrClasses);
        stream.close();
        std::cout << "The schedule was written correctly to the text file. Check it out now!" << std::endl;
    }

    return 0;
}
