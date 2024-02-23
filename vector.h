#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <vector>
#define CLASS_DAYS 5
#define WHITESPACES_PER_WEEK CLASS_DAYS

extern const std::vector<std::string> WEEK_DAYS;

void put_week_days_to_vector(std::vector<std::string> &, const int);
void put_separators_per_week_to_vector(std::vector<std::string> &, const int);

#endif
