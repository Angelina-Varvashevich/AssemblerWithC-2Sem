//
// Created by user on 01.06.22.
//

#ifndef TS_ABSTRACT_H
#define TS_ABSTRACT_H


class People {
public:
    People(std::string name_, int age_) : name(name_), age(age_) {

    }

    std::string name;
    int age;

    virtual void Occupation() = 0;

};

class Doctor : public People {
public:
    Doctor(std::string name_, int age_) : People(name_, age_) {
    }

    void Occupation() override {
        std::cout << name << std::endl;
        std::cout << age << std::endl;
        std::cout << "Doctor";
    }
};

class Worker/*: public People*/{
public:
    /*Worker(std::string name_, int age_ ) : People(name_, age_) {
    }*/
    void work(People* doc){
        doc->Occupation();
    }
};


#endif //TS_ABSTRACT_H
