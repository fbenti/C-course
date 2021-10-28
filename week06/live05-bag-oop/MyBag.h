#ifndef MYBAG_H_
#define MYBAG_H_

#include "actions.h"
#include <string>
#include <vector>

class myBag {
public:
    // some constructors
    myBag(int);
    myBag(int,int);
    void performAction(actions::action, std::string);
    void display(void);
    // The methods implementing the "actions"
    void add(int);
    void del(int);
    void sortIt(void);
    void makeSet(void);
    void read(std::string);
    void flip(void);
    // Some extra methods
    bool empty(void);
    int pick(void);

private:
    std::vector<unsigned int> data;
};

#endif /* MYBAG_H_ */
