#include <iostream>
#include <vector>
#include <string>
#define CLASS_DAYS 5
#define WHITESPACES_PER_SCHEDULE CLASS_DAYS

int main()
{
    const std::vector<std::string> days_of_week = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
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

    // puts the respective day of week in every schedule
    int i = 0, day = 0;
    do
    {
        arrClasses.insert(arrClasses.begin() + i, days_of_week[day]);
        arrClasses.insert(arrClasses.begin() + i + classes + 1, " ");

        i += classes + 2;
        day++;

        if (day > days_of_week.size() - 1)
            day = 0;
    } while (i < arrClasses.size() && day < days_of_week.size());

    if (weeks > 1)
        // separators per week
        for (int iterator = 0, sum = 0; iterator < arrClasses.size(); iterator += (classes * CLASS_DAYS) + CLASS_DAYS + WHITESPACES_PER_SCHEDULE, sum++)
        {
            if (iterator >= arrClasses.size() - sum)
                break;
            else
                arrClasses.insert(arrClasses.begin() + iterator + sum, "---- WEEK " + std::to_string(sum + 1) + " ----");
        }

    for (std::string item : arrClasses)
    {
        std::cout << item << std::endl;
    }

    return 0;
}
