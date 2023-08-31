#include "vector.h"

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
        std::cout << "Type a class: ";
        std::getline(std::cin, input);

        arrClasses[i] = input;
    }

    put_week_days_to_vector(arrClasses, classes);

    if (weeks > 1)
        put_separators_per_week_to_vector(arrClasses, classes);

    for (std::string item : arrClasses)
    {
        std::cout << item << std::endl;
    }

    return 0;
}
