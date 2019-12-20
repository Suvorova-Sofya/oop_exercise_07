#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <memory>
#include <fstream>
#include "figure.h"
#include "five_angles.h"
#include "six_angles.h"
#include "eight_angles.h"
#include "document.h"
#include "factory.h"

int main() {
    std::string command;
    factory fact;
    std::unique_ptr<document> doc1;
    while(std::cin >> command){
        if(command=="new"){
            doc1=std::make_unique<document>();
        }else if(command=="save"){
            std::string path;
            std::cin >> path;
            std::ofstream os(path);
            doc1->save(os);
            os.close();
        }else if(command=="load"){
            std::string path;
            std::cin >> path;
            std::ifstream is(path);
            if(is) {
                doc1->load(is);
            }else {
                std::cout << "No such file\n";
            }
            is.close();
        }else if(command=="add"){
            fact.construct(doc1);
        }else if(command=="remove"){
            size_t id;
            std::cin >> id;
            doc1->remove_figure(id);
        }else if(command=="show"){
            doc1->show(std::cout);
        }else if(command == "undo"){
            doc1->undo();
        }
    }
    return 0;
}