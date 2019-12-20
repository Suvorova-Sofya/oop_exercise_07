#include <iostream>

#include "factory.h"

void factory::construct(std::unique_ptr<document> &doc1) {
    std::string figures;
    std::cin >>figures;
    size_t id;
    std::cin >> id;
    if(figures == "five_angles"){
        std::unique_ptr<figure> new_figure;
        new_figure=std::make_unique<five_angles>( five_angles(std::cin));
        doc1->add_figure(std::move(new_figure),id);
    }else if(figures == "six_angles"){
        std::unique_ptr<figure> new_figure;
        new_figure=std::make_unique<six_angles>( six_angles(std::cin));
        doc1->add_figure(std::move(new_figure),id);
    }else if(figures == "eight_angles"){
        std::unique_ptr<figure> new_figure;
        new_figure=std::make_unique<eight_angles>( eight_angles(std::cin));
        doc1->add_figure(std::move(new_figure),id);
    }
}