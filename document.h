#ifndef D_DOCUMENT_H_
#define D_DOCUMENT_H_

#include "figure.h"
#include "five_angles.h"
#include "six_angles.h"
#include "eight_angles.h"
#include <vector>
#include <memory>
#include <iostream>



struct document{

    document()= default;
    void save(std::ostream& os) const;
    void load(std::istream& is);

    void add_figure(std::unique_ptr<figure>&& ptr, size_t id);
    void remove_figure(size_t id);

    void show(std::ostream &os) const;

    void undo();

    struct command{
        size_t id;
        std::unique_ptr<figure> ptr_;
        virtual void undo(document &doc)=0;
    };

    struct add_command:public command{
        void undo(document &doc) override;
    };

    struct remove_command:public command{
        void undo(document &doc) override;
    };

private:
    std::vector<std::unique_ptr<figure>> figures_;
    std::vector<std::unique_ptr<command>> operations_;
};

#endif