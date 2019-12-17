#ifndef D_DOCUMENT_H_
#define D_DOCUMENT_H_

#include "figure.h"
#include "five_angles.h"
#include "six_angles.h"
#include "eight_angles.h"
#include <vector>
#include <memory>
#include <iostream>

struct operation{
    int id_of_op;
    size_t id_of_fig;
    std::unique_ptr<figure> ptr;
};

struct document{

    document()= default;
    void save(std::ostream& os) const;
    void load(std::istream& is);

    void add_figure(std::unique_ptr<figure>&& ptr, size_t id);
    void remove_figure(size_t id);

    void show(std::ostream &os) const;

    void undo();
private:
    std::vector<std::unique_ptr<figure>> figures_;
    std::vector<operation> operations_;
};

#endif