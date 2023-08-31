#include "vector.h"

const std::vector<std::string> WEEK_DAYS = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

void put_week_days_to_vector(std::vector<std::string> &vector, const int CLASSES_PER_DAY)
{
    int i = 0, day = 0;

    do
    {
        vector.insert(vector.begin() + i, WEEK_DAYS[day]);
        vector.insert(vector.begin() + i + CLASSES_PER_DAY + 1, " ");

        i += CLASSES_PER_DAY + 2;
        day++;

        if (day > WEEK_DAYS.size() - 1)
            day = 0;
    } while (i < vector.size() && day < WEEK_DAYS.size());
}

void put_separators_per_week_to_vector(std::vector<std::string> &vector, const int CLASSES_PER_DAY)
{
    for (int iterator = 0, sum = 0; iterator < vector.size(); iterator += (CLASSES_PER_DAY * CLASS_DAYS) + CLASS_DAYS + WHITESPACES_PER_WEEK, sum++)
    {
        if (iterator >= vector.size() - sum)
            break;
        else
            vector.insert(vector.begin() + iterator + sum, "---- WEEK " + std::to_string(sum + 1) + " ----");
    }
}
