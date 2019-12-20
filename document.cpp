#include <iostream>

#include "document.h"

void document::save(std::ostream& os) const {
    for (size_t i = 0; i < figures_.size(); ++i) {
        figures_[i]->help_print(os);
    }
}

void document::load(std::istream& is){
    int help;
    while(is >> help){
        if(help ==1){
            five_angles fig(is);
            std::unique_ptr<figure> new_figure;
            new_figure=std::make_unique<five_angles>(fig);
            figures_.push_back(std::move(new_figure));
        }else if(help ==2){
            six_angles fig(is);
            std::unique_ptr<figure> new_figure;
            new_figure=std::make_unique<six_angles>(fig);
            figures_.push_back(std::move(new_figure));
        }else if(help ==3){
            eight_angles fig(is);
            std::unique_ptr<figure> new_figure;
            new_figure=std::make_unique<eight_angles>(fig);
            figures_.push_back(std::move(new_figure));
        }
    }
}

void document::add_figure(std::unique_ptr<figure>&& ptr,size_t id){
    figures_.insert(figures_.begin() + id,std::move(ptr));
    add_command op1;
    std::unique_ptr<add_command> op;
    op=std::make_unique<add_command>(std::move(op1));
    op->id=id;
    op->ptr_=nullptr;
    operations_.push_back(std::move(op));
}

void document::remove_figure(size_t id){
    remove_command op1;
    std::unique_ptr<remove_command> op;
    op=std::make_unique<remove_command>(std::move(op1));
    op->id=id;
    op->ptr_=std::move(figures_[id]);
    operations_.push_back(std::move(op));
    figures_.erase(figures_.begin() + id);

}

void document::show(std::ostream &os) const {
    if(figures_.size()>0) {
        for (size_t i = 0; i < figures_.size(); ++i) {
            os << "figure " << i << "\n";
            os << "cordinats ";
            figures_[i]->print(os);
            os << "center " << figures_[i]->center() << "\n";
            os << "square " << figures_[i]->square() << "\n";
        }
    }
}

void document::undo() {
    if(operations_.size()>0) {
        operations_[operations_.size()-1]->undo(*this);
        operations_.erase(operations_.begin()+operations_.size()-1);
    }
}

void document::add_command::undo(document &doc) {

    doc.figures_.erase(doc.figures_.begin() + id);
}

void document::remove_command::undo(document &doc) {
    doc.figures_.insert(doc.figures_.begin() + id,std::move(ptr_));
}