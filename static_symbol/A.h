// A.h
#pragma once
#include <vector>
#include <string>

struct Registry {
    static Registry& instance();

    void add(const std::string& name);
    void dump() const;

private:
    std::vector<std::string> items;
};

